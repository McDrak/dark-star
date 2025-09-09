#include "DarkStar.h"

class Test : public DarkStar::Application
{
public:
	Test() = default;
	~Test() override = default;
};

DarkStar::Application* DarkStar::CreateApplication()
{
	return new Test();
}