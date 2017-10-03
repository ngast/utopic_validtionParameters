
function GeneticOscilator_reach_set(CORA_path)

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Reachability analysis for systems with uncertain parameters using CORA
%
% Modified from the example example_nonlinear_reach_01_tank.m provided by CORA
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

 addpath(genpath(CORA_path));

 T = 1;
 theta_min=[ 0.9 1.8 0.5 ];
 theta_max=[ 1.1 2.1 1.0 ];
 x0_=[ 0.1 0.1 0.1 0.2 0.1 0.1 0.1 0.1 0.1 ]';
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
	thetaA = v(1); 
	thetaR = 1.0;
	gammaA = v(2); 
	gammaR = 2.0;
	gammaC = 2.0;
	alphaA = 0.2;
	alphaA1 = 0.5;
	alphaR = 0.2;
	alphaR1 = 0.5;
	deltaMa = 0.1;
	deltaMr = 0.1;
	deltaA = 0.1;
	deltaR = 0.1;
	betaA = v(3); 
	betaR = 0.7;

	dy(1,1) = thetaA*y(3)-gammaA*y(1)*y(6);
	dy(2,1) = thetaR*y(4)-gammaR*y(2)*y(6);
	dy(3,1) = gammaA*y(1)*y(6)-thetaA*y(3);
	dy(4,1) = gammaR*y(2)*y(6)-thetaR*y(4);
	dy(5,1) = alphaA1*y(3)+(alphaA*y(1)-deltaMa*y(5));
	dy(6,1) = betaA*y(5)+thetaA*y(3)+(thetaR*y(4)-y(6)*(gammaA*y(1)+gammaR*y(2)+gammaC*y(8)+deltaA));
	dy(7,1) = alphaR1*y(4)+(alphaR*y(2)-deltaMr*y(7));
	dy(8,1) = betaR*y(4)-gammaC*y(6)*y(8)+(deltaA*y(9)-deltaR*y(8));
	dy(9,1) = gammaC*y(6)*y(8)-gammaA*y(9);
end





