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
 * Modify by Diego J. Bodas Sagi
 * Evolutionary Algorithms with JMetal and R
 * November 2014
 * Madrid, Spain
 * First version
 */

#ifndef __RPROBLEM__
#define __RPROBLEM__

#include "Problem.h"
#include <math.h>
#include "BinaryRealSolutionType.h"
#include "RealSolutionType.h"
#include "ArrayRealSolutionType.h"
#include "XReal.h"
#include "Solution.h"

#include <Rcpp.h>
/**
 * Class representing problem Kursawe
 */
class RProblem : public Problem {

public:
	Rcpp::Function f_;
	RProblem(string solutionType, int numberOfVariables, Rcpp::Function f);
	~RProblem();
	void evaluate(Solution *solution);
};

#endif
