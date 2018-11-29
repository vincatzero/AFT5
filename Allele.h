#include <string>
#pragma once

using namespace std;
class Allele
{

  public:
	Allele();
	Allele(const string &x, const string &y, const string &z);

	string GetType();
	string GetVariant();
	string GetSequence();

	string GetSequence(const int &x);
	void ReturnToMenu();
	void SetThreeVariables(string &variant, string &type, string &sequence);
	void OutputToFile(ofstream &ofs);
	void AnalyzeGenotype();
	bool alleleClassTestBench();

  private:
	string alleleVariant;
	string alleleType;
	string nucleotideSequence;
};