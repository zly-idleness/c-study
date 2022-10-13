# include <stdio.h>
int main ()
{
    char  c;
    scanf ("%c",&c);

    if (c <= 'Z' && c>= 'A')
    {
        c += 32;
        printf ("%c %d",c , c );
    }
    else if (c <= 'z' && c>= 'a')
    {
        c -= 32;
        printf ("%c %d",c , c);
    }
    else
    printf ("%c %d",c , c);

    return 0;
}