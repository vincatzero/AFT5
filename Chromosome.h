#pragma once
#include "Allele.h"
#include "Gene.h"
#include <vector>
#include <string>

using namespace std;

class Chromosome
{
  public:
	Chromosome();
	Chromosome(const Gene &x);
	void AnalyzeGenotype();
	void AddGenes(const vector<Allele> &x);
	void AddNameandTrait(const string &x, const string &y);
	string GetGeneName(const int &x);
	string GetGeneTrait(const int &x);
	void OutputToFile(ofstream &ofs);

	Chromosome CreateChromosome();

  private:
	vector<vector<Allele>> genes;
	vector<string> geneNameandTrait;
	string name;
	string trait;
	string type1;
	string sequence1;
	string variant1;
	string type2;
	string sequence2;
	string variant2;
	Allele allele;
};