#define hzg_selector_cxx
#include "hzg_selector.h"
#include "PhysicsTools/Utilities/interface/LumiReweightingStandAlone.h"

string  selection       = "nunuGamma_GGF";//"datadriven_doubleMu";//"nunuGamma_GGF";
string  period          = "2012";
string  suffix          = "SUFFIX";

bool    verbose         = false;
bool    MHT_verbose     = false;

bool mc                 = true;
bool data               = false;
bool ddzg               = false;

reweight::LumiReWeighting LumiWeightsD_;
reweight::LumiReWeighting LumiWeightsD_sys_;

TF1* fjetreso = new TF1 ("jetReso","TMath::Sqrt(((sign([0])*(([0]/x)^2))+(([1]^2)*(x^([2]-1.))))+([3]^2))",0,15000);
TF1* fmex     = new TF1("Mex Sigma", "[0]*TMath::Sqrt(x) + [1]",0,5000);
TF1* fmey     = new TF1("Mey Sigma", "[0]*TMath::Sqrt(x) + [1]",0,5000);
TF1* fphoton  = new TF1("Photon_Sigma","[0]*pow(x,[1])",0,10000);
TF1* fmuon    = new TF1("ptsigma_barrel", "pol3", 0, 10000);

int n_vertex_count = 0;
int n_photon_count = 0;
int n_hltmatched_count = 0;
int pass_filter = 0;
void hzg_selector::Begin(TTree * tree)
{
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

  //PU Reweighting:

  Float_t DataDist_2012D[60] = {1768.77, 3651.68, 7356.92, 14793.3, 51246.8, 489173, 2.63921e+06, 6.82361e+06, 1.88317e+07, 5.19794e+07, 1.08899e+08, 1.88257e+08, 2.57316e+08, 3.01258e+08, 3.27492e+08, 3.44354e+08, 3.59374e+08, 3.74823e+08, 3.90058e+08, 4.0217e+08, 4.08643e+08, 4.11422e+08, 4.11151e+08, 4.05573e+08, 3.92856e+08, 3.72226e+08, 3.44284e+08, 3.10504e+08, 2.7226e+08, 2.30759e+08, 1.8777e+08, 1.45857e+08, 1.07763e+08, 7.56393e+07, 5.0551e+07, 3.23928e+07, 2.0178e+07, 1.25011e+07, 7.95461e+06, 5.38133e+06, 3.95572e+06, 3.15182e+06, 2.66553e+06, 2.33493e+06, 2.08e+06, 1.86352e+06, 1.669e+06, 1.48952e+06, 1.32229e+06, 1.16642e+06, 1.02175e+06, 888282, 766092, 655189, 555473, 466702, 388487, 320302, 261506, 211367};

  Float_t DataDist_2012D_sys[60] = {1632.3, 3240.95, 6296.46, 12068, 30517.4, 227305, 1.49497e+06, 4.52239e+06, 1.0476e+07, 2.96274e+07, 6.82538e+07, 1.28218e+08, 2.00114e+08, 2.55292e+08, 2.90327e+08, 3.11739e+08, 3.26279e+08, 3.39668e+08, 3.53444e+08, 3.67108e+08, 3.78444e+08, 3.85013e+08, 3.88036e+08, 3.88742e+08, 3.85622e+08, 3.76942e+08, 3.61739e+08, 3.39978e+08, 3.12601e+08, 2.80828e+08, 2.45645e+08, 2.08081e+08, 1.69728e+08, 1.32723e+08, 9.92184e+07, 7.08564e+07, 4.84379e+07, 3.18819e+07, 2.04316e+07, 1.29836e+07, 8.39661e+06, 5.69316e+06, 4.14131e+06, 3.24848e+06, 2.71199e+06, 2.35979e+06, 2.10068e+06, 1.88918e+06, 1.70364e+06, 1.53423e+06, 1.37666e+06, 1.22917e+06, 1.0912e+06, 962650, 843537, 733913, 633795, 543116, 461705, 389280};
  
  Float_t MCDist_Summer2012_S10[60] = {2.560E-06,5.239E-06,1.420E-05,5.005E-05,1.001E-04,2.705E-04,1.999E-03,6.097E-03,1.046E-02,1.383E-02,1.685E-02,2.055E-02,2.572E-02,3.262E-02,4.121E-02,4.977E-02,5.539E-02,5.725E-02,5.607E-02,5.312E-02,5.008E-02,4.763E-02,4.558E-02,4.363E-02,4.159E-02,3.933E-02,3.681E-02,3.406E-02,3.116E-02,2.818E-02,2.519E-02,2.226E-02,1.946E-02,1.682E-02,1.437E-02,1.215E-02,1.016E-02,8.400E-03,6.873E-03,5.564E-03,4.457E-03,3.533E-03,2.772E-03,2.154E-03,1.656E-03,1.261E-03,9.513E-04,7.107E-04,5.259E-04,3.856E-04,2.801E-04,2.017E-04,1.439E-04,1.017E-04,7.126E-05,4.948E-05,3.405E-05,2.322E-05,1.570E-05,5.005E-06};

  std::vector<float> DataDistD;
  std::vector<float> DataDistD_sys;
  std::vector<float> MCDist;
  
  for( int i=0; i<60; ++i) {
    DataDistD.push_back(DataDist_2012D[i]);
    DataDistD_sys.push_back(DataDist_2012D_sys[i]);
    MCDist.push_back(MCDist_Summer2012_S10[i]);
  }

  LumiWeightsD_ = reweight::LumiReWeighting(MCDist, DataDistD);
  LumiWeightsD_sys_ = reweight::LumiReWeighting(MCDist, DataDistD_sys);


  // Get trigger names from jobTree                                                                                                                                                
  vector<string>* triggerNames = 0;
  TFile   *inFile         = tree->GetCurrentFile();
  TTree   *jobTree        = (TTree*)inFile->Get("ntupleProducer/jobTree");

  jobTree->SetBranchAddress("triggerNames", &triggerNames);
  jobTree->GetEntry();
  triggerSelector = new TriggerSelector(selection, period, *triggerNames);

  //histoFile = new TFile("/uscms_data/d3/zdemirag/HZg_Ntuples/analyzer/CMSSW_5_3_8_patch1/src/Analyzer_v1/higgsHistograms_SUFFIX.root","RECREATE");
  histoFile = new TFile("/eos/uscms/store/user/zdemirag/higgsHistograms_SUFFIX.root", "RECREATE");
  histoFile->cd();
  
  hm        = new HistManager(histoFile, "Misc");

  //Setting up new tree
  histoFile->mkdir("Analyzer", "Analyzer");
  AnDir = (TDirectory*)histoFile->GetDirectory("Analyzer");
  OutTree = new TTree("AnalyzerTree", "HZ(nunu)Gamma Analyzer Tree");
  
  cout << " setting up the branches" <<endl;

  b_npT = OutTree->Branch("npT",&npT,"npT/I");
  b_npIT = OutTree->Branch("npIT",&npIT,"npIT/I");
  b_MyWeightData = OutTree->Branch("MyWeightData",&MyWeightData,"MyWeightData/F");
  b_MyWeightData_sys = OutTree->Branch("MyWeightData_sys",&MyWeightData_sys,"MyWeightData_sys/F");

  b_Pho 		= OutTree->Branch("Pho", &Pho);

  b_Muon1               = OutTree->Branch("Muon1", &Muon1);
  b_Muon2               = OutTree->Branch("Muon2", &Muon2);

  b_muon1_pt              = OutTree->Branch("muon1_pt",&muon1_pt,"muon1_pt/F");
  b_muon1_eta             = OutTree->Branch("muon1_eta",&muon1_eta,"muon1_eta/F");

  b_muon2_pt              = OutTree->Branch("muon2_pt",&muon2_pt,"muon2_pt/F");
  b_muon2_eta             = OutTree->Branch("muon2_eta",&muon2_eta,"muon2_eta/F");

  b_found_genmuon       = OutTree->Branch("found_genmuon",&found_genmuon,"found_genmuon/I");
  b_tight_IdIso         = OutTree->Branch("tight_IdIso",&tight_IdIso,"tight_IdIso/O");
  b_pho_pt              = OutTree->Branch("pho_pt",&pho_pt,"pho_pt/F");
  b_pho_phi             = OutTree->Branch("pho_phi",&pho_phi,"pho_phi/F");
  b_pho_eta             = OutTree->Branch("pho_eta",&pho_eta,"pho_eta/F");
  b_pho_R9              = OutTree->Branch("pho_R9",&pho_R9,"pho_R9/F");   
  b_pfmet_pt            = OutTree->Branch("pfmet_pt",&pfmet_pt,"pfmet_pt/F");
  b_MinMET              = OutTree->Branch("MinMET", &MinMET, "MinMET/F");
  b_RecoMET             = OutTree->Branch("RecoMET", &RecoMET, "RecoMET/F");
  b_p_value             = OutTree->Branch("p_value", &p_value, "p_value/F");
  b_good_photon_n       = OutTree->Branch("good_photon_n",&good_photon_n, "good_photon_n/I");
  b_found_isolatedMu    = OutTree->Branch("found_isolatedMu",&found_isolatedMu, "found_isolatedMu/I");
  b_found_isolatedEl    = OutTree->Branch("found_isolatedEl",&found_isolatedEl, "found_isolatedEl/I");
  
  b_dimuonmass          = OutTree->Branch("dimuonmass", &dimuonmass,"dimuonmass/F");
  b_corrMetPhi          = OutTree->Branch("corrMetPhi", &corrMetPhi, "corrMetPhi/F");
  b_corrMet             = OutTree->Branch("corrMet", &corrMet, "corrMet/F");
  b_corrDphi            = OutTree->Branch("corrDphi", &corrDphi, "corrDphi/F");
  b_pfMet 		= OutTree->Branch("pfMet", "TVector2", &pfMet);
  b_mvaMet 		= OutTree->Branch("mvaMet","TVector2" ,&mvaMet);
  b_dphi_pfmet_mvamet 	= OutTree->Branch("dphi_pfmet_mvamet", &dphi_pfmet_mvamet, "dphi_pfmet_mvamet/F");
  b_MT_pfmet	 	= OutTree->Branch("MT_pfmet", &MT_pfmet, "MT_pfmet/F");
  b_MT_mvamet	 	= OutTree->Branch("MT_mvamet", &MT_mvamet, "MT_mvamet/F");

  b_dphi_pfmetg 	= OutTree->Branch("dphi_pfmetg", &dphi_pfmetg, "dphi_pfmetg/F");
  b_dphi_mvametg 	= OutTree->Branch("dphi_mvametg", &dphi_mvametg, "dphi_mvametg/F");

  b_pfMet_Significance	= OutTree->Branch("pfMet_Significance", &pfMet_Significance, "pfMet_Significance/F");
  b_pfMet_SigmaX2	= OutTree->Branch("pfMet_SigmaX2", &pfMet_SigmaX2, "pfMet_SigmaX2/F");
  
  b_fired_HLTPho        = OutTree->Branch("fired_HLTPho", &fired_HLTPho, "fired_HLTPho/O");
  b_fired_HLTPhoId      = OutTree->Branch("fired_HLTPhoId", &fired_HLTPhoId, "fired_HLTPhoId/O");
  b_fired_HLTPhoIdMet   = OutTree->Branch("fired_HLTPhoIdMet", &fired_HLTPhoIdMet, "fired_HLTPhoIdMet/O");
  b_hltmatched_formaintrig = OutTree->Branch("hltmatched_formaintrig", &hltmatched_formaintrig, "hltmatched_formaintrig/O");
  b_hltmatched_pho      = OutTree->Branch("hltmatched_pho",&hltmatched_pho,"hltmatched_pho/O");
  b_hltmatched_phoId    = OutTree->Branch("hltmatched_phoId", &hltmatched_phoId, "hltmatched_phoId/O");


  Pho = 0;  good_photon_n = 0; pfMet = 0;  mvaMet = 0;  tMet = 0;  pctMet = 0;  pfMetGamma = 0;  mvaMetGamma = 0;  tMetGamma = 0;
  pctMetGamma = 0;  dphi_pfmet_mvamet = 0;  dphi_pfmet_tmet = 0;  dphi_pfmet_pctmet = 0;  dphi_mvamet_tmet = 0;  dphi_mvamet_pctmet = 0;  dphi_mvametg = 0;  dphi_tmetg = 0;
  dphi_pctmetg = 0;  dphi_pfmetg = 0;  dphi_mvametg = 0;  dphi_tmetg = 0;  dphi_pctmetg = 0;  

  // ch      nh       ph
  float EAPhoTemp[7][3] = {
    {0.012,  0.030,   0.148}, //         eta < 1.0  
    {0.010,  0.057,   0.130}, // 1.0   < eta < 1.479   
    {0.014,  0.039,   0.112}, // 1.479 < eta < 2.0  
    {0.012,  0.015,   0.216}, // 2.0   < eta < 2.2 
    {0.016,  0.024,   0.262}, // 2.2   < eta < 2.3  
    {0.020,  0.039,   0.260}, // 2.3   < eta < 2.4 
    {0.012,  0.072,   0.266}  // 2.4   < eta       
  };

  for (unsigned int i =0; i<7; i++){
    for (unsigned int j =0; j<3; j++){
      EAPho[i][j] = EAPhoTemp[i][j];
    }
  }
  
  NumVBFTaggedEvents = 0;
  TString option = GetOption();

}

