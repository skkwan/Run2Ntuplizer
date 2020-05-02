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

  std::vector<TGraphAsymmErrors*> vGraphs;
  std::vector<TString> vLabels;
  std::vector<int> vColors;

  /*******************************************************/
  /* efficiency as a function of recoPt                  */
  /*******************************************************/

  xMin = 0;
  xMax = 100;
  recoCut = "recoTauPt>10 && genTauPt>10 && genTauDM>9";
  l1Cut   = "recoTauPt>10 && genTauPt>10 && genTauDM>9 && l1TauPt>0";

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
		    "efficiency_recoPt_fullDetector.png",        
		    outputDirectory);    
  
  /*******************************************************/
  /* efficiency as a function of recoEta                 */
  /*******************************************************/
  xMin = -3;
  xMax = 3;
  
  recoCut = "recoTauPt>10 && genTauPt>20 && genTauDM>9";
  l1Cut   = "recoTauPt>10 && genTauPt>20 && genTauDM>9 && l1TauPt>0";

  vGraphs.clear();  vLabels.clear();  vColors.clear();

  TGraphAsymmErrors* recoTauEtaLoose = calculateEfficiency("recoTauEta", treePath, rootFileDirectory,
							   l1Cut + "&& l1IsoEt < 15",
							   recoCut, xMin, xMax, false);
  vGraphs.push_back(recoTauEtaLoose);
  vLabels.push_back("L1 iso E_{T} < 15");
  vColors.push_back(kBlue-3);

  TGraphAsymmErrors* recoTauEtaMedium = calculateEfficiency("recoTauEta", treePath, rootFileDirectory,
							    l1Cut + "&& l1IsoEt < 10",
							    recoCut, xMin, xMax, false);
  vGraphs.push_back(recoTauEtaMedium);
  vLabels.push_back("L1 iso E_{T} < 10");
  vColors.push_back(kViolet-5);
  
  TGraphAsymmErrors* recoTauEtaTight = calculateEfficiency("recoTauEta", treePath, rootFileDirectory,
							   l1Cut + "&& l1IsoEt < 5",
							   recoCut, xMin, xMax, false);
  vGraphs.push_back(recoTauEtaTight);
  vLabels.push_back("L1 iso E_{T} < 5");
  vColors.push_back(kPink+6);

  TGraphAsymmErrors* recoTauEtaAll = calculateEfficiency("recoTauEta", treePath, rootFileDirectory,
							 l1Cut,
							 recoCut, xMin, xMax, false);
  vGraphs.push_back(recoTauEtaAll);
  vLabels.push_back("All");
  vColors.push_back(kAzure+1);

  plotNEfficiencies(vGraphs, vLabels, vColors,
		    "Reco #tau_{H} #eta",
		    "Run II L1 Taus",                                                                
		    "efficiency_recoEta_fullDetector.png",        
		    outputDirectory);    

}


/*********************************************************************/
