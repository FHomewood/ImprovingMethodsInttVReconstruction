/////////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri Nov  1 11:49:46 2019 by ROOT version 6.14/04
// from TTree nominal_Loose/tree
// found on file: /lustre/scratch/epp/atlas/tjs31/top_reco/mc.ttee.mc16a.root
//////////////////////////////////////////////////////////

#ifndef LooseAnalysis_h
#define LooseAnalysis_h

#include <iostream>

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TLorentzVector.h>
// Header file for the classes stored in the TTree if any.
#include "vector"
#include "vector"
#include "vector"

class Lepton
{
 public: 
  Lepton() {};
  ~Lepton() {};

  int GetCharge() {return m_charge;}
  int GetFlavour() {return m_flavour;}
  void SetCharge(int charge) { m_charge = charge;}
  void SetFlavour(int flavour) { m_flavour = flavour;}
  TLorentzVector  & GetP4() {return m_p;}

 private:
  TLorentzVector m_p;
  int m_charge;
  int m_flavour;
};


class LooseAnalysis {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // my member variables

   unsigned long textbook;
   unsigned long notTextbook;
   TTree * l_friendTree;

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Float_t         weight_mc;
   Float_t         weight_pileup;
   Float_t         weight_leptonSF;
   Float_t         weight_bTagSF_MV2c10_77;
   Float_t         weight_bTagSF_MV2c10_85;
   Float_t         weight_bTagSF_MV2c10_Continuous;
   Float_t         weight_jvt;
   ULong64_t       eventNumber;
   UInt_t          runNumber;
   vector<float>   *jet_pt;
   vector<float>   *jet_eta;
   vector<float>   *jet_phi;
   vector<float>   *jet_e;
   vector<float>   *jet_mv2c10;
   vector<int>     *jet_truthflav;
   vector<int>     *jet_truthPartonLabel;
   vector<char>    *jet_isbtagged_MV2c10_77;
   vector<char>    *jet_isbtagged_MV2c10_85;
   vector<int>     *jet_tagWeightBin_MV2c10_Continuous;
   Int_t           nEl;
   Int_t           nMu;
   Float_t         ht;
   vector<float>   *jet_charge;
   vector<int>     *jet_nTracks;
   vector<float>   *jet_vtx_charge;
   Float_t         eT_miss;
   Float_t         phi_miss;
   Int_t           nJets;
   Float_t         pT_1lep;
   Float_t         pT_2lep;
   Float_t         pT_3lep;
   Float_t         pT_4lep;
   Float_t         eta_1lep;
   Float_t         eta_2lep;
   Float_t         eta_3lep;
   Float_t         eta_4lep;
   Float_t         phi_1lep;
   Float_t         phi_2lep;
   Float_t         phi_3lep;
   Float_t         phi_4lep;
   Float_t         e_1lep;
   Float_t         e_2lep;
   Float_t         e_3lep;
   Float_t         e_4lep;
   Int_t           charge_1lep;
   Int_t           charge_2lep;
   Int_t           charge_3lep;
   Int_t           charge_4lep;
   Int_t           type_1lep;
   Int_t           type_2lep;
   Int_t           type_3lep;
   Int_t           type_4lep;
   Bool_t          tight_1lep;
   Bool_t          tight_2lep;
   Bool_t          tight_3lep;
   Bool_t          tight_4lep;
   Float_t         dphi_1lep;
   Float_t         dphi_2lep;
   Float_t         dphi_3lep;
   Float_t         dphi_4lep;
   Float_t         mT_1lep;
   Float_t         mT_2lep;
   Float_t         mT_3lep;
   Float_t         mT_4lep;
   Int_t           origin_1lep;
   Int_t           origin_2lep;
   Int_t           origin_3lep;
   Double_t        XSecWeight;
   Float_t         weight_year;


   // variables from the truth tree

