#pragma once

#include "Event.h"

namespace Berry
{
	class BERRY_API WindowResizedEvent : public Event
	{
	public:
		WindowResizedEvent(int width, int height)
			: m_Width(width), m_Height(height)
		{
		}

		virtual std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowResizedEvent: " << m_Width << ", " << m_Height;
			return ss.str();
		}

		DEFINE_EVENT_TYPE(WindowResized)
		DEFINE_EVENT_CATEGORY(EventCategoryWindow)
	private:
		int m_Width, m_Height;
	};

	class BERRY_API WindowMovedEvent : public Event
	{
	public:
		WindowMovedEvent(int windowX, int windowY)
			: m_WindowX(windowX), m_WindowY(windowY)
		{
		}

		virtual std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowMovedEvent: " << m_WindowX << ", " << m_WindowY;
			return ss.str();
		}

		DEFINE_EVENT_TYPE(WindowMoved)
		DEFINE_EVENT_CATEGORY(EventCategoryWindow)
	private:
		int m_WindowX, m_WindowY;
	};

	class BERRY_API WindowClosedEvent : public Event
	{
	public:
		WindowClosedEvent() = default;

		DEFINE_EVENT_TYPE(WindowClosed)
		DEFINE_EVENT_CATEGORY(EventCategoryWindow)
	};

	class BERRY_API WindowFocusedEvent : public Event
	{
	public:
		WindowFocusedEvent() = default;

		DEFINE_EVENT_TYPE(WindowFocused)
		DEFINE_EVENT_CATEGORY(EventCategoryWindow)
	};

	class BERRY_API WindowLostFocusedEvent : public Event
	{
	public:
		WindowLostFocusedEvent() = default;

		DEFINE_EVENT_TYPE(WindowLostFocused)
		DEFINE_EVENT_CATEGORY(EventCategoryWindow)
	};
}