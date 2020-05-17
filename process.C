#include <TFile.h>
#include <TTree.h>
#include "Analysis/truthAnalysis.h"
#include "Analysis/nominal_LooseAnalysis.h"

void process(){
	TFile f("/lustre/scratch/epp/atlas/tjs31/top_reco/mc.ttee.mc16a.root");
	// TTree * truth = (TTree*) f.Get("truth");
	// truth->Process("/its/home/fh225/MPhys/ttV-and-EFT/Analysis/truthAnalysis.C");
	TTree * nominal_Loose = (TTree*) f.Get("nominal_Loose");
	nominal_Loose->Process("/its/home/fh225/MPhys/ttV-and-EFT/Analysis/nominal_LooseAnalysis.C");
}