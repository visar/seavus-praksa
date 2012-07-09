#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <string.h>

char * w2char(wchar_t *, size_t);
wchar_t * char2w(char *, size_t);

int main(int argc, char * argv[])
{
    wchar_t * s = L"Visar";
    char * t = w2char(s,wcslen(s));
    printf("%ls\n",s);
    printf("%s\n", t);
    free(t);
    return 0;
}

char * w2char(wchar_t * wstr, size_t len)
{
    char * str = (char *)malloc(len*sizeof(char)+1);
    char * start = str;

    while (len--)
    {
        *str = (char)(*wstr);
        str++;
        wstr++;
    }
    *str = '\0';

    return start;
}

wchar_t * char2w(char * str, size_t len)
{
    wchar_t * wstr = (wchar_t *)malloc(len*sizeof(wchar_t)+1);
    wchar_t * start = wstr;

    while (len--)
    {
        *wstr = (wchar_t)(*str);
        str++;
        wstr++;
    }
    *wstr = '\0';

    return start;
}
