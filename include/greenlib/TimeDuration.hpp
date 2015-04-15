#pragma once

#include <cstdint>

namespace grn
{
	class TimeDuration
	{
	private:
		std::int64_t durationSeconds;

		friend class TimePoint;

	public:
		TimeDuration() : durationSeconds(0) {}
		TimeDuration(std::int64_t durationSeconds) : durationSeconds(durationSeconds) {}

		static TimeDuration Seconds(std::int64_t durationSeconds)
		{
			return TimeDuration(durationSeconds);
		}

		static TimeDuration Minutes(std::int64_t durationMinutes)
		{
			return TimeDuration(durationMinutes * 60);
		}

		static TimeDuration Hours(std::int64_t durationHours)
		{
			return TimeDuration(durationHours * 3600);
		}

		static TimeDuration Days(std::int64_t durationDays)
		{
			return TimeDuration(durationDays * 86400);
		}

		TimeDuration operator+(const TimeDuration& rhs) const
		{
			return TimeDuration(this->durationSeconds + rhs.durationSeconds);
		}

		TimeDuration operator-(const TimeDuration& rhs) const
		{
			return TimeDuration(this->durationSeconds - rhs.durationSeconds);
		}
	};
}
