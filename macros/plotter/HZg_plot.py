import ROOT, sys, os, string, re
from ROOT import TCanvas, TFile, TProfile, TNtuple, TH1F, TH1D, TH2D, TH2F, TF1, TPad, TPaveLabel, TPaveText, TLegend, TLatex, THStack, TGraph, TGraphErrors, TColor, TMath
from ROOT import gROOT, gBenchmark, gRandom, gSystem, Double, gPad

from array import array

import math
from math import *

from tdrStyle import *
setTDRStyle()

from LoadData import *

print "Starting Plotting Be Patient!"

scale_up = 1000000.
lumi = 7369.
lumi_str = '7.369'

def plot_nice1D(channel, var, bin, low, high, ylabel, xlabel, save, setLog = False, finalcuts = False):

    ##   List = ['DiPhoton','WGamma','WJets','G_Pt-0to15','G_Pt-15to30','G_Pt-30to50','G_Pt-50to80','G_Pt-80to120','G_Pt-120to170','G_Pt-170to300', 'G_Pt-300to470', 'G_Pt-470to800', 'G_Pt-800to1400','G_Pt-1400to1800','G_Pt-1800','QCD_20to30', 'QCD_30to80', 'QCD_80to170', 'QCD_170to250' ,'QCD_250to350', 'QCD_350','Signal_VBF', 'Signal_GluGlu','Data_GGF','DD_Data_GGF']

