/*
 * Modify by Diego J. Bodas Sagi
 * Evolutionary Algorithms with JMetal and R
 * September 2013
 * Madrid, Spain
 * First version
 */

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

#ifndef __RKURSAWE__
#define __RKURSAWE__

#include "Problem.h"
#include <math.h>
#include "BinaryRealSolutionType.h"
#include "RealSolutionType.h"
#include "ArrayRealSolutionType.h"
#include "XReal.h"
#include "Solution.h"

#include <RInside.h>

/**
 * Class representing problem Kursawe
 */
class RKursawe : public Problem {

public:
	RInside & R_;
	RKursawe(string solutionType, int numberOfVariables, RInside & R);
	~RKursawe();
	void evaluate(Solution *solution);
	std::vector<double> evaluateParallel(std::vector<double> x);
	std::vector<double> dynamicArrayToVector(double * x, int sizeOfx);
};

#endif
