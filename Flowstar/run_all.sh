#!/bin/bash 

flowstar_path=~/Desktop/flowstar/flowstar-2.0.0

echo "Brusselator start"
cd Brusselator/
./run.sh $flowstar_path
read -n1 -r -p "Brusselator end. Press any key to continue" key

echo "Buckling start"
cd ../BuckingColumn/
./run.sh $flowstar_path
read -n1 -r -p "Buckling end. Press any key to continue" key

echo "JetEngine start"
cd ../JetEngine/
./run.sh $flowstar_path
read -n1 -r -p "JetEngine end. Press any key to continue" key

echo "VanderPol start"
cd ../VanderPol/
./run.sh $flowstar_path
read -n1 -r -p "VanderPol end. Press any key to continue" key

echo "RobotArm start"
cd ../RobotArm/
./run.sh $flowstar_path
read -n1 -r -p "RobotArm end. Press any key to continue" key

echo "Enzyme start"
cd ../Enzyme_RN/
./run.sh $flowstar_path
read -n1 -r -p "Enzyme end. Press any key to continue" key

echo "Oscilator start"
cd ../GeneticOscilator/
./run.sh $flowstar_path
read -n1 -r -p "Oscilator end. Press any key to continue" key

echo "Aging start"
cd ../Aging/
./run.sh $flowstar_path
read -n1 -r -p "Aging end. Press any key to continue" key

echo "Helicopter start"
cd ../Helicopter/
./run.sh $flowstar_path
read -n1 -r -p "Helicopter end. Press any key to continue" key

echo "Binding (2) start"
cd ../replicatedBindingSite2Asymm/
./run.sh $flowstar_path
read -n1 -r -p "Binding(2) end. Press any key to continue" key

echo "Binding (3) start"
cd ../replicatedBindingSite3Asymm/
./run.sh $flowstar_path
read -n1 -r -p "Binding(3) end. Press any key to continue" key

echo "Binding (4) start"
cd ../replicatedBindingSite4Asymm/
./run.sh $flowstar_path
read -n1 -r -p "Binding(4) end. Press any key to continue" key

echo "Binding (5) start"
cd ../replicatedBindingSite5Asymm/
./run.sh $flowstar_path
read -n1 -r -p "Binding(5) end. Press any key to continue" key

echo "Binding (6) start"
cd ../replicatedBindingSite6Asymm/
./run.sh $flowstar_path
read -n1 -r -p "Binding(6) end. Press any key to continue" key

echo "Binding (7)"
cd ../replicatedBindingSite7Asymm/
./run.sh $flowstar_path
read -n1 -r -p "Binding(7) end. Press any key to continue" key

