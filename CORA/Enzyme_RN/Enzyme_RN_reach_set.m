
function Enzyme_RN_reach_set()

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Reachability analysis for systems with uncertain parameters using CORA
%
% Modified from the example example_nonlinear_reach_01_tank.m provided by CORA
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

 CORA_path='../../CORA_2016/';
 addpath(genpath(CORA_path));

 T = 1;
 theta_min=[ 0.9 0.8 1.0 ];
 theta_max=[ 1.1 1.0 1.4 ];
 x0_=[ 0.1 0.1 0.1 0.2 0.1 0.3 0.1 ]'; 
 alpha=[1.0 0];

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

% compute the maximum and the minimum
 Z = Rcont{length(Rcont)}{1};
 Z = project(Z,[1 2]);
 p = polygon(Z);
 res=alpha(1)*p(1,:);
 disp(['The output interval is [',num2str(min(res)),', ',num2str(max(res)),']']);

 rmpath(genpath('../../CORA_2016/'));

end


function dy =  ode(t,y,v)

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Modification of the ODE system replicatedBindingSite2Asymm
% Used by ODE solvers in CORA 
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% 

	k1 = v(1);
	k2 = v(2);
	k3 = v(3);
	k4 = 1.0;
	k5 = 1.0;
	k6 = 1.0;
	k7 = 1.0;
	k8 = 1.0;
	k9 = 1.0;
	Fs1 = 2.0;
	Fs2 = 2.0;
	epsS1 = 0.1;
	epsS2 = 0.1;
	epsP = 0.1;

	dy(1,1) = (-k1)*y(1)*y(4)-k3*y(1)*y(5)+k9*y(6);
	dy(2,1) = (-k1)*y(1)*y(2)+k2*y(5)+k8*y(6)+(Fs1-epsS1*y(2));
	dy(3,1) = (-k3)*y(1)*y(5)-k5*y(3)*y(4)+k6*y(6)+(Fs2-epsS2*y(3));
	dy(4,1) = k1*y(1)*y(2)-k2*y(4)-k5*y(4)+k6*y(6);
	dy(5,1) = k3*y(1)*y(3)-k4*y(5)-k7*y(5)*y(2)+k8*y(6);
	dy(6,1) = k5*y(3)*y(4)+k7*y(5)*y(2)+(k6+k8+k9)*y(6);
	dy(7,1) = k9*y(6)-epsP*y(7);
end





