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

void Chromosome::AddGene(const Gene &x)
{
	Genes.push_back(x);
};

void Chromosome::OutputToFile(ofstream &ofs)
{
	Gene tempGene;

	for (vector<Gene>::size_type i = 0; i < Genes.size(); i++)
	{
		tempGene = Genes.at(i);
		tempGene.OutputToFile(ofs);
	}
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

	Gene newGene(a.GetGeneName(), a.GetGeneTrait(), a.doMeiosis(), b.doMeiosis());
	Chromosome newChromosome;
	newChromosome.AddGene(newGene);

	return newChromosome;
};

bool Chromosome::ChromosomeClassTestBench()
{
	string testfile = "testing123ABC098.csv";
	Chromosome testData;
	Chromosome testData2;
	Allele testAllele1("testvar1", "testtype1", "testseq1");
	Allele testAllele2("testvar2", "testtype2", "testseq2");

	string name;
	string trait;
	string type1;
	string sequence1;
	string variant1;
	string type2;
	string sequence2;
	string variant2;
	ofstream tester_out;
	ifstream tester_in;

	Gene testGene1("testname1", "testtrait1", testAllele1, testAllele2);
	Gene testGene2("testname2", "testtrait2", testAllele1, testAllele2);

	testData.AddGene(testGene1);
	testData.AddGene(testGene2);
	if (testData.Genes.size() != 2)
	{
		cout << "Chromosome class add gene error" << endl;
		return false;
	}
	testData.Genes.resize(1);
	tester_out.open(testfile);

	testData.OutputToFile(tester_out);
	tester_out.close();
	tester_in.open(testfile);
	for (int i = 1; i <= 1; i++)
	{
		getline(tester_in, name, ',');
		getline(tester_in, trait, ',');
		getline(tester_in, variant1, ',');
		getline(tester_in, type1, ',');
		getline(tester_in, sequence1, ',');
		getline(tester_in, variant2, ',');
		getline(tester_in, type2, ',');
		getline(tester_in, sequence2, '\n');
	}

	if (name != "testname1" || trait != "testtrait1" || type1 != "testtype1" || sequence1 != "testseq1" || variant1 != "testvar1" ||
		type2 != "testtype2" || sequence2 != "testseq2" || variant2 != "testvar2")
	{
		cout << "Chromosome class output to file error" << endl;
		return false;
	}

	Allele tempAllele = testGene1.doMeiosis();
	if ((testAllele1.GetType() != tempAllele.GetType() && testAllele2.GetType() != tempAllele.GetType()) ||
		(testAllele1.GetSequence() != tempAllele.GetSequence() && testAllele2.GetSequence() != tempAllele.GetSequence()) ||
		(testAllele1.GetVariant() != tempAllele.GetVariant() && testAllele2.GetVariant() != tempAllele.GetVariant()))
	{
		cout << "Chromosome class doMeiosis error" << endl;
		return false;
	}

	else
	{
		cout << "All chromosome class tests passed" << endl;
		remove("testing123ABC098.csv");
	}

	return true;
};
