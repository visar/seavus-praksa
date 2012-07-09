#include <stdio.h>
#include <stdlib.h>

double funk(double *, size_t);

int main()
{
	int n, brojac;
	double * p;
	printf("Kolku elementi?\n");
	scanf("%d", &n);
	brojac = n;
	p = (double *)malloc(n*sizeof(double));
	while(brojac--)
	{
		scanf("%lf", &p[brojac]);
	}
	printf("Prosek: %5.2lf\n", funk(p, n));
	free(p);
	return 0;
}

double funk(double arr[], size_t n)
{
	double sum = 0.0;
	size_t tmp = n;

	while (tmp--)
	{
		sum += arr[tmp];
	}

	return sum/n;
}
