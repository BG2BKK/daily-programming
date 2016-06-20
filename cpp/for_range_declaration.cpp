// https://msdn.microsoft.com/zh-cn/library/jj203382.aspx
#include <iostream>
#include <boost/shared_ptr.hpp>
#include <vector>
using namespace std;
/*
 *
	unique_ptr<Song> SongFactory(const std::wstring& artist, const std::wstring& title)
	{
		// Implicit move operation into the variable that stores the result.
		return make_unique<Song>(artist, title);
	}

	void MakeSongs()
	{
		// Create a new unique_ptr with a new object.
		auto song = make_unique<Song>(L"Mr. Children", L"Namonaki Uta");

		// Use the unique_ptr.
		vector<wstring> titles = { song->title };

		// Move raw pointer from one unique_ptr to another.
		unique_ptr<Song> song2 = std::move(song);

		// Obtain unique_ptr from function that returns by value.
		auto song3 = SongFactory(L"Michael Jackson", L"Beat It");
	}
*
*/


int main(){

	int x[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	for (int y : x) {
		cout << y << " ";
	}
	cout << endl;

	for (auto y : x) {
		cout << y << " ";
	}
	cout << endl;

	for (auto &y : x) {
		cout << y << " ";
	}
	cout << endl;

	for (const auto &y : x) {
		cout << y << " ";
	}
	cout << endl;

	vector<double> v;
	for ( int i = 0; i < 10; i++) {
		v.push_back(i + 0.14159);
	}

	for ( const auto &y : v) {
		cout << y << " ";
	}
	cout << endl;

}
