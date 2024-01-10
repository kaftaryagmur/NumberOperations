/** 
* @file Basamak.cpp
* @description Dosyadan okunan sayıların bağlı listeyi oluşturmak üzere düğümlerinin oluşturulması.
* @course 2. öğretim A grubu
* @assignment Ödev 1
* @date 25/11/2023
* @author Yağmur Kaftar/ yagmur.kaftar@ogr.sakarya.edu.tr
*/
#include "Basamak.hpp"
#include<iostream>

using namespace std;

Basamak::Basamak(int data) {
    this->data = data;
    this->next = NULL; 
}
