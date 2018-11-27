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
string Allele::GetType(const int &x) { return alleleType; };

string Allele::GetSequence() { return nucleotideSequence; };
string Allele::GetSequence(const int &x) { return nucleotideSequence; };

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

void Allele::WriteAlleleToFile(ofstream &, string &userfile) //NOT SURE ABOUT THIS
{
	ofstream AlleleOutput;
	AlleleOutput.open(userfile, ios::app);
	AlleleOutput << GetVariant() + "," << GetType() + "," << GetSequence();

	AlleleOutput.close();
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

	string testfile = "test.csv";

	//TEST 1
	testData.SetThreeVariables(tester1, tester2, tester3);
	if ((testData.GetVariant() != "test1") || (testData.GetType() != "test2") || (testData.GetSequence() != "test3"))
	{
		cout << "Allele class Set/Get nucleotide sequence error" << endl;
		return false;
	};

	testData.WriteAlleleToFile(tester_out, testfile);
	tester_in.open("test.csv");
	if (!tester_in.is_open())
	{
		cout << "Allele class Error opening file" << endl;
		return false;
	}

	for (int i = 1; i <= 1; i++) // (int i = 0; i < counter; i++)   //CAN I USE .GOOD HERE AGAIN?
	{
		getline(tester_in, in_out_1, ',');
		getline(tester_in, in_out_2, ',');
		getline(tester_in, in_out_3, ',');
	}

	if ((in_out_1 != "test1") || (in_out_2 != "test2") || (in_out_3 != "test3")) // || (in_out_4 != "test2") || (in_out_5 != "test2") || (in_out_6 != "test2"))
	{
		cout << "Allele class Read/Write to file error " << endl;
		return false;
	}
	else
	{
		cout << "All allele class tests passed" << endl;
		remove("test.csv");
	}

	return true;
};
