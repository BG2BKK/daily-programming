#!/usr/bin/python

# http://www.gitbook.net/html/postgresql/2013/080437.html
# http://www.gitbook.net/html/postgresql/2013/080998.html
import psycopg2

conn = psycopg2.connect(database="departments", user="postgres", password="huang", host="127.0.0.1", port="5432")

print "Opened database successfully"  

cur = conn.cursor()
cur.execute('''CREATE TABLE COMPANY
       (ID INT PRIMARY KEY     NOT NULL,
       NAME           TEXT    NOT NULL,
       AGE            INT     NOT NULL,
       ADDRESS        CHAR(50),
       SALARY         REAL);''')
print "Table created successfully"

conn.commit()
conn.close()  
