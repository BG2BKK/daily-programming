# encode = utf-8 
# http://python.jobbole.com/85611/
def my_info(func):
    def wrapper(*args, **params):
        print 1234
        return func(*args, **params)
    return wrapper

@my_info 
def my_name():
    print 'huang'

my_name()

def c_info(text):
    def my_info(func):
        def wrapper(*args, **params):
            print text
            print 1234
            return func(*args, **params)
        return wrapper
    return my_info

@c_info("brandon")
def my_name():
    print "huang"

my_name()
