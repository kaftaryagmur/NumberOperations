#ifndef SAYI_HPP
#define SAYI_HPP

#include "Basamak.hpp"
#include "Dugum.hpp"
class SayilarListesi;
class Sayi{
public:
	Basamak* first;
	Sayi();
	~Sayi();
	void addNode(const int data);	
	void printOutNodeAddress();   
	void printOutStars();
	void printOutNodeData();
	void printOutListAddres(Sayi* sayi);
	void printOutSharp();
	void printOutLine();
	void printOutListData();
	void SayiTekCiftAyir();
	void SayiTersle();
	

};

#endif