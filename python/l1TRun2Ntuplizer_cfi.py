import FWCore.ParameterSet.Config as cms


l1NtupleProducer = cms.EDAnalyzer("Run2Ntuplizer",
                                  ecalDigis               = cms.InputTag("caloLayer1Digis", "", "RAW2DIGI"),
                                  hcalDigis               = cms.InputTag("caloLayer1Digis", "", "RAW2DIGI"),
                                  miniTaus                = cms.InputTag("slimmedTaus", "", "PAT"),
                                  genParticles     = cms.InputTag("genParticles", "", "HLT"),
                                  recoPtCut               = cms.double(10),
                                  stage2DigisTaus         = cms.InputTag("simCaloStage2Digis", "", "RAW2DIGI"),
                                  genJets                 = cms.InputTag("slimmedGenJets"),
                                  isData                  = cms.bool(False),
                                  folderName              = cms.untracked.string("Stage2")
)
