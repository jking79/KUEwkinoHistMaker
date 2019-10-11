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
#include <TColor.h>
#include <TColorWheel.h>
#include <TH1D.h>
#include <TH2D.h>
#include <TStyle.h>

double evaluateZbi(double Nsig, double Nbkg, double sys)
{
    double Nobs = Nsig+Nbkg;
    double tau = 1./Nbkg/(sys*sys/10000.);
    double aux = Nbkg*tau;
    double Pvalue = TMath::BetaIncomplete(1./(1.+tau),Nobs,aux+1.);
    return sqrt(2.)*TMath::ErfcInverse(Pvalue*2.);
}

vector<TH1D*> list_histos(string fname, vector<string> dir_names, string hist_name)
{
    std::vector<TH1D*> vect_hist;
    TKey *key;
    TFile *f = TFile::Open(fname.c_str(), "READ");
    if(!f || f->IsZombie())
    {
        cout << "Unable to open " << fname << " for reading..." << endl;
        return vect_hist;
    }
    for(int i = 0; i < int(dir_names.size()); i++)
    {
    TDirectoryFile* folder = nullptr;
    f->GetObject(dir_names[i].c_str(),folder);
    folder->cd();
    TH1D* h = nullptr;
    folder->GetObject(hist_name.c_str(),h);
    vect_hist.push_back(h);
    }
    return vect_hist;
}

vector<TH2D*> list_histos2D(string fname, vector<string> dir_names, string hist_name)
{
    std::vector<TH2D*> vect_hist;
    TKey *key;
    TFile *f = TFile::Open(fname.c_str(), "READ");
    if(!f || f->IsZombie())
    {
        cout << "Unable to open " << fname << " for reading..." << endl;
        return vect_hist;
    }
    for(int i = 0; i < int(dir_names.size()); i++)
    {
    TDirectoryFile* folder = nullptr;
    f->GetObject(dir_names[i].c_str(),folder);
    folder->cd();
    TH2D* h = nullptr;
    folder->GetObject(hist_name.c_str(),h);
    vect_hist.push_back(h);
    }
    return vect_hist;
}

