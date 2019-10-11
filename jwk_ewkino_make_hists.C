//
//  Jack W King III 2019
//

#include "jwk_ewkino_define_hists.h"

///-------------- String declarations-------------------------------------------------------------------------

const string BkgTree_KUAnalysis = "KUAnalysis";

const string fall17_TTJets_SubDir = "TTJets";
vector<string> load_gFileVec_TChiWW_Bkg_TTJets(){
  vector<string> g_FileVec;
  g_FileVec.push_back("Fall17_94X/TTGJets_TuneCP5_13TeV-amcatnloFXFX-madspin-pythia8_Fall17_94X.root");
  g_FileVec.push_back("Fall17_94X/TTJets_DiLept_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17_94X.root");
  g_FileVec.push_back("Fall17_94X/TTJets_SingleLeptFromT_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17_94X.root");
  g_FileVec.push_back("Fall17_94X/TTJets_SingleLeptFromTbar_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17_94X.root");
  return g_FileVec;
}

const string fall17_Bkg_WJets_SubDir = "WJets";
vector<string> load_gFileVec_TChiWW_Bkg_WJets(){
  vector<string> g_FileVec;
  g_FileVec.push_back("Fall17_94X/WJetsToLNu_HT-100To200_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17_94X.root");
  g_FileVec.push_back("Fall17_94X/WJetsToLNu_HT-1200To2500_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17_94X.root");
  g_FileVec.push_back("Fall17_94X/WJetsToLNu_HT-200To400_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17_94X.root");
  g_FileVec.push_back("Fall17_94X/WJetsToLNu_HT-400To600_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17_94X.root");
  g_FileVec.push_back("Fall17_94X/WJetsToLNu_HT-600To800_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17_94X.root");
  g_FileVec.push_back("Fall17_94X/WJetsToLNu_HT-800To1200_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17_94X.root");
  return g_FileVec;
}

const string fall17_Bkg_ST_SubDir = "ST";
vector<string> load_gFileVec_TChiWW_Bkg_ST(){
  vector<string> g_FileVec;
  g_FileVec.push_back("Fall17_94X/ST_s-channel_4f_leptonDecays_TuneCP5_13TeV-amcatnlo-pythia8_Fall17_94X.root");
  g_FileVec.push_back("Fall17_94X/ST_t-channel_antitop_4f_inclusiveDecays_TuneCP5_13TeV-powhegV2-madspin-pythia8_Fall17_94X.root");
  g_FileVec.push_back("Fall17_94X/ST_t-channel_top_4f_inclusiveDecays_TuneCP5_13TeV-powhegV2-madspin-pythia8_Fall17_94X.root");
  g_FileVec.push_back("Fall17_94X/ST_tW_antitop_5f_NoFullyHadronicDecays_TuneCP5_13TeV-powheg-pythia8_Fall17_94X.root");
  g_FileVec.push_back("Fall17_94X/ST_tW_antitop_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8_Fall17_94X.root");
  g_FileVec.push_back("Fall17_94X/ST_tW_top_5f_NoFullyHadronicDecays_TuneCP5_13TeV-powheg-pythia8_Fall17_94X.root");
  return g_FileVec;
}

const string fall17_Bkg_DY_SubDir = "DYJetsToLL";
vector<string> load_gFileVec_TChiWW_Bkg_DY(){
  vector<string> g_FileVec;
  //g_FileVec.push_back("Fall17_94X/DYJetsToLL_M-4to50_HT-100to200_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17_94X.root");
  //g_FileVec.push_back("Fall17_94X/DYJetsToLL_M-4to50_HT-200to400_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17_94X.root");
  //g_FileVec.push_back("Fall17_94X/DYJetsToLL_M-4to50_HT-400to600_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17_94X.root");
  //g_FileVec.push_back("Fall17_94X/DYJetsToLL_M-4to50_HT-600toInf_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17_94X.root");
  g_FileVec.push_back("Fall17_94X/DYJetsToLL_M-50_HT-100to200_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17_94X.root");
  g_FileVec.push_back("Fall17_94X/DYJetsToLL_M-50_HT-1200to2500_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17_94X.root");
  g_FileVec.push_back("Fall17_94X/DYJetsToLL_M-50_HT-200to400_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17_94X.root");
  g_FileVec.push_back("Fall17_94X/DYJetsToLL_M-50_HT-2500toInf_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17_94X.root");
  g_FileVec.push_back("Fall17_94X/DYJetsToLL_M-50_HT-400to600_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17_94X.root");
  g_FileVec.push_back("Fall17_94X/DYJetsToLL_M-50_HT-600to800_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17_94X.root");
  g_FileVec.push_back("Fall17_94X/DYJetsToLL_M-50_HT-70to100_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17_94X.root");
  g_FileVec.push_back("Fall17_94X/DYJetsToLL_M-50_HT-800to1200_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17_94X.root");
  return g_FileVec;
}

