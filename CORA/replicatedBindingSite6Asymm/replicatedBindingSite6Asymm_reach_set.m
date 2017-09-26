
function replicatedBindingSite6Asymm_reach_set()

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Reachability analysis for systems with uncertain parameters using CORA
%
% Modified from the example example_nonlinear_reach_01_tank.m provided by CORA
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

 CORA_path='../../CORA_2016/';
 addpath(genpath(CORA_path));

 x0_= [ 0.0114 0.0064 0.0082 0.0201 0.0154 0.0115 0.0271 0.0191 0.0179 0.0299 0.0093 0.0247 0.0246 0.0124 0.0185 0.0025 0.0018 0.0042 0.0185 0.0153 4.0E-4 0.011 0.0053 0.0259 0.0101 0.0172 0.0054 0.0196 0.0086 0.0213 0.0225 0.0244 0.0147 0.0027 0.0075 0.0298 0.005 0.0269 0.0175 0.0325 0.0025 0.0144 0.0035 0.0314 2.0E-4 0.0253 0.0266 0.0283 0.0028 0.013 0.0085 0.0261 0.0141 0.0297 0.0059 0.0086 0.0047 0.0044 0.0283 0.0189 0.0179 0.0047 0.0266 0.0174 0.0115 ]'; 
 T = 0.2;
 theta_min=[ 9.5 9.0 0.05 ];
 theta_max=[ 10.0 11.0 0.2 ];
 alpha=[0 1.0 0 0 0 ];

 tic
 dim=size(x0_,1);

%set options --------------------------------------------------------------
options.tStart=0; %start time
options.tFinal=T; %final time
options.x0=x0_;
options.R0=zonotope([options.x0,0.0*eye(dim)]); %initial state for reachability analysis

options.timeStep=0.01; %time step size for reachable set computation
options.taylorTerms=20; %number of taylor terms for reachable sets

options.zonotopeOrder=80; %zonotope order
options.intermediateOrder=30;
options.reductionTechnique='girard';
options.errorOrder=4;
options.polytopeOrder=5; %polytope order
options.reductionInterval=1e3;
options.maxError = 1e1*ones(dim,1);

options.plotType='frame';
options.projectedDimensions=[1 2];

options.originContained = 0;
options.advancedLinErrorComp = 1;
options.tensorOrder = 3;

options.path = [coraroot '/contDynamics/stateSpaceModels'];
%--------------------------------------------------------------------------

v1=zeros(size(theta_min,2),1);
v2=zeros(size(theta_min,2),1);
for i=1:size(theta_min,2)
    v1(i)=0.5*(theta_max(i)+theta_min(i));
    v2(i)=0.5*(theta_max(i)-theta_min(i));
end

options.uTrans = v1; % center of uncertain inputs. 
options.U = zonotope([zeros(size(theta_min,2),1),diag(v2)]); % input for reachability analysis

% specify continuous dynamics-----------------------------------------------

tank = nonlinearSys(dim,size(theta_min,2),@ode,options); %initialize tank system
%--------------------------------------------------------------------------


%compute reachable set using zonotopes

Rcont = reach(tank, options);
tComp = toc;
disp(['computation time of reachable set: ',num2str(tComp)]);

 Z_ = Rcont{length(Rcont)}{1};
 Z = project(Z_,[1 2]);
 p = polygon(Z); 
 res = p(2,:);
 
 disp(['The output interval is [',num2str(min(res)),', ',num2str(max(res)),']']);

 rmpath(genpath('../../../CORA_2016/'));




end


