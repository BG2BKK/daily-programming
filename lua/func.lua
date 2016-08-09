
wrapper = function(f, data)
	if data > 0 then
		data = data - 1
		wrapper(f, data)
	end
	print(type(wrapper))
end

data = 10
wrapper(f, data)