const string fall17_Bkg_DiBoson_SubDir = "DiBoson";
vector<string> load_gFileVec_TChiWW_Bkg_DiBoson(){
  vector<string> g_FileVec;
  g_FileVec.push_back("Fall17_94X/WWTo2L2Nu_NNPDF31_TuneCP5_13TeV-powheg-pythia8_Fall17_94X.root");
  g_FileVec.push_back("Fall17_94X/WWTo4Q_NNPDF31_TuneCP5_13TeV-powheg-pythia8_Fall17_94X.root");
  g_FileVec.push_back("Fall17_94X/WWToLNuQQ_NNPDF31_TuneCP5_13TeV-powheg-pythia8_Fall17_94X.root");
  g_FileVec.push_back("Fall17_94X/WZTo1L1Nu2Q_13TeV_amcatnloFXFX_madspin_pythia8_Fall17_94X.root");
  g_FileVec.push_back("Fall17_94X/WZTo3LNu_TuneCP5_13TeV-amcatnloFXFX-pythia8_Fall17_94X.root");
  g_FileVec.push_back("Fall17_94X/ZZTo2L2Nu_13TeV_powheg_pythia8_Fall17_94X.root");
  g_FileVec.push_back("Fall17_94X/ZZTo2L2Q_13TeV_amcatnloFXFX_madspin_pythia8_Fall17_94X.root");
  g_FileVec.push_back("Fall17_94X/ZZTo2Q2Nu_TuneCP5_13TeV_amcatnloFXFX_madspin_pythia8_Fall17_94X.root");
  g_FileVec.push_back("Fall17_94X/ZZTo4L_13TeV_powheg_pythia8_Fall17_94X.root");
  return g_FileVec;
}

