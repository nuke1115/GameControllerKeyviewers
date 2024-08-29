#ifndef CALCULATION_UTILITY_HEADER
#define CALCULATION_UTILITY_HEADER
#include "..\headers\Containers.hpp"

class CalculationUtility
{
public:
    inline unsigned long long GetSum(const unsigned int counts[])
    {
        return counts[0] + counts[1] + counts[2] + counts[3] + counts[4] + counts[5];
    }
};

#endif // !CALCULATION_UTILITY_HEADER