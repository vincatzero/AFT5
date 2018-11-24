/*	Project:    NAME OF PROJECT GOES HERE
	Name:       YOUR NAME GOES HERE
    Partner:    PARTNER'S NAME IF ANY
    Class:      example: CSC 1810 - Section 1
*/

#include <iostream>
#include "Gene.h"
#include "GeneSequencer.h"
#include "Chromosome.h"
#include "Allele.h"
#include <fstream>
#include <string>

using namespace std;
void runMenu();

int main(int argc, char *argv[])
{
	runMenu();

	// This causes the program to pause at its completion.
	{
		char c;
		cout << "Hit enter to exit:";
		cin.get(c);
	}
	return 0;
}

void runMenu()
{
	GeneSequencer GeneSequencers;
	string UserOption;
	string userFile;
	Chromosome newChromosome;

	while (UserOption != "6")
	{
		cout << endl
			 << "        * MENU *" << endl
			 << endl
			 << "1 - Create Chromosome" << endl
			 << "2 - Analyze Chromosome" << endl
			 << "3 - Output Chromosome to File" << endl
			 << "4 - Input Chromosome from File" << endl
			 << "5 - Combine Chromosomes" << endl
			 << "6 - Exit" << endl
			 << endl
			 << "Please Enter your Choice (1-6): ";
		getline(cin, UserOption);
		cout << endl;
		while ((UserOption > "6") || (UserOption < "1") || (UserOption.length() > 1))
		{
			cout << "Please enter a valid choice: ";
			getline(cin, UserOption);
		}

		int userChoice = stoi(UserOption);

		switch (userChoice)
		{
		case 1:
			newChromosome = newChromosome.CreateChromosome();
			break;
		case 2:
			newChromosome.AnalyzeGenotype();
			break;
		case 3:
			cout << "Enter the name of the file you would like to export to: " << endl;
			getline(cin, userFile);
			GeneSequencers.ExportChromosome(newChromosome, userFile);

			break;
		case 4:
			cout << "Enter the file would you like to import from:" << endl;
			getline(cin, userFile);
			newChromosome = GeneSequencers.ImportChromosome(userFile);
			break;
		case 5:
			break;
		case 6:
			break;
		}
	}
};