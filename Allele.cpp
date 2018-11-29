#include "Allele.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

Allele::Allele()
{
	alleleVariant = "noVariant";
	alleleType = "noType";
	nucleotideSequence = "noSequence";
};
Allele::Allele(const string &x, const string &y, const string &z)
{
	alleleVariant = x;
	alleleType = y;
	nucleotideSequence = z;
};

string Allele::GetType()
{
	return alleleType;
};

string Allele::GetSequence()
{
	return nucleotideSequence;
};
string Allele::GetSequence(const int &x)
{
	return nucleotideSequence;
};

string Allele::GetVariant()
{

	return alleleVariant;
};

void Allele::ReturnToMenu()
{
	char c;
	cout << "Press enter to return to menu:" << endl;
	cin.get(c);
};

void Allele::SetThreeVariables(string &variant, string &type, string &sequence)
{
	alleleVariant = variant;
	alleleType = type;
	nucleotideSequence = sequence;
};

bool Allele::alleleClassTestBench()
{
	Allele testData;
	string tester1 = "test1";
	string tester2 = "test2";
	string tester3 = "test3";
	ofstream tester_out;
	ifstream tester_in;
	string in_out_1;
	string in_out_2;
	string in_out_3;
	string testfile = "testing123ABC098.csv";

	testData.SetThreeVariables(tester1, tester2, tester3);
	if ((testData.GetVariant() != "test1") || (testData.GetType() != "test2") || (testData.GetSequence() != "test3"))
	{
		cout << "Allele class Set/Get error" << endl;
		return false;
	};
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
	}

	if ((in_out_1 != "test1") || (in_out_2 != "test2") || (in_out_3 != "test3")) // || (in_out_4 != "test2") || (in_out_5 != "test2") || (in_out_6 != "test2"))
	{
		cout << "Allele class write to file error " << endl;
		return false;
	}
	else
	{
		cout << "All allele class tests passed" << endl;
		remove("testing123ABC098.csv");
	}

	return true;
};

void Allele::OutputToFile(ofstream &ofs)
{
	ofs << GetVariant() + "," << GetType() + "," << GetSequence();
};

void Allele::AnalyzeGenotype()
{
	if (GetType() == "dominant")
	{
		cout << "Expressed allele:     " << GetVariant() << endl
			 << "Nucleotide sequence:  " << GetSequence() << endl
			 << endl;
	}
};
