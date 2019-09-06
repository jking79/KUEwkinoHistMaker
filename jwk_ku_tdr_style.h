/////////////////////////////////////////////////////////////////////////////////////////
//
// Jack W King III   2017
//
// Plot Style Code
// to use add #include "ku_tdr_style.h" to top of analysis c file.
// be sure this file is in directory with your analysis c file.
//
// ****  Add: setTDRStyle(); in the same area, but before, you create canvases. *****
//
// you can use the draw functions and the getCanvas function provided or use the code 
// as shown in those functions below to draw and get a canvas.
//
// Titles are provided by you.  be sure to specify units ex: " Pt ( GeV ) " if there are
// units and specify bin size for events ex: " Events / 20 GeV " for an event axis title.
// The titles you specify in the declaration of the histogram will be used in the plot
// as the title of the plot and the title of the stats box, plan accordingly.  I recomend
// using the same title for the histogram plot and the canvas.
//
/////////////////////////////////////////////////////////////////////////////////////////

#include "TStyle.h"
#include "stdlib.h"
#include <sstream>


int can_x_width = 1000;
int can_y_width = 600;

void CreatePalette()
{
    //From Prof. Chris Rogan
    //Useful ROOT5 palette
    //Call with CreatePalette()
    Int_t MyPalette[28];
    Int_t alpha=1;
    
    Double_t Stops[5] = { 0.00, 0.50, 0.70, 0.82, 1.00 };
    Double_t Red[5]   = { 0.00, 0.00, 0.74, 1.00, 1.00 };
    Double_t Green[5] = { 0.00, 0.61, 0.82, 0.70, 1.00 };
    Double_t Blue[5]  = { 0.31, 0.73, 0.08, 0.00, 1.00 };
    
    Int_t test = TColor::CreateGradientColorTable(5, Stops, Red, Green, Blue, 28);
    for(int i=0; i<28; i++)
    {
        MyPalette[i] = test+i;
    }
    gStyle->SetPalette(28,MyPalette);
}

string itostr( int num ) // convert int to a string
{
	stringstream ss;
	ss << num;
	string result(ss.str());
	return result;
}

string rpsb(string temp)  // replace space with underline
{
   int position = temp.find( " " ); // find first space
   while ( position != int(string::npos) )
   {
      temp.replace( position, 1, "_" );
      position = temp.find( " ", position + 1 );
   }
   return temp;
}

string revrpsb(string temp)  //  replace underline with space
{
   int position = temp.find( "_" ); // find first space
   while ( position != int(string::npos) )
   {
      temp.replace( position, 1, " " );
      position = temp.find( "_", position + 1 );
   }
   return temp;
}

// draws a histogram when TH1F, canvas, and x,y titles provided.
void tdrHistDraw( TH1D* &hist, TCanvas* &can, string xtit, string ytit )
{
    can->cd();
    hist->UseCurrentStyle();
    hist->GetXaxis()->CenterTitle(true);
    hist->GetXaxis()->SetTitle(xtit.c_str());
    hist->GetYaxis()->CenterTitle(true);
    hist->GetYaxis()->SetTitle(ytit.c_str());
    hist->Draw();
    gPad->Update();
    return;

}

// draws a histogram when TH1F, canvas, and x,y titles provided.
void tdrHistDrawLogX( TH1D* &hist, TCanvas* &can, string xtit, string ytit )
{
    can->cd();
    hist->UseCurrentStyle();
    gPad->SetLogx();
    hist->GetXaxis()->CenterTitle(true);
    hist->GetXaxis()->SetTitle(xtit.c_str());
    hist->GetYaxis()->CenterTitle(true);
    hist->GetYaxis()->SetTitle(ytit.c_str());
    hist->Draw();
    gPad->Update();
    return;

}

// draws a 2d histogram when TH2F, canvas, and x,y titles provided.
void tdrHist2DDraw( TH2D* &hist, TCanvas* &can, string xtit, string ytit )
{
    can->cd();
    hist->UseCurrentStyle();
    hist->GetXaxis()->CenterTitle(true);
    hist->GetXaxis()->SetTitle(xtit.c_str());
    hist->GetYaxis()->CenterTitle(true);
    hist->GetYaxis()->SetTitle(ytit.c_str());
    hist->Draw("colz");
    gPad->Update();
    return;

}

