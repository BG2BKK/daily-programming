# coding=utf-8
import time, sys

def tutorial1():
    print sys._getframe().f_code.co_name

    class demo(object):
        pass
    obj = demo()
    print "Class of obj is {0}".format(obj.__class__)
    print "Class of obj is {0}".format(demo.__class__)

    print '-------------------------\n'


tutorial1()
