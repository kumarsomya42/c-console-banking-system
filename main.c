#include <stdio.h>
#include <string.h>

// taking the parallel arrays input here so that they would be pubic for every command or any function 
char user_data[5][30];     //defining the string with 150 characters so that we can store upto 5 peoples names and their unique ids that will be provided by us
int user_pin[5];       //defining the integer variable data type but of array and making this for pin of the accounts    
int user_balance[5];

void users_data() {         // Trying to add user's data upto 5 users only
    int c=0;  // this is for the loop setup 
    int a;
    printf("how many users data you want to enter in this??   (ONLY ENTER UPTO 5 OR THE PROGRAM WILL NOT RUN)\n");  // taking input of how many persons data is to be entered and maximum 5 is allowed right now 
    scanf("%d",&a);     //this will take the input from the user
    while (c<a){
        printf("enter user's name:\n");
        scanf("%s",user_data[c]);
        printf("Congratulations your account is opened!\n");    // the users data added into the array now we will add more data like pin and more things here
        printf("Now make a pinn for your account:\n");     // taking input of the users account pin so that he can access his/her account later
        scanf("%d",&user_pin[c]); 
        
        printf("Add some balance so that we can proceed:\n");    // depositing the balance into the users account
        scanf("%d",&user_balance[c]);
        c+=1;   // increasing c so that the loop will finish at a time it will not be an infinte loop 
    }
    
}


// now making a function through which the user can now find his/her balance and withdraw or deposit balance into their account they just have to enter the pin

void main_system_of_banking() {
    int pin;
    int found=0;
    printf("Enter the PIN to access your bank account:");
    scanf("%d",&pin);
    for (int i=0;i<5;i+=1) {  // this is for accessing the 5 users data from the user_data variable
        if (pin==user_pin[i]) {
            printf("Account found your account no is %d and your name is %s",i,user_data[i]);
            found=1;  //this statement is helpful in loop break
            int loop=0;
            printf("Now choose the option that you want to do-:\n");
            while (loop==0){
                printf("1) Check Balance\n");
                printf("2) Deposit Balance\n");
                printf("3) Withdraw Balance\n");
                printf("4) Logout \n");
                int choice;
                scanf("%d",&choice);
                if (choice==1) {   // this option is for balance check
                    printf("Your balance is %d\n",user_balance[i]);
                }
                else if (choice==2) {    // this option is for deposit balance in the account
                    int temp_deposit;
                    printf("How much do you want to deposit?\n");
                    scanf("%d",&temp_deposit);
                    user_balance[i]+=temp_deposit;
                }
                else if (choice==3) {     // this option is for withdraw balance from the users account
                    int temp_withdraw;
                    printf("How much do you want to withdraw?\n");
                    scanf("%d",&temp_withdraw);
                    user_balance[i]-=temp_withdraw;
                }
                else if (choice==4) {   // this is for qutting the program or logout in the banking language
                    loop=1;
                    break;
                }
                else {    // this is for if the user's input is invalid means if we are not having options for the input of the user
                    printf("Choose a correct option for this!!!");
                }
            }
            break;
        }
    }
    
    if (found==0) {
        printf("Wrong PIN enter correct one next time");
    }
}


int main() {
    int loop_start=1;
    while (loop_start==1) {
        printf("WELCOME To OUR BANKING SYSTEM\n");
        printf("-----------------------------\n");
        printf("WE ARE HERE TO HELP YOU CHOOSE THE OPTION WHAT YOU WANT TO DO TODAY ?\n");
        printf("-----------------------------\n");
        int input_choice;
        printf("1) Make a new user into the database\n");    // first option to make users data into the database
        printf("2) Handle a existing user data (BUT THERE SHOULD BE ALREADY A SINGLE ACCOUNT FOR THIS)\n");   // to do the main baking functions
        printf("3) Exit the program\n");  // to close the full program
        
        scanf("%d",&input_choice);
        if (input_choice==1) {
            users_data();
        }
        else if (input_choice==2) {
            main_system_of_banking();
        }
        else if (input_choice==3) {
            loop_start+=1;
        }
        else {
            printf("INVALID OPTION CHOSEN!!!");
        }
    }
}




// MADE BY ZYNOX