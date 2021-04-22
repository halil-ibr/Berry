#pragma once

#include "Event.h"

namespace Berry
{
	class BERRY_API KeyEvent : public Event
	{
	public:
		inline int GetKeyCode() const { return m_KeyCode; }

		DEFINE_EVENT_CATEGORY(EventCategoryInput | EventCategoryKeyboard)
	protected:
		KeyEvent(int keycode)
			: m_KeyCode(keycode)
		{
		}

		int m_KeyCode;
	};

	class BERRY_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int button)
			: KeyEvent(button)
		{
		}

		virtual std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_KeyCode;
			return ss.str();
		}

		DEFINE_EVENT_TYPE(KeyPressed)
	};

	class BERRY_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int button)
			: KeyEvent(button)
		{
		}

		virtual std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << m_KeyCode;
			return ss.str();
		}

		DEFINE_EVENT_TYPE(KeyReleased)
	};

	class BERRY_API KeyTypedEvent : public KeyEvent
	{
	public:
		KeyTypedEvent(int button)
			: KeyEvent(button)
		{
		}

		virtual std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyTypedEvent: " << m_KeyCode;
			return ss.str();
		}

		DEFINE_EVENT_TYPE(KeyReleased)
	};
}