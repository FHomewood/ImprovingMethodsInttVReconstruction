//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri Nov  1 12:21:48 2019 by ROOT version 6.14/04
// from TTree truth/tree
// found on file: /lustre/scratch/epp/atlas/tjs31/top_reco/mc.ttee.mc16a.root
//////////////////////////////////////////////////////////

#ifndef pippo_h
#define pippo_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "vector"
#include "vector"

class pippo {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Float_t         weight_mc;
   ULong64_t       eventNumber;
   UInt_t          runNumber;
   Float_t         weight_pileup;
   UInt_t          mcChannelNumber;
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
   TBranch        *b_eventNumber;   //!
   TBranch        *b_runNumber;   //!
   TBranch        *b_weight_pileup;   //!
   TBranch        *b_mcChannelNumber;   //!
   TBranch        *b_PDFinfo_X1;   //!
   TBranch        *b_PDFinfo_X2;   //!
   TBranch        *b_PDFinfo_PDGID1;   //!
   TBranch        *b_PDFinfo_PDGID2;   //!
   TBranch        *b_PDFinfo_Q;   //!
   TBranch        *b_PDFinfo_XF1;   //!
   TBranch        *b_PDFinfo_XF2;   //!
   TBranch        *b_MC_Z_AncestryCorrupted;   //!
   TBranch        *b_MC_Zdecay2_pdgId;   //!
   TBranch        *b_MC_Wdecay1_from_t_pdgId;   //!
   TBranch        *b_MC_Z_IsOnShell;   //!
   TBranch        *b_MC_Wdecay2_from_t_pdgId;   //!
   TBranch        *b_MC_Zdecay1_pdgId;   //!
   TBranch        *b_MC_Wdecay1_from_tbar_pdgId;   //!
   TBranch        *b_MC_Wdecay2_from_tbar_pdgId;   //!
   TBranch        *b_MC_Zdecay2_pt;   //!
   TBranch        *b_MC_Zdecay2_m;   //!
   TBranch        *b_MC_Zdecay1_pt;   //!
   TBranch        *b_MC_Zdecay2_eta;   //!
   TBranch        *b_MC_Zdecay1_m;   //!
   TBranch        *b_MC_Z_phi;   //!
   TBranch        *b_MC_Z_pt;   //!
   TBranch        *b_MC_Z_m;   //!
   TBranch        *b_MC_Wdecay2_from_tbar_eta;   //!
   TBranch        *b_MC_Wdecay2_from_t_eta;   //!
   TBranch        *b_MC_Wdecay2_from_t_pt;   //!
   TBranch        *b_MC_Wdecay1_from_tbar_eta;   //!
   TBranch        *b_MC_Wdecay1_from_tbar_pt;   //!
   TBranch        *b_MC_Wdecay1_from_tbar_m;   //!
   TBranch        *b_MC_Wdecay1_from_t_phi;   //!
   TBranch        *b_MC_Wdecay1_from_t_pt;   //!
   TBranch        *b_MC_Wdecay2_from_tbar_pt;   //!
   TBranch        *b_MC_b_from_tbar_eta;   //!
   TBranch        *b_MC_b_from_tbar_m;   //!
   TBranch        *b_MC_Wdecay2_from_t_m;   //!
   TBranch        *b_MC_b_from_t_phi;   //!
   TBranch        *b_MC_t_afterFSR_pt;   //!
   TBranch        *b_MC_Wdecay2_from_tbar_phi;   //!
   TBranch        *b_MC_ttbar_beforeFSR_eta;   //!
   TBranch        *b_MC_t_afterFSR_m;   //!
   TBranch        *b_MC_ttbar_afterFSR_beforeDecay_phi;   //!
   TBranch        *b_MC_t_beforeFSR_eta;   //!
   TBranch        *b_MC_ttbar_afterFSR_beforeDecay_eta;   //!
   TBranch        *b_MC_t_afterFSR_eta;   //!
   TBranch        *b_MC_tbar_beforeFSR_m;   //!
   TBranch        *b_MC_ttbar_beforeFSR_phi;   //!
   TBranch        *b_MC_ttbar_afterFSR_phi;   //!
   TBranch        *b_MC_ttbar_beforeFSR_pt;   //!
   TBranch        *b_MC_ttbar_beforeFSR_m;   //!
   TBranch        *b_MC_W_from_t_pt;   //!
   TBranch        *b_MC_b_from_t_eta;   //!
   TBranch        *b_MC_tbar_afterFSR_phi;   //!
   TBranch        *b_MC_ttbar_afterFSR_pt;   //!
   TBranch        *b_MC_Zdecay1_phi;   //!
   TBranch        *b_MC_Wdecay1_from_tbar_phi;   //!
   TBranch        *b_MC_t_beforeFSR_phi;   //!
   TBranch        *b_MC_ttbar_afterFSR_m;   //!
   TBranch        *b_MC_ttbar_afterFSR_eta;   //!
   TBranch        *b_MC_Z_eta;   //!
   TBranch        *b_MC_t_afterFSR_phi;   //!
   TBranch        *b_MC_ttbar_afterFSR_beforeDecay_pt;   //!
   TBranch        *b_MC_ttbar_afterFSR_beforeDecay_m;   //!
   TBranch        *b_MC_b_from_t_pt;   //!
   TBranch        *b_MC_t_beforeFSR_m;   //!
   TBranch        *b_MC_Zdecay1_eta;   //!
   TBranch        *b_MC_Wdecay2_from_tbar_m;   //!
   TBranch        *b_MC_tbar_beforeFSR_eta;   //!
   TBranch        *b_MC_Zdecay2_phi;   //!
   TBranch        *b_MC_tbar_afterFSR_m;   //!
   TBranch        *b_MC_Wdecay1_from_t_m;   //!
   TBranch        *b_MC_tbar_beforeFSR_phi;   //!
   TBranch        *b_MC_b_from_tbar_pt;   //!
   TBranch        *b_MC_W_from_t_eta;   //!
   TBranch        *b_MC_tbar_afterFSR_pt;   //!
   TBranch        *b_MC_b_from_t_m;   //!
   TBranch        *b_MC_tbar_beforeFSR_pt;   //!
   TBranch        *b_MC_W_from_tbar_pt;   //!
   TBranch        *b_MC_tbar_afterFSR_eta;   //!
   TBranch        *b_MC_Wdecay1_from_t_eta;   //!
   TBranch        *b_MC_W_from_t_m;   //!
   TBranch        *b_MC_b_from_tbar_phi;   //!
   TBranch        *b_MC_W_from_t_phi;   //!
   TBranch        *b_MC_Wdecay2_from_t_phi;   //!
   TBranch        *b_MC_W_from_tbar_m;   //!
   TBranch        *b_MC_W_from_tbar_eta;   //!
   TBranch        *b_MC_t_beforeFSR_pt;   //!
   TBranch        *b_MC_W_from_tbar_phi;   //!

