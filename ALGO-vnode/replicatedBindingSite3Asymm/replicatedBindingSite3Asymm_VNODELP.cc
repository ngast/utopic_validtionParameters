///////////////////////////////////////////////////////////////////////////////////////////////////
// Reachability analysis of the system replicatedBindingSite3AsymmODE with 3 uncertain parameters %
///////////////////////////////////////////////////////////////////////////////////////////////////

// Automatically generated from replicatedBindingSite3AsymmODE.
//// Number of species: 9.
// Number of reactions: 9.
// Coefficients:  0 1.0 0 0 0 0 0 0 0.
// Perturbed parameters: kBind1 in [9.9,10.0], kBind2 in [9.8,9.9], kUnbind1 in [0.08,0.1]

// Correspondence with original names:
//     y(1) = A(b1,b2,b3)
//     y(2) = B(b)
//     y(3) = A(b1!1,b2,b3).B(b!1)
//     y(4) = A(b1,b2!1,b3).B(b!1)
//     y(5) = A(b1,b2,b3!1).B(b!1)
//     y(6) = A(b1!1,b2!2,b3).B(b!2).B(b!1)
//     y(7) = A(b1!1,b2,b3!2).B(b!2).B(b!1)
//     y(8) = A(b1,b2!1,b3!2).B(b!2).B(b!1)
//     y(9) = A(b1!1,b2!2,b3!3).B(b!3).B(b!2).B(b!1)


/*74:*/
#line 54 "./binding3.w"

#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>
#include <string.h>
#include <stdlib.h>

#include "vnode.h"

struct
UncertainParameters{interval val[3];};


using namespace std;
using namespace vnodelp;

template<typename var_type> 
void drift(int n,var_type*yp,const var_type*y,var_type t,
void*param)
{
	UncertainParameters*p= (UncertainParameters*)param;


	interval kBind1 = p->val[0];
	interval kUnbind1 = p->val[2];
	interval kBind2 = p->val[1];
	interval kUnbind2 = 0.1;
	interval kBind3 = 10.01;
	interval kUnbind3 = 0.1;

	yp[0] = (-kBind1)*y[0]*y[1]+(-kBind2)*y[0]*y[1]+(-kBind3)*y[0]*y[1]+kUnbind1*y[2]+kUnbind2*y[3]+kUnbind3*y[4];
	yp[1] = (-kBind1)*y[0]*y[1]+(-kBind2)*y[0]*y[1]+(-kBind3)*y[0]*y[1]+(-kBind1)*y[1]*y[3]+(-kBind1)*y[1]*y[4]+kUnbind1*y[2]+(-kBind2)*y[1]*y[2]+(-kBind2)*y[1]*y[4]+kUnbind2*y[3]+(-kBind3)*y[1]*y[2]+(-kBind3)*y[1]*y[3]+kUnbind3*y[4]+(-kBind1)*y[1]*y[7]+kUnbind1*y[5]+kUnbind1*y[6]+(-kBind2)*y[1]*y[6]+kUnbind2*y[5]+kUnbind2*y[7]+(-kBind3)*y[1]*y[5]+kUnbind3*y[6]+kUnbind3*y[7]+kUnbind1*y[8]+kUnbind2*y[8]+kUnbind3*y[8];
	yp[2] = kBind1*y[0]*y[1]+(-kUnbind1)*y[2]+(-kBind2)*y[1]*y[2]+(-kBind3)*y[1]*y[2]+kUnbind2*y[5]+kUnbind3*y[6];
	yp[3] = kBind2*y[0]*y[1]+(-kBind1)*y[1]*y[3]+(-kUnbind2)*y[3]+(-kBind3)*y[1]*y[3]+kUnbind1*y[5]+kUnbind3*y[7];
	yp[4] = kBind3*y[0]*y[1]+(-kBind1)*y[1]*y[4]+(-kBind2)*y[1]*y[4]+(-kUnbind3)*y[4]+kUnbind1*y[6]+kUnbind2*y[7];
	yp[5] = kBind1*y[1]*y[3]+kBind2*y[1]*y[2]+(-kUnbind1)*y[5]+(-kUnbind2)*y[5]+(-kBind3)*y[1]*y[5]+kUnbind3*y[8];
	yp[6] = kBind1*y[1]*y[4]+kBind3*y[1]*y[2]+(-kUnbind1)*y[6]+(-kBind2)*y[1]*y[6]+(-kUnbind3)*y[6]+kUnbind2*y[8];
	yp[7] = kBind2*y[1]*y[4]+kBind3*y[1]*y[3]+(-kBind1)*y[1]*y[7]+(-kUnbind2)*y[7]+(-kUnbind3)*y[7]+kUnbind1*y[8];
	yp[8] = kBind1*y[1]*y[7]+kBind2*y[1]*y[6]+kBind3*y[1]*y[5]+(-kUnbind1)*y[8]+(-kUnbind2)*y[8]+(-kUnbind3)*y[8];
}


