//  testMACD.cpp
/*
 * Author: Diego J. Bodas Sagi
 * Evolutionary Algorithms with JMetal and R
 * September 2013
 * Madrid, Spain
 * First version
 */
#include "testMACD.h"


/**
 * @class testMACD
 * @brief Class representing the problem MACD: SMA or EMA? (With R)
 **/

/**
 * Constructor.
 * Creates a new instance of the testMACD problem.
 * @param numberOfVariables Number of variables of the problem
 * @param solutionType The solution type must "Real", "BinaryReal, and "ArrayReal".
 */
testMACD::testMACD(string solutionType, int numberOfVariables, RInside & R):R_(R) {

  numberOfVariables_   = numberOfVariables;
  numberOfObjectives_  = 2;
  numberOfConstraints_ = 0;
  problemName_         = "testMACD";

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

} // testMACD


/**
 * Destructor
 */
testMACD::~testMACD() {
  delete [] lowerLimit_ ;
  delete [] upperLimit_ ;
  delete solutionType_ ;
} // ~testMACD


/**
 * Evaluates a solution
 * @param solution The solution to evaluate
 */
void testMACD::evaluate(Solution *solution) {

  XReal * vars = new XReal(solution);

  double aux, xi, xj;                          // auxiliary variables
  double * fx = new double[2];                 // function values
  if (fx == NULL) {
    cout << "Severe error: Impossible to reserve memory while evaluating the problem" << endl;
    exit(-1);
  }

  double * x = new double[numberOfVariables_];
  for (int i = 0 ; i < numberOfVariables_; i++) {
    x[i] = vars->getValue(i) ;
  }
  std::vector<double> xVector = dynamicArrayToVector(x, numberOfVariables_);

  fx[0] = 0.0;
  fx[1] = 0.0;

  //call to parallel execution
  std::vector<double> results = evaluateParallel (xVector);

  fx[0] = results[0];
  fx[1] = results[1];


  solution->setObjective(0,fx[0]);
  solution->setObjective(1,fx[1]);

  delete [] fx;
  delete [] x;
  delete vars;

} // evaluate

std::vector<double> testMACD::evaluateParallel(std::vector<double> x) {

	std::vector<double> results;		// vector of doubles
	results.push_back(0.0);
	results.push_back(0.0);

	try {
		R_.assign(x,"x");
		//Parallel evaluation
		std::string txt;
		txt = "result<- clusterApply(cluster, 1:2, kursaweManager, x)";
		//execute and get the results
		R_.parseEvalQ(txt);
		//format
		txt = "result <- c(result[[1]], result[[2]])";
		std::vector<double> getResults = Rcpp::as< std::vector< double > >(R_.parseEval(txt));

		return (getResults);


	 } catch(std::exception& ex) {
	        std::cerr << "Exception caught: " << ex.what() << std::endl;

	    } catch(...) {
	        std::cerr << "Unknown exception caught" << std::endl;

	    }
	std::cout<<"*** RESULTS TO 0. FAIL ***"<< std::endl;
	return (results);
}

std::vector<double> testMACD::dynamicArrayToVector(double * x, int sizeOfx){

	std::vector<double> toVector (sizeOfx);

	for (int i=0; i<sizeOfx; i++){
		toVector[i]=x[i];
		}

	return toVector;

}
