#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
	unsigned M = atoi(argv[1]), N = atoi(argv[2]), tmp, tmp1;
	tmp1 = N;

	while (N--)
	{
		tmp = M;
		while (tmp--)
		{
			putchar('*');
		}
		putchar('\n');
	}

	putchar('\n');
	putchar('\n');

	N = tmp1;

	while (N--)
	{
		tmp = M;
		if (N == 0 || N == tmp1-1)
		{
			while (tmp--)
			{
				putchar('*');
			}
			putchar('\n');
			continue;
		}
		putchar('*');
		tmp-=2;
		while (tmp--)
		{
			putchar(' ');
		}
		putchar('*');
		putchar('\n');
	}

	return 0;
}
