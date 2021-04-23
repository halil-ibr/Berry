#pragma once

#include "Berry/Window.h"

#include <GLFW/glfw3.h>

namespace Berry
{
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		inline virtual unsigned int GetWidth() const override { return m_Data.Width; }
		inline virtual unsigned int GetHeight() const override { return m_Data.Height; }

		inline virtual void SetEventCallbackFunction(const EventCallbackFunc& eventCallbackFunc) override { m_Data.EventCallback = eventCallbackFunc; }
		virtual void SetVSync(bool enabled) override;
		virtual bool IsVSync() const override;
	private:
		void Init(const WindowProps& props);
		void Shutdown();
	private:
		GLFWwindow* m_Window;

		struct WindowData
		{
			std::string Title;
			unsigned int Width;
			unsigned int Height;
			bool VSync;

			EventCallbackFunc EventCallback;
		};

		WindowData m_Data;
	};
}