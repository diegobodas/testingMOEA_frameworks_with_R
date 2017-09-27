//  PAES_main.cpp
//

//  You should have received a copy of the GNU Lesser General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.
/*
 * Modify by Diego J. Bodas Sagi
 * Evolutionary Algorithms with JMetal and R
 * November 2014
 * Madrid, Spain
 * First version
 */
#include "PAES_main.h";

PAES_main::PAES_main(int evaluations, int archiveSize, int biSectionsVal, double DistIndex, Rcpp::Function f):f_(f) {

	clock_t t_ini, t_fin;
	  Problem   * problem   ; // The problem to solve
	  Algorithm * algorithm ; // The algorithm to use
	  Operator  * mutation  ; // Mutation operator

	  //Select program here
	  //cout << "Problem: " << f << endl;
	  problem = ProblemFactory::getProblem("RProblem", f_);

	  algorithm = new paes(problem);

	  // Algorithm parameters
	  int archiveSizeValue = archiveSize;
	  int *archiveSizePtr = &archiveSizeValue;
	  int biSectionsValue = biSectionsVal;
	  int *biSectionsPtr = &biSectionsValue;
	  int maxEvaluationsValue = evaluations;
	  int *maxEvaluationsPtr = &maxEvaluationsValue;

	  algorithm->setInputParameter("archiveSize",archiveSizePtr);
	  algorithm->setInputParameter("biSections",biSectionsPtr);
	  algorithm->setInputParameter("maxEvaluations",maxEvaluationsPtr);

	  // Mutation (Real variables)
	  map<string, void *> parameters; // Operator parameters
	  parameters.clear();
	  double probabilityValue1 = 1.0/problem->getNumberOfVariables();
	  double *probabilityPtr1 = &probabilityValue1;
	  double distributionIndexValue1 = DistIndex;
	  double *distributionIndexPtr1 = &distributionIndexValue1;
	  parameters["probability"] =  probabilityPtr1 ;
	  parameters["distributionIndex"] = distributionIndexPtr1 ;
	  mutation = new PolynomialMutation(parameters);

	  algorithm->addOperator("mutation",mutation);

	  t_ini = clock();
	  SolutionSet * population = algorithm->execute();
	  t_fin = clock();
	  double secs = (double) (t_fin - t_ini);
	  secs = secs / CLOCKS_PER_SEC;

	// Result messages
	cout << "Total execution time: " << secs << "s" << endl;
	cout << "Variables values have been written to file VAR" << endl;
	population->printVariablesToFile("VAR");
	cout << "Objectives values have been written to file FUN" << endl;
	population->printObjectivesToFile("FUN");

  delete mutation;
  delete population;
  delete algorithm;

  cout << "*** E N D *** " << endl;
  cout << "Check files for results" << endl;


} // NSGAII_main



