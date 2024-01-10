#include <iostream>
#include <string>
#include <fstream>

#include "Sayi.hpp"
#include "SayilarListesi.hpp"


using namespace std;


int main() {
	Sayi* sayi;
	SayilarListesi* list= new SayilarListesi();
	ifstream dosyaOku("Sayilar.txt");
	int number;
	while (dosyaOku >> number) {
        Sayi* sayi= new Sayi();
		int txtData = number;
        while (txtData > 0) {
            int digit = txtData % 10;
            sayi->addNode(digit);
            txtData /= 10;
        }	
		list->addNode(sayi);	   
	}
	int choice;
	
	list->PrintAllSayilar();
	do {
			
		cout << "1. Tek basamaklari basa al.\n";
		cout << "2. Basamaklari tersle.\n";
		cout << "3. En buyuk cikar\n";
		cout << "4. Cikis\n";
		cout << "Secim: ";
		cin >> choice;
		switch (choice) {
			case 1:{
				list->TekCiftAyir();
				list->PrintAllSayilar();
				break;
			}
			case 2:{
				list->Tersle();
				list->PrintAllSayilar();
				break;
			}
			case 3:{	
				list->deleteMax();
				list->PrintAllSayilar();
				break;
			}
			case 4:{
				cout << "cikis yapiliyor" << endl;
				break;
			}
			default:				
				cout << "Gecersiz secim. Lutfen 1-4 arasinda bir deger girin." << endl;				
				break;
		}
    } while (choice != 4);

    list->clear();
	delete list;
    return 0;
    
}
