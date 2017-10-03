
function replicatedBindingSite5Asymm_reach_set(CORA_path)

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Reachability analysis for systems with uncertain parameters using CORA
%
% Modified from the example example_nonlinear_reach_01_tank.m provided by CORA
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

 addpath(genpath(CORA_path));

 x0_= [ 0.0437 0.0454 0.0107 0.0279 0.0254 0.0369 0.0405 0.0431 0.0157 0.0388 0.0374 0.0093 0.0068 0.0284 0.0547 0.0194 0.0334 0.0128 0.0429 0.0146 0.0289 0.0399 0.0508 0.0547 0.0312 0.0079 0.0085 0.0147 0.048 0.0145 0.0465 0.0139 0.053 ]'; 
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
	kBind4 = 10.0004;
	kUnbind4 = 0.1;
	kBind5 = 10.0008;
	kUnbind5 = 0.1;

	dy(1,1) = (-kBind1)*y(1)*y(2)+(-kBind2)*y(1)*y(2)+(-kBind3)*y(1)*y(2)+(-kBind4)*y(1)*y(2)+(-kBind5)*y(1)*y(2)+kUnbind1*y(3)+kUnbind2*y(4)+kUnbind3*y(5)+kUnbind4*y(6)+kUnbind5*y(7);
	dy(2,1) = (-kBind1)*y(1)*y(2)+(-kBind2)*y(1)*y(2)+(-kBind3)*y(1)*y(2)+(-kBind4)*y(1)*y(2)+(-kBind5)*y(1)*y(2)+(-kBind1)*y(2)*y(4)+(-kBind1)*y(2)*y(5)+(-kBind1)*y(2)*y(6)+(-kBind1)*y(2)*y(7)+kUnbind1*y(3)+(-kBind2)*y(2)*y(3)+(-kBind2)*y(2)*y(5)+(-kBind2)*y(2)*y(6)+(-kBind2)*y(2)*y(7)+kUnbind2*y(4)+(-kBind3)*y(2)*y(3)+(-kBind3)*y(2)*y(4)+(-kBind3)*y(2)*y(6)+(-kBind3)*y(2)*y(7)+kUnbind3*y(5)+(-kBind4)*y(2)*y(3)+(-kBind4)*y(2)*y(4)+(-kBind4)*y(2)*y(5)+(-kBind4)*y(2)*y(7)+kUnbind4*y(6)+(-kBind5)*y(2)*y(3)+(-kBind5)*y(2)*y(4)+(-kBind5)*y(2)*y(5)+(-kBind5)*y(2)*y(6)+kUnbind5*y(7)+(-kBind1)*y(2)*y(12)+(-kBind1)*y(2)*y(13)+(-kBind1)*y(2)*y(14)+(-kBind1)*y(2)*y(15)+(-kBind1)*y(2)*y(16)+(-kBind1)*y(2)*y(17)+kUnbind1*y(8)+kUnbind1*y(9)+kUnbind1*y(10)+kUnbind1*y(11)+(-kBind2)*y(2)*y(9)+(-kBind2)*y(2)*y(10)+(-kBind2)*y(2)*y(11)+(-kBind2)*y(2)*y(15)+(-kBind2)*y(2)*y(16)+(-kBind2)*y(2)*y(17)+kUnbind2*y(8)+kUnbind2*y(12)+kUnbind2*y(13)+kUnbind2*y(14)+(-kBind3)*y(2)*y(8)+(-kBind3)*y(2)*y(10)+(-kBind3)*y(2)*y(11)+(-kBind3)*y(2)*y(13)+(-kBind3)*y(2)*y(14)+(-kBind3)*y(2)*y(17)+kUnbind3*y(9)+kUnbind3*y(12)+kUnbind3*y(15)+kUnbind3*y(16)+(-kBind4)*y(2)*y(8)+(-kBind4)*y(2)*y(9)+(-kBind4)*y(2)*y(11)+(-kBind4)*y(2)*y(12)+(-kBind4)*y(2)*y(14)+(-kBind4)*y(2)*y(16)+kUnbind4*y(10)+kUnbind4*y(13)+kUnbind4*y(15)+kUnbind4*y(17)+(-kBind5)*y(2)*y(8)+(-kBind5)*y(2)*y(9)+(-kBind5)*y(2)*y(10)+(-kBind5)*y(2)*y(12)+(-kBind5)*y(2)*y(13)+(-kBind5)*y(2)*y(15)+kUnbind5*y(11)+kUnbind5*y(14)+kUnbind5*y(16)+kUnbind5*y(17)+(-kBind1)*y(2)*y(24)+(-kBind1)*y(2)*y(25)+(-kBind1)*y(2)*y(26)+(-kBind1)*y(2)*y(27)+kUnbind1*y(18)+kUnbind1*y(19)+kUnbind1*y(20)+kUnbind1*y(21)+kUnbind1*y(22)+kUnbind1*y(23)+(-kBind2)*y(2)*y(21)+(-kBind2)*y(2)*y(22)+(-kBind2)*y(2)*y(23)+(-kBind2)*y(2)*y(27)+kUnbind2*y(18)+kUnbind2*y(19)+kUnbind2*y(20)+kUnbind2*y(24)+kUnbind2*y(25)+kUnbind2*y(26)+(-kBind3)*y(2)*y(19)+(-kBind3)*y(2)*y(20)+(-kBind3)*y(2)*y(23)+(-kBind3)*y(2)*y(26)+kUnbind3*y(18)+kUnbind3*y(21)+kUnbind3*y(22)+kUnbind3*y(24)+kUnbind3*y(25)+kUnbind3*y(27)+(-kBind4)*y(2)*y(18)+(-kBind4)*y(2)*y(20)+(-kBind4)*y(2)*y(22)+(-kBind4)*y(2)*y(25)+kUnbind4*y(19)+kUnbind4*y(21)+kUnbind4*y(23)+kUnbind4*y(24)+kUnbind4*y(26)+kUnbind4*y(27)+(-kBind5)*y(2)*y(18)+(-kBind5)*y(2)*y(19)+(-kBind5)*y(2)*y(21)+(-kBind5)*y(2)*y(24)+kUnbind5*y(20)+kUnbind5*y(22)+kUnbind5*y(23)+kUnbind5*y(25)+kUnbind5*y(26)+kUnbind5*y(27)+(-kBind1)*y(2)*y(32)+kUnbind1*y(28)+kUnbind1*y(29)+kUnbind1*y(30)+kUnbind1*y(31)+(-kBind2)*y(2)*y(31)+kUnbind2*y(28)+kUnbind2*y(29)+kUnbind2*y(30)+kUnbind2*y(32)+(-kBind3)*y(2)*y(30)+kUnbind3*y(28)+kUnbind3*y(29)+kUnbind3*y(31)+kUnbind3*y(32)+(-kBind4)*y(2)*y(29)+kUnbind4*y(28)+kUnbind4*y(30)+kUnbind4*y(31)+kUnbind4*y(32)+(-kBind5)*y(2)*y(28)+kUnbind5*y(29)+kUnbind5*y(30)+kUnbind5*y(31)+kUnbind5*y(32)+kUnbind1*y(33)+kUnbind2*y(33)+kUnbind3*y(33)+kUnbind4*y(33)+kUnbind5*y(33);
	dy(3,1) = kBind1*y(1)*y(2)+(-kUnbind1)*y(3)+(-kBind2)*y(2)*y(3)+(-kBind3)*y(2)*y(3)+(-kBind4)*y(2)*y(3)+(-kBind5)*y(2)*y(3)+kUnbind2*y(8)+kUnbind3*y(9)+kUnbind4*y(10)+kUnbind5*y(11);
	dy(4,1) = kBind2*y(1)*y(2)+(-kBind1)*y(2)*y(4)+(-kUnbind2)*y(4)+(-kBind3)*y(2)*y(4)+(-kBind4)*y(2)*y(4)+(-kBind5)*y(2)*y(4)+kUnbind1*y(8)+kUnbind3*y(12)+kUnbind4*y(13)+kUnbind5*y(14);
	dy(5,1) = kBind3*y(1)*y(2)+(-kBind1)*y(2)*y(5)+(-kBind2)*y(2)*y(5)+(-kUnbind3)*y(5)+(-kBind4)*y(2)*y(5)+(-kBind5)*y(2)*y(5)+kUnbind1*y(9)+kUnbind2*y(12)+kUnbind4*y(15)+kUnbind5*y(16);
	dy(6,1) = kBind4*y(1)*y(2)+(-kBind1)*y(2)*y(6)+(-kBind2)*y(2)*y(6)+(-kBind3)*y(2)*y(6)+(-kUnbind4)*y(6)+(-kBind5)*y(2)*y(6)+kUnbind1*y(10)+kUnbind2*y(13)+kUnbind3*y(15)+kUnbind5*y(17);
	dy(7,1) = kBind5*y(1)*y(2)+(-kBind1)*y(2)*y(7)+(-kBind2)*y(2)*y(7)+(-kBind3)*y(2)*y(7)+(-kBind4)*y(2)*y(7)+(-kUnbind5)*y(7)+kUnbind1*y(11)+kUnbind2*y(14)+kUnbind3*y(16)+kUnbind4*y(17);
	dy(8,1) = kBind1*y(2)*y(4)+kBind2*y(2)*y(3)+(-kUnbind1)*y(8)+(-kUnbind2)*y(8)+(-kBind3)*y(2)*y(8)+(-kBind4)*y(2)*y(8)+(-kBind5)*y(2)*y(8)+kUnbind3*y(18)+kUnbind4*y(19)+kUnbind5*y(20);
	dy(9,1) = kBind1*y(2)*y(5)+kBind3*y(2)*y(3)+(-kUnbind1)*y(9)+(-kBind2)*y(2)*y(9)+(-kUnbind3)*y(9)+(-kBind4)*y(2)*y(9)+(-kBind5)*y(2)*y(9)+kUnbind2*y(18)+kUnbind4*y(21)+kUnbind5*y(22);
	dy(10,1) = kBind1*y(2)*y(6)+kBind4*y(2)*y(3)+(-kUnbind1)*y(10)+(-kBind2)*y(2)*y(10)+(-kBind3)*y(2)*y(10)+(-kUnbind4)*y(10)+(-kBind5)*y(2)*y(10)+kUnbind2*y(19)+kUnbind3*y(21)+kUnbind5*y(23);
	dy(11,1) = kBind1*y(2)*y(7)+kBind5*y(2)*y(3)+(-kUnbind1)*y(11)+(-kBind2)*y(2)*y(11)+(-kBind3)*y(2)*y(11)+(-kBind4)*y(2)*y(11)+(-kUnbind5)*y(11)+kUnbind2*y(20)+kUnbind3*y(22)+kUnbind4*y(23);
	dy(12,1) = kBind2*y(2)*y(5)+kBind3*y(2)*y(4)+(-kBind1)*y(2)*y(12)+(-kUnbind2)*y(12)+(-kUnbind3)*y(12)+(-kBind4)*y(2)*y(12)+(-kBind5)*y(2)*y(12)+kUnbind1*y(18)+kUnbind4*y(24)+kUnbind5*y(25);
	dy(13,1) = kBind2*y(2)*y(6)+kBind4*y(2)*y(4)+(-kBind1)*y(2)*y(13)+(-kUnbind2)*y(13)+(-kBind3)*y(2)*y(13)+(-kUnbind4)*y(13)+(-kBind5)*y(2)*y(13)+kUnbind1*y(19)+kUnbind3*y(24)+kUnbind5*y(26);
	dy(14,1) = kBind2*y(2)*y(7)+kBind5*y(2)*y(4)+(-kBind1)*y(2)*y(14)+(-kUnbind2)*y(14)+(-kBind3)*y(2)*y(14)+(-kBind4)*y(2)*y(14)+(-kUnbind5)*y(14)+kUnbind1*y(20)+kUnbind3*y(25)+kUnbind4*y(26);
	dy(15,1) = kBind3*y(2)*y(6)+kBind4*y(2)*y(5)+(-kBind1)*y(2)*y(15)+(-kBind2)*y(2)*y(15)+(-kUnbind3)*y(15)+(-kUnbind4)*y(15)+(-kBind5)*y(2)*y(15)+kUnbind1*y(21)+kUnbind2*y(24)+kUnbind5*y(27);
	dy(16,1) = kBind3*y(2)*y(7)+kBind5*y(2)*y(5)+(-kBind1)*y(2)*y(16)+(-kBind2)*y(2)*y(16)+(-kUnbind3)*y(16)+(-kBind4)*y(2)*y(16)+(-kUnbind5)*y(16)+kUnbind1*y(22)+kUnbind2*y(25)+kUnbind4*y(27);
	dy(17,1) = kBind4*y(2)*y(7)+kBind5*y(2)*y(6)+(-kBind1)*y(2)*y(17)+(-kBind2)*y(2)*y(17)+(-kBind3)*y(2)*y(17)+(-kUnbind4)*y(17)+(-kUnbind5)*y(17)+kUnbind1*y(23)+kUnbind2*y(26)+kUnbind3*y(27);
	dy(18,1) = kBind1*y(2)*y(12)+kBind2*y(2)*y(9)+kBind3*y(2)*y(8)+(-kUnbind1)*y(18)+(-kUnbind2)*y(18)+(-kUnbind3)*y(18)+(-kBind4)*y(2)*y(18)+(-kBind5)*y(2)*y(18)+kUnbind4*y(28)+kUnbind5*y(29);
	dy(19,1) = kBind1*y(2)*y(13)+kBind2*y(2)*y(10)+kBind4*y(2)*y(8)+(-kUnbind1)*y(19)+(-kUnbind2)*y(19)+(-kBind3)*y(2)*y(19)+(-kUnbind4)*y(19)+(-kBind5)*y(2)*y(19)+kUnbind3*y(28)+kUnbind5*y(30);
	dy(20,1) = kBind1*y(2)*y(14)+kBind2*y(2)*y(11)+kBind5*y(2)*y(8)+(-kUnbind1)*y(20)+(-kUnbind2)*y(20)+(-kBind3)*y(2)*y(20)+(-kBind4)*y(2)*y(20)+(-kUnbind5)*y(20)+kUnbind3*y(29)+kUnbind4*y(30);
	dy(21,1) = kBind1*y(2)*y(15)+kBind3*y(2)*y(10)+kBind4*y(2)*y(9)+(-kUnbind1)*y(21)+(-kBind2)*y(2)*y(21)+(-kUnbind3)*y(21)+(-kUnbind4)*y(21)+(-kBind5)*y(2)*y(21)+kUnbind2*y(28)+kUnbind5*y(31);
	dy(22,1) = kBind1*y(2)*y(16)+kBind3*y(2)*y(11)+kBind5*y(2)*y(9)+(-kUnbind1)*y(22)+(-kBind2)*y(2)*y(22)+(-kUnbind3)*y(22)+(-kBind4)*y(2)*y(22)+(-kUnbind5)*y(22)+kUnbind2*y(29)+kUnbind4*y(31);
	dy(23,1) = kBind1*y(2)*y(17)+kBind4*y(2)*y(11)+kBind5*y(2)*y(10)+(-kUnbind1)*y(23)+(-kBind2)*y(2)*y(23)+(-kBind3)*y(2)*y(23)+(-kUnbind4)*y(23)+(-kUnbind5)*y(23)+kUnbind2*y(30)+kUnbind3*y(31);
	dy(24,1) = kBind2*y(2)*y(15)+kBind3*y(2)*y(13)+kBind4*y(2)*y(12)+(-kBind1)*y(2)*y(24)+(-kUnbind2)*y(24)+(-kUnbind3)*y(24)+(-kUnbind4)*y(24)+(-kBind5)*y(2)*y(24)+kUnbind1*y(28)+kUnbind5*y(32);
	dy(25,1) = kBind2*y(2)*y(16)+kBind3*y(2)*y(14)+kBind5*y(2)*y(12)+(-kBind1)*y(2)*y(25)+(-kUnbind2)*y(25)+(-kUnbind3)*y(25)+(-kBind4)*y(2)*y(25)+(-kUnbind5)*y(25)+kUnbind1*y(29)+kUnbind4*y(32);
	dy(26,1) = kBind2*y(2)*y(17)+kBind4*y(2)*y(14)+kBind5*y(2)*y(13)+(-kBind1)*y(2)*y(26)+(-kUnbind2)*y(26)+(-kBind3)*y(2)*y(26)+(-kUnbind4)*y(26)+(-kUnbind5)*y(26)+kUnbind1*y(30)+kUnbind3*y(32);
	dy(27,1) = kBind3*y(2)*y(17)+kBind4*y(2)*y(16)+kBind5*y(2)*y(15)+(-kBind1)*y(2)*y(27)+(-kBind2)*y(2)*y(27)+(-kUnbind3)*y(27)+(-kUnbind4)*y(27)+(-kUnbind5)*y(27)+kUnbind1*y(31)+kUnbind2*y(32);
	dy(28,1) = kBind1*y(2)*y(24)+kBind2*y(2)*y(21)+kBind3*y(2)*y(19)+kBind4*y(2)*y(18)+(-kUnbind1)*y(28)+(-kUnbind2)*y(28)+(-kUnbind3)*y(28)+(-kUnbind4)*y(28)+(-kBind5)*y(2)*y(28)+kUnbind5*y(33);
	dy(29,1) = kBind1*y(2)*y(25)+kBind2*y(2)*y(22)+kBind3*y(2)*y(20)+kBind5*y(2)*y(18)+(-kUnbind1)*y(29)+(-kUnbind2)*y(29)+(-kUnbind3)*y(29)+(-kBind4)*y(2)*y(29)+(-kUnbind5)*y(29)+kUnbind4*y(33);
	dy(30,1) = kBind1*y(2)*y(26)+kBind2*y(2)*y(23)+kBind4*y(2)*y(20)+kBind5*y(2)*y(19)+(-kUnbind1)*y(30)+(-kUnbind2)*y(30)+(-kBind3)*y(2)*y(30)+(-kUnbind4)*y(30)+(-kUnbind5)*y(30)+kUnbind3*y(33);
	dy(31,1) = kBind1*y(2)*y(27)+kBind3*y(2)*y(23)+kBind4*y(2)*y(22)+kBind5*y(2)*y(21)+(-kUnbind1)*y(31)+(-kBind2)*y(2)*y(31)+(-kUnbind3)*y(31)+(-kUnbind4)*y(31)+(-kUnbind5)*y(31)+kUnbind2*y(33);
	dy(32,1) = kBind2*y(2)*y(27)+kBind3*y(2)*y(26)+kBind4*y(2)*y(25)+kBind5*y(2)*y(24)+(-kBind1)*y(2)*y(32)+(-kUnbind2)*y(32)+(-kUnbind3)*y(32)+(-kUnbind4)*y(32)+(-kUnbind5)*y(32)+kUnbind1*y(33);
	dy(33,1) = kBind1*y(2)*y(32)+kBind2*y(2)*y(31)+kBind3*y(2)*y(30)+kBind4*y(2)*y(29)+kBind5*y(2)*y(28)+(-kUnbind1)*y(33)+(-kUnbind2)*y(33)+(-kUnbind3)*y(33)+(-kUnbind4)*y(33)+(-kUnbind5)*y(33);


end






