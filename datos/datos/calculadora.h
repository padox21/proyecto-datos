#pragma once
#include <iostream>
#include "Pila.h"
#include "cola.h"
#include <string.h>

class Calculadora {
public:
	bool esOperador(string);// el metodo dice si es un operando se trabaja con strings para que sea mas
							// facil sientoq que trabajarlos solo con char y asi poder trabajar los digitos completos

	int prioridad(string); // siento que es mas facil asignarle a cada operador un numero de prioriodad
							// para asi comprararlos

	Cola* pasarAPostfija(string);

	string resuelveOperacion(Cola*);
};