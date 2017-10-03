#!/bin/bash 

PATH=$PATH:/usr/local/MATLAB/R2016b/bin # put the correct path to Matlab binaries

echo "Brusselator start"
cd Brusselator/
matlab -nodesktop -r Brusselator_Pontryagin
./brusselator_VNODELP
read -n1 -r -p "Brusselator end. Press any key to continue" key

echo "Buckling start"
cd ../BucklingColumn/
matlab -nodesktop -r Buckling_Pontryagin
./buckling_VNODELP
read -n1 -r -p "Buckling end. Press any key to continue" key

echo "JetEngine start"
cd ../JetEngine/
matlab -nodesktop -r jetEngine_Pontryagin
./jetengine_VNODELP
read -n1 -r -p "JetEngine end. Press any key to continue" key

echo "VanderPol start"
cd ../VanderPol/
matlab -nodesktop -r vanderPol_Pontryagin
./vanderPol_VNODELP
read -n1 -r -p "VanderPol end. Press any key to continue" key

echo "RobotArm start"
cd ../RobotArm/
matlab -nodesktop -r robotArm_Pontryagin
./robotArm_VNODELP
read -n1 -r -p "RobotArm end. Press any key to continue" key

echo "Enzyme start"
cd ../Enzyme_RN/
matlab -nodesktop -r Enzyme_Pontryagin
./enzyme_VNODELP
read -n1 -r -p "Enzyme end. Press any key to continue" key

echo "Oscilator start"
cd ../GeneticOscilator/
matlab -nodesktop -r Oscilator_Pontryagin
./oscillator_VNODELP
read -n1 -r -p "Oscilator end. Press any key to continue" key

echo "Aging start..."
cd ../Aging/
matlab -nodesktop -r Aging_Pontryagin
./aging_VNODELP
read -n1 -r -p "Aging end. Press any key to continue" key

echo "Helicopter start"
cd ../Helicopter/
matlab -nodesktop -r helicopter_Pontryagin
./helicopter_VNODELP
read -n1 -r -p "Helicopter end. Press any key to continue" key

echo "Binding (2) start"
cd ../replicatedBindingSite2Asymm/
matlab -nodesktop -r replicatedBindingSite2Asym_Pontryagin
./replicatedBindingSite2Asym_VNODELP
read -n1 -r -p "Binding(2) end. Press any key to continue" key

echo "Binding (3) start"
cd ../replicatedBindingSite3Asymm/
matlab -nodesktop -r replicatedBindingSite3Asymm_Pontryagin
./replicatedBindingSite3Asymm_VNODELP
read -n1 -r -p "Binding(3) end. Press any key to continue" key

echo "Binding (4) start"
cd ../replicatedBindingSite4Asymm/
matlab -nodesktop -r replicatedBindingSite4Asymm_Pontryagin
./replicatedBindingSite4Asymm_VNODELP
read -n1 -r -p "Binding(4) end. Press any key to continue" key

echo "Binding (5) start"
cd ../replicatedBindingSite5Asymm/
matlab -nodesktop -r replicatedBindingSite5Asymm_Pontryagin
./replicatedBindingSite5Asymm_VNODELP
read -n1 -r -p "Binding(5) end. Press any key to continue" key

echo "Binding (6) start"
cd ../replicatedBindingSite6Asymm/
matlab -nodesktop -r replicatedBindingSite6Asymm_Pontryagin
./replicatedBindingSite6Asymm_VNODELP
read -n1 -r -p "Binding(6) end. Press any key to continue" key

echo "Binding (7)"
cd ../replicatedBindingSite7Asymm/
matlab -nodesktop -r replicatedBindingSite7Asymm_Pontryagin
./replicatedBindingSite7Asymm_VNODELP
read -n1 -r -p "Binding(7) end. Press any key to continue" key

