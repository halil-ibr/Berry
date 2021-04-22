#pragma once

#ifdef BR_PLATFORM_WINDOWS

extern Berry::Application* Berry::CreateApplication();

int main(int argc, char** argv)
{
	Berry::Log::Init();

	auto app = Berry::CreateApplication();
	app->Run();
	delete app;
}

#endif
