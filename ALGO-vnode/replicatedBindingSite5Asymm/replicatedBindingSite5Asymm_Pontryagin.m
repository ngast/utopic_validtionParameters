%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Reachability analysis of the system replicatedBindingSite5AsymmODE with 3 uncertain parameters %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Automatically generated from replicatedBindingSite5AsymmODE.
% Number of species: 33.
% Number of reactions: 33.
% Coefficients:  0 1.0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0.
% Perturbed parameters: kBind1 in [9.9,10.0], kBind2 in [9.8,9.9], kUnbind1 in [0.08,0.1]

% Correspondence with original names:
%     x(1) = A(b1,b2,b3,b4,b5)
%     x(2) = B(b)
%     x(3) = A(b1!1,b2,b3,b4,b5).B(b!1)
%     x(4) = A(b1,b2!1,b3,b4,b5).B(b!1)
%     x(5) = A(b1,b2,b3!1,b4,b5).B(b!1)
%     x(6) = A(b1,b2,b3,b4!1,b5).B(b!1)
%     x(7) = A(b1,b2,b3,b4,b5!1).B(b!1)
%     x(8) = A(b1!1,b2!2,b3,b4,b5).B(b!2).B(b!1)
%     x(9) = A(b1!1,b2,b3!2,b4,b5).B(b!2).B(b!1)
%     x(10) = A(b1!1,b2,b3,b4!2,b5).B(b!2).B(b!1)
%     x(11) = A(b1!1,b2,b3,b4,b5!2).B(b!2).B(b!1)
%     x(12) = A(b1,b2!1,b3!2,b4,b5).B(b!2).B(b!1)
%     x(13) = A(b1,b2!1,b3,b4!2,b5).B(b!2).B(b!1)
%     x(14) = A(b1,b2!1,b3,b4,b5!2).B(b!2).B(b!1)
%     x(15) = A(b1,b2,b3!1,b4!2,b5).B(b!2).B(b!1)
%     x(16) = A(b1,b2,b3!1,b4,b5!2).B(b!2).B(b!1)
%     x(17) = A(b1,b2,b3,b4!1,b5!2).B(b!2).B(b!1)
%     x(18) = A(b1!1,b2!2,b3!3,b4,b5).B(b!3).B(b!2).B(b!1)
%     x(19) = A(b1!1,b2!2,b3,b4!3,b5).B(b!3).B(b!2).B(b!1)
%     x(20) = A(b1!1,b2!2,b3,b4,b5!3).B(b!3).B(b!2).B(b!1)
%     x(21) = A(b1!1,b2,b3!2,b4!3,b5).B(b!3).B(b!2).B(b!1)
%     x(22) = A(b1!1,b2,b3!2,b4,b5!3).B(b!3).B(b!2).B(b!1)
%     x(23) = A(b1!1,b2,b3,b4!2,b5!3).B(b!3).B(b!2).B(b!1)
%     x(24) = A(b1,b2!1,b3!2,b4!3,b5).B(b!3).B(b!2).B(b!1)
%     x(25) = A(b1,b2!1,b3!2,b4,b5!3).B(b!3).B(b!2).B(b!1)
%     x(26) = A(b1,b2!1,b3,b4!2,b5!3).B(b!3).B(b!2).B(b!1)
%     x(27) = A(b1,b2,b3!1,b4!2,b5!3).B(b!3).B(b!2).B(b!1)
%     x(28) = A(b1!1,b2!2,b3!3,b4!4,b5).B(b!4).B(b!3).B(b!2).B(b!1)
%     x(29) = A(b1!1,b2!2,b3!3,b4,b5!4).B(b!4).B(b!3).B(b!2).B(b!1)
%     x(30) = A(b1!1,b2!2,b3,b4!3,b5!4).B(b!4).B(b!3).B(b!2).B(b!1)
%     x(31) = A(b1!1,b2,b3!2,b4!3,b5!4).B(b!4).B(b!3).B(b!2).B(b!1)
%     x(32) = A(b1,b2!1,b3!2,b4!3,b5!4).B(b!4).B(b!3).B(b!2).B(b!1)
%     x(33) = A(b1!1,b2!2,b3!3,b4!4,b5!5).B(b!5).B(b!4).B(b!3).B(b!2).B(b!1)


