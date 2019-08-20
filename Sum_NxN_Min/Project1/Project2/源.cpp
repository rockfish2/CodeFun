#include <iostream>
#include <stack>


using namespace::std;


int get_up(int *array)
{
	stack<int>  new_a;
	if (array == NULL)
		return 0;	
	int count =0;
	int length = sizeof(array) / sizeof(array[0]);
	new_a.push(array[0]);
	for (int i=1;i< length;i++)
	{
		if (array[i] > new_a.top)
		{
			new_a.push(array[i]);
		}
		else
		{
			new_a.pop;
			new_a.push(array[i]);
		}

	}
	return new_a.size;

}

int main()
{
	int a[] = { 1,6,2,3,7,5 };
	cout << get_up(a);
	return 0;
}