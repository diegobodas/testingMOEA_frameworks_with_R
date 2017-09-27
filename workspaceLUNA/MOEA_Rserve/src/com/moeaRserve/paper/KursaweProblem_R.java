package com.moeaRserve.paper;

/**
 *
 * @author Diego J. Bodas Sagi
 * all code based on MOEA framework and RServe examples
 */

import java.util.logging.Level;
import java.util.logging.Logger;

import org.moeaframework.core.Solution;
import org.moeaframework.core.variable.EncodingUtils;
import org.moeaframework.core.variable.RealVariable;
import org.moeaframework.problem.AbstractProblem;
import org.rosuda.REngine.REXPMismatchException;
import org.rosuda.REngine.REngineException;
import org.rosuda.REngine.Rserve.RConnection;
import org.rosuda.REngine.Rserve.RserveException;

class TestException extends Exception {
    /**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	public TestException(String msg) { super(msg); }
}


public class KursaweProblem_R extends AbstractProblem {
   
    public KursaweProblem_R(){
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
     //We evaluate the fitness function 
     public void evaluate(Solution solution) {
    	 double[] x = EncodingUtils.getReal(solution);        
         double[] result = null;
         
         //MIN Objective     
                       
         try {
        	 RConnection connect= new RConnection();      
           /*
            * Converting Java arrays to R arrays
            */
        	 connect.assign("x", x);
        	 connect.voidEval("x_length <- length(x)");
           
        	 connect.voidEval("obj1 <- -10.0 * sum(exp(-0.2 * sqrt(x[1:(x_length-1)]^2 + "
           		+ "x[2:x_length]^2)))");
        	 connect.voidEval("obj2 <- sum(abs(x)^0.8 + 5 * sin(x^3))");
        	 connect.voidEval("myResult <- as.double(c(obj1, obj2))");
               
        	 result =connect.eval("myResult").asDoubles();             
             
             connect.close();
          
          } catch (RserveException ex) {
              Logger.getLogger(KursaweProblem_R.class.getName()).log(Level.SEVERE, null, ex);
          } catch (REXPMismatchException ex) {
              Logger.getLogger(KursaweProblem_R.class.getName()).log(Level.SEVERE, null, ex);
          } catch (REngineException ex) {
              Logger.getLogger(KursaweProblem_R.class.getName()).log(Level.SEVERE, null, ex);
          }
                
         //Set objective #1
         solution.setObjective(0, result[0]);
         //Set objective #2
         solution.setObjective(1, result[1]);
     }    
}
