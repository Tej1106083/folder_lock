#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int i,j;
    char user[20],c;
    char lock[2][10]={" /deny "," /grant "},lockx[50];
    char file[75],password[20],passwd[20],ch;
    FILE *in=fopen("user.txt","r+"); 
    for(i=0;c!=EOF;i++)
    {
                       if(!i)fscanf(in,"%s",user);
                       else fscanf(in,"%s",passwd);
                       c=fgetc(in);
    }
    printf("Enter your password to access: ");
    for(i=0;i<20;i++)
    {
                     ch=getch();
                     if(ch=='\r')
                     {
                                 password[i]='\0';
                                 break;
                     }
                     else
                     {printf("*");password[i]=ch;}
    }
    if(!strcmp(password,passwd))
    {while(1)
    {
            main:
            system("cls");
            char cmd[200]="icacls ";
            printf("\n\n\tMenu\n\t1.Lock Folder or File\n\t2.Unlock a folder\n\t3.Exit\n\n\t");
            ch=getch();
            if(ch=='3') exit(0);
            else if(ch=='1'||ch=='2')
            {
                 if(ch=='1')i=0;
                 if(ch=='2')i=1;
                 if(i==0)
                 printf("\n\tEnter the location of the folder to be locked\n\n\t");
                 if(i==1)
                 printf("\n\tEnter the location of the folder to be unlocked\n\n\t");
                 scanf("%s",&file);
                 printf("\n"); strcpy(lockx,lock[i]);
                 strcat(lockx,user); strcat(lockx,":(F)");
                 strcat(cmd,file);
                 strcat(cmd,lockx);
                 j=system(cmd); system("cls");
                 if(j==0) 
                 {
                          if(!i) printf("\n\tFolder Successfully Locked\n\t");
                          else printf("\n\tFolder Successfully Unlocked\n\t");
                 }
                 else
                 {
                          if(!i) printf("\n\tFolder was not locked successfully\n\t");
                          else printf("\n\tFolder was not unlocked successfully\n\t");
                 }
                 system("pause");
            }
            else
            {printf("\n\tYou have entered a wrong choice"); getch(); goto main;}
    }}
    else printf("\n\nYou have entered a wrong Password");
    getch();
}
            
