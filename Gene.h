#pragma once
#include <string>
#include <vector>
#include "Allele.h"
using namespace std;

class Gene
{
  public:
	Gene();
	//Gene(const Allele &x, const Allele &y);
	Gene(const string &a, const string &b, const Allele &x, const Allele &y);

	void SetNameandTrait(const string &x, const string &y);
	string GetGeneName();
	string GetGeneTrait();

	string FindUserGene(const string &x); //FIXME DO SOMETHING WITH THIS
	bool GeneClassTestBench();

	void AddAlleles(const Allele &x, const Allele &y);

	void OutputToFile(ofstream &ofs);

	void AnalyzeGenotype();
	Allele doMeiosis();

  private:
	string geneName;
	string geneTrait;
	Allele A;
	Allele B;
};