function replicatedBindingSite5Asymm_Pontryagin()

	global dt 


	% Number of variables
	sVars = 33; 
	% Number of controls
	uVars = 3; 
	% Plot flag
	doPlot = 0;
	% 	The uncertain parameter kBind1 belongs to [9.9,10.0];
	% 	The uncertain parameter kBind2 belongs to [9.8,9.9];
	% 	The uncertain parameter kUnbind1 belongs to [0.08,0.1];
	% Upper control boundaries
	u_min=[ 9.9 9.8 0.08 ];
	% Lower control boundaries
	u_max=[ 10.0 9.9 0.1 ];

	%Initial condition
	x0=[  0.0437, 0.0454, 0.0107, 0.0279, 0.0254, 0.0369, 0.0405, 0.0431, 0.0157, 0.0388, 0.0374, 0.0093, 0.0068, 0.0284, 0.0547, 0.0194, 0.0334, 0.0128, 0.0429, 0.0146, 0.0289, 0.0399, 0.0508, 0.0547, 0.0312, 0.0079, 0.0085, 0.0147, 0.048, 0.0145, 0.0465, 0.0139, 0.053 ];
	% Vector of coefficients of the sum of variables
	vcoeff=[ 0 1.0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ];
	% Finite time horizon
	T=0.2;
	% Integration time step
	dt=0.002;
	% Intergation intervals
	tspan = 0 : dt : T;
	tspanRev = T : -dt : 0;


	% Algorithm parameters
	maximize = 1;
	minimize = 0;
	delta = -1.0; % threshold
	max_iter = 20; % maximal number of algorithm iterations
	step = 50.0;
	gamma = step*ones(1,max_iter); % step-sizes of the correction algorithm

	x = sym('x', [sVars 1]);
	u = sym('u', [uVars 1]);
	p = sym('p', [sVars 1]);
	f = sym('f', [sVars 1]);


	% Symbolic ODE drift vector
	f(1) = (-u(1))*x(1)*x(2)+(-u(2))*x(1)*x(2)+(-10)*x(1)*x(2)+(-10.0004)*x(1)*x(2)+(-10.0008)*x(1)*x(2)+u(3)*x(3)+0.1*x(4)+0.1*x(5)+0.1*x(6)+0.1*x(7);
	f(2) = (-u(1))*x(1)*x(2)+(-u(2))*x(1)*x(2)+(-10)*x(1)*x(2)+(-10.0004)*x(1)*x(2)+(-10.0008)*x(1)*x(2)+(-u(1))*x(2)*x(4)+(-u(1))*x(2)*x(5)+(-u(1))*x(2)*x(6)+(-u(1))*x(2)*x(7)+u(3)*x(3)+(-u(2))*x(2)*x(3)+(-u(2))*x(2)*x(5)+(-u(2))*x(2)*x(6)+(-u(2))*x(2)*x(7)+0.1*x(4)+(-10)*x(2)*x(3)+(-10)*x(2)*x(4)+(-10)*x(2)*x(6)+(-10)*x(2)*x(7)+0.1*x(5)+(-10.0004)*x(2)*x(3)+(-10.0004)*x(2)*x(4)+(-10.0004)*x(2)*x(5)+(-10.0004)*x(2)*x(7)+0.1*x(6)+(-10.0008)*x(2)*x(3)+(-10.0008)*x(2)*x(4)+(-10.0008)*x(2)*x(5)+(-10.0008)*x(2)*x(6)+0.1*x(7)+(-u(1))*x(2)*x(12)+(-u(1))*x(2)*x(13)+(-u(1))*x(2)*x(14)+(-u(1))*x(2)*x(15)+(-u(1))*x(2)*x(16)+(-u(1))*x(2)*x(17)+u(3)*x(8)+u(3)*x(9)+u(3)*x(10)+u(3)*x(11)+(-u(2))*x(2)*x(9)+(-u(2))*x(2)*x(10)+(-u(2))*x(2)*x(11)+(-u(2))*x(2)*x(15)+(-u(2))*x(2)*x(16)+(-u(2))*x(2)*x(17)+0.1*x(8)+0.1*x(12)+0.1*x(13)+0.1*x(14)+(-10)*x(2)*x(8)+(-10)*x(2)*x(10)+(-10)*x(2)*x(11)+(-10)*x(2)*x(13)+(-10)*x(2)*x(14)+(-10)*x(2)*x(17)+0.1*x(9)+0.1*x(12)+0.1*x(15)+0.1*x(16)+(-10.0004)*x(2)*x(8)+(-10.0004)*x(2)*x(9)+(-10.0004)*x(2)*x(11)+(-10.0004)*x(2)*x(12)+(-10.0004)*x(2)*x(14)+(-10.0004)*x(2)*x(16)+0.1*x(10)+0.1*x(13)+0.1*x(15)+0.1*x(17)+(-10.0008)*x(2)*x(8)+(-10.0008)*x(2)*x(9)+(-10.0008)*x(2)*x(10)+(-10.0008)*x(2)*x(12)+(-10.0008)*x(2)*x(13)+(-10.0008)*x(2)*x(15)+0.1*x(11)+0.1*x(14)+0.1*x(16)+0.1*x(17)+(-u(1))*x(2)*x(24)+(-u(1))*x(2)*x(25)+(-u(1))*x(2)*x(26)+(-u(1))*x(2)*x(27)+u(3)*x(18)+u(3)*x(19)+u(3)*x(20)+u(3)*x(21)+u(3)*x(22)+u(3)*x(23)+(-u(2))*x(2)*x(21)+(-u(2))*x(2)*x(22)+(-u(2))*x(2)*x(23)+(-u(2))*x(2)*x(27)+0.1*x(18)+0.1*x(19)+0.1*x(20)+0.1*x(24)+0.1*x(25)+0.1*x(26)+(-10)*x(2)*x(19)+(-10)*x(2)*x(20)+(-10)*x(2)*x(23)+(-10)*x(2)*x(26)+0.1*x(18)+0.1*x(21)+0.1*x(22)+0.1*x(24)+0.1*x(25)+0.1*x(27)+(-10.0004)*x(2)*x(18)+(-10.0004)*x(2)*x(20)+(-10.0004)*x(2)*x(22)+(-10.0004)*x(2)*x(25)+0.1*x(19)+0.1*x(21)+0.1*x(23)+0.1*x(24)+0.1*x(26)+0.1*x(27)+(-10.0008)*x(2)*x(18)+(-10.0008)*x(2)*x(19)+(-10.0008)*x(2)*x(21)+(-10.0008)*x(2)*x(24)+0.1*x(20)+0.1*x(22)+0.1*x(23)+0.1*x(25)+0.1*x(26)+0.1*x(27)+(-u(1))*x(2)*x(32)+u(3)*x(28)+u(3)*x(29)+u(3)*x(30)+u(3)*x(31)+(-u(2))*x(2)*x(31)+0.1*x(28)+0.1*x(29)+0.1*x(30)+0.1*x(32)+(-10)*x(2)*x(30)+0.1*x(28)+0.1*x(29)+0.1*x(31)+0.1*x(32)+(-10.0004)*x(2)*x(29)+0.1*x(28)+0.1*x(30)+0.1*x(31)+0.1*x(32)+(-10.0008)*x(2)*x(28)+0.1*x(29)+0.1*x(30)+0.1*x(31)+0.1*x(32)+u(3)*x(33)+0.1*x(33)+0.1*x(33)+0.1*x(33)+0.1*x(33);
	f(3) = u(1)*x(1)*x(2)+(-u(3))*x(3)+(-u(2))*x(2)*x(3)+(-10)*x(2)*x(3)+(-10.0004)*x(2)*x(3)+(-10.0008)*x(2)*x(3)+0.1*x(8)+0.1*x(9)+0.1*x(10)+0.1*x(11);
	f(4) = u(2)*x(1)*x(2)+(-u(1))*x(2)*x(4)+(-0.1)*x(4)+(-10)*x(2)*x(4)+(-10.0004)*x(2)*x(4)+(-10.0008)*x(2)*x(4)+u(3)*x(8)+0.1*x(12)+0.1*x(13)+0.1*x(14);
	f(5) = 10*x(1)*x(2)+(-u(1))*x(2)*x(5)+(-u(2))*x(2)*x(5)+(-0.1)*x(5)+(-10.0004)*x(2)*x(5)+(-10.0008)*x(2)*x(5)+u(3)*x(9)+0.1*x(12)+0.1*x(15)+0.1*x(16);
	f(6) = 10.0004*x(1)*x(2)+(-u(1))*x(2)*x(6)+(-u(2))*x(2)*x(6)+(-10)*x(2)*x(6)+(-0.1)*x(6)+(-10.0008)*x(2)*x(6)+u(3)*x(10)+0.1*x(13)+0.1*x(15)+0.1*x(17);
	f(7) = 10.0008*x(1)*x(2)+(-u(1))*x(2)*x(7)+(-u(2))*x(2)*x(7)+(-10)*x(2)*x(7)+(-10.0004)*x(2)*x(7)+(-0.1)*x(7)+u(3)*x(11)+0.1*x(14)+0.1*x(16)+0.1*x(17);
	f(8) = u(1)*x(2)*x(4)+u(2)*x(2)*x(3)+(-u(3))*x(8)+(-0.1)*x(8)+(-10)*x(2)*x(8)+(-10.0004)*x(2)*x(8)+(-10.0008)*x(2)*x(8)+0.1*x(18)+0.1*x(19)+0.1*x(20);
	f(9) = u(1)*x(2)*x(5)+10*x(2)*x(3)+(-u(3))*x(9)+(-u(2))*x(2)*x(9)+(-0.1)*x(9)+(-10.0004)*x(2)*x(9)+(-10.0008)*x(2)*x(9)+0.1*x(18)+0.1*x(21)+0.1*x(22);
	f(10) = u(1)*x(2)*x(6)+10.0004*x(2)*x(3)+(-u(3))*x(10)+(-u(2))*x(2)*x(10)+(-10)*x(2)*x(10)+(-0.1)*x(10)+(-10.0008)*x(2)*x(10)+0.1*x(19)+0.1*x(21)+0.1*x(23);
	f(11) = u(1)*x(2)*x(7)+10.0008*x(2)*x(3)+(-u(3))*x(11)+(-u(2))*x(2)*x(11)+(-10)*x(2)*x(11)+(-10.0004)*x(2)*x(11)+(-0.1)*x(11)+0.1*x(20)+0.1*x(22)+0.1*x(23);
	f(12) = u(2)*x(2)*x(5)+10*x(2)*x(4)+(-u(1))*x(2)*x(12)+(-0.1)*x(12)+(-0.1)*x(12)+(-10.0004)*x(2)*x(12)+(-10.0008)*x(2)*x(12)+u(3)*x(18)+0.1*x(24)+0.1*x(25);
	f(13) = u(2)*x(2)*x(6)+10.0004*x(2)*x(4)+(-u(1))*x(2)*x(13)+(-0.1)*x(13)+(-10)*x(2)*x(13)+(-0.1)*x(13)+(-10.0008)*x(2)*x(13)+u(3)*x(19)+0.1*x(24)+0.1*x(26);
	f(14) = u(2)*x(2)*x(7)+10.0008*x(2)*x(4)+(-u(1))*x(2)*x(14)+(-0.1)*x(14)+(-10)*x(2)*x(14)+(-10.0004)*x(2)*x(14)+(-0.1)*x(14)+u(3)*x(20)+0.1*x(25)+0.1*x(26);
	f(15) = 10*x(2)*x(6)+10.0004*x(2)*x(5)+(-u(1))*x(2)*x(15)+(-u(2))*x(2)*x(15)+(-0.1)*x(15)+(-0.1)*x(15)+(-10.0008)*x(2)*x(15)+u(3)*x(21)+0.1*x(24)+0.1*x(27);
	f(16) = 10*x(2)*x(7)+10.0008*x(2)*x(5)+(-u(1))*x(2)*x(16)+(-u(2))*x(2)*x(16)+(-0.1)*x(16)+(-10.0004)*x(2)*x(16)+(-0.1)*x(16)+u(3)*x(22)+0.1*x(25)+0.1*x(27);
	f(17) = 10.0004*x(2)*x(7)+10.0008*x(2)*x(6)+(-u(1))*x(2)*x(17)+(-u(2))*x(2)*x(17)+(-10)*x(2)*x(17)+(-0.1)*x(17)+(-0.1)*x(17)+u(3)*x(23)+0.1*x(26)+0.1*x(27);
	f(18) = u(1)*x(2)*x(12)+u(2)*x(2)*x(9)+10*x(2)*x(8)+(-u(3))*x(18)+(-0.1)*x(18)+(-0.1)*x(18)+(-10.0004)*x(2)*x(18)+(-10.0008)*x(2)*x(18)+0.1*x(28)+0.1*x(29);
	f(19) = u(1)*x(2)*x(13)+u(2)*x(2)*x(10)+10.0004*x(2)*x(8)+(-u(3))*x(19)+(-0.1)*x(19)+(-10)*x(2)*x(19)+(-0.1)*x(19)+(-10.0008)*x(2)*x(19)+0.1*x(28)+0.1*x(30);
	f(20) = u(1)*x(2)*x(14)+u(2)*x(2)*x(11)+10.0008*x(2)*x(8)+(-u(3))*x(20)+(-0.1)*x(20)+(-10)*x(2)*x(20)+(-10.0004)*x(2)*x(20)+(-0.1)*x(20)+0.1*x(29)+0.1*x(30);
	f(21) = u(1)*x(2)*x(15)+10*x(2)*x(10)+10.0004*x(2)*x(9)+(-u(3))*x(21)+(-u(2))*x(2)*x(21)+(-0.1)*x(21)+(-0.1)*x(21)+(-10.0008)*x(2)*x(21)+0.1*x(28)+0.1*x(31);
	f(22) = u(1)*x(2)*x(16)+10*x(2)*x(11)+10.0008*x(2)*x(9)+(-u(3))*x(22)+(-u(2))*x(2)*x(22)+(-0.1)*x(22)+(-10.0004)*x(2)*x(22)+(-0.1)*x(22)+0.1*x(29)+0.1*x(31);
	f(23) = u(1)*x(2)*x(17)+10.0004*x(2)*x(11)+10.0008*x(2)*x(10)+(-u(3))*x(23)+(-u(2))*x(2)*x(23)+(-10)*x(2)*x(23)+(-0.1)*x(23)+(-0.1)*x(23)+0.1*x(30)+0.1*x(31);
	f(24) = u(2)*x(2)*x(15)+10*x(2)*x(13)+10.0004*x(2)*x(12)+(-u(1))*x(2)*x(24)+(-0.1)*x(24)+(-0.1)*x(24)+(-0.1)*x(24)+(-10.0008)*x(2)*x(24)+u(3)*x(28)+0.1*x(32);
	f(25) = u(2)*x(2)*x(16)+10*x(2)*x(14)+10.0008*x(2)*x(12)+(-u(1))*x(2)*x(25)+(-0.1)*x(25)+(-0.1)*x(25)+(-10.0004)*x(2)*x(25)+(-0.1)*x(25)+u(3)*x(29)+0.1*x(32);
	f(26) = u(2)*x(2)*x(17)+10.0004*x(2)*x(14)+10.0008*x(2)*x(13)+(-u(1))*x(2)*x(26)+(-0.1)*x(26)+(-10)*x(2)*x(26)+(-0.1)*x(26)+(-0.1)*x(26)+u(3)*x(30)+0.1*x(32);
	f(27) = 10*x(2)*x(17)+10.0004*x(2)*x(16)+10.0008*x(2)*x(15)+(-u(1))*x(2)*x(27)+(-u(2))*x(2)*x(27)+(-0.1)*x(27)+(-0.1)*x(27)+(-0.1)*x(27)+u(3)*x(31)+0.1*x(32);
	f(28) = u(1)*x(2)*x(24)+u(2)*x(2)*x(21)+10*x(2)*x(19)+10.0004*x(2)*x(18)+(-u(3))*x(28)+(-0.1)*x(28)+(-0.1)*x(28)+(-0.1)*x(28)+(-10.0008)*x(2)*x(28)+0.1*x(33);
	f(29) = u(1)*x(2)*x(25)+u(2)*x(2)*x(22)+10*x(2)*x(20)+10.0008*x(2)*x(18)+(-u(3))*x(29)+(-0.1)*x(29)+(-0.1)*x(29)+(-10.0004)*x(2)*x(29)+(-0.1)*x(29)+0.1*x(33);
	f(30) = u(1)*x(2)*x(26)+u(2)*x(2)*x(23)+10.0004*x(2)*x(20)+10.0008*x(2)*x(19)+(-u(3))*x(30)+(-0.1)*x(30)+(-10)*x(2)*x(30)+(-0.1)*x(30)+(-0.1)*x(30)+0.1*x(33);
	f(31) = u(1)*x(2)*x(27)+10*x(2)*x(23)+10.0004*x(2)*x(22)+10.0008*x(2)*x(21)+(-u(3))*x(31)+(-u(2))*x(2)*x(31)+(-0.1)*x(31)+(-0.1)*x(31)+(-0.1)*x(31)+0.1*x(33);
	f(32) = u(2)*x(2)*x(27)+10*x(2)*x(26)+10.0004*x(2)*x(25)+10.0008*x(2)*x(24)+(-u(1))*x(2)*x(32)+(-0.1)*x(32)+(-0.1)*x(32)+(-0.1)*x(32)+(-0.1)*x(32)+u(3)*x(33);
	f(33) = u(1)*x(2)*x(32)+u(2)*x(2)*x(31)+10*x(2)*x(30)+10.0004*x(2)*x(29)+10.0008*x(2)*x(28)+(-u(3))*x(33)+(-0.1)*x(33)+(-0.1)*x(33)+(-0.1)*x(33)+(-0.1)*x(33);


	initpontryagin(f,p,x,u);

	cHeader = { 'kBind1' 'kBind2' 'kUnbind1'	 };
	pontryagin(maximize,vcoeff,max_iter,delta,uVars,cHeader,gamma,tspan,tspanRev,x0,u_max,u_min,'replicatedBindingSite5Asymm_Pontryagin_max.csv',doPlot);
	pontryagin(minimize,vcoeff,max_iter,delta,uVars,cHeader,gamma,tspan,tspanRev,x0,u_max,u_min,'replicatedBindingSite5Asymm_Pontryagin_min.csv',doPlot);

	exit;


