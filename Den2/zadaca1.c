#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

void print(void *, size_t);

int main()
{
	char buffer2[64];
	int buffer3[64];
	long buffer4[64];
	long long buffer5[64];
	char buffer[] = {
		0x23, 0xFF, 0x0D, 0x48, 0xEA, 0xDE, 0xBB, 0x8C
	};
	unsigned brojac;
	srand(time(NULL));

	for(brojac = 64; brojac; brojac--)
	{
		buffer2[brojac] = (char)(rand() * CHAR_MAX + 1);
	}

	for(brojac = 64; brojac; brojac--)
	{
		buffer3[brojac] = (int)(rand() * INT_MAX + 1);
	}

	for(brojac = 64; brojac; brojac--)
	{
		buffer4[brojac] = (long)(rand() * LONG_MAX + 1);
	}

	for(brojac = 64; brojac; brojac--)
	{
		buffer5[brojac] = (long long)(rand() * LLONG_MAX + 1);
	}


	print((void *)buffer2, sizeof(buffer2));
	print(buffer2, sizeof(buffer2));
	print(buffer3, sizeof(buffer3));
	print(buffer4, sizeof(buffer4));
	print(buffer5, sizeof(buffer5));
	print(buffer, sizeof(buffer));

	return 0;
}

void print(void * buffer, size_t size)
{
	unsigned char * tmp = (unsigned char *) buffer;
	size_t len = size;

	while (len)
	{
		printf("0x%02X; ", *tmp);
		tmp++;
		len--;
	}

	putchar('\n');

	unsigned short * tmp2 = (unsigned short *) buffer;

	len = size;
	while (len)
	{
		printf("0x%04X; ", ((*tmp2 & 0x00ff) << 8) | ((*tmp2 & 0xff00) >> 8));
		tmp2++;
		len -= 2;
	}

	putchar('\n');

	unsigned int * tmp3 = (unsigned int *) buffer;

	len = size;
	while (len)
	{
		printf("0x%08X; ", (*tmp3 & 0x000000ff) << 24 | (*tmp3 & 0x0000ff00) << 8 | (*tmp3 & 0x00ff0000) >> 8 | (*tmp3 & 0xff000000) >> 24);
		tmp3++;
		len -= 4;
	}

	putchar('\n');
}
