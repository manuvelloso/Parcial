#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#include "stdlib.h"

using namespace std;



class cClaseA

{

public:

	cClaseA() {}
	virtual ~cClaseA() { cout << "Llamando destructor A" << endl; }

	// Implemente destructor de cClaseA
};

class cClaseB :public cClaseA

{

public:

	cClaseB() {}
	~cClaseB() { cout << "Llamando destructor B" << endl; }
	// Implemente destructor de cClaseB
};



//----------- NO MODIFICAR EL MAIN ------------


int main()

{

	cClaseA* claseB = new cClaseB();

	delete claseB;

	return 0;

}