void hzg_selector::SlaveBegin(TTree * /*tree*/)
{
  // The SlaveBegin() function is called after the Begin() function.
  // When running with PROOF SlaveBegin() is called on each slave server.
  // The tree argument is deprecated (on PROOF 0 is passed).
  TString option = GetOption();
  
}

Bool_t hzg_selector::Process(Long64_t entry)
{

  if(mc)   fmex->SetParameters(0.53,3.08);
  if(data) fmex->SetParameters(0.61,0.37);
  
  if(mc)   fmey->SetParameters(0.53,3.4); 
  if(data) fmey->SetParameters(0.62,0.17);
  
  fphoton->SetParameters(0.1138,-0.449);
  fmuon->SetParameters(0.006821,0.0001047,-1.213e-08,1.874e-12);
  
  GetEntry(entry);
  //if( entry%1000 == 0) cout << "## Processing evt #: " << entry << endl;
  
  //Final Objects that we want (VBFJet0, VBFJet1, Photon, pfMET, MVAMET, trackMET, pctMET)
  TLorentzVector Photon;
  TVector2 pfMET, mvaMET, tMET, pctMET;
  
  int NumGoodPhotons = 0; 
  int found_isolatedMuon = 0;
  int found_isolatedElectron = 0;
  
  fired_HLTPho = false;
  fired_HLTPhoId = false;
  fired_HLTPhoIdMet = false;  


  if(data){
    //Trigger Status
    for(int i = 0; i < 64; ++i) {
      unsigned long iHLT = 0x0;
      iHLT = 0x01 << i;
      if ((triggerStatus & iHLT) == iHLT) hm->fill1DHist(i+1,"h1_triggerStatus_SUFFIX", "Triggers", 64, 0.5, 64.5,1);
    }
    //bool triggerPass   = triggerSelector->SelectTrigger(triggerStatus, hltPrescale);
    //if(ddzg && data) {if (!triggerPass) return kTRUE;}

    for (int i = 0; i <  triggerObjects->GetSize(); ++i) {
      TCTriggerObject* thisTrigObj = (TCTriggerObject*) triggerObjects->At(i);
      if(thisTrigObj->GetHLTName().find("HLT_Photon30_v")!=std::string::npos) fired_HLTPho = true;
      if(thisTrigObj->GetHLTName().find("HLT_Photon30_R9Id90_CaloId_HE10_Iso40_EBOnly_v")!=std::string::npos) fired_HLTPhoId = true; 
      if(thisTrigObj->GetHLTName().find("HLT_Photon30_R9Id90_CaloId_HE10_Iso40_EBOnly_Met25_HBHENoiseCleaned_v")!=std::string::npos) fired_HLTPhoIdMet = true;
    }
    
    if (NoiseFilters_isScraping) { if(verbose) cout << "NoiseFilters_isScraping: " << NoiseFilters_isScraping << endl; return kTRUE;}
    if (NoiseFilters_isNoiseHcalHBHE) {if(verbose) cout << "NoiseFilters_isNoiseHcalHBHE: " << NoiseFilters_isNoiseHcalHBHE <<endl; return kTRUE;}
    if (NoiseFilters_isNoiseHcalLaser) {if(verbose) cout << "NoiseFilters_isNoiseHcalLaser: " <<NoiseFilters_isNoiseHcalLaser <<endl; return kTRUE;}
    if (NoiseFilters_isNoiseEcalTP) {if(verbose) cout << "NoiseFilters_isNoiseEcalTP: " << NoiseFilters_isNoiseEcalTP<< endl; return kTRUE;}
    if (NoiseFilters_isNoiseEcalBE) {if(verbose) cout<< "NoiseFilters_isNoiseEcalBE: " << NoiseFilters_isNoiseEcalBE << endl; return kTRUE;}
    if (NoiseFilters_isCSCTightHalo) {if(verbose) cout<< "NoiseFilters_isCSCTightHalo: " << NoiseFilters_isCSCTightHalo <<endl; return kTRUE;}
    if (NoiseFilters_isNoiseEEBadSc) {if(verbose) cout << "NoiseFilters_isNoiseEEBadSc: " << NoiseFilters_isNoiseEEBadSc <<endl; return kTRUE;}
    if (!NoiseFilters_isNoisetrkPOG1){if(verbose) cout << "!NoiseFilters_isNoisetrkPOG1: " << !NoiseFilters_isNoisetrkPOG1 << endl; return kTRUE;}
    if (!NoiseFilters_isNoisetrkPOG2){if(verbose) cout << "!NoiseFilters_isNoisetrkPOG2: " << !NoiseFilters_isNoisetrkPOG2 << endl; return kTRUE;}
    if (!NoiseFilters_isNoisetrkPOG3) {if(verbose) cout << "!NoiseFilters_isNoisetrkPOG3: " << !NoiseFilters_isNoisetrkPOG3 << endl;return kTRUE;}
    pass_filter++;

    
  }



 
 ////////////////////////////
 //Check the event vertices//  
 ////////////////////////////  

 vector<TVector3> goodVertices;
 vector<TCPrimaryVtx> pvVect;
 for (int i = 0; i < primaryVtx->GetSize(); ++i) {
   TCPrimaryVtx* pVtx = (TCPrimaryVtx*) primaryVtx->At(i);
   if (!pVtx->IsFake()
       && pVtx->NDof() > 4.
       && fabs(pVtx->z()) <= 24.
       && fabs(pVtx->Perp()) <= 2.
       )
     goodVertices.push_back(*pVtx);
  }
 if (goodVertices.size() < 1) return kTRUE; 
 
 pvPosition = new TVector3();
 *pvPosition = goodVertices[0];
 
 n_vertex_count++;

 ///////////// 
 // photons //                                                                                   
 /////////////                                                                                                                                                                
 
 vector<TCPhoton> photonsID;
 vector<TCPhoton> photonsIDIso;
 //TLorentzVector LeadPhoton; //Highest Pt good photon
 

 tight_IdIso = false;

 for (Int_t i = 0; i < recoPhotons->GetSize(); ++i) {
   cout << "photon size: " << i << endl;

   TCPhoton* thisPhoton = (TCPhoton*) recoPhotons->At(i);
   
   if (PassPhotonID(thisPhoton, mediumPhID)) photonsID.push_back(*thisPhoton);
   if (PassPhotonID(thisPhoton, mediumPhID) && PassPhotonIso(thisPhoton, mediumPhIso) && thisPhoton->Pt()>25.){
     photonsIDIso.push_back(*thisPhoton);
     NumGoodPhotons++;
   }   

   /*   
   vector<TCPhoton::CrystalInfo> savedCrystals = thisPhoton->GetCrystalArray();
   //TCPhoton::CrystalInfo* savedCrystals;
   //savedCrystals = new TCPhoton::CrystalInfo[100];
   //savedCrystals = thisPhoton->GetCrystalArray();

   int seed = -1;
   float seedE = -99, LICTD = 0;

   std::cout << "NCrystal: " << thisPhoton->GetNCrystals() << std::endl;

   for(int k=0;k<thisPhoton->GetNCrystals() && k < 100; ++k){
     std::cout << "k = " << k << " seed = " << seed << " LICTD: " << LICTD  <<  " seed energy: "<<  savedCrystals[seed].energy << " k energy: " << savedCrystals[k].energy <<endl;
     if(savedCrystals[k].energy > seedE){seed = k; seedE = savedCrystals[seed].energy;}
     if(seed<0) LICTD = -99;
     if(seed==k) continue;
     if (savedCrystals[k].energy > 1.) {
       if(TMath::Abs(savedCrystals[seed].time - savedCrystals[k].time) > TMath::Abs(LICTD)) LICTD = savedCrystals[seed].time - savedCrystals[k].time;
     }
     //std::cout << "k = " << k << " seed = " << seed <<endl;
   }
   std::cout << "LICTD: " << LICTD <<std::endl;

   delete[] savedCrystals;
   */
 }

   

 //float LICDT = computeLICTD(Photon_ncrys[i],Photon_timing_xtal[i], Photon_energy_xtal[i]);
 
 if(NumGoodPhotons > 0 ) {
   //if(verbose) cout << "Number of Good Photons " << NumGoodPhotons << endl;
   sort(photonsID.begin(), photonsID.end(), P4SortCondition);
   sort(photonsIDIso.begin(), photonsIDIso.end(), P4SortCondition);
   //if(verbose)  cout<<photonsIDIso[0].Pt()<<endl;
   Photon = TLorentzVector(photonsIDIso[0].Px(), photonsIDIso[0].Py(), photonsIDIso[0].Pz(), photonsIDIso[0].Energy());
   //if(verbose) cout << "Lead Photon Pt " << Photon.Pt() << endl;
   pho_pt = Photon.Pt();
   pho_phi = Photon.Phi();
   pho_R9 = photonsIDIso[0].R9();
   pho_eta = photonsIDIso[0].SCEta();
   
   if (PassPhotonID( (&photonsIDIso[0]), tightPhID) &&  PassPhotonIso((&photonsIDIso[0]), tightPhIso) && (&photonsIDIso[0])->Pt()>25.){
     tight_IdIso = true;
     //std::cout << "Tight Photon" <<std::endl;
   }

   
 }

 if(NumGoodPhotons < 1) return kTRUE; //Skip events with no photons
 n_photon_count++;
 

 //////////////////
 // HLT MATCHING //
 //////////////////

 hltmatched_formaintrig = false; 
 hltmatched_pho = false;
 hltmatched_phoId = false;

 if(data){// && fired_HLTPhoIdMet){
   for (int i = 0; i <  triggerObjects->GetSize(); ++i) {                                                                                                                       
     TCTriggerObject* thisTrigObj = (TCTriggerObject*) triggerObjects->At(i);                                                                                                    
     if(/*thisTrigObj->GetModuleName() == "hltMETClean25" ||*/ thisTrigObj->GetModuleName() == "hltPhoton30R9Id90CaloIdHE10Iso40EBOnlyTrackIsoLastFilter"){
       //cout<<" HLT: "<<thisTrigObj->GetHLTName()<<endl;                                                                                                                        
       //cout<<" module: "<<thisTrigObj->GetModuleName()<<endl;                                                                                                                   
       //cout<<" id: "<<thisTrigObj->GetId()<<endl;                                                                                                                               
       //thisTrigObj->Print(); 
       //cout << "dR photon hlt_photon: " << Photon.DeltaR(*thisTrigObj) << endl;
       hm->fill1DHist(Photon.DeltaR(*thisTrigObj),"dR_hltpho","dR(Photon,HLT_Photon);dR(Photon,HLT_Photon);Events",100,0,5,1);
       if (Photon.DeltaR(*thisTrigObj) < 0.3 && fired_HLTPhoIdMet) {hltmatched_formaintrig = true;}
       if (Photon.DeltaR(*thisTrigObj) < 0.3 && fired_HLTPhoId) {hltmatched_phoId = true;}

     }
   } 
   //if(!hltmatched) return kTRUE;
   n_hltmatched_count++;
 } 

 if(data){// && fired_HLTPhoIdMet){                                                                                                                                             
   for (int i = 0; i <  triggerObjects->GetSize(); ++i) {
     TCTriggerObject* thisTrigObj = (TCTriggerObject*) triggerObjects->At(i);
     if(thisTrigObj->GetModuleName() == "hltPhoton30HEFilter"){
       if (Photon.DeltaR(*thisTrigObj) < 0.3 && fired_HLTPho) {hltmatched_pho = true;}                                                                                       
     }
   }
 }
 

 ///////////////
 // MET Stuff //
 ///////////////
 
 if(T0MET->Mod() < 30.) return kTRUE;
 
 pfmet_pt       = T0MET->Mod();
 pfMET 	        = TVector2(T0MET->Px(), T0MET->Py());
 mvaMET 	= TVector2(mva_MET->Px(), mva_MET->Py());
 tMET 		= TVector2(track_MET->Px(), track_MET->Py());
 pctMET	        = TVector2(track_MET->Px() - Photon.Px(), track_MET->Py() - Photon.Py());

 //plots
 hm->fill1DHist(pfMET.Mod(), "pfMET_pt", "Particle Flow MET; MET; n_evts", 100, 0, 150, 1);
 hm->fill1DHist(mvaMET.Mod(), "mvaMET_pt", "MVA MET; MET; n_evts", 100, 0, 150, 1);
 hm->fill1DHist(tMET.Mod(), "tMET_pt", "Track MET; MET; n_evts", 100, 0, 150, 1);
 hm->fill1DHist(pctMET.Mod(), "pctMET_pt", "Photon Corrected Track MET; MET; n_evts", 100, 0, 150, 1);
 
 // if(verbose) cout << "End of Photons loop & Begin of VBF" << endl;
 
 //////////////////////
 // MHT Minimization //
 //////////////////////

   float STPrime = T0MET->SumEt();

   if(MHT_verbose){
   cout << "*******************************" << endl;
   cout << "I am looking at a new run" << endl;
   }

   if(MHT_verbose) std::cout << "STPrime: " << STPrime << endl;
   reco_pt.push_back(Photon.Pt());
   reco_phi.push_back(Photon.Phi());
   sigma_ms.push_back(fphoton->Eval(Photon.Pt())*Photon.Pt());
   STPrime -= Photon.Pt();


   if(MHT_verbose)std::cout << "STPrime - Photon Pt: " << STPrime << endl;

   //Looking at electrons.
   found_isolatedElectron = 0;
   int size_jet = recoJets->GetSize();
   int size_elec = recoElectrons->GetSize();
   int size_muon = recoMuons->GetSize();

   int electronIsJet[size_elec];
   int muonIsJet[size_muon];
   int muon1IsJet[size_jet];
   int muon2IsJet[size_jet];

   for (int it = 0; it<size_jet; it++){
     //electronIsJet[it] = 0;
     muon1IsJet[it] = 0;
     muon2IsJet[it] = 0;

   }

   found_genmuon = 0;
   //vector<TCGenParticle> genParticle;
   for (int g = 0; g <  genParticles->GetSize(); ++g) {
     TCGenParticle* thisgen = (TCGenParticle*) genParticles->At(g);
     if(abs(thisgen->GetPDGId()) == 11){ if(MHT_verbose) cout << "Found gen ELECTRON with pt: " << thisgen->Pt() << " with status: "<< thisgen->GetStatus() <<endl; }
     if(abs(thisgen->GetPDGId()) == 13){ 
       found_genmuon = 1;
       if(MHT_verbose) cout << "Found gen MUON with pt: " << thisgen->Pt() << " with status: "<< thisgen->GetStatus() <<endl; }
   }
   
   vector<TCElectron> electronsIDIso;
   for (int i = 0; i <  recoElectrons->GetSize(); ++i) {
     TCElectron* thisElec = (TCElectron*) recoElectrons->At(i);   
     if (thisElec->DeltaR(Photon) > 0.3 && PassElectronID(thisElec, mediumElID) && PassElectronIso(thisElec, mediumElIso)) {
       electronIsJet[i] = 0;
       electronsIDIso.push_back(*thisElec);		
       found_isolatedElectron = 1; 
       
       //overlap check
       for(int jet = 0; jet < recoJets->GetSize(); jet++){
	 TCJet* Jet = (TCJet*) recoJets->At(jet);     
	 if(Jet->DeltaR(*thisElec) < 0.3) {
	   electronIsJet[i] = 1;
	   if(MHT_verbose) cout << "Jet: " << Jet->Pt() << " dR: " <<  Jet->DeltaR(*thisElec) << " ELEC Pt: " << thisElec->Pt()<<endl;}
       } //overlap check
       
       if(MHT_verbose)cout << "elec Pt: " << thisElec->Pt() << " electronIsJet: " << electronIsJet[i] << endl;
       
       if (electronIsJet[i] == 0 && thisElec->Pt()>10.){
	 
	 reco_pt.push_back(thisElec->Pt());
	 reco_phi.push_back(thisElec->Phi());
	 sigma_ms.push_back(fphoton->Eval(thisElec->Pt())* thisElec->Pt());
	 STPrime -= thisElec->Pt();
	 if(MHT_verbose)cout <<"Pushed in this electron: " << thisElec->Pt() << endl;
       }
       else { if(MHT_verbose) cout <<"Removed this electron: " << thisElec->Pt() << endl;}
     }
   }
   
   // Looking at muons:
   
   found_isolatedMuon = 0;
   vector<TCMuon> muonsIDIso;
   
   TLorentzVector Muon1_t, Muon2_t;
   
   bool good_muonpair = false;
   dimuonmass = 0;
   
   for (int i = 0; i < recoMuons->GetSize(); ++ i)  {
     TCMuon* thisMuon = (TCMuon*) recoMuons->At(i);    
     muonIsJet[i] = 0;
     muon1IsJet[i] = 0;
     muon2IsJet[i] = 0;
     
     if (thisMuon->DeltaR(Photon) > 0.3 && PassMuonID(thisMuon, tightMuID) && PassMuonIso(thisMuon, tightMuIso)){
       muonsIDIso.push_back(*thisMuon);
       found_isolatedMuon = 1;
       sort(muonsIDIso.begin(), muonsIDIso.end(), P4SortCondition);
       
       if(muonsIDIso.size()>1 && muonsIDIso[0].Pt() > 20.){
	 for(int k1=0;k1<muonsIDIso.size();k1++){
	   for(int k2=k1+1;k2<muonsIDIso.size();k2++){
	     if(muonsIDIso[k1].Charge()*muonsIDIso[k2].Charge() < 0) {
	       float mass = (muonsIDIso[k1] + muonsIDIso[k2]).M();
	       if(mass>75 && mass<105) {
		 //std::cout<<"good inv mass: "<<mass<< " muon pt: " <<muonsIDIso[k1].Pt() << " " <<muonsIDIso[k2].Pt() <<endl;
		 Muon1_t = TLorentzVector(muonsIDIso[k1].Px(), muonsIDIso[k1].Py(), muonsIDIso[k1].Pz(), muonsIDIso[k1].Energy());
		 Muon2_t = TLorentzVector(muonsIDIso[k2].Px(), muonsIDIso[k2].Py(), muonsIDIso[k2].Pz(), muonsIDIso[k2].Energy());
		 good_muonpair = true;
		 dimuonmass = mass; } } } }
       }
       
       //if(good_muonpair) cout << "Found a good muon pair with mass: "<< (Muon1_t + Muon2_t).M() << " muon pt: " << Muon1_t.Pt() << " " << Muon2_t.Pt() <<endl;
       
       //overlap check
       for(int jet = 0; jet < recoJets->GetSize(); jet++){
	 TCJet* Jet = (TCJet*) recoJets->At(jet);     
	 if(Jet->DeltaR(*thisMuon) < 0.3) muonIsJet[i] = 1; 

	 if(good_muonpair) {
	   if (Jet->DeltaR(Muon1_t) < 0.3) muon1IsJet[jet] = 1;
	   if (Jet->DeltaR(Muon2_t) < 0.3) muon2IsJet[jet] = 1;
	   //cout << "good muon pair and the overlaps: " << muon1IsJet[jet] << " " << muon2IsJet[jet] << " jet pt: " << Jet->Pt() << endl; 
	 }
	 
       } //overlap check
       
       if(MHT_verbose) cout << "Muon Pt: " << thisMuon->Pt() << " muonIsJet: " << muonIsJet[i] << endl;
       
       if(!ddzg || !good_muonpair){
	 if(muonIsJet[i] == 0 && thisMuon->Pt() > 10.){
	   //cout << "In the Muon loop for option: !ddzg || !good_muonpair" <<endl; 
	   reco_pt.push_back(thisMuon->Pt());
	   reco_phi.push_back(thisMuon->Phi());
	   sigma_ms.push_back(fmuon->Eval(thisMuon->Pt())* thisMuon->Pt());
	   STPrime -= thisMuon->Pt();  
	   //  if(MHT_verbose) cout <<"Pushed in this muon: " << thisMuon->Pt() << endl;
	 }
	 //else { if(MHT_verbose) cout <<"Removed this muon: " << thisMuon->Pt() << endl;}
       }
       
       if(ddzg && good_muonpair){
	 //cout << "In the Muon loop for option ddzg && good_muonpair" <<endl;
	 STPrime -= Muon1_t.Pt();
	 STPrime -= Muon2_t.Pt();
       }

     }
   }
   
   for(int jet = 0; jet < recoJets->GetSize(); jet++){
     TCJet* Jet = (TCJet*) recoJets->At(jet);     
     
     if(!ddzg || !good_muonpair){
       if( Jet->DeltaR(Photon) > 0.5 && Jet->Pt() > 20. ){
	 // cout << "In the Jet loop option !ddzg || !good_muonpair" <<endl;
	 //if(MHT_verbose) 
	 //cout << "Jet: " << Jet->Pt() << " Photon : " << Photon.Pt() << " dR: " <<  Jet->DeltaR(Photon) << endl;
	 reco_pt.push_back(Jet->Pt());
	 reco_phi.push_back(Jet->Phi());
	 sigma_ms.push_back(jetreso(fjetreso,Jet->Pt(), Jet->Eta()));
	 STPrime -= Jet->Pt(); 
       }
     }
     else {
       if(good_muonpair && muon1IsJet[jet] == 0 && muon2IsJet[jet] == 0 && Jet->DeltaR(Photon) > 0.5 && Jet->Pt() > 20. ){
	 //cout << "In the Jet loop option good_muonpair && muon1IsJet[jet] == 0 && muon2IsJet[jet] == 0 && Jet->DeltaR(Photon) > 0.5 && Jet->Pt() > 20." <<endl;
         //if(MHT_verbose) 
	 //cout << "Jet: " << Jet->Pt() << " Photon : " << Photon.Pt() << " dR: " <<  Jet->DeltaR(Photon) << endl;
         reco_pt.push_back(Jet->Pt());
         reco_phi.push_back(Jet->Phi());
         sigma_ms.push_back(jetreso(fjetreso,Jet->Pt(), Jet->Eta()));
         STPrime -= Jet->Pt();
       }
     }
   }
  
   if(MHT_verbose){
     if(STPrime<0){
       cout << "ST Prime IS NEGATIVE!! SOMETHING MIGHT BE WRONG: " << STPrime << endl;
     }
     else cout << "ST Left in the event is : " << STPrime << endl;
   }
   
   //cout << "ST Left in the event is : " << STPrime << endl;

   sigma_mex = fmex->Eval(TMath::Abs(STPrime));
   sigma_mey = fmey->Eval(TMath::Abs(STPrime));

   if(MHT_verbose) {std::cout << "sigma_mex: " << sigma_mex << " sigma_mey: " << sigma_mey <<std::endl;}

   Ndim = reco_pt.size();
    
   ROOT::Math::Minimizer* min =  ROOT::Math::Factory::CreateMinimizer("Minuit2", "Migrad");
    min->SetMaxFunctionCalls(1000000);
    min->SetMaxIterations(10000);
    min->SetTolerance(0.0001);
    //if(MHT_verbose) min->SetPrintLevel(4);

    ROOT::Math::Functor f(this,&hzg_selector::func, Ndim); 
    min->SetFunction(f);
    
    // Set the free variables to be minimized!
    for (int i=0; i<Ndim; i++){
      TString name = "pt";
      name += i;

      double lower = TMath::Max(0.,reco_pt[i] - 5*sigma_ms[i]);
      double upper = reco_pt[i] + (5*sigma_ms[i]);
      if(MHT_verbose) {
	std::cout <<" upper: " << upper << "  lower: " << lower << std::endl;
      }
      min->SetLimitedVariable(i,name.Data(),reco_pt[i],0.1,lower,upper);
      //min->SetLowerLimitedVariable(i,name.Data(),reco_pt[i],0.1,lower);
    }   
    
    min->Minimize();         
    const double *xs = min->X(); 
    min->Clear();
    
    p_value = TMath::Prob(func(xs),2);
    
    if(MHT_verbose){
      std::cout << "MHT Minimization Results: " << std::endl;
      std::cout << "Chi2: " << func(xs) << std::endl;
      std::cout<< "P Value: " << p_value << std::endl;
      for(int i =0; i<Ndim;i++){
	std::cout << "Reco: " << reco_pt[i] << " min: " << xs[i] << " reso: " << sigma_ms[i] << std::endl;
      }
    }    

    // Finding Parametrized MET:
    double ParPx = 0.;
    double ParPy = 0.;
    double RecoPx = 0.;
    double RecoPy = 0.;
    
    for(int j=0; j<Ndim; j++){
      ParPx += xs[j]*cos(reco_phi[j]);
      ParPy += xs[j]*sin(reco_phi[j]);
      RecoPx += reco_pt[j]*cos(reco_phi[j]);
      RecoPy += reco_pt[j]*sin(reco_phi[j]);
    }
    
    MinMET = sqrt((ParPx*ParPx)+(ParPy*ParPy));
    RecoMET = sqrt(RecoPx*RecoPx+RecoPy*RecoPy);
    

    if(MHT_verbose){std::cout << "PF MET: " << pfMET.Mod() << " Minimized MET: " << MinMET << " Reco MET: " << RecoMET << std::endl;}
    
    delete min;
    reco_pt.clear();
    reco_phi.clear();
    sigma_ms.clear();

   if(verbose) {


     //cout << " ********* NEW EVENT **********"   <<endl;
     for (int i = 0; i <  triggerObjects->GetSize(); ++i) {
       TCTriggerObject* thisTrigObj = (TCTriggerObject*) triggerObjects->At(i);
       //if(thisTrigObj->GetModuleName() == "hltDiCaloJet35MJJ750AllJetsDEta3p5Filter"){
       if(thisTrigObj->GetModuleName() == "hltMETClean25" || thisTrigObj->GetModuleName() == "hltPhoton30R9Id90CaloIdHE10Iso40EBOnlyTrackIsoLastFilter"){
	 cout<<" HLT: "<<thisTrigObj->GetHLTName()<<endl;
	 cout<<" module: "<<thisTrigObj->GetModuleName()<<endl;
	 cout<<" id: "<<thisTrigObj->GetId()<<endl;
	 thisTrigObj->Print();
	 cout<< "Trigger object Pt : " << thisTrigObj->Pt() <<endl;
	 cout<<endl;
	 }
     }


     cout << "Photon pt "	<< Photon.Pt() << endl;
     cout << "Photon Eta "	<< Photon.Eta() << endl;
   }
   

   TVector2 corrMet_TV;
   if(ddzg && good_muonpair){
     corrMet_TV  = TVector2(T0MET->Px()+Muon1_t.Px()+Muon2_t.Px(), T0MET->Py()+Muon1_t.Py()+Muon2_t.Py());
     corrMet = TMath::Sqrt(pow(T0MET->Px()+Muon1_t.Px()+Muon2_t.Px(),2) + pow(T0MET->Py()+Muon1_t.Py()+Muon2_t.Py(),2));
     corrMetPhi = TMath::ATan2(T0MET->Py()+Muon1_t.Py()+Muon2_t.Py(),T0MET->Px()+Muon1_t.Px()+Muon2_t.Px());
   }
   else {corrMet = 0; corrMetPhi = -99;}

   //////////////////////
   // Tree Assignments //
   //////////////////////

   found_isolatedMu = found_isolatedMuon;
   found_isolatedEl = found_isolatedElectron;

   Pho 		 = &Photon;
   Muon1         = &Muon1_t;
   Muon2         = &Muon2_t;
   if(good_muonpair){
     muon1_pt      = Muon1_t.Pt();
     muon1_eta     = Muon1_t.Eta();
     muon2_pt      = Muon2_t.Pt();
     muon2_eta     = Muon2_t.Eta();
   }
   else {
     muon1_pt      = 0;
     muon1_eta     = 0;
     muon2_pt      = 0;
     muon2_eta     = 0;
   }

   good_photon_n = NumGoodPhotons;

   pfMet 	= &pfMET;
   mvaMet 	= &mvaMET;
   tMet 	= &tMET;
   pctMet 	= &pctMET;
   
   TVector2 Pho2D  = TVector2(Pho->Px(), Pho->Py());
   dphi_pfmetg     = pfMet->DeltaPhi( Pho2D );
   dphi_mvametg    = mvaMet->DeltaPhi(Pho2D );
   dphi_tmetg      = tMet->DeltaPhi(Pho2D );
   dphi_pctmetg    = pctMet->DeltaPhi(Pho2D );
   if(good_muonpair) corrDphi = (&(corrMet_TV))->DeltaPhi(Pho2D );
   else corrDphi = -99;

   dphi_pfmet_mvamet       = pfMet->DeltaPhi(*mvaMet);
   dphi_pfmet_tmet         = pfMet->DeltaPhi(*tMet);
   dphi_pfmet_pctmet       = pfMet->DeltaPhi(*pctMet);
   dphi_mvamet_tmet        = mvaMet->DeltaPhi(*tMet);
   dphi_mvamet_pctmet      = mvaMet->DeltaPhi(*pctMet);
   
   MT_pfmet	= TransverseMass(Pho->Pt(), Pho->Px(), Pho->Py(), pfMet->Mod(), pfMet->Px(), pfMet->Py());
   MT_mvamet	= TransverseMass(Pho->Pt(), Pho->Px(), Pho->Py(), mvaMet->Mod(), mvaMet->Px(), mvaMet->Py());
   MT_tmet	= TransverseMass(Pho->Pt(), Pho->Px(), Pho->Py(), tMet->Mod(), tMet->Px(), tMet->Py());
   MT_pctmet	= TransverseMass(Pho->Pt(), Pho->Px(), Pho->Py(), pctMet->Mod(), pctMet->Px(), pctMet->Py());
   
   pfMet_Significance = recoMET->Significance();
   pfMet_SigmaX2      = recoMET->SigmaX2();


   //PU 
   if(mc){
     npT      = nPUVerticesTrue;
     npIT     = nPUVertices;
     MyWeightData    = LumiWeightsD_.weight(npT);
     MyWeightData_sys    = LumiWeightsD_sys_.weight(npT);

   }


   
   OutTree->Fill();

   return kTRUE;
}

