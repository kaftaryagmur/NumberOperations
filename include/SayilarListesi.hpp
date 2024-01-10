#ifndef SAYILARLISTESI_HPP
#define SAYILARLISTESI_HPP

#include "Dugum.hpp"
#include "Sayi.hpp"

class SayilarListesi{
private:
	Dugum* first;
	
public:
	SayilarListesi();
	~SayilarListesi();
	void addNode(Sayi* s);
	void printAll(); 
	void clear();
	Dugum* getFirst();
	void PrintAllSayilar();
	void deleteMax();
	int compare(Sayi* s1, Sayi* s2);
	void TekCiftAyir();
	void Tersle();




};

#endif