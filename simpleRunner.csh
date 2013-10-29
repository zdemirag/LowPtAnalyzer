#!/bin/csh

cp hzg_selector_Template.C hzg_selector.C

tar  -xzf plugins.tar.gz
tar  -xzf src.tar.gz
tar  -xzf PhysicsTools.tar.gz

sed -i "s/SUFFIX/$1/g" hzg_selector.C

cat > run.C << +EOF
    
	#include <iostream>
	#include <fstream>
	#include <string>
	#include <vector>
	#include <cstdlib>

	using namespace std;

	void run() {

     gROOT->ProcessLine("#include <TLorentzVector.h>");

     gROOT->LoadMacro("src/TCPhysObject.cc+");  
     gROOT->LoadMacro("src/TCJet.cc+");
     gROOT->LoadMacro("src/TCMET.cc+");
     gROOT->LoadMacro("src/TCElectron.cc+");
     gROOT->LoadMacro("src/TCMuon.cc+");
     gROOT->LoadMacro("src/TCTau.cc+");
     gROOT->LoadMacro("src/TCPhoton.cc+");
     gROOT->LoadMacro("src/TCGenJet.cc+");
     gROOT->LoadMacro("src/TCGenParticle.cc+");
     gROOT->LoadMacro("src/TCPrimaryVtx.cc+");
     gROOT->LoadMacro("src/TCTriggerObject.cc+");

     gROOT->LoadMacro("plugins/HistManager.cc+");
     gROOT->LoadMacro("plugins/TriggerSelector.cc+");
     
     TChain* fChain = new TChain("ntupleProducer/eventTree");

     ifstream sourceFiles("$1.txt");
     char line[128];
     int  count = 0;
     cout<<"Adding files from $1 to chain..."<<endl;

	  while (sourceFiles >> line) {
	    fChain->Add(line);      
       ++count;
	  }
	  cout<<count<<" files added!"<<endl;
	  sourceFiles.close();

	  TStopwatch timer;
	  timer.Start();

//	  fChain->Process("simple_v2.C+");
          fChain->Process("hzg_selector.C++");  
	  
	  cout << "\n\nDone!" << endl;
	  cout << "CPU Time : " << timer.CpuTime() << endl;
	  cout << "RealTime : " << timer.RealTime() << endl;
     cout << "\n";
	}
                                          
+EOF

root -l -b -q run.C

rm -f run.C
rm -f hzg_selector.C
