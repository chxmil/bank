#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

typedef struct deposit_account dep_acc;
struct deposit_account {    
    char id_account[10];
    int type;
    int deposit;
    int credit;
};

typedef struct customers_struct customers;
struct customers_struct {
    char id_customer[10];
    char fname[30];
    char lname[30];
    dep_acc account[10];
};
customers cust[10];

int check_customers(int number_customers){
    char Temp[10]="";
    int number;

    printf("List of customer id\n");
    for(int i=0; i<number_customers; i++){
        printf("%d.%s\t", i+1, cust[i].id_customer);
    }
    while(1) {
        int check = 0;
        printf("\nEnter id customer : ");
        scanf("%s", Temp);
        for(int i=0; i<number_customers; i++){
            if (strcmp(Temp, cust[i].id_customer) == 0){
                number = i;
                check = 1;
                break;
            }
        }
        if (check==0) {
            printf("Please enter correctly");
        }
        else {
            break;
        }
    }
    return number;
}

int check_accounts(int number_cust, int number_accounts[10]){
    char Temp[10]="";
    int number;
    printf("\nList of account id\n");
    for(int i=0; i<number_accounts[number_cust]; i++){
        if (strlen(cust[number_cust].account[i].id_account) != 0)
            printf("%d.%s\t", i+1, cust[number_cust].account[i].id_account);
        else
            break;
    }
    while(1) {
        int check = 0;
        printf("\nEnter id account : ");
        scanf("%s", Temp);
        for(int i=0; i<10; i++){
            if (strcmp(Temp, cust[number_cust].account[i].id_account) == 0){
                number = i;
                check = 1;
                break;
            }
        }
        if (check==0) {
            printf("Please enter correctly");
        }
        else {
            break;
        }
    }
    return number;
}

void deposit_money(int number_customers, int number_accounts[10]){
    int money;
    int number_cust, number_acc;
    system("cls");

    printf("###############################################\n");
    printf("Deposit Process\n");
    number_cust = check_customers(number_customers);
    number_acc = check_accounts(number_cust, number_accounts);
    printf("###############################################\n");

    printf("Enter the amount you want to deposit : ");
    scanf("%d", &money);
    cust[number_cust].account[number_acc].deposit = cust[number_cust].account[number_acc].deposit+money;
    printf("Deposited money successfully\n");

    printf("###############################################\n");
    getch();
}

void withdraw_money(int number_customers, int number_accounts[10]){
    int money;
    int number_cust, number_acc;
    int check = 0;
    system("cls");

    printf("###############################################\n");
    number_cust = check_customers(number_customers);
    number_acc = check_accounts(number_cust, number_accounts);
    printf("###############################################\n");

    printf("Enter the amount you want to withdraw : ");
    scanf("%d", &money);
    if (cust[number_cust].account[number_acc].type == 1 && money<=cust[number_cust].account[number_acc].deposit) {
        cust[number_cust].account[number_acc].deposit = cust[number_cust].account[number_acc].deposit-money;
        check = 1;
    } else if ((cust[number_cust].account[number_acc].type == 2) && (money<=cust[number_cust].account[number_acc].credit) && (money<=cust[number_cust].account[number_acc].deposit)) {
        cust[number_cust].account[number_acc].deposit = cust[number_cust].account[number_acc].deposit-money;
        check = 1;
    } else if (money>cust[number_cust].account[number_acc].deposit) {
        printf("You can't withdraw money Your deposit is insufficient.\n");
        printf("Your balance now is %d\n", cust[number_cust].account[number_acc].deposit);
    } else {
        printf("You cannot withdraw more than your credit limit\n");
    }
    if (check==1) {
        printf("Deposited money successfully\n");
    }
    printf("###############################################\n");
    getch();
}

