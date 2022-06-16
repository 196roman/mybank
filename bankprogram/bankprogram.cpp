

#include <iostream>
#include <string>
#include <fstream>
#include "UserTools.h"
#include "Banking.h"
#include "Passwordch.h"


int main()
{

    int select = 0, bankselect = 0, deposit = 0, withdraw = 0, startingbalance = 0;
    bool LoggedIn = false, bankSelecting = true, initialized = false;
    std::string newuser, newpassword; //if the user SIGNS UP, stores the username and password values here
    std::string username, password; //if the user LOGS IN, stores the username and password values here
    UserTools obj; //to use functions from different classes, we need to have an object of that class to point to
    Banking obj2;
    Passwordch obj3;

    do {
        std::cout << "Welcome. Sign up or log in.\n 1. Sign up\n 2. Log in\n"; //prompt
        std::cin >> select;

        switch (select)      //switch case, instead of if else, because a switch case is better suited for "selection" loops
        {

        case 1:
        {
            std::cout << "\nNew username: ";
            std::cin >> newuser;
            std::cout << "\nNew password: ";
            newpassword = obj3.takePasswdFromUser();
           

            obj.UserTools::storeNew(newuser, newpassword); //calls a function from "UserTools.h", using the input as arguments
           
            continue;

        }


        case 2:
        {
            std::cout << "\nUsername: ";
            std::cin >> username;
            std::cout << "\nPassword: ";
            password = obj3.takePasswdFromUser();
            

            bool usercorrect = obj.UserTools::verifyUser(username);
            bool passwordcorrect = obj.UserTools::verifyPass(username, password);

            if (usercorrect && passwordcorrect) {

                LoggedIn = true;
                break;

            }
            else if (usercorrect == true && passwordcorrect == false) {

                std::cout << "\nThe password you entered was incorrect.\n\n";

            }
            else if (usercorrect == false) {

                std::cout << "\nThe username you entered does not exist.\n\n";

            }
            continue;



        }


        default:
        {
            std::cout << "\nPlease follow the prompt.\n";
            continue;
        }


        }

    } while (LoggedIn == false);

    if (obj2.Banking::bankExists(username)) {

        initialized = true;
    }
    std::cout << "\n\nWelcome, " << username << ".\n";

    if (initialized == false) {

        std::cout << "Let's initialize your bank account.\nEnter your starting balance: ";
        std::cin >> startingbalance;
        obj2.Banking::bankAccountCreate(username);
        obj2.Banking::bankInitialize(username, startingbalance);
        initialized = true;
        

    }
    

        
   do {
                std::cout << "\nWhat would you like to do?\n1. Check Balance \n2. Deposit\n3. Withdraw\n4. Log out\n";
                std::cin >> bankselect;

                switch (bankselect) {

                case 1:
                {
                    std::cout << username << "'s current balance: $" << obj2.Banking::readBalance(username) << "\n";
                    continue;
                }

                case 2:
                {

                    std::cout << "\nHow much would you like to deposit?\n";
                    std::cin >> deposit;
                    obj2.Banking::bankDeposit(username, deposit, obj2.Banking::readBalance(username));
                    std::cout << "Your balance is now $" << obj2.Banking::readBalance(username) << ".\n";
                    continue;
                }

                case 3:
                {

                    std::cout << "\nHow much would you like to withdraw?\n";

                    std::cin >> withdraw;
                    obj2.Banking::bankWithdraw(username, withdraw, obj2.Banking::readBalance(username));
                    std::cout << "Your balance is now $" << obj2.Banking::readBalance(username) << ".\n";
                    continue;
                }

                case 4:
                {
                    bankSelecting = false;
                    break;
                }

                default:
                {

                    std::cout << "\nPlease follow the prompt.\n";
                    continue;

                }


                }

            } while (bankSelecting == true);

   std::cout << "\nThank you for using our bank.\n";
   return 0;

 
   

    }




