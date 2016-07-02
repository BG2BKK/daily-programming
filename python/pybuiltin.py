
lst = range(5)
print lst
print iter(lst)

print all(lst)
print any(lst)
print max(lst)
print min(lst)
print sum(lst, 100)
# above all is based on reduce builtin method


print zip([1,2, 5], [3,4,6], [7,8,9])

x = [1,2,3]
y = [4,5,6]

zipped = zip(x,y)
print zipped
x2, y2 = zip(*zipped)       # unzip
print x2, type(x2)
print y2, type(y2)


# iter for reading file
with open('pybuiltin.py') as fp:
    for line in iter(fp.readline, ''):
        print line
