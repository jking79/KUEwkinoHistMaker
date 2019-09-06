//
//  Jack W King III 2019
//

#include "jwk_ewkino_define_hists.h"

///-------------- String declarations-------------------------------------------------------------------------

const string BkgTree_KUAnalysis = "KUAnalysis";

const string fall17_TTJets_SubDir = "TTJets";
vector<string> load_gFileVec_TChiWZ_Bkg_TTJets(){
  vector<string> g_FileVec;
  g_FileVec.push_back("All_Bkg_2017/TTJets_TuneCP5_13TeV-madgraphMLM-pythia8_TuneCP5.root");
  return g_FileVec;
}

const string fall17_Bkg_WJets_SubDir = "WJets";
vector<string> load_gFileVec_TChiWZ_Bkg_WJets(){
  vector<string> g_FileVec;
  g_FileVec.push_back("All_Bkg_2017/WJetsToLNu_HT-100To200_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17.root");
  g_FileVec.push_back("All_Bkg_2017/WJetsToLNu_HT-1200To2500_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17.root");
  g_FileVec.push_back("All_Bkg_2017/WJetsToLNu_HT-200To400_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17.root");
  g_FileVec.push_back("All_Bkg_2017/WJetsToLNu_HT-400To600_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17.root");
  g_FileVec.push_back("All_Bkg_2017/WJetsToLNu_HT-600To800_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17.root");
  g_FileVec.push_back("All_Bkg_2017/WJetsToLNu_HT-800To1200_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17.root");
  return g_FileVec;
}

const string fall17_Bkg_ST_SubDir = "ST";
vector<string> load_gFileVec_TChiWZ_Bkg_ST(){
  vector<string> g_FileVec;
  g_FileVec.push_back("All_Bkg_2017/ST_s-channel_4f_leptonDecays_TuneCP5_13TeV-amcatnlo-pythia8_Fall17.root");
  //g_FileVec.push_back("All_Bkg_2017/ST_t-channel_antitop_5f_TuneCP5_PSweights_13TeV-powheg-pythia8_Fall17.root");
  g_FileVec.push_back("All_Bkg_2017/ST_t-channel_top_5f_TuneCP5_13TeV-powheg-pythia8_Fall17.root");
  g_FileVec.push_back("All_Bkg_2017/ST_tW_antitop_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8_Fall17.root");
  g_FileVec.push_back("All_Bkg_2017/ST_tW_top_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8_Fall17.root");
  return g_FileVec;
}

const string fall17_Bkg_DY_SubDir = "DYJetsToLL";
vector<string> load_gFileVec_TChiWZ_Bkg_DY(){
  vector<string> g_FileVec;
  g_FileVec.push_back("All_Bkg_2017/DYJetsToLL_M-4to50_HT-100to200_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17.root");
  g_FileVec.push_back("All_Bkg_2017/DYJetsToLL_M-4to50_HT-200to400_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17.root");
  g_FileVec.push_back("All_Bkg_2017/DYJetsToLL_M-4to50_HT-400to600_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17.root");
  g_FileVec.push_back("All_Bkg_2017/DYJetsToLL_M-4to50_HT-600toInf_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17.root");
  g_FileVec.push_back("All_Bkg_2017/DYJetsToLL_M-50_HT-100to200_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17.root");
  g_FileVec.push_back("All_Bkg_2017/DYJetsToLL_M-50_HT-1200to2500_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17.root");
  g_FileVec.push_back("All_Bkg_2017/DYJetsToLL_M-50_HT-200to400_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17.root");
  g_FileVec.push_back("All_Bkg_2017/DYJetsToLL_M-50_HT-2500toInf_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17.root");
  g_FileVec.push_back("All_Bkg_2017/DYJetsToLL_M-50_HT-400to600_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17.root");
  g_FileVec.push_back("All_Bkg_2017/DYJetsToLL_M-50_HT-600to800_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17.root");
  g_FileVec.push_back("All_Bkg_2017/DYJetsToLL_M-50_HT-70to100_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17.root");
  g_FileVec.push_back("All_Bkg_2017/DYJetsToLL_M-50_HT-800to1200_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17.root");
  return g_FileVec;
}

