#pragma once

#ifdef BR_PLATFORM_WINDOWS

extern Berry::Application* Berry::CreateApplication();

int main(int argc, char** argv)
{
	Berry::Log::Init();
	BR_CORE_WARN("It is a warn!");
	BR_INFO("VALUE: {}", 10);

	auto app = Berry::CreateApplication();
	app->Run();
	delete app;
}

#endif
