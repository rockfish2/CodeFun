#include <iostream>
#include <queue>

using namespace::std;

int main()
{
	priority_queue<int> heap;
	priority_queue<int, vector<int>, greater<int>> heap2;
	heap.push(1);
	heap.push(2);
	heap.push(3);
	heap.push(4);
	heap.push(5);

	heap2.push(1);
	heap2.push(2);
	heap2.push(3);
	heap2.push(4);
	heap2.push(5);
	int top_num = heap.top();
	int top_num2 = heap2.top();

	return 0;
}