function dy =  ode(t,y,v)

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Modification of the ODE system replicatedBindingSite2Asymm
% Used by ODE solvers in CORA 
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% 

	% However, theta is a vector and its value in t may not be defined.
	% Hence, we set each uncertain parameter as the nearest value of theta(t).
	kBind1 = v(1); 
	kUnbind1 = v(3); 
	kBind2 = v(2); 
	kUnbind2 = 0.1;
	kBind3 = 9.99995;
	kUnbind3 = 0.1;
	kBind4 = 10.0;
	kUnbind4 = 0.1;
	kBind5 = 10.00005;
	kUnbind5 = 0.1;
	kBind6 = 10.0001;
	kUnbind6 = 0.1;

	dy(1,1) = (-kBind1)*y(1)*y(2)+(-kBind2)*y(1)*y(2)+(-kBind3)*y(1)*y(2)+(-kBind4)*y(1)*y(2)+(-kBind5)*y(1)*y(2)+(-kBind6)*y(1)*y(2)+kUnbind1*y(3)+kUnbind2*y(4)+kUnbind3*y(5)+kUnbind4*y(6)+kUnbind5*y(7)+kUnbind6*y(8);
	dy(2,1) = (-kBind1)*y(1)*y(2)+(-kBind2)*y(1)*y(2)+(-kBind3)*y(1)*y(2)+(-kBind4)*y(1)*y(2)+(-kBind5)*y(1)*y(2)+(-kBind6)*y(1)*y(2)+(-kBind1)*y(2)*y(4)+(-kBind1)*y(2)*y(5)+(-kBind1)*y(2)*y(6)+(-kBind1)*y(2)*y(7)+(-kBind1)*y(2)*y(8)+kUnbind1*y(3)+(-kBind2)*y(2)*y(3)+(-kBind2)*y(2)*y(5)+(-kBind2)*y(2)*y(6)+(-kBind2)*y(2)*y(7)+(-kBind2)*y(2)*y(8)+kUnbind2*y(4)+(-kBind3)*y(2)*y(3)+(-kBind3)*y(2)*y(4)+(-kBind3)*y(2)*y(6)+(-kBind3)*y(2)*y(7)+(-kBind3)*y(2)*y(8)+kUnbind3*y(5)+(-kBind4)*y(2)*y(3)+(-kBind4)*y(2)*y(4)+(-kBind4)*y(2)*y(5)+(-kBind4)*y(2)*y(7)+(-kBind4)*y(2)*y(8)+kUnbind4*y(6)+(-kBind5)*y(2)*y(3)+(-kBind5)*y(2)*y(4)+(-kBind5)*y(2)*y(5)+(-kBind5)*y(2)*y(6)+(-kBind5)*y(2)*y(8)+kUnbind5*y(7)+(-kBind6)*y(2)*y(3)+(-kBind6)*y(2)*y(4)+(-kBind6)*y(2)*y(5)+(-kBind6)*y(2)*y(6)+(-kBind6)*y(2)*y(7)+kUnbind6*y(8)+(-kBind1)*y(2)*y(14)+(-kBind1)*y(2)*y(15)+(-kBind1)*y(2)*y(16)+(-kBind1)*y(2)*y(17)+(-kBind1)*y(2)*y(18)+(-kBind1)*y(2)*y(19)+(-kBind1)*y(2)*y(20)+(-kBind1)*y(2)*y(21)+(-kBind1)*y(2)*y(22)+(-kBind1)*y(2)*y(23)+kUnbind1*y(9)+kUnbind1*y(10)+kUnbind1*y(11)+kUnbind1*y(12)+kUnbind1*y(13)+(-kBind2)*y(2)*y(10)+(-kBind2)*y(2)*y(11)+(-kBind2)*y(2)*y(12)+(-kBind2)*y(2)*y(13)+(-kBind2)*y(2)*y(18)+(-kBind2)*y(2)*y(19)+(-kBind2)*y(2)*y(20)+(-kBind2)*y(2)*y(21)+(-kBind2)*y(2)*y(22)+(-kBind2)*y(2)*y(23)+kUnbind2*y(9)+kUnbind2*y(14)+kUnbind2*y(15)+kUnbind2*y(16)+kUnbind2*y(17)+(-kBind3)*y(2)*y(9)+(-kBind3)*y(2)*y(11)+(-kBind3)*y(2)*y(12)+(-kBind3)*y(2)*y(13)+(-kBind3)*y(2)*y(15)+(-kBind3)*y(2)*y(16)+(-kBind3)*y(2)*y(17)+(-kBind3)*y(2)*y(21)+(-kBind3)*y(2)*y(22)+(-kBind3)*y(2)*y(23)+kUnbind3*y(10)+kUnbind3*y(14)+kUnbind3*y(18)+kUnbind3*y(19)+kUnbind3*y(20)+(-kBind4)*y(2)*y(9)+(-kBind4)*y(2)*y(10)+(-kBind4)*y(2)*y(12)+(-kBind4)*y(2)*y(13)+(-kBind4)*y(2)*y(14)+(-kBind4)*y(2)*y(16)+(-kBind4)*y(2)*y(17)+(-kBind4)*y(2)*y(19)+(-kBind4)*y(2)*y(20)+(-kBind4)*y(2)*y(23)+kUnbind4*y(11)+kUnbind4*y(15)+kUnbind4*y(18)+kUnbind4*y(21)+kUnbind4*y(22)+(-kBind5)*y(2)*y(9)+(-kBind5)*y(2)*y(10)+(-kBind5)*y(2)*y(11)+(-kBind5)*y(2)*y(13)+(-kBind5)*y(2)*y(14)+(-kBind5)*y(2)*y(15)+(-kBind5)*y(2)*y(17)+(-kBind5)*y(2)*y(18)+(-kBind5)*y(2)*y(20)+(-kBind5)*y(2)*y(22)+kUnbind5*y(12)+kUnbind5*y(16)+kUnbind5*y(19)+kUnbind5*y(21)+kUnbind5*y(23)+(-kBind6)*y(2)*y(9)+(-kBind6)*y(2)*y(10)+(-kBind6)*y(2)*y(11)+(-kBind6)*y(2)*y(12)+(-kBind6)*y(2)*y(14)+(-kBind6)*y(2)*y(15)+(-kBind6)*y(2)*y(16)+(-kBind6)*y(2)*y(18)+(-kBind6)*y(2)*y(19)+(-kBind6)*y(2)*y(21)+kUnbind6*y(13)+kUnbind6*y(17)+kUnbind6*y(20)+kUnbind6*y(22)+kUnbind6*y(23)+(-kBind1)*y(2)*y(34)+(-kBind1)*y(2)*y(35)+(-kBind1)*y(2)*y(36)+(-kBind1)*y(2)*y(37)+(-kBind1)*y(2)*y(38)+(-kBind1)*y(2)*y(39)+(-kBind1)*y(2)*y(40)+(-kBind1)*y(2)*y(41)+(-kBind1)*y(2)*y(42)+(-kBind1)*y(2)*y(43)+kUnbind1*y(24)+kUnbind1*y(25)+kUnbind1*y(26)+kUnbind1*y(27)+kUnbind1*y(28)+kUnbind1*y(29)+kUnbind1*y(30)+kUnbind1*y(31)+kUnbind1*y(32)+kUnbind1*y(33)+(-kBind2)*y(2)*y(28)+(-kBind2)*y(2)*y(29)+(-kBind2)*y(2)*y(30)+(-kBind2)*y(2)*y(31)+(-kBind2)*y(2)*y(32)+(-kBind2)*y(2)*y(33)+(-kBind2)*y(2)*y(40)+(-kBind2)*y(2)*y(41)+(-kBind2)*y(2)*y(42)+(-kBind2)*y(2)*y(43)+kUnbind2*y(24)+kUnbind2*y(25)+kUnbind2*y(26)+kUnbind2*y(27)+kUnbind2*y(34)+kUnbind2*y(35)+kUnbind2*y(36)+kUnbind2*y(37)+kUnbind2*y(38)+kUnbind2*y(39)+(-kBind3)*y(2)*y(25)+(-kBind3)*y(2)*y(26)+(-kBind3)*y(2)*y(27)+(-kBind3)*y(2)*y(31)+(-kBind3)*y(2)*y(32)+(-kBind3)*y(2)*y(33)+(-kBind3)*y(2)*y(37)+(-kBind3)*y(2)*y(38)+(-kBind3)*y(2)*y(39)+(-kBind3)*y(2)*y(43)+kUnbind3*y(24)+kUnbind3*y(28)+kUnbind3*y(29)+kUnbind3*y(30)+kUnbind3*y(34)+kUnbind3*y(35)+kUnbind3*y(36)+kUnbind3*y(40)+kUnbind3*y(41)+kUnbind3*y(42)+(-kBind4)*y(2)*y(24)+(-kBind4)*y(2)*y(26)+(-kBind4)*y(2)*y(27)+(-kBind4)*y(2)*y(29)+(-kBind4)*y(2)*y(30)+(-kBind4)*y(2)*y(33)+(-kBind4)*y(2)*y(35)+(-kBind4)*y(2)*y(36)+(-kBind4)*y(2)*y(39)+(-kBind4)*y(2)*y(42)+kUnbind4*y(25)+kUnbind4*y(28)+kUnbind4*y(31)+kUnbind4*y(32)+kUnbind4*y(34)+kUnbind4*y(37)+kUnbind4*y(38)+kUnbind4*y(40)+kUnbind4*y(41)+kUnbind4*y(43)+(-kBind5)*y(2)*y(24)+(-kBind5)*y(2)*y(25)+(-kBind5)*y(2)*y(27)+(-kBind5)*y(2)*y(28)+(-kBind5)*y(2)*y(30)+(-kBind5)*y(2)*y(32)+(-kBind5)*y(2)*y(34)+(-kBind5)*y(2)*y(36)+(-kBind5)*y(2)*y(38)+(-kBind5)*y(2)*y(41)+kUnbind5*y(26)+kUnbind5*y(29)+kUnbind5*y(31)+kUnbind5*y(33)+kUnbind5*y(35)+kUnbind5*y(37)+kUnbind5*y(39)+kUnbind5*y(40)+kUnbind5*y(42)+kUnbind5*y(43)+(-kBind6)*y(2)*y(24)+(-kBind6)*y(2)*y(25)+(-kBind6)*y(2)*y(26)+(-kBind6)*y(2)*y(28)+(-kBind6)*y(2)*y(29)+(-kBind6)*y(2)*y(31)+(-kBind6)*y(2)*y(34)+(-kBind6)*y(2)*y(35)+(-kBind6)*y(2)*y(37)+(-kBind6)*y(2)*y(40)+kUnbind6*y(27)+kUnbind6*y(30)+kUnbind6*y(32)+kUnbind6*y(33)+kUnbind6*y(36)+kUnbind6*y(38)+kUnbind6*y(39)+kUnbind6*y(41)+kUnbind6*y(42)+kUnbind6*y(43)+(-kBind1)*y(2)*y(54)+(-kBind1)*y(2)*y(55)+(-kBind1)*y(2)*y(56)+(-kBind1)*y(2)*y(57)+(-kBind1)*y(2)*y(58)+kUnbind1*y(44)+kUnbind1*y(45)+kUnbind1*y(46)+kUnbind1*y(47)+kUnbind1*y(48)+kUnbind1*y(49)+kUnbind1*y(50)+kUnbind1*y(51)+kUnbind1*y(52)+kUnbind1*y(53)+(-kBind2)*y(2)*y(50)+(-kBind2)*y(2)*y(51)+(-kBind2)*y(2)*y(52)+(-kBind2)*y(2)*y(53)+(-kBind2)*y(2)*y(58)+kUnbind2*y(44)+kUnbind2*y(45)+kUnbind2*y(46)+kUnbind2*y(47)+kUnbind2*y(48)+kUnbind2*y(49)+kUnbind2*y(54)+kUnbind2*y(55)+kUnbind2*y(56)+kUnbind2*y(57)+(-kBind3)*y(2)*y(47)+(-kBind3)*y(2)*y(48)+(-kBind3)*y(2)*y(49)+(-kBind3)*y(2)*y(53)+(-kBind3)*y(2)*y(57)+kUnbind3*y(44)+kUnbind3*y(45)+kUnbind3*y(46)+kUnbind3*y(50)+kUnbind3*y(51)+kUnbind3*y(52)+kUnbind3*y(54)+kUnbind3*y(55)+kUnbind3*y(56)+kUnbind3*y(58)+(-kBind4)*y(2)*y(45)+(-kBind4)*y(2)*y(46)+(-kBind4)*y(2)*y(49)+(-kBind4)*y(2)*y(52)+(-kBind4)*y(2)*y(56)+kUnbind4*y(44)+kUnbind4*y(47)+kUnbind4*y(48)+kUnbind4*y(50)+kUnbind4*y(51)+kUnbind4*y(53)+kUnbind4*y(54)+kUnbind4*y(55)+kUnbind4*y(57)+kUnbind4*y(58)+(-kBind5)*y(2)*y(44)+(-kBind5)*y(2)*y(46)+(-kBind5)*y(2)*y(48)+(-kBind5)*y(2)*y(51)+(-kBind5)*y(2)*y(55)+kUnbind5*y(45)+kUnbind5*y(47)+kUnbind5*y(49)+kUnbind5*y(50)+kUnbind5*y(52)+kUnbind5*y(53)+kUnbind5*y(54)+kUnbind5*y(56)+kUnbind5*y(57)+kUnbind5*y(58)+(-kBind6)*y(2)*y(44)+(-kBind6)*y(2)*y(45)+(-kBind6)*y(2)*y(47)+(-kBind6)*y(2)*y(50)+(-kBind6)*y(2)*y(54)+kUnbind6*y(46)+kUnbind6*y(48)+kUnbind6*y(49)+kUnbind6*y(51)+kUnbind6*y(52)+kUnbind6*y(53)+kUnbind6*y(55)+kUnbind6*y(56)+kUnbind6*y(57)+kUnbind6*y(58)+(-kBind1)*y(2)*y(64)+kUnbind1*y(59)+kUnbind1*y(60)+kUnbind1*y(61)+kUnbind1*y(62)+kUnbind1*y(63)+(-kBind2)*y(2)*y(63)+kUnbind2*y(59)+kUnbind2*y(60)+kUnbind2*y(61)+kUnbind2*y(62)+kUnbind2*y(64)+(-kBind3)*y(2)*y(62)+kUnbind3*y(59)+kUnbind3*y(60)+kUnbind3*y(61)+kUnbind3*y(63)+kUnbind3*y(64)+(-kBind4)*y(2)*y(61)+kUnbind4*y(59)+kUnbind4*y(60)+kUnbind4*y(62)+kUnbind4*y(63)+kUnbind4*y(64)+(-kBind5)*y(2)*y(60)+kUnbind5*y(59)+kUnbind5*y(61)+kUnbind5*y(62)+kUnbind5*y(63)+kUnbind5*y(64)+(-kBind6)*y(2)*y(59)+kUnbind6*y(60)+kUnbind6*y(61)+kUnbind6*y(62)+kUnbind6*y(63)+kUnbind6*y(64)+kUnbind1*y(65)+kUnbind2*y(65)+kUnbind3*y(65)+kUnbind4*y(65)+kUnbind5*y(65)+kUnbind6*y(65);
	dy(3,1) = kBind1*y(1)*y(2)+(-kUnbind1)*y(3)+(-kBind2)*y(2)*y(3)+(-kBind3)*y(2)*y(3)+(-kBind4)*y(2)*y(3)+(-kBind5)*y(2)*y(3)+(-kBind6)*y(2)*y(3)+kUnbind2*y(9)+kUnbind3*y(10)+kUnbind4*y(11)+kUnbind5*y(12)+kUnbind6*y(13);
	dy(4,1) = kBind2*y(1)*y(2)+(-kBind1)*y(2)*y(4)+(-kUnbind2)*y(4)+(-kBind3)*y(2)*y(4)+(-kBind4)*y(2)*y(4)+(-kBind5)*y(2)*y(4)+(-kBind6)*y(2)*y(4)+kUnbind1*y(9)+kUnbind3*y(14)+kUnbind4*y(15)+kUnbind5*y(16)+kUnbind6*y(17);
	dy(5,1) = kBind3*y(1)*y(2)+(-kBind1)*y(2)*y(5)+(-kBind2)*y(2)*y(5)+(-kUnbind3)*y(5)+(-kBind4)*y(2)*y(5)+(-kBind5)*y(2)*y(5)+(-kBind6)*y(2)*y(5)+kUnbind1*y(10)+kUnbind2*y(14)+kUnbind4*y(18)+kUnbind5*y(19)+kUnbind6*y(20);
	dy(6,1) = kBind4*y(1)*y(2)+(-kBind1)*y(2)*y(6)+(-kBind2)*y(2)*y(6)+(-kBind3)*y(2)*y(6)+(-kUnbind4)*y(6)+(-kBind5)*y(2)*y(6)+(-kBind6)*y(2)*y(6)+kUnbind1*y(11)+kUnbind2*y(15)+kUnbind3*y(18)+kUnbind5*y(21)+kUnbind6*y(22);
	dy(7,1) = kBind5*y(1)*y(2)+(-kBind1)*y(2)*y(7)+(-kBind2)*y(2)*y(7)+(-kBind3)*y(2)*y(7)+(-kBind4)*y(2)*y(7)+(-kUnbind5)*y(7)+(-kBind6)*y(2)*y(7)+kUnbind1*y(12)+kUnbind2*y(16)+kUnbind3*y(19)+kUnbind4*y(21)+kUnbind6*y(23);
	dy(8,1) = kBind6*y(1)*y(2)+(-kBind1)*y(2)*y(8)+(-kBind2)*y(2)*y(8)+(-kBind3)*y(2)*y(8)+(-kBind4)*y(2)*y(8)+(-kBind5)*y(2)*y(8)+(-kUnbind6)*y(8)+kUnbind1*y(13)+kUnbind2*y(17)+kUnbind3*y(20)+kUnbind4*y(22)+kUnbind5*y(23);
	dy(9,1) = kBind1*y(2)*y(4)+kBind2*y(2)*y(3)+(-kUnbind1)*y(9)+(-kUnbind2)*y(9)+(-kBind3)*y(2)*y(9)+(-kBind4)*y(2)*y(9)+(-kBind5)*y(2)*y(9)+(-kBind6)*y(2)*y(9)+kUnbind3*y(24)+kUnbind4*y(25)+kUnbind5*y(26)+kUnbind6*y(27);
	dy(10,1) = kBind1*y(2)*y(5)+kBind3*y(2)*y(3)+(-kUnbind1)*y(10)+(-kBind2)*y(2)*y(10)+(-kUnbind3)*y(10)+(-kBind4)*y(2)*y(10)+(-kBind5)*y(2)*y(10)+(-kBind6)*y(2)*y(10)+kUnbind2*y(24)+kUnbind4*y(28)+kUnbind5*y(29)+kUnbind6*y(30);
	dy(11,1) = kBind1*y(2)*y(6)+kBind4*y(2)*y(3)+(-kUnbind1)*y(11)+(-kBind2)*y(2)*y(11)+(-kBind3)*y(2)*y(11)+(-kUnbind4)*y(11)+(-kBind5)*y(2)*y(11)+(-kBind6)*y(2)*y(11)+kUnbind2*y(25)+kUnbind3*y(28)+kUnbind5*y(31)+kUnbind6*y(32);
	dy(12,1) = kBind1*y(2)*y(7)+kBind5*y(2)*y(3)+(-kUnbind1)*y(12)+(-kBind2)*y(2)*y(12)+(-kBind3)*y(2)*y(12)+(-kBind4)*y(2)*y(12)+(-kUnbind5)*y(12)+(-kBind6)*y(2)*y(12)+kUnbind2*y(26)+kUnbind3*y(29)+kUnbind4*y(31)+kUnbind6*y(33);
	dy(13,1) = kBind1*y(2)*y(8)+kBind6*y(2)*y(3)+(-kUnbind1)*y(13)+(-kBind2)*y(2)*y(13)+(-kBind3)*y(2)*y(13)+(-kBind4)*y(2)*y(13)+(-kBind5)*y(2)*y(13)+(-kUnbind6)*y(13)+kUnbind2*y(27)+kUnbind3*y(30)+kUnbind4*y(32)+kUnbind5*y(33);
	dy(14,1) = kBind2*y(2)*y(5)+kBind3*y(2)*y(4)+(-kBind1)*y(2)*y(14)+(-kUnbind2)*y(14)+(-kUnbind3)*y(14)+(-kBind4)*y(2)*y(14)+(-kBind5)*y(2)*y(14)+(-kBind6)*y(2)*y(14)+kUnbind1*y(24)+kUnbind4*y(34)+kUnbind5*y(35)+kUnbind6*y(36);
	dy(15,1) = kBind2*y(2)*y(6)+kBind4*y(2)*y(4)+(-kBind1)*y(2)*y(15)+(-kUnbind2)*y(15)+(-kBind3)*y(2)*y(15)+(-kUnbind4)*y(15)+(-kBind5)*y(2)*y(15)+(-kBind6)*y(2)*y(15)+kUnbind1*y(25)+kUnbind3*y(34)+kUnbind5*y(37)+kUnbind6*y(38);
	dy(16,1) = kBind2*y(2)*y(7)+kBind5*y(2)*y(4)+(-kBind1)*y(2)*y(16)+(-kUnbind2)*y(16)+(-kBind3)*y(2)*y(16)+(-kBind4)*y(2)*y(16)+(-kUnbind5)*y(16)+(-kBind6)*y(2)*y(16)+kUnbind1*y(26)+kUnbind3*y(35)+kUnbind4*y(37)+kUnbind6*y(39);
	dy(17,1) = kBind2*y(2)*y(8)+kBind6*y(2)*y(4)+(-kBind1)*y(2)*y(17)+(-kUnbind2)*y(17)+(-kBind3)*y(2)*y(17)+(-kBind4)*y(2)*y(17)+(-kBind5)*y(2)*y(17)+(-kUnbind6)*y(17)+kUnbind1*y(27)+kUnbind3*y(36)+kUnbind4*y(38)+kUnbind5*y(39);
	dy(18,1) = kBind3*y(2)*y(6)+kBind4*y(2)*y(5)+(-kBind1)*y(2)*y(18)+(-kBind2)*y(2)*y(18)+(-kUnbind3)*y(18)+(-kUnbind4)*y(18)+(-kBind5)*y(2)*y(18)+(-kBind6)*y(2)*y(18)+kUnbind1*y(28)+kUnbind2*y(34)+kUnbind5*y(40)+kUnbind6*y(41);
	dy(19,1) = kBind3*y(2)*y(7)+kBind5*y(2)*y(5)+(-kBind1)*y(2)*y(19)+(-kBind2)*y(2)*y(19)+(-kUnbind3)*y(19)+(-kBind4)*y(2)*y(19)+(-kUnbind5)*y(19)+(-kBind6)*y(2)*y(19)+kUnbind1*y(29)+kUnbind2*y(35)+kUnbind4*y(40)+kUnbind6*y(42);
	dy(20,1) = kBind3*y(2)*y(8)+kBind6*y(2)*y(5)+(-kBind1)*y(2)*y(20)+(-kBind2)*y(2)*y(20)+(-kUnbind3)*y(20)+(-kBind4)*y(2)*y(20)+(-kBind5)*y(2)*y(20)+(-kUnbind6)*y(20)+kUnbind1*y(30)+kUnbind2*y(36)+kUnbind4*y(41)+kUnbind5*y(42);
	dy(21,1) = kBind4*y(2)*y(7)+kBind5*y(2)*y(6)+(-kBind1)*y(2)*y(21)+(-kBind2)*y(2)*y(21)+(-kBind3)*y(2)*y(21)+(-kUnbind4)*y(21)+(-kUnbind5)*y(21)+(-kBind6)*y(2)*y(21)+kUnbind1*y(31)+kUnbind2*y(37)+kUnbind3*y(40)+kUnbind6*y(43);
	dy(22,1) = kBind4*y(2)*y(8)+kBind6*y(2)*y(6)+(-kBind1)*y(2)*y(22)+(-kBind2)*y(2)*y(22)+(-kBind3)*y(2)*y(22)+(-kUnbind4)*y(22)+(-kBind5)*y(2)*y(22)+(-kUnbind6)*y(22)+kUnbind1*y(32)+kUnbind2*y(38)+kUnbind3*y(41)+kUnbind5*y(43);
	dy(23,1) = kBind5*y(2)*y(8)+kBind6*y(2)*y(7)+(-kBind1)*y(2)*y(23)+(-kBind2)*y(2)*y(23)+(-kBind3)*y(2)*y(23)+(-kBind4)*y(2)*y(23)+(-kUnbind5)*y(23)+(-kUnbind6)*y(23)+kUnbind1*y(33)+kUnbind2*y(39)+kUnbind3*y(42)+kUnbind4*y(43);
	dy(24,1) = kBind1*y(2)*y(14)+kBind2*y(2)*y(10)+kBind3*y(2)*y(9)+(-kUnbind1)*y(24)+(-kUnbind2)*y(24)+(-kUnbind3)*y(24)+(-kBind4)*y(2)*y(24)+(-kBind5)*y(2)*y(24)+(-kBind6)*y(2)*y(24)+kUnbind4*y(44)+kUnbind5*y(45)+kUnbind6*y(46);
	dy(25,1) = kBind1*y(2)*y(15)+kBind2*y(2)*y(11)+kBind4*y(2)*y(9)+(-kUnbind1)*y(25)+(-kUnbind2)*y(25)+(-kBind3)*y(2)*y(25)+(-kUnbind4)*y(25)+(-kBind5)*y(2)*y(25)+(-kBind6)*y(2)*y(25)+kUnbind3*y(44)+kUnbind5*y(47)+kUnbind6*y(48);
	dy(26,1) = kBind1*y(2)*y(16)+kBind2*y(2)*y(12)+kBind5*y(2)*y(9)+(-kUnbind1)*y(26)+(-kUnbind2)*y(26)+(-kBind3)*y(2)*y(26)+(-kBind4)*y(2)*y(26)+(-kUnbind5)*y(26)+(-kBind6)*y(2)*y(26)+kUnbind3*y(45)+kUnbind4*y(47)+kUnbind6*y(49);
	dy(27,1) = kBind1*y(2)*y(17)+kBind2*y(2)*y(13)+kBind6*y(2)*y(9)+(-kUnbind1)*y(27)+(-kUnbind2)*y(27)+(-kBind3)*y(2)*y(27)+(-kBind4)*y(2)*y(27)+(-kBind5)*y(2)*y(27)+(-kUnbind6)*y(27)+kUnbind3*y(46)+kUnbind4*y(48)+kUnbind5*y(49);
	dy(28,1) = kBind1*y(2)*y(18)+kBind3*y(2)*y(11)+kBind4*y(2)*y(10)+(-kUnbind1)*y(28)+(-kBind2)*y(2)*y(28)+(-kUnbind3)*y(28)+(-kUnbind4)*y(28)+(-kBind5)*y(2)*y(28)+(-kBind6)*y(2)*y(28)+kUnbind2*y(44)+kUnbind5*y(50)+kUnbind6*y(51);
	dy(29,1) = kBind1*y(2)*y(19)+kBind3*y(2)*y(12)+kBind5*y(2)*y(10)+(-kUnbind1)*y(29)+(-kBind2)*y(2)*y(29)+(-kUnbind3)*y(29)+(-kBind4)*y(2)*y(29)+(-kUnbind5)*y(29)+(-kBind6)*y(2)*y(29)+kUnbind2*y(45)+kUnbind4*y(50)+kUnbind6*y(52);
	dy(30,1) = kBind1*y(2)*y(20)+kBind3*y(2)*y(13)+kBind6*y(2)*y(10)+(-kUnbind1)*y(30)+(-kBind2)*y(2)*y(30)+(-kUnbind3)*y(30)+(-kBind4)*y(2)*y(30)+(-kBind5)*y(2)*y(30)+(-kUnbind6)*y(30)+kUnbind2*y(46)+kUnbind4*y(51)+kUnbind5*y(52);
	dy(31,1) = kBind1*y(2)*y(21)+kBind4*y(2)*y(12)+kBind5*y(2)*y(11)+(-kUnbind1)*y(31)+(-kBind2)*y(2)*y(31)+(-kBind3)*y(2)*y(31)+(-kUnbind4)*y(31)+(-kUnbind5)*y(31)+(-kBind6)*y(2)*y(31)+kUnbind2*y(47)+kUnbind3*y(50)+kUnbind6*y(53);
	dy(32,1) = kBind1*y(2)*y(22)+kBind4*y(2)*y(13)+kBind6*y(2)*y(11)+(-kUnbind1)*y(32)+(-kBind2)*y(2)*y(32)+(-kBind3)*y(2)*y(32)+(-kUnbind4)*y(32)+(-kBind5)*y(2)*y(32)+(-kUnbind6)*y(32)+kUnbind2*y(48)+kUnbind3*y(51)+kUnbind5*y(53);
	dy(33,1) = kBind1*y(2)*y(23)+kBind5*y(2)*y(13)+kBind6*y(2)*y(12)+(-kUnbind1)*y(33)+(-kBind2)*y(2)*y(33)+(-kBind3)*y(2)*y(33)+(-kBind4)*y(2)*y(33)+(-kUnbind5)*y(33)+(-kUnbind6)*y(33)+kUnbind2*y(49)+kUnbind3*y(52)+kUnbind4*y(53);
	dy(34,1) = kBind2*y(2)*y(18)+kBind3*y(2)*y(15)+kBind4*y(2)*y(14)+(-kBind1)*y(2)*y(34)+(-kUnbind2)*y(34)+(-kUnbind3)*y(34)+(-kUnbind4)*y(34)+(-kBind5)*y(2)*y(34)+(-kBind6)*y(2)*y(34)+kUnbind1*y(44)+kUnbind5*y(54)+kUnbind6*y(55);
	dy(35,1) = kBind2*y(2)*y(19)+kBind3*y(2)*y(16)+kBind5*y(2)*y(14)+(-kBind1)*y(2)*y(35)+(-kUnbind2)*y(35)+(-kUnbind3)*y(35)+(-kBind4)*y(2)*y(35)+(-kUnbind5)*y(35)+(-kBind6)*y(2)*y(35)+kUnbind1*y(45)+kUnbind4*y(54)+kUnbind6*y(56);
	dy(36,1) = kBind2*y(2)*y(20)+kBind3*y(2)*y(17)+kBind6*y(2)*y(14)+(-kBind1)*y(2)*y(36)+(-kUnbind2)*y(36)+(-kUnbind3)*y(36)+(-kBind4)*y(2)*y(36)+(-kBind5)*y(2)*y(36)+(-kUnbind6)*y(36)+kUnbind1*y(46)+kUnbind4*y(55)+kUnbind5*y(56);
	dy(37,1) = kBind2*y(2)*y(21)+kBind4*y(2)*y(16)+kBind5*y(2)*y(15)+(-kBind1)*y(2)*y(37)+(-kUnbind2)*y(37)+(-kBind3)*y(2)*y(37)+(-kUnbind4)*y(37)+(-kUnbind5)*y(37)+(-kBind6)*y(2)*y(37)+kUnbind1*y(47)+kUnbind3*y(54)+kUnbind6*y(57);
	dy(38,1) = kBind2*y(2)*y(22)+kBind4*y(2)*y(17)+kBind6*y(2)*y(15)+(-kBind1)*y(2)*y(38)+(-kUnbind2)*y(38)+(-kBind3)*y(2)*y(38)+(-kUnbind4)*y(38)+(-kBind5)*y(2)*y(38)+(-kUnbind6)*y(38)+kUnbind1*y(48)+kUnbind3*y(55)+kUnbind5*y(57);
	dy(39,1) = kBind2*y(2)*y(23)+kBind5*y(2)*y(17)+kBind6*y(2)*y(16)+(-kBind1)*y(2)*y(39)+(-kUnbind2)*y(39)+(-kBind3)*y(2)*y(39)+(-kBind4)*y(2)*y(39)+(-kUnbind5)*y(39)+(-kUnbind6)*y(39)+kUnbind1*y(49)+kUnbind3*y(56)+kUnbind4*y(57);
	dy(40,1) = kBind3*y(2)*y(21)+kBind4*y(2)*y(19)+kBind5*y(2)*y(18)+(-kBind1)*y(2)*y(40)+(-kBind2)*y(2)*y(40)+(-kUnbind3)*y(40)+(-kUnbind4)*y(40)+(-kUnbind5)*y(40)+(-kBind6)*y(2)*y(40)+kUnbind1*y(50)+kUnbind2*y(54)+kUnbind6*y(58);
	dy(41,1) = kBind3*y(2)*y(22)+kBind4*y(2)*y(20)+kBind6*y(2)*y(18)+(-kBind1)*y(2)*y(41)+(-kBind2)*y(2)*y(41)+(-kUnbind3)*y(41)+(-kUnbind4)*y(41)+(-kBind5)*y(2)*y(41)+(-kUnbind6)*y(41)+kUnbind1*y(51)+kUnbind2*y(55)+kUnbind5*y(58);
	dy(42,1) = kBind3*y(2)*y(23)+kBind5*y(2)*y(20)+kBind6*y(2)*y(19)+(-kBind1)*y(2)*y(42)+(-kBind2)*y(2)*y(42)+(-kUnbind3)*y(42)+(-kBind4)*y(2)*y(42)+(-kUnbind5)*y(42)+(-kUnbind6)*y(42)+kUnbind1*y(52)+kUnbind2*y(56)+kUnbind4*y(58);
	dy(43,1) = kBind4*y(2)*y(23)+kBind5*y(2)*y(22)+kBind6*y(2)*y(21)+(-kBind1)*y(2)*y(43)+(-kBind2)*y(2)*y(43)+(-kBind3)*y(2)*y(43)+(-kUnbind4)*y(43)+(-kUnbind5)*y(43)+(-kUnbind6)*y(43)+kUnbind1*y(53)+kUnbind2*y(57)+kUnbind3*y(58);
	dy(44,1) = kBind1*y(2)*y(34)+kBind2*y(2)*y(28)+kBind3*y(2)*y(25)+kBind4*y(2)*y(24)+(-kUnbind1)*y(44)+(-kUnbind2)*y(44)+(-kUnbind3)*y(44)+(-kUnbind4)*y(44)+(-kBind5)*y(2)*y(44)+(-kBind6)*y(2)*y(44)+kUnbind5*y(59)+kUnbind6*y(60);
	dy(45,1) = kBind1*y(2)*y(35)+kBind2*y(2)*y(29)+kBind3*y(2)*y(26)+kBind5*y(2)*y(24)+(-kUnbind1)*y(45)+(-kUnbind2)*y(45)+(-kUnbind3)*y(45)+(-kBind4)*y(2)*y(45)+(-kUnbind5)*y(45)+(-kBind6)*y(2)*y(45)+kUnbind4*y(59)+kUnbind6*y(61);
	dy(46,1) = kBind1*y(2)*y(36)+kBind2*y(2)*y(30)+kBind3*y(2)*y(27)+kBind6*y(2)*y(24)+(-kUnbind1)*y(46)+(-kUnbind2)*y(46)+(-kUnbind3)*y(46)+(-kBind4)*y(2)*y(46)+(-kBind5)*y(2)*y(46)+(-kUnbind6)*y(46)+kUnbind4*y(60)+kUnbind5*y(61);
	dy(47,1) = kBind1*y(2)*y(37)+kBind2*y(2)*y(31)+kBind4*y(2)*y(26)+kBind5*y(2)*y(25)+(-kUnbind1)*y(47)+(-kUnbind2)*y(47)+(-kBind3)*y(2)*y(47)+(-kUnbind4)*y(47)+(-kUnbind5)*y(47)+(-kBind6)*y(2)*y(47)+kUnbind3*y(59)+kUnbind6*y(62);
	dy(48,1) = kBind1*y(2)*y(38)+kBind2*y(2)*y(32)+kBind4*y(2)*y(27)+kBind6*y(2)*y(25)+(-kUnbind1)*y(48)+(-kUnbind2)*y(48)+(-kBind3)*y(2)*y(48)+(-kUnbind4)*y(48)+(-kBind5)*y(2)*y(48)+(-kUnbind6)*y(48)+kUnbind3*y(60)+kUnbind5*y(62);
	dy(49,1) = kBind1*y(2)*y(39)+kBind2*y(2)*y(33)+kBind5*y(2)*y(27)+kBind6*y(2)*y(26)+(-kUnbind1)*y(49)+(-kUnbind2)*y(49)+(-kBind3)*y(2)*y(49)+(-kBind4)*y(2)*y(49)+(-kUnbind5)*y(49)+(-kUnbind6)*y(49)+kUnbind3*y(61)+kUnbind4*y(62);
	dy(50,1) = kBind1*y(2)*y(40)+kBind3*y(2)*y(31)+kBind4*y(2)*y(29)+kBind5*y(2)*y(28)+(-kUnbind1)*y(50)+(-kBind2)*y(2)*y(50)+(-kUnbind3)*y(50)+(-kUnbind4)*y(50)+(-kUnbind5)*y(50)+(-kBind6)*y(2)*y(50)+kUnbind2*y(59)+kUnbind6*y(63);
	dy(51,1) = kBind1*y(2)*y(41)+kBind3*y(2)*y(32)+kBind4*y(2)*y(30)+kBind6*y(2)*y(28)+(-kUnbind1)*y(51)+(-kBind2)*y(2)*y(51)+(-kUnbind3)*y(51)+(-kUnbind4)*y(51)+(-kBind5)*y(2)*y(51)+(-kUnbind6)*y(51)+kUnbind2*y(60)+kUnbind5*y(63);
	dy(52,1) = kBind1*y(2)*y(42)+kBind3*y(2)*y(33)+kBind5*y(2)*y(30)+kBind6*y(2)*y(29)+(-kUnbind1)*y(52)+(-kBind2)*y(2)*y(52)+(-kUnbind3)*y(52)+(-kBind4)*y(2)*y(52)+(-kUnbind5)*y(52)+(-kUnbind6)*y(52)+kUnbind2*y(61)+kUnbind4*y(63);
	dy(53,1) = kBind1*y(2)*y(43)+kBind4*y(2)*y(33)+kBind5*y(2)*y(32)+kBind6*y(2)*y(31)+(-kUnbind1)*y(53)+(-kBind2)*y(2)*y(53)+(-kBind3)*y(2)*y(53)+(-kUnbind4)*y(53)+(-kUnbind5)*y(53)+(-kUnbind6)*y(53)+kUnbind2*y(62)+kUnbind3*y(63);
	dy(54,1) = kBind2*y(2)*y(40)+kBind3*y(2)*y(37)+kBind4*y(2)*y(35)+kBind5*y(2)*y(34)+(-kBind1)*y(2)*y(54)+(-kUnbind2)*y(54)+(-kUnbind3)*y(54)+(-kUnbind4)*y(54)+(-kUnbind5)*y(54)+(-kBind6)*y(2)*y(54)+kUnbind1*y(59)+kUnbind6*y(64);
	dy(55,1) = kBind2*y(2)*y(41)+kBind3*y(2)*y(38)+kBind4*y(2)*y(36)+kBind6*y(2)*y(34)+(-kBind1)*y(2)*y(55)+(-kUnbind2)*y(55)+(-kUnbind3)*y(55)+(-kUnbind4)*y(55)+(-kBind5)*y(2)*y(55)+(-kUnbind6)*y(55)+kUnbind1*y(60)+kUnbind5*y(64);
	dy(56,1) = kBind2*y(2)*y(42)+kBind3*y(2)*y(39)+kBind5*y(2)*y(36)+kBind6*y(2)*y(35)+(-kBind1)*y(2)*y(56)+(-kUnbind2)*y(56)+(-kUnbind3)*y(56)+(-kBind4)*y(2)*y(56)+(-kUnbind5)*y(56)+(-kUnbind6)*y(56)+kUnbind1*y(61)+kUnbind4*y(64);
	dy(57,1) = kBind2*y(2)*y(43)+kBind4*y(2)*y(39)+kBind5*y(2)*y(38)+kBind6*y(2)*y(37)+(-kBind1)*y(2)*y(57)+(-kUnbind2)*y(57)+(-kBind3)*y(2)*y(57)+(-kUnbind4)*y(57)+(-kUnbind5)*y(57)+(-kUnbind6)*y(57)+kUnbind1*y(62)+kUnbind3*y(64);
	dy(58,1) = kBind3*y(2)*y(43)+kBind4*y(2)*y(42)+kBind5*y(2)*y(41)+kBind6*y(2)*y(40)+(-kBind1)*y(2)*y(58)+(-kBind2)*y(2)*y(58)+(-kUnbind3)*y(58)+(-kUnbind4)*y(58)+(-kUnbind5)*y(58)+(-kUnbind6)*y(58)+kUnbind1*y(63)+kUnbind2*y(64);
	dy(59,1) = kBind1*y(2)*y(54)+kBind2*y(2)*y(50)+kBind3*y(2)*y(47)+kBind4*y(2)*y(45)+kBind5*y(2)*y(44)+(-kUnbind1)*y(59)+(-kUnbind2)*y(59)+(-kUnbind3)*y(59)+(-kUnbind4)*y(59)+(-kUnbind5)*y(59)+(-kBind6)*y(2)*y(59)+kUnbind6*y(65);
	dy(60,1) = kBind1*y(2)*y(55)+kBind2*y(2)*y(51)+kBind3*y(2)*y(48)+kBind4*y(2)*y(46)+kBind6*y(2)*y(44)+(-kUnbind1)*y(60)+(-kUnbind2)*y(60)+(-kUnbind3)*y(60)+(-kUnbind4)*y(60)+(-kBind5)*y(2)*y(60)+(-kUnbind6)*y(60)+kUnbind5*y(65);
	dy(61,1) = kBind1*y(2)*y(56)+kBind2*y(2)*y(52)+kBind3*y(2)*y(49)+kBind5*y(2)*y(46)+kBind6*y(2)*y(45)+(-kUnbind1)*y(61)+(-kUnbind2)*y(61)+(-kUnbind3)*y(61)+(-kBind4)*y(2)*y(61)+(-kUnbind5)*y(61)+(-kUnbind6)*y(61)+kUnbind4*y(65);
	dy(62,1) = kBind1*y(2)*y(57)+kBind2*y(2)*y(53)+kBind4*y(2)*y(49)+kBind5*y(2)*y(48)+kBind6*y(2)*y(47)+(-kUnbind1)*y(62)+(-kUnbind2)*y(62)+(-kBind3)*y(2)*y(62)+(-kUnbind4)*y(62)+(-kUnbind5)*y(62)+(-kUnbind6)*y(62)+kUnbind3*y(65);
	dy(63,1) = kBind1*y(2)*y(58)+kBind3*y(2)*y(53)+kBind4*y(2)*y(52)+kBind5*y(2)*y(51)+kBind6*y(2)*y(50)+(-kUnbind1)*y(63)+(-kBind2)*y(2)*y(63)+(-kUnbind3)*y(63)+(-kUnbind4)*y(63)+(-kUnbind5)*y(63)+(-kUnbind6)*y(63)+kUnbind2*y(65);
	dy(64,1) = kBind2*y(2)*y(58)+kBind3*y(2)*y(57)+kBind4*y(2)*y(56)+kBind5*y(2)*y(55)+kBind6*y(2)*y(54)+(-kBind1)*y(2)*y(64)+(-kUnbind2)*y(64)+(-kUnbind3)*y(64)+(-kUnbind4)*y(64)+(-kUnbind5)*y(64)+(-kUnbind6)*y(64)+kUnbind1*y(65);
	dy(65,1) = kBind1*y(2)*y(64)+kBind2*y(2)*y(63)+kBind3*y(2)*y(62)+kBind4*y(2)*y(61)+kBind5*y(2)*y(60)+kBind6*y(2)*y(59)+(-kUnbind1)*y(65)+(-kUnbind2)*y(65)+(-kUnbind3)*y(65)+(-kUnbind4)*y(65)+(-kUnbind5)*y(65)+(-kUnbind6)*y(65);
end






