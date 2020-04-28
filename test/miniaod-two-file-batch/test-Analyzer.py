# Auto generated configuration file
# using: 
# Revision: 1.19 
# Source: /local/reps/CMSSW/CMSSW/Configuration/Applications/python/ConfigBuilder.py,v 
# with command line options: l1Ntuple -s RAW2DIGI --era=Run2_2018 --mc --python_filename=mc.py --no_output -n 202 --conditions=106X_upgrade2018_realistic_v11 --no_exec --customise=L1Trigger/Configuration/customiseReEmul.L1TReEmulMCFromRAWSimHcalTP --customise=L1Trigger/L1TNtuples/customiseL1Ntuple.L1NtupleAODRAWEMUGEN_MC --customise=L1Trigger/Configuration/customiseSettings.L1TSettingsToCaloParams_2018_v1_2 --custom_conditions=HcalChannelQuality_2018_v3.0_mc,HcalChannelQualityRcd,frontier://FrontierProd/CMS_CONDITIONS --filein=/store/mc/RunIISpring18DR/QCD_Pt-15to3000_TuneCP5_Flat_13TeV_pythia8/GEN-SIM-RAW/NZSPU0to70_100X_upgrade2018_realistic_v10-v1/100001/1A22F20B-8321-E811-AABF-1866DAEA6C40.root
import FWCore.ParameterSet.Config as cms

from Configuration.Eras.Era_Run2_2018_cff import Run2_2018

process = cms.Process('RAW2DIGI',Run2_2018)

# import of standard configurations
process.load('Configuration.StandardSequences.Services_cff')
process.load('SimGeneral.HepPDTESSource.pythiapdt_cfi')
process.load('FWCore.MessageService.MessageLogger_cfi')
process.load('Configuration.EventContent.EventContent_cff')
process.load('SimGeneral.MixingModule.mixNoPU_cfi')
process.load('Configuration.StandardSequences.GeometryRecoDB_cff')
process.load('Configuration.StandardSequences.MagneticField_cff')
process.load('Configuration.StandardSequences.RawToDigi_cff')
process.load('Configuration.StandardSequences.EndOfProcess_cff')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')

process.load("L1Trigger.Run2Ntuplizer.l1TRun2Ntuplizer_cfi")
process.l1NtupleProducer.isData = cms.bool(False)

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(-1)
)

# Input source
process.source = cms.Source("PoolSource",
                            fileNames = cms.untracked.vstring('/store/mc/RunIISpring15MiniAODv2/GluGluHToTauTau_M125_13TeV_powheg_pythia8/MINIAODSIM/AsymptFlat10to50bx25Raw_74X_mcRun2_asymptotic_v2-v1/80000/629D1870-E67C-E511-8044-20CF305B05A8.root'),
                            secondaryFileNames = cms.untracked.vstring('root://cms-xrd-global.cern.ch//store/mc/RunIISpring15DR74/GluGluHToTauTau_M125_13TeV_powheg_pythia8/GEN-SIM-RAW/AsymptFlat10to50bx25Raw_MCRUN2_74_V9-v1/50000/4EB94F0A-0440-E511-9B3A-00238BCE4642.root'),

)

process.source.lumisToProcess = cms.untracked.VLuminosityBlockRange("1:5221-1:5223", "1:5227")

process.options = cms.untracked.PSet(

)

# Production Info
process.configurationMetadata = cms.untracked.PSet(
    annotation = cms.untracked.string('l1Ntuple nevts:202'),
    name = cms.untracked.string('Applications'),
    version = cms.untracked.string('$Revision: 1.19 $')
)

# Output definition
#process.endOfProcess = cms.OutputModule("PoolOutputModule",
#    fileName = cms.untracked.string("l1TFullEvent.root"),
#    outputCommands = cms.untracked.vstring('drop *')
#                                        #'keep *_*_*_L1TCaloSummaryTest')
#    #outputCommands = cms.untracked.vstring('drop *', 'keep *_l1tCaloLayer1Digis_*_*, keep *_*_*_L1TCaloSummaryTest' )
#)

process.TFileService = cms.Service(
    "TFileService",
    fileName = cms.string("test-analyzer.root")
)

# Other statements
from Configuration.AlCa.GlobalTag import GlobalTag
process.GlobalTag = GlobalTag(process.GlobalTag, '106X_upgrade2018_realistic_v11', 'HcalChannelQuality_2018_v3.0_mc,HcalChannelQualityRcd,frontier://FrontierProd/CMS_CONDITIONS')

# Path and EndPath definitions
process.raw2digi_step = cms.Path(process.RawToDigi)
#process.endjob_step = cms.EndPath(process.endOfProcess)

# Schedule definition
process.p = cms.Path(process.l1NtupleProducer)
process.schedule = cms.Schedule(process.raw2digi_step, process.p)#, process.endjob_step)
from PhysicsTools.PatAlgos.tools.helpers import associatePatAlgosToolsTask
associatePatAlgosToolsTask(process)

# customisation of the process.

# Automatic addition of the customisation function from L1Trigger.Configuration.customiseReEmul
from L1Trigger.Configuration.customiseReEmul import L1TReEmulMCFromRAWSimHcalTP 

#call to customisation function L1TReEmulMCFromRAWSimHcalTP imported from L1Trigger.Configuration.customiseReEmul
process = L1TReEmulMCFromRAWSimHcalTP(process)

# Automatic addition of the customisation function from L1Trigger.L1TNtuples.customiseL1Ntuple
#from L1Trigger.L1TNtuples.customiseL1Ntuple import L1NtupleAODRAWEMUGEN_MC 

#call to customisation function L1NtupleAODRAWEMUGEN_MC imported from L1Trigger.L1TNtuples.customiseL1Ntuple
#process = L1NtupleAODRAWEMUGEN_MC(process)

# Automatic addition of the customisation function from L1Trigger.Configuration.customiseSettings
from L1Trigger.Configuration.customiseSettings import L1TSettingsToCaloParams_2018_v1_2 

#call to customisation function L1TSettingsToCaloParams_2018_v1_2 imported from L1Trigger.Configuration.customiseSettings
process = L1TSettingsToCaloParams_2018_v1_2(process)

# End of customisation functions

# Customisation from command line

#Have logErrorHarvester wait for the same EDProducers to finish as those providing data for the OutputModule
from FWCore.Modules.logErrorHarvester_cff import customiseLogErrorHarvesterUsingOutputCommands
process = customiseLogErrorHarvesterUsingOutputCommands(process)

# Add early deletion of temporary data products to reduce peak memory need
from Configuration.StandardSequences.earlyDeleteSettings_cff import customiseEarlyDelete
process = customiseEarlyDelete(process)
# End adding early deletion

#dump_file = open('dump.py','w')
#dump_file.write(process.dumpPython())
