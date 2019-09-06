//
//  Histogram definitions and loading
//  Jack W King III 2019
//

#include "jwk_ewkino_hist_maker.h"
//#include "Selector.h"
#include <TLorentzVector.h>
//---------------------------------------------------------------------
// Utility functions
// -------------------------------------------------------------------
TLorentzVector * get4vec(double pt, double eta, double phi, double m){
	double px = pt*cos(phi);
	double py = pt*sin(phi);
	double pz = pt*sinh(eta);
	TLorentzVector *v = new TLorentzVector();
	v->SetXYZM( px,py,pz,m );
	return v;	
}
//---------------------------------------------------------------------
TLorentzVector * add4vecs( vector<double> pt, vector<double> eta, vector<double> phi, vector<double> m){

	TLorentzVector * p = new TLorentzVector();
	for(unsigned int i=0; i<pt.size(); i++){
		TLorentzVector *c = new TLorentzVector();
		c = get4vec(pt.at(i), eta.at(i), phi.at(i), m.at(i) );
		*p += *c;
	}
	return p;

}
//-----------------------------------------------------------------------
////---------------------------------------------------------------------
//
//	<--------------   create new histograms as in example below
//
//
//class otherHistClass : public parentHistClass{
// 
//  public:
//  void init_hist( string treeSubDir );
//  void fill_hist( Selector* selector );
// 
//}
//
//void otherHistClass::initi_hist(){
//    
//  setTDRStyle();
//  hist1d = new ROOT::TThreadedObject<TH1D>("parentHistClass","selectorHistClass", 2, -0.5, 1.5 );
//
//}
//
//  note:  parentHistClass has pointers:  
//  		hist1d 
//  		hist2d 
//  		hist1f 
//  		hist2f
//
//void otherHistClass::fill_hist( Selector* selector ){
//
//  (hist1d->Get())->Fill(1.0);
//  //----  or:  (hist1d->Get())->Fill(selector->RISR->at(2), 137.0*selector->weight);
//  //----  or:  (hist2d->Get())->Fill(selector->RISR->at(2), selector->PTISR->at(2) , 137.0*selector->weight);
//
//}

//-------------------------------------------------------------------------------------------------------
//----------------------------make new hist classes below------------------------------------------------
//-------------------------------------------------------------------------------------------------------
class metHist : public parentHistClass{

  public:
  void init_hist( string treeSubDir );
  void fill_hist( Selector* selector );

};

void metHist::init_hist( string treeSubDir ){

  set_subdir(treeSubDir);
  hist1d = new ROOT::TThreadedObject<TH1D>("metHist","MET", 90, 100, 1000 );
  (hist1d->Get())->GetXaxis()->SetTitle("MET [GeV]");
  (hist1d->Get())->GetYaxis()->SetTitle("Events Per 10 GeV Bin");
 // std::cout << "In Init from metHist !!" << std::endl;

}

void metHist::fill_hist( Selector* selector ){

  (hist1d->Get())->Fill(*(selector->MET), *(selector->weight)*137.0);

}
class flavorHist : public parentHistClass{

  public:
  void init_hist( string treeSubDir );
  void fill_hist( Selector* selector );

};

void flavorHist::init_hist( string treeSubDir ){

  set_subdir(treeSubDir);
  hist1d = new ROOT::TThreadedObject<TH1D>("flavorHist","FlavorCombination", 2, 0, 2 );
  (hist1d->Get())->GetXaxis()->SetTitle("Flavor Combination");
  (hist1d->Get())->GetYaxis()->SetTitle("Events");
}

void flavorHist::fill_hist( Selector* selector ){

  if(((abs((selector->PDGID_lep)[0]) == abs((selector->PDGID_lep)[1])) && ((selector->Charge_lep)[0] == (selector->Charge_lep)[1]))) (hist1d->Get())->Fill(0.5, *(selector->weight)*137.0);
  if(((abs((selector->PDGID_lep)[0]) != abs((selector->PDGID_lep)[1]) ) && ((selector->Charge_lep)[0] != (selector->Charge_lep)[1]))) (hist1d->Get())->Fill(1.5, 137.0*(*(selector->weight)));

}
//----------------------------------------------------------------------------
class mllHist : public parentHistClass{

  public:
  void init_hist( string treeSubDir );
  void fill_hist( Selector* selector );

};

