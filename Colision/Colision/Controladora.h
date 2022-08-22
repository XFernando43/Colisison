#pragma once
#include <iostream>
#include "vector_Cuadrados.h"
#define num_aumento 20
using namespace std;
class Controladora {
	Vector_Cuadrados* arreglo;
	int Colisiones;
public:
	Controladora() {
		Colisiones = 0;
		arreglo = new Vector_Cuadrados();
		AgregarCuadrados();
	}
	void Dibujar_Lineas(Graphics^ L) {
		L->DrawLine(Pens::AliceBlue, 30, 10, 30, 530);
		L->DrawLine(Pens::AliceBlue, 30, 530, 700, 530);
	}
	void AgregarCuadrados() {
		arreglo->AgregarCuadrado(70, 530 - 35, 30, 30,40,2,1);
		arreglo->AgregarCuadrado(120, 530 - 125, 120, 120,200,-2,2);
	}
	void DibujarCuadrados(Graphics^ L) {
		arreglo->Draw_Scuare(L);
	}
	void Mover_Cuadrado() {
		arreglo->MoverCuadrado();
	}
	void ShowNColision(Graphics^L) {
		L->DrawString(gcnew String("N Colisiones "  +"\n" + "     "+ Colisiones),
			gcnew System::Drawing::Font("Cascadia Code", 15), Brushes::Blue,250,150);
	}
	void Colision() {
		Rectangle r1 = Rectangle(arreglo->getCuadrado(0)->getX(), arreglo->getCuadrado(0)->getY(),
			 arreglo->getCuadrado(0)->getAncho(), arreglo->getCuadrado(0)->getAlto());
		Rectangle r2 = Rectangle(arreglo->getCuadrado(1)->getX(), arreglo->getCuadrado(1)->getY(),
			arreglo->getCuadrado(1)->getAncho(), arreglo->getCuadrado(1)->getAlto());
		//if (r1.IntersectsWith(r2)) {
		//	arreglo->getCuadrado(0)->setDireccion(arreglo->getCuadrado(0)->getDireccion() *-1);
		//	arreglo->getCuadrado(1)->setDireccion(arreglo->getCuadrado(0)->getDireccion() *-1);
		//	Colisiones++;
		//}
		if (r1.IntersectsWith(r2)) {
			if (arreglo->getCuadrado(0)->getFuerza() < arreglo->getCuadrado(1)->getFuerza()) {
				if (arreglo->getCuadrado(0)->getDireccion() > 0) {
					arreglo->getCuadrado(0)->setX(arreglo->getCuadrado(0)->getX() - num_aumento);
					arreglo->getCuadrado(0)->setFuerza(arreglo->getCuadrado(0)->getFuerza() + 1);
					arreglo->getCuadrado(0)->setDireccion(arreglo->getCuadrado(0)->getDireccion() *-1);
				}
				else if (arreglo->getCuadrado(0)->getDireccion() < 0) {
					arreglo->getCuadrado(0)->setX(arreglo->getCuadrado(0)->getX() + num_aumento);
					arreglo->getCuadrado(0)->setFuerza(arreglo->getCuadrado(0)->getFuerza() + 1);
					arreglo->getCuadrado(0)->setDireccion(arreglo->getCuadrado(0)->getDireccion() *-1);
				}
				Colisiones++;
			}
			else if (arreglo->getCuadrado(0)->getFuerza() > arreglo->getCuadrado(1)->getFuerza()) {
				arreglo->getCuadrado(1)->setDireccion(arreglo->getCuadrado(0)->getDireccion() *-1);
				arreglo->getCuadrado(0)->setDireccion(arreglo->getCuadrado(0)->getDireccion() *-1);
				Colisiones++;
			}
		}

	}

};