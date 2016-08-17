var m = {   
	"x" : 1
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
console.log(a.b);    // undefined
console.log(o.b);    // 5


function a(xx, yy) {    
	console.log(xx, yy);    
//	console.log(this);    
	console.log(arguments);
}
a.apply(null, [5, 55]);
a.call(null, 5, 55);
