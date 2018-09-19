#include "Pila.h"

Pila::Pila() {

	
	for (int i = 0; i < 100; i++)
		pila[i] = "";

	contador = -1;
}

Pila::~Pila() {}

void Pila::Push(string c) {

	if (!isEmpty()) {

		pila[contador+1] = c;
	}
	else
		pila[contador+1] = c;
	contador++;
}

string Pila::Pop() {

	if (contador>-1) {
		contador--;
		return (pila[contador+1]);
	}
	return "";

}

string Pila::Top() {

	if (!isEmpty()) {

		return pila[contador];
	}
	return "";

}

bool Pila::isEmpty() {

	return (contador == -1);
}

string Pila::toString() {
	stringstream s;
	for (int i = -1; i < contador; i++) {
		s << pila[i + 1]<<",";
	}
	return s.str();
}
