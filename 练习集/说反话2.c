#include <stdio.h>
#include <string.h>
 

 
int main(void)
{
   char str[81]; 
	int i, k;
	char *p;
    fgets(str,81,stdin);
	k = strlen(str);
	p = str + k;
	while (1)
	{
		if ( p == str )
		{
			printf("%s", p);
			break;
		}
		if (*p == ' ' && *(p+1) != ' ')
		{
			*p = '\0';
			printf("%s ", p+1);
		}
		p--;
	}
	return 0;
}

