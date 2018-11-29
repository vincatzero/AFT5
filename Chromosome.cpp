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

Chromosome::Chromosome(){

};
/*
Chromosome::Chromosome(const Gene &x)
{

	Genes.push_back(x);
};
*/
void Chromosome::AddGene(const Gene &x) //DELETE THIS FUNCTION
{
	Genes.push_back(x);
};

/*


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



bool Chromosome::ChromosomeClassTestBench()
{
	Chromosome testData;
	vector<Allele> testVector;
	string testName = "testName";
	string testTrait = "testTrait";

	testData.AddGene(testVector);
	if (testData.genes.size() != 1)
	{
		cout << "Chrosome class resize vector error" << endl;
		return false;
	}

	testData.AddNameandTrait(testName, testTrait);
	if (testData.geneNameandTrait[0] != "testName,testTrait")
	{
		cout << "Chromosome class set Name/Trait error" << endl;
		return false;
	}

	if (testName != testData.GetGeneName(0))
	{
		cout << "Chromosome class get name error" << endl;
		return false;
	}
	if (testTrait != testData.GetGeneTrait(0))
	{
	}
}
*/
//else { cout << "All chromosome class tests passed" << endl; }
//return true;

void Chromosome::InputFromFile(ifstream &ifs){
	//FIXME DELETE THIS OR FIGURE OUT WHAT I WANT TO DO WITH IT
};

void Chromosome::OutputToFile(ofstream &ofs)
{
	Gene tempGene;

	for (vector<Gene>::size_type i = 0; i < Genes.size(); i++)
	{
		tempGene = Genes.at(i);
	}

	tempGene.OutputToFile(ofs); //SHOULD THIS BE IN THE LOOP?
};

void Chromosome::AnalyzeGenotype()
{
	string expressedAllele;
	string expressedNucleotideSeq;
	Gene tempGene;
	for (vector<Gene>::size_type i = 0; i < Genes.size(); i++)
	{
		cout << "        Gene " << i + 1 << endl
			 << "Gene name:            " << Genes[i].GetGeneName() << endl
			 << "Genetic trait:        " << Genes[i].GetGeneTrait() << endl;
		tempGene = Genes.at(i);
		tempGene.AnalyzeGenotype();
	}
};

Chromosome Chromosome::operator+(Chromosome rhs)
{
	Gene a, b;
	for (vector<Gene>::size_type i = 0; i < Genes.size(); i++)
	{
		a = this->Genes[i];
		b = rhs.Genes[i];
	}

	Gene newGene(a.GetGeneName(), a.GetGeneTrait(), a.doMeiosis(), b.doMeiosis()); //TEST THIS
	cout
		<< endl
		<< "A new chromosome object has been" << endl
		<< "created through meiosis." << endl
		<< endl;
	//newGene.SetNameandTrait(a.GetGeneName(), a.GetGeneTrait());
	Chromosome newChromosome;
	newChromosome.AddGene(newGene); //TEST THIS TOO ESPECIALLY FOR GENE NAME
	//a.doMeiosis().ReturnToMenu();

	return newChromosome;
};

bool Chromosome::ChromosomeClassTestBench()
{
	string testfile = "testing123ABC098.csv";
	Chromosome testData;
	Allele testAllele1;
	Allele testAllele2;
	Gene testGene1("testname1", "testtrait1", testAllele1, testAllele2);
	Gene testGene2("testname2", "testtrait2", testAllele1, testAllele2);

	ofstream tester_out;

	testData.AddGene(testGene1);
	testData.AddGene(testGene2);
	if (testData.Genes.size() != 2)
	{
		cout << "Chromosome class add gene error" << endl;
		return false;
	}
	//testGene1.SetNameandTrait("testname", "testtrait");
	tester_out.open(testfile);

	testData.OutputToFile(tester_out);
	tester_out.close();

	/*else
	{
		cout << "All chromosome class tests passed" << endl;
		remove("testing123ABC098.csv");
	}*/

	Genes.resize(0); //MAKE SURE I NEED THIS
	return true;
};
