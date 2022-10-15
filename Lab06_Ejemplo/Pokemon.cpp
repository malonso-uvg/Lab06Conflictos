#include "Pokemon.h"

String^ Pokemon::getName() {
	return name;
}

String^ Pokemon::getGeneration() {
	return this->generation;
}

String^ Pokemon::getType() {
	return tipo;
}

void Pokemon::setName(String^ _name) {
	this->name = _name;
}

void Pokemon::setGeneration(String^ _generation) {
	this->generation = _generation;
}

void Pokemon::setType(String^ _type) {
	this->tipo = _type;
}