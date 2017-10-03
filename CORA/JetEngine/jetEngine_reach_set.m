
function Brusselator_reach_set(CORA_path)

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Reachability analysis for systems with uncertain parameters using CORA
%
% Modified from the example example_nonlinear_reach_01_tank.m provided by CORA
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

 addpath(genpath(CORA_path));

 x0_= [1 1]';
 T = 1;
 theta_min=[0.9 2.7 1.1];
 theta_max=[1.1 3.2 1.6];
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
 res=0;
 Z_=Z;
 for i=1:2:dim-1
   Z = project(Z_,[i i+1]);
   p = polygon(Z);
   res=res+alpha(i)*p(1,:)+alpha(i+1)*p(2,:);
 end
 if mod(dim,2)~=0
   Z = project(Z_,[dim-1 dim]);
   p = polygon(Z);
   res=res+alpha(dim)*p(2,:);
 end

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

	a = v(1);
	b = v(2);
	c = v(3); 

	dy(1,1) = -a*y(2) - c*y(1)*y(1)-0.5*y(1)*y(1)*y(1)-0.5;
  	dy(2,1) = b*y(1)-y(2);
end





