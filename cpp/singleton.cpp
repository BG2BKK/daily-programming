
/*
 * http://www.zkt.name/dan-li-mo-shi-singleton-ji-c-shi-xian/
 */

#include <iostream>

// #define Eager_Singleton
#define Meyers_Singleton

#ifdef Lazy_Singleton
class Singleton {
	public:
		static Singleton& Instance() {
			if ( instance_ == NULL) {
				instance_ = new Singleton;
			} 
			return *instance_;
		}
	private:
		Singleton();
		~Singleton();
		Singleton(const Singleton &);
		Singleton & operator=(const Singleton &);
	private:
		static Singleton *instance_;
};

Singleton* Singleton::instance_ = NULL;
#endif

#ifdef  Eager_Singleton
class Singleton {
	public:
		static Singleton& Instance() {
			return instance;
		}
	private:
		Singleton();
		~Singleton();
		Singleton(const Singleton&);
		Singleton& operator=(const Singleton&);
	private:
		static Singleton instance;
};
#endif

#ifdef Meyers_Singleton
class Singleton {
	public:
		static Singleton& Instance() {
			static Singleton instance;
			return instance;
		}

	private:
		Singleton();
		~Singleton();
		Singleton(const Singleton &);
		Singleton & operator=(const Singleton &);
};
#endif

int main() {
}
