
function Aging_erach_set()

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Reachability analysis for systems with uncertain parameters using CORA
%
% Modified from the example example_nonlinear_reach_01_tank.m provided by CORA
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

 CORA_path='../../CORA_2016/';
 addpath(genpath(CORA_path));

 x0_= [500 500 500 100 100 100 200 500 20]';
 T = 1;
 theta_min=[0.8 2.1 5.0];
 theta_max=[1.1 2.3 5.3];
 alpha=[ 1.0 0 0 0 0 0 0 0 0.0 ]; % vector of coefficients of the sum of variables

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
 
 Z=project(Z,[1 2]);
 p=polygon(Z);
 res=p(1,:);

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

	alpha = 0.01;
	beta = 0.05;
	gamma = 0.1;
	delt = 0.693; 
	RDF = 0.02;
	GDF = 5.0;
	kM = 0.003;
	kD = 0.003;
	k1 = 1000.0;
	k2 = 100.0;
	k3 = 7000.0;
	k4 = v(1);
	k5 = v(2);
	k6 = v(3);
	kEM = 400.0;
	kEP = 8.0E-4;
	kEC = 1000000.0;
	kR = 900.0;
	kATP = 1200.0;
	ATPc = 1000.0;
	PAOx = 1.0;

	dy(1,1) = y(9)/(y(9)+ATPc)*k1/((1+y(9)/ATPc)*(1+y(9)/ATPc)*(1+y(9)/ATPc));%*1/(y(1)+2*y(2)/(GDF+1)+(y(3)+y(4)+y(5)+y(6))/GDF)*y(1)+(2*y(9)/(y(9)+ATPc)*k1/((1+y(9)/ATPc)*(1+y(9)/ATPc)*(1+y(9)/ATPc))*1/(y(1)+2*y(2)/(GDF+1)+(y(3)+y(4)+y(5)+y(6))/GDF)*y(2)/(GDF+1)-(alpha+(kM+kD)*y(8))*y(1));
	dy(2,1) = (-k4)*y(9)/(y(9)+ATPc)*k1/((1+y(9)/ATPc)*(1+y(9)/ATPc)*(1+y(9)/ATPc));%*1/(y(1)+2*y(2)/(GDF+1)+(y(3)+y(4)+y(5)+y(6))/GDF)*y(2)/(GDF+1)+2*y(9)/(y(9)+ATPc)*k1/((1+y(9)/ATPc)*(1+y(9)/ATPc)*(1+y(9)/ATPc))*1/(y(1)+2*y(2)/(GDF+1)+(y(3)+y(4)+y(5)+y(6))/GDF)*y(3)/GDF+(kM*y(8)*y(1)-(beta+(kM+kD)*y(8))*y(1));
	dy(3,1) = (-k5)*y(9)/(y(9)+ATPc)*k1/((1+y(9)/ATPc)*(1+y(9)/ATPc)*(1+y(9)/ATPc));%*1/(y(1)+2*y(2)/(GDF+1)+(y(3)+y(4)+y(5)+y(6))/GDF)*y(3)/GDF+(kM*y(8)*y(2)-(gamma+kD*y(8))*y(3));
	dy(4,1) = y(9)/(y(9)+ATPc)*k1/((1+y(9)/ATPc)*(1+y(9)/ATPc)*(1+y(9)/ATPc));%*1/(y(1)+2*y(2)/(GDF+1)+(y(3)+y(4)+y(5)+y(6))/GDF)*(y(4)+y(5))/GDF+(kD*y(8)*y(1)-(alpha+kD*y(8))*y(4));
	dy(5,1) = 1;% (-y(9)/(y(9)+ATPc)*k1/((1+y(9)/ATPc)*(1+y(9)/ATPc)*(1+y(9)/ATPc))*1/(y(1)+2*y(2)/(GDF+1)+(y(3)+y(4)+y(5)+y(6))/GDF))*y(5)/GDF+2*y(9)/(y(9)+ATPc)*k1/((1+y(9)/ATPc)*(1+y(9)/ATPc)*(1+y(9)/ATPc))*1/(y(1)+2*y(2)/(GDF+1)+(y(3)+y(4)+y(5)+y(6))/GDF)*y(6)/GDF+(kD*y(8)*y(2)-(alpha+kM*RDF*y(8))*y(4)-(beta+kM*RDF*y(8))*y(5));
	dy(6,1) = 1;%(-y(9)/(y(9)+ATPc)*k1/((1+y(9)/ATPc)*(1+y(9)/ATPc)*(1+y(9)/ATPc))*1/(y(1)+2*y(2)/(GDF+1)+(y(3)+y(4)+y(5)+y(6))/GDF))*y(6)/GDF+kD*y(8)*y(3)+(kM*RDF*y(8)*y(5)-gamma*y(6));
	dy(7,1) = y(9)/(y(9)+ATPc);%*k2/(1+PAOx/(y(8)*(y(1)+y(2)+y(3))+RDF*y(8)*(y(4)+y(5)+y(6))))-delt*y(7);
	dy(8,1) = k6*kR-k3*y(7)*y(8)/(y(1)+y(2)+y(3)+y(4)+y(5)+y(6));
	dy(9,1) = kATP*y(1);%+(0.5*kATP*y(2)-y(9)/(y(9)+ATPc)*(kEM*k1/((1+y(9)/ATPc)*(1+y(9)/ATPc)*(1+y(9)/ATPc))+kEC+kEP*k2/(1+PAOx/(y(8)*(y(1)+y(2)+y(3))+RDF*y(8)*(y(4)+y(5)+y(6))))));

end





