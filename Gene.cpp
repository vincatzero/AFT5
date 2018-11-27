#include "Gene.h"
#include "Allele.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;
Gene::Gene(){

};
vector<Allele> Gene::AddAllele(const Allele &x, const Allele &y)
{
	alleles.resize(0);
	alleles.push_back(x);
	alleles.push_back(y);
	return alleles;
};

string Gene::FindUserGene(const string &x)
{
	return x;
};

bool Gene::GeneClassTestBench()
{

	Allele testAllele1;
	Allele testAllele2;

	AddAllele(testAllele1, testAllele2);
	if (alleles.size() != 2)
	{
		cout << "Gene class vector<Allele> resize error" << endl;
		return false;
	}
	else
	{
		cout << "All gene class tests passed" << endl;
	}
	//for (vector<Allele>::size_type i = 0; i < alleles.size(); i++)
	//{
	//}

	return true;
};
