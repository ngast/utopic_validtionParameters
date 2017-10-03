/*74:*/
#line 54 "./binding4.w"

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
 interval kUnbind2 = 0.1, kBind3 = 10.01, kUnbind3 = 0.1;
 interval kBind4 = 10.001, kUnbind4 = 0.1;


	yp[0] = ((0.0 - kBind4)+(0.0 - kBind3)+(0.0 - kBind1)+(0.0 - kBind2))*y[0]*y[1] + kUnbind1*y[2] + kUnbind2*y[3] + kUnbind3*y[4] + kUnbind4*y[5];
	yp[1] = ((0.0 - kBind4)+(0.0 - kBind3)+(0.0 - kBind1)+(0.0 - kBind2))*y[0]*y[1] + ((0.0 - kBind4)+(0.0 - kBind3)+(0.0 - kBind2))*y[1]*y[2] + ((0.0 - kBind4)+(0.0 - kBind3)+(0.0 - kBind1))*y[1]*y[3] + ((0.0 - kBind4)+(0.0 - kBind1)+(0.0 - kBind2))*y[1]*y[4] + ((0.0 - kBind3)+(0.0 - kBind1)+(0.0 - kBind2))*y[1]*y[5] + ((0.0 - kBind4)+(0.0 - kBind3))*y[1]*y[6] + ((0.0 - kBind4)+(0.0 - kBind2))*y[1]*y[7] + ((0.0 - kBind3)+(0.0 - kBind2))*y[1]*y[8] + ((0.0 - kBind4)+(0.0 - kBind1))*y[1]*y[9] + ((0.0 - kBind3)+(0.0 - kBind1))*y[1]*y[10] + ((0.0 - kBind1)+(0.0 - kBind2))*y[1]*y[11] + ((0.0 - kBind4))*y[1]*y[12] + ((0.0 - kBind3))*y[1]*y[13] + ((0.0 - kBind2))*y[1]*y[14] + ((0.0 - kBind1))*y[1]*y[15] + kUnbind1*y[2] + kUnbind2*y[3] + kUnbind3*y[4] + kUnbind4*y[5] + (kUnbind1+kUnbind2)*y[6] + (kUnbind1+kUnbind3)*y[7] + (kUnbind1+kUnbind4)*y[8] + (kUnbind2+kUnbind3)*y[9] + (kUnbind2+kUnbind4)*y[10] + (kUnbind3+kUnbind4)*y[11] + (kUnbind1+kUnbind2+kUnbind3)*y[12] + (kUnbind1+kUnbind2+kUnbind4)*y[13] + (kUnbind1+kUnbind3+kUnbind4)*y[14] + (kUnbind2+kUnbind3+kUnbind4)*y[15] + (kUnbind1+kUnbind2+kUnbind3+kUnbind4)*y[16];
	yp[2] = kBind1*y[0]*y[1] + ((0.0 - kBind4)+(0.0 - kBind3)+(0.0 - kBind2))*y[1]*y[2] + ((0.0 - kUnbind1))*y[2] + kUnbind2*y[6] + kUnbind3*y[7] + kUnbind4*y[8];
	yp[3] = kBind2*y[0]*y[1] + ((0.0 - kBind4)+(0.0 - kBind3)+(0.0 - kBind1))*y[1]*y[3] + ((0.0 - kUnbind2))*y[3] + kUnbind1*y[6] + kUnbind3*y[9] + kUnbind4*y[10];
	yp[4] = kBind3*y[0]*y[1] + ((0.0 - kBind4)+(0.0 - kBind1)+(0.0 - kBind2))*y[1]*y[4] + ((0.0 - kUnbind3))*y[4] + kUnbind1*y[7] + kUnbind2*y[9] + kUnbind4*y[11];
	yp[5] = kBind4*y[0]*y[1] + ((0.0 - kBind3)+(0.0 - kBind1)+(0.0 - kBind2))*y[1]*y[5] + ((0.0 - kUnbind4))*y[5] + kUnbind1*y[8] + kUnbind2*y[10] + kUnbind3*y[11];
	yp[6] = kBind2*y[1]*y[2] + kBind1*y[1]*y[3] + ((0.0 - kBind4)+(0.0 - kBind3))*y[1]*y[6] + ((0.0 - kUnbind1)+(0.0 - kUnbind2))*y[6] + kUnbind3*y[12] + kUnbind4*y[13];
	yp[7] = kBind3*y[1]*y[2] + kBind1*y[1]*y[4] + ((0.0 - kBind4)+(0.0 - kBind2))*y[1]*y[7] + ((0.0 - kUnbind1)+(0.0 - kUnbind3))*y[7] + kUnbind2*y[12] + kUnbind4*y[14];
	yp[8] = kBind4*y[1]*y[2] + kBind1*y[1]*y[5] + ((0.0 - kBind3)+(0.0 - kBind2))*y[1]*y[8] + ((0.0 - kUnbind1)+(0.0 - kUnbind4))*y[8] + kUnbind2*y[13] + kUnbind3*y[14];
	yp[9] = kBind3*y[1]*y[3] + kBind2*y[1]*y[4] + ((0.0 - kBind4)+(0.0 - kBind1))*y[1]*y[9] + ((0.0 - kUnbind2)+(0.0 - kUnbind3))*y[9] + kUnbind1*y[12] + kUnbind4*y[15];
	yp[10] = kBind4*y[1]*y[3] + kBind2*y[1]*y[5] + ((0.0 - kBind3)+(0.0 - kBind1))*y[1]*y[10] + ((0.0 - kUnbind2)+(0.0 - kUnbind4))*y[10] + kUnbind1*y[13] + kUnbind3*y[15];
	yp[11] = kBind4*y[1]*y[4] + kBind3*y[1]*y[5] + ((0.0 - kBind1)+(0.0 - kBind2))*y[1]*y[11] + ((0.0 - kUnbind3)+(0.0 - kUnbind4))*y[11] + kUnbind1*y[14] + kUnbind2*y[15];
	yp[12] = kBind3*y[1]*y[6] + kBind2*y[1]*y[7] + kBind1*y[1]*y[9] + ((0.0 - kBind4))*y[1]*y[12] + ((0.0 - kUnbind1)+(0.0 - kUnbind2)+(0.0 - kUnbind3))*y[12] + kUnbind4*y[16];
	yp[13] = kBind4*y[1]*y[6] + kBind2*y[1]*y[8] + kBind1*y[1]*y[10] + ((0.0 - kBind3))*y[1]*y[13] + ((0.0 - kUnbind1)+(0.0 - kUnbind2)+(0.0 - kUnbind4))*y[13] + kUnbind3*y[16];
	yp[14] = kBind4*y[1]*y[7] + kBind3*y[1]*y[8] + kBind1*y[1]*y[11] + ((0.0 - kBind2))*y[1]*y[14] + ((0.0 - kUnbind1)+(0.0 - kUnbind3)+(0.0 - kUnbind4))*y[14] + kUnbind2*y[16];
	yp[15] = kBind4*y[1]*y[9] + kBind3*y[1]*y[10] + kBind2*y[1]*y[11] + ((0.0 - kBind1))*y[1]*y[15] + ((0.0 - kUnbind2)+(0.0 - kUnbind3)+(0.0 - kUnbind4))*y[15] + kUnbind1*y[16];
	yp[16] = kBind4*y[1]*y[12] + kBind3*y[1]*y[13] + kBind2*y[1]*y[14] + kBind1*y[1]*y[15] + ((0.0 - kUnbind1)+(0.0 - kUnbind2)+(0.0 - kUnbind3)+(0.0 - kUnbind4))*y[16];
}



