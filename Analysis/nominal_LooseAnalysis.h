//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Oct 21 09:25:06 2019 by ROOT version 6.14/04
// from TTree nominal_Loose/tree
// found on file: /lustre/scratch/epp/atlas/tjs31/top_reco/mc.ttee.mc16a.root
//////////////////////////////////////////////////////////

#ifndef nominal_LooseAnalysis_h
#define nominal_LooseAnalysis_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>
#include <TTreeReader.h>
#include <TTreeReaderValue.h>
#include <TTreeReaderArray.h>

// Headers needed by this particular selector
#include <vector>



class nominal_LooseAnalysis : public TSelector {
public :
   TTreeReader     fReader;  //!the tree reader
   TTree          *fChain = 0;   //!pointer to the analyzed TTree or TChain

   // Readers to access the data (delete the ones you do not need).
   TTreeReaderValue<Float_t> weight_mc = {fReader, "weight_mc"};
   TTreeReaderValue<Float_t> weight_pileup = {fReader, "weight_pileup"};
   TTreeReaderValue<Float_t> weight_leptonSF = {fReader, "weight_leptonSF"};
   TTreeReaderValue<Float_t> weight_bTagSF_MV2c10_77 = {fReader, "weight_bTagSF_MV2c10_77"};
   TTreeReaderValue<Float_t> weight_bTagSF_MV2c10_85 = {fReader, "weight_bTagSF_MV2c10_85"};
   TTreeReaderValue<Float_t> weight_bTagSF_MV2c10_Continuous = {fReader, "weight_bTagSF_MV2c10_Continuous"};
   TTreeReaderValue<Float_t> weight_jvt = {fReader, "weight_jvt"};
   TTreeReaderValue<ULong64_t> eventNumber = {fReader, "eventNumber"};
   TTreeReaderValue<UInt_t> runNumber = {fReader, "runNumber"};
   TTreeReaderArray<float> jet_pt = {fReader, "jet_pt"};
   TTreeReaderArray<float> jet_eta = {fReader, "jet_eta"};
   TTreeReaderArray<float> jet_phi = {fReader, "jet_phi"};
   TTreeReaderArray<float> jet_e = {fReader, "jet_e"};
   TTreeReaderArray<float> jet_mv2c10 = {fReader, "jet_mv2c10"};
   TTreeReaderArray<int> jet_truthflav = {fReader, "jet_truthflav"};
   TTreeReaderArray<int> jet_truthPartonLabel = {fReader, "jet_truthPartonLabel"};
   TTreeReaderArray<char> jet_isbtagged_MV2c10_77 = {fReader, "jet_isbtagged_MV2c10_77"};
   TTreeReaderArray<char> jet_isbtagged_MV2c10_85 = {fReader, "jet_isbtagged_MV2c10_85"};
   TTreeReaderArray<int> jet_tagWeightBin_MV2c10_Continuous = {fReader, "jet_tagWeightBin_MV2c10_Continuous"};
   TTreeReaderValue<Int_t> nEl = {fReader, "nEl"};
   TTreeReaderValue<Int_t> nMu = {fReader, "nMu"};
   TTreeReaderValue<Float_t> ht = {fReader, "ht"};
   TTreeReaderArray<float> jet_charge = {fReader, "jet_charge"};
   TTreeReaderArray<int> jet_nTracks = {fReader, "jet_nTracks"};
   TTreeReaderArray<float> jet_vtx_charge = {fReader, "jet_vtx_charge"};
   TTreeReaderValue<Float_t> eT_miss = {fReader, "eT_miss"};
   TTreeReaderValue<Float_t> phi_miss = {fReader, "phi_miss"};
   TTreeReaderValue<Int_t> nJets = {fReader, "nJets"};
   TTreeReaderValue<Float_t> pT_1lep = {fReader, "pT_1lep"};
   TTreeReaderValue<Float_t> pT_2lep = {fReader, "pT_2lep"};
   TTreeReaderValue<Float_t> pT_3lep = {fReader, "pT_3lep"};
   TTreeReaderValue<Float_t> pT_4lep = {fReader, "pT_4lep"};
   TTreeReaderValue<Float_t> eta_1lep = {fReader, "eta_1lep"};
   TTreeReaderValue<Float_t> eta_2lep = {fReader, "eta_2lep"};
   TTreeReaderValue<Float_t> eta_3lep = {fReader, "eta_3lep"};
   TTreeReaderValue<Float_t> eta_4lep = {fReader, "eta_4lep"};
   TTreeReaderValue<Float_t> phi_1lep = {fReader, "phi_1lep"};
   TTreeReaderValue<Float_t> phi_2lep = {fReader, "phi_2lep"};
   TTreeReaderValue<Float_t> phi_3lep = {fReader, "phi_3lep"};
   TTreeReaderValue<Float_t> phi_4lep = {fReader, "phi_4lep"};
   TTreeReaderValue<Float_t> e_1lep = {fReader, "e_1lep"};
   TTreeReaderValue<Float_t> e_2lep = {fReader, "e_2lep"};
   TTreeReaderValue<Float_t> e_3lep = {fReader, "e_3lep"};
   TTreeReaderValue<Float_t> e_4lep = {fReader, "e_4lep"};
   TTreeReaderValue<Int_t> charge_1lep = {fReader, "charge_1lep"};
   TTreeReaderValue<Int_t> charge_2lep = {fReader, "charge_2lep"};
   TTreeReaderValue<Int_t> charge_3lep = {fReader, "charge_3lep"};
   TTreeReaderValue<Int_t> charge_4lep = {fReader, "charge_4lep"};
   TTreeReaderValue<Int_t> type_1lep = {fReader, "type_1lep"};
   TTreeReaderValue<Int_t> type_2lep = {fReader, "type_2lep"};
   TTreeReaderValue<Int_t> type_3lep = {fReader, "type_3lep"};
   TTreeReaderValue<Int_t> type_4lep = {fReader, "type_4lep"};
   TTreeReaderValue<Bool_t> tight_1lep = {fReader, "tight_1lep"};
   TTreeReaderValue<Bool_t> tight_2lep = {fReader, "tight_2lep"};
   TTreeReaderValue<Bool_t> tight_3lep = {fReader, "tight_3lep"};
   TTreeReaderValue<Bool_t> tight_4lep = {fReader, "tight_4lep"};
   TTreeReaderValue<Float_t> dphi_1lep = {fReader, "dphi_1lep"};
   TTreeReaderValue<Float_t> dphi_2lep = {fReader, "dphi_2lep"};
   TTreeReaderValue<Float_t> dphi_3lep = {fReader, "dphi_3lep"};
   TTreeReaderValue<Float_t> dphi_4lep = {fReader, "dphi_4lep"};
   TTreeReaderValue<Float_t> mT_1lep = {fReader, "mT_1lep"};
   TTreeReaderValue<Float_t> mT_2lep = {fReader, "mT_2lep"};
   TTreeReaderValue<Float_t> mT_3lep = {fReader, "mT_3lep"};
   TTreeReaderValue<Float_t> mT_4lep = {fReader, "mT_4lep"};
   TTreeReaderValue<Int_t> origin_1lep = {fReader, "origin_1lep"};
   TTreeReaderValue<Int_t> origin_2lep = {fReader, "origin_2lep"};
   TTreeReaderValue<Int_t> origin_3lep = {fReader, "origin_3lep"};
   TTreeReaderValue<Double_t> XSecWeight = {fReader, "XSecWeight"};
   TTreeReaderValue<Float_t> weight_year = {fReader, "weight_year"};


   nominal_LooseAnalysis(TTree * /*tree*/ =0) { }
   virtual ~nominal_LooseAnalysis() { }
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

   ClassDef(nominal_LooseAnalysis,0);

};

#endif

#ifdef nominal_LooseAnalysis_cxx
void nominal_LooseAnalysis::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the reader is initialized.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).
  std::cout << "Ciao!" << std::endl;

   fReader.SetTree(tree);
}

Bool_t nominal_LooseAnalysis::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}


#endif // #ifdef nominal_LooseAnalysis_cxx
