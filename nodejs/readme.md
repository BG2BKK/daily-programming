
nodejs的学习之路
---------------------


* [redis_load.js](test/redis_load.js)
	* 刚学会使用node，感觉node的异步功能很强大，正好有一个压力测试redis的需求，因此通过一个node异步发出1000个redis大查询
	* redis的返回比较慢，但是按部就班的回复，没有查询失败的请求，基本达成目标
* [promise.js](test/promise.js)
	* nodejs的promise样例
	* [教程](http://liubin.org/promises-book/#chapter2-how-to-write-promise)
	* 创建promise对象，函数内执行自己的逻辑
	* promise对象对外统一提供resolve和reject接口
	* promise对象执行时，promise.then(function resolve, function reject),
		* then执行成功的话，调用resolve，resolve是在promise对象内部调用的
		* then执行失败的话，调用then方法的reject参数；如果then没有reject参数，则会调用promise.then().catch()来接盘；如果都没有reject和catch的话，这个错误将不会被处理

	* 补充
		* reject和resolve是promise对象的状态，在promise执行体中决定转到何种状态
			* getURL中的resolve(req.responseText)将promise转为resolve状态
			* getURL中的reject(new ERROR(req.statusText))将promise转为reject状态
		* promise.then(onResolve, onReject)表示当promise是resolve状态时，onResolve方法来处理；当promise是reject状态时，onReject方法来处理