int main()
{
// size of the system
const int n= 17;


/*************************************************************************
*
* Computing maximum of the reachable set 
*
*************************************************************************/

// number of changes of u_max control
int m=0;
FILE *fp = fopen("replicatedBindingSite4Asymm_Pontryagin_max.csv","r");
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
ifstream file("replicatedBindingSite4Asymm_Pontryagin_max.csv");
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
y[0]=0.1008; y[1]=0.0988; y[2]=0.0522;
y[3]=0.0872; y[4]=0.0228; y[5]=0.0939;
y[6]=0.0042; y[7]=0.0368; y[8]=0.0061; y[9]=0.0129;
y[10]=0.1095; y[11]=0.0924; y[12]=0.0422;
y[13]=0.1264; y[14]=0.0046; y[15]=0.0584;
y[16]=0.0508;
coef[0]=0.0; coef[1]=1.0; coef[2]=0.0;
coef[3]=0.0; coef[4]=0.0; coef[5]=0.0; 
coef[6]=0.0; coef[7]=0.0; coef[8]=0.0; coef[9]=0.0;
coef[10]=0.0; coef[11]=0.0; coef[12]=0.0;
coef[13]=0.0; coef[14]=0.0; coef[15]=0.0; 
coef[16]=0.0;

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

// number of changes of u_min control
m=0;
fp = fopen("replicatedBindingSite4Asymm_Pontryagin_min.csv","r");
while (!feof(fp)){
  ch = fgetc(fp);
  if(ch == '\n')
    m++;
}
m--;
rewind(fp);

UncertainParameters p2[m];
iVector t2(m);

// getting u_min from file
ifstream file2("replicatedBindingSite4Asymm_Pontryagin_min.csv");
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
y[0]=0.1008; y[1]=0.0988; y[2]=0.0522;
y[3]=0.0872; y[4]=0.0228; y[5]=0.0939;
y[6]=0.0042; y[7]=0.0368; y[8]=0.0061; y[9]=0.0129;
y[10]=0.1095; y[11]=0.0924; y[12]=0.0422;
y[13]=0.1264; y[14]=0.0046; y[15]=0.0584;
y[16]=0.0508;

// Verified ODE solver solution for u_min control
t=0.0;
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
cout<<"Minimum reachable point enclosure at t = "<<t2[m-1] <<endl;
for (int i=0;i<n;i++)
   res += coef[i]*y[i];
cout << res << endl;

return 0;
}