void mllHist::init_hist( string treeSubDir ){

  set_subdir(treeSubDir);
  hist1d = new ROOT::TThreadedObject<TH1D>("mllHist","l_{1}l_{2} Lepton Pair Mass", 200, 0, 200 );
  (hist1d->Get())->GetXaxis()->SetTitle("l_{1}l_{2} Lepton Pair Mass [GeV]");
  (hist1d->Get())->GetYaxis()->SetTitle("Events Per 10 GeV Bin");

}

void mllHist::fill_hist( Selector* selector ){

  vector<double> lepVecPt;
  lepVecPt.push_back( (selector->PT_lep)[0] );
  lepVecPt.push_back( (selector->PT_lep)[1] );
  vector<double> lepVecEta;
  lepVecEta.push_back( (selector->Eta_lep)[0] );
  lepVecEta.push_back( (selector->Eta_lep)[1] );
  vector<double> lepVecPhi;
  lepVecPhi.push_back( (selector->Phi_lep)[0] );
  lepVecPhi.push_back( (selector->Phi_lep)[1] );
  vector<double> lepVecM;
  lepVecM.push_back( (selector->M_lep)[0] );
  lepVecM.push_back( (selector->M_lep)[1] );

  (hist1d->Get())->SetTitle("nOSSF Lepton Pair Mass [GeV]");

  TLorentzVector * ll = add4vecs( lepVecPt, lepVecEta, lepVecPhi, lepVecM );
  (hist1d->Get())->Fill( ll->M(), 137.0*(*(selector->weight)));

}
//----------------------------------------------------------------------------
class njetsHist : public parentHistClass{

  public:
  void init_hist( string treeSubDir );
  void fill_hist( Selector* selector );

};

void njetsHist::init_hist( string treeSubDir ){

  set_subdir(treeSubDir);
  hist1d = new ROOT::TThreadedObject<TH1D>("njetsHist","N jets", 11, -0.5, 10.5 );
  (hist1d->Get())->GetXaxis()->SetTitle("N jets");
  (hist1d->Get())->GetYaxis()->SetTitle("");
 // std::cout << "In Init from njetsHist !!" << std::endl;

}

void njetsHist::fill_hist( Selector* selector ){

  (hist1d->Get())->Fill(*(selector->Njet), 137.0*(*(selector->weight)));

}
//----------------------------------------------------------------------------
class ptcmHist_Cat1 : public parentHistClass{

  public:
  void init_hist( string treeSubDir );
  void fill_hist( Selector* selector );

};

void ptcmHist_Cat1::init_hist( string treeSubDir ){

  set_subdir(treeSubDir);
  hist1d = new ROOT::TThreadedObject<TH1D>("ptcmHist_Cat1","PTCM Cat 1", 50, 0, 500 );
  (hist1d->Get())->GetXaxis()->SetTitle("P_{t}^{CM} [GeV] Cat 1");
  (hist1d->Get())->GetYaxis()->SetTitle("Events Per 10 GeV Bin");
 // std::cout << "In Init from ptcmHist !!" << std::endl;

}

void ptcmHist_Cat1::fill_hist( Selector* selector ){

  (hist1d->Get())->Fill((selector->PTCM)[0] , 137.0*(*(selector->weight)));

}
//----------------------------------------------------------------------------
class ptisrHist_Cat1 : public parentHistClass{

  public:
  void init_hist( string treeSubDir );
  void fill_hist( Selector* selector );

};

void ptisrHist_Cat1::init_hist( string treeSubDir ){

  set_subdir(treeSubDir);
  hist1d = new ROOT::TThreadedObject<TH1D>("ptisrHist_Cat1","PTISR Cat 1", 100, 0, 1000 );
  (hist1d->Get())->GetXaxis()->SetTitle("P_{t}^{ISR} [GeV] Cat 1");
  (hist1d->Get())->GetYaxis()->SetTitle("Events Per 10 GeV Bin");
 // std::cout << "In Init from ptisrHist !!" << std::endl;

}

void ptisrHist_Cat1::fill_hist( Selector* selector ){

  (hist1d->Get())->Fill((selector->PTISR)[0], 137.0*(*(selector->weight)));

}
//----------------------------------------------------------------------------
class risrHist_Cat1 : public parentHistClass{

  public:
  void init_hist( string treeSubDir );
  void fill_hist( Selector* selector );

};

void risrHist_Cat1 ::init_hist( string treeSubDir ){

  set_subdir(treeSubDir);
  hist1d = new ROOT::TThreadedObject<TH1D>("risrHist_Cat1 ","R_{ISR} Cat 1", 40, 0, 2 );
  (hist1d->Get())->GetXaxis()->SetTitle("R_{ISR} [a.u.] Cat 1");
  (hist1d->Get())->GetYaxis()->SetTitle("");
 // std::cout << "In Init from risrHist !!" << std::endl;

}

