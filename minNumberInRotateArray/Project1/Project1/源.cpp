#include <iostream>
#include <vector>
#include <algorithm>
using namespace::std;
//��һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת�� 
//����һ���Ǽ�����������һ����ת�������ת�������СԪ�ء�
//��������{ 3,4,5,1,2 }Ϊ{ 1,2,3,4,5 }��һ����ת�����������СֵΪ1��
//NOTE������������Ԫ�ض�����0���������СΪ0���뷵��0��
class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		if (rotateArray.empty())
			return 0;
		sort(rotateArray.begin(), rotateArray.end());
		return rotateArray[0];
	}
};