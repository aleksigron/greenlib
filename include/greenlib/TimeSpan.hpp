#pragma once

#include "TimePoint.hpp"
#include "TimeDuration.hpp"

namespace grn
{
	class TimeSpan
	{
	private:
		TimePoint start;
		TimeDuration duration;

	public:
		TimeSpan() = default;
		TimeSpan(const TimePoint& start, const TimeDuration& duration) : start(start), duration(duration) {}
		TimeSpan(const TimePoint& start, const TimePoint& end) : start(start), duration(end - start) {}

		bool Contains(const TimePoint& timePoint)
		{
			return timePoint >= start && timePoint < start + duration;
		}
	};
}
