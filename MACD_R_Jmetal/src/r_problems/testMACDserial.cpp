//  testMACDserial.cpp
/*
 * Author: Diego J. Bodas Sagi
 * Evolutionary Algorithms with JMetal and R
 * September 2013
 * Madrid, Spain
 * First version
 */
#include "testMACDserial.h"


/**
 * @class testMACDserial
 * @brief Class representing the problem MACD: SMA or EMA? (With R)
 **/

/**
 * Constructor.
 * Creates a new instance of the testMACD problem for serial version.
 * @param numberOfVariables Number of variables of the problem
 * @param solutionType The solution type must "Real", "BinaryReal, and "ArrayReal".
 */
testMACDserial::testMACDserial(string solutionType, int numberOfVariables, RInside & R):R_(R) {
  //3 variables: fast, slow  and signal
  numberOfVariables_   = numberOfVariables;
  //2 objectives: minimize Sharpe Ratio with EMA and with SMA (MACD)
  numberOfObjectives_  = 2;
  numberOfConstraints_ = 0;
  //This is the serial version of the problem
  problemName_         = "testMACDserial";

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
	//JMetalcpp does not include an IntegerSolutionType
	//It is mandatory to format variables
    lowerLimit_[i] = 5; //min value for MACD parameters
    upperLimit_[i] = 150; //max value for MACD parameters based on Bodas-Sagi papers
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

} // testMACDserial


/**
 * Destructor
 */
testMACDserial::~testMACDserial() {
  delete [] lowerLimit_ ;
  delete [] upperLimit_ ;
  delete solutionType_ ;
} // ~testMACDserial


/**
 * Evaluates a solution
 * @param solution The solution to evaluate
 */
void testMACDserial::evaluate(Solution *solution) {

  XReal * vars = new XReal(solution);

  double * fx = new double[2];                 // function values
  if (fx == NULL) {
    cout << "Severe error: Impossible to reserve memory while evaluating the problem" << endl;
    exit(-1);
  }

  int * x = new int[numberOfVariables_];
  for (int i = 0 ; i < numberOfVariables_; i++) {
    x[i] = (int)(vars->getValue(i)); //we ignore decimals
  }

  //Check fast <> long
  if (x[0] == x[1]){
  	x[1] = x[1] + 1;
  	vars->setValue(1,x[1]+1);
  }

  	//Check fast <> signal
  if (x[0] == x[2]){
    	x[2] = x[2] - 1;
    	vars->setValue(2,x[2]-1);
    }



  //Check solution: signal<fast<slow.
  //x must be (fast, slow, signal)
  std::vector<int> xVector = findFast(x, numberOfVariables_);

/* DEBUG
  std::cout<<"----------\n";
  std::cout<<xVector[0]<<endl;
  std::cout<<xVector[1]<<endl;
  std::cout<<xVector[2]<<endl;
  std::cout<<"----------\n";
*/

  fx[0] = 0.0;
  fx[1] = 0.0;

  /* R code execution
   * #Example. Values for fast, slow and signal
   * fast_ <- 15
   * slow_ <- 44
   * signal_ <- 11
   * resultTest1 <- simpleRuleRiskReturnManager(1, myTserie, fast_, slow_, signal_, Rsp500, Rief)
   * resultTest2 <- simpleRuleRiskReturnManager(2, myTserie, fast_, slow_, signal_, Rsp500, Rief)
   *
   */

  try {
  		R_.assign(xVector,"x");

  		std::string txt;
  		txt = "resultTest1 <- simpleRuleRiskReturnManager(1, myTserie, x[1], x[2], x[3], Rsp500, Rief)";
  		//execute and get the results
  		R_.parseEvalQ(txt);
  		txt = "resultTest2 <- simpleRuleRiskReturnManager(2, myTserie, x[1], x[2], x[3], Rsp500, Rief)";
  		R_.parseEvalQ(txt);
  		//format
  		txt = "result <- c(resultTest1, resultTest2)";
  		std::vector<double> getResults = Rcpp::as< std::vector< double > >(R_.parseEval(txt));
  		//Assign to objectives
  		fx[0] = getResults[0];
  		fx[1] = getResults[1];

  	 } catch(std::exception& ex) {
  	        std::cerr << "Exception caught: " << ex.what() << std::endl;

  	    } catch(...) {
  	        std::cerr << "Unknown exception caught" << std::endl;

  	    }

  solution->setObjective(0,fx[0]);
  solution->setObjective(1,fx[1]);

  delete [] fx;
  delete [] x;
  delete vars;

} // evaluate

//Only for MACD problem, sizeOfx is supposed to be 3
//Objective: order elements in x: fast, slow, signal with slow > fast > signal
//fast, slow, signal = 0, 1 , 2 positions.
//We assume that fast <> slow <> signal
std::vector<int> testMACDserial::findFast(int * x, int sizeOfx){

	//PRE: for this problem sizeOfx = 3
	std::vector<int> result (sizeOfx);

	result[0] = x[0];
	result[1] = x[1];
	result[2] = x[2];

	//Check fast < long and signal < fast. Order = {fast, long, signal}. Ex -> {12, 26, 9}

	if ((x[0] > x[1]) && (x[1] > x[2])){
		result[0] = (int)x[1];
		result[1] = (int)x[0];
		result[2] = (int)x[2];
	}

	else if ((x[0] > x[2]) && (x[2] > x[1])){
		result[0] = (int)x[2];
		result[1] = (int)x[0];
		result[2] = (int)x[1];
	}

	else if ((x[1] > x[0]) && (x[0] > x[2])){
			result[0] = (int)x[0];
			result[1] = (int)x[1];
			result[2] = (int)x[2];
		}

	else if ((x[1] > x[2]) && (x[2] > x[0])){
				result[0] = (int)x[2];
				result[1] = (int)x[1];
				result[2] = (int)x[0];
			}

	else if ((x[2] > x[1]) && (x[1] > x[0])){
					result[0] = (int)x[1];
					result[1] = (int)x[2];
					result[2] = (int)x[0];
				}

	else if ((x[2] > x[0]) && (x[0] > x[01])){
						result[0] = (int)x[0];
						result[1] = (int)x[2];
						result[2] = (int)x[1];
					}


	return result;

} //findFast
