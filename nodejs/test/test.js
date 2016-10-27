var m = {
	"x": 1
};

function foo(y) {
	console.log(this.x + y);
}
foo.apply(m, [5]);
foo.call(m, 5);
var foo1 = foo.bind(m, 5);
foo1();


function a(xx) {
	this.b = xx;
}
var o = {};
a.apply(o, [5]);
console.log(a.b); // undefined
console.log(o.b); // 5


function a(xx, yy) {
	console.log(xx, yy);
	//	console.log(this);    
	console.log(arguments);
}
a.apply(null, [5, 55]);
a.call(null, 5, 55);
console.log("==================");

var dat = {
	'a': ['a1', 'a2', 'a3'],
	'a1': ['a11'],
	'a2': ['a12'],
	'a3': ['a13'],
	'a11': 1,
	'a12': 2,
	'a13': 3,
}

function getbyid(dat, id) {
	return dat[id];
}

// var ret = {
// 	'a' : {'a1':{'a11':1}, 'a2':{'a12':2},'a3':{'a13':3}}
// };

function get_by_id(dat, id) {
	var ret = {};
	var d = getbyid(dat, id);
	// console.log(typeof(d));
	// console.log(d);
	if (typeof(d) === typeof(1)) {
		console.log(typeof(d));
		return d;
	} else {
		
		for (var i in d) {
			// console.log(d[i]);
			ret[d[i]] = get_by_id(dat, d[i]);
		}
	}
	return ret;
}

console.log(get_by_id(dat, 'a'));