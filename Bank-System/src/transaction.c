#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "transaction.h"

void depositMoney(){
    updateBalance(1);
}

void withdrawMoney(){
    updateBalance(0);
}

void updateBalance(int isDeposit){
    char accInput[20];
    int accNo, amount, valid=0;

   
    while (!valid) {
        printf("Enter Account Number to view (max 10 digits): ");
        scanf("%s", accInput);

        if (strlen(accInput) > 10) {
            printf("Account number too long. Please try again.\n");
        } else {
            accNo = atoi(accInput);
            valid = 1;
        }
    }

    printf("Enter amount: ");
    scanf("%d", &amount);

    FILE *fp = fopen("data/accounts.txt","r");
    FILE *temp = fopen("data/temp.txt","w");

    int fileAccNo, bal;
    char name[50];
    int found=0;

    while(fscanf(fp,"%d %s %d", &fileAccNo,name,&bal)!=EOF){
        if(fileAccNo == accNo)
        {
            found=1;
            if(isDeposit) bal += amount;
            else if(bal>amount) bal-=amount;
            else{
                printf("Insufficient Balance!\n");
                fclose(fp);
                fclose(temp);
                remove("data/temp.txt");
                return;
            }
        }
        fprintf(temp, "%d %s %d\n",fileAccNo,name,bal);
    }
    fclose(fp);
    fclose(temp);

    remove("data/accounts.txt");
    rename("data/temp.txt", "data/accounts.txt");

    if (found) printf("Transaction successful!\n");
    else printf("Account not found.\n");
}