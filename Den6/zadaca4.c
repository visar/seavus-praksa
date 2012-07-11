#include <stdio.h>
#include <stdlib.h>

void lower2upper(char *);

int main(int argc, char * argv[])
{
	if (argc < 2)
	{
		printf("Upotreba: %s \"niza\"\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	printf("Pred:\n%s\n", argv[1]);
	lower2upper(argv[1]);
	printf("Potoa:\n%s\n", argv[1]);
	return 0;
}

void lower2upper(char * str)
{
	while (*str)
	{
		if ('a' <= *str && *str <= 'z')
		{
			*str = *str + 'A' - 'a';
		}
		str++;
	}
}
