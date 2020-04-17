# Run2Ntuplizer

Work in progress code for running an emulator from GEN-SIM-RAW and AOD-SIM files, using 2018 CaloParams and conditions, and creating 
n-tuples of gen and reco-matched L1 taus. Partially based on [Run3Ntuplizer](https://github.com/isobelojalvo/Run3Ntuplizer/tree/2020_Apr_5-boosted).

## Setup and usage
Based on the instructions for `CMSSW_10_6_0` [provided by the L1T group](https://twiki.cern.ch/twiki/bin/view/CMSPublic/SWGuideL1TStage2Instructions):

```
cmsrel CMSSW_10_6_0
cd CMSSW_10_6_0/src
cmsenv
git cms-init
git remote add cms-l1t-offline git@github.com:cms-l1t-offline/cmssw.git
git fetch cms-l1t-offline l1t-integration-CMSSW_10_6_0
git cms-merge-topic -u cms-l1t-offline:l1t-integration-v102.3
git cms-addpkg L1Trigger/L1TCommon
git cms-addpkg L1Trigger/L1TMuon
git clone https://github.com/cms-l1t-offline/L1Trigger-L1TMuon.git L1Trigger/L1TMuon/data
git cms-addpkg L1Trigger/L1TCalorimeter
git clone https://github.com/cms-l1t-offline/L1Trigger-L1TCalorimeter.git L1Trigger/L1TCalorimeter/data

cd L1Trigger
git clone git@github.com:skkwan/Run2Ntuplizer.git
cd ..
scram b -j 8

# to run the analyzer
cd L1Trigger/Run2Ntuplizer/test
cmsRun test-Analyzer.py 
```


## Development notes
Nominally the "Emulating 10_0_X MC with the 2018 CaloParams and conditions" cmsDriver command should work, but a few things 
had to be changed:

```cmsDriver.py l1Ntuple -s RAW2DIGI --era=Run2_2018 --mc --python_filename=mc.py --no_output -n 202 --conditions=100X_upgrade2018_realistic_v11 --customise=L1Trigger/Configuration/customiseReEmul.L1TReEmulMCFromRAWSimHcalTP --customise=L1Trigger/L1TNtuples/customiseL1Ntuple.L1NtupleAODRAWEMUGEN_MC --customise=L1Trigger/Configuration/customiseSettings.L1TSettingsToCaloParams_2018_v1_2 --custom_conditions=HcalChannelQuality_2018_v3.0_mc,HcalChannelQualityRcd,frontier://FrontierProd/CMS_CONDITIONS --filein=/store/mc/RunIISpring18DR/QCD_Pt-15to3000_TuneCP5_Flat_13TeV_pythia8/GEN-SIM-RAW/NZSPU0to70_100X_upgrade2018_realistic_v10-v1/100001/1A22F20B-8321-E811-AABF-1866DAEA6C40.root```

We changed `100X_upgrade2018_realistic_v11` to `106X_upgrade2018_realistic_v11`, added a `--no-exec` since the example file listed
is no longer accessible, and edited the config file to use two files that are accessible.

Run the emulator and ntuplizer in the `test/` folder: `cmsRun test-Analyzer.py`.
