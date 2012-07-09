#include <stdio.h>

int main(int argc, char * argv[])
{
	int niza[10], suma = 0;
	size_t size = 10;
	double prosek = 0;
	while (size--)
	{
		scanf("%d", &niza[size]);
		suma += niza[size];
	}
	prosek = suma / 10.;
	size = 9;
	int max = niza[9], min = niza[9];
	while (size--)
	{
		if (max < niza[size])
		{
			max = niza[size];
		}
		if (min > niza[size])
		{
			max = niza[size];
		}

	}

	printf("Suma:\t%5d\nProsek:\t%5.2lf\nMax:\t%5d\nMin:\t%5d\n", suma, prosek, max, min);

	return 0;
}