void risrHist_Cat1 ::fill_hist( Selector* selector ){

  (hist1d->Get())->Fill((selector->RISR)[0], 137.0*(*(selector->weight)));

}
//----------------------------------------------------------------------------
class dphiCMIHist_Cat1 : public parentHistClass{

  public:
  void init_hist( string treeSubDir );
  void fill_hist( Selector* selector );
  
};

void dphiCMIHist_Cat1::init_hist( string treeSubDir ){

  set_subdir(treeSubDir);
  hist1d = new ROOT::TThreadedObject<TH1D>("dphiCMIHist_Cat1","#delta(#phi_{CMI}) Cat 1", 64, 0, 3.2 );
  (hist1d->Get())->GetXaxis()->SetTitle("#delta(#phi_{CMI}) [GeV] Cat 1");
  (hist1d->Get())->GetYaxis()->SetTitle("Events Per 10 GeV Bin");
 // std::cout << "In Init from dphiCMIHist !!" << std::endl;

}

void dphiCMIHist_Cat1::fill_hist( Selector* selector ){

  (hist1d->Get())->Fill((selector->dphiCMI)[0], 137.0*(*(selector->weight)));

}
//----------------------------------------------------------------------------
class ptcmHist_Cat2 : public parentHistClass{

  public:
  void init_hist( string treeSubDir );
  void fill_hist( Selector* selector );

};

void ptcmHist_Cat2::init_hist( string treeSubDir ){

  set_subdir(treeSubDir);
  hist1d = new ROOT::TThreadedObject<TH1D>("ptcmHist_Cat2","P_{t}^{CM} Cat 2", 50, 0, 500 );
  (hist1d->Get())->GetXaxis()->SetTitle("P_{t}^{CM} [GeV] Cat 2");
  (hist1d->Get())->GetYaxis()->SetTitle("Events Per 10 GeV Bin");
 // std::cout << "In Init from ptcmHist !!" << std::endl;

}

void ptcmHist_Cat2::fill_hist( Selector* selector ){

  (hist1d->Get())->Fill((selector->PTCM)[1] , 137.0*(*(selector->weight)));

}
//----------------------------------------------------------------------------
class ptisrHist_Cat2 : public parentHistClass{

  public:
  void init_hist( string treeSubDir );
  void fill_hist( Selector* selector );

};

void ptisrHist_Cat2::init_hist( string treeSubDir ){

  set_subdir(treeSubDir);
  hist1d = new ROOT::TThreadedObject<TH1D>("ptisrHist_Cat2","P_{t}^{ISR} Cat 2", 100, 0, 1000 );
  (hist1d->Get())->GetXaxis()->SetTitle("P_{t}^{ISR} [GeV] Cat 2");
  (hist1d->Get())->GetYaxis()->SetTitle("Events Per 10 GeV Bin");
 // std::cout << "In Init from ptisrHist !!" << std::endl;

}

void ptisrHist_Cat2::fill_hist( Selector* selector ){

  (hist1d->Get())->Fill((selector->PTISR)[1], 137.0*(*(selector->weight)));

}
//----------------------------------------------------------------------------
class risrHist_Cat2 : public parentHistClass{

  public:
  void init_hist( string treeSubDir );
  void fill_hist( Selector* selector );

};

void risrHist_Cat2 ::init_hist( string treeSubDir ){

  set_subdir(treeSubDir);
  hist1d = new ROOT::TThreadedObject<TH1D>("risrHist_Cat2 ","R_{ISR} Cat 2", 40, 0, 2 );
  (hist1d->Get())->GetXaxis()->SetTitle("R_{ISR} [a.u.] Cat 2");
  (hist1d->Get())->GetYaxis()->SetTitle("");
 // std::cout << "In Init from risrHist !!" << std::endl;

}

void risrHist_Cat2 ::fill_hist( Selector* selector ){

  (hist1d->Get())->Fill((selector->RISR)[1], 137.0*(*(selector->weight)));

}
//----------------------------------------------------------------------------
class dphiCMIHist_Cat2 : public parentHistClass{

  public:
  void init_hist( string treeSubDir );
  void fill_hist( Selector* selector );
  
};

void dphiCMIHist_Cat2::init_hist( string treeSubDir ){

  set_subdir(treeSubDir);
  hist1d = new ROOT::TThreadedObject<TH1D>("dphiCMIHist_Cat2","#delta(#phi_{CMI}) Cat 2", 64, 0, 3.2 );
  (hist1d->Get())->GetXaxis()->SetTitle("#delta(#phi_{CMI}) [GeV] Cat 2");
  (hist1d->Get())->GetYaxis()->SetTitle("Events Per 10 GeV Bin");
 // std::cout << "In Init from dphiCMIHist !!" << std::endl;

}

