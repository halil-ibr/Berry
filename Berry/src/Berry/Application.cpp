#include "brpch.h"
#include "Application.h"

#include "Berry/Events/WindowEvent.h"
#include "Berry/Log.h"

namespace Berry
{
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		while (m_Running)
		{
			m_Window->OnUpdate();
		}
	}
}