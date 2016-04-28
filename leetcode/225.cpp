#include "leetcode.h"
#include <queue>

class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
		current->push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
		move_current_to_alternative();
		current->pop();
		swap(current, alternative);
    }

    // Get the top element.
    int top() {
		move_current_to_alternative();
		int ret = current->front();
		current->pop();
		alternative->push(ret);

		swap(current, alternative);
		return ret;
    }

    // Return whether the stack is empty.
    bool empty() {
		return q1.empty() && q2.empty();
    }
private:
	queue<int> q1;
	queue<int> q2;

	queue<int> *current = &q1;
	queue<int> *alternative = &q2;

	void move_current_to_alternative()
	{
		while (current->size() != 1)
		{
			int x = current->front();
			current->pop();
			alternative->push(x);
		}
	}
};

int main()
{
	Stack q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);

	cout << q.top() << endl;
	q.pop();
	cout << q.top() << endl;
	q.pop();

	q.push(5);
	cout << q.top() << endl;
	q.pop();
	cout << q.top() << endl;
	q.pop();

	cout << q.empty() << endl;

	q.push(6);
	cout << q.top() << endl;
	q.pop();
	cout << q.top() << endl;
	q.pop();

	cout << q.empty() << endl;
}
