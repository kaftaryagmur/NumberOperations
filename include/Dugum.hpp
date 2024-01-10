#ifndef DUGUM_HPP
#define DUGUM_HPP


class Sayi;
class Dugum {
public:	
	Sayi* sayi;
    Dugum* next;
    Dugum(Sayi* sayi);
    ~Dugum();
	Sayi* getSayi();
	Dugum* getNext();
	
};

#endif
