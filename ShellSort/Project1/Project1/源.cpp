#include <iostream>

using namespace::std;
#define MAXSIZE 10
typedef struct 
{
	int length;
	int r[MAXSIZE];

}SqList;

void ShellSort(SqList *L)
{
	int i, j;
	int increment = L->length;
	do {
		increment = increment / 3 + 1;//set increment
		for(i= increment+1;i <= L->length;i++)//
		{
			/*比较增量前后的值，后方的值比较大时*/
			if (L->r[i] < L->r[i - increment])
			{
				/*保存临时变量*/
				L->r[0] = L->r[i];
				/**/
				for (j = i- increment ; j>0 && L->r[0]<L->r[j] ; j -= increment)
				{
					L->r[j+ increment] = L->r[j];
				}

				L->r[j+ increment] = L->r[0];
			}
		}

	} while (increment > 1);

}

int main()
{
	SqList L;
	int temp[10] = { 0,9,11,5,8,3,7,4,6,2 };
	L.length = 9;
	memcpy(L.r, temp, sizeof(temp));//if char strcpy(a,b);
	ShellSort(&L);
	return 0;
}