
#include <iostream>
#include <vector>

using namespace::std;
//������������
int main()
{
	int n;
	cin >> n;
	vector<long> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	//����ͷβ����ָ��  ͷָ�����  βָ��ǰ��
	int left = 0, right = n - 1;
	//���Ӻ� �� �Ҳ�Ӻ�
	long long left_sum = 0, right_sum = 0;
	long res = 0;
	while (left <= right) //ѭ������
	{
		if (left_sum < right_sum)
		{
			left_sum += v[left]; //���С�����ǰ��
			left++;

		}
		else if (left_sum > right_sum)
		{
			right_sum += v[right]; //�Ҳ�С���ұ�ǰ��
			right--;

		}
		else
		{       //������� ����´� �������Ҿ�ǰ��
			res = left_sum;
			left_sum += v[left];
			right_sum += v[right];
			left++;
			right--;

		}
	}
	// ������©����
	if (left_sum == right_sum) 
		res = left_sum;
	cout << res << endl;
	return 0;
}