   Float_t         MC_weight_mc;
   ULong64_t       MC_eventNumber;
   UInt_t          MC_runNumber;
   Float_t         MC_weight_pileup;
   UInt_t          MC_mcChannelNumber;
   vector<float>   *PDFinfo_X1;
   vector<float>   *PDFinfo_X2;
   vector<int>     *PDFinfo_PDGID1;
   vector<int>     *PDFinfo_PDGID2;
   vector<float>   *PDFinfo_Q;
   vector<float>   *PDFinfo_XF1;
   vector<float>   *PDFinfo_XF2;
   Int_t           MC_Z_AncestryCorrupted;
   Int_t           MC_Zdecay2_pdgId;
   Int_t           MC_Wdecay1_from_t_pdgId;
   Int_t           MC_Z_IsOnShell;
   Int_t           MC_Wdecay2_from_t_pdgId;
   Int_t           MC_Zdecay1_pdgId;
   Int_t           MC_Wdecay1_from_tbar_pdgId;
   Int_t           MC_Wdecay2_from_tbar_pdgId;
   Float_t         MC_Zdecay2_pt;
   Float_t         MC_Zdecay2_m;
   Float_t         MC_Zdecay1_pt;
   Float_t         MC_Zdecay2_eta;
   Float_t         MC_Zdecay1_m;
   Float_t         MC_Z_phi;
   Float_t         MC_Z_pt;
   Float_t         MC_Z_m;
   Float_t         MC_Wdecay2_from_tbar_eta;
   Float_t         MC_Wdecay2_from_t_eta;
   Float_t         MC_Wdecay2_from_t_pt;
   Float_t         MC_Wdecay1_from_tbar_eta;
   Float_t         MC_Wdecay1_from_tbar_pt;
   Float_t         MC_Wdecay1_from_tbar_m;
   Float_t         MC_Wdecay1_from_t_phi;
   Float_t         MC_Wdecay1_from_t_pt;
   Float_t         MC_Wdecay2_from_tbar_pt;
   Float_t         MC_b_from_tbar_eta;
   Float_t         MC_b_from_tbar_m;
   Float_t         MC_Wdecay2_from_t_m;
   Float_t         MC_b_from_t_phi;
   Float_t         MC_t_afterFSR_pt;
   Float_t         MC_Wdecay2_from_tbar_phi;
   Float_t         MC_ttbar_beforeFSR_eta;
   Float_t         MC_t_afterFSR_m;
   Float_t         MC_ttbar_afterFSR_beforeDecay_phi;
   Float_t         MC_t_beforeFSR_eta;
   Float_t         MC_ttbar_afterFSR_beforeDecay_eta;
   Float_t         MC_t_afterFSR_eta;
   Float_t         MC_tbar_beforeFSR_m;
   Float_t         MC_ttbar_beforeFSR_phi;
   Float_t         MC_ttbar_afterFSR_phi;
   Float_t         MC_ttbar_beforeFSR_pt;
   Float_t         MC_ttbar_beforeFSR_m;
   Float_t         MC_W_from_t_pt;
   Float_t         MC_b_from_t_eta;
   Float_t         MC_tbar_afterFSR_phi;
   Float_t         MC_ttbar_afterFSR_pt;
   Float_t         MC_Zdecay1_phi;
   Float_t         MC_Wdecay1_from_tbar_phi;
   Float_t         MC_t_beforeFSR_phi;
   Float_t         MC_ttbar_afterFSR_m;
   Float_t         MC_ttbar_afterFSR_eta;
   Float_t         MC_Z_eta;
   Float_t         MC_t_afterFSR_phi;
   Float_t         MC_ttbar_afterFSR_beforeDecay_pt;
   Float_t         MC_ttbar_afterFSR_beforeDecay_m;
   Float_t         MC_b_from_t_pt;
   Float_t         MC_t_beforeFSR_m;
   Float_t         MC_Zdecay1_eta;
   Float_t         MC_Wdecay2_from_tbar_m;
   Float_t         MC_tbar_beforeFSR_eta;
   Float_t         MC_Zdecay2_phi;
   Float_t         MC_tbar_afterFSR_m;
   Float_t         MC_Wdecay1_from_t_m;
   Float_t         MC_tbar_beforeFSR_phi;
   Float_t         MC_b_from_tbar_pt;
   Float_t         MC_W_from_t_eta;
   Float_t         MC_tbar_afterFSR_pt;
   Float_t         MC_b_from_t_m;
   Float_t         MC_tbar_beforeFSR_pt;
   Float_t         MC_W_from_tbar_pt;
   Float_t         MC_tbar_afterFSR_eta;
   Float_t         MC_Wdecay1_from_t_eta;
   Float_t         MC_W_from_t_m;
   Float_t         MC_b_from_tbar_phi;
   Float_t         MC_W_from_t_phi;
   Float_t         MC_Wdecay2_from_t_phi;
   Float_t         MC_W_from_tbar_m;
   Float_t         MC_W_from_tbar_eta;
   Float_t         MC_t_beforeFSR_pt;
   Float_t         MC_W_from_tbar_phi;
   

