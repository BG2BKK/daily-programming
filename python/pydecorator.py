# coding=utf-8
import time
import sys
from functools import wraps

# 中文

def tutorial0():
    print 'tutorial0'

    print '-------------------------\n'

def tutorial1():
    print sys._getframe().f_code.co_name
    def timethis(func):
        def wrapper(*args, **kwargs):
            start = time.time()
            result = func(*args, **kwargs)
            end = time.time()
            print(func.__name__, end - start)
        return wrapper
    
    @timethis
    def countdown(n):
        while n > 0:
            n -= 1

    countdown(10000)

    print '-------------------------\n'

def tutorial2():
    print sys._getframe().f_code.co_name
    def timethis(func):

        # 并不知道wraps在这里有什么用
        # http://www.wklken.me/posts/2013/08/18/python-extra-functools.html
        @wraps(func)
        def wrapper(*args, **kwargs):
            start = time.time()
            result = func(*args, **kwargs)
            end = time.time()
            print(func.__name__, end - start)
            return result
        return wrapper
    
    @timethis
    def countdown(n):
        while n > 0:
            n -= 1

    countdown(10000)

    print '-------------------------\n'

def tutorial3():
    print sys._getframe().f_code.co_name
    class decorator(object):
        def __init__(self, f):
            print("inside decorator.__init__()")
            self.f = f

        def __call__(self):
            print("inside decorator.__call__")
            self.f()

    # http://blog.jobbole.com/61171/
    @decorator
    def f():
        pass

    @decorator
    def function():
        print("inside function()")

    print("finished decorating function()")

    function()

    print '-------------------------\n'



tutorial1()
tutorial2()
tutorial3()
