#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "server.h"
#define buffsize 1000
void delgroupGname(char deletinggroup[])//a function which deletes a group name present in group and gshadow files
{
    char PFILE[]="C:/Users/PAVAN KUMAR M S/Desktop/C_MiniProject/PROJECT";
    char str[buffsize];//str=variable to store the informations in the files
    char group[]="group.txt";                         /*declaration of the files*/
    char gshadow[]="gshadow.txt";
    char newgroup[]="newgroup.txt";//PFILE = C:/Users/PAVAN KUMAR M S/C_MiniProject/PROJECT/(in my computer)
    char newgshadow[]="newgshadow.txt";
    FILE *fp;
    FILE *fp1;//file pointer declarations which helps in the reading writing of files
    FILE *fp2;
    FILE *fp3;
    fp=fopen(group,"r");//used ton open the file
    int l1=1;
    while((fgets(str,buffsize,fp))!=NULL)//reads the file till it encounters null reads line by line
    {
        int a=strcmp(strtok(str,":"),deletinggroup);//to cut the string using specific point and adds /0 to it
        if(!a)
        {
            break;
        }
        else
        {
            l1++;
        }
    }
    fclose(fp);
    fp1=fopen(gshadow,"r");
    int l2=1;
    while((fgets(str,buffsize,fp))!=NULL)
    {
        int a=strcmp(strtok(str,":"),deletinggroup);//a=used to store the output which is used for the cutting of lines
        if(!a)
        {
            break;
        }
        else
        {
            l2++;
        }
    }
    fclose(fp1);
    fp=fopen(group,"r");
    fp2=fopen(newgroup,"w");
    char ch = fgetc(fp);
    int temp=1;//temp=used to increment,when lines are jumped
    while(ch!=EOF)//here writing of the file occurs to get the new file without the group name you want to delete
    {
        if(ch=='\n')//ch=reads every character of file
        {
            temp++;
        }
        if(temp!=l1)
        {
            putc(ch,fp2);
        }
        ch=fgetc(fp);
    }
    fclose(fp);//used to close the file
    fclose(fp2);
    fp1=fopen(gshadow,"r");
    fp3=fopen(newgshadow,"w");
    char ch2 = fgetc(fp1);
    int temp1=1;
    while(ch2!=EOF)
    {
        if(ch2=='\n')
        {
            temp1++;
        }
        if(temp1!=l1)
        {
            putc(ch2,fp3);
        }
        ch2=fgetc(fp1);
    }
    fclose(fp1);
    fclose(fp3);
    remove(group);//removing the file
    rename(newgroup,group);//renaming the file
    printf("*********************************new group file********************************\n");
    fp=fopen(group,"r");
    char ch4=fgetc(fp);    //printing the contents of file if necessary
    while(ch4!=EOF)
    {
        printf("%c",ch4);
        ch4=fgetc(fp);
    }
    printf("\n");
    printf("********************************************************************************\n");
    printf("\n\n\n\n");
    remove(gshadow);
    rename(newgshadow,gshadow);
    printf("**********************************new gshadow file***************************\n");
    fp1=fopen(gshadow,"r");
    char ch3=fgetc(fp1);
    while(ch3!=EOF)
    {
        printf("%c",ch3);
        ch3=fgetc(fp1);
    }
    printf("\n");
    printf("********************************************************************************\n");
}
