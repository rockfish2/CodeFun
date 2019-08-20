#include <iostream>

 class Sort {

	public static void MergeSort2(int[] arr)
	{
		//ʹ�÷ǵݹ�ķ�ʽ��ʵ�ֹ鲢����
		int len = arr.length;
		int k = 1;

		while (k < len)
		{
			MergePass(arr, k, len);
			k *= 2;
		}
	}

	//MergePass�������������е����ڵ���k��Ԫ�ص������н��й鲢
	private static void MergePass(int[] arr, int k, int n)
	{
		int i = 0;
		int j;

		//��ǰ����,��2������Ϊk�������кϲ�Ϊ1��
		while (i < n - 2 * k + 1)
		{
			merge(arr, i, i + k - 1, i + 2 * k - 1);
			i += 2 * k;
		}

		//��δ��뱣֤�ˣ�����Щ���䵥�ġ����Ȳ�������merge�Ĳ��ֺ�ǰ��merge������
		if (i < n - k)
		{
			merge(arr, i, i + k - 1, n - 1);
		}

	}

	//merge����ʵ�����ǽ�������������ϲ���һ����������
	//��Ϊ�������򣬺ϲ��ܼ򵥣�ֻҪά������ָ��Ϳ�����
	private static void merge(int[] arr, int low, int mid, int high)
	{
		//temp���������ݴ�ϲ��Ľ��
		int[] temp = new int[high - low + 1];
		//���ߵ�ָ��
		int i = low;
		//�Ұ�ߵ�ָ��
		int j = mid + 1;
		//�ϲ��������ָ��
		int k = 0;

		//����¼��С����طŽ�temp����
		for (; i <= mid && j <= high; k++)
		{
			if (arr[i] < arr[j])
				temp[k] = arr[i++];
			else
				temp[k] = arr[j++];
		}

		//����������whileѭ����Ϊ�˽�ʣ��ģ�����һ�߶�����ĸ������ŵ�temp������
		while (i <= mid)
			temp[k++] = arr[i++];

		while (j <= high)
			temp[k++] = arr[j++];

		//��temp�����е�Ԫ��д�뵽����������
		for (int l = 0; l < temp.length; l++)
			arr[low + l] = temp[l];
	}
 }