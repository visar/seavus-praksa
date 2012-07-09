#include <stdio.h>
#include <stdlib.h>

char * int2str(int);

int main(int argc, char * argv[])
{
	printf("%s\n",int2str(atoi(argv[1])));
	return 0;
}

char * int2str(int num)
{
	int size = 0, tmp = num;
	int sign = (num >> 31) & 1;
	if (sign)
	{
		num = ~ num + 1;
	}
	while (tmp)
	{
		size++;
		tmp /= 10;
	}
	size += sign;
	char * str = (char *)malloc(size * sizeof(char) + 1);

	str[size--] = '\0';
	if (sign) {
		str[0] = '-';
	}
	while (num)
	{
		tmp = num % 10;
		str[size--] = '0' + tmp;
		num /= 10;
	}

	return str;
}
