#include "Allele.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

Allele::Allele()
{
	alleleVariant = "noVariant";
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



