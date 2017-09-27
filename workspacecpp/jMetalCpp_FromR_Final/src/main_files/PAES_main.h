/*
 * Modify by Diego J. Bodas Sagi
 * Evolutionary Algorithms with JMetal and R
 * November 2014
 * Madrid, Spain
 * First version
 */

#ifndef PAES_MAIN_H_
#define PAES_MAIN_H_

#include <Problem.h>
#include <Algorithm.h>
#include <Operator.h>
#include <Solution.h>
#include <RealSolutionType.h>
#include <PolynomialMutation.h>
#include <ProblemFactory.h>
#include <iostream>
#include <paes.h>
#include <time.h>

#include <Rcpp.h>


//  PAES_main.cpp
//
//  Author:
//       Cristian Zambrano <cristian_uteq@hotmail.com>
//
//  Copyright (c) 2011 Antonio J. Nebro, Juan J. Durillo
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
//Declare extern the NSGAII_main class for share R session without any problem
//in future versions of this program we'll try to avoid global objects.

/*
 * Modify by Diego J. Bodas Sagi
 * Evolutionary Algorithms with JMetal and R
 * November 2014
 * Madrid, Spain
 * First version
 */

class PAES_main {
	public:
		Rcpp::Function f_;
		PAES_main(int evaluations, int archiveSize, int biSectionsVal, double DistIndex, Rcpp::Function f);
};




#endif /* NSGAII_MAIN_H_ */
