#include <stdio.h>
 
int main()
{
	int i, j;
    int b[10];
	for ( i=0; i<10; i++ )
	{
		b[i] = 0;
	}
	for ( i=0; i<10; i++ )
	{
		scanf("%d", &b[i]);
	}
	for ( i=1; i<10; i++ )
	{
		if (b[i])
		{
			printf("%d", i);
			b[i]--;
			break;
		}
	}
	for ( i=0; i<10; i++ )
	{
		for ( j=0; j<b[i]; j++ )
		{
			printf("%d", i);
		}
	}
	printf("\n");
	
	return 0;
}

