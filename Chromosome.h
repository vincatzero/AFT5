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
	//Chromosome(const Gene &x);

	void AnalyzeGenotype();

	void AddGene(const Gene &x);

	void OutputToFile(ofstream &ofs);

	void InputFromFile(ifstream &ifs); //DO SOMETHING WITH THIS
	vector<string> FindGene(string n); //AND THIS
	Chromosome operator+(Chromosome rhs);

	bool ChromosomeClassTestBench();

  private:
	vector<Gene> Genes;
};