
#include <iostream>
#include <vector>

using namespace::std;
//数组的左右相加
int main()
{
	int n;
	cin >> n;
	vector<long> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	//定义头尾两个指针  头指针后移  尾指针前移
	int left = 0, right = n - 1;
	//左侧加和 与 右侧加和
	long long left_sum = 0, right_sum = 0;
	long res = 0;
	while (left <= right) //循环条件
	{
		if (left_sum < right_sum)
		{
			left_sum += v[left]; //左侧小则左边前进
			left++;

		}
		else if (left_sum > right_sum)
		{
			right_sum += v[right]; //右侧小则右边前进
			right--;

		}
		else
		{       //两侧相等 则更新答案 并且左右均前进
			res = left_sum;
			left_sum += v[left];
			right_sum += v[right];
			left++;
			right--;

		}
	}
	// 不能遗漏更新
	if (left_sum == right_sum) 
		res = left_sum;
	cout << res << endl;
	return 0;
}