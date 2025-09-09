#pragma once

extern DarkStar::Application* DarkStar::CreateApplication();

int main(int argc, char** argv)
{
	DarkStar::Application* app = DarkStar::CreateApplication();
	app->Run();
	delete app;

	return 0;
}
