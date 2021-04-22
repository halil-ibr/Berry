#include "brpch.h"
#include "Application.h"

#include "Berry/Events/WindowEvent.h"
#include "Berry/Log.h"

namespace Berry
{
	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowMovedEvent e(100, 100);
		BR_CORE_INFO(e);

		while (true);
	}
}