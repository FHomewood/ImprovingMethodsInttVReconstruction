#define LooseAnalysis_cxx
#include "LooseAnalysis.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TLorentzVector.h>
#include <TH1F.h>

#include <TGraph.h>
#include <cmath>
#include <iostream>

//Defining the Likelihood function used to determine whether a set of quarks is more or less probable to be
//correctly reconstructed
//returns the natural log of the likelihood as a float
float Likelihood(std::map<std::string, TH1F*> PDFs /*Probability density functions*/,
                 std::vector<TLorentzVector> Quarks /*Reco Quark Combination*/)
{
   //proposed quark matching variables are denoted with a R_ prefix
   float R_TopMass = (Quarks[1] + Quarks[2] + Quarks[3]).M(); //Value of Top mass according to Reco Quark Combination
   float R_WMass = (Quarks[2] + Quarks[3]).M(); //Value of W mass according to Reco Quark Combination
   
   //Initial value of LogLikelihood is zero then we add to it
   float LogLikelihood = 0;
   //Add the log Probability of finding a Top of this mass according to the probability density functions
   LogLikelihood += log(PDFs["Top_Mass"] -> GetBinContent(PDFs["Top_Mass"] -> GetXaxis() -> FindBin(R_TopMass)));
   //Do the same with the proposed W mass
   LogLikelihood += log(PDFs["W_Mass"] -> GetBinContent(PDFs["W_Mass"] -> GetXaxis() -> FindBin(R_WMass)));
   //return the value of the LogLikelihood of this Quark Combination
   return LogLikelihood;
}

