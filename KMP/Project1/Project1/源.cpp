#include <iostream>
#include <string>

using namespace::std;
typedef int pathM[5][5];

void get_next(string T,int *next )
{
	int i, j;
	i = 1;
	j = 0;
	next[1] = 0;
	while (i < 6)
	{
		if ( (j == 0) || T[i] == T[j])
		{
			++i;
			++j;
			next[i] = j;
		}
		else
			j = next[j];
	}

}
int main()
{
	int next[7] = {0};
	string t = "cabcdef";
	get_next(t, next);
	return 0;
}