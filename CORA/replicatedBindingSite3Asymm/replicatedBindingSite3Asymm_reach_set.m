
function replicatedBindingSite3Asymm_reach_set()

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Reachability analysis for systems with uncertain parameters using CORA
%
% Modified from the example example_nonlinear_reach_01_tank.m provided by CORA
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

 CORA_path='../../CORA_2016/';
 addpath(genpath(CORA_path));

 x0_= [ 0.0676 0.1467 0.1269 0.1537 0.105 0.0057 0.136 0.1496 0.1087 ]';
 T = 0.2;
 theta_min=[ 9.99 9.89 0.08 ];
 theta_max=[ 10.0 9.9 0.1 ];
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


	kBind1 = v(1); 
	kUnbind1 = v(3); 
	kBind2 = v(2); 
	kUnbind2 = 0.1;
	kBind3 = 10.01;
	kUnbind3 = 0.1;


	dy(1,1) = (-kBind1)*y(1)*y(2)+(-kBind2)*y(1)*y(2)+(-kBind3)*y(1)*y(2)+kUnbind1*y(3)+kUnbind2*y(4)+kUnbind3*y(5);
	dy(2,1) = (-kBind1)*y(1)*y(2)+(-kBind2)*y(1)*y(2)+(-kBind3)*y(1)*y(2)+(-kBind1)*y(2)*y(4)+(-kBind1)*y(2)*y(5)+kUnbind1*y(3)+(-kBind2)*y(2)*y(3)+(-kBind2)*y(2)*y(5)+kUnbind2*y(4)+(-kBind3)*y(2)*y(3)+(-kBind3)*y(2)*y(4)+kUnbind3*y(5)+(-kBind1)*y(2)*y(8)+kUnbind1*y(6)+kUnbind1*y(7)+(-kBind2)*y(2)*y(7)+kUnbind2*y(6)+kUnbind2*y(8)+(-kBind3)*y(2)*y(6)+kUnbind3*y(7)+kUnbind3*y(8)+kUnbind1*y(9)+kUnbind2*y(9)+kUnbind3*y(9);
	dy(3,1) = kBind1*y(1)*y(2)+(-kUnbind1)*y(3)+(-kBind2)*y(2)*y(3)+(-kBind3)*y(2)*y(3)+kUnbind2*y(6)+kUnbind3*y(7);
	dy(4,1) = kBind2*y(1)*y(2)+(-kBind1)*y(2)*y(4)+(-kUnbind2)*y(4)+(-kBind3)*y(2)*y(4)+kUnbind1*y(6)+kUnbind3*y(8);
	dy(5,1) = kBind3*y(1)*y(2)+(-kBind1)*y(2)*y(5)+(-kBind2)*y(2)*y(5)+(-kUnbind3)*y(5)+kUnbind1*y(7)+kUnbind2*y(8);
	dy(6,1) = kBind1*y(2)*y(4)+kBind2*y(2)*y(3)+(-kUnbind1)*y(6)+(-kUnbind2)*y(6)+(-kBind3)*y(2)*y(6)+kUnbind3*y(9);
	dy(7,1) = kBind1*y(2)*y(5)+kBind3*y(2)*y(3)+(-kUnbind1)*y(7)+(-kBind2)*y(2)*y(7)+(-kUnbind3)*y(7)+kUnbind2*y(9);
	dy(8,1) = kBind2*y(2)*y(5)+kBind3*y(2)*y(4)+(-kBind1)*y(2)*y(8)+(-kUnbind2)*y(8)+(-kUnbind3)*y(8)+kUnbind1*y(9);
	dy(9,1) = kBind1*y(2)*y(8)+kBind2*y(2)*y(7)+kBind3*y(2)*y(6)+(-kUnbind1)*y(9)+(-kUnbind2)*y(9)+(-kUnbind3)*y(9);
end






