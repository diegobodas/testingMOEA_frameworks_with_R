/*
 * Modify by Diego J. Bodas Sagi
 * Evolutionary Algorithms with JMetal and R
 * November 2014
 * Madrid, Spain
 * First version
 */

//In future version, this class has to be parameterized in a standard
//problem using the R function
#include "RProblem.h"

/**
 * Constructor.
 * Creates a new instance of the Kursawe problem.
 * @param numberOfVariables Number of variables of the problem
 * @param solutionType The solution type must "Real", "BinaryReal, and "ArrayReal".
 */
RProblem::RProblem(string solutionType, int numberOfVariables, Rcpp::Function f):f_(f) {

  numberOfVariables_   = numberOfVariables;
  numberOfObjectives_  = 2;
  numberOfConstraints_ = 0;
  problemName_         = "RProblem";

  lowerLimit_ = new double[numberOfVariables_];
  if (lowerLimit_ == NULL) {
    cout << "Impossible to reserve memory for storing the variable lower limits" << endl;
    Rcpp::stop("There has been a problem in the execution!\n");
    exit(-1);
  }

  upperLimit_ = new double[numberOfVariables_];
  if (upperLimit_ == NULL) {
    cout << "Impossible to reserve memory for storing the variable lower limits" << endl;
    Rcpp::stop("There has been a problem in the execution!\n");
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
    Rcpp::stop("There has been a problem in the execution!\n");
    exit(-1) ;
  }

} // Problem


/**
 * Destructor
 */
RProblem::~RProblem() {
  delete [] lowerLimit_ ;
  delete [] upperLimit_ ;
  delete solutionType_ ;
} // ~Problem


/**
 * Evaluates a solution
 * @param solution The solution to evaluate
 */

// [[Rcpp::export]]
void RProblem::evaluate(Solution *solution) {

  XReal * vars = new XReal(solution);
  std::vector<double> xVector (numberOfVariables_);

  double * fx = new double[2];                 // function values
  if (fx == NULL) {
    cout << "Error grave: Impossible to reserve memory while evaluating the problem" << endl;
    Rcpp::stop("There has been a problem in the execution!\n");
    exit(-1);
  }

  //Get individual to evaluate
  for (int i=0; i<numberOfVariables_; i++){
	  xVector[i]=vars->getValue(i);
  }

  //Run in R
  Rcpp::NumericVector xx(f_(Rcpp::Named("x", xVector)));

  solution->setObjective(0,xx[0]);
  solution->setObjective(1,xx[1]);

  //vector class has a destructor, called when variable is out of scope
  delete vars;

} // evaluate
