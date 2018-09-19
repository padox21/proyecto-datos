#include "calculadora.h"

bool Calculadora::esOperador(string dato) {
	if (dato == "+" || dato == "-" || dato == "*" || dato == "/" || dato == "(" || dato == ")" 
		|| dato == "^")
		return true;
	return false;

}
int Calculadora::prioridad(string dato) {
	if (dato == "+" || dato == "-") {
		return 2;
	}
	if (dato == "*" || dato == "/") {
		return 3;
	}
	if (dato == "^") {
		return 4;
	}
	return 0;
}


Cola* Calculadora::pasarAPostfija(string infija) {
	Cola* result = new Cola(100);
	Pila*operadores = new Pila();
	string e;
	int contador = 0;
	while (contador<infija.size())
	{

		e = infija[contador];
		switch (esOperador(e))
		{
		case true://cuando es un operador
			if (e == "(") {
				operadores->Push(e);//agrega ese parentesis a la pila de operadores
			}
			else {
				if (e == ")") {
					while (operadores->Top() != "(") {
						result->enqueue(operadores->Pop());
					}
					operadores->Pop();
				}
				else {
					while (prioridad(e) <= prioridad(operadores->Top())) {
						result->enqueue(operadores->Pop());
					}
					operadores->Push(e);
				}
			}
			contador++;
			break;
		case false: // cuando no es un operador
			int contador2 = contador;
			stringstream s;
			s << e;
			while (++contador2 < infija.length())// este metodo es que que ayuda a recorrer datos los datos hasta que sea un operador
			{
				e = infija[contador2];
				if (esOperador(e))
				{
					contador = contador2-1;
					contador2 = infija.length();
				}
				else {
					s << e;
					contador++;
				}
			}
			e = s.str();
			result->enqueue(e);
			contador++;
			break;
		}
	}
	while (!(operadores->isEmpty())) {
		result->enqueue(operadores->Pop());
	}
	return result;
}

string Calculadora::resuelveOperacion(Cola*expresion)
{
	Pila p;
	string dato;
	int dato1, dato2;
	int result;
	stringstream s;
	while (!(expresion->empty()))
	{
		dato = expresion->dequeue();
		switch (esOperador(dato)){
		case true:
			if (p.isEmpty()) {
				dato1 = 0;
			}
			else {
				dato1 = atoi(p.Pop().c_str());
			}
			if (p.isEmpty()) {
				dato2 = 0;
			}
			else {
				dato2 = atoi(p.Pop().c_str());
			}
			try
			{
				switch (dato[0])
				{
				case '+':
					result = dato2 + dato1;
					break;
				case '-':
					result = dato2 - dato1;
					break;
				case '*':
					result = dato2 * dato1;
					break;
				case '/':
					result = dato2 / dato1;
					break;
				case '^':
					result = pow(dato2, dato1);
					break;
				}
			}
			catch (exception e)
			{
				cout << "no se puede realizar la operacion";
			}
			p.Push(std::to_string(result));
			break;

		case false:
			p.Push(dato);
			break;
		}
	}
	return p.Top();
}
