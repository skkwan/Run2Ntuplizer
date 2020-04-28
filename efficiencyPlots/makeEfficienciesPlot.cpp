/*******************************************************************/
/* makeEfficienciesPlot.cpp                                        */
/* ROOT macro                                                      */
/* Usage: root -l -b -q makeEfficienciesPlot.cpp                   */
/*******************************************************************/

#include "efficiencyHist.cpp"
#include "calculateEfficiency.cpp"

#include <string>
/*********************************************************************/

/* Plots L1 tau efficiency for different BDT discriminant working
   points. */

void makeEfficienciesPlot(void)
{
  gROOT->ProcessLine(".L calculateEfficiency.cpp");

  /* Load the TTree. */
  TString treePath = "l1NtupleProducer/Stage2/efficiencyTree";
  //  TString rootFileDirectory = "../test/analyzer.root";
  TString rootFileDirectory = "/scratch/skkwan/Run2Ntuplizer/2020-Apr-27_Run2_ggHtautau.root";
  TString outputDirectory = "plots/";

  float xMin, xMax;
  TString recoCut, l1Cut;

  /*******************************************************/
  /* efficiency as a function of recoPt                  */
  /*******************************************************/

  xMin = 0;
  xMax = 100;
  recoCut = "recoTauPt>10 && genTauPt>10";
  l1Cut   = "recoTauPt>10 && genTauPt>10 && l1TauPt>0";
  
  std::vector<TGraphAsymmErrors*> vGraphs;
  std::vector<TString> vLabels;
  std::vector<int> vColors;


  TGraphAsymmErrors* recoTauPtLoose = calculateEfficiency("recoTauPt", treePath, rootFileDirectory,
							  l1Cut + "&& l1IsoEt < 15",
							  recoCut, xMin, xMax, true);
  vGraphs.push_back(recoTauPtLoose);
  vLabels.push_back("L1 iso E_{T} < 15");
  vColors.push_back(kBlue-3);

  TGraphAsymmErrors* recoTauPtMedium = calculateEfficiency("recoTauPt", treePath, rootFileDirectory,
							   l1Cut + "&& l1IsoEt < 10",
							   recoCut, xMin, xMax, true);
  vGraphs.push_back(recoTauPtMedium);
  vLabels.push_back("L1 iso E_{T} < 10");
  vColors.push_back(kViolet-5);
  
  TGraphAsymmErrors* recoTauPtTight = calculateEfficiency("recoTauPt", treePath, rootFileDirectory,
							  l1Cut + "&& l1IsoEt < 5",
							  recoCut, xMin, xMax, true);
  vGraphs.push_back(recoTauPtTight);
  vLabels.push_back("L1 iso E_{T} < 5");
  vColors.push_back(kPink+6);

  TGraphAsymmErrors* recoTauPtAll = calculateEfficiency("recoTauPt", treePath, rootFileDirectory,
							l1Cut,
							recoCut, xMin, xMax, true);

  vGraphs.push_back(recoTauPtAll);
  vLabels.push_back("All");
  vColors.push_back(kAzure+1);

  plotNEfficiencies(vGraphs, vLabels, vColors,
		    "Reco #tau_{H} p_{T} [GeV]",
		    "Run II L1 Taus",                                                                                
		    "efficiency_noIso.png",        
		    outputDirectory);    

  /*
    plotFiveHists(
		recoTauPtNoBDT, "All", kAzure+1,
		recoTauPtTight, "L1 iso E_{T} < 5", kBlue-3,
		recoTauPtMedium, "L1 iso E_{T} < 10", kViolet-5,
		recoTauPtLoose, "L1 iso E_{T} < 15", kPink+8,
		recoTauPtVLoose, "L1 iso E_{T} < 20", kPink+6,
		"Reco #tau_{H} p_{T} [GeV]",
		"Run II L1 Taus",
		"efficiency_test.png",
		outputDirectory);
  */




    
  /*******************************************************/
  /* efficiency as a function of recoEta                 */
  /*******************************************************/
  /*  xMin = -3;
  xMax = 3;
  
  recoCut = "recoTauPt>30 && genPt>20 && l1Track_pt>10 && genDM>9";
  l1Cut   = "recoTauPt>30 && genPt>20 && l1Track_pt>10 && genDM>9 && l1TauPt>10";

  TGraphAsymmErrors* effVsRecoEta90 = calculateEfficiency("recoEta", treePath, rootFileDirectory,
							  l1Cut + "&& (l1BDTDisriminant > -0.0435867)",
							  recoCut, xMin, xMax, false);
  TGraphAsymmErrors* effVsRecoEta95 = calculateEfficiency("recoEta", treePath, rootFileDirectory,
                                                          l1Cut + "&& (l1BDTDisriminant > -0.0486184)",
							  recoCut, xMin, xMax, false);
  TGraphAsymmErrors* effVsRecoEtaNoBDT = calculateEfficiency("recoEta", treePath, rootFileDirectory, 
							     l1Cut,
							     recoCut, xMin, xMax, false);

  plotThreeHists(
		 effVsRecoEta90, "BDT Loose",
		 effVsRecoEta95, "BDT VLoose",
		 effVsRecoEtaNoBDT, "No BDT",
		 "Reco #tau_{H} #eta",
		 "Phase 2 L1 Taus (all #tau_{H} decay modes)",
		 "effVsRecoEta_allDM_l1TracksPt10.png",
		 outputDirectory);
  */
}


/*********************************************************************/
