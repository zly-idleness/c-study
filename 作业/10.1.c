#include<stdio.h>

void MyStrcpy (char* dstStr,char* srcStr)
{
    while(* srcStr != '\0')
    {
        * dstStr++ = * srcStr++;
    }
}