#pragma once

#include "Event.h"

namespace Berry
{
	class BERRY_API MouseButtonEvent : public Event
	{
	public:
		inline int GetMouseCode() const { return m_MouseCode; }

		DEFINE_EVENT_CATEGORY(EventCategoryInput | EventCategoryMouse)
	protected:
		MouseButtonEvent(int mousecode)
			: m_MouseCode(mousecode)
		{
		}

		int m_MouseCode;
	};

	class BERRY_API MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int mousecode)
			: MouseButtonEvent(mousecode)
		{
		}

		virtual std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << m_MouseCode;
			return ss.str();
		}

		DEFINE_EVENT_TYPE(MouseButtonPressed)
	};

	class BERRY_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int mousecode)
			: MouseButtonEvent(mousecode)
		{
		}

		virtual std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << m_MouseCode;
			return ss.str();
		}

		DEFINE_EVENT_TYPE(MouseButtonReleased)
	};

	class BERRY_API MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(float mouseX, float mouseY)
			: m_MouseX(mouseX), m_MouseY(mouseY)
		{
		}

		inline float GetX() const { return m_MouseX; }
		inline float GetY() const { return m_MouseY; }

		virtual std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent: " << m_MouseX << ", " << m_MouseY;
			return ss.str();
		}

		DEFINE_EVENT_TYPE(MouseMoved)
		DEFINE_EVENT_CATEGORY(EventCategoryInput | EventCategoryMouse)
	private:
		float m_MouseX, m_MouseY;
	};

	class BERRY_API MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(float scrollX, float scrollY)
			: m_ScrollX(scrollX), m_ScrollY(scrollY)
		{
		}

		inline float GetScrollX() const { return m_ScrollX; }
		inline float GetScrollY() const { return m_ScrollY; }

		virtual std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << m_ScrollX << ", " << m_ScrollY;
			return ss.str();
		}

		DEFINE_EVENT_TYPE(MouseScrolled)
		DEFINE_EVENT_CATEGORY(EventCategoryInput | EventCategoryMouse)
	private:
		float m_ScrollX, m_ScrollY;
	};
}