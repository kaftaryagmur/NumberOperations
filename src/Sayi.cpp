/** 
* @file Sayi.cpp
* @description Dosyadan okunan sayıların bağlı listeyi oluşturmak üzere düğümlerinin oluşturulması.
* @course 2. öğretim A grubu
* @assignment Ödev 1
* @date 25/11/2023
* @author Yağmur Kaftar/ yagmur.kaftar@ogr.sakarya.edu.tr
*/
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

#include "Sayi.hpp"	
#include "Basamak.hpp"
#include "SayilarListesi.hpp"

Sayi::Sayi() {
    first = NULL;
} 
Sayi::~Sayi() {
	
}
void Sayi::addNode(const int data){
	Basamak* newBasamak = new Basamak(data);
    if (first == NULL) {
        first = newBasamak;
    } else {
        newBasamak->next = first;
        first = newBasamak;
    }
}
void Sayi::printOutNodeAddress(){
	Basamak* tmp = first;
    while (tmp != NULL) {
        uintptr_t address = reinterpret_cast<uintptr_t>(tmp);
        cout << "* " << std::setw(3) << std::hex << std::setfill(' ') << (address % 0x1000) << " *  ";

        tmp = tmp->next;
    }
	cout<<endl;
}
void Sayi::printOutStars(){
	Basamak* tmp = first;
    while (tmp != NULL) {
		cout<<"*******"<<"  ";
        tmp = tmp->next;
    }
}
void Sayi::printOutNodeData(){
	Basamak* tmp = first;
    while (tmp != NULL) {
        cout <<"*  "<<tmp->data<<"  *  ";

        tmp = tmp->next;
    }
	cout<<endl;
}
void Sayi::printOutListAddres(Sayi* sayi){
	cout<<"#"<<sayi<<"#"<<"  ";
} 
void Sayi::printOutSharp(){
	cout<<"##########"<<"  ";
}
void Sayi::printOutLine(){
	cout<<"#--------#"<<"  ";
}
void Sayi::printOutListData() {
    Basamak* tmp = first;

    // Basamak sayısını hesapla
    int basamakSayisi = 0;
    while (tmp != NULL) {
        basamakSayisi++;
        tmp = tmp->next;
    }

    tmp = first; // İkinci geçiş için başa dön

    cout << "#";

    while (tmp != NULL) {
        cout << tmp->data;
        tmp = tmp->next;
    }

    cout << std::setw(11 - basamakSayisi) << " #  "; // Genişlik ayarlaması
}


void Sayi::SayiTekCiftAyir() 
{
    Basamak* gecerli = first;
    Basamak *ilktek = NULL;
    Basamak* ilkcift = NULL; 
    while (gecerli != NULL) 
    {
        Basamak* next = gecerli->next; 
        if (gecerli->data % 2 == 0) 
        { 
            gecerli->next = ilkcift; 
            ilkcift = gecerli; 
        } 
        else 
        { 
            gecerli->next = ilktek;
            ilktek = gecerli; 
        }
        gecerli = next; 
    }
    if (ilktek == NULL) 
    {
        first = ilkcift;
    } 
    else 
    { 
        first = ilktek;
        Basamak* temp = ilktek;
        while (temp->next != NULL) 
        {
            temp = temp->next;
        }
        temp->next = ilkcift; 
    }
}

void Sayi::SayiTersle() {
    Basamak* gecerli = first;
    Basamak* onceki = NULL;
    Basamak *next = NULL;
    while (gecerli != NULL) 
    {
        next = gecerli->next;
        gecerli->next = onceki;
        onceki = gecerli; 
        gecerli = next; 
    }
    first=onceki;
}









