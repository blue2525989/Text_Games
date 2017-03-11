/*
 * GuessMyNumber.cpp
 *
 *  Created on: Mar 11, 2017
 *      Author: Jason
 */
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	srand(static_cast<unsigned int>(time(0)));

	int secretNumber = rand() % 100 +1;
	int tries = 0;
	int guess;

	cout<< "\tWelcome to Guess my Number."<<endl <<endl;

	do
	{
		cout<< "Enter a guess: ";
		cin>> guess;
		++tries;

		if (guess > secretNumber)
		{
			cout<< "Too high!"<<endl <<endl;
		}
		else if (guess < secretNumber)
		{
			cout<< "Too low!"<<endl <<endl;
		}
		else
		{
			cout<< "\nThat's it! You got it in " << tries << " guesses!!\n";
		}

	} while (guess != secretNumber);
}


