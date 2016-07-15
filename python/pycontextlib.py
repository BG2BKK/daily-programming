# coding=utf-8
import time, sys
from contextlib import contextmanager

def tutorial1():
    print sys._getframe().f_code.co_name
    
    class demo:
        def __init__(self, label):
            self.label = label
        def __enter__(self):
            self.start = time.time()
        def __exit__(self, exec_ty, exc_val, exc_tb):
            end = time.time()
            print("{} : {}".format(self.label, end - self.start))

    with demo("counting"):
        n = 10000000
        while n > 0:
            n -= 1

    print '-------------------------\n'

def tutorial2():
    print sys._getframe().f_code.co_name

    @contextmanager
    def demo(label):
        start = time.time()
        try:
            yield
        finally:
            end = time.time()
            print("{} : {}".format(label, end - start))

    with demo("counting"):
        n = 10000000
        while n > 0:
            n -= 1
    
    print '-------------------------\n'

    # with将上下文demo传给contextmanager，yield前相当于__init__和__enter__，yield后，调用demo，demo运行结束后，重新唤醒contextmanager，开始执行yield语句后的所有代码
 
tutorial1()
tutorial2()
