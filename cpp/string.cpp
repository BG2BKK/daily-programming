#include <iostream>
#include <string.h>
using namespace std;

class String {
	public:
		String(const char *str = NULL);
		String(const String &other);
		~String(void);
		String & operator =( const String &other);
		const void print() {
			cout << m_data << "\t" << &m_data<< endl;
		}
	private:
		char *m_data;
};

String::String(const char *str) {
	if(str == NULL) {
		m_data = new char[1];
		*m_data = '\0';
	} else {
		int len = strlen(str);
		m_data = new char[len+1];
		strcpy(m_data, str);
	}
}

String::String(const String &other) {
	cout << " copy constructor "<<endl;
	int len = strlen(other.m_data);
	m_data = new char[len+1];
	strcpy(m_data, other.m_data);
}

String &String::operator =(const String &other) {
	cout << " assign constructor "<<endl;
	if( this == &other) {
		return *this;
	}

	delete []m_data;
	int len = strlen(other.m_data);
	m_data = new char[len+1];
	strcpy(m_data, other.m_data);
	return *this;
}

String::~String() {
	delete []m_data;
}

int test() {
	static int cnt = 0;
	cout << cnt ++ << endl;
}

int main() {
	String s("hello");
	String t(s);
	String m = s;
	String n;
	n = s;


	s.print();
	t.print();
	m.print();
	n.print();


	test();
	test();
	test();

}
