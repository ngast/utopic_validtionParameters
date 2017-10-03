
function replicatedBindingSite4Asymm_reach_set(CORA_path)

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Reachability analysis for systems with uncertain parameters using CORA
%
% Modified from the example example_nonlinear_reach_01_tank.m provided by CORA
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

 addpath(genpath(CORA_path));

 x0_= [ 0.1008 0.0988 0.0522 0.0872 0.0228 0.0939 0.0042 0.0368 0.0061 0.0129 0.1095 0.0924 0.0422 0.1264 0.0046 0.0584 0.0508 ]'; 
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
	kBind3 = 10.0;
	kUnbind3 = 0.1;
	kBind4 = 10.001;
	kUnbind4 = 0.1;

	dy(1,1) = (-kBind1)*y(1)*y(2)+(-kBind2)*y(1)*y(2)+(-kBind3)*y(1)*y(2)+(-kBind4)*y(1)*y(2)+kUnbind1*y(3)+kUnbind2*y(4)+kUnbind3*y(5)+kUnbind4*y(6);
	dy(2,1) = (-kBind1)*y(1)*y(2)+(-kBind2)*y(1)*y(2)+(-kBind3)*y(1)*y(2)+(-kBind4)*y(1)*y(2)+(-kBind1)*y(2)*y(4)+(-kBind1)*y(2)*y(5)+(-kBind1)*y(2)*y(6)+kUnbind1*y(3)+(-kBind2)*y(2)*y(3)+(-kBind2)*y(2)*y(5)+(-kBind2)*y(2)*y(6)+kUnbind2*y(4)+(-kBind3)*y(2)*y(3)+(-kBind3)*y(2)*y(4)+(-kBind3)*y(2)*y(6)+kUnbind3*y(5)+(-kBind4)*y(2)*y(3)+(-kBind4)*y(2)*y(4)+(-kBind4)*y(2)*y(5)+kUnbind4*y(6)+(-kBind1)*y(2)*y(10)+(-kBind1)*y(2)*y(11)+(-kBind1)*y(2)*y(12)+kUnbind1*y(7)+kUnbind1*y(8)+kUnbind1*y(9)+(-kBind2)*y(2)*y(8)+(-kBind2)*y(2)*y(9)+(-kBind2)*y(2)*y(12)+kUnbind2*y(7)+kUnbind2*y(10)+kUnbind2*y(11)+(-kBind3)*y(2)*y(7)+(-kBind3)*y(2)*y(9)+(-kBind3)*y(2)*y(11)+kUnbind3*y(8)+kUnbind3*y(10)+kUnbind3*y(12)+(-kBind4)*y(2)*y(7)+(-kBind4)*y(2)*y(8)+(-kBind4)*y(2)*y(10)+kUnbind4*y(9)+kUnbind4*y(11)+kUnbind4*y(12)+(-kBind1)*y(2)*y(16)+kUnbind1*y(13)+kUnbind1*y(14)+kUnbind1*y(15)+(-kBind2)*y(2)*y(15)+kUnbind2*y(13)+kUnbind2*y(14)+kUnbind2*y(16)+(-kBind3)*y(2)*y(14)+kUnbind3*y(13)+kUnbind3*y(15)+kUnbind3*y(16)+(-kBind4)*y(2)*y(13)+kUnbind4*y(14)+kUnbind4*y(15)+kUnbind4*y(16)+kUnbind1*y(17)+kUnbind2*y(17)+kUnbind3*y(17)+kUnbind4*y(17);
	dy(3,1) = kBind1*y(1)*y(2)+(-kUnbind1)*y(3)+(-kBind2)*y(2)*y(3)+(-kBind3)*y(2)*y(3)+(-kBind4)*y(2)*y(3)+kUnbind2*y(7)+kUnbind3*y(8)+kUnbind4*y(9);
	dy(4,1) = kBind2*y(1)*y(2)+(-kBind1)*y(2)*y(4)+(-kUnbind2)*y(4)+(-kBind3)*y(2)*y(4)+(-kBind4)*y(2)*y(4)+kUnbind1*y(7)+kUnbind3*y(10)+kUnbind4*y(11);
	dy(5,1) = kBind3*y(1)*y(2)+(-kBind1)*y(2)*y(5)+(-kBind2)*y(2)*y(5)+(-kUnbind3)*y(5)+(-kBind4)*y(2)*y(5)+kUnbind1*y(8)+kUnbind2*y(10)+kUnbind4*y(12);
	dy(6,1) = kBind4*y(1)*y(2)+(-kBind1)*y(2)*y(6)+(-kBind2)*y(2)*y(6)+(-kBind3)*y(2)*y(6)+(-kUnbind4)*y(6)+kUnbind1*y(9)+kUnbind2*y(11)+kUnbind3*y(12);
	dy(7,1) = kBind1*y(2)*y(4)+kBind2*y(2)*y(3)+(-kUnbind1)*y(7)+(-kUnbind2)*y(7)+(-kBind3)*y(2)*y(7)+(-kBind4)*y(2)*y(7)+kUnbind3*y(13)+kUnbind4*y(14);
	dy(8,1) = kBind1*y(2)*y(5)+kBind3*y(2)*y(3)+(-kUnbind1)*y(8)+(-kBind2)*y(2)*y(8)+(-kUnbind3)*y(8)+(-kBind4)*y(2)*y(8)+kUnbind2*y(13)+kUnbind4*y(15);
	dy(9,1) = kBind1*y(2)*y(6)+kBind4*y(2)*y(3)+(-kUnbind1)*y(9)+(-kBind2)*y(2)*y(9)+(-kBind3)*y(2)*y(9)+(-kUnbind4)*y(9)+kUnbind2*y(14)+kUnbind3*y(15);
	dy(10,1) = kBind2*y(2)*y(5)+kBind3*y(2)*y(4)+(-kBind1)*y(2)*y(10)+(-kUnbind2)*y(10)+(-kUnbind3)*y(10)+(-kBind4)*y(2)*y(10)+kUnbind1*y(13)+kUnbind4*y(16);
	dy(11,1) = kBind2*y(2)*y(6)+kBind4*y(2)*y(4)+(-kBind1)*y(2)*y(11)+(-kUnbind2)*y(11)+(-kBind3)*y(2)*y(11)+(-kUnbind4)*y(11)+kUnbind1*y(14)+kUnbind3*y(16);
	dy(12,1) = kBind3*y(2)*y(6)+kBind4*y(2)*y(5)+(-kBind1)*y(2)*y(12)+(-kBind2)*y(2)*y(12)+(-kUnbind3)*y(12)+(-kUnbind4)*y(12)+kUnbind1*y(15)+kUnbind2*y(16);
	dy(13,1) = kBind1*y(2)*y(10)+kBind2*y(2)*y(8)+kBind3*y(2)*y(7)+(-kUnbind1)*y(13)+(-kUnbind2)*y(13)+(-kUnbind3)*y(13)+(-kBind4)*y(2)*y(13)+kUnbind4*y(17);
	dy(14,1) = kBind1*y(2)*y(11)+kBind2*y(2)*y(9)+kBind4*y(2)*y(7)+(-kUnbind1)*y(14)+(-kUnbind2)*y(14)+(-kBind3)*y(2)*y(14)+(-kUnbind4)*y(14)+kUnbind3*y(17);
	dy(15,1) = kBind1*y(2)*y(12)+kBind3*y(2)*y(9)+kBind4*y(2)*y(8)+(-kUnbind1)*y(15)+(-kBind2)*y(2)*y(15)+(-kUnbind3)*y(15)+(-kUnbind4)*y(15)+kUnbind2*y(17);
	dy(16,1) = kBind2*y(2)*y(12)+kBind3*y(2)*y(11)+kBind4*y(2)*y(10)+(-kBind1)*y(2)*y(16)+(-kUnbind2)*y(16)+(-kUnbind3)*y(16)+(-kUnbind4)*y(16)+kUnbind1*y(17);
	dy(17,1) = kBind1*y(2)*y(16)+kBind2*y(2)*y(15)+kBind3*y(2)*y(14)+kBind4*y(2)*y(13)+(-kUnbind1)*y(17)+(-kUnbind2)*y(17)+(-kUnbind3)*y(17)+(-kUnbind4)*y(17);

end






