#include <stdio.h>
#include "account.h"
#include "transaction.h"
int main(){
    int choice;
    while (1)
    {
        printf("\n==== Bank Management System ====");
        printf("\n1. Create Account");
        printf("\n2. Deposit Money");
        printf("\n3. Withdraw Money");
        printf("\n4. View Account");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1: createAccount(); break;
        case 2: depositMoney(); break;
        case 3: withdrawMoney(); break;
        case 4: viewAccount(); break;
        case 5: printf("Exiting..\n"); return 0;
        default:
            printf("Invalid choice. Try again. \n");
        }
    }
    return 0;
}