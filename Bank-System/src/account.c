#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "account.h"
void createAccount()
{
    char name[50];
    char accInput[20];
    int accNo;
    int valid = 0;

    while (!valid)
    {
        printf("Enter Account Number (max 10 digits): ");
        scanf("%s", accInput);

        if (strlen(accInput) > 10)
        {
            printf("Account number too long. Please try again\n");
        }
        else
        {
            accNo = atoi(accInput);
            valid = 1;
        }
    }

    printf("Enter Name: ");
    scanf("%s", name);

    FILE *fp = fopen("data/accounts.txt", "a");
    fprintf(fp, "%d %s 0\n", accNo, name);
    fclose(fp);

    printf("Account Created successfully!\n");
}

void viewAccount()
{
    char accInput[20];
    int accNo;
    int valid = 0;

    while (!valid)
    {
        printf("Enter Account Number to view (max 10 digits): ");
        scanf("%s", accInput);

        if (strlen(accInput) > 10) {
            printf("Account number too long. Please try again.\n");
        } else {
            accNo = atoi(accInput);
            valid = 1;
        }
    }
    FILE *fp = fopen("data/accounts.txt", "r");
    int fileAccNo, balance;
    char name[50];
    int found = 0;

    while (fscanf(fp, "%d %s %d", &fileAccNo, name, &balance) != EOF)
    {
        if (fileAccNo == accNo)
        {
            printf("Account No: %d\nName: %s\nBalance: %d\n", fileAccNo, name, balance);
            found = 1;
            break;
        }
    }
    fclose(fp);
    if (!found)
        printf("Account not Found.\n");
}