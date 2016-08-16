
nodejs的学习之路
---------------------


* Promise的例子，[教程](http://liubin.org/promises-book/#chapter2-how-to-write-promise)
	* 创建promise对象，函数内执行自己的逻辑
	* promise对象对外统一提供resolve和reject接口
	* promise对象执行时，promise.then(function resolve, function reject),
		* then执行成功的话，调用resolve，resolve是在promise对象内部调用的
		* then执行失败的话，调用then方法的reject参数；如果then没有reject参数，则会调用promise.then().catch()来接盘；如果都没有reject和catch的话，这个错误将不会被处理
