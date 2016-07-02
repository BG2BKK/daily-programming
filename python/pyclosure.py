def test_closure():
    n = 1
    def inner():
        print(n)
        nonlocal n
        n = '4'
    inner()
    
#    n = 'x'
    inner()

    print('-------------------------\n')

test_closure()
