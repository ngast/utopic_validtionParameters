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
 
 interval alpha = 0.01, beta = 0.05, gamma = 0.1;
 interval delt = 0.693, RDF = 0.02, GDF = 5.0;
 interval k4 = p->val[0];
 interval k5 = p->val[1];
 interval k6 = p->val[2];
 interval kM = 0.003, kD = 0.003, k1 = 1000.0, k2 = 100.0, k3 = 7000.0;
 interval kEM = 400.0, kEP = 0.0008, kEC = 1000000.0, kR = 900.0;  
 interval kATP = 1200.0, ATPc = 1000.0, PAOx = 1.0;

 	yp[0] = y[8]/(y[8]+ATPc)*k1/((1.0+y[8]/ATPc)*(1.0+y[8]/ATPc)*(1.0+y[8]/ATPc))/(y[0]+2.0*y[1]/(GDF+1.0)+(y[2]+y[3]+y[4]+y[5])/GDF)*y[0]+(2.0*y[8]/(y[8]+ATPc)*k1/((1.0+y[8]/ATPc)*(1.0+y[8]/ATPc)*(1.0+y[8]/ATPc))*1.0/(y[0]+2.0*y[1]/(GDF+1.0)+(y[2]+y[3]+y[4]+y[5])/GDF)*y[1]/(GDF+1.0)-(alpha+(kM+kD)*y[7])*y[0]);
	yp[1] = (-k4)*y[8]/(y[8]+ATPc)*k1/((1.0+y[8]/ATPc)*(1.0+y[8]/ATPc)*(1.0+y[8]/ATPc))*1.0/(y[0]+2.0*y[1]/(GDF+1.0)+(y[2]+y[3]+y[4]+y[5])/GDF)*y[1]/(GDF+1.0)+2.0*y[8]/(y[8]+ATPc)*k1/((1.0+y[8]/ATPc)*(1.0+y[8]/ATPc)*(1.0+y[8]/ATPc))*1.0/(y[0]+2.0*y[1]/(GDF+1.0)+(y[2]+y[3]+y[4]+y[5])/GDF)*y[2]/GDF+(kM*y[7]*y[0]-(beta+(kM+kD)*y[7])*y[0]);
	yp[2] = (-k5)*y[8]/(y[8]+ATPc)*k1/((1.0+y[8]/ATPc)*(1.0+y[8]/ATPc)*(1.0+y[8]/ATPc))*1.0/(y[0]+2.0*y[1]/(GDF+1.0)+(y[2]+y[3]+y[4]+y[5])/GDF)*y[2]/GDF+(kM*y[7]*y[1]-(gamma+kD*y[7])*y[2]);
	yp[3] = y[8]/(y[8]+ATPc)*k1/((1.0+y[8]/ATPc)*(1.0+y[8]/ATPc)*(1.0+y[8]/ATPc))*1.0/(y[0]+2.0*y[1]/(GDF+1.0)+(y[2]+y[3]+y[4]+y[5])/GDF)*(y[3]+y[4])/GDF+(kD*y[7]*y[0]-(alpha+kD*y[7])*y[3]);
	yp[4] = (-y[8]/(y[8]+ATPc)*k1/((1.0+y[8]/ATPc)*(1.0+y[8]/ATPc)*(1.0+y[8]/ATPc))*1.0/(y[0]+2.0*y[1]/(GDF+1.0)+(y[2]+y[3]+y[4]+y[5])/GDF))*y[4]/GDF+2.0*y[8]/(y[8]+ATPc)*k1/((1.0+y[8]/ATPc)*(1.0+y[8]/ATPc)*(1.0+y[8]/ATPc))*1.0/(y[0]+2.0*y[1]/(GDF+1.0)+(y[2]+y[3]+y[4]+y[5])/GDF)*y[5]/GDF+(kD*y[7]*y[1]-(alpha+kM*RDF*y[7])*y[3]-(beta+kM*RDF*y[7])*y[4]);
	yp[5] = (-y[8]/(y[8]+ATPc)*k1/((1.0+y[8]/ATPc)*(1.0+y[8]/ATPc)*(1.0+y[8]/ATPc))*1.0/(y[0]+2.0*y[1]/(GDF+1.0)+(y[2]+y[3]+y[4]+y[5])/GDF))*y[5]/GDF+kD*y[7]*y[2]+(kM*RDF*y[7]*y[4]-gamma*y[5]);
	yp[6] = y[8]/(y[8]+ATPc)*k2/(1.0+PAOx/(y[7]*(y[0]+y[1]+y[2])+RDF*y[7]*(y[3]+y[4]+y[5])))-delt*y[6];
	yp[7] = k6*kR-k3*y[6]*y[7]/(y[0]+y[1]+y[2]+y[3]+y[4]+y[5]);
	yp[8] = kATP*y[0]+(0.5*kATP*y[1]-y[8]/(y[8]+ATPc)*(kEM*k1/((1.0+y[8]/ATPc)*(1.0+y[8]/ATPc)*(1.0+y[8]/ATPc))+kEC+kEP*k2/(1.0+PAOx/(y[7]*(y[0]+y[1]+y[2])+RDF*y[7]*(y[3]+y[4]+y[5])))));

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


// number of changes of u_max control
int m=0;
FILE *fp = fopen("Aging_Pontryagin_max.csv","r");
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

// getting u_max from file
iVector t_(m);
string line;
ifstream file("Aging_Pontryagin_max.csv");
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
y[0]= 500.0;
y[1]= 500.0;
y[2]= 500.0;
y[3]= 100.0;
y[4]= 100.0;
y[5]= 100.0;
y[6]= 200.0;
y[7]= 500.0;
y[8]= 20.0;
iVector coef(n);
coef[0] = 1.0;
coef[1] = 0.0;
coef[2] = 0.0;
coef[3] = 0.0;
coef[4] = 0.0;
coef[5] = 0.0;
coef[6] = 0.0;
coef[7] = 0.0;
coef[8] = 0.0;


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
fp = fopen("Aging_Pontryagin_min.csv","r");
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
ifstream file2("Aging_Pontryagin_min.csv");
getline(file2,line);
for (int i=0;i<m;i++){
   getline(file2,line);
   std::stringstream    lineStream(line);
   string       cell;
   getline(lineStream,cell,',');
   if(i>0){
     t2[i-1]=string_to_interval(cell.c_str());
   }
 
   for(int j=0; getline(lineStream,cell,','); j++){
      p2[i].val[j]=string_to_interval(cell.c_str());
   }
}
t2[m-1]=1.0; // horizon time value

// reachability problem parameters
y[0]= 500.0;
y[1]= 500.0;
y[2]= 500.0;
y[3]= 100.0;
y[4]= 100.0;
y[5]= 100.0;
y[6]= 200.0;
y[7]= 500.0;
y[8]= 20.0;


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