const string fall17_Bkg_SubDir = "Bkg";
vector<string> load_gFileVec_TChiWW_Bkg(){
  vector<string> g_FileVec;
  g_FileVec.push_back("Fall17_94X/WWTo2L2Nu_NNPDF31_TuneCP5_13TeV-powheg-pythia8_Fall17_94X.root");
  g_FileVec.push_back("Fall17_94X/WWTo4Q_NNPDF31_TuneCP5_13TeV-powheg-pythia8_Fall17_94X.root");
  g_FileVec.push_back("Fall17_94X/WWToLNuQQ_NNPDF31_TuneCP5_13TeV-powheg-pythia8_Fall17_94X.root");
  g_FileVec.push_back("Fall17_94X/WZTo1L1Nu2Q_13TeV_amcatnloFXFX_madspin_pythia8_Fall17_94X.root");
  g_FileVec.push_back("Fall17_94X/WZTo3LNu_TuneCP5_13TeV-amcatnloFXFX-pythia8_Fall17_94X.root");
  g_FileVec.push_back("Fall17_94X/ZZTo2L2Nu_13TeV_powheg_pythia8_Fall17_94X.root");
  g_FileVec.push_back("Fall17_94X/ZZTo2L2Q_13TeV_amcatnloFXFX_madspin_pythia8_Fall17_94X.root");
  g_FileVec.push_back("Fall17_94X/ZZTo2Q2Nu_TuneCP5_13TeV_amcatnloFXFX_madspin_pythia8_Fall17_94X.root");
  g_FileVec.push_back("Fall17_94X/ZZTo4L_13TeV_powheg_pythia8_Fall17_94X.root");
  g_FileVec.push_back("Fall17_94X/ST_s-channel_4f_leptonDecays_TuneCP5_13TeV-amcatnlo-pythia8_Fall17_94X.root");
  g_FileVec.push_back("Fall17_94X/ST_t-channel_antitop_4f_inclusiveDecays_TuneCP5_13TeV-powhegV2-madspin-pythia8_Fall17_94X.root");
  g_FileVec.push_back("Fall17_94X/ST_t-channel_top_4f_inclusiveDecays_TuneCP5_13TeV-powhegV2-madspin-pythia8_Fall17_94X.root");
  g_FileVec.push_back("Fall17_94X/ST_tW_antitop_5f_NoFullyHadronicDecays_TuneCP5_13TeV-powheg-pythia8_Fall17_94X.root");
  g_FileVec.push_back("Fall17_94X/ST_tW_antitop_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8_Fall17_94X.root");
  g_FileVec.push_back("Fall17_94X/ST_tW_top_5f_NoFullyHadronicDecays_TuneCP5_13TeV-powheg-pythia8_Fall17_94X.root");
  g_FileVec.push_back("Fall17_94X/WJetsToLNu_HT-100To200_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17_94X.root");
  g_FileVec.push_back("Fall17_94X/WJetsToLNu_HT-1200To2500_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17_94X.root");
  g_FileVec.push_back("Fall17_94X/WJetsToLNu_HT-200To400_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17_94X.root");
  g_FileVec.push_back("Fall17_94X/WJetsToLNu_HT-400To600_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17_94X.root");
  g_FileVec.push_back("Fall17_94X/WJetsToLNu_HT-600To800_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17_94X.root");
  g_FileVec.push_back("Fall17_94X/WJetsToLNu_HT-800To1200_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17_94X.root");
  g_FileVec.push_back("Fall17_94X/TTGJets_TuneCP5_13TeV-amcatnloFXFX-madspin-pythia8_Fall17_94X.root");
  g_FileVec.push_back("Fall17_94X/TTJets_DiLept_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17_94X.root");
  g_FileVec.push_back("Fall17_94X/TTJets_SingleLeptFromT_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17_94X.root");
  g_FileVec.push_back("Fall17_94X/TTJets_SingleLeptFromTbar_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17_94X.root");
  //g_FileVec.push_back("Fall17_94X/DYJetsToLL_M-4to50_HT-100to200_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17_94X.root");
  //g_FileVec.push_back("Fall17_94X/DYJetsToLL_M-4to50_HT-200to400_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17_94X.root");
  //g_FileVec.push_back("Fall17_94X/DYJetsToLL_M-4to50_HT-400to600_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17_94X.root");
  //g_FileVec.push_back("Fall17_94X/DYJetsToLL_M-4to50_HT-600toInf_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17_94X.root");
  g_FileVec.push_back("Fall17_94X/DYJetsToLL_M-50_HT-100to200_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17_94X.root");
  g_FileVec.push_back("Fall17_94X/DYJetsToLL_M-50_HT-1200to2500_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17_94X.root");
  g_FileVec.push_back("Fall17_94X/DYJetsToLL_M-50_HT-200to400_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17_94X.root");
  g_FileVec.push_back("Fall17_94X/DYJetsToLL_M-50_HT-2500toInf_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17_94X.root");
  g_FileVec.push_back("Fall17_94X/DYJetsToLL_M-50_HT-400to600_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17_94X.root");
  g_FileVec.push_back("Fall17_94X/DYJetsToLL_M-50_HT-600to800_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17_94X.root");
  g_FileVec.push_back("Fall17_94X/DYJetsToLL_M-50_HT-70to100_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17_94X.root");
  g_FileVec.push_back("Fall17_94X/DYJetsToLL_M-50_HT-800to1200_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17_94X.root");
  return g_FileVec;
}

const string fall17_TChiWW = "Fall17_94X_SMS/SMS-TChipmWW_WWTo2LNu_TuneCP2_13TeV-madgraphMLM-pythia8_Fall17_94X.root";

