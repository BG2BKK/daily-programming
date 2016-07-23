#!/usr/bin/python

# http://www.gitbook.net/html/postgresql/2013/080437.html
# http://www.gitbook.net/html/postgresql/2013/080998.html
import psycopg2

def conn2db():
    conn = psycopg2.connect(database="testdb", user="postgres", password="huang", host="127.0.0.1", port="5432")
    return conn

def init(conn):
    cur = conn.cursor()
    cur.execute("drop TABLE test")
    cur.execute("create TABLE test ( id serial PRIMARY KEY, num integer, data varchar)")
    cur.execute("insert into test (num, data) VALUES (%s, %s)", [100, "hello world"])
    cur.execute("insert into test (num, data) VALUES (%s, %s)", [190, "mydream"])
    conn.commit()

def test(conn):
    cur = conn.cursor()
    cur.execute("insert into test (num, data) VALUES (%s, %s), (%s, %s), (%s, %s);", (190, "mydream2", 200, "abc", 2354, "postgre"))
    conn.commit()

def query(conn, num):
    cur = conn.cursor()
    cur.execute("select * from test where data LIKE 'my%'")
    conn.commit()
    
    try:
        for x in cur.fetchmany(1):
            print x
        for x in cur.fetchone():
            print x
    except:
        pass

def update(conn, key, val):
    cur = conn.cursor()
    cur.execute("update test set data = 'another' where data = 'mydream' ")
    conn.commit()

def delete(conn, key, val):
    cur = conn.cursor()
    cur.execute("delete from test where data = 'mydream2' ")
    conn.commit()

def orderby(conn, key):
    cur = conn.cursor()
    cur.execute("select * from test order by %s,data desc"%key)
    conn.commit()

    for x in cur.fetchmany(100):
        print x
 
def epilog(conn):
    conn.close()  

conn = conn2db()
print "Opened database successfully"  
init(conn)
print "init table successfully"  

test(conn)

query(conn, 190)
update(conn, 'num', 19999)
orderby(conn, "num")
delete(conn, 'num', 19999)

epilog(conn)
print "done"
