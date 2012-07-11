#include <stdio.h>
#include <stdlib.h>

int isLittleEndian(void);
void changeEndiannes(int [], size_t);
void print(int [], size_t);

int main()
{
	printf("Vnesi golemina na niza: ");
	int n;
	scanf("%d", &n);
	int * p = (int *)calloc(n, sizeof(int));
	int brojac;
	for (brojac = 0; brojac < n; brojac++)
	{
		scanf("%d", &p[brojac]);
	}
	printf("Kompjuterot raboti so %s endian\n", isLittleEndian() ? "little" : "big" );
	printf("Ova e nizata bez da se menuva endianness:\n");
	print(p, (size_t)n);
	changeEndiannes(p, (size_t)n);
	printf("Ova e nizata koga se menuva endianness:\n");
	print(p, (size_t)n);
	free(p);

	return 0;
}

int isLittleEndian(void)
{
	union
	{
		unsigned int val;
		char c[4];
	} tmp = {0x01020304};

	return tmp.c[0] == 4;
}

void print(int niza[], size_t size)
{
	char * tmp = (char *) niza;
	size_t brojac = 0;
	size_t size2 = 4 * size;
	while (brojac < size2)
	{
		printf("%02X ", tmp[brojac+3]);
		printf("%02X ", tmp[brojac+2]);
		printf("%02X ", tmp[brojac+1]);
		printf("%02X ", tmp[brojac]);
		brojac += 4;
		putchar('\t');
	}
	putchar('\n');
}

void changeEndiannes(int niza[], size_t size)
{
	while (size--)
	{
		niza[size] = (niza[size] & 0x000000ff) << 24 | (niza[size] & 0x0000ff00) << 8 | (niza[size] & 0x00ff0000) >> 8 | (niza[size] & 0xff000000) >> 24;
	}
}
