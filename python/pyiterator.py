# http://www.cnblogs.com/huxi/archive/2011/07/15/2107536.html

from itertools import *
def tutorial0():
    print 'tutorial0'

    print '-------------------------\n'


def tutorial1():
    print 'tutorial1'

    lst = range(100,110)
    it = (x+1 for x in lst)
    print it, it.next(), it.next()

    lst2 = [x+1 for x in lst]
    print lst2

    def getodd(x):
        if x%2 != 0:
            return x
    lt = [x for x in (getodd(y) for y in lst) if x > 0]
    print lt

    print '-------------------------\n'

def tutorial2():
    print 'tutorial2'

    it = count(10, 1)

#    while 1:
#        print it.next()
    
    def get_0_1_2():
        yield 0
        yield 1
        yield 2
    it = get_0_1_2()
    print it.next()
    print it.next()
    print next(it)
    try:
        print next(it)
    except StopIteration:
        pass

    print '-------------------------\n'


def test_fibonacci():
    def fibonacci():
        a = b = 1
        yield a
        yield b
    
        while True:
            a, b = b, a+b
            yield b

    fib = fibonacci()
    
    it = count(1)
    print fib.next()
    
    while True:
        t = it.next()
        print t, fib.next()
        if t  == 1000:
            break

def tutorial3():
    print 'tutorial3'

    def repeater():
        n = 0
        while True:
            n = (yield n+1)
    
    r = repeater()
    print r.next()
    print r.send(10)
    print r.send(10)
    print r.close()

    print '-------------------------\n'

   
tutorial1()
tutorial2()
# test_fibonacci()
tutorial3()
