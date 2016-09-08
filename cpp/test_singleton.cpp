#include <iostream>
using namespace std;

class Singleton
{
public:
	static Singleton *GetInstance()
	{
		if (m_Instance == NULL )
		{
			m_Instance = new Singleton ();
		}
		return m_Instance;
	}

	static void DestoryInstance()
	{
		if (m_Instance != NULL )
		{
			delete m_Instance;
			m_Instance = NULL ;
		}
	}

	// This is just a operation example
	int GetTest()
	{
		return m_Test;
	}

private:
	Singleton(){ m_Test = 10; }
	static Singleton *m_Instance;
	int m_Test;
};

Singleton *Singleton ::m_Instance = NULL;

int main(int argc , char *argv [])
{
	Singleton *singletonObj = Singleton ::GetInstance();
	cout<<singletonObj->GetTest()<<endl;

	Singleton ::DestoryInstance();
	return 0;
}
