#pragma once

#include "object.h"

class Stone : public Object 
{
public:

	Stone();
	void live() override;
};
