#include <stdio.h>
#include <stdlib.h>

int hash(char *);

int main(int argc, char * argv[])
{
	int nbytes = 0;
	char *str = (char *) malloc (1);
	printf("Vnesi niza od karakteri, ke vratam hash od taa niza:\n");
	while (getline(&str, (size_t *)&nbytes, stdin) > 0)
	{
		printf("Vnesi niza od karakteri, ke vratam hash od taa niza:\n");
		printf("%d\n", hash(str));
	}

	return 0;
}

int hash(char * niza)
{
	int tmp = 0;
	while (*niza != '\n')
	{
		tmp ^= (*niza);
		niza++;
	}
	return tmp;
}
