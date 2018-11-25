#include "Gene.h"
#include "Allele.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;
Gene::Gene()
{
	geneName = "noNameSet";
	geneTrait = "noTraitSet";
};
vector<Allele> Gene::AddAllele(const Allele &x, const Allele &y)
{
	alleles.resize(0);
	alleles.push_back(x);
	alleles.push_back(y);
	return alleles;
};

void Gene::SetNameandTrait(const string &x, const string &y)
{
	geneName = x;
	geneTrait = y;
};
/*
vector<Allele> Gene::GetAlleles()
{

	return alleles;
};
 */
string Gene::FindUserGene(const string &x)
{
	return x;
};