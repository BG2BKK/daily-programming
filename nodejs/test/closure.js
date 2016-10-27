
var name = "The Window";
var object = {
	name : "My Object",
	getNameFunc : function(){
		return function(){
			return this.name;
		};
	}
};
console.log(object.getNameFunc()());

/*
var name = "The Window";
var object = {
	name : "My Object",
	getNameFunc : function(){
		var that = this;
		return function(){
			return that.name;
		};
	}
};
console.log(object.getNameFunc()());
*/
var parent = function () {
  var name = "parent_name";
  var age = 13;

  var child = function () {
    var name = "child_name";
    var childAge = 0.3;

    // => child_name 13 0.3
    console.log(name, age, childAge);
  };

  child();

  // will throw Error
  // ReferenceError: childAge is not defined
//  console.log(name, age, childAge);
};

parent();

var adder = function(x) {
	var base = x;
	return function(n) {
		return n + base;
	};
}

var add10 = adder(10);
console.log(add10(5));

var add20 = adder(20);
console.log(add20(5));

var myObject = {value : 100};
myObject.getValue = function() {}
	var foo = function() {
		console.log(this.value);
//		console.log(this);
	};

	console.log("*******");
	foo();
	return this.value;
;
console.log(myObject.getValue());
