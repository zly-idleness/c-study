#include <stdio.h>
#define N 10
 
struct Person {
	char name[11];
	char birthday[11];
	char sex;           
	char fixed[17];     
	char mobile[17];     
};
 
int main(void)
{
	struct Person p[N];
	int num[N];
	int i, n, k;
	scanf("%d", &n);
	for(i = 0; i < n; ++i)
		scanf("%s %s %c %s %s", p[i].name, p[i].birthday, 
		      &p[i].sex, p[i].fixed, p[i].mobile);
	scanf("%d", &k);
		
	for(i = 0; i < k; ++i) {
        scanf("%d", &num[i]);
        if(num[i] >= 0 && num[i] < n)
			{printf("%s %s %s %c %s\n", p[num[i]].name, 
			       p[num[i]].fixed, p[num[i]].mobile, p[num[i]].sex, p[num[i]].birthday);
            }else
			printf("Not Found\n");
	}
	return 0;
}


