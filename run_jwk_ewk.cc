#include <TROOT.h>
void run_jwk_ewk(string outFile){
 Long64_t start = gSystem->Now();
 gSystem->Exec(("rm "+outFile).c_str());
 gROOT->ProcessLine(".L Selector.C++");
 gROOT->ProcessLine((".x jwk_ewkino_make_hists.C++(\""+outFile+"\")").c_str()); 
 gROOT->ProcessLine((".x ewkino_stacker.C++(\""+outFile+"\")").c_str()); 
 Long64_t end = gSystem->Now();
 cout << "Time to Run: " << (end-start)/1000.0 << " seconds" << endl;
 gROOT->ProcessLine(".q"); 
}
