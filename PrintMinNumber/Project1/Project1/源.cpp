#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace::std;
class Solution {//�ο��߷ִ�
public:
	static bool cmp(int a, int b) {
		string A = "";
		string B = "";
		A += to_string(a);
		A += to_string(b);
		B += to_string(b);
		B += to_string(a);
		return A < B;
	}
	string PrintMinNumber(vector<int> numbers) {
		string  answer = "";
		sort(numbers.begin(), numbers.end(), cmp);//����sort��������
		for (int i = 0; i < numbers.size(); i++)
		{
			answer += to_string(numbers[i]);
		}
		return answer;
	}									                                                            
};
int main()
{

	return 0;
}