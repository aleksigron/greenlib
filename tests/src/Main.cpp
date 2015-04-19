#include <iostream>

#include "greenlib/TimePoint.hpp"
#include "greenlib/TimeDuration.hpp"
#include "greenlib/TimeSpan.hpp"

#include "greenlib/RandomGenerator.hpp"

#include "greenlib/PerformanceTimer.hpp"

int main()
{
	using namespace grn;

	PerformanceTimer timer;
	
	TimeDuration oneSec = TimeDuration::Seconds(1);
	TimeDuration oneMin = TimeDuration::Minutes(1);
	TimeDuration oneHour = TimeDuration::Hours(1);
	TimeDuration oneDay = TimeDuration::Days(1);

	TimePoint point0(1429131690);
	TimePoint theDayBefore = point0 - oneDay;
	TimePoint theDayAfter = point0 + oneDay;

	TimeSpan surroundingDays(theDayBefore, theDayAfter);
	bool containedInSurroundingDays = surroundingDays.Contains(point0);

	TimeSpan nextWeek(point0, TimeDuration::Days(7));
	bool thisWeekCointainsStartOfNextWeek = nextWeek.Contains(point0 + TimeDuration::Days(7));

	RandomGenerator_Int rng;
	rng.InitializeDistribution(0, 255);

	std::cout << "Random [0, 255]:\n";

	for (int i = 0; i < 128; ++i)
		std::cout << rng.Generate() << " ";
	
	std::cout << "\n";

	double elapsedTime = timer.ElapsedSeconds();
	long long elapsedNanoseconds = timer.ElapsedNanoseconds();

	std::cout << elapsedTime << " s, " << elapsedNanoseconds << " ns\n";

	char c;
	std::cin >> c;
}
