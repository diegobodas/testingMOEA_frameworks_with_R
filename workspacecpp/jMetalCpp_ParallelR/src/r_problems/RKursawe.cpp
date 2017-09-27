//  Kursawe.cpp
//
//  Authors:
//       Antonio J. Nebro <antonio@lcc.uma.es>
//       Juan J. Durillo <durillo@lcc.uma.es>
//       Esteban L�pez <esteban@lcc.uma.es>
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

/*
 * Modify by Diego J. Bodas Sagi
 * Evolutionary Algorithms with JMetal and R
 * September 2013
 * Madrid, Spain
 * First version
 */
#include "RKursawe.h"


/**
 * @class Kursawe
 * @brief Class representing the problem Kursawe (With R)
 **/

/**
 * Constructor.
 * Creates a new instance of the Kursawe problem.
 * @param numberOfVariables Number of variables of the problem
 * @param solutionType The solution type must "Real", "BinaryReal, and "ArrayReal".
 */
RKursawe::RKursawe(string solutionType, int numberOfVariables, RInside & R):R_(R) {

  numberOfVariables_   = numberOfVariables;
  numberOfObjectives_  = 2;
  numberOfConstraints_ = 0;
  problemName_         = "RKursawe";

  lowerLimit_ = new double[numberOfVariables_];
  if (lowerLimit_ == NULL) {
    cout << "Impossible to reserve memory for storing the variable lower limits" << endl;
    exit(-1);
  }

  upperLimit_ = new double[numberOfVariables_];
  if (upperLimit_ == NULL) {
    cout << "Impossible to reserve memory for storing the variable lower limits" << endl;
    exit(-1);
  }

  for (int i = 0; i < numberOfVariables_; i++) {
    lowerLimit_[i] = -5.0;
    upperLimit_[i] =  5.0;
  }

  if (solutionType.compare("BinaryReal") == 0)
    solutionType_ = new BinaryRealSolutionType(this) ;
  else if (solutionType.compare("Real") == 0) {
    solutionType_ = new RealSolutionType(this) ;
    cout << "Selected type= Real" << endl;
  }
  else if (solutionType.compare("ArrayReal") == 0)
    solutionType_ = new ArrayRealSolutionType(this) ;
  else {
    cout << "Error: solution type " << solutionType << " invalid" << endl;
    exit(-1) ;
  }

} // Kursawe


/**
 * Destructor
 */
RKursawe::~RKursawe() {
  delete [] lowerLimit_ ;
  delete [] upperLimit_ ;
  delete solutionType_ ;
} // ~Kursawe


/**
 * Evaluates a solution
 * @param solution The solution to evaluate
 */
void RKursawe::evaluate(Solution *solution) {

  XReal * vars = new XReal(solution);
  std::vector<double> xVector (numberOfVariables_);
  std::vector<double> result;

  double * fx = new double[2];                 // function values
  if (fx == NULL) {
    cout << "Error grave: Impossible to reserve memory while evaluating the problem" << endl;
    exit(-1);
  }

  //Get individual to evaluate
  for (int i=0; i<numberOfVariables_; i++){
	  xVector[i]=vars->getValue(i);
  }

  //Try to evaluate objectives in R
  try {
	  R_.assign(xVector,"x");
	  std::string txt;
	  txt = "result<- clusterApply(cluster, 1:2, kursaweManager, x);"
			"result <- c(result[[1]], result[[2]])";
	  R_.parseEvalQ(txt);
	  result = R_["result"];

 } catch(std::exception& ex) {
	 std::cerr << "Exception caught: " << ex.what() << std::endl;
	 exit (-1);
	} catch(...) {
		std::cerr << "Unknown exception caught" << std::endl;
		exit(-1);
	}
  solution->setObjective(0,result[0]);
  solution->setObjective(1,result[1]);

  //vector class has a destructor, called when variable is out of scope
  delete vars;

} // evaluate