   // List of branches
   TBranch        *b_weight_mc;   //!
   TBranch        *b_weight_pileup;   //!
   TBranch        *b_weight_leptonSF;   //!
   TBranch        *b_weight_bTagSF_MV2c10_77;   //!
   TBranch        *b_weight_bTagSF_MV2c10_85;   //!
   TBranch        *b_weight_bTagSF_MV2c10_Continuous;   //!
   TBranch        *b_weight_jvt;   //!
   TBranch        *b_eventNumber;   //!
   TBranch        *b_runNumber;   //!
   TBranch        *b_jet_pt;   //!
   TBranch        *b_jet_eta;   //!
   TBranch        *b_jet_phi;   //!
   TBranch        *b_jet_e;   //!
   TBranch        *b_jet_mv2c10;   //!
   TBranch        *b_jet_truthflav;   //!
   TBranch        *b_jet_truthPartonLabel;   //!
   TBranch        *b_jet_isbtagged_MV2c10_77;   //!
   TBranch        *b_jet_isbtagged_MV2c10_85;   //!
   TBranch        *b_jet_tagWeightBin_MV2c10_Continuous;   //!
   TBranch        *b_nEl;   //!
   TBranch        *b_nMu;   //!
   TBranch        *b_ht;   //!
   TBranch        *b_jet_charge;   //!
   TBranch        *b_jet_nTracks;   //!
   TBranch        *b_jet_vtx_charge;   //!
   TBranch        *b_eT_miss;   //!
   TBranch        *b_phi_miss;   //!
   TBranch        *b_nJets;   //!
   TBranch        *b_pT_1lep;   //!
   TBranch        *b_pT_2lep;   //!
   TBranch        *b_pT_3lep;   //!
   TBranch        *b_pT_4lep;   //!
   TBranch        *b_eta_1lep;   //!
   TBranch        *b_eta_2lep;   //!
   TBranch        *b_eta_3lep;   //!
   TBranch        *b_eta_4lep;   //!
   TBranch        *b_phi_1lep;   //!
   TBranch        *b_phi_2lep;   //!
   TBranch        *b_phi_3lep;   //!
   TBranch        *b_phi_4lep;   //!
   TBranch        *b_e_1lep;   //!
   TBranch        *b_e_2lep;   //!
   TBranch        *b_e_3lep;   //!
   TBranch        *b_e_4lep;   //!
   TBranch        *b_charge_1lep;   //!
   TBranch        *b_charge_2lep;   //!
   TBranch        *b_charge_3lep;   //!
   TBranch        *b_charge_4lep;   //!
   TBranch        *b_type_1lep;   //!
   TBranch        *b_type_2lep;   //!
   TBranch        *b_type_3lep;   //!
   TBranch        *b_type_4lep;   //!
   TBranch        *b_tight_1lep;   //!
   TBranch        *b_tight_2lep;   //!
   TBranch        *b_tight_3lep;   //!
   TBranch        *b_tight_4lep;   //!
   TBranch        *b_dphi_1lep;   //!
   TBranch        *b_dphi_2lep;   //!
   TBranch        *b_dphi_3lep;   //!
   TBranch        *b_dphi_4lep;   //!
   TBranch        *b_mT_1lep;   //!
   TBranch        *b_mT_2lep;   //!
   TBranch        *b_mT_3lep;   //!
   TBranch        *b_mT_4lep;   //!
   TBranch        *b_origin_1lep;   //!
   TBranch        *b_origin_2lep;   //!
   TBranch        *b_origin_3lep;   //!
   TBranch        *b_XSecWeight;   //!
   TBranch        *b_weight_year;   //!

   LooseAnalysis(TTree *tree=0);
   virtual ~LooseAnalysis();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Reconstruct();
   virtual void     LikelihoodAnalysis();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);

   bool AddFriend(TTree * tree);};
#endif

#ifdef LooseAnalysis_cxx

