/** 
* @file SayilarListesi.cpp
* @description Dosyadan okunan sayıların bağlı listeyi oluşturmak üzere düğümlerinin oluşturulması.
* @course 2. öğretim A grubu
* @assignment Ödev 1
* @date 25/11/2023
* @author Yağmur Kaftar/ yagmur.kaftar@ogr.sakarya.edu.tr
*/
#include <iostream>
#include<iomanip>
using namespace std;

#include "SayilarListesi.hpp"	
#include "Dugum.hpp"
#include "Sayi.hpp"


SayilarListesi::SayilarListesi() {
    first = NULL;
} 

SayilarListesi::~SayilarListesi() {
   clear();
}
void SayilarListesi::addNode(Sayi* s) {
    Dugum* newDugum = new Dugum(s);
    if (first == NULL) {
        first = newDugum;
    } else {
        Dugum* tmp = first;
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = newDugum;
    }
}



void SayilarListesi::clear() {
    Dugum* del = first;
    while (del != NULL) {
        Dugum* tmp = del->next;
        delete del;
        del = tmp;
    }
    first = NULL;
}

Dugum* SayilarListesi::getFirst(){
	return first;
}

void SayilarListesi::PrintAllSayilar() {

    Dugum* tmp = first;
    while (tmp != NULL) {

        Sayi* sayi = tmp->getSayi();
        if (sayi != NULL) {
            sayi->printOutSharp();
            sayi->printOutStars();
            cout << endl;

            sayi->printOutListAddres(sayi);
            sayi->printOutNodeAddress();
            sayi->printOutLine();
            sayi->printOutStars();
            cout << endl;

            sayi->printOutListData();
            sayi->printOutNodeData();
            sayi->printOutSharp();
            sayi->printOutStars();
            cout << endl << endl;
        } else {
            cout << "Hata: NULL Sayi!" << endl;
        }
        tmp = tmp->next;
    }
}

void SayilarListesi::deleteMax(){
    Dugum* current = first; 
    Dugum* prev = NULL; 
    Dugum* max = NULL; 
	Dugum* maxPrev = NULL; 
    while(current != NULL){
        if(max == NULL || compare(current->sayi, max->sayi) > 0){ 
            max = current; 
            maxPrev = prev;
        }
		
        prev = current; 
        current = current->next; 
    }
    if(max != NULL){
        if(maxPrev != NULL){
            maxPrev->next = max->next; 
        }
        else{
			cout<<"Empty list!\n"<<endl;
            first = max->next; 
        }
        delete max; 
    }
}

int SayilarListesi::compare(Sayi* s1, Sayi* s2){
    Basamak* b1 = s1->first; 
    Basamak* b2 = s2->first;
    int len1 = 0; 
    int len2 = 0; 
    while(b1 != NULL){ 
        len1++; 
        b1 = b1->next; 
    }
    while(b2 != NULL){
        len2++; 
        b2 = b2->next; 
    }
    if(len1 > len2){ 
        return 1; 
    }
    else if(len1 < len2){ 
        return -1; 
    }
    else{ 
        b1 = s1->first;
        b2 = s2->first; 
        while(b1 != NULL && b2 != NULL){ 
            if(b1->data > b2->data){
                return 1;
            }
            else if(b1->data < b2->data){ 
                return -1; 
            }
            else{
                b1 = b1->next; 
                b2 = b2->next; 
            }
        }
        return 0; 
    }
}
void SayilarListesi::TekCiftAyir() 
{
    Dugum* gecerli = first;
    while (gecerli != NULL) 
    {
        gecerli->sayi->SayiTekCiftAyir();
        gecerli = gecerli->next; 
    }
}
void SayilarListesi::Tersle() 
{
    Dugum* current = first;
    while (current != nullptr) {
        current->sayi->SayiTersle();
        current = current->next;
    }
}
