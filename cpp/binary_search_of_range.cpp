#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#include <iostream>
#include <map>
#include <algorithm>
#include <array>
using namespace std;

#define DEBUG

array<int, 10> a{91073, 16994, 4581, 72079, 84786, 85252, 47028, 93655, 60343, 90452};
map<int, int> b;

#ifdef DEBUG
int main()
{
	srand(time(NULL));
	for(auto& i : a) {
		i = rand()%100000;
	}
	for(auto& i : a) {
		cout << i << ", ";
	}
	cout << endl;
}
#endif 

#ifndef DEBUG
int main() {
	sort(a.begin(), a.end());
	for(auto it = a.begin(); it != a.end(); it++) {
		auto k = *it;
		it ++;
		if(it == a.end()) {
			cout << "end" << endl; 
			break;
		}
		auto v = *it;
		b[k] = v;
	}

	for(auto it = b.begin(); it != b.end(); it++) {
		cout << it->first << "\t"<< it->second << endl;
	}
}
#endif
