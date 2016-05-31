-- http://lua-users.org/wiki/MetamethodsTutorial
local x = {value = 5}

local mt = {
	__add = function(a, b)
		return {value = a.value + b.value}
	end,

	__tostring = function(a)
		return a.value
	end,

	__index = {key = 4}
}

setmetatable(x, mt)
print(x)
print(x.value)
print(x.key)

local y = x + x
print(y.value)

print('-------------------------------------')


local m = {key = 4}
local x = {value = 5}
local mt = {
	__add = function(a, b)
		return {value = a.value + b.value}
	end,

	__tostring = function(a)
		return a.value
	end,

	__index = m
}

setmetatable(x, mt)
print(x)
print(x.value)
print(x.key)

print('-------------------------------------')


local m = {}
setmetatable(m, {key = 4})

local x = {value = 5}
local mt = {
	__add = function(a, b)
		return {value = a.value + b.value}
	end,

	__tostring = function(a)
		return a.value
	end,

	__index = m
}

setmetatable(x, mt)
print(x.value)
print(x.key)

print(m.key)
print(getmetatable(x) == mt)


print('-------------------------------------')


local m = {}
setmetatable(m, {__index = function() print("doesn't exist") end})

local x = {value = 5}
local mt = {
	__add = function(a, b)
		return {value = a.value + b.value}
	end,

	__tostring = function(a)
		return a.value
	end,

	__index = m
}

setmetatable(x, mt)
print(x.value)
print(x.key)

print(m.key)
print(getmetatable(x) == mt)

print('-------------------------------------')

local m = {}
setmetatable(m, {__index = {key = 4}})

local x = {value = 5}
local mt = {
	__add = function(a, b)
		return {value = a.value + b.value}
	end,

	__tostring = function(a)
		return a.value
	end,

	__index = m
}

setmetatable(x, mt)
print(x.value)
print(x.key)

print(m.key)
print(getmetatable(x) == mt)

print('-------------------------------------')

local func_example = setmetatable({}, {__index = function (t, k)  -- {} an empty table, and after the comma, a custom function failsafe
	return "key doesn't exist"
end})

local fallback_tbl = setmetatable({ 
		foo = "bar",
		[123] = 456,  
	}, {__index=func_example})

local fallback_example = setmetatable({}, {__index=fallback_tbl})  -- {} again an empty table, but this time with a fallback failsafe

print(func_example[1]) --> key doesn't exist
print(fallback_example.foo) --> bar
print(fallback_example[123]) --> 456
print(fallback_example[456]) --> key doesn't exist

print('-------------------------------------')

-- http://lua-users.org/wiki/LuaClassesWithMetatable
t = { a = 3}
mt = {__index = print}

print(t)
print(t.a)
print(t.b)

setmetatable(t, mt)
print(t.b)	-- __index函数的第一个参数是table本身，也就是t，第二个参数是b；而函数是print，所以两个会被打印出来；print()自然是没有返回值，所以会再打印一行nil

mt = {__newindex = print} -- 如果__newindex域赋值为print方法，也很有趣
setmetatable(t, mt) 

t[4] = 'rat'

t = {a = 3}
mt = {__index = _G}
setmetatable(t, mt)

print(t.a)
print(t.b)

b = 4
print(t.b)	-- b作为全局变量，存储在_G表中，table t的metatable是mt，mt的__index是_G表
print(t.qqq)	-- b作为全局变量，存储在_G表中，table t的metatable是mt，mt的__index是_G表

local c = 5
print(t.c)	-- c是局部变量，哪里都找不到

