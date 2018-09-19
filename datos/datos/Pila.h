#pragma once
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string>
using namespace std;

class Pila {

	string pila[100];
	int contador;

public:
	Pila();
	~Pila();

	void Push(string);
	string Pop();
	string Top();
	bool isEmpty();

	string toString(); // este mnetodo no debe existir solo es para revisar las operaciones
};
