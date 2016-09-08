
local Singleton = {}

function Singleton:new(o)
	print('new object')
	o = o or {}
	setmetatable(o, self)
	self.__index = self
	return o
end

function Singleton:Instance()
	if self.instance == nil then
		self.instance = self:new()
	end
	return self.instance
end

s1 = Singleton:Instance()

s2 = Singleton:Instance()

print(s1 == s2)
