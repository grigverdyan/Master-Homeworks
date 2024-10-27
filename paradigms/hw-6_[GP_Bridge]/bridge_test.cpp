// Bridge.cpp : Defines the entry point for the console application.
//

#include "List.h"
#include "Stack.h"
#include "Queue.h"
#include <iostream>
using namespace std;

int main()
{
	Stack<char, List<char>> s;
	cout << endl << "*** STACK: a, b, c are sequentially pushed and popped ***" << endl;
	s.push('a'); s.push('b'); s.push('c');
	while (!s.empty()) {
		cout << s.top() << endl;
		s.pop();
	}
	cout << endl;

	Queue<char, List<char>> q;
	cout << endl << "*** QUEUE: a, b, c are sequentially pushed and popped ***" << endl;
	q.push('a'); q.push('b'); q.push('c');
	while (!q.empty()) {
		cout << q.top() << endl;
		q.pop();
	}
	cout << endl;

	return 0;
}