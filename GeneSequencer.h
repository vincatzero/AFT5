#pragma once
#include <fstream>
#include "Gene.h"
#include "Chromosome.h"
#include "Allele.h"
#include <vector>
#include <string>

using namespace std;

class GeneSequencer
{
  public:
	GeneSequencer();
	Chromosome CreateChromosome();
	Chromosome ImportChromosome(const string &fileName);
	void ExportChromosome(Chromosome c, const string &filename = "");

  private:
	string name;
	string trait;
	string type1;
	string sequence1;
	string variant1;
	string type2;
	string sequence2;
	string variant2;
	vector<Chromosome> chromosomes;
	Allele allele;
};