void hzg_selector::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}

void hzg_selector::Terminate()
{
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.


  cout<<"unskimmed total: "<<unskimmedEventsTotal<<endl;
  cout << "passed_filters: " << pass_filter <<endl;
  cout << "n_vertex_count: " << n_vertex_count << endl;
  cout << "n_photon_count: " << n_photon_count << endl;
  cout << "n_hltmatched_count: "<< n_hltmatched_count <<endl;

  hm->writeHists();
  AnDir->cd();
  OutTree->Write();
  histoFile->cd();
  histoFile->cd();
  histoFile->Close();
}


bool hzg_selector::PassPhotonID(TCPhoton *ph, phIDCuts cutLevel){
  float tmpEta;
  bool phoPass = false;
  tmpEta = ph->SCEta();
  if (fabs(tmpEta) > 2.5) return phoPass;
  if (fabs(tmpEta) > 1.4442 && fabs(tmpEta) < 1.566) return phoPass;
  if(
     (fabs(tmpEta)  < 1.4442
      && ph->ConversionVeto()       == cutLevel.PassedEleSafeVeto[0]
      && ph->HadOverEm()               < cutLevel.HadOverEm[0]
      && ph->SigmaIEtaIEta()           < cutLevel.sigmaIetaIeta[0]
      ) ||
     (fabs(tmpEta)  > 1.566
      && ph->ConversionVeto()       == cutLevel.PassedEleSafeVeto[1]
      && ph->HadOverEm()               < cutLevel.HadOverEm[1]
      && ph->SigmaIEtaIEta()           < cutLevel.sigmaIetaIeta[1]
      )
     ) phoPass = true;
  return phoPass;
}


