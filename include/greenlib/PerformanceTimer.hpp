#pragma once

#include <chrono>

namespace grn
{
	class PerformanceTimer
	{
	private:
		std::chrono::time_point<std::chrono::high_resolution_clock> startTimePoint;

	public:
		PerformanceTimer() : startTimePoint(std::chrono::high_resolution_clock::now())
		{
		}

		void Restart()
		{
			startTimePoint = std::chrono::high_resolution_clock::now();
		}

		double ElapsedSeconds() const
		{
			using namespace std::chrono;
			return duration_cast<nanoseconds>(high_resolution_clock::now() - startTimePoint).count() * (nanoseconds::period::num / double(nanoseconds::period::den));
		}

		long long ElapsedNanoseconds() const
		{
			using namespace std::chrono;
			return duration_cast<nanoseconds>(high_resolution_clock::now() - startTimePoint).count();
		}
	};
}
