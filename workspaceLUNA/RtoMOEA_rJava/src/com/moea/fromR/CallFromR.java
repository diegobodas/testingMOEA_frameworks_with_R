package com.moea.fromR;

/**
* @author Diego J. Bodas Sagi
* all code based on MOEA framework and rJava examples
*/

public class CallFromR {

	public static void main(String[] args) {
		
		int N = Integer.parseInt(args[0]);
		int thin = Integer.parseInt(args[1]);
		int seed = Integer.parseInt(args[2]);
		double suma = suma (N,thin,seed);
		System.out.println("La suma es :" +  suma);
	}
	
	public static double suma (int N,int thin,int seed) {
		return N + thin + seed;
	}
	
	//Try call to NSGA-II
	public static int NSGA_II (int evaluation, int popsize, long cross_prob, 
							   long cross_index, long pm_rate, long pm_index) {
		MOEA_Main EA_Main_Class = new MOEA_Main(evaluation, popsize, cross_prob,
				cross_index, pm_rate, pm_index);
		//Call to Static Method Main
		EA_Main_Class.run();
		return 0;
	}
    
			 
}
