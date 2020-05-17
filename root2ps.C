string root2ps(){
	TFile truthFile("/its/home/fh225/MPhys/ttV-and-EFT/RootFiles/PDFs.root");
    TIter keyList(truthFile.GetListOfKeys());
   	TKey *key;
   	TCanvas c1;
   	c1.Print("/its/home/fh225/MPhys/ttV-and-EFT/RootFiles/PDFs..ps[");
   	while ((key = (TKey*)keyList())) {
      TClass *cl = gROOT->GetClass(key->GetClassName());
      if (!cl->InheritsFrom("TH1")) continue;
      TH1 *h = (TH1*)key->ReadObj();
      h->Draw();
      c1.Print("/its/home/fh225/MPhys/ttV-and-EFT/RootFiles/PDFs.ps");
   	}
   	c1.Print("/its/home/fh225/MPhys/ttV-and-EFT/RootFiles/PDFs.ps]");
      return "Finished";
}
