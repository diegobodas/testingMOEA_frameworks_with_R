package com.moea.fromR;

import org.rosuda.JRI.Rengine;
import org.rosuda.JRI.REXP;
/**
* @author Diego J. Bodas Sagi
* all code based on MOEA framework and rJava examples
*/

public class CallFromR {
	private static Rengine re;
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
	
    //Problem: R is single-threaded, 
	//so you can only run one JRIEngine instance in one JVM 
	//(and you can only initialize it once).
	//If you want parallel connections, consider using Rserve 
	//(REngine supports both JRI and Rserve). 
	//For R-based web-services, have a look at FastRWeb (which uses Rserve).
	public static int checkREngine () {
		//Get actual session from R
		//Rengine re = Rengine.getMainEngine();
		if (!Rengine.versionCheck()) {
			System.err.println("** Version mismatch - Java files don't match library=version.");
			System.exit(1);
		}
		System.out.println("Creating Rengine");
		String[] Rargs = {"--vanilla"};
		re= new Rengine(Rargs, false, null);//new TextConsole());
		System.out.println("Rengine created, waiting for R");
		/*
		@SuppressWarnings("unused")
		REXP exp;
		int[] x = {3};
		re.assign("x", x); //only with arrays
		re.eval("x <- x + 16;");
		double[] result = re.eval("a;").asDoubleArray();
		//print result 0
		for (int i = 1; i < result.length; i++)
			System.out.println(result[i]);
		System.out.println("All printed");
		*/
		return 0;
	}
}