bool hzg_selector::PassPhotonIso(TCPhoton *ph, phIsoCuts cutLevel){
  float chEA,nhEA,phEA,chIsoCor,nhIsoCor,phIsoCor,tmpEta;
  bool isoPass = false;
  tmpEta = ph->SCEta();

  if(fabs(tmpEta) > 2.5) return isoPass;

  if (fabs(tmpEta) < 1.0){
    chEA = EAPho[0][0];
    nhEA = EAPho[0][1];
    phEA = EAPho[0][2];
  }else if (fabs(tmpEta) < 1.479){
    chEA = EAPho[1][0];
    nhEA = EAPho[1][1];
    phEA = EAPho[1][2];
  }else if (fabs(tmpEta) < 2.0){
    chEA = EAPho[2][0];
    nhEA = EAPho[2][1];
    phEA = EAPho[2][2];
  }else if (fabs(tmpEta) < 2.2){
    chEA = EAPho[3][0];
    nhEA = EAPho[3][1];
    phEA = EAPho[3][2];
  }else if (fabs(tmpEta) < 2.3){
    chEA = EAPho[4][0];
    nhEA = EAPho[4][1];
    phEA = EAPho[4][2];
  }else if (fabs(tmpEta) < 2.4){
    chEA = EAPho[5][0];
    nhEA = EAPho[5][1];
    phEA = EAPho[5][2];
  }else{
    chEA = EAPho[6][0];
    nhEA = EAPho[6][1];
    phEA = EAPho[6][2];
  }

  chIsoCor = ph->IsoMap("chIso03")-rhoFactor*chEA;
  nhIsoCor = ph->IsoMap("nhIso03")-rhoFactor*nhEA;
  phIsoCor = ph->IsoMap("phIso03")-rhoFactor*phEA;

  if (cutLevel.cutName == "loosePhIso"){
    if (
        (fabs(tmpEta) < 1.4442
	 //(fabs(ph->Eta())  < 1.566                                                                                                                                                
         && max((double)chIsoCor,0.)          < cutLevel.chIso03[0]
         && max((double)nhIsoCor,0.)          < cutLevel.nhIso03[0] + 0.04*ph->Pt()
         && max((double)phIsoCor,0.)          < cutLevel.phIso03[0] + 0.005*ph->Pt()
	 ) ||
	(fabs(tmpEta) > 1.566
	 //(fabs(ph->Eta())  > 1.566                                                                                                                                                
         && max((double)chIsoCor,0.)          < cutLevel.chIso03[1]
         && max((double)nhIsoCor,0.)          < cutLevel.nhIso03[1] + 0.04*ph->Pt()
         //&& phoCut["phIso03"]/ph->Pt() < nuthin                                                                                                                                  
	 )
	) isoPass = true;
  } else {
    if (
	//(fabs(ph->Eta())  < 1.566                                                                                                                                                
        (fabs(tmpEta) < 1.4442
         && max((double)chIsoCor,0.)          < cutLevel.chIso03[0]
         && max((double)nhIsoCor,0.)          < cutLevel.nhIso03[0] + 0.04*ph->Pt()
         && max((double)phIsoCor,0.)          < cutLevel.phIso03[0] + 0.005*ph->Pt()
	 ) ||
        //(fabs(ph->Eta())  > 1.566                                                                                                                                                
        (fabs(tmpEta) > 1.566
         && max((double)chIsoCor,0.)          < cutLevel.chIso03[1]
         && max((double)nhIsoCor,0.)          < cutLevel.nhIso03[1] + 0.04*ph->Pt()
         && max((double)phIsoCor,0.)          < cutLevel.phIso03[1] + 0.005*ph->Pt()
	 )
	) isoPass = true;
  }
  return isoPass;
}

