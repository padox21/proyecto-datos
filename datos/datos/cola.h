#pragma once
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string>

using namespace std;

class Cola{
private:
	string* vec;	//vector
	int rpos;//front
	int spos;//back
	int max;	//tamanno del vector
public:
	Cola(int);
	~Cola();
	bool enqueue(string);
	string dequeue();
	bool empty();
	string front();

	string toString();
};
