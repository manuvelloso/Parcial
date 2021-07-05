
#include <iostream>
#include <math.h>

using namespace std;
class cFigura
{
protected:
	const int lados;

public:
	cFigura(int lados);
	~cFigura() {};
	virtual float CalcularArea() = 0;
	virtual float CalcularPerimetro() = 0;
};
cFigura::cFigura(int lados) : lados(lados)
{
}

class cTriangulo :
	public cFigura
{
private:
	float base;
	float altura;

public:
	cTriangulo();
	~cTriangulo();
	float CalcularArea();
	float CalcularPerimetro();
};
cTriangulo::cTriangulo() : cFigura(3)
{
	base = (rand() % 10) + 1;
	altura = base = (rand() % 10) + 1;
}

cTriangulo::~cTriangulo()
{
}

float cTriangulo::CalcularArea()
{
	return base * altura;
}

float cTriangulo::CalcularPerimetro()
{
	int perim = base + altura + sqrt(base * base + altura * altura);
	return perim;
}

class cCuadrado :
	public cFigura
{
private:
	float base;
public:
	cCuadrado(float base = 2, int lados = 4);
	~cCuadrado() {};
	float CalcularArea();
	float CalcularPerimetro();
};

cCuadrado::cCuadrado(float base, int lados) :cFigura(lados)
{
	this->base = base;
}

float cCuadrado::CalcularArea()
{
	return base * base;
}

float cCuadrado::CalcularPerimetro()
{
	return lados * base;
}
class cPentagono :
	public cFigura
{
private:
	float largo;
public:
	cPentagono(cPentagono& P);
	cPentagono();
	~cPentagono() {};
	float CalcularArea();
	float CalcularPerimetro();
};

cPentagono::cPentagono(cPentagono& P) : cFigura(P.lados)
{
	this->largo = P.largo;
}

cPentagono::cPentagono() : cFigura(5)
{
	largo = (rand() % 5) + 1;
}

float cPentagono::CalcularArea()
{
	float altura = largo * (1 / sqrt(2));
	float area = (altura * largo / 2) * 10;
	return area;
}

float cPentagono::CalcularPerimetro()
{
	return lados * largo;
}

int main()
{
	cFigura* trig = new cTriangulo();
	cFigura* cuad = new cCuadrado();
	cPentagono* pent = new cPentagono();
	cFigura* pent2 = new cPentagono(*pent);

	cout << trig->CalcularArea() << endl;
	cout << cuad->CalcularArea() << endl;
	cout << pent->CalcularArea() << endl;
	cout << pent2->CalcularArea() << endl;

	cout << trig->CalcularPerimetro() << endl;
	cout << cuad->CalcularPerimetro() << endl;
	cout << pent->CalcularPerimetro() << endl;
	cout << pent2->CalcularPerimetro() << endl;

	delete trig;
	delete cuad;
	delete pent;
	delete pent2;
}