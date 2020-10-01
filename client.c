#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "server.h"
int main(int argc,char *argv[])
{
    if(argc==2)
        delgroupGname(argv[1]);
    else
        printf("Please Enter the correct input");
    return 0;
}