const string SigTree_SMS_275_235 = "SMS_275_235";

const string fall17_TChiWW_SMS_275_235_SubDir =  "TChiWW_SMS_275_235";

const string g_Path = "/home/t3-ku/crogan/NTUPLES/NANO/";

//----------------------------------------------------------
//  Create TFile and TFile SubDirectories
//---------------------------------------------------------
TFile * makeTFile( string outfile_name ){

  auto outfile = new TFile( outfile_name.c_str(), "UPDATE" );
  outfile->cd();
  make_subdir( outfile, fall17_TTJets_SubDir.c_str() );
  make_subdir( outfile, fall17_Bkg_DiBoson_SubDir.c_str() );
  make_subdir( outfile, fall17_Bkg_DY_SubDir.c_str() );
  make_subdir( outfile, fall17_Bkg_ST_SubDir.c_str() );
  make_subdir( outfile, fall17_Bkg_SubDir.c_str() );
  make_subdir( outfile, fall17_TChiWW_SMS_275_235_SubDir.c_str() );
  return outfile;
}
//-------------------------------------------------------------------------------------------------------
//  Functions called to substantiate and run the hist maker class
//-------------------------------------------------------------------------------------------------------
void run_hist_maker( string treename, vector<string> g_FileVec, string outfile_name, string treeSubDir )
{ 
  std::cout << "Running over " << treename << " in: "  << std::endl;
  for( auto gfile : g_FileVec ){ std::cout << gfile << std::endl; }
  std::cout << "Writing to " << outfile_name << "/" << treeSubDir << std::endl;
  histMaker hist_maker; 
  auto tfile = makeTFile(outfile_name);
  hist_maker.make_hists( g_Path, g_FileVec, treename, tfile, treeSubDir );
  tfile->Close();
  std::cout << "Finished" << std::endl;
}
void run_hist_maker( string treename, string g_FileName, string outfile_name, string treeSubDir )
{
  std::cout << "Running over " << treename << " in: "  << std::endl;
  std::cout << g_FileName << std::endl;
  std::cout << "Writing to " << outfile_name << "/" << treeSubDir << std::endl;
  histMaker hist_maker;
  auto tfile = makeTFile(outfile_name);
  hist_maker.make_hists( g_Path, g_FileName, treename, tfile, treeSubDir );
  tfile->Close();
  std::cout << "Finished" << std::endl;
}
//-------------------------------------------------------------------------------------------------------
//Root Macro to run histogram jobs
//--------------------------------------------------------------------------------------------------------

void jwk_ewkino_make_hists(string NotOSSFTFile = "KUEwkino_2017_ll_NotOSSF_hists.root"){
  ROOT::EnableImplicitMT(8);
  ROOT::EnableThreadSafety();
//--------BackGrounds
  run_hist_maker( BkgTree_KUAnalysis, load_gFileVec_TChiWW_Bkg(), NotOSSFTFile, fall17_Bkg_SubDir );
  run_hist_maker( BkgTree_KUAnalysis, load_gFileVec_TChiWW_Bkg_DiBoson(), NotOSSFTFile, fall17_Bkg_DiBoson_SubDir );
  run_hist_maker( BkgTree_KUAnalysis, load_gFileVec_TChiWW_Bkg_DY(), NotOSSFTFile, fall17_Bkg_DY_SubDir );
  run_hist_maker( BkgTree_KUAnalysis, load_gFileVec_TChiWW_Bkg_WJets(), NotOSSFTFile, fall17_Bkg_WJets_SubDir );
  run_hist_maker( BkgTree_KUAnalysis, load_gFileVec_TChiWW_Bkg_ST(), NotOSSFTFile, fall17_Bkg_ST_SubDir );
  run_hist_maker( BkgTree_KUAnalysis, load_gFileVec_TChiWW_Bkg_TTJets(), NotOSSFTFile, fall17_TTJets_SubDir );

//--------Signals
  run_hist_maker( SigTree_SMS_275_235, fall17_TChiWW, NotOSSFTFile, fall17_TChiWW_SMS_275_235_SubDir );
}


