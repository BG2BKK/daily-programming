# coding=utf-8
import time, sys
import weakref

def tutorial1():
    print sys._getframe().f_code.co_name
    class Celsius(object):
        def __init__(self, value=0.0):
            print('__init__')
            self.value = float(value)
        def __get__(self, instance, owner):
            print('__get__')
            return self.value
        def __set__(self, instance, value):
            self.value = float(value)

    class Temperature(object):
        celsius = Celsius()

    temp = Temperature()

    print('\n---')

    temp.celsius
   
    print '-------------------------\n'

def tutorial2():
    print sys._getframe().f_code.co_name
  
    class lazyattribute(object):
        def __init__(self, f):
            self.data = weakref.WeakKeyDictionary()
            self.f = f
        def __get__(self, obj, cls):
            if obj not in self.data:
                self.data[obj] = self.f(obj)
            return self.data[obj]
    class Foo(object):
        @lazyattribute
        def bar(self):
            print "Being lazy"
            return 42

    f = Foo()
    print f.bar

    print f.bar
    print '-------------------------\n'


tutorial1()
tutorial2()