void LooseAnalysis::LikelihoodAnalysis()
{
   std::cout<<"Maximising Likelihood"<<std::endl;
   float DRThreshold = 1*pow(10,-1);
   //Initialize three Histograms that will store the DeltaR between each of the splits in our dataset
   TH1F* DeltaR_LikelihoodMatching_Reconstructed = new TH1F( "DeltaR_LikelihoodMatching_Reconstructed", "DeltaR_LikelihoodMatching_Reconstructed",20,0,5);
   TH1F* DeltaR_LikelihoodMatching_Truth = new TH1F( "DeltaR_LikelihoodMatching_Truth", "DeltaR_LikelihoodMatching_Truth",20,0,5);
   TH1F* DeltaR_Reconstructed_Truth = new TH1F( "DeltaR_Reconstructed_Truth", "DeltaR_Reconstructed_Truth",20,0,5);

   //Initialize the TTree which stores the reconstructed information about the event
   TFile Infile("~/MPhys/ttV-and-EFT/RootFiles/output.root", "READ");
   TTree* EventTree = nullptr;
   Infile.GetObject("EventTree",EventTree);

   //initialize TTree Variables
   Float_t isTextbook              = 0;
   Float_t leptonic_b_pt           = 0;
   Float_t leptonic_b_eta          = 0;
   Float_t leptonic_b_phi          = 0;
   Float_t leptonic_b_e            = 0;
   Float_t hadronic_b_pt           = 0;
   Float_t hadronic_b_eta          = 0;
   Float_t hadronic_b_phi          = 0;
   Float_t hadronic_b_e            = 0;
   Float_t hadronic_Wproduct1_pt   = 0;
   Float_t hadronic_Wproduct1_eta  = 0;
   Float_t hadronic_Wproduct1_phi  = 0;
   Float_t hadronic_Wproduct1_e    = 0;
   Float_t hadronic_Wproduct2_pt   = 0;
   Float_t hadronic_Wproduct2_eta  = 0;
   Float_t hadronic_Wproduct2_phi  = 0;
   Float_t hadronic_Wproduct2_e    = 0;

   //and assign the TTree variable to these addresses
   EventTree->SetBranchAddress("isTextbook",&isTextbook);
   EventTree->SetBranchAddress("leptonic_b_pt",&leptonic_b_pt);
   EventTree->SetBranchAddress("leptonic_b_eta",&leptonic_b_eta);
   EventTree->SetBranchAddress("leptonic_b_phi",&leptonic_b_phi);
   EventTree->SetBranchAddress("leptonic_b_e",&leptonic_b_e);
   EventTree->SetBranchAddress("hadronic_b_pt",&hadronic_b_pt);
   EventTree->SetBranchAddress("hadronic_b_eta",&hadronic_b_eta);
   EventTree->SetBranchAddress("hadronic_b_phi",&hadronic_b_phi);
   EventTree->SetBranchAddress("hadronic_b_e",&hadronic_b_e);
   EventTree->SetBranchAddress("hadronic_Wproduct1_pt",&hadronic_Wproduct1_pt);
   EventTree->SetBranchAddress("hadronic_Wproduct1_eta",&hadronic_Wproduct1_eta);
   EventTree->SetBranchAddress("hadronic_Wproduct1_phi",&hadronic_Wproduct1_phi);
   EventTree->SetBranchAddress("hadronic_Wproduct1_e",&hadronic_Wproduct1_e);
   EventTree->SetBranchAddress("hadronic_Wproduct2_pt",&hadronic_Wproduct2_pt);
   EventTree->SetBranchAddress("hadronic_Wproduct2_eta",&hadronic_Wproduct2_eta);
   EventTree->SetBranchAddress("hadronic_Wproduct2_phi",&hadronic_Wproduct2_phi);
   EventTree->SetBranchAddress("hadronic_Wproduct2_e",&hadronic_Wproduct2_e);

   //assign the stored PDF histograms in the InFile
   std::map<std::string,TH1F*> PDFs;
   PDFs["Top_Mass"] = nullptr;
   PDFs["W_Mass"] = nullptr;
   Infile.GetObject("PDF_Top_Mass",PDFs["Top_Mass"]);
   Infile.GetObject("PDF_W_Mass",PDFs["W_Mass"]);

   //if the tree isn't found then stop
   if (fChain == 0) return;
   //an optional debug printout
   bool debug = false;

   //Parameters used to define Acc, Eff and Likelihood Efficiency
   Long64_t N_Total = fChain->GetEntriesFast(),N_Truth = 0,N_Reco = 0,N_Likelihood = 0;
   bool isinTotal = true,isinTruth, isinReco,isinLikelihood;

   //an empty TLorentzVector used to quickly store four momenta without unneccesary initializations
   TLorentzVector temp;
   temp.SetPtEtaPhiE(0,0,0,0);

   //Start looping through fChain entries
   Long64_t nentries = fChain->GetEntriesFast();
   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries; jentry++) {
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      EventTree->GetEntry(jentry);
      Int_t nBytesRead = l_friendTree->GetEntryWithIndex(runNumber, eventNumber);
      //if no bytes are read then we will report that the event wasn't matched
      if ( nBytesRead < 0 )  {
         std::cout << "Event number " << eventNumber << " in run " << runNumber << " NO MATCH FOUND!!!" << std::endl;
         continue;
      }

      //printout to show how far through the data we are
      if ((100*jentry / nentries) % 10 == 0 && (100*(jentry-1) / nentries) % 10 != 0) std::cout<<100*(float)jentry/nentries<<"%"<<std::endl;

      //
      // Determine whether the Parton level data is within signal region
      //

      //These variables are what we defined as our signal cut in the reco data
      int nlep  = 0;
      int njet  = 0;
      int nbjet = 0;

      //So lets look at the Parton level objects and see if they match this definition
      std::vector<int> objects = {  MC_Wdecay1_from_t_pdgId,
                                    MC_Wdecay2_from_t_pdgId,
                                    MC_Wdecay1_from_tbar_pdgId,
                                    MC_Wdecay2_from_tbar_pdgId,
                                    MC_Zdecay1_pdgId,
                                    MC_Zdecay2_pdgId            };
      //loop through all objects with pdgId data and see what value they are
      for (unsigned int i = 0; i < objects.size(); i++){
         // if the object is a lepton
         if (objects[i] == +11) nlep++;
         if (objects[i] == -11) nlep++;
         if (objects[i] == +13) nlep++;
         if (objects[i] == -13) nlep++;
         if (objects[i] == +15) nlep++; //I doubt tau will be an issue
         if (objects[i] == -15) nlep++; //but it's here for completeness

         // if the object is a quark
         if(objects[i] > -9 && objects[i] < 9) njet++;
         // and a bquark
         if(objects[i] == 5 || objects[i] == -5) nbjet++;
      }
      // the top quark b decays don't have MC pdgId data so I'm using whether their mass was nonzero
      if (MC_b_from_t_m > 1000) {nbjet++; njet++;}
      if (MC_b_from_tbar_m > 1000) {nbjet++; njet++;}

      //Then apply the Signal Region condition
      if(nlep == 3 && njet >= 4 && nbjet >= 2){
         isinTruth = true;
         N_Truth++;
      } else {isinTruth = false;}

      
      if(isTextbook){
         if ( isinTruth ){
            isinReco = true;
            N_Reco++;
         } else {isinReco = false;}
         TLorentzVector temp;

         //Assign all parton variables to four vector arrays
         std::vector<TLorentzVector> JetList;
         std::vector<TLorentzVector> bJetList;

         for (unsigned int i = 0; i < jet_pt -> size(); ++i){
            temp.SetPtEtaPhiE( jet_pt -> at(i) , jet_eta -> at(i) , jet_phi -> at(i) , jet_e -> at(i) );
            temp = 0.001 * temp; //converting to GeV
            if ( (int)(jet_isbtagged_MV2c10_77->at(i)) == 1) { bJetList.push_back(temp); }
            else { JetList.push_back(temp); }
         }

         //define a map to hold all likelihood values of all combinations (including quark swaps)
         std::map< float, std::vector<TLorentzVector> > ComboLikelihoods; 
         //This goes through all combinations of quarks in order to find maximal likelihood combination
         if (bJetList.size() > 1 && JetList.size() > 1){
            //for each combination of b jets
            for (unsigned int b1index = 0; b1index < bJetList.size(); b1index++){
               for (unsigned int b2index = 0; b2index < bJetList.size(); b2index++){
                  if (b1index != b2index){//not including repeat quarks

                     //for each combination of light flavour jets
                     for (unsigned int q1index = 0; q1index < JetList.size(); q1index++){
                        for (unsigned int q2index = 0; q2index < JetList.size(); q2index++){
                           if (q1index != q2index)//not including repeat quarks
                           {
                              //store the quark combination and the log(Likelihood) of that combination
                              std::vector<TLorentzVector> Quarks = {bJetList[b1index],bJetList[b2index],JetList[q1index],JetList[q2index]};
                              ComboLikelihoods[ Likelihood(PDFs,Quarks) ] = Quarks;
                           }
                        }
                     }
                  }
               }
            }
         
         

            float MaxLikelihood = -9999; //initialise the minimum possible likelihood (just a very negative number) This is sufficient as ML is of the order of 10^1
            std::vector<TLorentzVector> combination; //and a place to store the optimal combinations
            for (auto MapEntry : ComboLikelihoods)
               if (MapEntry.first > MaxLikelihood)
               {
                  MaxLikelihood = MapEntry.first;
                  combination = MapEntry.second;
               }

            std::vector<TLorentzVector> Reconstructed_combination;

            //Read the root file to get the expected b1b2q1q2 combo then we can compare it with the Likelihood predictions
            temp.SetPtEtaPhiE(leptonic_b_pt,leptonic_b_eta,leptonic_b_phi,leptonic_b_e);
            Reconstructed_combination.push_back(temp);
            temp.SetPtEtaPhiE(hadronic_b_pt,hadronic_b_eta,hadronic_b_phi,hadronic_b_e);
            Reconstructed_combination.push_back(temp);
            temp.SetPtEtaPhiE(hadronic_Wproduct1_pt,hadronic_Wproduct1_eta,hadronic_Wproduct1_phi,hadronic_Wproduct1_e);
            Reconstructed_combination.push_back(temp);
            temp.SetPtEtaPhiE(hadronic_Wproduct2_pt,hadronic_Wproduct2_eta,hadronic_Wproduct2_phi,hadronic_Wproduct2_e);
            Reconstructed_combination.push_back(temp);


            if (Reconstructed_combination.size() > 3 && combination.size() > 3){

               //swap bjets if to try to align them to the reconstructed ones (just if they've been assigned in the wrong order)
               if (Reconstructed_combination[0].DeltaR(combination[0]) > Reconstructed_combination[0].DeltaR(combination[1])){
                     temp = combination[0];
                     combination[0] = combination[1];
                     combination[1] = temp;
               }
               //do the same thing for q1 and q2
               if (Reconstructed_combination[2].DeltaR(combination[2]) > Reconstructed_combination[2].DeltaR(combination[3])){
                     temp = combination[2];
                     combination[2] = combination[3];
                     combination[3] = temp;
               }

               float DeltaR = 0;
               for (int i = 0; i < 4; i++) DeltaR += Reconstructed_combination[i].DeltaR(combination[i]);
               DeltaR /= 4;

               if(isinReco && DeltaR < DRThreshold){
                  N_Likelihood++;
                  isinLikelihood = true;
               } else {
                  isinLikelihood = false;
               }
               if(jentry < 100){
                  if (isinLikelihood)
                     std::cout<<"Event Number "<< jentry << " IS in the Likelihood Region"<<std::endl;
                  else 
                     std::cout<<"Event Number "<< jentry << " is NOT in the Likelihood Region"<<std::endl;
                  for (unsigned int i = 0; i < jet_pt->size();++i)
                     std::cout<<"jet: "<< jet_pt->at(i) <<"\t"<<jet_phi->at(i)<<"\t"<<jet_eta->at(i)<<"\t"<<jet_e->at(i)<<std::endl;
               }
               DeltaR_LikelihoodMatching_Reconstructed -> Fill(DeltaR);
            }

            std::vector<TLorentzVector> Truth_combination;

            //Assign the correct truth quarks
            //Wproducts: 
             //first condition should check if both are hadronic but both added for redundancy
            
            if (MC_Wdecay1_from_t_pdgId < 10 && MC_Wdecay2_from_t_pdgId > -10)
            {
               temp.SetPtEtaPhiM(MC_b_from_tbar_pt,MC_b_from_tbar_eta,MC_b_from_tbar_phi,MC_b_from_tbar_m);
               Truth_combination.push_back(temp);
               temp.SetPtEtaPhiM(MC_b_from_t_pt,MC_b_from_t_eta,MC_b_from_t_phi,MC_b_from_t_m);
               Truth_combination.push_back(temp);
               temp.SetPtEtaPhiM(MC_Wdecay1_from_t_pt,MC_Wdecay1_from_t_eta,MC_Wdecay1_from_t_phi,MC_Wdecay1_from_t_m);
               Truth_combination.push_back(temp);
               temp.SetPtEtaPhiM(MC_Wdecay2_from_t_pt,MC_Wdecay2_from_t_eta,MC_Wdecay2_from_t_phi,MC_Wdecay2_from_t_m);
               Truth_combination.push_back(temp);
            } else {
               temp.SetPtEtaPhiM(MC_b_from_t_pt,MC_b_from_t_eta,MC_b_from_t_phi,MC_b_from_t_m);
               Truth_combination.push_back(temp);
               temp.SetPtEtaPhiM(MC_b_from_tbar_pt,MC_b_from_tbar_eta,MC_b_from_tbar_phi,MC_b_from_tbar_m);
               Truth_combination.push_back(temp);
               temp.SetPtEtaPhiM(MC_Wdecay1_from_tbar_pt,MC_Wdecay1_from_tbar_eta,MC_Wdecay1_from_tbar_phi,MC_Wdecay1_from_tbar_m);
               Truth_combination.push_back(temp);
               temp.SetPtEtaPhiM(MC_Wdecay2_from_tbar_pt,MC_Wdecay2_from_tbar_eta,MC_Wdecay2_from_tbar_phi,MC_Wdecay2_from_tbar_m);
               Truth_combination.push_back(temp);
            }

            if (Truth_combination.size() > 3 && combination.size() > 3){

               //swap bjets if to try to align them to the reconstructed ones (just if they've been assigned in the wrong order)
               if (Truth_combination[0].DeltaR(combination[0]) > Truth_combination[0].DeltaR(combination[1])){
                     temp = combination[0];
                     combination[0] = combination[1];
                     combination[1] = temp;
               }
               //do the same thing for q1 and q2
               if (Truth_combination[2].DeltaR(combination[2]) > Truth_combination[2].DeltaR(combination[3])){
                     temp = combination[2];
                     combination[2] = combination[3];
                     combination[3] = temp;
               }

               float DeltaR = 0;
               for (int i = 0; i < 4; i++) DeltaR += Truth_combination[i].DeltaR(combination[i]);
               DeltaR /= 4;
               
               DeltaR_LikelihoodMatching_Truth -> Fill(DeltaR);
            }
            float DeltaR = 0;
            for (int i = 0; i < 4; i++) DeltaR += Truth_combination[i].DeltaR(Reconstructed_combination[i]);
            DeltaR /= 4;
            DeltaR_Reconstructed_Truth->Fill(DeltaR);
         }
      }
   }
            Infile.Close();

            TFile Outfile("~/MPhys/ttV-and-EFT/RootFiles/Likelihoods.root", "RECREATE");
            DeltaR_LikelihoodMatching_Reconstructed->Write();
            DeltaR_LikelihoodMatching_Truth -> Write();
            DeltaR_Reconstructed_Truth -> Write();
            Outfile.Close();

            std::cout<<"Acceptance :\t"<<(float)N_Truth/N_Total<<std::endl;
            std::cout<<"Experiment Efficiency :\t"<<(float)N_Reco/N_Truth<<std::endl;
            std::cout<<"Threshold:\t"<<(float)DRThreshold<<std::endl;
            std::cout<<"Likelihood Efficiency :\t"<<(float)N_Likelihood/N_Reco<<std::endl;

}

