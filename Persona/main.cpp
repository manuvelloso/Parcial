
#include <iostream>

using namespace std;

class cPersona {
protected:
	int edad;

public:
	cPersona() { edad = (rand() % 100) + 1; }
	virtual ~cPersona() {};
	void Hablar() { cout << "Hola!" << endl; }
	virtual void Trabajar() { cout << "No tengo trabajo" << endl; }
};

class cEmpleado : public cPersona {

	const int ID;

public:
	cEmpleado();
	~cEmpleado() {};
	void Trabajar() { cout << "Me voy al trabajo" << endl; }
};

cEmpleado::cEmpleado() : cPersona() , ID((rand() % 100) + 1)
{
}

int main() {

	cPersona* personita = new cPersona();
	cEmpleado* miEmpleado = new cEmpleado();

	personita->Hablar();
	personita->Trabajar();
	miEmpleado->Hablar();
	miEmpleado->Trabajar();

	delete personita;
	delete miEmpleado;
	return 0;
}

