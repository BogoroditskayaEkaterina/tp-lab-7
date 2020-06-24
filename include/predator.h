#pragma once
#include "object.h"
#include "prey.h"

class Predator : public Prey 
{
private:

	int fullness;

public:

	Predator();
	void hunt();
	void live() override;
};