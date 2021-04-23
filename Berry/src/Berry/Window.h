#pragma once

#include "Core.h"
#include "Events/Event.h"

#include <string>
#include <functional>

namespace Berry
{
	struct WindowProps
	{
		unsigned int Width;
		unsigned int Height;
		std::string Title;

		WindowProps(unsigned int width = 1024, unsigned int height = 640, const std::string& title = "Berry Engine")
			: Width(width), Height(height), Title(title)
		{
		}
	};

	class BERRY_API Window
	{
	public:
		using EventCallbackFunc = std::function<void(Event&)>;

		virtual ~Window() = default;

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		virtual void SetEventCallbackFunction(const EventCallbackFunc& eventCallbackFunc) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());
	};
}