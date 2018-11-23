#ifndef GAP_H
#define GAP_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <climits>
#include <cfloat>
#include <cmath>
#include <string>
#include <vector>
#include <array>
#include <stdlib>     /* atof */
#include <cstdlib>    /* srand, rand */
#include <time.h>     /* time */
#include <assert.h>   /* assert */
#include <algorithm>  /* std::sort */

using namespace std;

class GeneralizedAssignemnt
{
   public:
      GeneralizedAssignemnt();
      ~GeneralizedAssignemnt();
      string name; // instance name
      int n;       // number of clients
      int m;       // number of servers
      int nDays;   // planning horizon (if scheduling)
      int** c;     // assignment costs
      int** req;   // client requests
      int*  cap;   // server capacities

      int *sol,*solbest;    // for each client, its server
      int zub,zlb;

      double EPS;

      int checkSol(int* sol);                       // feasibility check
      int fixSol(int* infeasSol, int* zsol);        // recovers feasibility in case of partial or overassigned solution
      int fixSolViaKnap(int* infeasSol, int* zsol); // recovers feasibility via knapsacks on residual capacities

      void readJSONdata(string);
};

// free
void computeRegrets(int**, int, int, vector<int> & );
double KDynRecur(int n, int Kcap, int* Q, double* val, int* Ksol);
void KdecodeSol(int i, int Kcap, int* Q, double* val, int n, double** f, int* sol);
void printDblArray(double* a, int n);

#endif // GAP_H