   pippo(TTree *tree=0);
   virtual ~pippo();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef pippo_cxx
pippo::pippo(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/lustre/scratch/epp/atlas/tjs31/top_reco/mc.ttee.mc16a.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("/lustre/scratch/epp/atlas/tjs31/top_reco/mc.ttee.mc16a.root");
      }
      f->GetObject("truth",tree);

   }
   Init(tree);
}

pippo::~pippo()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t pippo::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t pippo::LoadTree(Long64_t entry)
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

void pippo::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
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
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("weight_mc", &weight_mc, &b_weight_mc);
   fChain->SetBranchAddress("eventNumber", &eventNumber, &b_eventNumber);
   fChain->SetBranchAddress("runNumber", &runNumber, &b_runNumber);
   fChain->SetBranchAddress("weight_pileup", &weight_pileup, &b_weight_pileup);
   fChain->SetBranchAddress("mcChannelNumber", &mcChannelNumber, &b_mcChannelNumber);
   fChain->SetBranchAddress("PDFinfo_X1", &PDFinfo_X1, &b_PDFinfo_X1);
   fChain->SetBranchAddress("PDFinfo_X2", &PDFinfo_X2, &b_PDFinfo_X2);
   fChain->SetBranchAddress("PDFinfo_PDGID1", &PDFinfo_PDGID1, &b_PDFinfo_PDGID1);
   fChain->SetBranchAddress("PDFinfo_PDGID2", &PDFinfo_PDGID2, &b_PDFinfo_PDGID2);
   fChain->SetBranchAddress("PDFinfo_Q", &PDFinfo_Q, &b_PDFinfo_Q);
   fChain->SetBranchAddress("PDFinfo_XF1", &PDFinfo_XF1, &b_PDFinfo_XF1);
   fChain->SetBranchAddress("PDFinfo_XF2", &PDFinfo_XF2, &b_PDFinfo_XF2);
   fChain->SetBranchAddress("MC_Z_AncestryCorrupted", &MC_Z_AncestryCorrupted, &b_MC_Z_AncestryCorrupted);
   fChain->SetBranchAddress("MC_Zdecay2_pdgId", &MC_Zdecay2_pdgId, &b_MC_Zdecay2_pdgId);
   fChain->SetBranchAddress("MC_Wdecay1_from_t_pdgId", &MC_Wdecay1_from_t_pdgId, &b_MC_Wdecay1_from_t_pdgId);
   fChain->SetBranchAddress("MC_Z_IsOnShell", &MC_Z_IsOnShell, &b_MC_Z_IsOnShell);
   fChain->SetBranchAddress("MC_Wdecay2_from_t_pdgId", &MC_Wdecay2_from_t_pdgId, &b_MC_Wdecay2_from_t_pdgId);
   fChain->SetBranchAddress("MC_Zdecay1_pdgId", &MC_Zdecay1_pdgId, &b_MC_Zdecay1_pdgId);
   fChain->SetBranchAddress("MC_Wdecay1_from_tbar_pdgId", &MC_Wdecay1_from_tbar_pdgId, &b_MC_Wdecay1_from_tbar_pdgId);
   fChain->SetBranchAddress("MC_Wdecay2_from_tbar_pdgId", &MC_Wdecay2_from_tbar_pdgId, &b_MC_Wdecay2_from_tbar_pdgId);
   fChain->SetBranchAddress("MC_Zdecay2_pt", &MC_Zdecay2_pt, &b_MC_Zdecay2_pt);
   fChain->SetBranchAddress("MC_Zdecay2_m", &MC_Zdecay2_m, &b_MC_Zdecay2_m);
   fChain->SetBranchAddress("MC_Zdecay1_pt", &MC_Zdecay1_pt, &b_MC_Zdecay1_pt);
   fChain->SetBranchAddress("MC_Zdecay2_eta", &MC_Zdecay2_eta, &b_MC_Zdecay2_eta);
   fChain->SetBranchAddress("MC_Zdecay1_m", &MC_Zdecay1_m, &b_MC_Zdecay1_m);
   fChain->SetBranchAddress("MC_Z_phi", &MC_Z_phi, &b_MC_Z_phi);
   fChain->SetBranchAddress("MC_Z_pt", &MC_Z_pt, &b_MC_Z_pt);
   fChain->SetBranchAddress("MC_Z_m", &MC_Z_m, &b_MC_Z_m);
   fChain->SetBranchAddress("MC_Wdecay2_from_tbar_eta", &MC_Wdecay2_from_tbar_eta, &b_MC_Wdecay2_from_tbar_eta);
   fChain->SetBranchAddress("MC_Wdecay2_from_t_eta", &MC_Wdecay2_from_t_eta, &b_MC_Wdecay2_from_t_eta);
   fChain->SetBranchAddress("MC_Wdecay2_from_t_pt", &MC_Wdecay2_from_t_pt, &b_MC_Wdecay2_from_t_pt);
   fChain->SetBranchAddress("MC_Wdecay1_from_tbar_eta", &MC_Wdecay1_from_tbar_eta, &b_MC_Wdecay1_from_tbar_eta);
   fChain->SetBranchAddress("MC_Wdecay1_from_tbar_pt", &MC_Wdecay1_from_tbar_pt, &b_MC_Wdecay1_from_tbar_pt);
   fChain->SetBranchAddress("MC_Wdecay1_from_tbar_m", &MC_Wdecay1_from_tbar_m, &b_MC_Wdecay1_from_tbar_m);
   fChain->SetBranchAddress("MC_Wdecay1_from_t_phi", &MC_Wdecay1_from_t_phi, &b_MC_Wdecay1_from_t_phi);
   fChain->SetBranchAddress("MC_Wdecay1_from_t_pt", &MC_Wdecay1_from_t_pt, &b_MC_Wdecay1_from_t_pt);
   fChain->SetBranchAddress("MC_Wdecay2_from_tbar_pt", &MC_Wdecay2_from_tbar_pt, &b_MC_Wdecay2_from_tbar_pt);
   fChain->SetBranchAddress("MC_b_from_tbar_eta", &MC_b_from_tbar_eta, &b_MC_b_from_tbar_eta);
   fChain->SetBranchAddress("MC_b_from_tbar_m", &MC_b_from_tbar_m, &b_MC_b_from_tbar_m);
   fChain->SetBranchAddress("MC_Wdecay2_from_t_m", &MC_Wdecay2_from_t_m, &b_MC_Wdecay2_from_t_m);
   fChain->SetBranchAddress("MC_b_from_t_phi", &MC_b_from_t_phi, &b_MC_b_from_t_phi);
   fChain->SetBranchAddress("MC_t_afterFSR_pt", &MC_t_afterFSR_pt, &b_MC_t_afterFSR_pt);
   fChain->SetBranchAddress("MC_Wdecay2_from_tbar_phi", &MC_Wdecay2_from_tbar_phi, &b_MC_Wdecay2_from_tbar_phi);
   fChain->SetBranchAddress("MC_ttbar_beforeFSR_eta", &MC_ttbar_beforeFSR_eta, &b_MC_ttbar_beforeFSR_eta);
   fChain->SetBranchAddress("MC_t_afterFSR_m", &MC_t_afterFSR_m, &b_MC_t_afterFSR_m);
   fChain->SetBranchAddress("MC_ttbar_afterFSR_beforeDecay_phi", &MC_ttbar_afterFSR_beforeDecay_phi, &b_MC_ttbar_afterFSR_beforeDecay_phi);
   fChain->SetBranchAddress("MC_t_beforeFSR_eta", &MC_t_beforeFSR_eta, &b_MC_t_beforeFSR_eta);
   fChain->SetBranchAddress("MC_ttbar_afterFSR_beforeDecay_eta", &MC_ttbar_afterFSR_beforeDecay_eta, &b_MC_ttbar_afterFSR_beforeDecay_eta);
   fChain->SetBranchAddress("MC_t_afterFSR_eta", &MC_t_afterFSR_eta, &b_MC_t_afterFSR_eta);
   fChain->SetBranchAddress("MC_tbar_beforeFSR_m", &MC_tbar_beforeFSR_m, &b_MC_tbar_beforeFSR_m);
   fChain->SetBranchAddress("MC_ttbar_beforeFSR_phi", &MC_ttbar_beforeFSR_phi, &b_MC_ttbar_beforeFSR_phi);
   fChain->SetBranchAddress("MC_ttbar_afterFSR_phi", &MC_ttbar_afterFSR_phi, &b_MC_ttbar_afterFSR_phi);
   fChain->SetBranchAddress("MC_ttbar_beforeFSR_pt", &MC_ttbar_beforeFSR_pt, &b_MC_ttbar_beforeFSR_pt);
   fChain->SetBranchAddress("MC_ttbar_beforeFSR_m", &MC_ttbar_beforeFSR_m, &b_MC_ttbar_beforeFSR_m);
   fChain->SetBranchAddress("MC_W_from_t_pt", &MC_W_from_t_pt, &b_MC_W_from_t_pt);
   fChain->SetBranchAddress("MC_b_from_t_eta", &MC_b_from_t_eta, &b_MC_b_from_t_eta);
   fChain->SetBranchAddress("MC_tbar_afterFSR_phi", &MC_tbar_afterFSR_phi, &b_MC_tbar_afterFSR_phi);
   fChain->SetBranchAddress("MC_ttbar_afterFSR_pt", &MC_ttbar_afterFSR_pt, &b_MC_ttbar_afterFSR_pt);
   fChain->SetBranchAddress("MC_Zdecay1_phi", &MC_Zdecay1_phi, &b_MC_Zdecay1_phi);
   fChain->SetBranchAddress("MC_Wdecay1_from_tbar_phi", &MC_Wdecay1_from_tbar_phi, &b_MC_Wdecay1_from_tbar_phi);
   fChain->SetBranchAddress("MC_t_beforeFSR_phi", &MC_t_beforeFSR_phi, &b_MC_t_beforeFSR_phi);
   fChain->SetBranchAddress("MC_ttbar_afterFSR_m", &MC_ttbar_afterFSR_m, &b_MC_ttbar_afterFSR_m);
   fChain->SetBranchAddress("MC_ttbar_afterFSR_eta", &MC_ttbar_afterFSR_eta, &b_MC_ttbar_afterFSR_eta);
   fChain->SetBranchAddress("MC_Z_eta", &MC_Z_eta, &b_MC_Z_eta);
   fChain->SetBranchAddress("MC_t_afterFSR_phi", &MC_t_afterFSR_phi, &b_MC_t_afterFSR_phi);
   fChain->SetBranchAddress("MC_ttbar_afterFSR_beforeDecay_pt", &MC_ttbar_afterFSR_beforeDecay_pt, &b_MC_ttbar_afterFSR_beforeDecay_pt);
   fChain->SetBranchAddress("MC_ttbar_afterFSR_beforeDecay_m", &MC_ttbar_afterFSR_beforeDecay_m, &b_MC_ttbar_afterFSR_beforeDecay_m);
   fChain->SetBranchAddress("MC_b_from_t_pt", &MC_b_from_t_pt, &b_MC_b_from_t_pt);
   fChain->SetBranchAddress("MC_t_beforeFSR_m", &MC_t_beforeFSR_m, &b_MC_t_beforeFSR_m);
   fChain->SetBranchAddress("MC_Zdecay1_eta", &MC_Zdecay1_eta, &b_MC_Zdecay1_eta);
   fChain->SetBranchAddress("MC_Wdecay2_from_tbar_m", &MC_Wdecay2_from_tbar_m, &b_MC_Wdecay2_from_tbar_m);
   fChain->SetBranchAddress("MC_tbar_beforeFSR_eta", &MC_tbar_beforeFSR_eta, &b_MC_tbar_beforeFSR_eta);
   fChain->SetBranchAddress("MC_Zdecay2_phi", &MC_Zdecay2_phi, &b_MC_Zdecay2_phi);
   fChain->SetBranchAddress("MC_tbar_afterFSR_m", &MC_tbar_afterFSR_m, &b_MC_tbar_afterFSR_m);
   fChain->SetBranchAddress("MC_Wdecay1_from_t_m", &MC_Wdecay1_from_t_m, &b_MC_Wdecay1_from_t_m);
   fChain->SetBranchAddress("MC_tbar_beforeFSR_phi", &MC_tbar_beforeFSR_phi, &b_MC_tbar_beforeFSR_phi);
   fChain->SetBranchAddress("MC_b_from_tbar_pt", &MC_b_from_tbar_pt, &b_MC_b_from_tbar_pt);
   fChain->SetBranchAddress("MC_W_from_t_eta", &MC_W_from_t_eta, &b_MC_W_from_t_eta);
   fChain->SetBranchAddress("MC_tbar_afterFSR_pt", &MC_tbar_afterFSR_pt, &b_MC_tbar_afterFSR_pt);
   fChain->SetBranchAddress("MC_b_from_t_m", &MC_b_from_t_m, &b_MC_b_from_t_m);
   fChain->SetBranchAddress("MC_tbar_beforeFSR_pt", &MC_tbar_beforeFSR_pt, &b_MC_tbar_beforeFSR_pt);
   fChain->SetBranchAddress("MC_W_from_tbar_pt", &MC_W_from_tbar_pt, &b_MC_W_from_tbar_pt);
   fChain->SetBranchAddress("MC_tbar_afterFSR_eta", &MC_tbar_afterFSR_eta, &b_MC_tbar_afterFSR_eta);
   fChain->SetBranchAddress("MC_Wdecay1_from_t_eta", &MC_Wdecay1_from_t_eta, &b_MC_Wdecay1_from_t_eta);
   fChain->SetBranchAddress("MC_W_from_t_m", &MC_W_from_t_m, &b_MC_W_from_t_m);
   fChain->SetBranchAddress("MC_b_from_tbar_phi", &MC_b_from_tbar_phi, &b_MC_b_from_tbar_phi);
   fChain->SetBranchAddress("MC_W_from_t_phi", &MC_W_from_t_phi, &b_MC_W_from_t_phi);
   fChain->SetBranchAddress("MC_Wdecay2_from_t_phi", &MC_Wdecay2_from_t_phi, &b_MC_Wdecay2_from_t_phi);
   fChain->SetBranchAddress("MC_W_from_tbar_m", &MC_W_from_tbar_m, &b_MC_W_from_tbar_m);
   fChain->SetBranchAddress("MC_W_from_tbar_eta", &MC_W_from_tbar_eta, &b_MC_W_from_tbar_eta);
   fChain->SetBranchAddress("MC_t_beforeFSR_pt", &MC_t_beforeFSR_pt, &b_MC_t_beforeFSR_pt);
   fChain->SetBranchAddress("MC_W_from_tbar_phi", &MC_W_from_tbar_phi, &b_MC_W_from_tbar_phi);
   Notify();
}

Bool_t pippo::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void pippo::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t pippo::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef pippo_cxx
