#include <iostream>

using namespace ::std;

int number_of_1(int n)
{
	int count = 0;
	unsigned int flg = 1;
	while (flg)
	{
		if (flg & n)
			count++;
		flg = flg << 1;
	}
	return count;
}
class Solution {
public:
	void replaceSpace(char *str, int length)
	{
		if (str == NULL || length<=0)
			return;
		int num_block = 0,num_lenth = 0;
		char *p_str = str;
		while(str[num_lenth] != '\0')//数组表示法
		{
			
			if(str[num_lenth] == ' ')
			num_block++;
			num_lenth++;
		}
		int num_all = num_lenth + num_block * 2;
		if (num_all> length)
			return;
		while (num_lenth>=0 && num_all > num_lenth)
		{
			if (str[num_lenth] == ' ')
			{
				str[num_all--] = '0';
				str[num_all--] = '2';
				str[num_all--] = '%';
			}
			else
			{
				str[num_all--] = str[num_lenth];
			}

			num_lenth--;

		}




	}
};
int main()
{

	cout<<  number_of_1(9) <<endl;
	cout << number_of_1(-1) << endl;
	cout << number_of_1(0) << endl;
	cout << number_of_1(999) << endl;
	return 0;

}