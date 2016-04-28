#include "leetcode.h"
#include "stack"

class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
       s1.push(x); 
    }

    // Removes the element from in front of queue.
    void pop(void) {
		if (s2.empty()) reverse_elements();
		s2.pop();
    }

    // Get the front element.
    int peek(void) {
		if (s2.empty()) reverse_elements();
		return s2.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
		return s1.empty() && s2.empty();
    }
private:
	stack<int> s1;
	stack<int> s2;

	void reverse_elements()
	{
		while (!s1.empty())
		{
			s2.push(s1.top());
			s1.pop();
		}
	}
};

int main()
{
	Queue q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);

	cout << q.peek() << endl;
	q.pop();
	cout << q.peek() << endl;
	q.pop();

	q.push(5);
	cout << q.peek() << endl;
	q.pop();
	cout << q.peek() << endl;
	q.pop();

	cout << q.empty() << endl;

	q.push(6);
	cout << q.peek() << endl;
	q.pop();
	cout << q.peek() << endl;
	q.pop();

	cout << q.empty() << endl;
}
