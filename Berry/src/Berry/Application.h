#pragma once

#include "Core.h"

namespace Berry
{
	class BR_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in client
	Application* CreateApplication();
}