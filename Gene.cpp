#include "Gene.h"
#include "Allele.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;
#include <ctime>
Gene::Gene(){};
Gene::Gene(const string &a, const string &b, const Allele &x, const Allele &y)
{
	geneName = a;
	geneTrait = b;
	A = x;
	B = y;
};

void Gene::SetNameandTrait(const string &x, const string &y)
{
	geneName = x;
	geneTrait = y;
};

string Gene::GetGeneName()
{
	return geneName;
};
string Gene::GetGeneTrait()
{
	return geneTrait;
};

void Gene::AddAlleles(const Allele &x, const Allele &y)
{
	Gene NewGene;
	A = x;
	B = y;
};

void Gene::OutputToFile(ofstream &ofs)
{
	ofs << this->GetGeneName() + "," << this->GetGeneTrait() + ",";
	Allele a, b;
	a = this->A;
	b = this->B;
	A.OutputToFile(ofs);
	ofs << ",";
	B.OutputToFile(ofs);
	ofs << '\n';
};

void Gene::AnalyzeGenotype()
{
	Allele a, b;

	a = this->A;
	a.AnalyzeGenotype();

	b = this->B;
	b.AnalyzeGenotype();
};

Allele Gene::doMeiosis()
{
	Allele chosenAllele;
	srand(time(NULL));
	int randomAllele = (rand() % 2) + 1;

	if (randomAllele == 1)
	{
		chosenAllele = this->A;
	}
	else if (randomAllele == 2)
	{
		chosenAllele = this->B;
	}
	return chosenAllele;
};

bool Gene::GeneClassTestBench()
{
	Gene testData;
	string tester1 = "test1";
	string tester2 = "test2";
	Allele testAllele1("testvariant1", "dominant", "testseq1");
	Allele testAllele2("testvariant2", "testtype2", "testseq2");
	ofstream tester_out;
	ifstream tester_in;
	string in_out_1;
	string in_out_2;
	string in_out_3;
	string in_out_4;
	string in_out_5;
	string in_out_6;
	string in_out_7;
	string in_out_8;
	string testfile = "testing123ABC098.csv";

	testData.SetNameandTrait(tester1, tester2);
	if ((testData.GetGeneName() != "test1") || (testData.GetGeneTrait() != "test2"))
	{
		cout << "Gene class Set/Get error" << endl;
		return false;
	}

	testData.AddAlleles(testAllele1, testAllele2);
	if ((testData.A.GetVariant() != "testvariant1") || (testData.A.GetType() != "dominant") || (testData.A.GetSequence() != "testseq1") ||
		(testData.B.GetVariant() != "testvariant2") || (testData.B.GetType() != "testtype2") || (testData.B.GetSequence() != "testseq2"))
	{
		cout << "Gene class add allele error" << endl;
		return false;
	}

	tester_out.open(testfile);
	testData.OutputToFile(tester_out);
	tester_out.close();

	tester_in.open(testfile);
	if (!tester_in.is_open())
	{
		cout << "Allele class Error opening file" << endl;
		return false;
	}

	for (int i = 1; i <= 1; i++)
	{
		getline(tester_in, in_out_1, ',');
		getline(tester_in, in_out_2, ',');
		getline(tester_in, in_out_3, ',');
		getline(tester_in, in_out_4, ',');
		getline(tester_in, in_out_5, ',');
		getline(tester_in, in_out_6, ',');
		getline(tester_in, in_out_7, ',');
		getline(tester_in, in_out_8, '\n');
	}

	if ((in_out_1 != "test1") || (in_out_2 != "test2") || (in_out_3 != "testvariant1") || (in_out_4 != "dominant") ||
		(in_out_5 != "testseq1") || (in_out_6 != "testvariant2") || (in_out_7 != "testtype2") || (in_out_8 != "testseq2"))
	{
		cout << "Gene class write to file error " << endl;
		return false;
	}

	testAllele1 = testData.doMeiosis();
	if ((testAllele1.GetVariant() != "testvariant1" && testAllele1.GetVariant() != "testvariant2") ||
		(testAllele1.GetType() != "dominant" && testAllele1.GetType() != "testtype2") ||
		(testAllele1.GetSequence() != "testseq1" && testAllele1.GetSequence() != "testseq2"))

	{
		cout << "Gene class do meiosis error" << endl;
		return false;
	}
	else
	{
		cout << "All gene class tests passed" << endl;
		remove("testing123ABC098.csv");
	}

	return true;
};
