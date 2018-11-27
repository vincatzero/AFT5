#pragma once
#include <string>
#include <vector>
#include "Allele.h"
using namespace std;

class Gene
{
  public:
	Gene();
	Gene(const Allele &x, const Allele &y);
	vector<Allele> AddAllele(const Allele &x, const Allele &y);
	//void SetNameandTrait(const string &x, const string &y);
	string FindUserGene(const string &x);
	bool GeneClassTestBench();
	//FIXME DO I NEED A GETTER FOR THE VECTOR?

  private:
	vector<Allele> alleles;
};