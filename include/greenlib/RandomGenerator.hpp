#pragma once

#include <random>
#include <limits>
#include <cstdint>

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

	using RandomGeneratorInt = RandomGenerator<int, std::uniform_int_distribution<int>>;
	using RandomGeneratorInt32 = RandomGenerator<std::int32_t, std::uniform_int_distribution<std::int32_t>>;
	using RandomGeneratorInt64 = RandomGenerator<std::int64_t, std::uniform_int_distribution<std::int64_t>>;
	using RandomGeneratorFloat = RandomGenerator<float, std::uniform_real_distribution<float>>;
	using RandomGeneratorDouble = RandomGenerator<double, std::uniform_real_distribution<double>>;
}
