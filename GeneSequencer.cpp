#include "GeneSequencer.h"
#include "Allele.h"
#include "Gene.h"
#include "Chromosome.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

GeneSequencer::GeneSequencer(){};

Chromosome GeneSequencer::ImportChromosome(const string &fileName) //NEED " = "" "?
{
	Chromosome newChromosome;
	int counter = 0;
	string fileToOpen = fileName;
	ifstream userFile(fileName);
	if (!userFile.is_open())
	{
		cout << "ERROR. File not found" << endl;
	};
	string line;
	string displayGenes = "y";
	while (!userFile.eof())
	{
		getline(userFile, line); //FIXME counter number for file without emtpy last line
		counter++;
	}
	counter -= 1;
	cout << endl
		 << counter << " genes found on file." << endl
		 << "Would you like to display them? (y/n): ";
	getline(cin, displayGenes);

	userFile.clear();
	userFile.seekg(0, ios::beg);
	for (int i = 1; i <= counter; i++)
	{
		getline(userFile, name, ','); //DO I HAVE TO INCLUDE THE USER OPTION TO PICK A SPECIFIC CHROMOSOME?
		getline(userFile, trait, ',');
		getline(userFile, variant1, ',');
		getline(userFile, type1, ',');
		getline(userFile, sequence1, ',');
		getline(userFile, variant2, ',');
		getline(userFile, type2, ',');
		getline(userFile, sequence2, '\n');

		if (displayGenes == "y")
		{
			cout << endl
				 << "                   Chromosome " << i << " data " << endl
				 << endl

				 << "                   Gene name:       " << name << endl
				 << "                   Gene trait:      " << trait << endl
				 << "                   Gene variant 1:  " << variant1 << endl
				 << "                   Gene type 1:     " << type1 << endl
				 << "                   Gene sequence 1: " << sequence1 << endl
				 << "                   Gene variant 2:  " << variant2 << endl
				 << "                   Gene type 2:     " << type2 << endl
				 << "                   Gene sequence 2: " << sequence2 << endl //FIXME press enter to return to menu
				 << "                   ------------------------";
		}

		Allele newAlleleA(variant1, type1, sequence1);
		Allele newAlleleB(variant2, type2, sequence2);
		Gene tempGene;
		vector<Allele> temp = tempGene.AddAllele(newAlleleA, newAlleleB);
		newChromosome.AddGenes(temp);
		newChromosome.AddNameandTrait(name, trait);

		//newChromosome.InputFromFile(userFile);

		//Gene newGene(newAlleleA, newAlleleB);
		//newGene.SetNameandTrait(name, trait);
		//newChromosome.AddGene(newGene);
	}
	cout << endl
		 << "A chromosome object with the file information has been created" << endl
		 << endl;
	userFile.close();
	allele.ReturnToMenu();
	return newChromosome;
};

void GeneSequencer::ExportChromosome(Chromosome c, const string &filename)
{
	string userFile = filename;
	ofstream outPut;
	outPut.open(filename);
	c.OutputToFile(outPut);
	outPut.close();
};
