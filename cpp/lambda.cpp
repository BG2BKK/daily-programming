// even_lambda.cpp
// compile with: cl /EHsc /nologo /W4 /MTd
// http://www.cnblogs.com/DLzhang/p/4645978.html
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class functorClass{
public:
   explicit functorClass(int &eventCount): m_eventCount(eventCount){}
   void operator()(int n)const{
      cout << n;
      if(n % 2==0){
         cout << "is Even" << endl;
         ++m_eventCount;
      } else {
         cout << "is Odd"<<endl;
      }

   }
private:
   functorClass &operator=(const functorClass &);
   int &m_eventCount;
};

int main() 
{
   // Create a vector object that contains 10 elements.
   vector<int> v;
   for (int i = 1; i < 10; ++i) {
      v.push_back(i);
   }

   // Count the number of even numbers in the vector by 
   // using the for_each function and a lambda.
   int evenCount = 0;
   for_each(v.begin(), v.end(), functorClass(evenCount));

   // Print the count of even numbers to the console.
   cout << "There are " << evenCount 
        << " even numbers in the vector." << endl;

}