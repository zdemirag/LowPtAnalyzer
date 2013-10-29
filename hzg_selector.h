//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri Aug  9 04:08:03 2013 by ROOT version 5.32/00
// from TTree eventTree/eventTree
// found on file: nuTuple_39_1_pZv.root
//////////////////////////////////////////////////////////

#ifndef hzg_selector_h
#define hzg_selector_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>
#include <TStyle.h>
#include <TF1.h>
#include <TMath.h>
#include "Math/Minimizer.h"
#include "Math/Factory.h"
#include "Math/Functor.h"

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>

// Header file for the classes stored in the TTree if any.
#include <TClonesArray.h>
#include <TVector3.h>
#include "src/TCJet.h"
#include "src/TCMET.h"
#include "src/TCElectron.h"
#include "src/TCMuon.h"
#include "src/TCTau.h"
#include "src/TCPhoton.h"
#include "src/TCGenJet.h"
#include "src/TCPrimaryVtx.h"
#include "src/TCTriggerObject.h"
#include "src/TCGenParticle.h"

#include "plugins/HistManager.h"
#include "plugins/TriggerSelector.h"

//Phosphor corrections
//#include "PhosphorCorrectorFunctor.hh"

#ifdef __MAKECINT__
#pragma link C++ class vector<string>+;
#endif

// Fixed size dimensions of array or collections stored in the TTree if any.

class hzg_selector : public TSelector {

 public :


  std::vector<double> reco_pt;
  std::vector<double> reco_phi;
  std::vector<double> sigma_ms;
  double sigma_mex;
  double sigma_mey;
  int Ndim;



 /////////////////
 // Output Tree //
 /////////////////
  TTree*		OutTree;
  TDirectory*		AnDir;
  int found_genmuon;
  float                 MinMET;
  float                 RecoMET;
  float                 p_value;
  float                 pho_pt;
  float pho_phi;
  float pho_R9;
  float pfmet_pt;
  float pho_eta;

  float corrDphi;
  int npT;
  int npIT;
  float MyWeightData;
  float MyWeightData_sys;

  float muon1_pt;
  float muon1_eta;
  float muon2_pt;
  float muon2_eta;
  bool tight_IdIso;

  int                   found_isolatedMu;
  int                   found_isolatedEl;
  int                   good_photon_n;
  TLorentzVector*	Pho;
  TLorentzVector*	VBFj0;
  TLorentzVector*	VBFj1;
  TLorentzVector*	VBFDiJet;
  TVector2*		pfMet;
  TVector2*		mvaMet;
  TVector2*		tMet;
  TVector2*		pctMet;
  TVector2*		pfMetGamma;
  TVector2*		mvaMetGamma;
  TVector2*		tMetGamma;
  TVector2*		pctMetGamma;

  float			dphi_pfmet_mvamet;
  float			dphi_pfmet_tmet;
  float			dphi_pfmet_pctmet;
  float			dphi_mvamet_tmet;
  float			dphi_mvamet_pctmet;
  float			MT_pfmet;
  float			MT_mvamet;
  float			MT_tmet;
  float			MT_pctmet;
  float			dphi_pfmetg;
  float			dphi_mvametg;
  float			dphi_tmetg;
  float			dphi_pctmetg;
  float			pfMet_Significance;
  float			pfMet_SigmaX2;


  TLorentzVector* Muon1;
  TLorentzVector* Muon2;
  float dimuonmass;
  float corrMetPhi;
  float corrMet;
  bool fired_HLTPho;
  bool fired_HLTPhoId;
  bool fired_HLTPhoIdMet;
  bool hltmatched_formaintrig;
  bool hltmatched_pho;
  bool hltmatched_phoId;
  
//  Long64_t*		EventNumber;


  TBranch* b_tight_IdIso;
  TBranch* b_corrDphi;
  TBranch* b_npT;
  TBranch* b_npIT;
  TBranch* b_MyWeightData;
  TBranch* b_MyWeightData_sys;

  TBranch* b_muon1_pt;
  TBranch* b_muon1_eta;

  TBranch* b_muon2_pt;
  TBranch* b_muon2_eta;


