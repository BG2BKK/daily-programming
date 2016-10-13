
/*
 * https://solarianprogrammer.com/2011/12/16/cpp-11-thread-tutorial/
*/

#include <iostream>
#include <thread>

static const int num_threads = 10;

void call_from_thread(int tid) {
	std::cout << "launched by thread " << tid << std::endl;
}

int main() {
	std::thread t[num_threads];

	for(int i=0; i < num_threads; i++) {
		t[i] = std::thread(call_from_thread, i);
	}

	std::cout << "launched from the main\n";

	for(int i=0; i < num_threads; i++) {
		t[i].join();
	}
}
