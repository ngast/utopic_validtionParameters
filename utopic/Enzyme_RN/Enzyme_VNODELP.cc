/*74:*/
#line 54 "./vanderpol.w"

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

 interval k1 = p->val[0];
 interval k2 = p->val[1];
 interval k3 = p->val[2];
 interval k4 = 1.0, k5 = 1.0, k6 = 1.0, k7 = 1.0, k8 = 1.0, k9 = 1.0;
 interval Fs1 = 2.0, Fs2 = 2.0, epsS1 = 0.1, epsS2 = 0.1, epsP = 0.1;

 yp[0] = -k1*y[0]*y[3] -k3*y[0]*y[4] + k9*y[5];
 yp[1] = -k1*y[0]*y[1] -epsS1*y[1] + k2*y[4] + k8*y[5] + Fs1;
 yp[2] = -k3*y[0]*y[4] -epsS2*y[2] -k5*y[2]*y[3] + k6*y[5] + Fs2;
 yp[3] = k1*y[0]*y[1] - k2-k5*y[4] + k6*y[5];
 yp[4] = k3*y[0]*y[2] + -k7*y[1]*y[4] -k4*y[4] + k8*y[5];
 yp[5] = k7*y[1]*y[4] + k5*y[2]*y[3] + (k6+k8+k9)*y[5];
 yp[6] = k9*y[5] + -epsP*y[6];
}




int main()
{
// size of the system
const int n= 7;


/*************************************************************************
*
* Computing maximum of the reachable set 
*
*************************************************************************/


// number of changes of u_max control
int m=0;
FILE *fp = fopen("Enzyme_Pontryagin_max.csv","r");
char ch;
while (!feof(fp)){
  ch = fgetc(fp);
  if(ch == '\n')
    m++;
}
m--;
rewind(fp);

UncertainParameters p[m];
interval t= 0.0;

iVector t_(m);
string line;
ifstream file("Enzyme_Pontryagin_max.csv");
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
t_[m-1]=1.0; // horizon time value


// reachability problem parameters
iVector y(n);
y[0]= 0.1;
y[1]= 0.1;
y[2]= 0.1;
y[3]= 0.2;
y[4]= 0.1;
y[5]= 0.3;
y[6]= 0.1; 
iVector coef(n);
coef[0] = 1.0;
coef[1] = 0.0;
coef[2] = 0.0;
coef[3] = 0.0;
coef[4] = 0.0;
coef[5] = 0.0;
coef[6] = 0.0;

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
fp = fopen("Enzyme_Pontryagin_min.csv","r");
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
ifstream file2("Enzyme_Pontryagin_min.csv");

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
t2[m-1]=1.0; // horizon time value



// reachability problem parameters
y[0]= 0.1;
y[1]= 0.1;
y[2]= 0.1;
y[3]= 0.2;
y[4]= 0.1;
y[5]= 0.3;
y[6]= 0.1; 


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