  TBranch* b_found_genmuon;
  TBranch*             b_Muon1;
  TBranch*          b_Muon2;
  TBranch*          b_dimuonmass;
  TBranch*          b_corrMetPhi;
  TBranch*          b_corrMet;
  TBranch*          b_fired_HLTPho;
  TBranch*          b_fired_HLTPhoId;
  TBranch*          b_fired_HLTPhoIdMet;
  TBranch*          b_hltmatched_formaintrig;
  TBranch*          b_hltmatched_pho;
  TBranch*          b_hltmatched_phoId;

  TBranch*              b_MinMET;
  TBranch*              b_RecoMET;
  TBranch*              b_p_value;

  TBranch*              b_good_photon_n;
  TBranch*              b_found_isolatedMu;
  TBranch*              b_found_isolatedEl;

  TBranch*              b_pho_pt;
  TBranch*              b_pho_phi;
  TBranch*              b_pho_eta;
  TBranch*              b_pho_R9;
  TBranch*              b_pfmet_pt;

  TBranch*		b_Pho;
  TBranch*		b_pfMet;
  TBranch*		b_mvaMet;
  TBranch*		b_tMet;
  TBranch*		b_pctMet;
  TBranch*              b_pfMetGamma;
  TBranch*              b_mvaMetGamma;
  TBranch*              b_tMetGamma;
  TBranch*              b_pctMetGamma;
  TBranch*              b_dphi_pfmet_mvamet;
  TBranch*              b_dphi_pfmet_tmet;
  TBranch*              b_dphi_pfmet_pctmet;
  TBranch*              b_dphi_mvamet_tmet;
  TBranch*              b_dphi_mvamet_pctmet;
  TBranch*              b_MT_pfmet;
  TBranch*              b_MT_mvamet;
  TBranch*              b_MT_tmet;
  TBranch*              b_MT_pctmet;
  TBranch*              b_dphi_pfmetg;
  TBranch*              b_dphi_mvametg;
  TBranch*              b_dphi_tmetg;
  TBranch*              b_dphi_pctmetg;
  TBranch*		b_pfMet_Significance;
  TBranch*		b_pfMet_SigmaX2;
  
//  TBranch*		b_EventNumber;

//////////////////////////////////////////
// Copy of Old Tree for Selected Events //
//////////////////////////////////////////
  TTree*                CopyTree;
  TDirectory*           nuTuple;


//Phosphor corrector:
//  zgamma::PhosphorCorrectionFunctor* phoCorrector;
  float R9;
  float R9Cor;

  TFile        *histoFile;
  HistManager  *hm;
  float        unskimmedEvents;
  float        unskimmedEventsTotal;
  int          fileCount;
  TTree        *thisTree;
  TFile        *file0;
  TH1F         *h1_numOfEvents;
  TVector3     *pvPosition;
  float        weight;

  TriggerSelector *triggerSelector;
  TTree          *fChain;   //!pointer to the analyzed TTree or TChain


   long int NumVBFTaggedEvents;

   
   // Declaration of leaf types
   TClonesArray    *recoJets;
   TClonesArray    *recoJPT;
   TClonesArray    *recoElectrons;
   TClonesArray    *recoMuons;
   TClonesArray    *recoPhotons;
   TCMET           *recoMET;
   TCMET           *mva_MET;
   TCMET           *track_MET;
   TCMET           *T0MET;
   TCMET           *T2MET;
   TClonesArray    *triggerObjects;
   TClonesArray    *genJets;
   TClonesArray    *genParticles;
   TClonesArray    *primaryVtx;
   TVector3        *beamSpot;
   Int_t           nPUVertices;
   Float_t         nPUVerticesTrue;
   Bool_t          isRealData;
   UInt_t          runNumber;
   ULong64_t       eventNumber;
   UInt_t          lumiSection;
   UInt_t          bunchCross;
   Float_t         ptHat;
   Float_t         qScale;
   Float_t         evtWeight;
   Float_t         rhoFactor;
   Float_t         rho25Factor;
   Float_t         rhoMuFactor;
   ULong64_t       triggerStatus;
   UInt_t          hltPrescale[64];
   Bool_t          NoiseFilters_isScraping;
   Bool_t          NoiseFilters_isNoiseHcalHBHE;
   Bool_t          NoiseFilters_isNoiseHcalLaser;
   Bool_t          NoiseFilters_isNoiseEcalTP;
   Bool_t          NoiseFilters_isNoiseEcalBE;
   Bool_t          NoiseFilters_isCSCTightHalo;
   Bool_t          NoiseFilters_isCSCLooseHalo;
   Bool_t          NoiseFilters_isNoiseTracking;
   Bool_t          NoiseFilters_isNoiseEEBadSc;
   Bool_t          NoiseFilters_isNoisetrkPOG1;
   Bool_t          NoiseFilters_isNoisetrkPOG2;
   Bool_t          NoiseFilters_isNoisetrkPOG3;

