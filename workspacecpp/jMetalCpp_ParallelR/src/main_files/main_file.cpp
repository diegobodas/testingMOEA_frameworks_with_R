/*
 * main_file.cpp
 *
 *  Created on: 24/08/2013
 *      Author: Diego
 */

/*
 * Diego J. Bodas Sagi
 * Evolutionary Algorithms with JMetal and R
 * main file (start the program)
 * September 2013
 * Madrid, Spain
 * First version
 */
#include "NSGAII_main.h";


int main(int argc, char **argv) {

	try {

		RInside R(argc, argv);

		//load snow library for parallelization
		R.parseEvalQ("library (snow)");

		//load kursawe package for objective evaluation
		R.parseEvalQ("library (kursaweMO)");

		//start the cluster in dual core computer
		R.parseEvalQ("cluster <- makeCluster(type = \"SOCK\", c(\"localhost\", \"localhost\"))");

		//Solve the multiobjective problem
		NSGAII_main NSGAII_run(R);

		//stop the cluster
		R.parseEvalQ("stopCluster(cluster)");

	} catch(...) {
        std::cerr << "Unknown exception caught" << std::endl;
        return(-1);
	}

    return (0);
}