const string fall17_Bkg_DiBoson_SubDir = "DiBoson";
vector<string> load_gFileVec_TChiWZ_Bkg_DiBoson(){
  vector<string> g_FileVec;
  g_FileVec.push_back("All_Bkg_2017/WWTo2L2Nu_NNPDF31_TuneCP5_13TeV-powheg-pythia8_Fall17.root");
  g_FileVec.push_back("All_Bkg_2017/WWTo4Q_NNPDF31_TuneCP5_13TeV-powheg-pythia8_Fall17.root");
  g_FileVec.push_back("All_Bkg_2017/WWToLNuQQ_NNPDF31_TuneCP5_13TeV-powheg-pythia8_Fall17.root");
  g_FileVec.push_back("All_Bkg_2017/WZTo1L1Nu2Q_13TeV_amcatnloFXFX_madspin_pythia8_Fall17.root");
  g_FileVec.push_back("All_Bkg_2017/WZTo3LNu_TuneCP5_13TeV-amcatnloFXFX-pythia8_Fall17.root");
  g_FileVec.push_back("All_Bkg_2017/ZZTo2L2Nu_13TeV_powheg_pythia8_Fall17.root");
  g_FileVec.push_back("All_Bkg_2017/ZZTo2L2Q_13TeV_amcatnloFXFX_madspin_pythia8_Fall17.root");
  g_FileVec.push_back("All_Bkg_2017/ZZTo2Q2Nu_TuneCP5_13TeV_amcatnloFXFX_madspin_pythia8_Fall17.root");
  g_FileVec.push_back("All_Bkg_2017/ZZTo4L_13TeV_powheg_pythia8_Fall17.root");
  return g_FileVec;
}

const string fall17_Bkg_SubDir = "Bkg";
vector<string> load_gFileVec_TChiWZ_Bkg(){
  vector<string> g_FileVec;
  g_FileVec.push_back("All_Bkg_2017/WWTo2L2Nu_NNPDF31_TuneCP5_13TeV-powheg-pythia8_Fall17.root");
  g_FileVec.push_back("All_Bkg_2017/WWTo4Q_NNPDF31_TuneCP5_13TeV-powheg-pythia8_Fall17.root");
  g_FileVec.push_back("All_Bkg_2017/WWToLNuQQ_NNPDF31_TuneCP5_13TeV-powheg-pythia8_Fall17.root");
  g_FileVec.push_back("All_Bkg_2017/WZTo1L1Nu2Q_13TeV_amcatnloFXFX_madspin_pythia8_Fall17.root");
  g_FileVec.push_back("All_Bkg_2017/WZTo3LNu_TuneCP5_13TeV-amcatnloFXFX-pythia8_Fall17.root");
  g_FileVec.push_back("All_Bkg_2017/ZZTo2L2Nu_13TeV_powheg_pythia8_Fall17.root");
  g_FileVec.push_back("All_Bkg_2017/ZZTo2L2Q_13TeV_amcatnloFXFX_madspin_pythia8_Fall17.root");
  g_FileVec.push_back("All_Bkg_2017/ZZTo2Q2Nu_TuneCP5_13TeV_amcatnloFXFX_madspin_pythia8_Fall17.root");
  g_FileVec.push_back("All_Bkg_2017/ZZTo4L_13TeV_powheg_pythia8_Fall17.root");
  g_FileVec.push_back("All_Bkg_2017/TTJets_TuneCP5_13TeV-madgraphMLM-pythia8_TuneCP5.root");
  g_FileVec.push_back("All_Bkg_2017/WJetsToLNu_HT-100To200_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17.root");
  g_FileVec.push_back("All_Bkg_2017/WJetsToLNu_HT-1200To2500_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17.root");
  g_FileVec.push_back("All_Bkg_2017/WJetsToLNu_HT-200To400_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17.root");
  g_FileVec.push_back("All_Bkg_2017/WJetsToLNu_HT-400To600_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17.root");
  g_FileVec.push_back("All_Bkg_2017/WJetsToLNu_HT-600To800_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17.root");
  g_FileVec.push_back("All_Bkg_2017/WJetsToLNu_HT-800To1200_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17.root");
  g_FileVec.push_back("All_Bkg_2017/ST_s-channel_4f_leptonDecays_TuneCP5_13TeV-amcatnlo-pythia8_Fall17.root");
  //g_FileVec.push_back("All_Bkg_2017/ST_t-channel_antitop_5f_TuneCP5_PSweights_13TeV-powheg-pythia8_Fall17.root");
  g_FileVec.push_back("All_Bkg_2017/ST_t-channel_top_5f_TuneCP5_13TeV-powheg-pythia8_Fall17.root");
  g_FileVec.push_back("All_Bkg_2017/ST_tW_antitop_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8_Fall17.root");
  g_FileVec.push_back("All_Bkg_2017/ST_tW_top_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8_Fall17.root");
  g_FileVec.push_back("All_Bkg_2017/DYJetsToLL_M-4to50_HT-100to200_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17.root");
  g_FileVec.push_back("All_Bkg_2017/DYJetsToLL_M-4to50_HT-200to400_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17.root");
  g_FileVec.push_back("All_Bkg_2017/DYJetsToLL_M-4to50_HT-400to600_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17.root");
  g_FileVec.push_back("All_Bkg_2017/DYJetsToLL_M-4to50_HT-600toInf_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17.root");
  g_FileVec.push_back("All_Bkg_2017/DYJetsToLL_M-50_HT-100to200_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17.root");
  g_FileVec.push_back("All_Bkg_2017/DYJetsToLL_M-50_HT-1200to2500_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17.root");
  g_FileVec.push_back("All_Bkg_2017/DYJetsToLL_M-50_HT-200to400_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17.root");
  g_FileVec.push_back("All_Bkg_2017/DYJetsToLL_M-50_HT-2500toInf_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17.root");
  g_FileVec.push_back("All_Bkg_2017/DYJetsToLL_M-50_HT-400to600_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17.root");
  g_FileVec.push_back("All_Bkg_2017/DYJetsToLL_M-50_HT-600to800_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17.root");
  g_FileVec.push_back("All_Bkg_2017/DYJetsToLL_M-50_HT-70to100_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17.root");
  g_FileVec.push_back("All_Bkg_2017/DYJetsToLL_M-50_HT-800to1200_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17.root");
  return g_FileVec;
}