   // List of branches
   TBranch        *b_recoJets;   //!
   TBranch        *b_recoJPT;   //!
   TBranch        *b_recoElectrons;   //!
   TBranch        *b_recoMuons;   //!
   TBranch        *b_recoPhotons;   //!
   TBranch        *b_recoMET;   //!
   TBranch        *b_mva_MET;   //!
   TBranch        *b_track_MET;   //!
   TBranch        *b_T0MET;   //!
   TBranch        *b_T2MET;   //!
   TBranch        *b_triggerObjects;   //!
   TBranch        *b_genJets;   //!
   TBranch        *b_genParticles;   //!
   TBranch        *b_primaryVtx;   //!
   TBranch        *b_beamSpot;   //!
   TBranch        *b_nPUVertices;   //!
   TBranch        *b_nPUVerticesTrue;   //!
   TBranch        *b_isRealData;   //!
   TBranch        *b_runNumber;   //!
   TBranch        *b_eventNumber;   //!
   TBranch        *b_lumiSection;   //!
   TBranch        *b_bunchCross;   //!
   TBranch        *b_ptHat;   //!
   TBranch        *b_qScale;   //!
   TBranch        *b_evtWeight;   //!
   TBranch        *b_rhoFactor;   //!
   TBranch        *b_rho25Factor;   //!
   TBranch        *b_rhoMuFactor;   //!
   TBranch        *b_triggerStatus;   //!
   TBranch        *b_hltPrescale;   //!
   TBranch        *b_NoiseFilters;   //!

   int          nEvents[100];


