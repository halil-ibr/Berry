#pragma once

#include "Event.h"

namespace Berry
{
	class BERRY_API AppUpdateEvent : public Event
	{
	public:
		AppUpdateEvent() = default;

		DEFINE_EVENT_TYPE(AppUpdate)
		DEFINE_EVENT_CATEGORY(EventCategoryApplication)
	};

	class BERRY_API AppTickEvent : public Event
	{
	public:
		AppTickEvent() = default;

		DEFINE_EVENT_TYPE(AppTick)
		DEFINE_EVENT_CATEGORY(EventCategoryApplication)
	};

	class BERRY_API AppRenderEvent : public Event
	{
	public:
		AppRenderEvent() = default;

		DEFINE_EVENT_TYPE(AppRender)
		DEFINE_EVENT_CATEGORY(EventCategoryApplication)
	};
}