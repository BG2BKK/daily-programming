# coding: utf-8
# http://www.pythoner.com/18.html
# http://www.cnblogs.com/huxi/archive/2011/06/24/2089358.html

def tutorial1():
    print 'tutorial1'
    true = lambda :True
    print 'lambda:', true()

    def func_true():
        return True
    print 'func:',func_true()

    print '-------------------------\n'

def tutorial2():
    print 'tutorial2'
    add = lambda x,y :x+y
    print add(1,2)

    add = lambda x, y=2 : x+y
    print add(1)

    c = lambda *z : z
    print c("abc")
    print type(c("abc"))
    print len(c("abc"))
    print c("abc", 1, 2, 3)

    print '-------------------------\n'

def tutorial3():
    print 'tutorial3'
    lst = [1,-2,3,-4]
    
    lst2 = filter(lambda n: n>0, lst)
    print lst2

    class greater_than_helper:
        def __init__(self, minval):
            self.minval = minval
        def is_greater_than(self, val):
            return val > self.minval

    def my_filter(lst, minval):
        helper = greater_than_helper(minval)
        return filter(helper.is_greater_than, lst)
    print my_filter(lst, -3)

    def lambda_filter(lst, minval):
        return filter(lambda x:x>minval, lst)
    print lambda_filter(lst, -3)

    print '-------------------------\n'

def tutorial4():
    print 'tutorial4'
    lst = range(5)

    lst = map(lambda x : x + 1, lst)
    lst = reduce(lambda x, y : x*y, lst, 1)
    print lst

    print '-------------------------\n'

tutorial1()
tutorial2()
tutorial3()
tutorial4()

