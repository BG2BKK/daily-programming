function consumer(prod)
	while true do
		local x = receive(prod)
		print(x)
	end
end

function receive(prod)
	local status, value = coroutine.resume(prod)
	return value
end

function send(x)
	coroutine.yield(x) -- go back to where resumed
end

function producer()
	return coroutine.create(function()
		while true do
			local x = io.read()
			send(x)
		end
	end)
end

-- consumer-driven design
consumer(producer())

