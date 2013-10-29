from ROOT import TFile

lumi = 1.0

######################################################

RootFiles = {}
Trees = {}

outdir = "/eos/uscms/store/user/zdemirag/monophoton_samples_pu_added/higgsHistograms_"
#outdir = "/afs/cern.ch/work/z/zdemirag/work/HtoZGamma/CMSSW_5_3_8_patch1/src/files/files_cuts/higgsHistograms_"

#RootFiles['Data'] = TFile(outdir+"Data.root")
#Trees['Data']  = RootFiles['Data'].Get("tree")

Samples = ['DD_Data_GGF','Data_GGF','Data_VBF_2012C','Signal_VBF','Signal_GluGlu','G_Pt-0to15','G_Pt-15to30','G_Pt-30to50','G_Pt-50to80','G_Pt-80to120','G_Pt-120to170','G_Pt-170to300', 'G_Pt-300to470', 'G_Pt-470to800', 'G_Pt-800to1400', 'G_Pt-1400to1800','G_Pt-1800', 'WGamma', 'WJets','DiPhoton', 'W2lnuEl', 'W2lnuTau' , 'W2lnuMu', 'QCD_20to30', 'QCD_30to80' , 'QCD_80to170' , 'QCD_170to250', 'QCD_250to350', 'QCD_350']

for bg in Samples:
        RootFiles[bg] = TFile(outdir+bg+".root")
        Trees[bg]     = RootFiles[bg].Get("Analyzer/AnalyzerTree")


######################################################

Nevents = {}

Nevents['Data_VBF_2012C']            = 1.0
Nevents['Data_GGF']            = 1.0
Nevents['DD_Data_GGF']            = 1.0

Nevents['Signal_VBF']      = 98000.0
Nevents['Signal_GluGlu']   = 98000.0

Nevents['WGamma']          = 5000000.0

Nevents['G_Pt-0to15']      = 2000488.0
Nevents['G_Pt-15to30']     = 1970745.0
Nevents['G_Pt-30to50']     = 1993325.0
Nevents['G_Pt-50to80']     = 1995062.0
Nevents['G_Pt-80to120']    = 1992627.0
Nevents['G_Pt-120to170']   = 2000043.0
Nevents['G_Pt-170to300']   = 2000069.0
Nevents['G_Pt-300to470']   = 2000130.0
Nevents['G_Pt-470to800']   = 1975231.0
Nevents['G_Pt-800to1400']  = 1973504.0
Nevents['G_Pt-1400to1800'] = 1984890.0
Nevents['G_Pt-1800']       = 1939122.0

Nevents['WJets']        = 18393090.0
Nevents['DiPhoton']     = 1156284.0
Nevents['W2lnuEl']      = 4883504.0
Nevents['W2lnuTau']     = 5000722.0
Nevents['W2lnuMu']      = 4769214.0
Nevents['QCD_20to30']   = 35040638.0
Nevents['QCD_30to80']   = 33088822.0

#forgot to run on a file
Nevents['QCD_80to170']  = 22639900#34542672.0

# a file is missing fix the # of events
Nevents['QCD_170to250'] = 31646986.0

Nevents['QCD_250to350'] = 42292370
Nevents['QCD_350'] = 34080630


######################################################
xsec = {}

xsec['Data_VBF_2012C']            = 1.0
xsec['Data_GGF']            = 1.0
xsec['DD_Data_GGF']            = 1.0


#Glu : 19.27 pb * BR (1.55 E-03) * nunu (~%20)
xsec['Signal_GluGlu']   = 5.9737E-03
#VBF : 1.578 pb  * BR (1.55 E-03) * nunu (~%20)
xsec['Signal_VBF']      = 0.489E-03

xsec['WGamma']          =  461.6 

xsec['G_Pt-0to15']      =  9.0601456E7 
xsec['G_Pt-15to30']     =  200061.7 
xsec['G_Pt-30to50']     =  19931.62 
xsec['G_Pt-50to80']     =  3322.309 
xsec['G_Pt-80to120']    =  558.2865 
xsec['G_Pt-120to170']   =  108.0068 
xsec['G_Pt-170to300']   =  30.12207 
xsec['G_Pt-300to470']   =  2.138632 
xsec['G_Pt-470to800']   =  0.2119244 
xsec['G_Pt-800to1400']  =  0.007077847 
xsec['G_Pt-1400to1800'] =  4.510327E-5 
xsec['G_Pt-1800']       =  1.867141E-6 

xsec['WJets']        = 30400.0
xsec['DiPhoton']     = 1.0
xsec['W2lnuEl']      =  9170.0 
xsec['W2lnuTau']     =  9170.0 
xsec['W2lnuMu']      =  9170.0

# 2.886E8 *  0.0101 
xsec['QCD_20to30']   = 2.91486000000000000e+06
#  7.433E7 *  0.0621 
xsec['QCD_30to80']   = 4.61589300000000000e+06
# 1191000.0  *  0.1539 
xsec['QCD_80to170']  =  1.83294900000000023e+05
# 30990.0 *  0.148 
xsec['QCD_170to250'] =  4.58651999999999953e+03
#4250.0* 0.131
xsec['QCD_250to350'] = 556.75
#810.0 *0.11
xsec['QCD_350'] =  89.1
