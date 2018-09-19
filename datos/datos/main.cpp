#pragma once
#include <iostream>

using namespace std;
#include "calculadora.h"

int  main() {
	Calculadora* c = new Calculadora();
	//string dato;
	//cin >> dato;
	Cola*p=new Cola(100);
	p=c->pasarAPostfija("(34--2)+(21/-7)");
	cout << p->toString()<<endl;
	cout<<c->resuelveOperacion(p);
	system("pause");
	return 0;
}