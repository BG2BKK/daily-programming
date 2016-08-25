
local test_index = function()
	local father = {
		house = 1
	}

	local son = {
		car = 1
	}

	setmetatable(son, father);
	print(son.house)
end

local test_metatable = function()
	local father = {
		house = 1
	}

	father.__index = father

	local son = {
		car = 1
	}

	setmetatable(son, father);
	print(son.house)
end

local test_metatable_trick = function()
	local father = {
		house = 1
	}

	father.__index = function() 
		return 'hello'
	end

	local son = {
		car = 1
	}

	setmetatable(son, father);
	print(son.house)
end
test_index()
test_metatable()
test_metatable_trick()
