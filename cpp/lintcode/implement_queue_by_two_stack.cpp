#include <stack>
#include <iostream>
using namespace std;

class Queue {
public:
    stack<int> stack1;
    stack<int> stack2;

    Queue() {
        // do intialization if necessary
    }

    void push(int element) {
        stack1.push(element);
    }
    
    int pop() {
        // write your code here
        int val;
        if(stack2.size() > 0){
            val = stack2.top();
            stack2.pop();
            // return val;
        } else {
            while(!stack1.empty()){
                val = stack1.top();
                stack1.pop();
                stack2.push(val);
            }
            val = stack2.top();
            stack2.pop();
            
        }
        return val;
    }

    int top() {
        // write your code here
        int val;
        if(stack2.size() > 0){
            val = stack2.top();
            // stack2.pop();
            // return val;
        } else {
            while(!stack1.empty()){
                int val = stack1.top();
                stack1.pop();
                stack2.push(val);
            }
            val = stack2.top();
        }
        return val;
    }
};

int main(){
	Queue queue;
	int val;
	queue.push(1);
	val = queue.pop();
	cout << val << endl;

	queue.push(2);
	queue.push(3);
	val = queue.top();
	cout << val << endl;
	val = queue.pop();
	cout << val << endl;
}

