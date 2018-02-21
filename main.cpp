#include <iostream>
#include "GAP.h"
#include "Lagrangian.h"

int main(int argc, char *argv[])
{  clock_t start, end;
   GeneralizedAssignemnt* GAP = new GeneralizedAssignemnt();
   string fileName, path;
   int res;

   double alpha     = atof(argv[1]);
   double alphastep = atof(argv[2]);
   double minalpha  = atof(argv[3]);
   int innerIter = atoi(argv[4]);
   int maxiter   = atoi(argv[5]);
   cout << "alpha="     << alpha << endl;
   cout << "alphastep=" << alphastep << endl;
   cout << "minalpha="  << minalpha << endl;
   cout << "innerIter=" << innerIter << endl;
   cout << "maxiter="   << maxiter << endl;

   path = "c:/AAAToBackup/ricerche/GAP/istanze/instances/homemade/";
   fileName = "toy.json";

   GAP->readJSONdata(path+fileName);

   start = clock();
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
