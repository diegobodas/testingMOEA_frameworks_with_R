/*
 * main.cpp
 *
 *  Created on: Nov 19, 2014
 *      Author: cloudera
 */
#include <RInside.h>                    // for the embedded R via RInside

int main(int argc, char *argv[]) {

    RInside R_(argc, argv);              // create an embedded R instance

    R_["txt"] = "Hello, world!\n";	// assign a char* (string) to 'txt'

    double x[3] = {1, 2, 30};

    std::vector<double> v(x, x + sizeof x / sizeof x[0]);

    R_.parseEvalQ("cat(txt)");           // eval the init string, ignoring any returns
    try {
    		R_["x"] = v;
    		//R_.parseEvalQ("x");
    		std::string txt;
    		txt = "myResult<-0;"
    			  "for (i in 1:(length(x)-1)){myResult <- myResult + "
    			  "(-10.0 * exp(-0.2 * sqrt((x[i])^(2.0) + (x[i+1])^(2.0))))};";
    		R_.parseEvalQ(txt);
    		double salida = R_["myResult"];
    		std::cout << "La salida ha sido: " <<  salida;


    	 } catch(std::exception& ex) {
    	        std::cerr << "Exception caught: " << ex.what() << std::endl;
    	        return (-1);
    	    } catch(...) {
    	        std::cerr << "Unknown exception caught" << std::endl;
    	        return(-1);
    	    }


    exit(0);
}

