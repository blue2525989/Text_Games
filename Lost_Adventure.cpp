/*
 * LostAdventure.cpp
 *
 *  Created on: Mar 11, 2017
 *      Author: Jason
 */
#include <iostream>
using namespace std;

int main()
{

	int GOLD_PIECES = 0;
	int captinShare = 0;
	int cptShrMult = 0;
	int advToKill = 0;

	char again = 'y';
	while (again == 'y')
	{
		cout<< "Difficulty Levels\n\n";
		cout<<"1. Easy.\n";
		cout<<"2. Normal\n";
		cout<<"3. Hard\n\n";

		int choice;
		cout<< "Choice: ";
		cin>> choice;

		switch (choice)
		{
		case 1:
			cout<< "You picked Easy.\n";
			GOLD_PIECES = 975;
			cptShrMult = 6;
			advToKill = 4;
			break;
		case 2:
			cout<< "You picked Normal.\n";
			GOLD_PIECES = 575;
			cptShrMult = 4;
			advToKill = 3;
			break;
		case 3:
			cout<< "You picked Hard.\n";
			GOLD_PIECES = 375;
			cptShrMult = 2;
			advToKill = 2;
			break;
		default:
			cout<< "You made an illegal choice.\n";
		}

		// game part
		int adventurers, numKilled, survivorsLeft;
		string leader;

		cout<< "Welcome to Lost Fortune\n\n";
		cout<< "Please enter the following for your personalized adventure\n";

		cout<< "Enter a number: ";
		cin>> adventurers;

		numKilled = adventurers / advToKill + 1;
		survivorsLeft = adventurers - numKilled;
		captinShare = (survivorsLeft * cptShrMult);
		GOLD_PIECES -= captinShare;

		cout<< "Enter your last name: ";
		cin>> leader;

		// story
		cout<< "\nAlong the way, a band of marauding ogres ambushed the party. ";
		cout<< "\nAll fought bravely under the command of " << leader;
		cout<< "\nOf the adventurers, " << numKilled << " were vanquished, ";
		cout<< "\nleaving just "<< survivorsLeft << " in the group.\n";
		cout<< "\nThe party was about to give up all hope. ";
		cout<< "\nBut while laying the deceased to rest, ";
		cout<< "\nthey stumbled opon the buried fortune.\n ";
		cout<< "\nSo the adventurers split " << (GOLD_PIECES) << " gold pieces.";
		cout<< leader << " held on to the extra " << (captinShare);
		cout<< " \npieces to keep things fair of course.\n";

		// play again
		cout<< "\nDo you want to play again? [y/n]: ";
		cin>> again;
	}
	cout<< "\nOkay bye.";

	return 0;
}