void LooseAnalysis::Reconstruct()
{
   //Initialise Config Variables
   bool debug = false;
   float DRThreshold = 1 * pow(10,-16);
   float Target_ZMass = 91.1876 /* GeV */;
   float Target_WMass = 80.379 /* GeV */;
   float Target_tMass = 173.0 /* GeV */;

   unsigned long textbook = 0;
   unsigned long notTextbook = 0;

   TFile OutFile("~/MPhys/ttV-and-EFT/RootFiles/output.root","RECREATE");
   TTree* EventTree = new TTree("EventTree","EventTree");
   std::map<std::string, TBranch*> BranchMap;
   Float_t isTextbook              = 0;
   Float_t leptonic_b_pt           = 0;
   Float_t leptonic_b_eta          = 0;
   Float_t leptonic_b_phi          = 0;
   Float_t leptonic_b_e            = 0;
   Float_t hadronic_b_pt           = 0;
   Float_t hadronic_b_eta          = 0;
   Float_t hadronic_b_phi          = 0;
   Float_t hadronic_b_e            = 0;
   Float_t hadronic_Wproduct1_pt   = 0;
   Float_t hadronic_Wproduct1_eta  = 0;
   Float_t hadronic_Wproduct1_phi  = 0;
   Float_t hadronic_Wproduct1_e    = 0;
   Float_t hadronic_Wproduct2_pt   = 0;
   Float_t hadronic_Wproduct2_eta  = 0;
   Float_t hadronic_Wproduct2_phi  = 0;
   Float_t hadronic_Wproduct2_e    = 0;
   BranchMap["isTextbook"]             = EventTree->Branch("isTextbook",            &isTextbook,            "F");
   BranchMap["leptonic_b_pt"]          = EventTree->Branch("leptonic_b_pt",         &leptonic_b_pt,         "F");
   BranchMap["leptonic_b_eta"]         = EventTree->Branch("leptonic_b_eta",        &leptonic_b_eta,        "F");
   BranchMap["leptonic_b_phi"]         = EventTree->Branch("leptonic_b_phi",        &leptonic_b_phi,        "F");
   BranchMap["leptonic_b_e"]           = EventTree->Branch("leptonic_b_e",          &leptonic_b_e,          "F");
   BranchMap["hadronic_b_pt"]          = EventTree->Branch("hadronic_b_pt",         &hadronic_b_pt,         "F");
   BranchMap["hadronic_b_eta"]         = EventTree->Branch("hadronic_b_eta",        &hadronic_b_eta,        "F");
   BranchMap["hadronic_b_phi"]         = EventTree->Branch("hadronic_b_phi",        &hadronic_b_phi,        "F");
   BranchMap["hadronic_b_e"]           = EventTree->Branch("hadronic_b_e",          &hadronic_b_e,          "F");
   BranchMap["hadronic_Wproduct1_pt"]  = EventTree->Branch("hadronic_Wproduct1_pt", &hadronic_Wproduct1_pt, "F");
   BranchMap["hadronic_Wproduct1_eta"] = EventTree->Branch("hadronic_Wproduct1_eta",&hadronic_Wproduct1_eta,"F");
   BranchMap["hadronic_Wproduct1_phi"] = EventTree->Branch("hadronic_Wproduct1_phi",&hadronic_Wproduct1_phi,"F");
   BranchMap["hadronic_Wproduct1_e"]   = EventTree->Branch("hadronic_Wproduct1_e",  &hadronic_Wproduct1_e,  "F");
   BranchMap["hadronic_Wproduct2_pt"]  = EventTree->Branch("hadronic_Wproduct2_pt", &hadronic_Wproduct2_pt, "F");
   BranchMap["hadronic_Wproduct2_eta"] = EventTree->Branch("hadronic_Wproduct2_eta",&hadronic_Wproduct2_eta,"F");
   BranchMap["hadronic_Wproduct2_phi"] = EventTree->Branch("hadronic_Wproduct2_phi",&hadronic_Wproduct2_phi,"F");
   BranchMap["hadronic_Wproduct2_e"]   = EventTree->Branch("hadronic_Wproduct2_e",  &hadronic_Wproduct2_e,  "F");

   std::map<std::string, TH1F *> HistMap;

   //Reconstructed Quantities
   HistMap["RECO_JetMass"] = new TH1F( "RECO_JetMass", "RECO_JetMass",50,4,100);
   HistMap["RECO_N_bJets"] = new TH1F( "RECO_N_bJets", "RECO_N_bJets",5,0,5);
   HistMap["RECO_Z_Mass"] = new TH1F( "RECO_Z_Mass", "RECO_Z_Mass",50,50,130);
   HistMap["RECO_Hadronic_W_Mass"] = new TH1F( "RECO_Hadronic_W_Mass", "RECO_Hadronic_W_Mass",200,0,1000);
   HistMap["RECO_Hadronic_Top_Mass"] = new TH1F( "RECO_Hadronic_Top_Mass", "RECO_Hadronic_Top_Mass",50,50,250);
   HistMap["RECO_Leptonic_W_TransverseMass"] = new TH1F( "RECO_Leptonic_W_TransverseMass", "RECO_Leptonic_W_TransverseMass",50,0,120);
   HistMap["isTextBook"] = new TH1F( "isTextBook", "isTextBook",2,0,2);
   HistMap["Truth_Top_Mass"] = new TH1F( "Truth_Top_Mass", "Truth_Top_Mass",50,50,250);

   //DeltaR Plots
   HistMap["DeltaR_Z_Products"] = new TH1F( "DeltaR_Z_Products", "DeltaR_Z_Products",20,0,6);
   HistMap["DeltaR_Hadronic_W"] = new TH1F( "DeltaR_Hadronic_W", "DeltaR_Hadronic_W",20,0,6);
   HistMap["DeltaR_bJets"] = new TH1F( "DeltaR_bJets", "DeltaR_bJets",20,0,6);
   HistMap["DeltaR_Hadronic_T"] = new TH1F( "DeltaR_Hadronic_T", "DeltaR_Hadronic_T",20,0,6);
   //Likelihood pdfs
   HistMap["PtRatio_b1"] = new TH1F( "PtRatio_b1","PtRatio_b1",20,0,2 );
   HistMap["PtRatio_b2"] = new TH1F( "PtRatio_b2","PtRatio_b2",20,0,2 );
   HistMap["PtRatio_q1"] = new TH1F( "PtRatio_q1","PtRatio_q1",20,0,2 );
   HistMap["PtRatio_q2"] = new TH1F( "PtRatio_q2","PtRatio_q2",20,0,2 );

   //2D histograms
   TH2F* q1_scatter = new TH2F("q1_scatter","q1_scatter",20,0,4,32,0,3.2);
   TH2F* q2_scatter = new TH2F("q2_scatter","q2_scatter",20,0,4,32,0,3.2);


   TLorentzVector Truth_quarks[4];
   std::cout<<"Plotting PDF Graphs"<<std::endl;
   if (fChain == 0) return;
   Long64_t nentries = fChain->GetEntriesFast();
   Long64_t nbytes = 0, nb = 0;

   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      Int_t nBytesRead = l_friendTree->GetEntryWithIndex(runNumber, eventNumber);
      if ( nBytesRead < 0 ){                                                                                                                                    
      	std::cout << "Event number " << eventNumber << " in run " << runNumber << " NO MATCH FOUND!!!" << std::endl;
      	continue;
      }
      if (jentry > 15) debug = false;
      if (debug) std::cout << "\n\nNew event " <<jentry<<"\n\n" << std::endl;
      //Short hand progress report stdout
      if ((100*jentry / nentries) % 10 == 0 && (100*(jentry-1) / nentries) % 10 != 0) std::cout<<100*(float)jentry/nentries<<"%"<<std::endl;

      TLorentzVector temp; //temporary vector used to swap and scale four momenta in more compact ways
      TLorentzVector Truth_Hadronic_W_Momentum;
      TLorentzVector Truth_Leptonic_W_Momentum;
      TLorentzVector Truth_Hadronic_Top_Momentum;
      TLorentzVector Truth_Leptonic_Top_Momentum;

      TLorentzVector b1,b2,q1,q2;
      //Initialize quark array for Likelihood analysis
      //set all four vectors to zero
      for (int i = 0; i<4; i++)Truth_quarks[i].SetPtEtaPhiE(0,0,0,0);

      //Assign all parton variables to four vector arrays
      std::vector<TLorentzVector> JetList;
      std::vector<TLorentzVector> bJetList;
      std::vector<TLorentzVector> LepList;
      bool isTextBook = true;
      
      for (unsigned int i = 0; i < jet_pt -> size(); ++i){
      	temp.SetPtEtaPhiE( jet_pt -> at(i) , jet_eta -> at(i) , jet_phi -> at(i) , jet_e -> at(i) );
	if (debug){
	  std::cout << "reco jet " << i << " 4-vector: \t" << temp.Pt() << '\t' << temp.Eta() << '\t' << temp.Phi() << '\t' << temp.M() << " isbtagged " << ((int)jet_isbtagged_MV2c10_77->at(i)) << std::endl;
	}
	temp = 0.001 * temp; //converting to GeV
	 if ( (int)(jet_isbtagged_MV2c10_77->at(i)) == 1) { bJetList.push_back(temp); }
	 else { JetList.push_back(temp); }
	 HistMap["RECO_JetMass"]->Fill(temp.M());
      }
      HistMap["RECO_N_bJets"]->Fill((float) bJetList.size());
      //Top mass
      if (MC_Wdecay1_from_t_pdgId < 10 && MC_Wdecay2_from_t_pdgId > -10) //first condition should check if both are hadronic but both added for redundancy
	{
	  temp.SetPtEtaPhiM(MC_t_afterFSR_pt,MC_t_afterFSR_eta,MC_t_afterFSR_phi,MC_t_afterFSR_m);
	  if (debug){
	    std::cout << "Hadronic top 4v \t" << temp.Pt() << '\t' << temp.Eta() << '\t' << temp.Phi() << '\t' << temp.M() << std::endl;
	  }
	  temp = 0.001*temp;
	  HistMap["Truth_Top_Mass"] -> Fill(temp.M());
          
         }
         else if (MC_Wdecay1_from_tbar_pdgId < 10 && MC_Wdecay2_from_tbar_pdgId > -10)
         {
            temp.SetPtEtaPhiM(MC_tbar_afterFSR_pt,MC_tbar_afterFSR_eta,MC_tbar_afterFSR_phi,MC_tbar_afterFSR_m);
	  if (debug){
	    std::cout << "Hadronic tbar 4v \t" << temp.Pt() << '\t' << temp.Eta() << '\t' << temp.Phi() << '\t' << temp.M() << std::endl;
	  }
            HistMap["Truth_Top_Mass"] -> Fill(temp.M());
         }

      //VALIDATE
      if (bJetList.size() == 3){
         float minimumPt = bJetList[0].Pt(); //start by assuming the first entry is the lowest pt
         int minIndex = 0;
         for (unsigned int i = 0 ; i < bJetList.size(); ++i)
            if (bJetList[i].Pt() < minimumPt){
               minimumPt = bJetList[i].Pt();
               minIndex = i;
            }
         bJetList.erase(bJetList.begin() + minIndex);
      }
      if (bJetList.size() < 2 || JetList.size() < 2) isTextBook = false;

      std::vector<float> lep_pt   = {pT_1lep,  pT_2lep,  pT_3lep,  pT_4lep };
      std::vector<float> lep_eta  = {eta_1lep, eta_2lep, eta_3lep, eta_4lep};
      std::vector<float> lep_phi  = {phi_1lep, phi_2lep, phi_3lep, phi_4lep};
      std::vector<float> lep_e    = {e_1lep,   e_2lep,   e_3lep,   e_4lep  };
      std::vector<int> lep_charge = {charge_1lep,   charge_2lep,   charge_3lep,   charge_4lep };
      std::vector<int> lep_flav   = {type_1lep,     type_2lep,     type_3lep,     type_4lep   };
      std::vector<Lepton> v_lep;
      for (int i = 0; i < 4; ++i){
         temp.SetPtEtaPhiE(lep_pt[i], lep_eta[i], lep_phi[i], lep_e[i]);
	  if (debug){
	    std::cout << "lepton " << i  << "\t\t" << temp.Pt() << '\t' << temp.Eta() << '\t' << temp.Phi() << '\t' << temp.M() << std::endl;
	  }
         if(temp.Pt() > 0.00001) { 
      	   LepList.push_back(temp);
      	   Lepton lep;
      	   lep.GetP4().SetPtEtaPhiE(lep_pt[i],lep_eta[i], lep_phi[i], lep_e[i]);
      	   lep.SetCharge(lep_charge[i]);
      	   lep.SetFlavour(lep_flav[i]);
      	   v_lep.push_back(lep);
	      }
      }
      if(LepList.size() < 3) isTextbook = false;

      //mll test for z boson reconstruction
      std::vector< std::vector<float> > z_productCandidates; //vector of vectors for storing Z-mass candidates. Not intuitive, but does the job
      for (unsigned int i = 0; i < v_lep.size(); ++i){
      	for (unsigned int j = 0; j < v_lep.size(); ++j){
      	   if (  i < j &&                                 //not the same lepton and not double counted
         		v_lep[i].GetFlavour() == v_lep[j].GetFlavour() &&      //same flavour
         		v_lep[i].GetCharge() == -v_lep[j].GetCharge())         //opposite sign 
            {
	            z_productCandidates.push_back({(float)i,(float)j,(float)(v_lep[i].GetP4() + v_lep[j].GetP4() ).M()}); //remember possible z decays
            }
         }
      }

      //then we must find which one ( if any ) matches the z decay
      //picking most likely z decays by which matches the invariant Z mass best
      std::vector<float> z_products = {-1, -1, -10000};
      for ( auto OSSFpair : z_productCandidates )
         if ((OSSFpair[2] - Target_ZMass)*(OSSFpair[2] - Target_ZMass) < (z_products[2] - Target_ZMass)*(z_products[2]-Target_ZMass))
            z_products = OSSFpair;

      // if (z_products[0] < 0) isTextBook = false;
      else HistMap["RECO_Z_Mass"]->Fill(z_products[2]);
      temp = LepList[z_products[0]];
      if (debug) std::cout<<"z decay 1: \t\t"<< temp.Pt() << '\t' << temp.Eta() << '\t' << temp.Phi() << '\t' << temp.M() << std::endl;
      temp = LepList[z_products[1]];
      if (debug) std::cout<<"z decay 2: \t\t"<< temp.Pt() << '\t' << temp.Eta() << '\t' << temp.Phi() << '\t' << temp.M() << std::endl;




      if (isTextBook)
      {
	      if (debug) {std::cout<<"selection passed"<<std::endl;}

         //Hadronic W decay
         std::vector<float> hW_products = {-1,-1, -1000};
         for (unsigned int i = 0; i < JetList.size(); ++i){
            for (unsigned int j = 0; j < i; ++j){
               float _mass = (JetList[i] + JetList[j]).M();
               if( (_mass - Target_WMass)*(_mass - Target_WMass) < (hW_products[2] - Target_WMass)*(hW_products[2] - Target_WMass) ) //here W mass is given in MeV
                  hW_products = {(float)i,(float)j,_mass};
            }
         }

         TLorentzVector Hadronic_W_Momentum = JetList[hW_products[0]] + JetList[hW_products[1]];
         float Hadronic_W_DeltaR;
         //assign temp and truth_quarks to the hadronic W then use throughout
         if (MC_Wdecay1_from_t_pdgId < 10 && MC_Wdecay2_from_t_pdgId > -10) //first condition should check if both are hadronic but both added for redundancy
         {
            temp.SetPtEtaPhiM(MC_W_from_t_pt,MC_W_from_t_eta,MC_W_from_t_phi,MC_W_from_t_m);
            Truth_quarks[2].SetPtEtaPhiM(MC_Wdecay1_from_t_pt,MC_Wdecay1_from_t_eta,MC_Wdecay1_from_t_phi,MC_Wdecay1_from_t_m);
            Truth_quarks[3].SetPtEtaPhiM(MC_Wdecay2_from_t_pt,MC_Wdecay2_from_t_eta,MC_Wdecay2_from_t_phi,MC_Wdecay2_from_t_m);
         } else {
            temp.SetPtEtaPhiM(MC_W_from_tbar_pt,MC_W_from_tbar_eta,MC_W_from_tbar_phi,MC_W_from_tbar_m);
            Truth_quarks[2].SetPtEtaPhiM(MC_Wdecay1_from_tbar_pt,MC_Wdecay1_from_tbar_eta,MC_Wdecay1_from_tbar_phi,MC_Wdecay1_from_tbar_m);
            Truth_quarks[3].SetPtEtaPhiM(MC_Wdecay2_from_tbar_pt,MC_Wdecay2_from_tbar_eta,MC_Wdecay2_from_tbar_phi,MC_Wdecay2_from_tbar_m);
         }
         Hadronic_W_DeltaR = Hadronic_W_Momentum.DeltaR(temp);

         if (debug) std::cout<<"truth w decay 1: \t"<< Truth_quarks[2].Pt() << '\t' << Truth_quarks[2].Eta() << '\t' << Truth_quarks[2].Phi() << '\t' << Truth_quarks[2].M() << std::endl;
         if (debug) std::cout<<"truth w decay 2: \t"<< Truth_quarks[3].Pt() << '\t' << Truth_quarks[3].Eta() << '\t' << Truth_quarks[3].Phi() << '\t' << Truth_quarks[3].M() << std::endl;


         //Align Hadronic W products with their respected RECO four momentum [0] -> q1, [1] -> q2
         if (Truth_quarks[2].DeltaR(JetList[hW_products[0]]) < Truth_quarks[3].DeltaR(JetList[hW_products[0]]))
         {
            q1 = 1000*JetList[hW_products[0]];
            q2 = 1000*JetList[hW_products[1]];
         } else {
            q1 = 1000*JetList[hW_products[1]];
            q2 = 1000*JetList[hW_products[0]];
         }
	  temp = q1;
      if (debug) std::cout<<"reco w decay 1: \t"<< temp.Pt() << '\t' << temp.Eta() << '\t' << temp.Phi() << '\t' << temp.M() << std::endl;
      temp = q2;
      if (debug) std::cout<<"reco w decay 2: \t"<< temp.Pt() << '\t' << temp.Eta() << '\t' << temp.Phi() << '\t' << temp.M() << std::endl;
         HistMap["PtRatio_q1"] ->Fill(q1.Pt()/Truth_quarks[2].Pt());
         HistMap["PtRatio_q2"] ->Fill(q2.Pt()/Truth_quarks[3].Pt()); 

         q1_scatter -> Fill(q1.Pt()/Truth_quarks[2].Pt(),q1.DeltaR(Truth_quarks[2]));
         q2_scatter -> Fill(q2.Pt()/Truth_quarks[3].Pt(),q2.DeltaR(Truth_quarks[3]));

         HistMap["RECO_Hadronic_W_Mass"] -> Fill(hW_products[2]);
         HistMap["DeltaR_Hadronic_W"] -> Fill(Hadronic_W_DeltaR);
         if (Hadronic_W_DeltaR < DRThreshold) isTextbook = false;

         //Hadronic T decay
         float Hadronic_Top_Delta_R;
         if (isTextBook /*so far*/){
            if( pow((bJetList[0] + Hadronic_W_Momentum).M() - Target_tMass,2) < pow((bJetList[1] + Hadronic_W_Momentum).M() - Target_tMass,2)){
               b1 = bJetList[1]; //assign bjet from leptonic top
               b2 = bJetList[0]; //assign bjet from hadronic top
            } else {
               b1 = bJetList[0]; //assign bjet from leptonic top
               b2 = bJetList[1]; //assign bjet from hadronic top
            }
      temp = b1;
      if (debug) std::cout<<"leptonic b: \t\t"<< temp.Pt() << '\t' << temp.Eta() << '\t' << temp.Phi() << '\t' << temp.M() << std::endl;
      temp = b2;
      if (debug) std::cout<<"hadronic b: \t\t"<< temp.Pt() << '\t' << temp.Eta() << '\t' << temp.Phi() << '\t' << temp.M() << std::endl;
            TLorentzVector Hadronic_Top_Momentum = (b2 + Hadronic_W_Momentum);

            //Here is where we are picking up the wrong top quark, this explains the dR peak at pi
            //Should be fixed now, we're filtering to find just the hadronic top
            if (MC_Wdecay1_from_t_pdgId < 10 && MC_Wdecay2_from_t_pdgId > -10)
            {
               temp.SetPtEtaPhiM(MC_t_afterFSR_pt,MC_t_afterFSR_eta,MC_t_afterFSR_phi,MC_t_afterFSR_m); 
            } else {
               temp.SetPtEtaPhiM(MC_tbar_afterFSR_pt,MC_tbar_afterFSR_eta,MC_tbar_afterFSR_phi,MC_tbar_afterFSR_m); 
            }

            Hadronic_Top_Delta_R = Hadronic_Top_Momentum.DeltaR(temp);
            HistMap["DeltaR_Hadronic_T"] -> Fill(Hadronic_Top_Delta_R);
            HistMap["RECO_Hadronic_Top_Mass"] -> Fill(Hadronic_Top_Momentum.M());
            if (Hadronic_Top_Delta_R < DRThreshold) isTextbook = false;
         }

         //Leptonic W decay
         TLorentzVector Wlep = LepList[0];
         for (unsigned int i = 0; i < LepList.size(); ++i)
            if (i != z_products[0] && i != z_products[1]){
               Wlep = LepList[i];
         }
         //I'm sorry, still haven't changed this 
         float phi_difference = Wlep.Phi() - phi_miss;
         phi_difference += (phi_difference > 3.14159) ? -2*3.14159 : (phi_difference<-3.14159) ? 2*3.14159 : 0;

         float transverseMass = sqrt(2 * Wlep.Et() * eT_miss * (1-cos(phi_difference)));
         HistMap["RECO_Leptonic_W_TransverseMass"]->Fill(transverseMass);
         

         //Z product DeltaR
         TLorentzVector MC_Zdecay1,MC_Zdecay2;
         MC_Zdecay1.SetPtEtaPhiM(MC_Zdecay1_pt,MC_Zdecay1_eta,MC_Zdecay1_phi,MC_Zdecay1_m);
         MC_Zdecay2.SetPtEtaPhiM(MC_Zdecay2_pt,MC_Zdecay2_eta,MC_Zdecay2_phi,MC_Zdecay2_m);
         if (MC_Zdecay1.DeltaR(LepList[z_products[0]]) < MC_Zdecay2.DeltaR(LepList[z_products[0]]))
         {
            HistMap["DeltaR_Z_Products"] ->Fill(MC_Zdecay1.DeltaR(LepList[z_products[0]]));
            HistMap["DeltaR_Z_Products"] ->Fill(MC_Zdecay2.DeltaR(LepList[z_products[1]]));
         } else {
            HistMap["DeltaR_Z_Products"] ->Fill(MC_Zdecay1.DeltaR(LepList[z_products[1]]));
            HistMap["DeltaR_Z_Products"] ->Fill(MC_Zdecay2.DeltaR(LepList[z_products[0]]));
         }

         //bJet DeltaR
         Truth_quarks[0].SetPtEtaPhiM(MC_b_from_t_pt   ,MC_b_from_t_eta   ,MC_b_from_t_phi   ,MC_b_from_t_m   );
         Truth_quarks[1].SetPtEtaPhiM(MC_b_from_tbar_pt,MC_b_from_tbar_eta,MC_b_from_tbar_phi,MC_b_from_tbar_m);

         if (MC_Wdecay1_from_t_pdgId < 10 && MC_Wdecay2_from_t_pdgId > -10)
         {
            HistMap["DeltaR_bJets"]      ->Fill(Truth_quarks[0].DeltaR(b2));
            HistMap["DeltaR_bJets"]      ->Fill(Truth_quarks[1].DeltaR(b1));

            HistMap["PtRatio_b1"]        ->Fill(1000*b2.Pt()/Truth_quarks[0].Pt());
            HistMap["PtRatio_b2"]        ->Fill(1000*b1.Pt()/Truth_quarks[1].Pt());
         } else {
            HistMap["DeltaR_bJets"]      ->Fill(Truth_quarks[0].DeltaR(b1));
            HistMap["DeltaR_bJets"]      ->Fill(Truth_quarks[1].DeltaR(b2));

            HistMap["PtRatio_b1"]        ->Fill(1000*b1.Pt()/Truth_quarks[0].Pt());
            HistMap["PtRatio_b2"]        ->Fill(1000*b2.Pt()/Truth_quarks[1].Pt());
         }

      }
      if(isTextBook){
         textbook++;
         HistMap["isTextBook"] -> Fill(isTextBook);
      } else {
         notTextbook++;
         HistMap["isTextBook"] -> Fill(isTextBook);
      }

      isTextbook              = (Float_t)isTextBook;
      leptonic_b_pt           = (Float_t)b1.Pt();
      leptonic_b_eta          = (Float_t)b1.Eta();
      leptonic_b_phi          = (Float_t)b1.Phi();
      leptonic_b_e            = (Float_t)b1.E();
      hadronic_b_pt           = (Float_t)b2.Pt();
      hadronic_b_eta          = (Float_t)b2.Eta();
      hadronic_b_phi          = (Float_t)b2.Phi();
      hadronic_b_e            = (Float_t)b2.E();
      hadronic_Wproduct1_pt   = (Float_t)q1.Pt();
      hadronic_Wproduct1_eta  = (Float_t)q1.Eta();
      hadronic_Wproduct1_phi  = (Float_t)q1.Phi();
      hadronic_Wproduct1_e    = (Float_t)q1.E();
      hadronic_Wproduct2_pt   = (Float_t)q2.Pt();
      hadronic_Wproduct2_eta  = (Float_t)q2.Eta();
      hadronic_Wproduct2_phi  = (Float_t)q2.Phi();
      hadronic_Wproduct2_e    = (Float_t)q2.E();

      EventTree->Fill();
   } // end of loop on entries

   std::cout<<"Percent Textbook: "<<100*textbook/(notTextbook + textbook)<<"%"<<std::endl;

   //Construct and normalize the PDFs
   std::map<std::string,TH1F*> PDFs;
   PDFs["Top Mass"] = HistMap["RECO_Hadronic_Top_Mass"];
   PDFs["W Mass"] = HistMap["RECO_Hadronic_W_Mass"];

   // Create output files 
   for (auto MapEntry : HistMap) MapEntry.second -> Write();
   for (auto MapEntry : PDFs) MapEntry.second->Scale(1/MapEntry.second->Integral(-10000,10000));
   PDFs["Top Mass"] -> SetName("PDF_Top_Mass");
   PDFs["Top Mass"] -> SetTitle("PDF_Top_Mass");
   PDFs["W Mass"] -> SetName("PDF_W_Mass");
   PDFs["W Mass"] -> SetTitle("PDF_W_Mass");
   for (auto MapEntry : PDFs) MapEntry.second -> Write();
   EventTree  -> Write();
   q1_scatter -> Write();
   q2_scatter -> Write();
   OutFile.Close();
}
