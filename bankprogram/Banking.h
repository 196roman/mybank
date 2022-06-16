#pragma once
#include <string>
#include <iostream>
#include <fstream>

class Banking {

public: 
	void bankAccountCreate(std::string username) {

		std::ofstream file(username + "bank.txt");

	}

public:
	void bankInitialize(std::string username, int val) {

		std::fstream file(username + "bank.txt");
		file << "INITIAL BALANCE\n" << val;


	}

public: 
	bool bankExists(std::string username) {

		std::fstream Check;
		Check.open(username + "bank.txt");
		if (!Check) {

			return false;

		}
		else {

			return true;

		}

	}

public:
	void bankDeposit(std::string username, int value, int balance ) {

		std::fstream Check;
		Check.open(username + "bank.txt", std::ios::app);
		Check << "\n+ DEPOSIT " << value << "\n";
		int sum = value + balance;
		Check << sum;

	}
public:
	void bankWithdraw(std::string username, int value, int balance) {

		std::fstream Check;
		Check.open(username + "bank.txt", std::ios::app);
		Check << "\n- WITHDRAW " << value << "\n";
		int sum = balance - value;
		Check << sum;

	}
public:
	int readBalance(std::string username) {

		std::fstream Check;
		Check.open(username + "bank.txt");	//this code is longer because you need to actually instruct the computer to look beyond the first line in the file
		if (Check.is_open()) {
			Check.seekg(-1, std::ios_base::end); //look at the contents from start to finish

			bool keepLooping = true; // a variable to use to check when the loop needs to end. initializes as true

			while (keepLooping) {

				char ch;
				Check.get(ch); //grab a character from the contents and check if the character pulled is the newline character
							//when it finds the newline character, the computer will know it's on the second line

				if ((int)Check.tellg() <= 1) {
					Check.seekg(0);
					keepLooping = false;	//if the character grabbed is not the newline character, continue searching
				}

				else if (ch == '\n') {	//if it is the newline character, terminate the loop

					keepLooping = false;
				}

				else {
					Check.seekg(-2, std::ios_base::cur); //instructs the computer to check the next character if the character checked wasn't newline
				}


			}


		}

		std::string lastLine; //variable to store the last line in the file in
		std::getline(Check, lastLine); //grab the last line in the file

		int value = stoi(lastLine);

		return value;


	}
	

};