void dphiCMIHist_Cat2::fill_hist( Selector* selector ){

  (hist1d->Get())->Fill((selector->dphiCMI)[1], 137.0*(*(selector->weight)));

}
//----------------------------------------------------------------------------
class dphiSIHist_Cat2 : public parentHistClass{

  public:
  void init_hist( string treeSubDir );
  void fill_hist( Selector* selector );
  
};

void dphiSIHist_Cat2::init_hist( string treeSubDir ){

  set_subdir(treeSubDir);
  hist1d = new ROOT::TThreadedObject<TH1D>("dphiSIHist_Cat2","#delta(#phi_{SI}) Cat 2", 64, 0, 3.15 );
  (hist1d->Get())->GetXaxis()->SetTitle("#delta(#phi_{SI}) [GeV] Cat 2");
  (hist1d->Get())->GetYaxis()->SetTitle("Events/Bin");

}

void dphiSIHist_Cat2::fill_hist( Selector* selector ){

  (hist1d->Get())->Fill((selector->dphiSI)[1], 137.0*(*(selector->weight)));

}
//--------------------------------------------------------------
class dphiSI_DeltaMX3aMX3b_Cat1_hist : public parentHistClass{

  public:
  void init_hist( string treeSubDir );
  void fill_hist( Selector * selector );

};

void dphiSI_DeltaMX3aMX3b_Cat1_hist::init_hist( string treeSubDir ){

  set_subdir(treeSubDir);

  string g_Xname = "#delta#phi(S,I)";
  double g_Xmin = 0.;
  double g_Xmax = 3.15;
  int    g_NX = 50;
  string g_Yname = "|MX3a-MX3b| [GeV]";
  double g_Ymin = 0.;
  double g_Ymax = 500.;
  int    g_NY = 50;

  hist2d = new ROOT::TThreadedObject<TH2D>("dphiSI_DeltaMX3aMX3b_Cat1_hist","dphiSI_DeltaMX3aMX3b_Cat1_hist", g_NX, g_Xmin, g_Xmax, g_NY, g_Ymin, g_Ymax);
  (hist2d->Get())->GetXaxis()->SetTitle(g_Xname.c_str());
  (hist2d->Get())->GetYaxis()->SetTitle(g_Yname.c_str());

}

void dphiSI_DeltaMX3aMX3b_Cat1_hist::fill_hist( Selector * selector ){

  (hist2d->Get())->Fill((selector->dphiSI)[0], fabs((selector->MX3a)[0]-(selector->MX3b)[0]) , 137.0*(*(selector->weight)));

}
//--------------------------------------------------------------
class dphiSI_DeltaMX3aMX3b_Cat2_hist : public parentHistClass{

  public:
  void init_hist( string treeSubDir );
  void fill_hist( Selector * selector );

};

void dphiSI_DeltaMX3aMX3b_Cat2_hist::init_hist( string treeSubDir ){

  set_subdir(treeSubDir);

  string g_Xname = "#delta#phi(S,I)";
  double g_Xmin = 0.;
  double g_Xmax = 3.15;
  int    g_NX = 50;
  string g_Yname = "|MX3a-MX3b| [GeV]";
  double g_Ymin = 0.;
  double g_Ymax = 500.;
  int    g_NY = 50;

  hist2d = new ROOT::TThreadedObject<TH2D>("dphiSI_DeltaMX3aMX3b_Cat2_hist","dphiSI_DeltaMX3aMX3b_Cat2_hist", g_NX, g_Xmin, g_Xmax, g_NY, g_Ymin, g_Ymax);
  (hist2d->Get())->GetXaxis()->SetTitle(g_Xname.c_str());
  (hist2d->Get())->GetYaxis()->SetTitle(g_Yname.c_str());

}

void dphiSI_DeltaMX3aMX3b_Cat2_hist::fill_hist( Selector * selector ){

  (hist2d->Get())->Fill((selector->dphiSI)[1], fabs((selector->MX3a)[1]-(selector->MX3b)[1]) , 137.0*(*(selector->weight)));

}

//--------------------------------------------------------------
class RISR_v_PTISR_Cat2_hist : public parentHistClass{

  public:
  void init_hist( string treeSubDir );
  void fill_hist( Selector * selector );

};

