var redis = require('redis');
var bluebird = require("bluebird");
bluebird.promisifyAll(redis.RedisClient.prototype);
bluebird.promisifyAll(redis.Multi.prototype);

var client = redis.createClient(16379, '10.13.112.54');
for(var i = 0; i < 1000; i++){
	client.smembersAsync('bakwhitelist').then(function(reply) {
		console.log(i + ":" + reply.length + "\n");
	}, function(err){
		console.log(i + ":" + err);
	});
}
 

console.log('hello world');