void Get_Stack(string hists_name, vector<string> labels_bkg, vector<string> labels_sig, vector<int> colors_bkg, vector<int> colors_sig, string outFile)
{
  vector<TH1D*> hists_bkg = list_histos(outFile, labels_bkg, hists_name);
  vector<TH1D*> hists_sig = list_histos(outFile, labels_sig, hists_name);
  TH1D* bkg_hist = (TH1D*)hists_bkg[0]->Clone("TOT_BKG");
  for(int i = 1; i < int(hists_bkg.size()); i++)
  {
   for(int k = 0; k < i; k++)
   {
    hists_bkg[k]->Add(hists_bkg[i]);
   }
   bkg_hist->Add(hists_bkg[i]);
  }
  double fmax = -1.;
  int imax = -1;
  for(int i = 0; i < int(hists_bkg.size()); i++){
    if(hists_bkg[i]->GetMaximum() > fmax){
      fmax = hists_bkg[i]->GetMaximum();
      imax = i;
    }
  }
  string Yname = "Events / bin";
  string Xname = hists_bkg[0]->GetXaxis()->GetTitle();
  gStyle->SetOptTitle(0);
  gStyle->SetOptStat(0);
  gStyle->SetOptFit(11111111);

  string name = "can_";
  name+=hists_bkg[0]->GetName();
  TCanvas* can = new TCanvas(name.c_str(),"",600.,500);
  can->SetLeftMargin(0.13);
  can->SetRightMargin(0.04);
  can->SetBottomMargin(0.15);
  can->SetTopMargin(0.085);
  can->SetGridx();
  can->SetGridy();
  can->Draw();
  can->cd();
  hists_bkg[imax]->Draw("hist");
  hists_bkg[imax]->GetXaxis()->CenterTitle();
  hists_bkg[imax]->GetXaxis()->SetTitleFont(132);
  hists_bkg[imax]->GetXaxis()->SetTitleSize(0.06);
  hists_bkg[imax]->GetXaxis()->SetTitleOffset(1.06);
  hists_bkg[imax]->GetXaxis()->SetLabelFont(132);
  hists_bkg[imax]->GetXaxis()->SetLabelSize(0.05);
  hists_bkg[imax]->GetXaxis()->SetTitle(Xname.c_str());
  hists_bkg[imax]->GetYaxis()->CenterTitle();
  hists_bkg[imax]->GetYaxis()->SetTitleFont(132);
  hists_bkg[imax]->GetYaxis()->SetTitleSize(0.06);
  hists_bkg[imax]->GetYaxis()->SetTitleOffset(1.);
  hists_bkg[imax]->GetYaxis()->SetLabelFont(132);
  hists_bkg[imax]->GetYaxis()->SetLabelSize(0.05);
  hists_bkg[imax]->GetYaxis()->SetTitle("a. u.");
  hists_bkg[imax]->GetYaxis()->SetTitle(Yname.c_str());
  
  for(int i = 0; i < int(hists_bkg.size()); i++)
  {
   hists_bkg[i]->SetFillColor(colors_bkg[i]);
   hists_bkg[i]->SetFillStyle(1001);
   hists_bkg[i]->SetLineColor(colors_bkg[i]);
   hists_bkg[i]->SetLineWidth(1);
   hists_bkg[i]->SetMarkerColor(colors_bkg[i]);
   hists_bkg[i]->SetMarkerSize(0);
   hists_bkg[i]->Draw("SAME HIST");
  }
  bkg_hist->SetLineWidth(3.0);
  bkg_hist->SetLineColor(kRed);
  bkg_hist->SetMarkerSize(0);
  bkg_hist->Draw("SAME HIST");
  gPad->RedrawAxis();
  gPad->RedrawAxis("G");
  
  for(int i = 0; i < int(hists_sig.size()); i++)
  {
    hists_sig[i]->SetLineWidth(3.0);
    hists_sig[i]->SetMarkerSize(0.);
    hists_sig[i]->SetMarkerColor(kBlack);
    hists_sig[i]->SetLineStyle(7);
    hists_sig[i]->SetLineColor(colors_sig[i]);
    hists_sig[i]->Draw("SAME HIST");
  }
  TLegend* leg = new TLegend(0.588,0.546,0.945,0.904);
  leg->SetTextFont(132);
  leg->SetTextSize(0.045);
  leg->SetFillColor(kWhite);
  leg->SetLineColor(kWhite);
  leg->SetShadowColor(kWhite);
  leg->AddEntry(bkg_hist, "SM total");
  for(int i = 0; i < int(hists_bkg.size()); i++)
  {
   leg->AddEntry(hists_bkg[i],labels_bkg[i].c_str(),"F");
  }
  for(int i = 0; i < int(hists_sig.size()); i++)
  { 
   leg->AddEntry(hists_sig[i],labels_sig[i].c_str());
  }
  leg->SetLineColor(kWhite);
  leg->SetFillColor(kWhite);
  leg->SetShadowColor(kWhite);
  leg->Draw("SAME");

  TLatex l;
  l.SetNDC();
  l.SetTextSize(0.05);
  l.SetTextFont(42);
  l.DrawLatex(0.15,0.943,"#bf{#it{CMS}} Internal 13 TeV Simulation");
  l.SetTextSize(0.05);
  l.SetTextFont(42);
  string s_lumi = "#scale[0.6]{#int} #it{L dt} = "+to_string(int(137.0))+" fb^{-1}";
  l.DrawLatex(0.72,0.94,s_lumi.c_str());	
  
  TFile* output = new TFile(outFile.c_str(),"UPDATE");
  can->Write();
  output->Close();
  delete leg;
  delete can;
  delete output;  
}

