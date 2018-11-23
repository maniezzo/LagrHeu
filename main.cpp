#include <iostream>
#include "GAP.h"
#include "Lagrangian.h"

int main(int argc, char *argv[])
{  clock_t start, end;
   GeneralizedAssignemnt* GAP = new GeneralizedAssignemnt();
   string fileName, path;
   int res;

   double alpha     = atof(argv[2]);
   double alphastep = atof(argv[4]);
   double minalpha  = atof(argv[6]);
   int innerIter = atoi(argv[8]);
   int maxiter   = atoi(argv[10]);
   int algoType  = atoi(argv[12]);
   int isVerbose = atoi(argv[14]);
   string instance = argv[16];

   if(isVerbose)
   {  cout << "alpha="     << alpha << endl;
      cout << "alphastep=" << alphastep << endl;
      cout << "minalpha="  << minalpha << endl;
      cout << "innerIter=" << innerIter << endl;
      cout << "maxiter="   << maxiter << endl;
      cout << "algorithm: "<< (algoType == 1 ? "Relax capacities" : "Relax assignments") << endl;
      cout << "verbose: "  << (isVerbose ? true : false) << endl;
      cout << "instance: "  << instance << endl;
   }

   path = "c:/AAAToBackup/ricerche/GAP/istanze/instances/homemade/";
   fileName = instance;
   GAP->isVerbose = isVerbose;

   GAP->readJSONdata(path+fileName);

   start = clock();
   Lagrangian* LAGR = new Lagrangian(GAP, GAP->zub);

   if(algoType == 1)
   {  if(isVerbose) cout << "Relaxing capacities ---------------" << endl;
      res = LAGR->lagrAss(GAP->c, alpha, alphastep, minalpha, innerIter, maxiter);
   }
   else
   {  if(isVerbose) cout << "Relaxing assignments ---------------" << endl;
      res = LAGR->lagrCap(GAP->c, alpha, alphastep, minalpha, innerIter, maxiter);
   }
   if (LAGR != NULL) delete LAGR;
   LAGR = NULL;

   end = clock();
   if(isVerbose) cout << "Time: " << (double)(end - start)/CLOCKS_PER_SEC << endl;
   cout << GAP->zub << endl;

   if(isVerbose) 
   {  cout << "\n<ENTER> to exit ..."; 
      cin.get();
   }
   delete GAP->sol;
   delete GAP->solbest;
   delete GAP;
   return 0;
}
