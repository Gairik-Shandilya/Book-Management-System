#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void insert();
void search();

struct book
{
    int book_code;
    char name[50];
    char author[50];
};
struct book s;
void main()
{
    int choice;
    while (choice != 3)
    {
        printf("\n\n");
        printf("\t'WELCOME TO SRM LIBRARY DATABASE'\n\n\n");

        printf("\t\t****Available Options****\n\n");
        printf("\t\t1: Insert Book record\n");
        printf("\t\t2: Search Book record\n");
        printf("\t\t3: Exit\n\n");
        printf("\t\tEnter Your Choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            system("cls");
            insert(); 
            break;
        case 2:
            system("cls");
            search();
            break;
        case 3:
            exit(1);
            break;

        default:
            printf("\n\t\t!!! You Entered The Wrong Choice !!!\n\n");
        }
        getchar(); 
    }
}

void insert()
{
    FILE *fp;
    fp = fopen("books.txt", "a+");
    printf("\n\n\t\t^^^^ ENTER NEW BOOK DATA ^^^^");
    printf("\n\n\t\tEnter Book Code : ");
    scanf("%d", &s.book_code);
    fflush(stdin);
    printf("\n\t\tEnter Book's Name : ");
    gets(s.name);
    printf("\n\t\tEnter Author's Name : ");
    gets(s.author);
    fwrite(&s, sizeof(s), 1, fp);
    {
        printf("\n\n\tBook Database Recorded Successfully !!!\n");
    }
    fclose(fp);
    printf("\n\t\tRecord Updated !!!\n\n");
}

void search()
{
    int code, flag = 0;
    FILE *fp;
    fp = fopen("books.txt", "r");
    if (fp == NULL)
    {
        printf("\n\t\tError : File Does Not Exist !!! ");
        return;
    }
    printf("\n\n\tEnter Student Book Code which You Want To Search : ");
    scanf("%d", &code);
    while (fread(&s, sizeof(s), 1, fp) > 0 && flag == 0)
    {
        if (s.book_code == code)
        {
            flag = 1;
            printf("\n\nSearch Successfull And Book Records is as follows:");
            printf("\nBook Code: %d", s.book_code);
            printf("\nName of the Book: %s",s.name);
            printf("\nName of The Author: %s\n\n",s.author);
        }
    }
    if (flag == 0)
    {
        printf("\n\n\t\t!!! No Record Found !!!\n\n");
    }
    fclose(fp);
}
