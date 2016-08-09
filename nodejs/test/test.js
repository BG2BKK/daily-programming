
var dat = {};
dat['a'] = 3;
dat['b'] = 4;

for( var k in dat) {
	console.log(k+"\t"+dat[k]);
}

console.log(dat.length);

for ( var i = 0; i < dat.length; i++){
	console.log(dat[i]);
}

var arr = [];
arr[0] = 5;
arr[1] = 3;
arr[2] = 4;
for ( var i = 0; i < arr.length; i++){
	console.log(arr[i]);
}

for( var k in arr){
	console.log(k, arr[k]);
}