LooseAnalysis::LooseAnalysis(TTree *tree) : fChain(0) 
{

  l_friendTree = 0;
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.

   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/lustre/scratch/epp/atlas/tjs31/top_reco/mc.ttee.mc16a.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("/lustre/scratch/epp/atlas/tjs31/top_reco/mc.ttee.mc16a.root");
      }
      f->GetObject("nominal_Loose",tree);
   }
   Init(tree);
}

LooseAnalysis::~LooseAnalysis()
{
   if (!fChain) return;
}

Int_t LooseAnalysis::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t LooseAnalysis::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void LooseAnalysis::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   jet_pt = 0;
   jet_eta = 0;
   jet_phi = 0;
   jet_e = 0;
   jet_mv2c10 = 0;
   jet_truthflav = 0;
   jet_truthPartonLabel = 0;
   jet_isbtagged_MV2c10_77 = 0;
   jet_isbtagged_MV2c10_85 = 0;
   jet_tagWeightBin_MV2c10_Continuous = 0;
   jet_charge = 0;
   jet_nTracks = 0;
   jet_vtx_charge = 0;

   PDFinfo_X1 = 0;                                                                                                                                                                                     
   PDFinfo_X2 = 0;                                                                                                                                                                                     
   PDFinfo_PDGID1 = 0;                                                                                                                                                                                 
   PDFinfo_PDGID2 = 0;                                                                                                                                                                                 
   PDFinfo_Q = 0;                                                                                                                                                                                      
   PDFinfo_XF1 = 0;                                                                                                                                                                                    
   PDFinfo_XF2 = 0;      

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;

   fChain->SetBranchAddress("weight_mc", &weight_mc, &b_weight_mc);
   fChain->SetBranchAddress("weight_pileup", &weight_pileup, &b_weight_pileup);
   fChain->SetBranchAddress("weight_leptonSF", &weight_leptonSF, &b_weight_leptonSF);
   fChain->SetBranchAddress("weight_bTagSF_MV2c10_77", &weight_bTagSF_MV2c10_77, &b_weight_bTagSF_MV2c10_77);
   fChain->SetBranchAddress("weight_bTagSF_MV2c10_85", &weight_bTagSF_MV2c10_85, &b_weight_bTagSF_MV2c10_85);
   fChain->SetBranchAddress("weight_bTagSF_MV2c10_Continuous", &weight_bTagSF_MV2c10_Continuous, &b_weight_bTagSF_MV2c10_Continuous);
   fChain->SetBranchAddress("weight_jvt", &weight_jvt, &b_weight_jvt);
   fChain->SetBranchAddress("eventNumber", &eventNumber, &b_eventNumber);
   fChain->SetBranchAddress("runNumber", &runNumber, &b_runNumber);
   fChain->SetBranchAddress("jet_pt", &jet_pt, &b_jet_pt);
   fChain->SetBranchAddress("jet_eta", &jet_eta, &b_jet_eta);
   fChain->SetBranchAddress("jet_phi", &jet_phi, &b_jet_phi);
   fChain->SetBranchAddress("jet_e", &jet_e, &b_jet_e);
   fChain->SetBranchAddress("jet_mv2c10", &jet_mv2c10, &b_jet_mv2c10);
   fChain->SetBranchAddress("jet_truthflav", &jet_truthflav, &b_jet_truthflav);
   fChain->SetBranchAddress("jet_truthPartonLabel", &jet_truthPartonLabel, &b_jet_truthPartonLabel);
   fChain->SetBranchAddress("jet_isbtagged_MV2c10_77", &jet_isbtagged_MV2c10_77, &b_jet_isbtagged_MV2c10_77);
   fChain->SetBranchAddress("jet_isbtagged_MV2c10_85", &jet_isbtagged_MV2c10_85, &b_jet_isbtagged_MV2c10_85);
   fChain->SetBranchAddress("jet_tagWeightBin_MV2c10_Continuous", &jet_tagWeightBin_MV2c10_Continuous, &b_jet_tagWeightBin_MV2c10_Continuous);
   fChain->SetBranchAddress("nEl", &nEl, &b_nEl);
   fChain->SetBranchAddress("nMu", &nMu, &b_nMu);
   fChain->SetBranchAddress("ht", &ht, &b_ht);
   fChain->SetBranchAddress("jet_charge", &jet_charge, &b_jet_charge);
   fChain->SetBranchAddress("jet_nTracks", &jet_nTracks, &b_jet_nTracks);
   fChain->SetBranchAddress("jet_vtx_charge", &jet_vtx_charge, &b_jet_vtx_charge);
   fChain->SetBranchAddress("eT_miss", &eT_miss, &b_eT_miss);
   fChain->SetBranchAddress("phi_miss", &phi_miss, &b_phi_miss);
   fChain->SetBranchAddress("nJets", &nJets, &b_nJets);
   fChain->SetBranchAddress("pT_1lep", &pT_1lep, &b_pT_1lep);
   fChain->SetBranchAddress("pT_2lep", &pT_2lep, &b_pT_2lep);
   fChain->SetBranchAddress("pT_3lep", &pT_3lep, &b_pT_3lep);
   fChain->SetBranchAddress("pT_4lep", &pT_4lep, &b_pT_4lep);
   fChain->SetBranchAddress("eta_1lep", &eta_1lep, &b_eta_1lep);
   fChain->SetBranchAddress("eta_2lep", &eta_2lep, &b_eta_2lep);
   fChain->SetBranchAddress("eta_3lep", &eta_3lep, &b_eta_3lep);
   fChain->SetBranchAddress("eta_4lep", &eta_4lep, &b_eta_4lep);
   fChain->SetBranchAddress("phi_1lep", &phi_1lep, &b_phi_1lep);
   fChain->SetBranchAddress("phi_2lep", &phi_2lep, &b_phi_2lep);
   fChain->SetBranchAddress("phi_3lep", &phi_3lep, &b_phi_3lep);
   fChain->SetBranchAddress("phi_4lep", &phi_4lep, &b_phi_4lep);
   fChain->SetBranchAddress("e_1lep", &e_1lep, &b_e_1lep);
   fChain->SetBranchAddress("e_2lep", &e_2lep, &b_e_2lep);
   fChain->SetBranchAddress("e_3lep", &e_3lep, &b_e_3lep);
   fChain->SetBranchAddress("e_4lep", &e_4lep, &b_e_4lep);
   fChain->SetBranchAddress("charge_1lep", &charge_1lep, &b_charge_1lep);
   fChain->SetBranchAddress("charge_2lep", &charge_2lep, &b_charge_2lep);
   fChain->SetBranchAddress("charge_3lep", &charge_3lep, &b_charge_3lep);
   fChain->SetBranchAddress("charge_4lep", &charge_4lep, &b_charge_4lep);
   fChain->SetBranchAddress("type_1lep", &type_1lep, &b_type_1lep);
   fChain->SetBranchAddress("type_2lep", &type_2lep, &b_type_2lep);
   fChain->SetBranchAddress("type_3lep", &type_3lep, &b_type_3lep);
   fChain->SetBranchAddress("type_4lep", &type_4lep, &b_type_4lep);
   fChain->SetBranchAddress("tight_1lep", &tight_1lep, &b_tight_1lep);
   fChain->SetBranchAddress("tight_2lep", &tight_2lep, &b_tight_2lep);
   fChain->SetBranchAddress("tight_3lep", &tight_3lep, &b_tight_3lep);
   fChain->SetBranchAddress("tight_4lep", &tight_4lep, &b_tight_4lep);
   fChain->SetBranchAddress("dphi_1lep", &dphi_1lep, &b_dphi_1lep);
   fChain->SetBranchAddress("dphi_2lep", &dphi_2lep, &b_dphi_2lep);
   fChain->SetBranchAddress("dphi_3lep", &dphi_3lep, &b_dphi_3lep);
   fChain->SetBranchAddress("dphi_4lep", &dphi_4lep, &b_dphi_4lep);
   fChain->SetBranchAddress("mT_1lep", &mT_1lep, &b_mT_1lep);
   fChain->SetBranchAddress("mT_2lep", &mT_2lep, &b_mT_2lep);
   fChain->SetBranchAddress("mT_3lep", &mT_3lep, &b_mT_3lep);
   fChain->SetBranchAddress("mT_4lep", &mT_4lep, &b_mT_4lep);
   fChain->SetBranchAddress("origin_1lep", &origin_1lep, &b_origin_1lep);
   fChain->SetBranchAddress("origin_2lep", &origin_2lep, &b_origin_2lep);
   fChain->SetBranchAddress("origin_3lep", &origin_3lep, &b_origin_3lep);
   fChain->SetBranchAddress("XSecWeight", &XSecWeight, &b_XSecWeight);
   fChain->SetBranchAddress("weight_year", &weight_year, &b_weight_year);

   fChain->SetBranchStatus("*",0);
   fChain->SetBranchStatus("*Number",1);
   fChain->SetBranchStatus("*lep",1);
   fChain->SetBranchStatus("mT*",0);
   fChain->SetBranchStatus("tight*",0);
   fChain->SetBranchStatus("dphi*",0);
   fChain->SetBranchStatus("origin*",0);
   fChain->SetBranchStatus("jet*",1);
   Notify();
}

