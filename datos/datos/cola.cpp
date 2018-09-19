#include "cola.h"

Cola::Cola(int n) {
	vec = new string[n];
	rpos = n;
	spos = 0;
	max = n;
}
Cola::~Cola() {
	delete[]vec;
}
bool Cola::enqueue(string elemento) {
	if (rpos == max && spos == 0) {
		vec[spos] = elemento;
		spos = (spos + 1) % max;
		rpos = 0;

	}
	else {
		if ((spos + 1) % max != rpos) {
			vec[spos] = elemento;
			spos = (spos + 1) % max;
			return true;
		}
	}
	return false;
}
string Cola::dequeue() {
	string elemento = "";
	if ((rpos + 1) % max != (spos + 1) % max) {
		elemento = vec[rpos%max];
		rpos = (rpos + 1) % max;
	}
	return elemento;
}
bool Cola::empty() {
	if (spos == 0 && rpos == max)
		return true;
	if (rpos == spos)
		return true;
	return false;
}

//necesario saber sis la pila tiene elementos
string Cola::front() {
	return vec[rpos];
}

string Cola::toString() {
	stringstream s;
	for (int i = rpos; i < spos; i++) {
		s << vec[i] << ",";
	}
	return s.str();
}