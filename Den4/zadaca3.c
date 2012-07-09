#include <stdio.h>
#include <stdlib.h>

char * int2str(int, int);
char * int2str2(int);

int main(int argc, char * argv[])
{
	printf("%s\n",int2str(atoi(argv[1]), atoi(argv[2])));
	return 0;
}

char * int2str(int num, int w)
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
	if (size >= w)
	{
		return int2str2(num);
	}
	char * str = (char *)malloc(w * sizeof(char) + 1);

	str[w--] = '\0';

	while (num)
	{
		tmp = num % 10;
		str[w--] = '0' + tmp;
		num /= 10;
	}

	if (sign) {
		str[w--] = '-';
	}
	while (w)
	{
		str[w--] = ' ';
	}
	str[0] = ' ';

	return str;
}

char * int2str2(int num)
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
