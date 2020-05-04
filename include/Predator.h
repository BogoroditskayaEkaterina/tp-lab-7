#pragma once
#include "Object.h"
#include "Prey.h"

class Predator : public Prey {
private:	
	int fullness = 60; //�������, ������ ���� - �����, ������ ���� - �������
public:
	Predator();
	void breed();
	void hunt();
	void live() override;
}; 