bool hzg_selector::PassElectronIso(TCElectron *el, elIsoCuts cutLevel){
  float thisEA = 0;
  if (fabs(el->Eta())     <  1.0) thisEA = EAEle[0];
  else if (fabs(el->Eta())     <  1.5) thisEA = EAEle[1];
  else if (fabs(el->Eta())     <  2.0) thisEA = EAEle[2];
  else if (fabs(el->Eta())     <  2.2) thisEA = EAEle[3];
  else if (fabs(el->Eta())     <  2.3) thisEA = EAEle[4];
  else if (fabs(el->Eta())     <  2.4) thisEA = EAEle[5];
  else if (fabs(el->Eta())     >  2.4) thisEA = EAEle[6];

  float combIso = (el->IsoMap("pfChIso_R04")
    + max(0.,(double)el->IsoMap("pfNeuIso_R04") + el->IsoMap("pfPhoIso_R04") - rhoFactor*thisEA));
  bool isoPass = false;
  if (combIso/el->Pt() < cutLevel.relCombIso04) isoPass = true;
  return isoPass;
}


bool hzg_selector::PassMuonID(TCMuon *mu, muIDCuts cutLevel){

  bool muPass = false;
  if (
    fabs(mu->Eta()) < 2.4
      && mu->IsPF()                          == cutLevel.IsPF
      && mu->IsGLB()                         == cutLevel.IsGLB
      && mu->NormalizedChi2()                < cutLevel.NormalizedChi2
      && mu->NumberOfValidMuonHits()         > cutLevel.NumberOfValidMuonHits
      && mu->NumberOfMatchedStations()       > cutLevel.NumberOfMatchedStations
      && mu->NumberOfValidPixelHits()        > cutLevel.NumberOfValidPixelHits
      && mu->TrackLayersWithMeasurement()    > cutLevel.TrackLayersWithMeasurement
      && fabs(mu->Dxy(pvPosition))           < cutLevel.dxy
      && fabs(mu->Dz(pvPosition))            < cutLevel.dz
    ) muPass = true;
  return muPass;

}

