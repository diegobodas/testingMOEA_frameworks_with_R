package com.moeaRcaller.paper;

/**
 *
 * @author Diego J. Bodas Sagi
 * using MOEAFramework & RCaller
 * code based on libraries examples
 */
import org.moeaframework.Executor;
import org.moeaframework.core.NondominatedPopulation;
import org.moeaframework.core.Solution;

/**
 * Demonstrates using an Executor to solve my problem with NSGA-II,
 * one of the most widely-used multiobjective evolutionary algorithms.
 */
public class BasicExampleRCaller {

	public static void main(String[] args) {
		//configure and run this experiment
		NondominatedPopulation result = new Executor()
				.withProblemClass(BasicKursaweProblem.class)
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
		
		//display the results
		for (Solution solution : result) {
			System.out.println(solution.getObjective(0) + "," + 
					solution.getObjective(1));
		}
	}

}

