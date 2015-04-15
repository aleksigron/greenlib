#pragma once

#include <cstdint>

#include "TimeDuration.hpp"

namespace grn
{
	class TimePoint
	{
	private:
		std::uint64_t secondsSinceEpoch;

	public:
		TimePoint() : secondsSinceEpoch(0) {}
		explicit TimePoint(std::uint64_t secondsSinceEpoch) : secondsSinceEpoch(secondsSinceEpoch) {}
		
		std::uint64_t Uint64() const { return this->secondsSinceEpoch; }

		TimePoint& operator+=(const TimeDuration& rhs) { this->secondsSinceEpoch += rhs.durationSeconds; }
		TimePoint& operator-=(const TimeDuration& rhs) { this->secondsSinceEpoch -= rhs.durationSeconds; }

		TimePoint operator+(const TimeDuration& rhs) const { return TimePoint(this->secondsSinceEpoch + rhs.durationSeconds); }
		TimePoint operator-(const TimeDuration& rhs) const { return TimePoint(this->secondsSinceEpoch - rhs.durationSeconds); }

		TimeDuration operator-(const TimePoint& rhs) const { return TimeDuration(this->secondsSinceEpoch - rhs.secondsSinceEpoch); }

		bool operator==(const TimePoint& rhs) const { return this->secondsSinceEpoch == rhs.secondsSinceEpoch; }
		bool operator!=(const TimePoint& rhs) const { return this->operator==(rhs) == false; }
		
		bool operator<(const TimePoint& rhs) const { return this->secondsSinceEpoch < rhs.secondsSinceEpoch; }
		bool operator>(const TimePoint& rhs) const { return rhs.operator<(*this); }
		bool operator<=(const TimePoint& rhs) const { return rhs.operator<(*this) == false; }
		bool operator>=(const TimePoint& rhs) const { return this->operator<(rhs) == false; }
	};
}