const string fall17_TChiWZ = "All_Sig/SMS-TChiWZ_ZToLL_mZMin-0p1_TuneCP2_13TeV-madgraphMLM-pythia8_Fall17.root";

const string SigTree_SMS_300_210 = "SMS_300_210";
const string SigTree_SMS_300_270 = "SMS_300_270";

const string fall17_TChiWZ_SMS_300_210_SubDir =  "TChiWZ_SMS_300_210";
const string fall17_TChiWZ_SMS_300_270_SubDir =  "TChiWZ_SMS_300_270";

const string g_Path = "/home/t3-ku/crogan/NTUPLES/StopNtuple_new/";

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
  //make_subdir( outfile, fall17_Bkg_SubDir.c_str() );
  make_subdir( outfile, fall17_TChiWZ_SMS_300_270_SubDir.c_str() );
  make_subdir( outfile, fall17_TChiWZ_SMS_300_210_SubDir.c_str() );
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
  //run_hist_maker( BkgTree_KUAnalysis, load_gFileVec_TChiWZ_Bkg(), NotOSSFTFile, fall17_Bkg_SubDir );
  run_hist_maker( BkgTree_KUAnalysis, load_gFileVec_TChiWZ_Bkg_DiBoson(), NotOSSFTFile, fall17_Bkg_DiBoson_SubDir );
  run_hist_maker( BkgTree_KUAnalysis, load_gFileVec_TChiWZ_Bkg_DY(), NotOSSFTFile, fall17_Bkg_DY_SubDir );
  run_hist_maker( BkgTree_KUAnalysis, load_gFileVec_TChiWZ_Bkg_WJets(), NotOSSFTFile, fall17_Bkg_WJets_SubDir );
  run_hist_maker( BkgTree_KUAnalysis, load_gFileVec_TChiWZ_Bkg_ST(), NotOSSFTFile, fall17_Bkg_ST_SubDir );
  run_hist_maker( BkgTree_KUAnalysis, load_gFileVec_TChiWZ_Bkg_TTJets(), NotOSSFTFile, fall17_TTJets_SubDir );

//--------Signals
  run_hist_maker( SigTree_SMS_300_210, fall17_TChiWZ, NotOSSFTFile, fall17_TChiWZ_SMS_300_210_SubDir );
  run_hist_maker( SigTree_SMS_300_270,  fall17_TChiWZ, NotOSSFTFile, fall17_TChiWZ_SMS_300_270_SubDir );
}


