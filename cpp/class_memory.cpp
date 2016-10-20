#include <iostream>

using namespace std;

class Base
{
	public:
		Base(int i) :baseI(i){};
		int getI(){ return baseI; }
		static void countI(){};
		virtual void print(void){ cout << "Base::print()"; }
		virtual void print2(void){ cout << "Base::print2()"; }
		virtual ~Base(){}
		static int i;

	private:
		int baseI;
		static int baseS;
};


void testBase( Base &p)
{
    cout << "对象的内存起始地址：" << &p << endl;

    cout << "虚函数表地址:" << (void *)(&p) << endl;
 
    //验证虚表
    cout << "虚函数表第一个函数的地址：" << (void *)*((int*)(&p)) << endl;
    cout << "析构函数的地址:" << (void* )*(int *)*((int*)(&p)) << endl;
    cout << "虚函数表中，第二个虚函数即print（）的地址：" << ((void *)*(int*)(&p) + 1) << endl;
 
    //通过地址调用虚函数print（）
    typedef void(*Fun)(void);
    Fun IsPrint = *((Fun *)*(int *)(&p) + 0);
	cout << "========================" << endl;
	cout << (int *)(&p) << endl;
	Fun pp = *((Fun *)*(int *)(&p) + 1); 
	pp();
	cout << endl <<"========================" << endl;
    cout << endl;
    cout<<"调用了虚函数: ";
    IsPrint(); //若地址正确，则调用了Base类的虚函数print（）
    cout << endl;
 
    //输入static函数的地址
    p.countI();//先调用函数以产生一个实例
    cout << "static函数countI()的地址：" << p.countI << endl;
 
    //验证nonstatic数据成员
    cout << "推测nonstatic数据成员baseI的地址：" << (int *)(&p) + 1 << endl;
    cout << "根据推测出的地址，输出该地址的值：" << *((int *)(&p) + 1) << endl;
    cout << "Base::getI():" << p.getI() << endl;
 
}

int main() {
	Base b(100);
	testBase(b);
}
