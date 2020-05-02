#include "../baseCodeForPlots/comparisonPlots.C"

void runValidationPlots()
{
  gROOT->ProcessLine(".L ../baseCodeForPlots/comparisonPlots.C");
 
  TString treePath = "l1NtupleProducer/Stage2/efficiencyTree";
  TString inputDirectory  = "/scratch/skkwan/Run2Ntuplizer/2020-Apr-27_Run2_ggHtautau.root";
  TString outputDirectory = "comparisonPlots/test_";

  TString sigCut = "recoTauPt>10 && genTauPt>10 && genTauDM>9 && l1TauPt>0";
  TString bkgCut = "genTauPt<5";

  comparisonPlots("l1TauPt", sigCut, bkgCut, treePath, inputDirectory, outputDirectory, "l1TauPt", 60, 0, 120);
  comparisonPlots("l1TauEta", sigCut, bkgCut, treePath, inputDirectory, outputDirectory, "l1TauEta", 60, -3, 3);
  comparisonPlots("l1TauPhi", sigCut, bkgCut, treePath, inputDirectory, outputDirectory, "l1TauPhi", 60, -4, 4);
  // l1IsoEt does not have the tau included in the sum                                                                                                               
  comparisonPlots("l1IsoEt", sigCut, bkgCut, treePath, inputDirectory, outputDirectory, "l1IsoEt", 40, 0, 80);

}
