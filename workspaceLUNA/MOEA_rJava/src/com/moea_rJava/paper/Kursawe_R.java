package com.moea_rJava.paper;

/**
 *
 * @author Diego J. Bodas Sagi
 * all code based on MOEA framework and rJava examples
 * http://blog.pingoured.fr/index.php?post/2009/03/23/Getting-rJava/JRI-to-work%3A
 */
import org.moeaframework.Executor;
import org.moeaframework.core.NondominatedPopulation;
import org.moeaframework.core.Solution;

/**
 * Demonstrates using an Executor to solve my problem with NSGA-II,
 * one of the most widely-used multiobjective evolutionary algorithms.
 */

public class Kursawe_R {

	public static void main(String[] args) {
		//configure and run this experiment
		//System.out.println(System.getProperty("java.library.path"));
		NondominatedPopulation result = new Executor()
				.withProblemClass(KursaweProblem_rJava.class)
				.withAlgorithm("NSGAII")
                                .withMaxEvaluations(10000)//several executions
                                //parameters
                                .withProperty("populationSize", 100)
                                .withProperty("sbx.rate", 0.9)
                                .withProperty("sbx.distributionIndex", 20.0)
                                .withProperty("pm.rate", 0.1)
                                .withProperty("pm.distributionIndex", 20.0)
				.distributeOnAllCores() //Local parallelization
				.run();
		
		//Close R session
		//chequear, comprobar que .run() no cierra el objeto
		KursaweProblem_rJava.closeR();
		//display the results
		for (Solution solution : result) {
			System.out.println(solution.getObjective(0) + "," + 
					solution.getObjective(1));
		}
	}

}

