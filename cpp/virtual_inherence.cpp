#include <iostream>

using namespace std;

class Base
{
	public:
		Base(int i) :baseI(i){};
		virtual void print(void){ cout << "调用了虚函数Base::print()"<<endl; }
		virtual void setI(){cout<<"调用了虚函数Base::setI()"<< endl;}
		virtual ~Base(){}

	private:
		int baseI;
};

int main() {
	Base b(100);
	int *vptr = (int *)&b;
	cout << vptr << endl;
	((Base )*(Base *)vptr).print();

	typedef void (* Func)(void);
	Func vfunc = (Func)*( (int *)*(int *)(&b));
	vfunc();

	vfunc = (Func)*( (Func *)( (int *)*(int *)(&b)) + 1);
	vfunc();
}
