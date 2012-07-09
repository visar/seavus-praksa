#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
	unsigned N = atoi(argv[1]);
	unsigned M = 1, tmp;
	while (N--)
	{
		tmp = M-1;
		do
		{
			putchar('*');
		}
		while (tmp--);
		/* while (tmp--) */
		/* { */
		/*	putchar('*'); */
		/* } */
		putchar('\n');
		M++;
	}
	return 0;
}
