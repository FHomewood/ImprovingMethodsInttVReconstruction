#define truthAnalysis_cxx

#include "truthAnalysis.h"
#include <TH2.h>
#include <TStyle.h>

/******Global Variables******/

TH1D* testHist;
TH1D* Zdecay_m_ab_Hist;
TH1D* Top_Mass_Hist;

/******Initialisation Procedure******/
void truthAnalysis::Begin(TTree * /*tree*/)
{
   testHist = new TH1D(
      "test",
      "Test Histogram of Z eta (NOT REMOTELY ACCURATE)",
      40,-100,100
      );
   Zdecay_m_ab_Hist = new TH1D(
      "Zdecay_m_ab",
      "invariant mass of Z decay products",
      50, 0.5 * 90 * 1000,1.5 * 90 * 1000
      );
   Top_Mass_Hist = new TH1D(
      "top_mass",
      "mass of reconstructed top quark",
      40, 1.5 * 1.73 * 100000, 0.5 * 1.73*100000
      );

   TString option = GetOption();
}

/******Entry Loop Function******/
Bool_t truthAnalysis::Process(Long64_t entry)
{
   fReader.SetEntry(entry);
      GetEntry(entry); // loads all used variables into memory via SetBranchAddress

      //Just a simplistic and useless example
      //of a plot that can't be achieved in the ROOT terminal
      auto variable = *MC_Z_eta;
      testHist->Fill(variable * log(entry));

      //Actual calculations

      //Z_m_ab
      TLorentzVector Z_decay1;
      TLorentzVector Z_decay2;
      Z_decay1.SetPtEtaPhiM(*MC_Zdecay1_pt,*MC_Zdecay1_eta,*MC_Zdecay1_phi,*MC_Zdecay1_m);
      Z_decay2.SetPtEtaPhiM(*MC_Zdecay2_pt,*MC_Zdecay2_eta,*MC_Zdecay2_phi,*MC_Zdecay2_m);
      Zdecay_m_ab_Hist->Fill((Double_t)(Z_decay1 + Z_decay2).M());

      //t_m_wb
      TLorentzVector t_decay1;
      TLorentzVector t_decay2;
      t_decay1.SetPtEtaPhiM(*MC_W_from_t_pt,*MC_W_from_t_eta,*MC_W_from_t_phi,*MC_W_from_t_m);
      t_decay2.SetPtEtaPhiM(*MC_b_from_t_pt,*MC_b_from_t_eta,*MC_b_from_t_phi,*MC_b_from_t_m);
      Top_Mass_Hist -> Fill((Double_t)(t_decay1 + t_decay2).M());

   return kTRUE;
}

/******Final Procedure******/
void truthAnalysis::Terminate()
{ //Save outputs to a root file
   TFile OutFile("~/MPhys/ttV-and-EFT/RootFiles/truthAnalysis.root","RECREATE");
   TH1* HistList[] = {testHist,Zdecay_m_ab_Hist,Top_Mass_Hist};
   for (int i = 0; i < sizeof(HistList)/sizeof(*HistList); i++) HistList[i] -> Write();
   OutFile.Close();
   cout<<"Finished truth Analysis"<<endl;
}

void truthAnalysis::SlaveTerminate()
{  }

void truthAnalysis::SlaveBegin(TTree * tree)
{  TString option = GetOption(); }