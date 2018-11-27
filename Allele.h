#include <string>
#pragma once

using namespace std;
class Allele
{

  public:
	Allele();
	string GetType();
	string GetVariant();
	string GetSequence(const int &x);
	void ReturnToMenu();
	string GetVariant(const int &x);
	string GetType(const int &x);
	string GetSequence();
	bool alleleClassTestBench();
	void SetThreeVariables(string &variant, string &type, string &sequence);
	void WriteAlleleToFile(ofstream &, string &userfile);

	Allele(const string &x, const string &y, const string &z);

  private:
	string alleleVariant;
	string alleleType;
	string nucleotideSequence;
};