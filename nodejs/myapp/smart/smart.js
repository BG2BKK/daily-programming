var redis = require('redis');
var bluebird = require("bluebird");
bluebird.promisifyAll(redis.RedisClient.prototype);
bluebird.promisifyAll(redis.Multi.prototype);
// var logger = require('../app').logger('normal');

var smart = function(req, res, next) {
	next();
}

smart.getdeviceinfo = function(req, res, next) {
	// console.log(req.params.id);
	var id = req.params.id;
	var devicestat = id + ':stat'
	var client = redis.createClient(6379, '127.0.0.1');
	res.writeHead(200, {
		"Content-Type": "application/json"
	});
	client.lrangeAsync(devicestat, 0, 10).then(function(reply){
		console.log(reply);
		res.write(JSON.stringify(reply));
	}).then(function(){
		res.end();
		client.quit();
	});
	
}

smart.device_and_stat = function(req, res, next) {

	var client = redis.createClient(6379, '127.0.0.1');
	res.writeHead(200, {
		"Content-Type": "application/json"
	});
	client.hkeysAsync('smartdevice').then(function(reply) {
		var promises = [];
		for (var id in reply) {			
			var key = reply[id]+":last"		
			promises.push(client.hgetallAsync(key));
		}
		var dat = [];
		Promise.all(promises).then(function(reply) {					
			
			for(var id in reply){
				// console.log(item);					
				dat.push(reply[id]);
			}
			res.write(JSON.stringify(dat));
			console.log(JSON.stringify(dat));

			res.write("\n");
			// client.quit();
		}, function(err){
			console.log(err);
		}).then(function() {
			res.end();
			client.quit();
		});
	})

	// client.quit();
}

smart.getdevices = function(req, res, next) {

	var client = redis.createClient(6379, '127.0.0.1');

	client.hkeysAsync('smartdevice').then(function(reply) {
		res.writeHead(200, {
			"Content-Type": "application/json"
		});
		res.write(JSON.stringify(reply));
		res.end();
	})
	client.quit();
}

smart.heartbeat = function(req, res, next) {

	var val = req.body;
	// console.log(val);


	var client = redis.createClient(6379, '127.0.0.1');

	for (var k in val) {
		client.set(k, val[k]);
	}
	var mac = val['mac'];
	var chipid = val['chipid'];
	var id = mac + ':' + chipid;
	var heartbeat = new Date().getTime();

	var dat = {}
	dat['id'] = id;
	dat['temp'] = val['temp'];
	dat['hum'] = val['hum'];
	dat['time'] = val['time'];
	dat['heap'] = val['heap'];
	dat['heartbeat'] = heartbeat;

	for (var k in dat) {
		var key = id + ':last';
		client.hset(key, k, dat[k]);
	}

	client.hset('smartdevice', id, heartbeat);

	client.lpush(id + ':stat', JSON.stringify(dat));
	client.quit();

	var resp = {};
	resp.code = 200;
	resp.data = 'success';

	res.writeHead(200, {
		"Content-Type": "application/json"
	});
	res.write(JSON.stringify(resp));
	res.end();

}

module.exports = smart;