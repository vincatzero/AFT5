#include "Allele.h"
#include "Gene.h"
#include "Chromosome.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

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
};

void Chromosome::AddGenes(const vector<Allele> &x)
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
		newChromosome.AddGenes(temp);
		temp.resize(0);						   //DONT THINK I NEED THIS ANYMORE
		tempGene.SetNameandTrait(name, trait); //OR THIS

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

/*

void Chromosome::OutputToFile(ofstream &ofs)
{
	Gene newGene;
	//ofs << GetGeneName() + ",";
	ofs.close();

	for (vector<vector<Allele>>::size_type i = 0; i < genes.size(); i++)

	{
		for (vector<Allele>::size_type j = 0; j < this->genes[i].size(); j++)

		{
			cout << GetGeneName(i) + "," << GetGeneTrait(i) + "," << genes[i][j].GetVariant() + "," << genes[i][j].GetType(i) + ","; //genes[i][j].GetSequence(i) + "\n";

			//ofs << GetGeneName(i) + "," << GetGeneTrait(i) + "," << genes[i][j].GetVariant();
		}
	}
};
*/