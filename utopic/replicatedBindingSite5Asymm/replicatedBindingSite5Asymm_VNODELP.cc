/*74:*/
#line 54 "./binding5.w"

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
 interval kBind4 = 10.001, kUnbind4 = 0.1, kBind5 = 10.001, kUnbind5 = 0.1;

	yp[0] = ((0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind3)+(0.0 - kBind2)+(0.0 - kBind1))*y[0]*y[1] + kUnbind1*y[2] + kUnbind2*y[3] + kUnbind3*y[4] + kUnbind4*y[5] + kUnbind5*y[6];
	yp[1] = ((0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind3)+(0.0 - kBind2)+(0.0 - kBind1))*y[0]*y[1] + ((0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind3)+(0.0 - kBind2))*y[1]*y[2] + ((0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind3)+(0.0 - kBind1))*y[1]*y[3] + ((0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[4] + ((0.0 - kBind5)+(0.0 - kBind3)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[5] + ((0.0 - kBind4)+(0.0 - kBind3)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[6] + ((0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind3))*y[1]*y[7] + ((0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind2))*y[1]*y[8] + ((0.0 - kBind5)+(0.0 - kBind3)+(0.0 - kBind2))*y[1]*y[9] + ((0.0 - kBind4)+(0.0 - kBind3)+(0.0 - kBind2))*y[1]*y[10] + ((0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind1))*y[1]*y[11] + ((0.0 - kBind5)+(0.0 - kBind3)+(0.0 - kBind1))*y[1]*y[12] + ((0.0 - kBind4)+(0.0 - kBind3)+(0.0 - kBind1))*y[1]*y[13] + ((0.0 - kBind5)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[14] + ((0.0 - kBind4)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[15] + ((0.0 - kBind3)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[16] + ((0.0 - kBind5)+(0.0 - kBind4))*y[1]*y[17] + ((0.0 - kBind5)+(0.0 - kBind3))*y[1]*y[18] + ((0.0 - kBind4)+(0.0 - kBind3))*y[1]*y[19] + ((0.0 - kBind5)+(0.0 - kBind2))*y[1]*y[20] + ((0.0 - kBind4)+(0.0 - kBind2))*y[1]*y[21] + ((0.0 - kBind3)+(0.0 - kBind2))*y[1]*y[22] + ((0.0 - kBind5)+(0.0 - kBind1))*y[1]*y[23] + ((0.0 - kBind4)+(0.0 - kBind1))*y[1]*y[24] + ((0.0 - kBind3)+(0.0 - kBind1))*y[1]*y[25] + ((0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[26] + ((0.0 - kBind5))*y[1]*y[27] + ((0.0 - kBind4))*y[1]*y[28] + ((0.0 - kBind3))*y[1]*y[29] + ((0.0 - kBind2))*y[1]*y[30] + ((0.0 - kBind1))*y[1]*y[31] + kUnbind1*y[2] + kUnbind2*y[3] + kUnbind3*y[4] + kUnbind4*y[5] + kUnbind5*y[6] + (kUnbind1+kUnbind2)*y[7] + (kUnbind1+kUnbind3)*y[8] + (kUnbind1+kUnbind4)*y[9] + (kUnbind1+kUnbind5)*y[10] + (kUnbind2+kUnbind3)*y[11] + (kUnbind2+kUnbind4)*y[12] + (kUnbind2+kUnbind5)*y[13] + (kUnbind3+kUnbind4)*y[14] + (kUnbind3+kUnbind5)*y[15] + (kUnbind4+kUnbind5)*y[16] + (kUnbind1+kUnbind2+kUnbind3)*y[17] + (kUnbind1+kUnbind2+kUnbind4)*y[18] + (kUnbind1+kUnbind2+kUnbind5)*y[19] + (kUnbind1+kUnbind3+kUnbind4)*y[20] + (kUnbind1+kUnbind3+kUnbind5)*y[21] + (kUnbind1+kUnbind4+kUnbind5)*y[22] + (kUnbind2+kUnbind3+kUnbind4)*y[23] + (kUnbind2+kUnbind3+kUnbind5)*y[24] + (kUnbind2+kUnbind4+kUnbind5)*y[25] + (kUnbind3+kUnbind4+kUnbind5)*y[26] + (kUnbind1+kUnbind2+kUnbind3+kUnbind4)*y[27] + (kUnbind1+kUnbind2+kUnbind3+kUnbind5)*y[28] + (kUnbind1+kUnbind2+kUnbind4+kUnbind5)*y[29] + (kUnbind1+kUnbind3+kUnbind4+kUnbind5)*y[30] + (kUnbind2+kUnbind3+kUnbind4+kUnbind5)*y[31] + (kUnbind1+kUnbind2+kUnbind3+kUnbind4+kUnbind5)*y[32];
	yp[2] = kBind1*y[0]*y[1] + ((0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind3)+(0.0 - kBind2))*y[1]*y[2] + ((0.0 - kUnbind1))*y[2] + kUnbind2*y[7] + kUnbind3*y[8] + kUnbind4*y[9] + kUnbind5*y[10];
	yp[3] = kBind2*y[0]*y[1] + ((0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind3)+(0.0 - kBind1))*y[1]*y[3] + ((0.0 - kUnbind2))*y[3] + kUnbind1*y[7] + kUnbind3*y[11] + kUnbind4*y[12] + kUnbind5*y[13];
	yp[4] = kBind3*y[0]*y[1] + ((0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[4] + ((0.0 - kUnbind3))*y[4] + kUnbind1*y[8] + kUnbind2*y[11] + kUnbind4*y[14] + kUnbind5*y[15];
	yp[5] = kBind4*y[0]*y[1] + ((0.0 - kBind5)+(0.0 - kBind3)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[5] + ((0.0 - kUnbind4))*y[5] + kUnbind1*y[9] + kUnbind2*y[12] + kUnbind3*y[14] + kUnbind5*y[16];
	yp[6] = kBind5*y[0]*y[1] + ((0.0 - kBind4)+(0.0 - kBind3)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[6] + ((0.0 - kUnbind5))*y[6] + kUnbind1*y[10] + kUnbind2*y[13] + kUnbind3*y[15] + kUnbind4*y[16];
	yp[7] = kBind2*y[1]*y[2] + kBind1*y[1]*y[3] + ((0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind3))*y[1]*y[7] + ((0.0 - kUnbind1)+(0.0 - kUnbind2))*y[7] + kUnbind3*y[17] + kUnbind4*y[18] + kUnbind5*y[19];
	yp[8] = kBind3*y[1]*y[2] + kBind1*y[1]*y[4] + ((0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind2))*y[1]*y[8] + ((0.0 - kUnbind1)+(0.0 - kUnbind3))*y[8] + kUnbind2*y[17] + kUnbind4*y[20] + kUnbind5*y[21];
	yp[9] = kBind4*y[1]*y[2] + kBind1*y[1]*y[5] + ((0.0 - kBind5)+(0.0 - kBind3)+(0.0 - kBind2))*y[1]*y[9] + ((0.0 - kUnbind1)+(0.0 - kUnbind4))*y[9] + kUnbind2*y[18] + kUnbind3*y[20] + kUnbind5*y[22];
	yp[10] = kBind5*y[1]*y[2] + kBind1*y[1]*y[6] + ((0.0 - kBind4)+(0.0 - kBind3)+(0.0 - kBind2))*y[1]*y[10] + ((0.0 - kUnbind1)+(0.0 - kUnbind5))*y[10] + kUnbind2*y[19] + kUnbind3*y[21] + kUnbind4*y[22];
	yp[11] = kBind3*y[1]*y[3] + kBind2*y[1]*y[4] + ((0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind1))*y[1]*y[11] + ((0.0 - kUnbind2)+(0.0 - kUnbind3))*y[11] + kUnbind1*y[17] + kUnbind4*y[23] + kUnbind5*y[24];
	yp[12] = kBind4*y[1]*y[3] + kBind2*y[1]*y[5] + ((0.0 - kBind5)+(0.0 - kBind3)+(0.0 - kBind1))*y[1]*y[12] + ((0.0 - kUnbind2)+(0.0 - kUnbind4))*y[12] + kUnbind1*y[18] + kUnbind3*y[23] + kUnbind5*y[25];
	yp[13] = kBind5*y[1]*y[3] + kBind2*y[1]*y[6] + ((0.0 - kBind4)+(0.0 - kBind3)+(0.0 - kBind1))*y[1]*y[13] + ((0.0 - kUnbind2)+(0.0 - kUnbind5))*y[13] + kUnbind1*y[19] + kUnbind3*y[24] + kUnbind4*y[25];
	yp[14] = kBind4*y[1]*y[4] + kBind3*y[1]*y[5] + ((0.0 - kBind5)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[14] + ((0.0 - kUnbind3)+(0.0 - kUnbind4))*y[14] + kUnbind1*y[20] + kUnbind2*y[23] + kUnbind5*y[26];
	yp[15] = kBind5*y[1]*y[4] + kBind3*y[1]*y[6] + ((0.0 - kBind4)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[15] + ((0.0 - kUnbind3)+(0.0 - kUnbind5))*y[15] + kUnbind1*y[21] + kUnbind2*y[24] + kUnbind4*y[26];
	yp[16] = kBind5*y[1]*y[5] + kBind4*y[1]*y[6] + ((0.0 - kBind3)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[16] + ((0.0 - kUnbind4)+(0.0 - kUnbind5))*y[16] + kUnbind1*y[22] + kUnbind2*y[25] + kUnbind3*y[26];
	yp[17] = kBind3*y[1]*y[7] + kBind2*y[1]*y[8] + kBind1*y[1]*y[11] + ((0.0 - kBind5)+(0.0 - kBind4))*y[1]*y[17] + ((0.0 - kUnbind1)+(0.0 - kUnbind2)+(0.0 - kUnbind3))*y[17] + kUnbind4*y[27] + kUnbind5*y[28];
	yp[18] = kBind4*y[1]*y[7] + kBind2*y[1]*y[9] + kBind1*y[1]*y[12] + ((0.0 - kBind5)+(0.0 - kBind3))*y[1]*y[18] + ((0.0 - kUnbind1)+(0.0 - kUnbind2)+(0.0 - kUnbind4))*y[18] + kUnbind3*y[27] + kUnbind5*y[29];
	yp[19] = kBind5*y[1]*y[7] + kBind2*y[1]*y[10] + kBind1*y[1]*y[13] + ((0.0 - kBind4)+(0.0 - kBind3))*y[1]*y[19] + ((0.0 - kUnbind1)+(0.0 - kUnbind2)+(0.0 - kUnbind5))*y[19] + kUnbind3*y[28] + kUnbind4*y[29];
	yp[20] = kBind4*y[1]*y[8] + kBind3*y[1]*y[9] + kBind1*y[1]*y[14] + ((0.0 - kBind5)+(0.0 - kBind2))*y[1]*y[20] + ((0.0 - kUnbind1)+(0.0 - kUnbind3)+(0.0 - kUnbind4))*y[20] + kUnbind2*y[27] + kUnbind5*y[30];
	yp[21] = kBind5*y[1]*y[8] + kBind3*y[1]*y[10] + kBind1*y[1]*y[15] + ((0.0 - kBind4)+(0.0 - kBind2))*y[1]*y[21] + ((0.0 - kUnbind1)+(0.0 - kUnbind3)+(0.0 - kUnbind5))*y[21] + kUnbind2*y[28] + kUnbind4*y[30];
	yp[22] = kBind5*y[1]*y[9] + kBind4*y[1]*y[10] + kBind1*y[1]*y[16] + ((0.0 - kBind3)+(0.0 - kBind2))*y[1]*y[22] + ((0.0 - kUnbind1)+(0.0 - kUnbind4)+(0.0 - kUnbind5))*y[22] + kUnbind2*y[29] + kUnbind3*y[30];
	yp[23] = kBind4*y[1]*y[11] + kBind3*y[1]*y[12] + kBind2*y[1]*y[14] + ((0.0 - kBind5)+(0.0 - kBind1))*y[1]*y[23] + ((0.0 - kUnbind2)+(0.0 - kUnbind3)+(0.0 - kUnbind4))*y[23] + kUnbind1*y[27] + kUnbind5*y[31];
	yp[24] = kBind5*y[1]*y[11] + kBind3*y[1]*y[13] + kBind2*y[1]*y[15] + ((0.0 - kBind4)+(0.0 - kBind1))*y[1]*y[24] + ((0.0 - kUnbind2)+(0.0 - kUnbind3)+(0.0 - kUnbind5))*y[24] + kUnbind1*y[28] + kUnbind4*y[31];
	yp[25] = kBind5*y[1]*y[12] + kBind4*y[1]*y[13] + kBind2*y[1]*y[16] + ((0.0 - kBind3)+(0.0 - kBind1))*y[1]*y[25] + ((0.0 - kUnbind2)+(0.0 - kUnbind4)+(0.0 - kUnbind5))*y[25] + kUnbind1*y[29] + kUnbind3*y[31];
	yp[26] = kBind5*y[1]*y[14] + kBind4*y[1]*y[15] + kBind3*y[1]*y[16] + ((0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[26] + ((0.0 - kUnbind3)+(0.0 - kUnbind4)+(0.0 - kUnbind5))*y[26] + kUnbind1*y[30] + kUnbind2*y[31];
	yp[27] = kBind4*y[1]*y[17] + kBind3*y[1]*y[18] + kBind2*y[1]*y[20] + kBind1*y[1]*y[23] + ((0.0 - kBind5))*y[1]*y[27] + ((0.0 - kUnbind1)+(0.0 - kUnbind2)+(0.0 - kUnbind3)+(0.0 - kUnbind4))*y[27] + kUnbind5*y[32];
	yp[28] = kBind5*y[1]*y[17] + kBind3*y[1]*y[19] + kBind2*y[1]*y[21] + kBind1*y[1]*y[24] + ((0.0 - kBind4))*y[1]*y[28] + ((0.0 - kUnbind1)+(0.0 - kUnbind2)+(0.0 - kUnbind3)+(0.0 - kUnbind5))*y[28] + kUnbind4*y[32];
	yp[29] = kBind5*y[1]*y[18] + kBind4*y[1]*y[19] + kBind2*y[1]*y[22] + kBind1*y[1]*y[25] + ((0.0 - kBind3))*y[1]*y[29] + ((0.0 - kUnbind1)+(0.0 - kUnbind2)+(0.0 - kUnbind4)+(0.0 - kUnbind5))*y[29] + kUnbind3*y[32];
	yp[30] = kBind5*y[1]*y[20] + kBind4*y[1]*y[21] + kBind3*y[1]*y[22] + kBind1*y[1]*y[26] + ((0.0 - kBind2))*y[1]*y[30] + ((0.0 - kUnbind1)+(0.0 - kUnbind3)+(0.0 - kUnbind4)+(0.0 - kUnbind5))*y[30] + kUnbind2*y[32];
	yp[31] = kBind5*y[1]*y[23] + kBind4*y[1]*y[24] + kBind3*y[1]*y[25] + kBind2*y[1]*y[26] + ((0.0 - kBind1))*y[1]*y[31] + ((0.0 - kUnbind2)+(0.0 - kUnbind3)+(0.0 - kUnbind4)+(0.0 - kUnbind5))*y[31] + kUnbind1*y[32];
	yp[32] = kBind5*y[1]*y[27] + kBind4*y[1]*y[28] + kBind3*y[1]*y[29] + kBind2*y[1]*y[30] + kBind1*y[1]*y[31] + ((0.0 - kUnbind1)+(0.0 - kUnbind2)+(0.0 - kUnbind3)+(0.0 - kUnbind4)+(0.0 - kUnbind5))*y[32];

}



int main()
{
// size of the system
const int n= 33;


/*************************************************************************
*
* Computing maximum of the reachable set 
*
*************************************************************************/

// number of changes of u_max control
int m=0;
FILE *fp = fopen("replicatedBindingSite5Asymm_Pontryagin_max.csv","r");
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
ifstream file("replicatedBindingSite5Asymm_Pontryagin_max.csv");
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
y[0]=0.0437; y[1]=0.0454; y[2]=0.0107;
y[3]=0.0279; y[4]=0.0254; y[5]=0.0369;
y[6]=0.0405; y[7]=0.0431; y[8]=0.0157;
y[9]=0.0388; y[10]=0.0374; y[11]=0.0093;
y[12]=0.0068; y[13]=0.0284; y[14]=0.0547;
y[15]=0.0194; y[16]=0.0334; y[17]=0.0128; y[18]=0.0429;
y[19]=0.0146; y[20]=0.0289; y[21]=0.0399;
y[22]=0.0508; y[24]=0.0547; y[25]=0.0312;
y[25]=0.0079; y[26]=0.0085; y[27]=0.0147; y[28]=0.048;
y[29]=0.0145; y[30]=0.0465; y[31]=0.0139; y[32]=0.053;
coef[0]=0.0; coef[1]=1.0; coef[2]=0.0;
coef[3]=0.0; coef[4]=0.0; coef[5]=0.0; 
coef[6]=0.0; coef[7]=0.0; coef[8]=0.0; coef[9]=0.0;
coef[10]=0.0; coef[11]=0.0; coef[12]=0.0;
coef[13]=0.0; coef[14]=0.0; coef[15]=0.0; 
coef[16]=0.0; coef[17]=0.0; coef[18]=0.0; coef[19]=0.0;
coef[20]=0.0; coef[21]=0.0; coef[22]=0.0;
coef[23]=0.0; coef[24]=0.0; coef[25]=0.0; 
coef[26]=0.0; coef[27]=0.0; coef[28]=0.0; coef[29]=0.0;
coef[30]=0.0; coef[31]=0.0; coef[32]=0.0;
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
fp = fopen("replicatedBindingSite5Asymm_Pontryagin_min.csv","r");
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
ifstream file2("replicatedBindingSite5Asymm_Pontryagin_min.csv");

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
y[0]=0.0437; y[1]=0.0454; y[2]=0.0107;
y[3]=0.0279; y[4]=0.0254; y[5]=0.0369;
y[6]=0.0405; y[7]=0.0431; y[8]=0.0157;
y[9]=0.0388; y[10]=0.0374; y[11]=0.0093;
y[12]=0.0068; y[13]=0.0284; y[14]=0.0547;
y[15]=0.0194; y[16]=0.0334; y[17]=0.0128; y[18]=0.0429;
y[19]=0.0146; y[20]=0.0289; y[21]=0.0399;
y[22]=0.0508; y[24]=0.0547; y[25]=0.0312;
y[25]=0.0079; y[26]=0.0085; y[27]=0.0147; y[28]=0.048;
y[29]=0.0145; y[30]=0.0465; y[31]=0.0139; y[32]=0.053;


// Verified ODE solver solution for u_max control
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
cout<<"Minimum reachable point enclosure at t = "<<t_[m-1] <<endl;
for (int i=0;i<n;i++)
   res += coef[i]*y[i];
cout << res << endl;

return 0;
}

