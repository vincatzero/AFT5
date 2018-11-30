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
void GeneSequencer::SequenceChromosomePair(Chromosome c)
{

	c.AnalyzeGenotype();

	ReturnToMenu();
};

Chromosome GeneSequencer::CreateChromosome()
{
	string anotherGene = "y";
	Chromosome newChromosome;
	Gene newGene;

	while (anotherGene == "y")
	{

		cout << "Enter the name of the new gene (e.g. TZ458): " << endl;
		getline(cin, name);
		cout << "Enter the name of the gene trait (e.g. eye color): " << endl;
		getline(cin, trait);

		cout << "Enter the allele 1 variant (e.g. brown/blue/etc.): " << endl;
		getline(cin, variant1);
		cout << "Enter the allele 1 type (e.g. dominant or recessive): " << endl;
		getline(cin, type1);

		while (type1 != "dominant" && type1 != "recessive")
		{
			cout << "Entry must be either \"dominant\" or \"recessive\" " << endl;
			getline(cin, type1);
		}

		cout << "Enter the allele 1 nucleotide sequence (e.g. AGTC): " << endl;
		getline(cin, sequence1);

		cout << "Enter the allele 2 variant (e.g. brown/blue/etc.): " << endl;
		getline(cin, variant2);
		cout << "Enter the allele 2 type (e.g. dominant or recessive): " << endl;
		getline(cin, type2);
		while (type2 != "dominant" && type2 != "recessive")
		{
			cout << "Entry must be either \"dominant\" or \"recessive\" " << endl;
			getline(cin, type2);
		}
		while (type1 == type2)
		{
			cout << endl
				 << endl
				 << "One type must be dominant and one must be recessive" << endl;
			cout << "Enter the allele 2 type (e.g. dominant or recessive): " << endl;
			getline(cin, type2);
		}

		cout << "Enter the allele 2 nucleotide sequence (e.g. AGTC): " << endl;
		getline(cin, sequence2);

		Allele newAlleleA(variant1, type1, sequence1);
		Allele newAlleleB(variant2, type2, sequence2);
		newGene.SetNameandTrait(name, trait); //FIXME USE CONSTRUCTORS

		newGene.AddAlleles(newAlleleA, newAlleleB);

		newChromosome.AddGene(newGene);

		cout << "Would you like to add another gene: (y/n)" << endl;
		getline(cin, anotherGene);
	}
	return newChromosome;
};

Chromosome GeneSequencer::ImportChromosome(const string &fileName)
{
	Chromosome newChromosome;
	int counter = 0;
	ifstream userFile(fileName);
	if (!userFile.is_open())
	{
		cout << "ERROR. File not found" << endl
			 << endl;
	}

	else
	{
		string line;
		string displayGenes = "y";
		while (!userFile.eof())
		{
			getline(userFile, line);
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
			getline(userFile, name, ',');
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
			Gene newGene(name, trait, newAlleleA, newAlleleB);

			newChromosome.AddGene(newGene);
		}
		cout << endl
			 << "A chromosome object with the file information has been created." << endl
			 << endl;
		userFile.close();
	}

	ReturnToMenu();
	return newChromosome;
};
void GeneSequencer::ExportChromosome(Chromosome c, const string &filename)
{
	string userFile = filename;
	ofstream outPut(filename, ios::app);
	if (!outPut.is_open())
	{
		cout << "Error creating/opening file" << endl;
	}
	else
	{
		cout << "File opened/created successfully" << endl;
	}

	c.OutputToFile(outPut);
	outPut.close();
	cout << endl;
	ReturnToMenu();
};

Chromosome GeneSequencer::DoMeiosis(Chromosome x, Chromosome y)
{
	Chromosome c = x + y;
	cout
		<< endl
		<< "A new chromosome object has been" << endl
		<< "created through meiosis." << endl
		<< endl;
	return c;
	ReturnToMenu();
};

void GeneSequencer::ReturnToMenu()
{
	char c;
	cout << "Press enter to return to menu:" << endl;
	cin.get(c);
};

bool GeneSequencer::PowerOnSelfTest()
{
	Allele testAllele;
	Gene testGene;
	Chromosome testChromosome;
	GeneSequencer testData;

	testAllele.alleleClassTestBench();
	testGene.GeneClassTestBench();
	testChromosome.ChromosomeClassTestBench();

	cout << "test";
	streambuf *cout_sbuf = std::cout.rdbuf();
	ofstream fout("/dev/null");
	cout.rdbuf(fout.rdbuf());

	testData.CreateChromosome();
	cout.rdbuf(cout_sbuf);
	return true;
};