function run_all()

CORA_path='/home/utopia/Desktop/CORA/CORA_2016/'; % put the correct path to CORA

disp('Brusselator start'); 
cd Brusselator/
Brusselator_reach_set(CORA_path)
disp('Brusselator end. Press a key to continue'); 
pause

disp('Buckling start');
cd ../BucklingColumn/
BucklingColumn_reach_set(CORA_path)
disp('Buckling end. Press a key to continue'); 
pause

disp('JetEngine start'); 
cd ../JetEngine/
jetEngine_reach_set(CORA_path)
disp('JetEngine end. Press a key to continue'); 
pause

disp('VanderPol start'); 
cd ../VanderPol/
vanderPol_reach_set(CORA_path)
disp('VanderPol end. Press a key to continue'); 
pause


disp('RobotArm start'); 
cd ../RobotArm/
robotArm_reach_set(CORA_path)
disp('RobotArm end. Press a key to continue'); 
pause

disp('Enzyme start');
cd ../Enzyme_RN/
Enzyme_RN_reach_set(CORA_path)
disp('Enzyme end. Press a key to continue'); 
pause

disp('Oscilator'); 
cd ../GeneticOscilator/
GeneticOscilator_reach_set(CORA_path)
disp('Oscilator end. Press a key to continue'); 
pause

%disp('Aging start');
%cd ../Aging/
%Aging_reach_set(CORA_path)
%disp('Aging end. Press a key to continue'); 
%pause

disp('Helicopter'); 
cd ../Helicopter/
helicopter_reach_set(CORA_path)
disp('Helicopter end. Press a key to continue'); 
pause

disp('Binding(2) start'); 
cd ../replicatedBindingSite2Asymm/
replicatedBindingSite2Asymm_reach_set(CORA_path)
disp('Binding(2) end. Press a key to continue'); 
pause

disp('Binding(3) start'); 
cd ../replicatedBindingSite3Asymm/
replicatedBindingSite3Asymm_reach_set(CORA_path)
disp('Binding(3) end. Press a key to continue'); 
pause

disp('Binding(4) start');
cd ../replicatedBindingSite4Asymm/
replicatedBindingSite4Asymm_reach_set(CORA_path)
disp('Binding(4) end. Press a key to continue'); 
pause

%disp('Binding(5) start');
%cd ../replicatedBindingSite5Asymm/
%replicatedBindingSite5Asymm_reach_set(CORA_path)
%disp('Binding(5) end. Press a key to continue'); 
%pause

%disp('Binding(6) start'); 
%cd ../replicatedBindingSite6Asymm/
%replicatedBindingSite6Asymm_reach_set(CORA_path)
%disp('Binding(6) end. Press a key to continue'); 
%pause

%disp('Binding(7) start');
%cd ../replicatedBindingSite7Asymm/
%replicatedBindingSite7Asymm_reach_set(CORA_path)
%disp('Binding(7) end. Press a key to continue'); 
%pause
exit;
end
