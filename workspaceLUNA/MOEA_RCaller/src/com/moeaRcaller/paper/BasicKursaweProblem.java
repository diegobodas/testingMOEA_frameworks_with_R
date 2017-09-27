package com.moeaRcaller.paper;

/**
 *
 * @author Diego J. Bodas Sagi
 * using MOEAFramework & RCaller
 * code based on libraries examples
 */

import org.moeaframework.core.Solution;
import org.moeaframework.core.variable.EncodingUtils;
import org.moeaframework.core.variable.RealVariable;
import org.moeaframework.problem.AbstractProblem;

import rcaller.RCaller;
import rcaller.RCode;

public class BasicKursaweProblem extends AbstractProblem {
    
    public BasicKursaweProblem(){
        //#variables and objectives
        super(3,2);
    }
    
     @Override
     public Solution newSolution() {
         Solution solution = new Solution(numberOfVariables, numberOfObjectives);
         for (int i = 0; i < numberOfVariables; i++) {
             //Domain for variable
             solution.setVariable(i, new RealVariable(-5.0, 5.0));
        }
        return solution;
     }
     
     @Override
     //We evaluate the fitness function calling to R with RCaller
     public void evaluate(Solution solution) {
        
    	double[] x = EncodingUtils.getReal(solution);        
        double[] result = null;
        
        //MIN Objective     
                      
        try {
          /*
           * Creating an instance of RCaller class
           */
          RCaller caller = new RCaller();
          RCode code = new RCode();
          
           /*
           * Find Rscript in your linux system
           * We must do this!
           * 
           */
          caller.setRscriptExecutable("/usr/bin/Rscript");
          
          /*
           * Converting Java arrays to R arrays
           */
          code.addDoubleArray("x", x);
          code.addRCode("x_length <- length(x)");
          
          code.addRCode("obj1 <- -10.0 * sum(exp(-0.2 * sqrt(x[1:(x_length-1)]^2 + "
          		+ "x[2:x_length]^2)))");
          code.addRCode("obj2 <- sum(abs(x)^0.8 + 5 * sin(x^3))");
          code.addRCode("myResult <- as.double(c(obj1, obj2))");
              
          caller.setRCode(code);
          caller.runAndReturnResult("myResult");
          //result          
          result = caller.getParser().getAsDoubleArray("myResult");                            
        } 
        
          catch (Exception e) {
          /*
           * Note that, RCaller does some OS based works such as creating an external process and
           * reading files from temporary directories or creating images for plots. Those operations
           * may cause exceptions for those that user must handle the potential errors. 
           */
          System.out.println(e.toString());
        }
               
        //Set objective #1
        solution.setObjective(0, result[0]);
        //Set objective #2
        solution.setObjective(1, result[1]);
     }    
}