void RISR_v_PTISR_Cat2_hist::init_hist( string treeSubDir ){

  set_subdir(treeSubDir);

  string g_Xname = "R_{ISR}";
  double g_Xmin = 0.;
  double g_Xmax = 2.;
  int    g_NX = 50;
  string g_Yname = "p_{T}^{ISR} [GeV]";
  double g_Ymin = 50.;
  double g_Ymax = 900.;
  int    g_NY = 50;

  hist2d = new ROOT::TThreadedObject<TH2D>("RISR_v_PTISR_Cat2_hist","RISR_v_PTISR_Cat2_hist", g_NX, g_Xmin, g_Xmax, g_NY, g_Ymin, g_Ymax);
  (hist2d->Get())->GetXaxis()->SetTitle(g_Xname.c_str());
  (hist2d->Get())->GetYaxis()->SetTitle(g_Yname.c_str());
 // std::cout << "In Init from testHistTheSecond !!" << std::endl;

}

void RISR_v_PTISR_Cat2_hist::fill_hist( Selector * selector ){

  (hist2d->Get())->Fill((selector->RISR)[1], (selector->PTISR)[1] , 137.0*(*(selector->weight)));

}
//---------------------------------------------------------------------------------
class RISR_v_PTISR_Cat1_hist : public parentHistClass{

  public:
  void init_hist( string treeSubDir );
  void fill_hist( Selector * selector );

};

void RISR_v_PTISR_Cat1_hist::init_hist( string treeSubDir ){

  set_subdir(treeSubDir);

  string g_Xname = "R_{ISR}";
  double g_Xmin = 0.;
  double g_Xmax = 2.;
  int    g_NX = 50;
  string g_Yname = "p_{T}^{ISR} [GeV]";
  double g_Ymin = 50.;
  double g_Ymax = 900.;
  int    g_NY = 50;

  hist2d = new ROOT::TThreadedObject<TH2D>("RISR_v_PTISR_Cat1_hist","RISR_v_PTISR_Cat1_hist", g_NX, g_Xmin, g_Xmax, g_NY, g_Ymin, g_Ymax);
  (hist2d->Get())->GetXaxis()->SetTitle(g_Xname.c_str());
  (hist2d->Get())->GetYaxis()->SetTitle(g_Yname.c_str());
 // std::cout << "In Init from testHistTheSecond !!" << std::endl;

}

void RISR_v_PTISR_Cat1_hist::fill_hist( Selector * selector ){

  (hist2d->Get())->Fill((selector->RISR)[0], (selector->PTISR)[0] , 137.0*(*(selector->weight)));

}
//------------------------------------------------------------------------------
class EVa_v_EVb_Cat1_hist : public parentHistClass{

  public:
  void init_hist( string treeSubDir );
  void fill_hist( Selector * selector );

};

void EVa_v_EVb_Cat1_hist::init_hist( string treeSubDir ){

  set_subdir(treeSubDir);

  string g_Xname = "EVa [GeV]";
  double g_Xmin = 0.;
  double g_Xmax = 150.;
  int    g_NX = 50;
  string g_Yname = "EVb [GeV]";
  double g_Ymin = 0.;
  double g_Ymax = 150.;
  int    g_NY = 50;

  hist2d = new ROOT::TThreadedObject<TH2D>("EVa_v_EVb_Cat1_hist","EVa_v_EVb_Cat1_hist", g_NX, g_Xmin, g_Xmax, g_NY, g_Ymin, g_Ymax);
  (hist2d->Get())->GetXaxis()->SetTitle(g_Xname.c_str());
  (hist2d->Get())->GetYaxis()->SetTitle(g_Yname.c_str());
 // std::cout << "In Init from testHistTheSecond !!" << std::endl;

}

void EVa_v_EVb_Cat1_hist::fill_hist( Selector * selector ){

  (hist2d->Get())->Fill((selector->EVa)[0], (selector->EVb)[0] , 137.0*(*(selector->weight)));

}
//------------------------------------------------------------------------------
class EVa_v_EVb_Cat2_hist : public parentHistClass{

  public:
  void init_hist( string treeSubDir );
  void fill_hist( Selector * selector );

};