end
function initpontryagin(f,p,x,u)

     global htf
     global p_ind_Hu
     global x_ind_Hu
     global htHu
     global htHx
     global x_ind_Hx
     global u_ind_Hx
     
    
    
    % Numeric ODE drift vector 
    htf = matlabFunction(f); 
    
    % Compute the symbolic Hamiltonian 
    %H = dot(p,f); %more ellegant but introduces conjugates
    sym H;
    H = 0;
    for i = 1 : size(f,1)
        H = H + p(i)*f(i);
    end
       
    
    % Symbolic drift of the costate p    
    Hx = -jacobian(H, x);     
    HxVars = symvar(Hx);
    % Compute the indices of x appearing in Hx
    x_ind_Hx = [];
    for i = 1 : size(x,1)
        for j = 1 : size(HxVars,2)
            if(isequal(x(i),HxVars(j)))
                x_ind_Hx = [x_ind_Hx , i];
                break;
            end
        end
    end
    % Compute the indices of u appearing in Hx
    u_ind_Hx = [];
    for i = 1 : size(u,1)
        for j = 1 : size(HxVars,2)
            if(isequal(u(i),HxVars(j)))
                u_ind_Hx = [u_ind_Hx , i];
                break;
            end
        end
    end        
    % Numeric drift of the costate p
    htHx = matlabFunction(Hx);
    

    % Symbolic correction of control u
    Hu = -jacobian(H, u);   
    HuVars = symvar(Hu);    
    % Since we assume that the drift is linear in controls, the indices of
    % u do not have to be computed (because there are no u variables in Hu)    
    % Compute the indices of x appearing in Hu
    x_ind_Hu = [];
    for i = 1 : size(x,1)
        for j = 1 : size(HuVars,2)
            if(isequal(x(i),HuVars(j)))
                x_ind_Hu = [x_ind_Hu , i];
                break;
            end
        end
    end
    % Compute the indices of p appearing in Hu
    p_ind_Hu = [];
    for i = 1 : size(p,1)
        for j = 1 : size(HuVars,2)
            if(isequal(p(i),HuVars(j)))
                p_ind_Hu = [p_ind_Hu , i];
                break;
            end
        end
    end
    % Numeric correction of control u
    htHu = matlabFunction(Hu);

