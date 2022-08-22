#include "Cuadrado.h"
#include <vector>
using namespace std;
class Vector_Cuadrados {
	vector<Cuadrado*>*arreglo;
public: 
	Vector_Cuadrados() {
		arreglo = new vector<Cuadrado*>();
	}
	void AgregarCuadrado(int x, int y, int ancho, int alto, int value,int direccion ,int color) {
		arreglo->push_back(new Cuadrado(x, y, ancho, alto,value,direccion ,color));
	}
	void Draw_Scuare(Graphics^ L) {
		for (size_t i = 0; i < arreglo->size(); i++)
		{
			arreglo->at(i)->Draw(L);
		}
	}
	void MoverCuadrado() {
		for (size_t i = 0; i < arreglo->size(); i++)
		{
			arreglo->at(i)->Move();
		}
	}

	int getSize() {
		return arreglo->size();
	}

	Cuadrado* getCuadrado(int i) {
		return arreglo->at(i);
	}
};
