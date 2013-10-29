#!/bin/tcsh
setenv pwd $PWD
echo ${pwd}

setenv SOURCE ${1}
echo ${SOURCE}

cat>Job_${1}.csh<<EOF
#!/bin/tcsh
source /uscmst1/prod/sw/cms/setup/cshrc prod
setenv SCRAM_ARCH slc5_amd64_gcc462 

cd /uscms_data/d3/zdemirag/HZg_Ntuples/analyzer/CMSSW_5_3_8_patch1/src/Analyzer_v1/
cmsenv
cd ${pwd}
SSC
./simpleRunner.csh ${1}
EOF


sed -e 's|SSC|cd ${_CONDOR_SCRATCH_DIR} |'   ${pwd}/Job_${1}.csh > ${pwd}/Job_${1}_tmp.csh
mv ${pwd}/Job_${1}_tmp.csh ${pwd}/Job_${1}.csh

chmod 775 ${pwd}/Job_${1}.csh



cat>condor_${1}<<EOF
universe = vanilla
Executable = Job_${1}.csh
Requirements = Memory >= 199 &&OpSys == "LINUX"&& (Arch != "DUMMY" )&& Disk > 1000000
Should_Transfer_Files = YES
WhenToTransferOutput = ON_EXIT
transfer_input_files = ${pwd}/simpleRunner.csh, ${pwd}/sourceFiles/${SOURCE}.txt, ${pwd}/hzg_selector_Template.C, ${pwd}/hzg_selector.h, ${pwd}/plugins.tar.gz, ${pwd}/src.tar.gz, ${pwd}/PhysicsTools.tar.gz
notify_user = error
SSC 
Error
Log 
Queue 1
EOF

sed -e 's|SSC| Output = CondorJobs/$(Cluster)_$(Process).stdout|'   ${pwd}/condor_${1} > ${pwd}/condor_${1}_tmp
mv ${pwd}/condor_${1}_tmp ${pwd}/condor_${1}
sed -e 's|Error| Error = CondorJobs/$(Cluster)_$(Process).stderr|'  ${pwd}/condor_${1} > ${pwd}/condor_${1}_tmp
mv ${pwd}/condor_${1}_tmp ${pwd}/condor_${1}
sed -e 's|Log| Log = CondorJobs/$(Cluster)_$(Process).log|'   ${pwd}/condor_${1} > ${pwd}/condor_${1}_tmp
mv ${pwd}/condor_${1}_tmp ${pwd}/condor_${1}

condor_submit condor_${1}

#mv condor_${1} CondorJobs/condor_${1}
#mv Job_${1}.csh CondorJobs/Job_${1}.csh
