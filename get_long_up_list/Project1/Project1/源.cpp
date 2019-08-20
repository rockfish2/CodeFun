#include <iostream>
#include <stack>
#include <vector>


using namespace::std;
vector<int> v;



int get_up(int *array,int length)
{
	
	stack<int>  new_a;
	if (array == NULL)
		return 0;
	int count = 0;
	//int length = sizeof(array) / sizeof(array[0]);
	new_a.push(array[0]);
	for (int i = 1; i < length; i++)
	{
		if (array[i] > new_a.top())
		{
			new_a.push(array[i]);
		}
		else
		{
			new_a.pop();
			new_a.push(array[i]);
		}

	}
	return new_a.size();

}

int main()
{
	int a[] = { 1,6,2,3,7,5 };
	cout << get_up(a,6);
	return 0;
}