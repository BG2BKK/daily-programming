

-- http://see.sl088.com/wiki/Lua_%E5%8E%BB%E9%99%A4%E4%B8%A4%E5%A4%B4%E7%A9%BA%E7%99%BD
--


local trim = function(s)
	return (string.gsub(s, "^%s*(.-)%s*$", "%1"))
end

s = '  123 '
print(trim(s))

s = '  '
print(trim(s))

s = '1234, 1234'

local ipstr = s
local last_beg = 1
local pos = string.find(ipstr, ',')

if not pos then	-- xff只有一个ip
	local m, err = ngx.re.match(ipstr, '[0-9]+.[0-9]+.[0-9]+.[0-9]+')	-- 略low，不过ngx.re好像只能这么弄了
	if not err then
		clientIP = m[0]
	end
else
	while pos and pos ~= 1 do
		last_beg = pos + 1
		ipstr = string.sub(ipstr, last_beg)
		clientIP = ipstr
		pos = string.find(ipstr, ',')
	end
end

print(clientIP)
print(trim(clientIP))

local ipstr = s
local pos = string.find(ipstr, ',', 1)
print(pos)

s = "%d+002929aciwe%a+cqoe01230"
local x,y = string.find(s,"%d+", 1) --匹配数字，一次或多次连续
print(x,y)
--> x = 22, y = 26
print(string.sub(s, x, y))
