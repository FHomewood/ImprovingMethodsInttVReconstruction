//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Oct 21 09:11:05 2019 by ROOT version 6.14/04
// from TTree truth/tree
// found on file: /lustre/scratch/epp/atlas/tjs31/top_reco/mc.ttee.mc16a.root
//////////////////////////////////////////////////////////

#ifndef truthAnalysis_h
#define truthAnalysis_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>
#include <TTreeReader.h>
#include <TTreeReaderValue.h>
#include <TTreeReaderArray.h>

// Headers needed by this particular selector
#include <vector>



class truthAnalysis : public TSelector {
public :
   TTreeReader     fReader;  //!the tree reader
   TTree          *fChain = 0;   //!pointer to the analyzed TTree or TChain

   // Readers to access the data (delete the ones you do not need).
   TTreeReaderValue<Float_t> weight_mc = {fReader, "weight_mc"};
   TTreeReaderValue<ULong64_t> eventNumber = {fReader, "eventNumber"};
   TTreeReaderValue<UInt_t> runNumber = {fReader, "runNumber"};
   TTreeReaderValue<Float_t> weight_pileup = {fReader, "weight_pileup"};
   TTreeReaderValue<UInt_t> mcChannelNumber = {fReader, "mcChannelNumber"};
   TTreeReaderArray<float> PDFinfo_X1 = {fReader, "PDFinfo_X1"};
   TTreeReaderArray<float> PDFinfo_X2 = {fReader, "PDFinfo_X2"};
   TTreeReaderArray<int> PDFinfo_PDGID1 = {fReader, "PDFinfo_PDGID1"};
   TTreeReaderArray<int> PDFinfo_PDGID2 = {fReader, "PDFinfo_PDGID2"};
   TTreeReaderArray<float> PDFinfo_Q = {fReader, "PDFinfo_Q"};
   TTreeReaderArray<float> PDFinfo_XF1 = {fReader, "PDFinfo_XF1"};
   TTreeReaderArray<float> PDFinfo_XF2 = {fReader, "PDFinfo_XF2"};
   TTreeReaderValue<Int_t> MC_Z_AncestryCorrupted = {fReader, "MC_Z_AncestryCorrupted"};
   TTreeReaderValue<Int_t> MC_Zdecay2_pdgId = {fReader, "MC_Zdecay2_pdgId"};
   TTreeReaderValue<Int_t> MC_Wdecay1_from_t_pdgId = {fReader, "MC_Wdecay1_from_t_pdgId"};
   TTreeReaderValue<Int_t> MC_Z_IsOnShell = {fReader, "MC_Z_IsOnShell"};
   TTreeReaderValue<Int_t> MC_Wdecay2_from_t_pdgId = {fReader, "MC_Wdecay2_from_t_pdgId"};
   TTreeReaderValue<Int_t> MC_Zdecay1_pdgId = {fReader, "MC_Zdecay1_pdgId"};
   TTreeReaderValue<Int_t> MC_Wdecay1_from_tbar_pdgId = {fReader, "MC_Wdecay1_from_tbar_pdgId"};
   TTreeReaderValue<Int_t> MC_Wdecay2_from_tbar_pdgId = {fReader, "MC_Wdecay2_from_tbar_pdgId"};
   TTreeReaderValue<Float_t> MC_Zdecay2_pt = {fReader, "MC_Zdecay2_pt"};
   TTreeReaderValue<Float_t> MC_Zdecay2_m = {fReader, "MC_Zdecay2_m"};
   TTreeReaderValue<Float_t> MC_Zdecay1_pt = {fReader, "MC_Zdecay1_pt"};
   TTreeReaderValue<Float_t> MC_Zdecay2_eta = {fReader, "MC_Zdecay2_eta"};
   TTreeReaderValue<Float_t> MC_Zdecay1_m = {fReader, "MC_Zdecay1_m"};
   TTreeReaderValue<Float_t> MC_Z_phi = {fReader, "MC_Z_phi"};
   TTreeReaderValue<Float_t> MC_Z_pt = {fReader, "MC_Z_pt"};
   TTreeReaderValue<Float_t> MC_Z_m = {fReader, "MC_Z_m"};
   TTreeReaderValue<Float_t> MC_Wdecay2_from_tbar_eta = {fReader, "MC_Wdecay2_from_tbar_eta"};
   TTreeReaderValue<Float_t> MC_Wdecay2_from_t_eta = {fReader, "MC_Wdecay2_from_t_eta"};
   TTreeReaderValue<Float_t> MC_Wdecay2_from_t_pt = {fReader, "MC_Wdecay2_from_t_pt"};
   TTreeReaderValue<Float_t> MC_Wdecay1_from_tbar_eta = {fReader, "MC_Wdecay1_from_tbar_eta"};
   TTreeReaderValue<Float_t> MC_Wdecay1_from_tbar_pt = {fReader, "MC_Wdecay1_from_tbar_pt"};
   TTreeReaderValue<Float_t> MC_Wdecay1_from_tbar_m = {fReader, "MC_Wdecay1_from_tbar_m"};
   TTreeReaderValue<Float_t> MC_Wdecay1_from_t_phi = {fReader, "MC_Wdecay1_from_t_phi"};
   TTreeReaderValue<Float_t> MC_Wdecay1_from_t_pt = {fReader, "MC_Wdecay1_from_t_pt"};
   TTreeReaderValue<Float_t> MC_Wdecay2_from_tbar_pt = {fReader, "MC_Wdecay2_from_tbar_pt"};
   TTreeReaderValue<Float_t> MC_b_from_tbar_eta = {fReader, "MC_b_from_tbar_eta"};
   TTreeReaderValue<Float_t> MC_b_from_tbar_m = {fReader, "MC_b_from_tbar_m"};
   TTreeReaderValue<Float_t> MC_Wdecay2_from_t_m = {fReader, "MC_Wdecay2_from_t_m"};
   TTreeReaderValue<Float_t> MC_b_from_t_phi = {fReader, "MC_b_from_t_phi"};
   TTreeReaderValue<Float_t> MC_t_afterFSR_pt = {fReader, "MC_t_afterFSR_pt"};
   TTreeReaderValue<Float_t> MC_Wdecay2_from_tbar_phi = {fReader, "MC_Wdecay2_from_tbar_phi"};
   TTreeReaderValue<Float_t> MC_ttbar_beforeFSR_eta = {fReader, "MC_ttbar_beforeFSR_eta"};
   TTreeReaderValue<Float_t> MC_t_afterFSR_m = {fReader, "MC_t_afterFSR_m"};
   TTreeReaderValue<Float_t> MC_ttbar_afterFSR_beforeDecay_phi = {fReader, "MC_ttbar_afterFSR_beforeDecay_phi"};
   TTreeReaderValue<Float_t> MC_t_beforeFSR_eta = {fReader, "MC_t_beforeFSR_eta"};
   TTreeReaderValue<Float_t> MC_ttbar_afterFSR_beforeDecay_eta = {fReader, "MC_ttbar_afterFSR_beforeDecay_eta"};
   TTreeReaderValue<Float_t> MC_t_afterFSR_eta = {fReader, "MC_t_afterFSR_eta"};
   TTreeReaderValue<Float_t> MC_tbar_beforeFSR_m = {fReader, "MC_tbar_beforeFSR_m"};
   TTreeReaderValue<Float_t> MC_ttbar_beforeFSR_phi = {fReader, "MC_ttbar_beforeFSR_phi"};
   TTreeReaderValue<Float_t> MC_ttbar_afterFSR_phi = {fReader, "MC_ttbar_afterFSR_phi"};
   TTreeReaderValue<Float_t> MC_ttbar_beforeFSR_pt = {fReader, "MC_ttbar_beforeFSR_pt"};
   TTreeReaderValue<Float_t> MC_ttbar_beforeFSR_m = {fReader, "MC_ttbar_beforeFSR_m"};
   TTreeReaderValue<Float_t> MC_W_from_t_pt = {fReader, "MC_W_from_t_pt"};
   TTreeReaderValue<Float_t> MC_b_from_t_eta = {fReader, "MC_b_from_t_eta"};
   TTreeReaderValue<Float_t> MC_tbar_afterFSR_phi = {fReader, "MC_tbar_afterFSR_phi"};
   TTreeReaderValue<Float_t> MC_ttbar_afterFSR_pt = {fReader, "MC_ttbar_afterFSR_pt"};
   TTreeReaderValue<Float_t> MC_Zdecay1_phi = {fReader, "MC_Zdecay1_phi"};
   TTreeReaderValue<Float_t> MC_Wdecay1_from_tbar_phi = {fReader, "MC_Wdecay1_from_tbar_phi"};
   TTreeReaderValue<Float_t> MC_t_beforeFSR_phi = {fReader, "MC_t_beforeFSR_phi"};
   TTreeReaderValue<Float_t> MC_ttbar_afterFSR_m = {fReader, "MC_ttbar_afterFSR_m"};
   TTreeReaderValue<Float_t> MC_ttbar_afterFSR_eta = {fReader, "MC_ttbar_afterFSR_eta"};
   TTreeReaderValue<Float_t> MC_Z_eta = {fReader, "MC_Z_eta"};
   TTreeReaderValue<Float_t> MC_t_afterFSR_phi = {fReader, "MC_t_afterFSR_phi"};
   TTreeReaderValue<Float_t> MC_ttbar_afterFSR_beforeDecay_pt = {fReader, "MC_ttbar_afterFSR_beforeDecay_pt"};
   TTreeReaderValue<Float_t> MC_ttbar_afterFSR_beforeDecay_m = {fReader, "MC_ttbar_afterFSR_beforeDecay_m"};
   TTreeReaderValue<Float_t> MC_b_from_t_pt = {fReader, "MC_b_from_t_pt"};
   TTreeReaderValue<Float_t> MC_t_beforeFSR_m = {fReader, "MC_t_beforeFSR_m"};
   TTreeReaderValue<Float_t> MC_Zdecay1_eta = {fReader, "MC_Zdecay1_eta"};
   TTreeReaderValue<Float_t> MC_Wdecay2_from_tbar_m = {fReader, "MC_Wdecay2_from_tbar_m"};
   TTreeReaderValue<Float_t> MC_tbar_beforeFSR_eta = {fReader, "MC_tbar_beforeFSR_eta"};
   TTreeReaderValue<Float_t> MC_Zdecay2_phi = {fReader, "MC_Zdecay2_phi"};
   TTreeReaderValue<Float_t> MC_tbar_afterFSR_m = {fReader, "MC_tbar_afterFSR_m"};
   TTreeReaderValue<Float_t> MC_Wdecay1_from_t_m = {fReader, "MC_Wdecay1_from_t_m"};
   TTreeReaderValue<Float_t> MC_tbar_beforeFSR_phi = {fReader, "MC_tbar_beforeFSR_phi"};
   TTreeReaderValue<Float_t> MC_b_from_tbar_pt = {fReader, "MC_b_from_tbar_pt"};
   TTreeReaderValue<Float_t> MC_W_from_t_eta = {fReader, "MC_W_from_t_eta"};
   TTreeReaderValue<Float_t> MC_tbar_afterFSR_pt = {fReader, "MC_tbar_afterFSR_pt"};
   TTreeReaderValue<Float_t> MC_b_from_t_m = {fReader, "MC_b_from_t_m"};
   TTreeReaderValue<Float_t> MC_tbar_beforeFSR_pt = {fReader, "MC_tbar_beforeFSR_pt"};
   TTreeReaderValue<Float_t> MC_W_from_tbar_pt = {fReader, "MC_W_from_tbar_pt"};
   TTreeReaderValue<Float_t> MC_tbar_afterFSR_eta = {fReader, "MC_tbar_afterFSR_eta"};
   TTreeReaderValue<Float_t> MC_Wdecay1_from_t_eta = {fReader, "MC_Wdecay1_from_t_eta"};
   TTreeReaderValue<Float_t> MC_W_from_t_m = {fReader, "MC_W_from_t_m"};
   TTreeReaderValue<Float_t> MC_b_from_tbar_phi = {fReader, "MC_b_from_tbar_phi"};
   TTreeReaderValue<Float_t> MC_W_from_t_phi = {fReader, "MC_W_from_t_phi"};
   TTreeReaderValue<Float_t> MC_Wdecay2_from_t_phi = {fReader, "MC_Wdecay2_from_t_phi"};
   TTreeReaderValue<Float_t> MC_W_from_tbar_m = {fReader, "MC_W_from_tbar_m"};
   TTreeReaderValue<Float_t> MC_W_from_tbar_eta = {fReader, "MC_W_from_tbar_eta"};
   TTreeReaderValue<Float_t> MC_t_beforeFSR_pt = {fReader, "MC_t_beforeFSR_pt"};
   TTreeReaderValue<Float_t> MC_W_from_tbar_phi = {fReader, "MC_W_from_tbar_phi"};


   truthAnalysis(TTree * /*tree*/ =0) { }
   virtual ~truthAnalysis() { }
   virtual Int_t   Version() const { return 2; }
   virtual void    Begin(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual void    Init(TTree *tree);
   virtual Bool_t  Notify();
   virtual Bool_t  Process(Long64_t entry);
   virtual Int_t   GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
   virtual void    SetOption(const char *option) { fOption = option; }
   virtual void    SetObject(TObject *obj) { fObject = obj; }
   virtual void    SetInputList(TList *input) { fInput = input; }
   virtual TList  *GetOutputList() const { return fOutput; }
   virtual void    SlaveTerminate();
   virtual void    Terminate();

   ClassDef(truthAnalysis,0);

};

#endif

#ifdef truthAnalysis_cxx
void truthAnalysis::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the reader is initialized.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   fReader.SetTree(tree);
}

Bool_t truthAnalysis::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}


#endif // #ifdef truthAnalysis_cxx
