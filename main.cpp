#include <iostream>
#include "GAP.h"
#include "Lagrangian.h"

int main()
{  clock_t start, end;
   GeneralizedAssignemnt* GAP = new GeneralizedAssignemnt();
   string fileName, path;
   int res;

   path = "c:/AAAToBackup/ricerche/GAP/istanze/instances/homemade/";
   fileName = "toy.json";

   GAP->readJSONdata(path+fileName);

   start = clock();

   double alpha     = 2.5;
   double alphastep = 0.97;
   double minalpha  = 0.001;
   int innerIter = 40;
   int maxiter   = 1000000;
   Lagrangian* LAGR = new Lagrangian(GAP, GAP->zub);

   cout << "Relaxing capacities ---------------" << endl;
   res = LAGR->lagrAss(GAP->c, alpha, alphastep, minalpha, innerIter, maxiter);

   cout << "Relaxing assignments ---------------" << endl;
   res = LAGR->lagrCap(GAP->c, alpha, alphastep, minalpha, innerIter, maxiter);

   if (LAGR != NULL) delete LAGR;
   LAGR = NULL;

   end = clock();
   cout << "Time: " << (double)(end - start)/CLOCKS_PER_SEC << endl;

   cout << "\n<ENTER> to exit ..."; cin.get();
   delete GAP->sol;
   delete GAP->solbest;
   delete GAP;
   return 0;
}
