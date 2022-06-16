#pragma once
#include <iostream>
#include <string>
#include <fstream>

 class UserTools //these are functions I wrote for the logging in and signing up portion of the program
{


public:

	void storeNew(std::string user, std::string pass) { //the function requires the variables "user" and "pass"

		std::ofstream Store(user + ".txt");	//creates a file using the given username
		Store << user << "\n" << pass;	//stores the user and pass seperated by a newline in the file

	}


public:

	bool verifyUser(std::string user) { //checks if a username exists already

		
		std::fstream check;
		check.open(user + ".txt");
			if (!check) {
				return false;
			}
			else {
				return true;
			}
		

	}


public:

	bool verifyPass(std::string user, std::string password) { //checks if the password matches the password stored with the given username

		std::fstream file;
		file.open(user + ".txt");	//this code is longer because you need to actually instruct the computer to look beyond the first line in the file
		if (file.is_open()) {
			file.seekg(-1, std::ios_base::end); //look at the contents from start to finish

			bool keepLooping = true; // a variable to use to check when the loop needs to end. initializes as true

			while (keepLooping) {

				char ch;
				file.get(ch); //grab a character from the contents and check if the character pulled is the newline character
							//when it finds the newline character, the computer will know it's on the second line

				if ((int)file.tellg() <= 1) {
					file.seekg(0);
					keepLooping = false;	//if the character grabbed is not the newline character, continue searching
				}

				else if (ch == '\n') {	//if it is the newline character, terminate the loop

					keepLooping = false;
				}

				else {
					file.seekg(-2, std::ios_base::cur); //instructs the computer to check the next character if the character checked wasn't newline
				}


			}


		}

		std::string lastLine; //variable to store the last line in the file in
		std::getline(file, lastLine); //grab the last line in the file

		if (lastLine == password) { //if it matches the user input, the password is correct
			return true;
		}
		else {
			return false;	//if the password is not found in the last line of the file, it is incorrect
		}

	}





};

