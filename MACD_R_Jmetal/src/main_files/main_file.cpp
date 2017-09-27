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
 * version 1.0
 */
#include "NSGAII_main.h";


int main(int argc, char **argv) {

	try {

		RInside R(argc, argv);

		//PARALLELIZATION ENVIRONMENT --- OPTIONAL
		//load snow library for parallelization
		//R.parseEvalQ("library (snow)");

		//load TTR (MACD), PerformanceAnalytics (Simple Returns)
		//load testMACDrules packages for objective evaluation
		R.parseEvalQ("library (TTR); library (PerformanceAnalytics); library (testMACDrules)");

		/*
		 *
			#load sp500 and IEF data from 2000 to September 2013
			sp500 <- getYahooData("^GSPC", 20000101, 20130901, freq="daily", type="price")
			IEF <- getYahooData("IEF", 20000101, 20130901, freq="daily", type="price")
			#In this version, data are downloaded previously and loaded in the R session.
			#We try to avoid network connection problems.
			#Prepare data and simple returns calculation
			myTserie <- cbind(sp500$Close, IEF$Close) #AvgClose is other option
			colnames(myTserie) <- c("SP500", "IEF")
			myTserie <- na.omit(myTserie) #delete missing values

			Rsp500 <- Return.calculate(myTserie$SP500)
			Rief <- Return.calculate(myTserie$IEF)

		 *
		 */

		string txt = "load(\"/home/Diego/ParallelWork/sp500_2000_2013.RData\"); \n"
				     "load(\"/home/Diego/ParallelWork/IEF_2000_2013.RData\"); \n"
					 "myTserie <- cbind(sp500$Close, IEF$Close); \n"
					 "colnames(myTserie) <- c(\"SP500\", \"IEF\"); \n"
					 "myTserie <- na.omit(myTserie); \n"
				     "Rsp500 <- Return.calculate(myTserie$SP500); \n"
				     "Rief <- Return.calculate(myTserie$IEF)";

		R.parseEvalQ(txt);


		//PARALLELIZATION ENVIRONMENT --- OPTIONAL
		//start the cluster in dual core computer
		//R.parseEvalQ("cluster <- makeCluster(type = \"SOCK\", c(\"localhost\", \"localhost\", \"localhost\"))");

		//Solve the multiobjective problem
		NSGAII_main NSGAII_run(R);

		//PARALLELIZATION ENVIRONMENT --- OPTIONAL
		//stop the cluster
		//R.parseEvalQ("stopCluster(cluster)");

	} catch(...) {
        std::cerr << "Unknown exception caught" << std::endl;
        return(-1);
	}

    return (0);
}