void EVa_v_EVb_Cat2_hist::init_hist( string treeSubDir ){

  set_subdir(treeSubDir);

  string g_Xname = "EVa [GeV]";
  double g_Xmin = 0.;
  double g_Xmax = 150.;
  int    g_NX = 50;
  string g_Yname = "EVb [GeV]";
  double g_Ymin = 0.;
  double g_Ymax = 150.;
  int    g_NY = 50;

  hist2d = new ROOT::TThreadedObject<TH2D>("EVa_v_EVb_Cat2_hist","EVa_v_EVb_Cat2_hist", g_NX, g_Xmin, g_Xmax, g_NY, g_Ymin, g_Ymax);
  (hist2d->Get())->GetXaxis()->SetTitle(g_Xname.c_str());
  (hist2d->Get())->GetYaxis()->SetTitle(g_Yname.c_str());
 // std::cout << "In Init from testHistTheSecond !!" << std::endl;

}

void EVa_v_EVb_Cat2_hist::fill_hist( Selector * selector ){

  (hist2d->Get())->Fill((selector->EVa)[1], (selector->EVb)[1] , 137.0*(*(selector->weight)));

}
//----------------------------------------------------------------------------
class REVHist_Cat1 : public parentHistClass{

  public:
  void init_hist( string treeSubDir );
  void fill_hist( Selector* selector );

};

void REVHist_Cat1 ::init_hist( string treeSubDir ){

  set_subdir(treeSubDir);
  hist1d = new ROOT::TThreadedObject<TH1D>("REVHist_Cat1","REVHist_Cat1", 50, 0., 5.);
  (hist1d->Get())->GetXaxis()->SetTitle("#frac{EVa}{EVb}");
  (hist1d->Get())->GetYaxis()->SetTitle("");
 // std::cout << "In Init from risrHist !!" << std::endl;

}

void REVHist_Cat1 ::fill_hist( Selector* selector ){

  (hist1d->Get())->Fill((selector->EVa)[0]/(selector->EVb)[0], 137.0*(*(selector->weight)));

}
//----------------------------------------------------------------------------
class REVHist_Cat2 : public parentHistClass{

  public:
  void init_hist( string treeSubDir );
  void fill_hist( Selector* selector );

};

void REVHist_Cat2 ::init_hist( string treeSubDir ){

  set_subdir(treeSubDir);
  hist1d = new ROOT::TThreadedObject<TH1D>("REVHist_Cat2","REVHist_Cat2", 50, 0., 5.);
  (hist1d->Get())->GetXaxis()->SetTitle("#frac{EVa}{EVb}");
  (hist1d->Get())->GetYaxis()->SetTitle("");
 // std::cout << "In Init from risrHist !!" << std::endl;

}

void REVHist_Cat2 ::fill_hist( Selector* selector ){

  (hist1d->Get())->Fill((selector->EVa)[1]/(selector->EVb)[1], 137.0*(*(selector->weight)));

}
//------------------------------------------------------------------------------
class MX3a_v_MX3b_Cat1_hist : public parentHistClass{

  public:
  void init_hist( string treeSubDir );
  void fill_hist( Selector * selector );

};

void MX3a_v_MX3b_Cat1_hist::init_hist( string treeSubDir ){

  set_subdir(treeSubDir);

  string g_Xname = "MX3a [GeV]";
  double g_Xmin = 0.;
  double g_Xmax = 150.;
  int    g_NX = 50;
  string g_Yname = "MX3b [GeV]";
  double g_Ymin = 0.;
  double g_Ymax = 150.;
  int    g_NY = 50;

  hist2d = new ROOT::TThreadedObject<TH2D>("MX3a_v_MX3b_Cat1_hist","MX3a_v_MX3b_Cat1_hist", g_NX, g_Xmin, g_Xmax, g_NY, g_Ymin, g_Ymax);
  (hist2d->Get())->GetXaxis()->SetTitle(g_Xname.c_str());
  (hist2d->Get())->GetYaxis()->SetTitle(g_Yname.c_str());
 // std::cout << "In Init from testHistTheSecond !!" << std::endl;

}

void MX3a_v_MX3b_Cat1_hist::fill_hist( Selector * selector ){

  (hist2d->Get())->Fill((selector->MX3a)[0], (selector->MX3b)[0], 137.0*(*(selector->weight)));

}
//------------------------------------------------------------------------------
class MX3a_v_MX3b_Cat2_hist : public parentHistClass{

  public:
  void init_hist( string treeSubDir );
  void fill_hist( Selector * selector );

};