void account_details(int number_customers, int number_accounts[10]){ //�ʴ���
    int number_cust, number_acc;
    system("cls");

    printf("###############################################\n");
    number_cust = check_customers(number_customers);
    number_acc = check_accounts(number_cust, number_accounts);
    printf("###############################################\n");

    printf("Customer number %d details\n", number_cust+1);
    printf("ID_Customer : %s\n", cust[number_cust].id_customer);
    printf("Name : %s %s \n", cust[number_cust].fname, cust[number_cust].lname);
    printf("Account No.%d\n", number_acc+1);
    printf("ID Account : %s\n", cust[number_cust].account[number_acc].id_account);
    if (cust[number_cust].account[number_acc].type == 1) {
        printf("Account type : Savings account\n");
    } else if (cust[number_cust].account[number_acc].type == 2) {
        printf("Account type : Current account\n");
    }
    printf("Account deposit balance : %d\n", cust[number_cust].account[number_acc].deposit);
    if (cust[number_cust].account[number_acc].type==2)
        printf("Credit limit : %d\n", cust[number_cust].account[number_acc].credit);

    printf("###############################################\n");
    getch();
}

void end(int number_customers, int number_accounts[10]){
    system("cls");

    printf("###############################################\n");
    for(int i=0; i<number_customers; i++){
        printf("Customer number %d details\n", i+1);
        printf("ID_Customer : %s\n", cust[i].id_customer);
        printf("Name : %s %s\n", cust[i].fname, cust[i].lname);
        for(int j=0; j<number_accounts[i]; j++) {
            printf("\nAccount No.%d\n", j+1);
            printf("ID Account : %s\n", cust[i].account[j].id_account);
            if (cust[i].account[j].type == 1) {
                printf("Account type : Savings account\n");
            } else if (cust[i].account[j].type == 2) {
                printf("Account type : Current account\n");
            }
            printf("Account deposit balance : %d\n", cust[i].account[j].deposit);
            if (cust[i].account[j].type==2)
                printf("Credit limit : %d\n", cust[i].account[j].credit);
        }
        printf("###############################################\n");
    }

    getch();
}

int main(){
    int number_customers, number_accounts[10];
    char button;
    system("cls");

    //input
    while(1){
    printf("Enter number of customers : ");
    scanf("%d", &number_customers);
    if (number_customers < 1 || number_customers > 10) 
        printf("Try again. Number of customers is incorrect (1-10)\n");
    else 
        break;
    }

    for(int i=0; i<number_customers; i++){
        printf("Customer number %d\n", i+1);
        printf("Enter customer id : ");
        scanf("%s", &cust[i].id_customer);
        printf("Enter customer first name : ");
        scanf("%s", cust[i].fname);
        printf("Enter customer last name : ");
        scanf("%s", cust[i].lname);
        while(1){
            int temp;
            printf("Enter the number of accounts the customer will open : ");
            scanf("%d", &temp);
            if (temp>=1 && temp <=10){
                number_accounts[i]=temp;
                break;
            }
            else {
                printf("Try again. You can only open 1 to 10 accounts\n");
            }
        }

        for(int j=0; j<number_accounts[i]; j++){
            printf("Account number %d\n", j+1);
            printf("Enter account id : ");
            scanf("%s", &cust[i].account[j].id_account);
            while(1) {
                printf("Enter account type ( 1.savings account, 2.current account ) : ");
                scanf("%d", &cust[i].account[j].type);
                if (cust[i].account[j].type ==1 || cust[i].account[j].type==2){
                    break;
                }
                else {
                    printf("Try again, enter only 1 and 2\n");
                }
            }
            printf("Enter the account deposit balance : ");
            scanf("%d", &cust[i].account[j].deposit);
            if (cust[i].account[j].type==2){
                printf("Enter credit limit : ");
                scanf("%d", &cust[i].account[j].credit);
            }
        }
    }

    //Process & Output
    while(1){
        system("cls");
        printf("###############################################\n");
        printf("#    Press number 1 to deposit money          #\n");
        printf("#    Press number 2 to withdraw money         #\n");
        printf("#    Press number 3 to view account details   #\n");
        printf("#    Press number x to exit                   #\n");
        printf("###############################################\n");

        printf("Enter : ");
        scanf(" %c", &button);
        
        if (button == '1') {
            deposit_money(number_customers, number_accounts);
        }
        else if (button == '2') {
            withdraw_money(number_customers, number_accounts);
        }
        else if (button == '3') {
            account_details(number_customers, number_accounts);
        }
        else if (button == 'x' || button == 'X') {
            end(number_customers, number_accounts);
            break;  
        }
    }
    getch();
}