   hzg_selector(TTree * /*tree*/ =0) : fChain(0) { }
   virtual ~hzg_selector() { }
   virtual Int_t   Version() const { return 2; }
   virtual void    Begin(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual void    Init(TTree *tree);
   virtual Bool_t  Notify();
   virtual Bool_t  Process(Long64_t entry);
   virtual Int_t   GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
   virtual void    SetOption(const char *option) { fOption = option; }
   virtual void    SetObject(TObject *obj) { fObject = obj; }
   virtual void    SetInputList(TList *input) { fInput = input; }
   virtual TList  *GetOutputList() const { return fOutput; }
   virtual void    SlaveTerminate();
   virtual void    Terminate();

   static bool P4SortCondition(const TLorentzVector& p1, const TLorentzVector& p2) {return (p1.Pt() > p2.Pt());}
   static bool VertexSortCondition(const TCPrimaryVtx& pv1, const TCPrimaryVtx& pv2) {return (pv1.SumPt2Trks() > pv2.SumPt2Trks());}
//   virtual float TransverseMass(TLorentzVector* P, TVector2* M); //{ return 100;}
   virtual float TransverseMass(float Ppt, float Ppx, float Ppy, float Mpt, float Mpx, float Mpy){ return sqrt( (Ppt+Mpt)*(Ppt+Mpt) - (Ppx+Mpx)*(Ppx+Mpx) - (Ppy+Mpy)*(Ppy+Mpy) );} //{ return 100;}

   double func(const double *par);
   double jetreso(TF1 *fjetreso,double pt,double eta);
   float computeLICTD(int n_crys, float* crys_time, float* crys_energy) {
     int seed = -1;
     float seedE = -99, LICTD = 0;
     for(int k=0;k<n_crys&&k<100;++k){
       if(crys_energy[k] > seedE){seed = k; seedE = crys_energy[seed];}
       if(seed<0) LICTD = -99;
       if(seed==k) continue;
       if (crys_energy[k] > 1.) {
	 if(TMath::Abs(crys_time[seed] - crys_time[k]) > TMath::Abs(LICTD)) LICTD = crys_time[seed] - crys_time[k];
       }
     }
     return LICTD;
   };


   //////////////////////                                                                                                                                                      
   // Cut and Iso Defs //                                                                                                                                                      
   ////////////////////// 


   float EAMu[6]; 
   float EAEle[7]; 
   float EAPho[7][3];
   
   struct muIDCuts{
     float IsPF;
     float IsGLB;
     float NormalizedChi2;
     float NumberOfValidMuonHits;
     float NumberOfMatchedStations;
     float NumberOfValidPixelHits;
     float TrackLayersWithMeasurement;
     float dxy;
     float dz;
      string cutName;
   } tightMuID;
   
    struct muIsoCuts{
      float chIso04;
      float nhIso04;
      float phIso04;
      float relCombIso04;
      string cutName;
    } tightMuIso;

    struct elIDCuts{
      //broken into [0] barrel and [1] endcap
      float dEtaIn[2];
      float dPhiIn[2];
      float sigmaIetaIeta[2];
      float HadOverEm[2];
      float dxy[2];
      float dz[2];
      float fabsEPDiff[2];
      float ConversionMissHits[2];
      float PassedConversionProb[2];
      string cutName;
    } mediumElID, looseElID;

    struct elIsoCuts{
      float chIso04;
      float nhIso04;
      float phIso04;
      float relCombIso04;
      string cutName;
    } mediumElIso, looseElIso;


   struct phIDCuts{
      //broken into [0] barrel and [1] endcap
      float PassedEleSafeVeto[2];
      float HadOverEm[2];
      float sigmaIetaIeta[2];
      string cutName;
   } loosePhID, mediumPhID , tightPhID;
   
   struct phIsoCuts{
     float chIso03[2];
     float nhIso03[2];
     float phIso03[2];
     float relCombIso03[2];
     string cutName;
   } loosePhIso, mediumPhIso, tightPhIso;


   virtual bool      PassPhotonID(TCPhoton *ph, phIDCuts cutLevel);
   virtual bool      PassPhotonIso(TCPhoton *ph, phIsoCuts cutLevel);
   virtual bool      PassMuonID(TCMuon *mu, muIDCuts cutLevel);
   virtual bool      PassMuonIso(TCMuon *mu, muIsoCuts cutLevel);
   virtual bool      PassElectronID(TCElectron *el, elIDCuts cutLevel);
   virtual bool      PassElectronIso(TCElectron *el, elIsoCuts cutLevel);
   

   ClassDef(hzg_selector,0);
};

#endif

#ifdef hzg_selector_cxx
void hzg_selector::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   recoJets = 0;
   recoJPT = 0;
   recoElectrons = 0;
   recoMuons = 0;
   recoPhotons = 0;
   recoMET = 0;
   mva_MET = 0;
   track_MET = 0;
   T0MET = 0;
   T2MET = 0;
   triggerObjects = 0;
   genJets = 0;
   genParticles = 0;
   primaryVtx = 0;
   beamSpot = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   thisTree = tree;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("recoJets", &recoJets, &b_recoJets);
   fChain->SetBranchAddress("recoJPT", &recoJPT, &b_recoJPT);
   fChain->SetBranchAddress("recoElectrons", &recoElectrons, &b_recoElectrons);
   fChain->SetBranchAddress("recoMuons", &recoMuons, &b_recoMuons);
   fChain->SetBranchAddress("recoPhotons", &recoPhotons, &b_recoPhotons);
   fChain->SetBranchAddress("recoMET", &recoMET, &b_recoMET);
   fChain->SetBranchAddress("mva_MET", &mva_MET, &b_mva_MET);
   fChain->SetBranchAddress("track_MET", &track_MET, &b_track_MET);
   fChain->SetBranchAddress("T0MET", &T0MET, &b_T0MET);
   fChain->SetBranchAddress("T2MET", &T2MET, &b_T2MET);
   fChain->SetBranchAddress("triggerObjects", &triggerObjects, &b_triggerObjects);
   fChain->SetBranchAddress("genJets", &genJets, &b_genJets);
   fChain->SetBranchAddress("genParticles", &genParticles, &b_genParticles);
   fChain->SetBranchAddress("primaryVtx", &primaryVtx, &b_primaryVtx);
   fChain->SetBranchAddress("beamSpot", &beamSpot, &b_beamSpot);
   fChain->SetBranchAddress("nPUVertices", &nPUVertices, &b_nPUVertices);
   fChain->SetBranchAddress("nPUVerticesTrue", &nPUVerticesTrue, &b_nPUVerticesTrue);
   fChain->SetBranchAddress("isRealData", &isRealData, &b_isRealData);
   fChain->SetBranchAddress("runNumber", &runNumber, &b_runNumber);
   fChain->SetBranchAddress("eventNumber", &eventNumber, &b_eventNumber);
   fChain->SetBranchAddress("lumiSection", &lumiSection, &b_lumiSection);
   fChain->SetBranchAddress("bunchCross", &bunchCross, &b_bunchCross);
   fChain->SetBranchAddress("ptHat", &ptHat, &b_ptHat);
   fChain->SetBranchAddress("qScale", &qScale, &b_qScale);
   fChain->SetBranchAddress("evtWeight", &evtWeight, &b_evtWeight);
   fChain->SetBranchAddress("rhoFactor", &rhoFactor, &b_rhoFactor);
   fChain->SetBranchAddress("rho25Factor", &rho25Factor, &b_rho25Factor);
   fChain->SetBranchAddress("rhoMuFactor", &rhoMuFactor, &b_rhoMuFactor);
   fChain->SetBranchAddress("triggerStatus", &triggerStatus, &b_triggerStatus);
   fChain->SetBranchAddress("hltPrescale", hltPrescale, &b_hltPrescale);
   fChain->SetBranchAddress("NoiseFilters", &NoiseFilters_isScraping, &b_NoiseFilters);


