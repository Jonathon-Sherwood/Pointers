/*
	Jonathon Sherwood
	11/28/2020
	C++ Pointers: Open practice with pointers
*/

#include <iostream> //Used to display messages to the console
#include <string> //Allows for functions using string
#include <vector> //Allows for functions using vectors

using namespace std; //Uses shortcuts for std names

//returns a pointer to a string element
string* ptrToElement(vector<string>* const pVec, int i);

//Returns a potion color based on the potion inputs
string potionChoice(int* firstChoice, int* secondChoice, string* potionName);

int main() //Main C++ that allows the script to run
{
	vector<string> potions; //Creates a string vector
	int firstChoice = 0;    //Creates a first input
	int secondChoice = 0;   //Creates a second input

	bool playAgain = true; //Allows the game to be reset

	//List of starting potion colours
	potions.push_back("red");
	potions.push_back("blue");
	potions.push_back("yellow");

	//Intro
	cout << "Welcome to the potion shop.\n";

	do //Game Loop
	{
		//Displays potions from list using their dereferenced address
		cout << "Combine any 2 of these options:\n";
		cout << "--1: " << *(ptrToElement(&potions, 0)) << " potion-- \n"
			"--2: " << *(ptrToElement(&potions, 1)) << " potion-- \n"
			"--3: " << *(ptrToElement(&potions, 2)) << " potion-- \n\n";

		//Takes in the first potion option
		cout << "\nPlease type the number of the first potion you want\n";
		cin >> firstChoice;

		//Loops the same question if the player does not input 1-3
		while (firstChoice != 1 && firstChoice != 2 && firstChoice != 3)
		{
			cout << "\nPlease only enter 1, 2, or 3\n";
			cin.clear();
			cin.ignore();
			cin >> firstChoice;
		}

		int* potionSelection = &firstChoice;                                   //Pointer int to the address of the first choice
		string* potionName = (ptrToElement(&potions, (*potionSelection) - 1)); //Pointer string matching the address of the list of original potions

		potionName = (ptrToElement(&potions, firstChoice - 1)); //Assigns the pointer to the address of the vector for the first selection

		//Dereferences the pointer to say the name of the address's variable
		cout << "\nYour first potion is: " << *potionName << "\n"; 
		cout << "What would you like to mix it with?\n";
		cout << "Please choose potion 1, 2, or 3\n";

		//Takes in the second variable
		cin >> secondChoice;

		//Loops the same question if the player does not input 1-3
		while (secondChoice != 1 && secondChoice != 2 && secondChoice != 3)
		{
			cout << "\nPlease only enter 1, 2, or 3\n";
			cin.clear();
			cin.ignore();
			cin >> secondChoice;
		}

		potionName = (ptrToElement(&potions, secondChoice - 1)); //Assigns the pointer to the address of the vector for the second selection

		//Dereferences the pointer to say the name of the address's variable
		cout << "\nYour second potion is: " << *potionName << "\n\n";

		potionSelection = &secondChoice; //Sets the pointer to look for the new address at second choice

		//Puts into the function the address of the first and second choices, then changes the potionName pointer
		cout << "You have created a " << potionChoice(&firstChoice, &secondChoice, potionName) << " potion.\n";
		cout << "Excellent work.\n";

		cout << "\n\nPlay again? (Y/N)\n";

		//Variable for looping the game
		char answer; 
		cin >> answer;

		if (answer == 'y' || answer == 'Y') //Loops game if yes
		{
			playAgain = true;
			cout << "\n\n";
		}
		else if (answer == 'n' || answer == 'N') //Ends game if no
		{
			cout << "\nVery well. Enjoy your potion.\n";
			playAgain = false;
			exit(0);
		}
		else //Also ends game if the answer is anything other than yes or no
		{
			cout << "\nI don't have time for nonsense answers. Goodbye\n";
			playAgain = false;
			exit(0);
		}
	} while (playAgain == true); //Loops game while play again is true

	return 0;
}

//Returns the string address for the specific element in the vector
string* ptrToElement(vector<string>* const pVec, int i)
{
	return &((*pVec)[i]);
}

//Takes in two pointers to return a string
string potionChoice(int* firstChoice, int* secondChoice, string* potionName)
{
	vector<string> potionCreation; //Creates a list of potion results

	//Creates integer based on the two pointers taken in
	int potionSelection = (*firstChoice + *secondChoice) - 2;

	//Prevents multiple answers to the same vector location
	if (*firstChoice == 2 && *secondChoice == 2)
	{
		potionSelection = 5;
	}

	//Potion results 
	potionCreation.push_back("red");
	potionCreation.push_back("purple");
	potionCreation.push_back("orange");
	potionCreation.push_back("green");
	potionCreation.push_back("yellow");
	potionCreation.push_back("blue");

	//Takes in the potionName pointer and changes its address
	potionName = &potionCreation[potionSelection];

	//Returns the string at the vector element chosen by first and second choice
	return *potionName;
}