#include "DarkStar.h"

class Test : public DarkStar::CApplication
{
public:
	explicit Test(const DarkStar::SApplicationConfiguration& configuration)
		: CApplication(configuration)
	{
	}

	~Test() override = default;
};

std::unique_ptr<DarkStar::CApplication> DarkStar::CreateApplication()
{
	const SApplicationConfiguration configuration("Test App", 800, 600);
	return std::make_unique<Test>(configuration);
}