#include "greenlib/TimePoint.hpp"
#include "greenlib/TimeDuration.hpp"
#include "greenlib/TimeSpan.hpp"

int main()
{
	using namespace grn;
	
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
	bool startOfNextWeekContainedInThisWeek = nextWeek.Contains(point0 + TimeDuration::Days(7));
}