end


function pontryagin(maximize,vcoeff,max_iter,delta,uVars,cHeader,gamma,tspan,tspanRev,x0,u_max,u_min,csvfile,doPlot)

     global x_num
     global u_num
     global p_ind_Hu
     global x_ind_Hu
     global htHu
    

     if(maximize)
         % Boundary condition of the costate
        pT = - vcoeff;
     else
        %Use the following if interested in minimizing
        pT = vcoeff;
     end
        
     

    delta_u_num = zeros(uVars,size(tspan,2));
	new_u_num = zeros(uVars,size(tspan,2));
    
    u_num = zeros(uVars,size(tspan,2));
    for i = 1 : uVars
        u_num(i,:) = ((u_max(i) + u_min(i)) / 2) .* ones(1,size(tspan,2));
    end
    
    
    % Gradient based Pontryagin algorithm for the correction of the 
    % optimal control
    corr = inf;
    tic;
    for iter = 1 : max_iter
        if(corr <= delta)
            break;
        end
        corr = 0;
        
        [t,x_num] = ode45(@numf,tspan,x0);
        [t,p_num] = ode45(@numHx,tspanRev,pT);
        p_num = flipud(p_num);
        
        for j = 1 : size(tspan,2)
            % Compute the control change at time j
            p_num_aux = p_num(j,:);
            p_num_aux = p_num_aux(p_ind_Hu);
            p_cell = num2cell(p_num_aux);
            
            x_num_aux = x_num(j,:);
            x_num_aux = x_num_aux(x_ind_Hu);
            x_cell = num2cell(x_num_aux);
            
            delta_u_num(:,j) = htHu(p_cell{:},x_cell{:});            
            new_u_num(:,j) = u_num(:,j) + gamma(iter) .* delta_u_num(:,j);

            % Project the new controls to the control space at time j
            new_u_num(:,j) = min(new_u_num(:,j), u_max');
            new_u_num(:,j) = max(new_u_num(:,j), u_min');
            
            % Compute the norm of the correction vector at time j
            aux = norm(new_u_num(:,j) - u_num(:,j),'inf');
            if(aux > corr)
                corr = aux;
            end            
        end    
        
        u_num = new_u_num;
    end
    %fprintf('Computation time: %s', toc);
	
	m = size(u_num,1)+1;
    u_num2(1,1) = 0.0;
    u_num2(2:m,1) = u_num(:,1);
    ind = 2;
    for i=2:size(u_num,2)-1
        if u_num(:,i) ~= u_num(:,i-1)
            u_num2(1,ind) = tspan(i);
            u_num2(2:m,ind) = u_num(:,i);
	    ind = ind + 1;
        end
    end
    u_numTransp = u_num2';
	%u_numTransp = u_num';
	 
	commaHeader = [cHeader;repmat({','},1,numel(cHeader))]; %insert commaas
	commaHeader = commaHeader(:)';
	textHeader = cell2mat(commaHeader); %cHeader in text with commas
	%write header to file
	fid = fopen(csvfile,'w');
	fprintf(fid,'%s\n',textHeader);
	fclose(fid);
	%write data to end of file
	dlmwrite(csvfile,u_numTransp, 'precision', '%.8i','-append');
    
    % After the grandient algorithm has finished, u_num stores the optimal 
    % control candidate    
    if(doPlot == 1)        
        % Plot the optimal control candidate and the underlying ODE solution
        [t,x_num] = ode45(@numf,tspan,x0);    
        %figure(03)
        figure()
        %iptsetpref('ImshowBorder','tight');                            
        plot(tspan,x_num);    
        %figure(04)
        figure()
        %iptsetpref('ImshowBorder','tight');                            
        plot(tspan,u_num);       
    end

end
function dx = numf(t,x)

    global u_num
    global htf
    global dt    
    
    i = max(floor(t / dt),1);    
    u = u_num(:,i);  
    u_cell = num2cell(u);
    x_cell = num2cell(x);
    dx = htf(u_cell{:},x_cell{:});
end


function dp = numHx(t,p)

    global u_num
    global x_num
    global htHx
    global x_ind_Hx    
    global u_ind_Hx      
    global dt    
    
    i = max(floor(t / dt),1);    
    u = u_num(:,i);   
    u = u(u_ind_Hx);
    u_cell = num2cell(u);
    x = x_num(i,:);
    x = x(x_ind_Hx);    
    x_cell = num2cell(x);
    
    p_cell = num2cell(p);    

    dp = htHx(p_cell{:},u_cell{:}, x_cell{:})';
end


