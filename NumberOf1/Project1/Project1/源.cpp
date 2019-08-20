#include <iostream>

using namespace::std;
class Solution {
public:
	int  NumberOf1(int n) {
		//移位的问题,全部用补码表示
		int i = 1,count=0,n = 0;
		while (i)
		{
			if (n&i)
				count++;
			i = i << 1;//左移1位；
		}

		return count;
	}
};

int main()
{
	Solution s;
	s.NumberOf1(2);
	return 0;


}