void Get2D_Plot(string hist_name, vector<string> directories, string outFile){
 vector<TH2D*> hist = list_histos2D(outFile, directories, hist_name);
 TFile* output = new TFile(outFile.c_str(),"UPDATE");
 for(int i = 0; i < int(hist.size()); i++)
 {
  string name = "can_";
  name+=directories[i];
  name+=hist[i]->GetName();
  TCanvas* can = new TCanvas(name.c_str(),"",600.,500);
  can->SetLeftMargin(0.15);
  can->SetRightMargin(0.18);
  can->SetBottomMargin(0.15);
  can->SetGridx();
  can->SetGridy();
  can->SetLogz();
  can->Draw();
  can->cd();
  hist[i]->Draw("COLZ");
  TLatex l;
  l.SetNDC();
  l.SetTextSize(0.05);
  l.SetTextFont(42);
  l.DrawLatex(0.15,0.943,"#bf{#it{CMS}} Internal 13 TeV Simulation");
  l.SetTextSize(0.05);
  l.SetTextFont(42);
  string s_lumi = "#scale[0.6]{#int} #it{L dt} = "+to_string(int(137.0))+" fb^{-1}";
  l.DrawLatex(0.72,0.94,s_lumi.c_str());	
  gPad->RedrawAxis();
  gPad->RedrawAxis("G");
  can->Write();
  delete can;
 }
 output->Close();
 delete output;
}

void ewkino_stacker(string inFile = "KUEwkino_2017_ll_NotOSSF_hists.root"){
 cout << "Running Stacker..." << endl;
 vector<string> bkg_directories{"TTJets", "WJets", "DiBoson", "DYJetsToLL", "ST"};
 vector<string> sig_directories{"TChiWW_SMS_275_235"};
 vector<string> directories_2D{"TChiWW_SMS_275_235", "TTJets", "WJets", "DiBoson", "DYJetsToLL", "ST"};
 vector<int> colors_bkg = { kAzure+1, kGreen-9, kPink, kTeal+2, kYellow-4 };
 vector<int> colors_sig = { kMagenta, kCyan+2, };

 Get_Stack("metHist",bkg_directories,sig_directories,colors_bkg,colors_sig,inFile);
 Get_Stack("flavorHist",bkg_directories,sig_directories,colors_bkg,colors_sig,inFile);
 Get_Stack("mllHist",bkg_directories,sig_directories,colors_bkg,colors_sig,inFile);
 Get_Stack("risrHist_Cat2",bkg_directories,sig_directories,colors_bkg,colors_sig,inFile);
 Get_Stack("ptcmHist_Cat2",bkg_directories,sig_directories,colors_bkg,colors_sig,inFile);
 Get_Stack("REVHist_Cat2",bkg_directories,sig_directories,colors_bkg,colors_sig,inFile);
 Get_Stack("PzSHist_Cat2",bkg_directories,sig_directories,colors_bkg,colors_sig,inFile);
 Get_Stack("dphiSIHist_Cat2",bkg_directories,sig_directories,colors_bkg,colors_sig,inFile);
 Get_Stack("dphiCMIHist_Cat2",bkg_directories,sig_directories,colors_bkg,colors_sig,inFile);

 Get2D_Plot("RISR_v_PTISR_Cat2_hist", directories_2D, inFile); 
 Get2D_Plot("dphiSI_DeltaMX3aMX3b_Cat2_hist", directories_2D, inFile); 
 Get2D_Plot("EVa_v_EVb_Cat2_hist", directories_2D, inFile); 
 Get2D_Plot("MX3a_v_MX3b_Cat2_hist", directories_2D, inFile); 
 Get2D_Plot("dphiSI_MS_Cat2_hist", directories_2D, inFile); 
 Get2D_Plot("dphiSI_PzS_Cat2_hist", directories_2D, inFile); 
/*
 double bkg_Entries = 0.0;
 for(int i = 0; i < int(bkg_directories.size()); i++)
 {
  bkg_Entries+=met_hists_bkg[i]->GetEntries();
 }
 cout << "Zbi TChiWW_SMS_275_235: " << evaluateZbi(met_hists_sig[1]->GetEntries(),bkg_Entries,10.) << endl << "TChiWZ_SMS_275_235 Events: " << met_hists_sig[1]->GetEntries() << endl;
 cout << "BKG Events: " << bkg_Entries << endl;
*/
}
