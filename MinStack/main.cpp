#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class MinStack {
public:
	void push(int x) {
		_data.push(x);
		if (_min.empty() || x <= getMin())
			_min.push(x);
	}

	void pop() {
		if (top() == getMin())
			_min.pop();
		_data.pop();
		
	}

	int top() {
		return _data.top();
	}

	int getMin() {
		return _min.top();
	}
private:
	stack<int> _data;
	stack<int> _min;
};

int main()
{
	MinStack S;

	return 0;
}