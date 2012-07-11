#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void cisti(char *);

int main(int argc, char * argv[])
{
	if (argc < 2)
	{
		printf("Upotreba: %s \"niza\"\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	printf("Pred:\n%s\n", argv[1]);
	cisti(argv[1]);
	printf("Potoa:\n%s\n", argv[1]);

	return 0;
}

void cisti(char * str)
{
	char * tmp = str;

	while (*str)
	{
		if (isspace(*str) || ispunct(*str))
		{
			str++;
			continue;
		}
		*(tmp++) = *(str++);
	}
	*tmp = '\0';
}
