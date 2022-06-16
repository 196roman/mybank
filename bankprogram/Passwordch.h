#pragma once
#include <iostream>
#include <string>
#include <conio.h>
class Passwordch
{
   
    enum IN {

        // 13 is ASCII for carriage
        // return
        IN_BACK = 8,
        IN_RET = 13

    };

    // Function that accepts the password
public:

    std::string takePasswdFromUser(char sp = '*')
    {
        // Stores the password
        std::string passwd = "";
        char ch_ipt;

        // Until condition is true
        while (true) {

            ch_ipt = _getch();

            // if the ch_ipt
            if (ch_ipt == IN::IN_RET) {
                std::cout << std::endl;
                return passwd;
            }
            else if (ch_ipt == IN::IN_BACK
                && passwd.length() != 0) {
                passwd.pop_back();

                // Cout statement is very
                // important as it will erase
                // previously printed character
                std::cout << "\b \b";

                continue;
            }

            // Without using this, program
            // will crash as \b can't be
            // print in beginning of line
            else if (ch_ipt == IN::IN_BACK
                && passwd.length() == 0) {
                continue;
            }

            passwd.push_back(ch_ipt);
            std::cout << sp;
        }
    }

};





