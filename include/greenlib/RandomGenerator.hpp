#pragma once

#include <random>
#include <limits>

namespace grn
{
	template <typename Output, typename Distribution>
	class RandomGenerator
	{
	private:
		std::mt19937 generator;
		Distribution distribution;

	public:
		RandomGenerator() :
			generator(std::random_device()()),
			distribution(std::numeric_limits<Output>::min(), std::numeric_limits<Output>::max())
		{
		}

		RandomGenerator(Output minimum, Output maximum) :
			generator(std::random_device()()),
			distribution(minimum, maximum)
		{
		}

		RandomGenerator(Output seed) :
			generator(seed),
			distribution(std::numeric_limits<Output>::min(), std::numeric_limits<Output>::max())
		{
		}

		RandomGenerator(Output minimum, Output maximum, Output seed) :
			generator(seed),
			distribution(minimum, maximum)
		{
		}

		void InitializeDistribution()
		{
			distribution = Distribution(std::numeric_limits<Output>::min(), std::numeric_limits<Output>::max());
		}

		void InitializeDistribution(Output minimum, Output maximum)
		{
			distribution = Distribution(minimum, maximum);
		}

		Output Generate()
		{
			return distribution(generator);
		}

		Output operator()()
		{
			return distribution(generator);
		}
	};

	typedef RandomGenerator<int, std::uniform_int_distribution<int>> RandomGenerator_Int;
	typedef RandomGenerator<long, std::uniform_int_distribution<long>> RandomGenerator_Long;
	typedef RandomGenerator<long long, std::uniform_int_distribution<long long>> RandomGenerator_LongLong;
	typedef RandomGenerator<float, std::uniform_real_distribution<float>> RandomGenerator_Float;
	typedef RandomGenerator<double, std::uniform_real_distribution<double>> RandomGenerator_Double;
}
