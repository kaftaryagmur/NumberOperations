/** 
* @file Dugum.cpp
* @description Dosyadan okunan sayıların bağlı listeyi oluşturmak üzere düğümlerinin oluşturulması.
* @course 2. öğretim A grubu
* @assignment Ödev 1
* @date 25/11/2023
* @author Yağmur Kaftar/ yagmur.kaftar@ogr.sakarya.edu.tr
*/
#include "Dugum.hpp"
#include "Sayi.hpp"
#include "Basamak.hpp"
#include<iostream>
using namespace std;

Dugum::Dugum(Sayi* s){
	this->sayi = s;
    this->next = NULL;
}

Dugum::~Dugum() {
	
}

Sayi* Dugum::getSayi(){
	return sayi;
}
Dugum* Dugum::getNext(){
	return next;
}