#Took out G 50,80
    List = ['DiPhoton','WGamma','WJets','G_Pt-0to15','G_Pt-15to30','G_Pt-30to50','G_Pt-80to120','G_Pt-120to170','G_Pt-170to300', 'G_Pt-300to470', 'G_Pt-470to800','G_Pt-800to1400','G_Pt-1400to1800','G_Pt-1800','QCD_20to30', 'QCD_30to80', 'QCD_80to170', 'QCD_170to250' ,'QCD_250to350', 'QCD_350','Signal_VBF', 'Signal_GluGlu','Data_GGF','DD_Data_GGF']  

    cut_GGFTrig = " && hltmatched_formaintrig==1"
    cut_standard = "pho_pt > 30. && found_isolatedMu ==0 && found_isolatedEl ==0 && p_value < 0.05 && good_photon_n ==1"
    cut_met = " && pfmet_pt>40."# && TMath::Abs(dphi_pfmetg) < 1.5"
    cut_ddzg = " && dimuonmass>0 && corrMet>40 "#&& TMath::Abs( (corrMet_phi - pho_phi) ) < 1.5"

    pu_weight = "MyWeightData"
    trig_phoid = "((0.5*0.892*(1+TMath::Erf((pho_pt-(-36.8)) / (43.8*sqrt(2))))) * (pho_pt>30) )"
    trig_met = " ( (0.5*0.986*(1+TMath::Erf( (pfmet_pt-28) / (26*sqrt(2)) ) ) )*(pfmet_pt>40.) )"

    weight  = pu_weight +"*"+ trig_phoid + "*" +trig_met

    stack = THStack('a', 'a')
    Variables = {}
    
    totalbkg = 0
    bkg = 0
    totalWeight = 0
    data = 0

    #Trees[Type].Draw(var + " >> " + histName,  "(" + cut_standard + cut_met  + cut_GGFTrig ")"  , "goff")

    #Trees[Type].Draw(var + " >> " + histName,  "(" + cut_standard + cut_ddzg  + cut_GGFTrig ")"  , "goff")
    
    
    for Type in List:

        #print Type

        Variables[Type] = TH1F(Type+save+channel, Type+save+channel, bin, low, high)
        histName = Type+save+channel
        
        #Trees[Type].Draw(var + " >> " + histName,  "(" + cut_standard + cut_met  + ") *"+ pu_weight + "*" + trig_phoid + "*" + trig_met   , "goff")

        totalWeight += xsec[Type]/Nevents[Type]

        #print "Integral not scaled : ", Type , Variables[Type].Integral()
           
        if Variables[Type].Integral() != 0:
            if not (Type.startswith("Signal") or Type.startswith("Data")):
                bkg += Variables[Type].Integral()
                totalbkg+= Variables[Type].Integral()
            if not Type.startswith("Data"):
                Variables[Type].Scale(lumi / Nevents[Type] * xsec[Type])

        #print "Integral scaled : ", Type , Variables[Type].Integral()
       
        if Type.startswith("WJets"):
            Variables[Type].SetFillColor(7)
            Variables[Type].SetLineColor(7)
            #print Type
            Trees[Type].Draw(var + " >> " + histName,  "(" + cut_standard + cut_met  + ") *"+weight   , "goff")
            stack.Add(Variables[Type])

        ##if Type.startswith("DiPhoton"):
          ##  Variables[Type].SetFillColor(ROOT.kOrange-3)
          ##  Variables[Type].SetLineColor(ROOT.kOrange-3)
          ##  Trees[Type].Draw(var + " >> " + histName,  "(" + cut_standard + cut_met  + ") *"+weight   , "goff")
            #print Type
          ##  stack.Add(Variables[Type])

        if Type.startswith("WGamma"):
            Variables[Type].SetFillColor(ROOT.kGreen-3)
            Variables[Type].SetLineColor(ROOT.kGreen-3)
            #print Type
            Trees[Type].Draw(var + " >> " + histName,  "(" + cut_standard + cut_met  + ") *"+weight   , "goff")
            stack.Add(Variables[Type])

        if Type.startswith("G_Pt-"):
            Variables[Type].SetFillColor(ROOT.kRed-7)
            Variables[Type].SetLineColor(ROOT.kRed-7)
            Trees[Type].Draw(var + " >> " + histName,  "(" + cut_standard + cut_met  + ") *"+weight   , "goff")
            stack.Add(Variables[Type])

        if Type.startswith("QCD"):
            Variables[Type].SetFillColor(9)
            Variables[Type].SetLineColor(9)
            Trees[Type].Draw(var + " >> " + histName,  "(" + cut_standard + cut_met  + ") *"+weight   , "goff")
            #print Type
            stack.Add(Variables[Type])

        if Type.startswith("Signal_VBF"):
            Variables[Type].SetLineColor(4)
            Variables[Type].SetLineWidth(3)
            Variables[Type].SetLineStyle(5)
            Trees[Type].Draw(var + " >> " + histName,  "(" + cut_standard + cut_met  + ") *"+weight   , "goff")
            Variables[Type].Scale(scale_up)

        if Type.startswith("Signal_Glu"):
            Variables[Type].SetLineColor(1)
            Variables[Type].SetLineWidth(3)
            Variables[Type].SetLineStyle(5)
            Trees[Type].Draw(var + " >> " + histName,  "(" + cut_standard + cut_met  + ") *"+weight   , "goff")
            Variables[Type].Scale(scale_up)

        if Type.startswith("Data_GGF"):
            Variables[Type].SetMarkerStyle(20)
            Trees[Type].Draw(var + " >> " + histName,  "(" + cut_standard + cut_met  + cut_GGFTrig +")"  , "goff")

        if Type.startswith("DD_Data"):
            Variables[Type].Scale(280.123)
            Variables[Type].SetFillColor(1)
            Variables[Type].SetLineWidth(3)
            Trees[Type].Draw(var + " >> " + histName,  "(" + cut_standard + cut_ddzg  + cut_GGFTrig + ")"  , "goff")
            stack.Add(Variables[Type])
                        
    legend = TLegend(.60,.70,.90,.90)
    legend . AddEntry( Variables['QCD_20to30'], "QCD" , "f")
    legend . AddEntry( Variables['G_Pt-0to15'], "#gamma + Jets" , "f")
    legend . AddEntry( Variables['WJets'], "W + Jets" , "f")
    #legend . AddEntry( Variables['W2lnuEl'], "W #rightarrow l #nu" , "f")
    legend . AddEntry( Variables['WGamma'], "W #gamma #rightarrow l #nu #gamma" , "f")
    legend . AddEntry( Variables['DiPhoton'], "#gamma #gamma" , "f")
    #legend . AddEntry( Variables['W2lnuMu'], "W #rightarrow #mu #nu" , "f")
    #legend . AddEntry( Variables['W2lnuTau'], "W #rightarrow #tau #nu" , "f")
    legend . AddEntry( Variables['DD_Data_GGF'], "Data Driven ZnunuGamma","f")    
    legend . AddEntry( Variables['Signal_GluGlu'], "GGF Signal X 1M", "l")
    legend . AddEntry( Variables['Signal_VBF'], "VBF Signal X 1M", "l")

    #legend . AddEntry( Variables['Data_GGF'], "VBF Data", "p")
    legend . AddEntry( Variables['Data_GGF'], "Inclusive Data", "p")


    c4 = TCanvas("c4","c4", 1000, 900)
    #c4.SetBottomMargin(0.3)
    #c4.SetRightMargin(0.06)
    stack.SetMaximum( stack.GetMaximum()  +  10*stack.GetMaximum() )
    
    #stack.SetMaximum(Variables['Data_GGF'].GetMaximum()*10 )

    stack.SetMinimum(0.1)

    if setLog:
        c4.SetLogy()
        stack.SetMaximum( stack.GetMaximum()  +  10*stack.GetMaximum() )
    
    stack.Draw()
    #stack.GetYaxis().CenterTitle()
    stack.GetYaxis().SetTitle(ylabel)
    stack.GetXaxis().SetTitle(xlabel)

    Variables['Signal_GluGlu'].Draw("same")
    #Variables['Signal_VBF'].Draw("same")
    Variables['Data_GGF'].Draw("Esame")
    
    legend.SetShadowColor(0);
    legend.SetFillColor(0);
    legend.SetLineColor(0);
    legend.Draw("same")
    
    latex2 = TLatex()
    latex2.SetNDC()
    latex2.SetTextSize(0.035)
    latex2.SetTextAlign(31) # align right
    latex2.DrawLatex(0.87, 0.95, "CMS Preliminary H #rightarrow Z #gamma, "+lumi_str+" pb^{-1} at #sqrt{s} = 8 TeV");
    
    c4.SaveAs('StackedHisto_' + save + '.pdf')

    if save.startswith('pho_pt'):
        print "*******************************************************"
        print "bkg scaled to ",lumi,"/pb: " ,round(totalbkg,2) #, " scaled to 18/fb: " ,  round(totalbkg* 18000,2) ,  " scaled to 7.6/fb: " ,  round(totalbkg* 7600,2)
        #print "total # of entries for bkg is:  " , bkg

        print "Data: ", Variables['Data_GGF'].Integral()
        scaled_GGF =  round(Variables['Signal_GluGlu'].Integral()/ scale_up,2)
        sig_GGF = round(scaled_GGF / sqrt(totalbkg),2)
        
        print "GGF scaled to ",lumi,"/pb: " ,  scaled_GGF,  "Significance: ", sig_GGF
        #print "GGF count is: ",  round(Variables['Signal_GluGlu'].Integral(),2), "Significance: ", round(Variables['Signal_GluGlu'].Integral()/sqrt(totalbkg),2)


        scaled_VBF =  round(Variables['Signal_VBF'].Integral()/ scale_up,2)
        sig_VBF = round(scaled_VBF / sqrt(totalbkg),2)

        print "VBF scaled to ",lumi,"/pb: " , scaled_VBF , "Significance: ", sig_VBF
        #print "VBF count is: ",  round(Variables['Signal_VBF'].Integral(),2) , "Significance: ", round(Variables['Signal_VBF'].Integral()/sqrt(totalbkg),2)
        print "*******************************************************"

        #print totalWeight
    
    del c4
    del stack
    del Variables

   
    