void MX3a_v_MX3b_Cat2_hist::init_hist( string treeSubDir ){

  set_subdir(treeSubDir);

  string g_Xname = "MX3a [GeV]";
  double g_Xmin = 0.;
  double g_Xmax = 150.;
  int    g_NX = 50;
  string g_Yname = "MX3b [GeV]";
  double g_Ymin = 0.;
  double g_Ymax = 150.;
  int    g_NY = 50;

  hist2d = new ROOT::TThreadedObject<TH2D>("MX3a_v_MX3b_Cat2_hist","MX3a_v_MX3b_Cat2_hist", g_NX, g_Xmin, g_Xmax, g_NY, g_Ymin, g_Ymax);
  (hist2d->Get())->GetXaxis()->SetTitle(g_Xname.c_str());
  (hist2d->Get())->GetYaxis()->SetTitle(g_Yname.c_str());
 // std::cout << "In Init from testHistTheSecond !!" << std::endl;

}

void MX3a_v_MX3b_Cat2_hist::fill_hist( Selector * selector ){

  (hist2d->Get())->Fill((selector->MX3a)[1], (selector->MX3b)[1] , 137.0*(*(selector->weight)));

}
//--------------------------------------------------------------
class dphiSI_MS_Cat1_hist : public parentHistClass{

  public:
  void init_hist( string treeSubDir );
  void fill_hist( Selector * selector );

};

void dphiSI_MS_Cat1_hist::init_hist( string treeSubDir ){

  set_subdir(treeSubDir);

  string g_Xname = "#delta#phi(S,I)";
  double g_Xmin = 0.;
  double g_Xmax = 3.15;
  int    g_NX = 50;
  string g_Yname = "MS [GeV]";
  double g_Ymin = 0.;
  double g_Ymax = 1000.;
  int    g_NY = 50;

  hist2d = new ROOT::TThreadedObject<TH2D>("dphiSI_MS_Cat1_hist","dphiSI_MS_Cat1_hist", g_NX, g_Xmin, g_Xmax, g_NY, g_Ymin, g_Ymax);
  (hist2d->Get())->GetXaxis()->SetTitle(g_Xname.c_str());
  (hist2d->Get())->GetYaxis()->SetTitle(g_Yname.c_str());

}

void dphiSI_MS_Cat1_hist::fill_hist( Selector * selector ){

  (hist2d->Get())->Fill((selector->dphiSI)[0], (selector->MS)[0] , 137.0*(*(selector->weight)));

}
//--------------------------------------------------------------
class dphiSI_MS_Cat2_hist : public parentHistClass{

  public:
  void init_hist( string treeSubDir );
  void fill_hist( Selector * selector );

};

void dphiSI_MS_Cat2_hist::init_hist( string treeSubDir ){

  set_subdir(treeSubDir);

  string g_Xname = "#delta#phi(S,I)";
  double g_Xmin = 0.;
  double g_Xmax = 3.15;
  int    g_NX = 50;
  string g_Yname = "MS [GeV]";
  double g_Ymin = 0.;
  double g_Ymax = 1000.;
  int    g_NY = 50;

  hist2d = new ROOT::TThreadedObject<TH2D>("dphiSI_MS_Cat2_hist","dphiSI_MS_Cat2_hist", g_NX, g_Xmin, g_Xmax, g_NY, g_Ymin, g_Ymax);
  (hist2d->Get())->GetXaxis()->SetTitle(g_Xname.c_str());
  (hist2d->Get())->GetYaxis()->SetTitle(g_Yname.c_str());

}

void dphiSI_MS_Cat2_hist::fill_hist( Selector * selector ){

  (hist2d->Get())->Fill((selector->dphiSI)[1], (selector->MS)[1] , 137.0*(*(selector->weight)));

}
//----------------------------------------------------------------------------
class PzSHist_Cat2 : public parentHistClass{

  public:
  void init_hist( string treeSubDir );
  void fill_hist( Selector* selector );
  
};

void PzSHist_Cat2::init_hist( string treeSubDir ){

  set_subdir(treeSubDir);
  hist1d = new ROOT::TThreadedObject<TH1D>("PzSHist_Cat2","PzS Cat 2", 50, 0, 1. );
  (hist1d->Get())->GetXaxis()->SetTitle("#frac{PzS}{PzS+MS}");
  (hist1d->Get())->GetYaxis()->SetTitle("Events/Bin");
 // std::cout << "In Init from dphiCMIHist !!" << std::endl;

}

void PzSHist_Cat2::fill_hist( Selector* selector ){

  (hist1d->Get())->Fill(fabs((selector->PzS)[1])/(fabs((selector->PzS)[1])+(selector->MS)[1]), 137.0*(*(selector->weight)));

}
//--------------------------------------------------------------
class dphiSI_PzS_Cat2_hist : public parentHistClass{

  public:
  void init_hist( string treeSubDir );
  void fill_hist( Selector * selector );

};

