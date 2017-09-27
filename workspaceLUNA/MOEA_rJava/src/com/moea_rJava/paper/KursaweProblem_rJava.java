package com.moea_rJava.paper;

/**
 *
 * @author Diego J. Bodas Sagi
 * all code based on MOEA framework and rJava examples
 * rJava: http://www.rforge.net/JRI/files/
 */

import org.moeaframework.core.Solution;
import org.moeaframework.core.variable.EncodingUtils;
import org.moeaframework.core.variable.RealVariable;
import org.moeaframework.problem.AbstractProblem;

import org.rosuda.JRI.Rengine;
import org.rosuda.JRI.REXP;

//R CMD javareconf --- as Root.
//install.packages("rJava")
class KursaweProblem_rJava extends AbstractProblem {
	private static Rengine re;
	private void startR() {
		// just making sure we have the right version of everything
		if (!Rengine.versionCheck()) {
			System.err.println("** Version mismatch - Java files don't match library=version.");
			System.exit(1);
		}
		System.out.println("Creating Rengine");
		String[] Rargs = {"--vanilla"};
		re= new Rengine(Rargs, false, null);//new TextConsole());
		System.out.println("Rengine created, waiting for R");
		// the engine creates R is a new thread, so we should wait until it's ready
		if (!re.waitForR()) {
			System.out.println("Cannot load R");
			return;
		}
	}
	
	public static void closeR(){
		re.end();
		System.out.println("R session closed");
	}

	public KursaweProblem_rJava() {
		//#variables and objectives
		super(3, 2);
		startR();
	}
	@Override
	public Solution newSolution() {
		Solution solution = new Solution(numberOfVariables,
		numberOfObjectives);
		for (int i = 0; i < numberOfVariables; i++) {
			//Domain for variable
			solution.setVariable(i, new RealVariable(-5.0, 5.0));
		}
		return solution;
	}
	@Override
	//We evaluate the fitness function
	public synchronized void evaluate(Solution solution) {
		double[] x = EncodingUtils.getReal(solution);
		double[] result = null;
		//Kursawe1
		@SuppressWarnings("unused")
		REXP exp;
		re.assign("x", x);
		re.eval("x_length <- length(x)");
        re.eval("obj1 <- -10.0 * sum(exp(-0.2 * sqrt(x[1:(x_length-1)]^2 + "
      		+ "x[2:x_length]^2)))");
   	 	re.eval("obj2 <- sum(abs(x)^0.8 + 5 * sin(x^3))");
   	 	re.eval("myResult <- as.double(c(obj1, obj2))");
		result = re.eval("myResult;").asDoubleArray();
		//objective #1
		solution.setObjective(0, result[0]);
		//objective #2
		solution.setObjective(1, result[1]);
	}
}
