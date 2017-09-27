//  ProblemFactory.cpp
//
//  Author:
//       Esteban López-Camacho <esteban@lcc.uma.es>
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
 * November 2014
 * Madrid, Spain
 * First version
 */

#include "ProblemFactory.h"


/**
 * Problem factory
 * @param name : Name of the problem
 */
Problem * ProblemFactory::getProblem(char * name, Rcpp::Function myFunction) {

	return getProblem(name, 0, NULL, myFunction);
}


/**
 * Problem factory which uses the same arguments as the main from where
 * is called (minimum two arguments)
 * @param argc : Number of arguments
 * @param argv : Array of arguments
 */
Problem * ProblemFactory::getProblem(int argc, char ** argv, Rcpp::Function myFunction) {

	if (argc==2) {
		return getProblem(argv[1], 0, NULL, myFunction);
	} else if (argc>2) {
		char ** argv2 = new char*[argc-2];
		for (int i=0; i<argc-2; i++) {
			argv2[i] = argv[i+2];
		}
		return getProblem(argv[1], argc-2, argv2, myFunction);
	} else {
		cerr << "Too few arguments to build a problem.";
		exit(-1);
	}
}


/**
 * Problem factory with some optional parameters to be used to construct the
 * problem
 * @param name : Name of the problem
 * @param argc : Number of parameters
 * @param argv : Array of parameters
 *
 * Your R Problem must appear here
 */

//Function modified for R executions. We pass the RInside instance
Problem * ProblemFactory::getProblem(char * name, int argc, char ** argv, Rcpp::Function myFunction) {

	if (strcmp(name, "RProblem")==0) { // RKursawe
		return new RProblem("Real", 3, myFunction);
		}

	else {
		cerr << "ProblemFactory::getProblem: Problem '" << name
				<< "' does not exist. Please, check the problem names "<< endl;
		exit(-1);

	}

}

