/*
 * NSGAII_main.h
 *
 *  Created on: 16/08/2013
 *      Author: Diego
 */

#ifndef NSGAII_MAIN_H_
#define NSGAII_MAIN_H_

#include "Problem.h"
#include "Solution.h"
#include "SBXCrossover.h"
#include "PolynomialMutation.h"
#include "BinaryTournament2.h"
#include <iostream>
#include "NSGAII.h"
#include "ProblemFactory.h"
#include <string.h>
#include <time.h>

#include <RInside.h>


/**
 * Class implementing the NSGA-II algorithm.
 * This implementation of NSGA-II makes use of a QualityIndicator object
 *  to obtained the convergence speed of the algorithm. This version is used
 *  in the paper:
 *     A.J. Nebro, J.J. Durillo, C.A. Coello Coello, F. Luna, E. Alba
 *     "A Study of Convergence Speed in Multi-Objective Metaheuristics."
 *     To be presented in: PPSN'08. Dortmund. September 2008.
 *
 *   Besides the classic NSGA-II, a steady-state version (ssNSGAII) is also
 *   included (See: J.J. Durillo, A.J. Nebro, F. Luna and E. Alba
 *                  "On the Effect of the Steady-State Selection Scheme in
 *                  Multi-Objective Genetic Algorithms"
 *                  5th International Conference, EMO 2009, pp: 183-197.
 *                  April 2009)
 */

//Declare extern the NSGAII_main class for share R session without any problem
//in future versions of this program we'll try to avoid global objects.
class NSGAII_main {
	public:
		RInside & R_;		// reference to embedded R instance
		NSGAII_main(RInside & R);
};




#endif /* NSGAII_MAIN_H_ */
