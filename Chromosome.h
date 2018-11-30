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

	void AnalyzeGenotype();

	void AddGene(const Gene &x);

	void OutputToFile(ofstream &ofs);

	void InputFromFile(ifstream &ifs);
	Chromosome operator+(Chromosome rhs);

	bool ChromosomeClassTestBench();

  private:
	vector<Gene> Genes;
};