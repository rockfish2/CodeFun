#include <iostream>
#include<stdio.h>
#include<string.h>


using namespace std;
//思路：申明两个数组分别用来存储从左侧开始计算的方差，
//和从右侧开始计算的方差，最后将两个数组错一位相加，取和值最小的位点返回。

int minVar(float *a, int n)
{
	float *left = new float[n];
	float *right = new float[n];

	float leftsum = 0;
	float rightsum = 0;
	float leftSquareSum = 0;
	float rightSquareSum = 0;

	memset(left, 0, n);
	memset(right, 0, n);

	for (int i = 0; i < n; i++)
	{
		leftsum += a[i];
		leftSquareSum += a[i] * a[i];
		left[i] = leftSquareSum / (i + 1) - (leftsum / (i + 1))*(leftsum / (i + 1));
	}
	    /*
	    for(int i=0;i<n;i++)
	    {
	        cout<<left[i]<<endl;
	    }*/

	for (int i = n - 1; i >= 0; i--)
	{
		rightsum += a[i];
		rightSquareSum += a[i] * a[i];
		right[i] = rightSquareSum / (n - i) - (rightsum / (n - i))*(rightsum / (n - i));
	}
	   /*
	    for(int i=0;i<n;i++)
	    {
	        cout<<right[i]<<endl;
	    }
	    */
	for (int i = 0; i < n - 1; i++)
	{
		left[i] += right[i + 1];
	}

	    /*
	    cout<<endl;
	    for(int i=0;i<n;i++)
	    {
	        cout<<left[i]<<endl;
	    }
	   */

	float minvar = left[0];
	int pos = 0;
	for (int i = 0; i < n; i++)
	{
		if (minvar > left[i])
		{
			minvar = left[i];
			pos = i;
		}
	}
	cout << "minVar:" << minvar << endl;
	return (pos + 1);
}

int main()
{
	float a[10] = { 1,2,3,4,5,11,12,13,14,15 };
	cout << "pos:" << minVar(a, 10) << endl;
	return 0;
}
