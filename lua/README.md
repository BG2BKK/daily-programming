
lua daily tips
====================

* [mt.lua](mt.lua)
	* [lua的metatable相关练习](http://lua-users.org/wiki/MetamethodsTutorial)

* [setclass.lua](ClassesAndMethodsExample)
	* [ClassesAndMethodsExample](http://lua-users.org/wiki/ClassesAndMethodsExample)

* [lua的元表metatable和__index的区别](test_metatable.lua)
	* lua的metatable和\_\_index并不能混为一谈
	* [metatable和\_\_index的是相互起作用的：](http://www.aichengxu.com/view/6545168)
		* 当从lua的一个table中查找元素时，如果存在，则返回；如果不存在，则查找它的元表
		* 如果它没有元表，则直接返回nil；有元表的话查找元表有没有\_\_index方法
		* 如果元表没有\_\_index方法，则返回nil；如果元表的__index方法是一个表，重复第一步；如果元表的__index方法是一个函数，则返回函数的返回值

* [singleton.lua](singleton.lua)
	* lua单例模式

[Back to TOP](#lua daily tips)
