/*74:*/
//#line 54 "./vanderpol.w"

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


 interval a= p->val[0];
 interval b= p->val[1];
 interval c= p->val[2];

 yp[0] = y[2];
 yp[1] = c*y[3];
 yp[2] = ((-a)*y[1]*y[2]*y[3]-a*y[1]-b*y[2]+4.0)/(y[1]*y[1]+1.0);
 yp[3] = y[1]*y[2]*y[2] -y[1] -y[3] +1.0;


}




int main()
{
// size of the system
const int n= 4;



/*************************************************************************
*
* Computing maximum of the reachable set
*
*************************************************************************/



int m=0;
FILE *fp = fopen("robotArm_Pontryagin_max.csv","r");
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
ifstream file("robotArm_Pontryagin_max.csv");
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
iVector y(n), coef(n); 
y[0]=1.2; 
y[1]=1.0;
y[2]=0.2;
y[3]=0.6;
coef[0]=0.0;
coef[1]=0.0;
coef[2]=1.0;
coef[3]=0.0;

// Verified ODE solver solution for u_max control
AD *myad;
VNODE *Solver;
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
fp = fopen("robotArm_Pontryagin_min.csv","r");
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
ifstream file2("robotArm_Pontryagin_min.csv");

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
y[0]=1.2 ;
y[1]=1.0 ;
y[2]=0.2 ;
y[3]=0.6 ;



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
cout<<"Minimum reachable point enclosure at t = "<<t2[m-1] <<endl;
for (int i=0;i<n;i++)
   res += coef[i]*y[i];
cout << res << endl;

return 0;
}

