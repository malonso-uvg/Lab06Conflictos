#pragma once

using namespace System;

ref class Pokemon
{
private:
	//ESta es un comentario de conflicto
	String^ name;
	String^ generation;
	String^ tipo;

public:
	String^ getName();
	String^ getGeneration();
	String^ getType();
	void setName(String^ _name);
	void setGeneration(String^ _generation);
	void setType(String^ _type);


};

