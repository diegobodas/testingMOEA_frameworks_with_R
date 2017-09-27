/*
 * Modify by Diego J. Bodas Sagi
 * Evolutionary Algorithms with JMetal and R
 * November 2014
 * Madrid, Spain
 * First version
 */
#include "PAES_main.h"
#include "NSGAII_main.h"
#include <iostream>

using namespace Rcpp;

// [[Rcpp::export]]
RcppExport SEXP callNSGAII_jMetalCpp(SEXP evaluations, SEXP pop_size, SEXP cross_prob,
									 SEXP cross_distr_index, SEXP f) {
	//check
	int evaluate = REAL(evaluations)[0];
	int popSize = REAL(pop_size)[0];
	double crossProb = REAL(cross_prob)[0];
	double crossDistIndex = REAL(cross_distr_index)[0];
	const char * funct = CHAR(STRING_ELT(f,0));

	//Get R Environment
	Rcpp::Environment myEnv = Environment::global_env();
	//Get R Function
	Function myFunction = myEnv[funct];
	//Use it!
	NSGAII_main NSGAII_run(evaluate, popSize, crossProb, crossDistIndex, myFunction);
	//TEST
	//std::vector<double> individual;
	//individual.push_back (1);
	//individual.push_back (2);
	//individual.push_back (3);
	//return myFunction(Rcpp::Named("x", individual));
	//TEST END
	Rprintf("See FUN file");
	return R_NilValue;
}

// [[Rcpp::export]]
RcppExport SEXP callPAES_jMetalCpp(SEXP evaluations, SEXP archiveSize, SEXP biSectionsVal,
									 SEXP DistIndex, SEXP f) {
	//check
	int evaluate = REAL(evaluations)[0];
	int archSize = REAL(archiveSize)[0];
	double biSections = REAL(biSectionsVal)[0];
	double DistInd = REAL(DistIndex)[0];
	const char * funct = CHAR(STRING_ELT(f,0));

	//Get R Environment
	Rcpp::Environment myEnv = Environment::global_env();
	//Get R Function
	Function myFunction = myEnv[funct];
	//Use it!
	PAES_main PAES_run(evaluate, archSize, biSections, DistInd, myFunction);
	//TEST
	//std::vector<double> individual;
	//individual.push_back (1);
	//individual.push_back (2);
	//individual.push_back (3);
	//return myFunction(Rcpp::Named("x", individual));
	//TEST END
	Rprintf("See FUN file");
	return R_NilValue;
}