// draws a histogram when TH1F, canvas, and x,y titles provided.
void tdrHistDrawMulti( vector<TH1D*> &hist, TCanvas* &can, string xtit, string ytit, double miny, double maxy, vector<string> label )
{
    can->cd();
    TLegend* myleg = new TLegend( 0.6, 0.6, 0.8, 0.8 );
    myleg->SetFillColor(0);
    myleg->SetBorderSize(0);
    myleg->SetTextSize(0.025);
    myleg->SetHeader( (label[0]).c_str() );
    for( int i = 0 ; i < int(hist.size()); i++)
    {
      hist[i]->UseCurrentStyle();
      hist[i]->SetStats(false);
      hist[i]->GetXaxis()->CenterTitle(true);
      hist[i]->GetXaxis()->SetTitle(xtit.c_str());
      hist[i]->GetYaxis()->CenterTitle(true);
      hist[i]->GetYaxis()->SetTitle(ytit.c_str());
      hist[i]->GetYaxis()->SetRangeUser(miny, maxy);
      if( i == 0 ){
	 hist[i]->SetLineColor(i+2);
         hist[i]->Draw();
	 myleg->AddEntry( hist[i], (label[i+1]).c_str(), "L" );
	 gPad->Update();
      }else{
	 hist[i]->SetLineColor(i+2);
         hist[i]->Draw("same");
         myleg->AddEntry( hist[i], (label[i+1]).c_str(), "L" );
	 gPad->Update();
      }
    }
    myleg->Draw(); 
    gPad->Update();
    return;

}

void tdrHistDrawMulti( vector<TH1D*> &hists, TCanvas* &can, string xtit, string ytit )
{
	vector<string> bob;
	bob.push_back( "Legend" );
	bob.push_back( "DeltaR of Tmax" );
        bob.push_back( "DeltaR of Tmin" );        
	bob.push_back( "DeltaR of Wb" );

	tdrHistDrawMulti( hists, can, xtit, ytit, 0, 2500, bob );
	return;

}

// returns a canvas if title is specified.

TCanvas* getEwkinoCanvas(){

  TCanvas* can = (TCanvas*) new TCanvas("can","can",700.,600);

  can->SetLeftMargin(0.15);
  can->SetRightMargin(0.18);
  can->SetBottomMargin(0.15);
  can->SetGridx();
  can->SetGridy();
  can->SetLogz();
  can->Draw();
  can->cd();

  return can;

}

TCanvas* getTDRCanvas( string title )
{
    TCanvas *can = new TCanvas( title.c_str(), title.c_str(), can_x_width, can_y_width );
    return can;
}

TCanvas* getTDRCanvas( string title, string mod )
{
    TCanvas *can = new TCanvas( title.c_str(), title.c_str(), can_x_width*2, can_y_width*3 );
    return can;
}

void fixOverlay() {
  gPad->RedrawAxis();
}

void setTDRStyle(bool invert_colors) {
CreatePalette();
    TStyle* myStyle = new TStyle("myStyle","myStyle");
    
    // For the canvas:
    myStyle->SetCanvasBorderMode(0);
    myStyle->SetCanvasColor(kWhite);
    myStyle->SetCanvasDefX(0);
    myStyle->SetCanvasDefY(0);
    
    // For the Legend
    myStyle->SetLegendBorderSize(0);
    myStyle->SetLegendFillColor(0);
    myStyle->SetLegendFont(42);
    myStyle->SetLegendTextSize(0.04);
    
    // For the Pad:
    myStyle->SetPadBorderMode(0);
    myStyle->SetPadColor(kWhite);
    myStyle->SetGridColor(0);
    myStyle->SetGridStyle(3);
    myStyle->SetGridWidth(1);
    
    // For the frame:
    myStyle->SetFrameBorderMode(0);
    myStyle->SetFrameBorderSize(1);
    myStyle->SetFrameFillColor(0);
    myStyle->SetFrameFillStyle(0);
    myStyle->SetFrameLineColor(1);
    myStyle->SetFrameLineStyle(1);
    myStyle->SetFrameLineWidth(1);
    
    // set the paper & margin sizes
    myStyle->SetPaperSize(20,26);
    myStyle->SetPadTopMargin(0.12);
    myStyle->SetPadRightMargin(0.12);
    myStyle->SetPadBottomMargin(0.18);
    myStyle->SetPadLeftMargin(0.12);
    
    myStyle->SetTitleX(0.5);
    myStyle->SetTitleAlign(23);
    myStyle->SetTitleY(0.985);
    myStyle->SetTitleFont(42);
    myStyle->SetTitleColor(1);
    myStyle->SetTitleTextColor(1);
    myStyle->SetTitleFillColor(0);
    myStyle->SetTitleFontSize(0.05);
    myStyle->SetTitleBorderSize(0);
    
    // use large Times-Roman fonts
    myStyle->SetTitleFont(42,"xyz");  // set the all 3 axes title font
    myStyle->SetTitleFont(42," ");    // set the pad title font
    myStyle->SetTitleSize(0.06,"xyz"); // set the 3 axes title size
    myStyle->SetTitleSize(0.06," ");   // set the pad title size
    myStyle->SetLabelFont(42,"xyz");
    myStyle->SetLabelSize(0.05,"xyz");
    myStyle->SetLabelColor(1,"xyz");
    myStyle->SetTextFont(42);
    myStyle->SetTextSize(0.08);
    myStyle->SetStatFont(42);
    
    // use bold lines and markers
    myStyle->SetLineWidth(2);
    myStyle->SetMarkerStyle(8);
    myStyle->SetHistLineWidth(2);
    myStyle->SetLineStyleString(2,"[12 12]"); // postscript dashes
    
    //..Get rid of X error bars
    myStyle->SetErrorX(0.001);
    
    // do not display any of the standard histogram decorations
    myStyle->SetOptTitle(0);
    myStyle->SetOptStat(0);
    myStyle->SetOptFit(11111111);
    
    // put tick marks on top and RHS of plots
    myStyle->SetPadTickX(1);
    myStyle->SetPadTickY(1);
    
    Int_t MyPalette[28];
    Int_t alpha=1;
    
    Double_t Stops[5] = { 0.00, 0.50, 0.70, 0.82, 1.00 };
    Double_t Red[5]   = { 0.00, 0.00, 0.74, 1.00, 1.00 };
    Double_t Green[5] = { 0.00, 0.61, 0.82, 0.70, 1.00 };
    Double_t Blue[5]  = { 0.31, 0.73, 0.08, 0.00, 1.00 };
    
    Int_t zpalette = TColor::CreateGradientColorTable(5, Stops, Red, Green, Blue, 28);
    for(int i=0; i<28; i++)
    {
        MyPalette[i] = zpalette+i;
    }
    myStyle->SetPalette(28,MyPalette);
    if(invert_colors)
    {
     myStyle->SetAxisColor(kWhite);
     myStyle->SetCanvasColor(kBlack);
     myStyle->SetFrameFillColor(kBlack);
     myStyle->SetFrameLineColor(kWhite);
     myStyle->SetGridColor(kWhite);
     myStyle->SetHistLineColor(kWhite);
     myStyle->SetLabelColor(kWhite);
     myStyle->SetLegendFillColor(kBlack);
     myStyle->SetPadColor(kBlack);
     myStyle->SetStatColor(kBlack);
     myStyle->SetStatTextColor(kWhite);
     myStyle->SetTitleColor(kWhite);
     myStyle->SetTitleTextColor(kWhite);
    }
    
    myStyle->cd();
}