## Variables We Want to Plot
var = 'pho_pt'; bin = 80; low = 0; high = 400; xaxis = "Photon P_{T} [GeV]"; yaxis = 'Events / 5 GeV'; save = 'pho_pt'; setLog = True; finalcuts = False;channel = "VBF";
plot_nice1D(channel,var, bin, low, high, yaxis, xaxis , save, setLog, finalcuts)

## var = 'Pho.Pt()/pfMet.Mod()'; bin = 10; low = 0; high = 1.5; xaxis = "Ratio [GeV]"; yaxis = 'Events / 1 GeV'; save = 'pho_pt_ratio'; setLog = True; finalcuts = False;channel = "VBF";
## plot_nice1D(channel,var, bin, low, high, yaxis, xaxis , save, setLog, finalcuts)

#var = 'MT_pfmet';

#var = '(2*Pho.E()*pfMet.Mod() * (1-cos(dphi_pfmetg)))^(0.5)';
#bin = 30; low = 0; high = 150; xaxis = "MT (met,gamma) [GeV]"; yaxis = 'Events / 5 GeV'; save = 'mt_pfmet'; setLog = True; finalcuts = False;channel = "VBF"
#plot_nice1D(channel,var, bin, low, high, yaxis, xaxis , save, setLog, finalcuts)

## var = 'TMath::Abs(dphi_pfmetg)'; bin = 40; low = 0; high = 4; xaxis = "dphi_pfmetg"; yaxis = 'Events'; save = 'dphi_pfmetg'; setLog = True; finalcuts = False;channel = "VBF
## plot_nice1D(channel,var, bin, low, high, yaxis, xaxis , save, setLog, finalcuts)

## var = 'TMath::Abs(dphi_photon_dijet)'; bin = 40; low = 0; high = 4; xaxis = " dphi_photon_dijet [GeV]"; yxis = 'Events'; save = 'dphi_photon_dijet'; setLog = True; finalcuts = False;channel = "VBF"
## plot_nice1D(channel,var, bin, low, high, yaxis, xaxis , save, setLog, finalcuts)

## var = 'TMath::Abs(dphi_pfmet_dijet)'; bin = 40; low = 0; high = 4; xaxis = "dphi_pfmet_dijet [GeV]"; yaxis = 'Events'; save = 'dphi_pfmet_dijet'; setLog = True; finalcuts = False;channel = "VBF"
## plot_nice1D(channel,var, bin, low, high, yaxis, xaxis , save, setLog, finalcuts)
 
