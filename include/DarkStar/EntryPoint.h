#pragma once

extern std::unique_ptr<DarkStar::CApplication> DarkStar::CreateApplication();

int main(int argc, char** argv)
{
	std::unique_ptr<DarkStar::CApplication> app = DarkStar::CreateApplication();
	app->Run();

	return 0;
}