bool LooseAnalysis::AddFriend(TTree * tree )
{
  if (!fChain) return false;

  if (!tree) {
    std::cout << "tree is not provided" << std::endl;
    return false;
  }
  l_friendTree = tree;
  if (l_friendTree->BuildIndex("runNumber", "eventNumber") < 0){                                                                                                                                                   
    std::cerr << "Could not build truth index!" << std::endl;                                                                                                                                                    
    std::abort();                                                                                                                                                                                                
  }
  l_friendTree->SetBranchAddress("weight_mc", &MC_weight_mc);
  l_friendTree->SetBranchAddress("eventNumber", &MC_eventNumber);
  l_friendTree->SetBranchAddress("runNumber", &MC_runNumber);
  l_friendTree->SetBranchAddress("weight_pileup", &MC_weight_pileup);
  l_friendTree->SetBranchAddress("mcChannelNumber", &MC_mcChannelNumber);
  l_friendTree->SetBranchAddress("PDFinfo_X1", &PDFinfo_X1);
  l_friendTree->SetBranchAddress("PDFinfo_X2", &PDFinfo_X2);
  l_friendTree->SetBranchAddress("PDFinfo_PDGID1", &PDFinfo_PDGID1);
  l_friendTree->SetBranchAddress("PDFinfo_PDGID2", &PDFinfo_PDGID2);
  l_friendTree->SetBranchAddress("PDFinfo_Q", &PDFinfo_Q);
  l_friendTree->SetBranchAddress("PDFinfo_XF1", &PDFinfo_XF1);
  l_friendTree->SetBranchAddress("PDFinfo_XF2", &PDFinfo_XF2);
  l_friendTree->SetBranchAddress("MC_Z_AncestryCorrupted", &MC_Z_AncestryCorrupted);
  l_friendTree->SetBranchAddress("MC_Zdecay2_pdgId", &MC_Zdecay2_pdgId);
  l_friendTree->SetBranchAddress("MC_Wdecay1_from_t_pdgId", &MC_Wdecay1_from_t_pdgId);
  l_friendTree->SetBranchAddress("MC_Z_IsOnShell", &MC_Z_IsOnShell);
  l_friendTree->SetBranchAddress("MC_Wdecay2_from_t_pdgId", &MC_Wdecay2_from_t_pdgId);
  l_friendTree->SetBranchAddress("MC_Zdecay1_pdgId", &MC_Zdecay1_pdgId);
  l_friendTree->SetBranchAddress("MC_Wdecay1_from_tbar_pdgId", &MC_Wdecay1_from_tbar_pdgId);
  l_friendTree->SetBranchAddress("MC_Wdecay2_from_tbar_pdgId", &MC_Wdecay2_from_tbar_pdgId);
  l_friendTree->SetBranchAddress("MC_Zdecay2_pt", &MC_Zdecay2_pt);
  l_friendTree->SetBranchAddress("MC_Zdecay2_m", &MC_Zdecay2_m);
  l_friendTree->SetBranchAddress("MC_Zdecay1_pt", &MC_Zdecay1_pt);
  l_friendTree->SetBranchAddress("MC_Zdecay2_eta", &MC_Zdecay2_eta);
  l_friendTree->SetBranchAddress("MC_Zdecay1_m", &MC_Zdecay1_m);
  l_friendTree->SetBranchAddress("MC_Z_phi", &MC_Z_phi);
  l_friendTree->SetBranchAddress("MC_Z_pt", &MC_Z_pt);
  l_friendTree->SetBranchAddress("MC_Z_m", &MC_Z_m);
  l_friendTree->SetBranchAddress("MC_Wdecay2_from_tbar_eta", &MC_Wdecay2_from_tbar_eta);
  l_friendTree->SetBranchAddress("MC_Wdecay2_from_t_eta", &MC_Wdecay2_from_t_eta);
  l_friendTree->SetBranchAddress("MC_Wdecay2_from_t_pt", &MC_Wdecay2_from_t_pt);
  l_friendTree->SetBranchAddress("MC_Wdecay1_from_tbar_eta", &MC_Wdecay1_from_tbar_eta);
  l_friendTree->SetBranchAddress("MC_Wdecay1_from_tbar_pt", &MC_Wdecay1_from_tbar_pt);
  l_friendTree->SetBranchAddress("MC_Wdecay1_from_tbar_m", &MC_Wdecay1_from_tbar_m);
  l_friendTree->SetBranchAddress("MC_Wdecay1_from_t_phi", &MC_Wdecay1_from_t_phi);
  l_friendTree->SetBranchAddress("MC_Wdecay1_from_t_pt", &MC_Wdecay1_from_t_pt);
  l_friendTree->SetBranchAddress("MC_Wdecay2_from_tbar_pt", &MC_Wdecay2_from_tbar_pt);
  l_friendTree->SetBranchAddress("MC_b_from_tbar_eta", &MC_b_from_tbar_eta);
  l_friendTree->SetBranchAddress("MC_b_from_tbar_m", &MC_b_from_tbar_m);
  l_friendTree->SetBranchAddress("MC_Wdecay2_from_t_m", &MC_Wdecay2_from_t_m);
  l_friendTree->SetBranchAddress("MC_b_from_t_phi", &MC_b_from_t_phi);
  l_friendTree->SetBranchAddress("MC_t_afterFSR_pt", &MC_t_afterFSR_pt);
  l_friendTree->SetBranchAddress("MC_Wdecay2_from_tbar_phi", &MC_Wdecay2_from_tbar_phi);
  l_friendTree->SetBranchAddress("MC_ttbar_beforeFSR_eta", &MC_ttbar_beforeFSR_eta);
  l_friendTree->SetBranchAddress("MC_t_afterFSR_m", &MC_t_afterFSR_m);
  l_friendTree->SetBranchAddress("MC_ttbar_afterFSR_beforeDecay_phi", &MC_ttbar_afterFSR_beforeDecay_phi);
  l_friendTree->SetBranchAddress("MC_t_beforeFSR_eta", &MC_t_beforeFSR_eta);
  l_friendTree->SetBranchAddress("MC_ttbar_afterFSR_beforeDecay_eta", &MC_ttbar_afterFSR_beforeDecay_eta);
  l_friendTree->SetBranchAddress("MC_t_afterFSR_eta", &MC_t_afterFSR_eta);
  l_friendTree->SetBranchAddress("MC_tbar_beforeFSR_m", &MC_tbar_beforeFSR_m);
  l_friendTree->SetBranchAddress("MC_ttbar_beforeFSR_phi", &MC_ttbar_beforeFSR_phi);
  l_friendTree->SetBranchAddress("MC_ttbar_afterFSR_phi", &MC_ttbar_afterFSR_phi);
  l_friendTree->SetBranchAddress("MC_ttbar_beforeFSR_pt", &MC_ttbar_beforeFSR_pt);
  l_friendTree->SetBranchAddress("MC_ttbar_beforeFSR_m", &MC_ttbar_beforeFSR_m);
  l_friendTree->SetBranchAddress("MC_W_from_t_pt", &MC_W_from_t_pt);
  l_friendTree->SetBranchAddress("MC_b_from_t_eta", &MC_b_from_t_eta);
  l_friendTree->SetBranchAddress("MC_tbar_afterFSR_phi", &MC_tbar_afterFSR_phi);
  l_friendTree->SetBranchAddress("MC_ttbar_afterFSR_pt", &MC_ttbar_afterFSR_pt);
  l_friendTree->SetBranchAddress("MC_Zdecay1_phi", &MC_Zdecay1_phi);
  l_friendTree->SetBranchAddress("MC_Wdecay1_from_tbar_phi", &MC_Wdecay1_from_tbar_phi);
  l_friendTree->SetBranchAddress("MC_t_beforeFSR_phi", &MC_t_beforeFSR_phi);
  l_friendTree->SetBranchAddress("MC_ttbar_afterFSR_m", &MC_ttbar_afterFSR_m);
  l_friendTree->SetBranchAddress("MC_ttbar_afterFSR_eta", &MC_ttbar_afterFSR_eta);
  l_friendTree->SetBranchAddress("MC_Z_eta", &MC_Z_eta);
  l_friendTree->SetBranchAddress("MC_t_afterFSR_phi", &MC_t_afterFSR_phi);
  l_friendTree->SetBranchAddress("MC_ttbar_afterFSR_beforeDecay_pt", &MC_ttbar_afterFSR_beforeDecay_pt);
  l_friendTree->SetBranchAddress("MC_ttbar_afterFSR_beforeDecay_m", &MC_ttbar_afterFSR_beforeDecay_m);
  l_friendTree->SetBranchAddress("MC_b_from_t_pt", &MC_b_from_t_pt);
  l_friendTree->SetBranchAddress("MC_t_beforeFSR_m", &MC_t_beforeFSR_m);
  l_friendTree->SetBranchAddress("MC_Zdecay1_eta", &MC_Zdecay1_eta);
  l_friendTree->SetBranchAddress("MC_Wdecay2_from_tbar_m", &MC_Wdecay2_from_tbar_m);
  l_friendTree->SetBranchAddress("MC_tbar_beforeFSR_eta", &MC_tbar_beforeFSR_eta);
  l_friendTree->SetBranchAddress("MC_Zdecay2_phi", &MC_Zdecay2_phi);
  l_friendTree->SetBranchAddress("MC_tbar_afterFSR_m", &MC_tbar_afterFSR_m);
  l_friendTree->SetBranchAddress("MC_Wdecay1_from_t_m", &MC_Wdecay1_from_t_m);
  l_friendTree->SetBranchAddress("MC_tbar_beforeFSR_phi", &MC_tbar_beforeFSR_phi);
  l_friendTree->SetBranchAddress("MC_b_from_tbar_pt", &MC_b_from_tbar_pt);
  l_friendTree->SetBranchAddress("MC_W_from_t_eta", &MC_W_from_t_eta);
  l_friendTree->SetBranchAddress("MC_tbar_afterFSR_pt", &MC_tbar_afterFSR_pt);
  l_friendTree->SetBranchAddress("MC_b_from_t_m", &MC_b_from_t_m);
  l_friendTree->SetBranchAddress("MC_tbar_beforeFSR_pt", &MC_tbar_beforeFSR_pt);
  l_friendTree->SetBranchAddress("MC_W_from_tbar_pt", &MC_W_from_tbar_pt);
  l_friendTree->SetBranchAddress("MC_tbar_afterFSR_eta", &MC_tbar_afterFSR_eta);
  l_friendTree->SetBranchAddress("MC_Wdecay1_from_t_eta", &MC_Wdecay1_from_t_eta);
  l_friendTree->SetBranchAddress("MC_W_from_t_m", &MC_W_from_t_m);
  l_friendTree->SetBranchAddress("MC_b_from_tbar_phi", &MC_b_from_tbar_phi);
  l_friendTree->SetBranchAddress("MC_W_from_t_phi", &MC_W_from_t_phi);
  l_friendTree->SetBranchAddress("MC_Wdecay2_from_t_phi", &MC_Wdecay2_from_t_phi);
  l_friendTree->SetBranchAddress("MC_W_from_tbar_m", &MC_W_from_tbar_m);
  l_friendTree->SetBranchAddress("MC_W_from_tbar_eta", &MC_W_from_tbar_eta);
  l_friendTree->SetBranchAddress("MC_t_beforeFSR_pt", &MC_t_beforeFSR_pt);
  l_friendTree->SetBranchAddress("MC_W_from_tbar_phi", &MC_W_from_tbar_phi);
  
  l_friendTree->SetBranchStatus("*",0);
  l_friendTree->SetBranchStatus("*Number",1);
  l_friendTree->SetBranchStatus("MC_Wdecay*",1);
  l_friendTree->SetBranchStatus("MC_Zdecay*",1);
  l_friendTree->SetBranchStatus("MC_b_*",1);
  l_friendTree->SetBranchStatus("MC_t_afterFSR*",1);
  l_friendTree->SetBranchStatus("MC_tbar_afterFSR*",1);
  l_friendTree->SetBranchStatus("MC_W_from_*",1);
  fChain->AddFriend(l_friendTree,"",kTRUE);
  return true;
}


Bool_t LooseAnalysis::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void LooseAnalysis::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t LooseAnalysis::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}

#endif // #ifdef LooseAnalysis_cxx
