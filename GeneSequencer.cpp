#include "GeneSequencer.h"
#include "Allele.h"
#include "Gene.h"
#include "Chromosome.h"
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

using namespace std;

GeneSequencer::GeneSequencer(){};
void SequenceChromosomePair(Chromosome c){};

Chromosome GeneSequencer::ImportChromosome(const string &fileName)
{
	Chromosome newChromosome;
	int counter = 0;
	string fileToOpen = fileName;
	ifstream userFile(fileName);
	if (!userFile.is_open())
	{
		cout << "ERROR. File not found" << endl;
		//FIXEME after error, it gets stuck
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
				 << "                   Gene sequence 2: " << sequence2 << endl
				 << "                   ------------------------";
		}

		Allele newAlleleA(variant1, type1, sequence1);
		Allele newAlleleB(variant2, type2, sequence2);
		Gene tempGene;
		vector<Allele> temp = tempGene.AddAllele(newAlleleA, newAlleleB);
		newChromosome.AddGene(temp);
		newChromosome.AddNameandTrait(name, trait);
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
	outPut.open(filename, ios::app);
	if (!outPut.is_open())
	{
		cout << "Error creating/opening file" << endl;
	}
	else
	{
		cout << "File opened successfully" << endl;
	}

	c.OutputToFile(outPut);
	outPut.close();
};

Chromosome GeneSequencer::DoMeiosis(Chromosome x, Chromosome y)
{
	Chromosome newChromosome1 = x;
	Chromosome newChromosome2 = y;

	chromosomes.push_back(newChromosome1);
	chromosomes.push_back(newChromosome2);
	int pos1 = newChromosome1.GetPos();
	int pos2 = newChromosome2.GetPos();

	vector<Allele> temp1 = newChromosome1.GetGenes(pos1);
	string name1 = newChromosome1.GetGeneName(pos1);
	string trait1 = newChromosome1.GetGeneTrait(pos1);
	vector<Allele> temp2 = newChromosome2.GetGenes(pos2);
	string name2 = newChromosome2.GetGeneName(pos2);
	string trait2 = newChromosome2.GetGeneTrait(pos2);
	Chromosome newChromosome3;
	newChromosome3.AddGene(temp1);
	newChromosome3.AddGene(temp2);

	newChromosome3.AddNameandTrait(name1, trait1);
	newChromosome3.AddNameandTrait(name2, trait2);

	return newChromosome3;
};