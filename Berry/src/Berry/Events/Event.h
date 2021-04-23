#pragma once

#include "Berry/Core.h"

#include <string>
#include <sstream>

namespace Berry
{
	enum class EventType
	{
		None = 0,
		WindowClosed, WindowResized, WindowFocused, WindowLostFocused, WindowMoved,
		AppUpdate, AppTick, AppRender,
		KeyPressed, KeyReleased, KeyTyped,
		MouseMoved, MouseButtonPressed, MouseButtonReleased, MouseScrolled
	};

	enum EventCategory
	{
		None = 0,
		EventCategoryApplication = BIT(1),
		EventCategoryWindow		 = BIT(2),
		EventCategoryInput		 = BIT(3),
		EventCategoryKeyboard	 = BIT(4),
		EventCategoryMouse		 = BIT(5)
	};

#define DEFINE_EVENT_TYPE(type) static EventType GetStaticType() { return EventType::type; }				\
								virtual EventType GetEventType() const override { return EventType::type; } \
								virtual const char* GetName() const override { return #type; }

#define DEFINE_EVENT_CATEGORY(categories) virtual int GetEventCategories() const override { return categories; }

	class BERRY_API Event
	{
	public:
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual std::string ToString() const { return GetName(); }

		virtual int GetEventCategories() const = 0;

		// TODO: This function looks garbage
		inline bool IsInCategory(EventCategory category)
		{
			return category & GetEventCategories();
		}

		// TODO: Remove Handled variable
		bool Handled = false;
	};

	class BERRY_API EventDispatcher
	{
	public:
		EventDispatcher(Event& e)
			: m_Event(e)
		{
		}

		template<typename T, typename Func>
		bool Dispatch(const Func& func)
		{
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				m_Event.Handled = func(static_cast<T&>(m_Event));
				return true;
			}
			return false;
		}

	private:
		Event& m_Event;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}
}