   ///////////////
   // Cuts Init //
   ///////////////

   looseElID.cutName =                     "looseElID";
   looseElID.dEtaIn[0] =                   0.007;
   looseElID.dPhiIn[0] =                   0.15;
   looseElID.sigmaIetaIeta[0] =            0.01;
   looseElID.HadOverEm[0] =                0.12;
   looseElID.dxy[0] =                      0.02;
   looseElID.dz[0] =                       0.2;
   looseElID.fabsEPDiff[0] =               0.05;
   looseElID.ConversionMissHits[0] =       1;
   looseElID.PassedConversionProb[0] =     1;
   
   looseElID.dEtaIn[1] =                   0.009;
   looseElID.dPhiIn[1] =                   0.10;
   looseElID.sigmaIetaIeta[1] =            0.03;
   looseElID.HadOverEm[1] =                0.10;
   looseElID.dxy[1] =                      0.02;
   looseElID.dz[1] =                       0.2;
   looseElID.fabsEPDiff[1] =               0.05;
   looseElID.ConversionMissHits[1] =       1;
   looseElID.PassedConversionProb[1] =     1;
   
   looseElIso.cutName =                    "looseElIso";
   looseElIso.chIso04 =                    99999;
   looseElIso.nhIso04 =                    99999;
   looseElIso.phIso04 =                    99999;
   looseElIso.relCombIso04 =               0.4;

   mediumElID.cutName =                     "mediumElID";
   mediumElID.dEtaIn[0] =                   0.004;
   mediumElID.dPhiIn[0] =                   0.06;
   mediumElID.sigmaIetaIeta[0] =            0.01;
   mediumElID.HadOverEm[0] =                0.12;
   mediumElID.dxy[0] =                      0.02;
   mediumElID.dz[0] =                       0.1;
   mediumElID.fabsEPDiff[0] =               0.05;
   mediumElID.ConversionMissHits[0] =       1;
   mediumElID.PassedConversionProb[0] =     1;
   
   mediumElID.dEtaIn[1] =                   0.007;
   mediumElID.dPhiIn[1] =                   0.03;
   mediumElID.sigmaIetaIeta[1] =            0.03;
   mediumElID.HadOverEm[1] =                0.10;
   mediumElID.dxy[1] =                      0.02;
   mediumElID.dz[1] =                       0.1;
   mediumElID.fabsEPDiff[1] =               0.05;
   mediumElID.ConversionMissHits[1] =       1;
   mediumElID.PassedConversionProb[1] =     1;
   
