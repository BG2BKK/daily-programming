-- http://tech.uc.cn/?p=1131

tab = {1, 4, 5, 8}
print(#tab)                    --=====> 4	#遇到nil的时候返回
print(table.getn(tab))         --=====> 4	getn遇到nil的时候返回
print(tab[4])				   -- 1 4 5 8是数字，所以按照array分配了，所以8的下标是4

tab[5] = 10
print(#tab)                    --=====> 5
print(table.getn(tab))         --=====> 5
print(tab[5])                  --=====> 10

print('----------------------------------------------')

tab = {1, 4, 5, 8}
print(#tab)                    --=====> 4	#遇到nil的时候返回
print(table.getn(tab))         --=====> 4	getn遇到nil的时候返回
print(tab[4])				   -- 1 4 5 8是数字，所以按照array分配了，所以8的下标是4

tab[9] = 10
print(#tab)                    --=====> 4
print(table.getn(tab))         --=====> 4
print(tab[5])                  --=====> nil
print(tab[9])                  --=====> 10


print('----------------------------------------------')

-- 函数名作为局部变量，存在局部变量表里，并且在栈上开辟空间；函数运行期间将会新建一个closure；新建function后，lua将它压栈，调用时从栈顶往下找，找到匹配的函数名就是返回
