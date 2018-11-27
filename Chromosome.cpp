#include "Allele.h"
#include "Gene.h"
#include "Chromosome.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <ctime>

using namespace std;

Chromosome::Chromosome(){};
Chromosome::Chromosome(const Gene &x){
	//genes.push_back(x);
};

string Chromosome::GetGeneName(const int &x)
{
	string tempName = geneNameandTrait.at(x);
	istringstream ss(tempName);
	getline(ss, name, ',');
	return name;
};

string Chromosome::GetGeneTrait(const int &x)
{
	string tempTrait = geneNameandTrait.at(x);
	string trait2;
	istringstream ss(tempTrait);
	getline(ss, trait, ',');
	getline(ss, trait2, ',');

	return trait2;
};

void Chromosome::AddNameandTrait(const string &x, const string &y)
{
	geneNameandTrait.push_back(x + "," + y);
};

void Chromosome::AnalyzeGenotype()
{
	string expressedAllele;
	string expressedNucleotideSeq;

	for (vector<vector<Allele>>::size_type i = 0; i < genes.size(); i++)

	{
		for (vector<Allele>::size_type j = 0; j < genes[i].size(); j++)

		{
			if (genes[i][j].GetType() == "dominant")

			{
				expressedNucleotideSeq = genes[i][j].GetSequence();
				expressedAllele = genes[i][j].GetVariant();

				cout << "        Gene " << i + 1 << endl
					 << "Gene name:            " << GetGeneName(i) << endl
					 << "Genetic trait:        " << GetGeneTrait(i) << endl
					 << "Expressed allele:     " << expressedAllele << endl
					 << "Nucleotide sequence:  " << expressedNucleotideSeq << endl
					 << endl;
			}
		}
	}
	Allele allele;
	allele.ReturnToMenu();
};

void Chromosome::AddGene(const vector<Allele> &x)
{
	genes.push_back(x);
};

Chromosome Chromosome::CreateChromosome()
{
	string anotherGene = "y";
	Chromosome newChromosome;
	Gene tempGene;

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

		//while (this->type1 != "dominant") // || (this->type1 != "recessive")) //FIXME WHY IS THIS NOT WORKING?
		//{
		//	cout << "Entry must be either \"dominant\" or \"recessive\" " << endl;
		//	getline(cin, type1);
		//	}

		cout << "Enter the allele 1 nucleotide sequence (e.g. AGTC): " << endl;
		getline(cin, sequence1);

		cout << "Enter the allele 2 variant (e.g. brown/blue/etc.): " << endl;
		getline(cin, variant2);
		cout << "Enter the allele 2 type (e.g. dominant or recessive): " << endl;
		getline(cin, type2);

		cout << "Enter the allele 2 nucleotide sequence (e.g. AGTC): " << endl;
		getline(cin, sequence2);

		Allele newAlleleA(variant1, type1, sequence1);
		Allele newAlleleB(variant2, type2, sequence2);

		vector<Allele> temp = tempGene.AddAllele(newAlleleA, newAlleleB);
		newChromosome.AddGene(temp);
		//temp.resize(0);						   //DONT THINK I NEED THIS ANYMORE
		//tempGene.SetNameandTrait(name, trait); //OR THIS

		newChromosome.AddNameandTrait(name, trait);
		//Gene newGene;
		//newGene.AddAllele(newAlleleA, newAlleleB);

		//	Gene tempGene;
		//vector<Allele> temp = tempGene.GetAlleles();

		//	newGene.SetNameandTrait(name, trait);

		//newChromosome.AddGenes(temp);

		//Gene newGene(newAlleleA, newAlleleB);
		//newGene.AddAllele(newAlleleA, newAlleleB);
		//Chromosome newc

		//newGene.SetNameandTrait(name, trait);
		//newChromosome.AddGene(newGene);

		cout << "Would you like to add another gene: (y/n)" << endl;
		getline(cin, anotherGene);
	}
	return newChromosome;
};

void Chromosome::OutputToFile(ofstream &ofs)
{

	for (vector<vector<Allele>>::size_type i = 0; i < genes.size(); i++)

	{
		ofs << GetGeneName(i) + "," << GetGeneTrait(i) + ",";
		int counter = 0;

		for (vector<Allele>::size_type j = 0; j < this->genes[i].size(); j++)

		{
			ofs << genes[i][j].GetVariant() + "," << genes[i][j].GetType(i) + "," << genes[i][j].GetSequence(i);
			if (counter == 0)
			{
				ofs << ",";
				counter++;
			}
		}
		ofs << endl;
	}
	cout << endl
		 << endl;
	allele.ReturnToMenu();
};

vector<string> Chromosome::FindGene(string n) //FIXME figure out what he wants us to return and how to do it
{
	string userSearch = n;

	for (vector<string>::size_type i = 0; i < geneNameandTrait.size(); i++)

	{
		if (GetGeneName(i) == userSearch)
		{
			cout << "found it !!" << endl;
		};
	}
	return geneNameandTrait;
}
/*
	vector<vector<Allele>> Chromosome::operator+(vector<vector<Allele>> rhs)
{

	vector<vector<Allele>> newChromosome = rhs;
	int firstGenePos = (rand() % (newChromosome.size() + 1));


	for (vector<vector<Allele>>::size_type i = 0; i < genes.size(); i++)

	{

		for (vector<Allele>::size_type j = 0; j < this->genes[i].size(); j++)
		{
		}
	}


	return newChromosome;
};*/

vector<Allele> Chromosome::GetGenes(int x)
{

	vector<Allele> temp = genes.at(x);
	return genes.at(x);
};

int Chromosome::GetPos()
{

	int pos = (rand() % (genes.size()));
	return pos;
};
