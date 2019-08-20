#include <iostream>
using namespace::std;
class Solution {
public:
	int NumberOf1Between1AndN_Solution(int n)
	{
		int exp = 1;
		int ans = 0;
		while (n / exp)
		{
			ans += n / (exp * 10) * exp;
			if (n % (exp * 10) / exp > 1) 
				ans += exp;
			else if (n % (exp * 10) / exp == 1) 
				ans += (n % exp + 1);
			exp *= 10;
		}
		return ans;
	}
};
int main()
{
	return 0;
}