   mediumElIso.cutName =                    "mediumElIso";
   mediumElIso.chIso04 =                    99999;
   mediumElIso.nhIso04 =                    99999;
   mediumElIso.phIso04 =                    99999;
   mediumElIso.relCombIso04 =               0.4;

   tightMuID.cutName =                     "tightMuID";
   tightMuID.IsPF =                        1;
   tightMuID.IsGLB =                       1;
   tightMuID.NormalizedChi2 =              10;
   tightMuID.NumberOfValidMuonHits =       0;
   tightMuID.NumberOfMatchedStations =     1;
   tightMuID.NumberOfValidPixelHits =      0;
   tightMuID.TrackLayersWithMeasurement =  5;
   tightMuID.dxy =                         0.2;
   tightMuID.dz =                          0.5;
   
   tightMuIso.cutName =                    "tightMuIso";
   tightMuIso.chIso04 =                    99999;
   tightMuIso.nhIso04 =                    99999;
   tightMuIso.phIso04 =                    99999;
   tightMuIso.relCombIso04 =               0.12;

   loosePhID.cutName =                     "loosePhID";
   loosePhID.PassedEleSafeVeto[0] =        1;
   loosePhID.HadOverEm[0] =                0.05;
   loosePhID.sigmaIetaIeta[0] =            0.012;
   
   loosePhID.PassedEleSafeVeto[1] =        1;
   loosePhID.HadOverEm[1] =                0.05;
   loosePhID.sigmaIetaIeta[1] =            0.034;
   
   loosePhIso.cutName =                    "loosePhIso";
   loosePhIso.chIso03[0] =                 2.6;
   loosePhIso.nhIso03[0] =                 3.5;
   loosePhIso.phIso03[0] =                 1.3;
   
   loosePhIso.chIso03[1] =                 2.3;
   loosePhIso.nhIso03[1] =                 2.9;
   loosePhIso.phIso03[1] =                 99999;
   
   mediumPhID.cutName =                     "mediumPhID";
   mediumPhID.PassedEleSafeVeto[0] =        1;
   mediumPhID.HadOverEm[0] =                0.05;
   mediumPhID.sigmaIetaIeta[0] =            0.011;
   
   mediumPhID.PassedEleSafeVeto[1] =        1;
   mediumPhID.HadOverEm[1] =                0.05;
   mediumPhID.sigmaIetaIeta[1] =            0.033;
   
   mediumPhIso.cutName =                    "mediumPhIso";
   mediumPhIso.chIso03[0] =                 1.5;
   mediumPhIso.nhIso03[0] =                 1.0;
   mediumPhIso.phIso03[0] =                 0.7;
   
   mediumPhIso.chIso03[1] =                 1.2;
   mediumPhIso.nhIso03[1] =                 1.5;
   mediumPhIso.phIso03[1] =                 1.0;
   
   tightPhID.cutName =                     "tightPhID";
   tightPhID.PassedEleSafeVeto[0] =        1;
   tightPhID.HadOverEm[0] =                0.05;
   tightPhID.sigmaIetaIeta[0] =            0.011;

   tightPhID.PassedEleSafeVeto[1] =        1;
   tightPhID.HadOverEm[1] =                0.05;
   tightPhID.sigmaIetaIeta[1] =            0.031;

   tightPhIso.cutName =                    "tightPhIso";
   tightPhIso.chIso03[0] =                 0.7;
   tightPhIso.nhIso03[0] =                 0.4;
   tightPhIso.phIso03[0] =                 0.5;

   tightPhIso.chIso03[1] =                 0.5;
   tightPhIso.nhIso03[1] =                 1.5;
   tightPhIso.phIso03[1] =                 1.0;

}





Bool_t hzg_selector::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.
  
  fileCount+= 1;
  file0 = thisTree->GetCurrentFile();
  h1_numOfEvents = (TH1F*) file0->Get("ntupleProducer/numOfEvents");
  unskimmedEvents = h1_numOfEvents->GetBinContent(1);
  cout<<"THIS IS FILE NUMBER: "<<fileCount<<" and it has this many events: "<<unskimmedEvents<<endl;
  unskimmedEventsTotal += unskimmedEvents;
  
  return kTRUE;
}

#endif // #ifdef hzg_selector_cxx
