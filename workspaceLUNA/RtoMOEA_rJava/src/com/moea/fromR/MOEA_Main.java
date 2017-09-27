package com.moea.fromR;

/**
 *
 * @author Diego J. Bodas Sagi
 * all code based on MOEA framework and rJava examples
 * http://blog.pingoured.fr/index.php?post/2009/03/23/Getting-rJava/JRI-to-work%3A
 */
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

import org.moeaframework.Executor;
import org.moeaframework.core.NondominatedPopulation;
import org.moeaframework.core.Solution;

/**
 * Demonstrates using an Executor to solve my problem with NSGA-II,
 * one of the most widely-used multiobjective evolutionary algorithms.
 */

public class MOEA_Main {
	
	private int evaluation_;
	private int popsize_;
	private long cross_prob_;
	private long cross_index_;
	private long pm_rate_;
	private long pm_index_;
	private String ea_algorithm;
	
	MOEA_Main (int evaluation, int popsize, 
			long cross_prob, long cross_index, long pm_rate, long pm_index){
		//Initialize parameters
		evaluation_ = evaluation;
		popsize_ = popsize;
		cross_prob_ = cross_prob; //0.9
		cross_index_ = cross_index; //20.0
		pm_rate_ = pm_rate; //0.1
		pm_index_ = pm_index; //20.0
		ea_algorithm = "NSGAII";
	}

	public void run() {
		long startTime = System.currentTimeMillis();
		//configure and run this experiment
		//System.out.println(System.getProperty("java.library.path"));
		NondominatedPopulation result = new Executor()
				.withProblemClass(Problem_rJava.class)
				.withAlgorithm(ea_algorithm)
                                .withMaxEvaluations(evaluation_)//several executions
                                //parameters
                                .withProperty("populationSize", popsize_)
                                .withProperty("sbx.rate", cross_prob_)
                                .withProperty("sbx.distributionIndex", cross_index_)
                                .withProperty("pm.rate", pm_rate_)
                                .withProperty("pm.distributionIndex", pm_index_)
				.distributeOnAllCores() //Local parallelization
				.run();
		
		//Close R session
		Problem_rJava.closeR();
		//RunTime
		long stopTime = System.currentTimeMillis();
		long elapsedTime = stopTime - startTime;
		System.out.println(elapsedTime);
		//Write results to file
		writeToFile(result);
	}
	
	public void writeToFile(NondominatedPopulation result) {
		
		try {
			String path = "/home/cloudera/RevisionNoviembre2014/CodigosFinales/Rcode/RtoJava/FUN.txt";
			File file = new File(path);
 
			// if file doesn't exists, then create it
			if (!file.exists()) {
				file.createNewFile();
			}
 
			FileWriter fw = new FileWriter(file.getAbsoluteFile());
			BufferedWriter bw = new BufferedWriter(fw);
			//display the results
			for (Solution solution : result) {
				bw.write(solution.getObjective(0) + "," + 
						solution.getObjective(1));
			}
			
			bw.close();
 
			System.out.println("Done");
 
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

}

