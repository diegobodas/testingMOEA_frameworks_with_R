//  testMACDserial.h
//	Author:
//		 Diego J. Bodas Sagi (based on JMetal Tutorial)
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU Lesser General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.

/*
 * Find the best parameters for MACD. Compare SMA with EMA.
 * Serial version
 */
//checks if a unique value is defined/included
#ifndef __TESTMACDSERIAL__
#define __TESTMACDSERIAL__

#include "Problem.h"
#include <math.h>
#include <algorithm>
//JMetalcpp V 1.0 has no included an IntegerSolutionType
#include "BinaryRealSolutionType.h"
#include "RealSolutionType.h"
#include "ArrayRealSolutionType.h"
#include "XReal.h"
#include "Solution.h"

#include <RInside.h>

/**
 * Class representing problem testMACDserial
 */
class testMACDserial : public Problem {

public:
	RInside & R_;
	testMACDserial(string solutionType, int numberOfVariables, RInside & R);
	~testMACDserial();
	void evaluate(Solution *solution);
	std::vector<int> findFast(int * x, int sizeOfx);
};

#endif