int main()
{
// size of the system
const int n= 9;


/*************************************************************************
*
* Computing maximum of the reachable set
*
*************************************************************************/

int m=0;
FILE *fp = fopen("replicatedBindingSite3Asymm_Pontryagin_max.csv","r");
char ch;
while (!feof(fp)){
  ch = fgetc(fp);
  if(ch == '\n'){
    m++;
  }
}
m--;
rewind(fp);

UncertainParameters p[m];
interval t= 0.0;
 
 
 
// getting u_max from file
iVector t_(m);
string line;
ifstream file("replicatedBindingSite3Asymm_Pontryagin_max.csv");
getline(file,line);
int j;
for (int i=0;i<m;i++){
   getline(file,line);
   std::stringstream    lineStream(line);
   string       cell;
   getline(lineStream,cell,',');
   if(i>0){
     t_[i-1]=string_to_interval(cell.c_str());
 
 
 
   }
 
   for(int j=0; getline(lineStream,cell,','); j++){
      p[i].val[j]=string_to_interval(cell.c_str());
   }
}
t_[m-1]=0.2; // horizon time value

// reachability problem parameters
iVector y(n), coef(n); 
y[0]=0.0676;
y[1]=0.1467;
y[2]=0.1269;
y[3]=0.1537;
y[4]=0.105;
y[5]=0.0057;
y[6]=0.136;
y[7]=0.1496;
y[8]=0.1087;
coef[0]=0.0;
coef[1]=1.0;
coef[2]=0.0;
coef[3]=0.0;
coef[4]=0.0;
coef[5]=0.0;
coef[6]=0.0;
coef[7]=0.0;
coef[8]=0.0;

// Verified ODE solver solution for u_max control
AD*myad;
VNODE*Solver;
for (int i=0; i<m ; i++){
 myad= new FADBAD_AD(n,drift,drift,&p[i]);
 Solver= new VNODE(myad);
 Solver->integrate(t,y,t_[i]);
 if(!Solver->successful()){
    cout<<"VNODE-LP could not reach t = "<<t_[i-1]<<endl;
    break;
 }
 delete myad, Solver; 
}


// print results
interval res=0.0;
cout<<"Maximum reachable point enclosure at t = "<<t_[m-1] <<endl;
for (int i=0;i<n;i++)
   res += coef[i]*y[i];
cout << res << endl;

/*************************************************************************
*
* Computing minimum of the reachable set 
*
*************************************************************************/


m=0;
fp = fopen("replicatedBindingSite3Asymm_Pontryagin_min.csv","r");
while (!feof(fp)){
  ch = fgetc(fp);
  if(ch == '\n'){
    m++;
  }
}
m--;
rewind(fp);

UncertainParameters p2[m];
t= 0.0;
 
 
// getting u_min from file
iVector t2(m);
ifstream file2("replicatedBindingSite3Asymm_Pontryagin_min.csv");

getline(file2,line);
 
for (int i=0;i<m;i++){
   getline(file2,line);
   std::stringstream    lineStream(line);
   string       cell2;
   getline(lineStream,cell2,',');
   if(i>0){
     t2[i-1]=string_to_interval(cell2.c_str());
   }
 
   for(int j=0; getline(lineStream,cell2,','); j++){
      p2[i].val[j]=string_to_interval(cell2.c_str());
   }
}
t2[m-1]=0.2; // horizon time value

// reachability problem parameters
y[0]=0.0676;
y[1]=0.1467;
y[2]=0.1269;
y[3]=0.1537;
y[4]=0.105;
y[5]=0.0057;
y[6]=0.136;
y[7]=0.1496;
y[8]=0.1087;



// Verified ODE solver solution for u_max control
for (int i=0; i<m ; i++){
 myad= new FADBAD_AD(n,drift,drift,&p2[i]);
 Solver= new VNODE(myad);
 Solver->integrate(t,y,t2[i]);
 if(!Solver->successful()){
    cout<<"VNODE-LP could not reach t = "<<t2[i-1]<<endl;
    break;
 }
 delete myad, Solver; 
}

// print results
res=0.0;
cout<<"Minimum reachable point enclosure at t = "<<t_[m-1] <<endl;
for (int i=0;i<n;i++)
   res += coef[i]*y[i];
cout << res << endl;

return 0;
}