TCanvas* drawPrint( TH1D* hist, string type, string title, string xtitle, string ytitle, string rfname)
{
        TCanvas *c = getTDRCanvas( title + rfname );
	tdrHistDraw( hist, c, xtitle, ytitle );
        string savetitle( rfname + "_" + rpsb(title) + type );
        c->SaveAs( savetitle.c_str() );
        return c;
}

TCanvas* drawPrint( TH1D* hist, string title, string xtitle, string ytitle, string rfname)
{
        return drawPrint( hist, ".pdf", title, xtitle, ytitle, rfname );
}

TCanvas* drawPrintLogX( TH1D* hist, string type, string title, string xtitle, string ytitle, string rfname)
{
        TCanvas *c = getTDRCanvas( title + rfname );
        tdrHistDrawLogX( hist, c, xtitle, ytitle );
        string savetitle( rfname + "_" + rpsb(title) + type );
        c->SaveAs( savetitle.c_str() );

        return c;
}

TCanvas* drawPrintLogX( TH1D* hist, string title, string xtitle, string ytitle, string rfname )
{
        return drawPrintLogX( hist, ".pdf", title, xtitle, ytitle, rfname );
}

TCanvas* drawPrintMulti( vector<TH1D*> histlist, string type, string title, string xtitle, string ytitle, string rfname, double ymin, double ymax, vector<string> label )
{
		
	double biggest = 0;
	for( int i = 0; i < int(histlist.size()); i++ ){ if( biggest < histlist[i]->GetMaximum() ) biggest = histlist[i]->GetMaximum();}
	ymax = biggest*1.25;
        TCanvas *c = getTDRCanvas( title + rfname );
        tdrHistDrawMulti( histlist, c, xtitle, ytitle, ymin, ymax, label );
        string savetitle( rfname + "_" + rpsb(title) + type );
        c->SaveAs( savetitle.c_str() );
        return c;
}

TCanvas* drawPrintMulti( vector<TH1D*> histlist, string title, string xtitle, string ytitle, string rfname, double ymin, double ymax, vector<string> label )
{
        return drawPrintMulti( histlist, ".pdf", title, xtitle, ytitle, rfname, ymin, ymax, label );
}

TCanvas* drawPrintMulti( vector<TH1D*> histlist, string title, string xtitle, string ytitle, string rfname, vector<string> label )
{
        return drawPrintMulti( histlist, ".pdf", title, xtitle, ytitle, rfname, 0, 0, label );
}

TCanvas* drawPrint2D( TH2D* hist, string type, string title, string xtitle, string ytitle, string rfname )
{
        TCanvas *c = getTDRCanvas( title + rfname );
        tdrHist2DDraw( hist, c, xtitle, ytitle );
        string savetitle( rfname + "_" + rpsb(title) + type );
        c->SaveAs( savetitle.c_str() );

        return c;
}

TCanvas* drawPrint2D( TH2D* hist, string title, string xtitle, string ytitle, string rfname)
{
        return drawPrint2D( hist, ".pdf", title, xtitle, ytitle , rfname );
}


