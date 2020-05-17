#define nominal_LooseAnalysis_cxx

#include "nominal_LooseAnalysis.h"
#include <TH2.h>
#include <TStyle.h>
#include <vector>

/******Global Variables******/

std::vector<TH1*> HistVec;

unsigned long textbook = 0;
unsigned long notTextbook = 0;

/******Initialisation Procedure******/
void nominal_LooseAnalysis::Begin(TTree * /*tree*/)
{
   //initialize global variables
   TString option = GetOption();
   HistVec.push_back(new TH1F( "jetMass", "jetMass",
      200,20000,10000));
   HistVec.push_back(new TH1F( "DeltaR", "DeltaR",
      20,-5,5));
   HistVec.push_back(new TH1F( "Z_Mass", "Z_Mass",
      80,0,200));
}

/******Entry Loop Function******/
Bool_t nominal_LooseAnalysis::Process(Long64_t entry)
{
   fReader.SetEntry(entry);
      GetEntry(entry); // loads all used variables into memory via SetBranchAddress
      TLorentzVector temp;
      //Assign all parton variables to four vector arrays
      std::vector<TLorentzVector> JetList;
      std::vector<TLorentzVector> bJetList;
      std::vector<TLorentzVector> LepList;

      bool isTextBook = 1;

      for (int i = 0; i < jet_pt.GetSize(); ++i){
         temp.SetPtEtaPhiE(jet_pt[i],jet_eta[i],jet_phi[i],jet_e[i]);
         if ((int)(jet_isbtagged_MV2c10_77[i]) == 1) bJetList.push_back(temp);
         else JetList.push_back(temp);
         HistVec[0]->Fill(temp.M());
      }
      if (bJetList.size() < 2) isTextBook = 0;
      std::vector<float> lep_pt  = {*pT_1lep,  *pT_2lep,  *pT_3lep,  *pT_4lep };
      std::vector<float> lep_eta = {*eta_1lep, *eta_2lep, *eta_3lep, *eta_4lep};
      std::vector<float> lep_phi = {*phi_1lep, *phi_2lep, *phi_3lep, *phi_4lep};
      std::vector<float> lep_e   = {*e_1lep,   *e_2lep,   *e_3lep,   *e_4lep  };
      for (int i = 0; i < 4; ++i){
         temp.SetPtEtaPhiE(lep_pt[i], lep_eta[i], lep_phi[i], lep_e[i]);
         LepList.push_back(temp);
      }

      std::vector<int> lep_charge = {*charge_1lep,   *charge_2lep,   *charge_3lep,   *charge_4lep };
      std::vector<int> lep_flav   = {*type_1lep,     *type_2lep,     *type_3lep,     *type_4lep   };

// for (auto i : LepList)
// for (std::vector<TLorentzVector>::iterator l = LepList.begin(); l != LepList.end(); ++l) i->Charge()

   //mll test for z boson reconstruction
   int z1lep = -1;
   int z2lep = -1;
   for (int i = 0; i < 4; ++i){
      for (int j = 0; j < 4; ++j){
         if (i < j &&                                 //not the same lepton and not double counted
             LepList[i].Pt() != 0 &&                  //the i'th lepton is actually measured
             LepList[j].Pt() != 0 &&                  //the j'th lepton is actually measured
             lep_flav[i] == lep_flav[j] &&            //same flavour
             lep_charge[i] == - lep_charge[j]){       //opposite sign 
            z1lep = i; //remember z decays
            z2lep = j;
            HistVec[2]->Fill((LepList[i] + LepList[j]).M());  // Maybe a better choice in case of more than one SFOS pair is to pick the one with mass closest to the Z boson
         }
      }
   }

   if (z1lep < 0 || z2lep < 0) isTextBook = 0;


   if (entry == 2){

      cout<<endl<< "EVENT: "<< entry <<endl;
      for (int i = 0; i < JetList.size(); i++) cout<< jet_isbtagged_MV2c10_77[i] << "Jet: " << JetList[i].Pt() << endl;
      for (int i = 0; i < bJetList.size(); i++) cout<< "B-Jet: " << bJetList[i].Pt() << endl;
      for (int i = 0; i < 4; i++) cout<< "Lepton: " << LepList[i].Pt() << endl;

      for (auto i : JetList)  HistVec[1]->Fill(i.DeltaR(JetList[0]));
      //for (auto i : bJetList) HistVec[1]->Fill(i.DeltaR(JetList[0]));
      for (int i = 0; i < 4 ; ++i) {
          if(i != z1lep && i != z2lep)

            HistVec[1]->Fill(LepList[i].DeltaR(JetList[0]));
      }
   }

   if(isTextBook) textbook++;
   else notTextbook++;
   return kTRUE;
}

/******Final Procedure******/
void nominal_LooseAnalysis::Terminate()
{//Save outputs to a root file
   TFile OutFile("~/MPhys/ttV-and-EFT/RootFiles/nominal_LooseAnalysis.root","RECREATE");
   for (auto i : HistVec) i -> Write();
   OutFile.Close();
   cout<<"Percent Textbook: " << 100 * float(textbook) / (notTextbook + textbook) << "%"<<endl;
   cout<<"Finished nominal_Loose Analysis"<<endl;

}

void nominal_LooseAnalysis::SlaveTerminate()
{  }

void nominal_LooseAnalysis::SlaveBegin(TTree * /*tree*/)
{   TString option = GetOption();   }