bool hzg_selector::PassMuonIso(TCMuon *mu, muIsoCuts cutLevel){

  float combIso;

  combIso = (mu->IsoMap("pfChargedHadronPt_R04")
    + max(0.,(double)mu->IsoMap("pfNeutralHadronEt_R04") + mu->IsoMap("pfPhotonEt_R04") - 0.5*mu->IsoMap("pfPUPt_R04")));

  bool isoPass = false;
  if (combIso/mu->Pt() < cutLevel.relCombIso04) isoPass = true;
  return isoPass;
}



bool hzg_selector::PassElectronID(TCElectron *el, elIDCuts cutLevel)
{
  bool elPass = false;
  if (fabs(el->SCEta()) > 2.5) return elPass;
  if (fabs(el->SCEta()) > 1.4442 && fabs(el->SCEta()) < 1.566) return elPass;
  if (
    (fabs(el->Eta()) < 1.566
      && fabs(el->DetaSuperCluster())    < cutLevel.dEtaIn[0]
      && fabs(el->DphiSuperCluster())    < cutLevel.dPhiIn[0]
      && el->SigmaIEtaIEta()             < cutLevel.sigmaIetaIeta[0]
      && el->HadOverEm()                 < cutLevel.HadOverEm[0]
      && fabs(el->Dxy(pvPosition))       < cutLevel.dxy[0]
      && fabs(el->Dz(pvPosition))        < cutLevel.dz[0]
      && el->IdMap("fabsEPDiff")         < cutLevel.fabsEPDiff[0]
      && el->ConversionMissHits()        <= cutLevel.ConversionMissHits[0]
      && el->ConversionVeto()            == cutLevel.PassedConversionProb[0]
      ) ||
    (fabs(el->Eta()) > 1.566  
      && fabs(el->DetaSuperCluster())    < cutLevel.dEtaIn[1]
      && fabs(el->DphiSuperCluster())    < cutLevel.dPhiIn[1]
      && el->SigmaIEtaIEta()             < cutLevel.sigmaIetaIeta[1]
      && el->HadOverEm()                 < cutLevel.HadOverEm[1]
      && fabs(el->Dxy(pvPosition))       < cutLevel.dxy[1]
      && fabs(el->Dz(pvPosition))        < cutLevel.dz[1]
      && el->IdMap("fabsEPDiff")         < cutLevel.fabsEPDiff[1]
      && el->ConversionMissHits()        <= cutLevel.ConversionMissHits[1]
      && el->ConversionVeto()            == cutLevel.PassedConversionProb[1]
      )
      ) elPass = true; 
    //   cout<<"evt: "<<eventNumber<<" muon num: "<<recoMuons->GetSize()<<endl;
       for (int j = 0; j < recoMuons->GetSize(); ++ j)
       {
         TCMuon* thisMuon = (TCMuon*) recoMuons->At(j);    
    //     if (eventNumber==11944 || eventNumber==1780) cout<<thisMuon->DeltaR(*el)<<endl;
         if (thisMuon->DeltaR(*el) < 0.05){
           //cout<<"event: "<<eventNumber<<endl;
           //cout<<"unclean"<<endl;
           //el->Print();
           elPass = false;
           break;
         }
       }
       return elPass;
}




