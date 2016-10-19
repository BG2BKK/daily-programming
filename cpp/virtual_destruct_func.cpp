#include <iostream>
using namespace std;

class ClxBase {
	public:
		ClxBase() {};
		virtual ~ClxBase() { cout << "output from the destructor of class ClxBase" << endl; };
		virtual void DoSomething() { cout << "Do something in class ClxBase" << endl; };
};

class ClxDerived:public ClxBase
{

	public:
		ClxDerived() {};
		~ClxDerived() { cout << "output from the destructor of class ClxDerived" << endl;};

		void DoSomething() { cout << "Do something in class ClxDerived!" << endl; };
};

int main() {
	ClxBase *pTest = new ClxDerived;
	pTest->DoSomething();
	delete pTest;
}
