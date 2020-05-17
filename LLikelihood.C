#include <TFile.h>
#include <TTree.h>

void LLikelihood(){
	TFile f("/lustre/scratch/epp/atlas/tjs31/top_reco/mc.ttee.mc16a.root");
	TTree * nominal_Loose = (TTree*) f.Get("nominal_Loose");
	TTree * truth = (TTree *) f.Get("truth");
	LooseAnalysis myanalysis(nominal_Loose);
	std::cout<<"Truth Tree: "<<truth<<std::endl<<"Reco Tree : "<<nominal_Loose<<std::endl;
	if (!myanalysis.AddFriend(truth)){
	  std::cout << "Cannot add friend tree, exiting...." << std::endl;
	  return;
	}
	if (truth->BuildIndex("runNumber", "eventNumber") < 0){
	    std::cerr << "Could not build truth index!" << std::endl;
	    std::abort();
	}
	
	myanalysis.LikelihoodAnalysis();
}
