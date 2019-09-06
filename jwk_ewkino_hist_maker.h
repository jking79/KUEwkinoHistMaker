//
//  Jack W King III  2019
//

#include <iostream>
#include <string>

#include <TFile.h>
#include <TTree.h>
#include <TBranch.h>
#include <TGraph.h>
#include <TMultiGraph.h>
#include <TAxis.h>
#include <TCanvas.h>
#include <TMath.h>
#include <TLegend.h>
#include <TLatex.h>
#include <TH2.h>
#include "ROOT/TTreeProcessorMT.hxx"
#include "ROOT/TProcessExecutor.hxx"
#include "ROOT/TTreeProcessorMP.hxx"
#include "TInterpreter.h"
#include "ROOT/TThreadedObject.hxx"
#include "TTreeReader.h"
#include "TTreeReaderValue.h"
#include <TStyle.h>

#include "jwk_ku_tdr_style.h"
#include "Selector.h"

using namespace std;

//-----------------  helper function  -----------------------------------------
TDirectory* make_subdir( TFile* outfile, string subdir ){

  outfile->cd();
  TDirectory* fileSubDir = nullptr;
  if( subdir != ""){
        fileSubDir = outfile->GetDirectory(subdir.c_str());
        if( fileSubDir == 0 ){
                outfile->mkdir( subdir.c_str() );
                fileSubDir = outfile->GetDirectory(subdir.c_str());
        }
  }
  return fileSubDir;
}
//-----------------------------------------------------------------------------
////////////////////////////////////////////////////////////////////////////////
class parentHistClass{

  public:

  parentHistClass();
  ~parentHistClass();

  virtual void init_hist(  string treeSubDir );	
  virtual void fill_hist( Selector * selector );
  virtual void write_hist( TFile * outfile );
  void set_subdir( string name ){ subdir = name; }

  protected:

  string subdir;

  ROOT::TThreadedObject < TH1F > * hist1f;
  ROOT::TThreadedObject < TH2F > * hist2f;
  ROOT::TThreadedObject < TH1D > * hist1d;
  ROOT::TThreadedObject < TH2D > * hist2d;

};
////////////////////////////////////////////////////////////////
parentHistClass::parentHistClass(){

  hist1f = NULL;
  hist2f = NULL;
  hist1d = NULL;
  hist2d = NULL;

  subdir = "";

}

parentHistClass::~parentHistClass(){

  if( hist1f ) delete hist1f;
  if( hist2f ) delete hist2f;
  if( hist1d ) delete hist1d;
  if( hist2d ) delete hist2d;

}

void parentHistClass::write_hist( TFile* outfile ){

  //outfile->cd();
  auto fileSubDir = make_subdir( outfile, subdir );
  //fileSubDir->cd();

  if( hist1f ) { auto temphist = (TH1F*)(hist1f->Merge())->Clone(); fileSubDir->WriteObject( temphist, temphist->GetName() ); } 
  if( hist2f ) { auto temphist = (TH2F*)(hist2f->Merge())->Clone(); fileSubDir->WriteObject( temphist, temphist->GetName() ); } 
  if( hist1d ) { auto temphist = (TH1D*)(hist1d->Merge())->Clone(); fileSubDir->WriteObject( temphist, temphist->GetName() ); } 
  if( hist2d ) { auto temphist = (TH2D*)(hist2d->Merge())->Clone(); fileSubDir->WriteObject( temphist, temphist->GetName() ); } 

}

void parentHistClass::init_hist( string treeSubDir ){

  //set_subdir( treeSubDir );
  // hist1d = new TH1D("parentHistClass","selectorHistClass", 2, -0.5, 1.5 );
  std::cout << "In Init from BaseClass !" << std::endl;
}

void parentHistClass::fill_hist( Selector* selector ){

  //hist1d->Fill(1.0);
  std::cout << "Filling from BaseClass !" << std::endl;

}
//--------------------------------------------------------------------------------
/////////////////////////////////    maker class that loops over events
class histMaker{

	public:
	vector< parentHistClass * > hist_vector_loader( string treeSubDir );
	bool global_cuts( Selector * selector );
	void make_hists( string g_Path, vector<string> g_FileVec, string treeName,  TFile * outfile, string treeSubDir );
        void make_hists( string g_Path, string g_FileName, string treeName,  TFile * outfile, string treeSubDir );

};

void histMaker::make_hists( string g_Path, string g_FileName, string treeName,  TFile * outfile, string treeSubDir ){

	vector< string > g_FileVec;
	g_FileVec.push_back( g_FileName );
	histMaker::make_hists( g_Path, g_FileVec, treeName, outfile, treeSubDir );
}

void histMaker::make_hists( string g_Path, vector<string> g_FileVec, string treeName,  TFile * outfile, string treeSubDir ){

  setTDRStyle(false); //true/false is related to trying a "dark" theme for plots
  //setup the hist classes with the proper subdirectories
  const auto vhistclasses = hist_vector_loader( treeSubDir );
  //make the chain to be fed into the multithreader (MT)
  TChain* chain = new TChain( treeName.c_str() );
  for( int s = 0; s < int(g_FileVec.size()); s++ ){ chain->Add( ( g_Path + g_FileVec[s] ).c_str() ); } 
  ROOT::TTreeProcessorMT TreeProcessorMT(*chain); //pass the chain to the MT processor
  //setup a function for what the threads will be doing
  auto ReaderFunction = [&](TTreeReader &reader) { 
   Selector * selector = new Selector();
   selector->Init( reader.GetTree() );
   while ( reader.Next() )
   {
    selector->fReader.SetEntry(reader.GetCurrentEntry());
    //used to skip any events that do not meet a requirement (like MET > 200 GeV)
    if( global_cuts( selector ) ) continue;
    for( auto histclass : vhistclasses ){ histclass->fill_hist( selector ); }
   }
   delete selector;
  };
  //Tells the MT Processor to run our function
  TreeProcessorMT.Process(ReaderFunction); 
  //writes the output of the histograms to a file
  for( auto histclass : vhistclasses ){ histclass->write_hist( outfile ); delete histclass; }
  delete chain;
  /*
  /////////////////////////////////////////////////////////
  // Testing Multicore Implementation
  TChain* chain = new TChain( treeName.c_str() );
  for( int s = 0; s < int(g_FileVec.size()); s++ ){ chain->Add( ( g_Path + g_FileVec[s] ).c_str() ); } 
  const auto nFiles = chain->GetListOfFiles()->GetEntries();
  const auto vhistclasses = hist_vector_loader( treeSubDir );
  auto workItem = [&](TTreeReader &reader) {  
   //ROOT::TTreeProcessorMT TreeProcessorMT(*chain); //pass the chain to the MT processor
   //TreeProcessorMT.Process(ReaderFunction); 
   //writes the output of the histograms to a file
   
   for( auto histclass : vhistclasses ){ histclass->write_hist( outfile ); delete histclass; }
  };  
  ROOT::TTreeProcessorMP workers(nFiles);
  workers.Process(workItem);
  //for( auto histclass : vhistclasses ){ histclass->write_hist( outfile ); delete histclass; }
  delete chain;
  /////////////////////////////////////////////////////////
  */
}

/////////////////////////////////////////////////////////////