double  hzg_selector::func(const double* par){
  Ndim = reco_pt.size();
  double px = 0, py =0, arg = 0;  
  for(int i=0; i<Ndim; i++){
    px += par[i]*cos(reco_phi[i]);
    py += par[i]*sin(reco_phi[i]);
    arg += pow((reco_pt[i]-par[i])/(sigma_ms[i]),2);
  }
  return arg + ((px*px)/(sigma_mex*sigma_mex) + (py*py)/(sigma_mey*sigma_mey));
}

double  hzg_selector::jetreso(TF1 *fjetreso_T, double pt, double eta_or){
  double reso = 0;
  //TF1 *fjetreso = new TF1 ("jetReso","TMath::Sqrt(((sign([0])*(([0]/x)^2))+(([1]^2)*(x^([2]-1.))))+([3]^2))",0,15000);
  double scale = 0;

  double eta = TMath::Abs(eta_or);

  if (eta <= 0.3)              {fjetreso_T->SetParameters(2.866,0.3118,0.4075,0.01823); scale = 1.052;}
  if (eta > 0.3 && eta <= 0.5) {fjetreso_T->SetParameters(2.91,0.2793,0.4629,0.001049); scale = 1.052;}
  if (eta > 0.5 && eta <= 0.8) {fjetreso_T->SetParameters(2.768,0.3797,0.3144,0.02803); scale = 1.057;}
  if (eta > 0.8 && eta <= 1.1) {fjetreso_T->SetParameters(2.934,0.3251,0.4401,0.0079); scale = 1.057;}
  if (eta > 1.1 && eta <= 1.4) {fjetreso_T->SetParameters(2.617,0.736,0.0899,-0.04179); scale = 1.096;}
  if (eta > 1.4 && eta <= 1.7) {fjetreso_T->SetParameters(0.1406,1.477,-0.2062,-0.03656); scale = 1.096;}
  if (eta > 1.7 && eta <= 2.0) {fjetreso_T->SetParameters(1.959,1.099,-0.1357,-0.02382); scale = 1.134;}
  if (eta > 2.0 && eta <= 2.3) {fjetreso_T->SetParameters(4.113,0.4146,0.1918,0.02413); scale = 1.134;}
  if (eta > 2.3 && eta <= 2.8) {fjetreso_T->SetParameters(5.817,0.1547,0.5529,0.001136); scale = 1.288;}
  if (eta > 2.8 && eta <= 3.2) {fjetreso_T->SetParameters(4.894,0.3666,0.4251,-0.00215); scale = 1.288;}
  if (eta > 3.2 && eta <= 4.1) {fjetreso_T->SetParameters(3.624,0.2542,0.6046,0.02232); scale = 1.288;}
  if (eta > 4.1)               {fjetreso_T->SetParameters(2.727,1.035,-0.1662,0); scale = 1.288;}


  if(mc)   reso = pt * fjetreso_T->Eval(pt);
  if(data) reso = pt * scale * fjetreso_T->Eval(pt);
  return reso;

}