## var = 'VBFj0_pt'; bin = 80; low = 0; high = 400; xaxis = "Leading Jet P_{T} [GeV]"; yaxis = 'Events / 5 GeV'; save = 'leading_jet_pt'; setLog = True; finalcuts = False;channel = "VBF"
## plot_nice1D(channel,var, bin, low, high, yaxis, xaxis , save, setLog, finalcuts)

## var = 'VBFj1_pt'; bin = 60; low = 0; high = 300; xaxis = "Trailing Jet P_{T} [GeV]"; yaxis = 'Events / 5 GeV'; save = 'trailing_jet_pt'; setLog = True; finalcuts = False;channel = "VBF"
## plot_nice1D(channel,var, bin, low, high, yaxis, xaxis , save, setLog, finalcuts)

#var = 'VBFDiJet_M'; bin = 80; low = 0; high = 2000; xaxis = "M_{jj} [GeV]"; yaxis = 'Events / 25 GeV'; save = 'mjj'; setLog = True; finalcuts = False;channel = "VBF"
#plot_nice1D(channel,var, bin, low, high, yaxis, xaxis , save, setLog, finalcuts)

#var = 'VBF_DeltaEta'; bin = 100; low = 0; high = 10; xaxis = "#Delta #eta_{jj}"; yaxis = 'Events'; save = 'delta_eta_jj'; setLog = True; finalcuts = False;channel = "VBF"
#plot_nice1D(channel,var, bin, low, high, yaxis, xaxis , save, setLog, finalcuts)

#var = 'pfMet.Mod()'; bin = 60; low = 0; high = 300; xaxis = "PF ME_{T} [GeV]"; yaxis = 'Events / 5 GeV'; save = 'pfmet_pt'; setLog = True; finalcuts = False;channel = "VBF"
#plot_nice1D(channel,var, bin, low, high, yaxis, xaxis , save, setLog, finalcuts)

## var = 'MinMET'; bin = 60; low = 0; high = 300; xaxis = "Min ME_{T} [GeV]"; yaxis = 'Events / 5 GeV'; save = 'minmet_pt'; setLog = True; finalcuts = False;channel = "VBF"
## plot_nice1D(channel,var, bin, low, high, yaxis, xaxis , save, setLog, finalcuts)

## var = 'RecoMET'; bin = 60; low = 0; high = 300; xaxis = "Reco ME_{T} [GeV]"; yaxis = 'Events / 5 GeV'; save = 'recomet_pt'; setLog = True; finalcuts = False;channel = "VBF"
## plot_nice1D(channel,var, bin, low, high, yaxis, xaxis , save, setLog, finalcuts)

#var = 'TMath::Abs(log10(p_value))'; bin = 40; low = 0; high = 40; xaxis = "log(p_{value})"; yaxis = 'Events'; save = 'log_pvalue'; setLog = True; finalcuts = False; channel = "VBF"
#plot_nice1D(channel,var, bin, low, high, yaxis, xaxis , save, setLog, finalcuts)
 
## var = 'p_value'; bin = 100; low = 0; high = 1; xaxis = "p_{value}"; yaxis = 'Events'; save = 'pvalue'; setLog = True; finalcuts = False;channel = "VBF"
## plot_nice1D(channel,var, bin, low, high, yaxis, xaxis , save, setLog, finalcuts)

## var = 'pfMet_Significance'; bin = 250; low = 0; high = 500; xaxis = "PF ME_{T} Significance"; yaxis = 'Events'; save = 'pfmet_significance'; setLog = True; finalcuts = False;channel = "VBF"
## plot_nice1D(channel,var, bin, low, high, yaxis, xaxis , save, setLog, finalcuts)

## var = 'TMath::Abs(dphi_pfmetg)'; bin = 100 ; low = 0; high = 4; xaxis = "#Delta #phi(PFMET,#gamma)"; yaxis = 'Events'; save = 'dphi_pfmetg'; setLog = True; finalcuts = False;channel = "VBF"
## plot_nice1D(channel,var, bin, low, high, yaxis, xaxis , save, setLog, finalcuts)

## var = 'mvaMet.Mod()'; bin = 60; low = 0; high = 300; xaxis = "MVA ME_{T} [GeV]"; yaxis = 'Events / 5 GeV'; save = 'mvamet_pt'; setLog = True; finalcuts = False;channel = "VBF"
## plot_nice1D(channel,var, bin, low, high, yaxis, xaxis , save, setLog, finalcuts)

## ## ## var = 'pctMet.Mod()'; bin = 500; low = 0; high = 1000; xaxis = "Photon Corrected Track ME_{T} [GeV]"; yaxis = 'Events / 2 GeV'; save = 'pctmet_pt'; setLog = True; finalcuts = False;channel = "VBF"
## ## ## plot_nice1D(channel,var, bin, low, high, yaxis, xaxis , save, setLog, finalcuts)