void dphiSI_PzS_Cat2_hist::init_hist( string treeSubDir ){

  set_subdir(treeSubDir);

  string g_Xname = "#delta#phi(S,I)";
  double g_Xmin = 0.;
  double g_Xmax = 3.15;
  int    g_NX = 50;
  string g_Yname = "#frac{PzS}{PzS+MS}";
  double g_Ymin = 0.;
  double g_Ymax = 1.;
  int    g_NY = 50;

  hist2d = new ROOT::TThreadedObject<TH2D>("dphiSI_PzS_Cat2_hist","dphiSI_PzS_Cat2_hist", g_NX, g_Xmin, g_Xmax, g_NY, g_Ymin, g_Ymax);
  (hist2d->Get())->GetXaxis()->SetTitle(g_Xname.c_str());
  (hist2d->Get())->GetYaxis()->SetTitle(g_Yname.c_str());

}

void dphiSI_PzS_Cat2_hist::fill_hist( Selector * selector ){

  (hist2d->Get())->Fill((selector->dphiSI)[1], fabs((selector->PzS)[1])/fabs(((selector->PzS)[1])+(selector->MS)[1]), 137.0*(*(selector->weight)));

}



//-------------------------------------------------------------------------------------------------------
//  make any global cuts for all histograms here.  Should return true to skip event.
//--------------------------------------------------------------------------------------------------------
bool histMaker::global_cuts( Selector * selector ){
  bool cut_sfos = true;
  if(*(selector->Nlep) == 2)
  {
   if(!((abs((selector->PDGID_lep)[0]) == abs((selector->PDGID_lep)[1]) ) && ((selector->Charge_lep)[0] != (selector->Charge_lep)[1])))
   {
    if((selector->PTISR)[1] > 150. && (selector->RISR)[1] < 1.2 && (selector->RISR)[1] > 0.6 && (selector->PTCM)[1] < 150. )//&& (selector->Njet_S)[1] == 0)
    {
     cut_sfos = false;
    }
   }
  }
  return cut_sfos;
}
//---------------------------------------------------------------------------------------------------------
//  loads histograms to be filled, add to new histogram to be run to the hist class vector as shown below.
//--------------------------------------------------------------------------------------------------------
vector< parentHistClass * > histMaker::hist_vector_loader( string treeSubDir ){
 
  vector< parentHistClass *  > vhistclasses;
  //vhistclasses.push_back( new testHistTheFirst );
  //vhistclasses.push_back( new testHistTheSecond );
  //   <--------------------------------------   add new hist classes here
  vhistclasses.push_back( new RISR_v_PTISR_Cat2_hist );
  //vhistclasses.push_back( new RISR_v_PTISR_Cat1_hist );
  vhistclasses.push_back( new metHist );
  vhistclasses.push_back( new flavorHist );
  vhistclasses.push_back( new mllHist );
  vhistclasses.push_back( new njetsHist );
  //vhistclasses.push_back( new ptcmHist_Cat1 );
  //vhistclasses.push_back( new ptisrHist_Cat1 );
  //vhistclasses.push_back( new risrHist_Cat1 );
  //vhistclasses.push_back( new dphiCMIHist_Cat1 );
  vhistclasses.push_back( new ptcmHist_Cat2 );
  vhistclasses.push_back( new ptisrHist_Cat2 );
  vhistclasses.push_back( new risrHist_Cat2 );
  vhistclasses.push_back( new dphiCMIHist_Cat2 );
  vhistclasses.push_back( new dphiSIHist_Cat2 );
  //vhistclasses.push_back( new dphiSI_DeltaMX3aMX3b_Cat1_hist );
  vhistclasses.push_back( new dphiSI_DeltaMX3aMX3b_Cat2_hist );
  //vhistclasses.push_back( new EVa_v_EVb_Cat1_hist );
  vhistclasses.push_back( new EVa_v_EVb_Cat2_hist );
  //vhistclasses.push_back( new MX3a_v_MX3b_Cat1_hist );
  vhistclasses.push_back( new MX3a_v_MX3b_Cat2_hist );
  //vhistclasses.push_back( new dphiSI_MS_Cat1_hist );
  vhistclasses.push_back( new dphiSI_MS_Cat2_hist );
  //vhistclasses.push_back( new REVHist_Cat1 );
  vhistclasses.push_back( new REVHist_Cat2 );
  vhistclasses.push_back( new PzSHist_Cat2 );
  vhistclasses.push_back( new dphiSI_PzS_Cat2_hist );

  for( auto histclass : vhistclasses ){ histclass->init_hist( treeSubDir ); }

  return vhistclasses;
 
}
//----------------------------------------------------------------------------

