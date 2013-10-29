#include "HistManager.h"

  HistManager::HistManager(TFile* theFile, TString DirName){
    myFile = theFile;
    dirName = DirName;
  }


  HistManager::~HistManager(){

  }
    
    
  void HistManager::writeHists(){
    
    myFile->cd();
    if(dirName != "") {
	TDirectory* dir = myFile->GetDirectory(dirName);	
	if(dir) {
	  dir->cd();
	} else {
	  myFile->mkdir(dirName, dirName);
	  TDirectory* dir2 = myFile->GetDirectory(dirName);
	  if(dir2) {
	    dir2->cd();
	  } else { cout << "Ay, Caramba! Something went very wrong..." << endl;}
	}
    }
    std::map<std::string,TH1F*>::const_iterator mapit1;
    std::map<std::string,TH2F*>::const_iterator mapit2;
    std::map<std::string,TProfile*>::const_iterator mapit3;
    for (mapit1 = the1DMap.begin(); mapit1 != the1DMap.end(); ++mapit1){
      (*mapit1).second->Write();
    }
    for (mapit2 = the2DMap.begin(); mapit2 != the2DMap.end(); ++mapit2){
      (*mapit2).second->Write();
    }
    for (mapit3 = theProfMap.begin(); mapit3 != theProfMap.end(); ++mapit3){
      (*mapit3).second->Write();
    }
    //myFile->cd();
//    myFile->Close();
    
  }
    

  void HistManager::fill1DHist(float x, std::string name, std::string title,
                               int bins, float xmin, float xmax, float weight){
  
    myFile->cd();
    std::map<std::string,TH1F*>::iterator it;
    it = the1DMap.find(name);
    if (it == the1DMap.end()){
      the1DMap[name] = new TH1F(name.c_str(),title.c_str(),bins,xmin,xmax);
    }

    the1DMap[name]->Fill(x,weight);

  }

  void HistManager::fill1DHist(float x, std::string name, std::string title,
                               int bins, float xmin, float xmax, float weight,std::string folder){
  
    myFile->cd();
    std::map<std::string,TH1F*>::iterator it;
    it = the1DMap.find(name);
    if (it == the1DMap.end()){
      myFile->cd(folder.c_str());
      the1DMap[name] = new TH1F(name.c_str(),title.c_str(),bins,xmin,xmax);
   //   myFile->cd();
    }


    the1DMap[name]->Fill(x,weight);

  }

  void HistManager::fill1DHistUnevenBins(float x, std::string name, std::string title,
                                         int bins, float *binEdges, float weight){
    myFile->cd();
    std::map<std::string,TH1F*>::iterator it;
    it = the1DMap.find(name);
    if (it == the1DMap.end()){
      the1DMap[name] = new TH1F(name.c_str(),title.c_str(),bins,binEdges);
    }


    the1DMap[name]->Fill(x,weight);

  }

  void HistManager::fill1DHistUnevenBins(float x, std::string name, std::string title,
                                         int bins, float *binEdges, float weight,std::string folder){
    myFile->cd();
    std::map<std::string,TH1F*>::iterator it;
    it = the1DMap.find(name);
    if (it == the1DMap.end()){
      myFile->cd(folder.c_str());
      the1DMap[name] = new TH1F(name.c_str(),title.c_str(),bins,binEdges);
    //  myFile->cd();
    }


    the1DMap[name]->Fill(x,weight);

  }



  void HistManager::fill2DHist(float x, float y, std::string name, std::string title,
                               int binsx, float xmin, float xmax,
                               int binsy, float ymin, float ymax, float weight){

    myFile->cd();
    std::map<std::string,TH2F*>::iterator it;
    it = the2DMap.find(name);
    if (it == the2DMap.end()){
      the2DMap[name] = new TH2F(name.c_str(),title.c_str(),binsx,xmin,xmax,binsy,ymin,ymax);
    }

    the2DMap[name]->Fill(x,y,weight);

  }

  void HistManager::fill2DHist(float x, float y, std::string name, std::string title,
                               int binsx, float xmin, float xmax,
                               int binsy, float ymin, float ymax, float weight,std::string folder){

    myFile->cd();
    std::map<std::string,TH2F*>::iterator it;
    it = the2DMap.find(name);
    if (it == the2DMap.end()){
      myFile->cd(folder.c_str());
      the2DMap[name] = new TH2F(name.c_str(),title.c_str(),binsx,xmin,xmax,binsy,ymin,ymax);
   //   myFile->cd();
    }

    the2DMap[name]->Fill(x,y,weight);

  }

  void HistManager::fillProfile(float x, float y, std::string name, std::string title,
                                int binsx, float xmin, float xmax,
                                float ymin, float ymax, float weight){

    myFile->cd();
    std::map<std::string,TProfile*>::iterator it;
    it = theProfMap.find(name);
    if (it == theProfMap.end()){
      theProfMap[name] = new TProfile(name.c_str(),title.c_str(),binsx,xmin,xmax,ymin,ymax);
    }

    theProfMap[name]->Fill(x,y,weight);

  }

  void HistManager::fillProfile(float x, float y, std::string name, std::string title,
                                int binsx, float xmin, float xmax,
                                float ymin, float ymax, float weight,std::string folder){

    myFile->cd();
    std::map<std::string,TProfile*>::iterator it;
    it = theProfMap.find(name);
    if (it == theProfMap.end()){
      myFile->cd(folder.c_str());
      theProfMap[name] = new TProfile(name.c_str(),title.c_str(),binsx,xmin,xmax,ymin,ymax);
   //   myFile->cd();
    }

    theProfMap[name]->Fill(x,y,weight);

  }


