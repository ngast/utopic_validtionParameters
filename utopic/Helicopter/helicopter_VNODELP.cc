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
 
 interval a= p->val[0];
 interval b= p->val[1];
 interval c= p->val[2];

 
 yp[0] = 0.99857378006*y[22] + 0.053384274244*y[23];
 yp[1] = ((0.0- 0.01975778857))*y[0] + ((0.0- 0.003710494952))*y[1] + 0.86350701147*y[2] + ((0.0- 1.236460821044))*y[3] + 0.060184240645*y[4] + 0.009012833714*y[11] + 0.311015942657*y[21] + 2.81018120479*y[22] + ((0.0- 0.001602140073))*y[23] + 0.008134087133*y[27];
 yp[2] = ((0.0- 0.030385323449))*y[0] + ((0.0- 36.922139523656))*y[1] + ((0.0- 18.505141519315))*y[2] + ((0.0- 3.793715804769))*y[3] + ((0.0- 2.765572372983))*y[4] + 0.035944961732*y[5] + ((0.0- 0.03891010472))*y[6] + 0.025846348888*y[7] + 0.527826299191*y[8] + 1.697201876759*y[9] + 17.980094722474*y[10] + 0.003110159427*y[11] + 4.615721721183*y[12] + 0.618925691035*y[13] + 0.71776394151*y[14] + 0.036154725527*y[15] + 0.021151770407*y[16] + 0.200211885807*y[17] + ((0.0- 0.236208723376))*y[18] + ((0.0- 10.127341872304))*y[19] + 0.037053334254*y[20] + 0.312812882924*y[21] + 0.287354391281*y[22] + ((0.0- 0.00233173063))*y[23] + ((0.0- 8.414922645141))*y[27];
 yp[3] = 0.002667394037*y[0] + 0.536693033369*y[1] + 0.353775293385*y[2] + ((0.0- 8.335731095093))*y[3] + 0.078527228401*y[4] + 0.005987264162*y[5] + 0.006725273267*y[6] + ((0.0- 0.005979187005))*y[7] + ((0.0- 0.182029763642))*y[8] + 3.233906041666*y[9] + ((0.0- 0.268381596955))*y[10] + 0.004496152836*y[11] + ((0.0- 0.514971094398))*y[12] + ((0.0- 0.005888452287))*y[13] + ((0.0- 0.00311046421))*y[14] + 0.081894084826*y[15] + 0.066024394813*y[16] + ((0.0- 0.104516302587))*y[17] + 1.63128979696*y[18] + 0.066233671911*y[19] + ((0.0- 0.002829938571))*y[20] + 0.045956750452*y[21] + 1.764514260408*y[22] + (1.46052012E-4)*y[23] + ((0.0- 17.119523267503))*y[27];
 yp[4] = 0.024056576806*y[0] + ((0.0- 5.819307733117))*y[1] + ((0.0- 2.712299197847))*y[2] + ((0.0- 0.61581752704))*y[3] + ((0.0- 4.029675752634))*y[4] + 0.002306818331*y[5] + ((0.0- 0.004623901048))*y[6] + 0.071938991843*y[7] + 2.282021405408*y[8] + 0.349879770769*y[9] + 2.900759066988*y[10] + ((0.0- 0.001361685819))*y[11] + 4.516150272075*y[12] + 0.111029828612*y[13] + 0.13730505946*y[14] + 0.00365562004*y[15] + 0.001262406662*y[16] + 1.082630189953*y[17] + ((0.0- 0.024777388732))*y[18] + ((0.0- 1.766450614425))*y[19] + ((0.0- 0.930338103031))*y[20] + ((0.0- 0.230715295944))*y[21] + 0.185551143531*y[22] + 0.001832537128*y[23] + ((0.0- 1.696796379292))*y[27];
 yp[5] = ((0.0- 1.753103616578))*y[0] + ((0.0- 0.70542490241))*y[1] + ((0.0- 10.592707880324))*y[2] + ((0.0- 54.888617486514))*y[3] + ((0.0- 0.619258600252))*y[4] + ((0.0- 0.018180886764))*y[5] + ((0.0- 0.016310350542))*y[6] + 0.17226746335*y[7] + 3.857750758541*y[8] + ((0.0- 3.73362923875))*y[9] + 0.251977753557*y[10] + 0.52186960989*y[11] + 1.659474556422*y[12] + 0.007076928248*y[13] + 0.00759488332*y[14] + ((0.0- 0.096433822422))*y[15] + ((0.0- 0.077989008913))*y[16] + 1.068213380174*y[17] + ((0.0- 1.854605830991))*y[18] + ((0.0- 0.041177323469))*y[19] + 0.038137029879*y[20] + 23.319318958026*y[21] + 145.082271971311*y[22] + ((0.0- 0.138741289403))*y[23] + (8.60128319E-4)*y[26] + ((0.0- 11.594360544437))*y[27];
 yp[6] = 1.708539622488*y[0] + 23.870898681235*y[1] + 1.639719754761*y[2] + ((0.0- 40.888303474223))*y[3] + 2.851614162302*y[4] + 0.00134943057*y[5] + ((0.0- 0.024984412428))*y[6] + 0.102862439056*y[7] + 1.794950045519*y[8] + 0.252919074168*y[9] + 3.893644396914*y[10] + 0.111898315003*y[11] + ((0.0- 2.155538119928))*y[12] + 0.123550997381*y[13] + 0.137525326941*y[14] + 0.007512594224*y[15] + 0.004476043338*y[16] + ((0.0- 0.081084731931))*y[17] + ((0.0- 0.05006218142))*y[18] + ((0.0- 2.033833968448))*y[19] + 1.145542115841*y[20] + ((0.0- 13.174473231922))*y[21] + 91.46275555623*y[22] + 0.127584976026*y[23] + ((0.0- 7.23245056E-4))*y[26] + ((0.0- 1.878010842263))*y[27];
 yp[7] = ((0.0- 0.069753861204))*y[0] + ((0.0- 0.784811430978))*y[1] + ((0.0- 1.913888711445))*y[2] + ((0.0- 8.087612492321))*y[3] + 11.48870135415*y[4] + 0.19441123747*y[5] + 0.167838434014*y[6] + ((0.0- 3.255004272242))*y[7] + ((0.0- 71.490067651024))*y[8] + 0.531333931032*y[9] + 1.089774627294*y[10] + 0.041269247265*y[11] + ((0.0- 20.947639012098))*y[12] + ((0.0- 0.006423930487))*y[13] + ((0.0- 0.078948253623))*y[14] + 0.050383537787*y[15] + 0.045369546582*y[16] + ((0.0- 18.580601832107))*y[17] + ((0.0- 0.295436370828))*y[18] + ((0.0- 0.680521274763))*y[19] + ((0.0- 0.683600561672))*y[20] + 1.243498527057*y[21] + 13.467483657041*y[22] + ((0.0- 0.005772466581))*y[23] + ((0.0- 5.161896992464))*y[27];
 yp[8] = ((0.0- 0.012))*y[8] + ((0.0- 0.013549327978))*y[24] + ((0.0- 0.012135188033))*y[25] + 0.226991094595*y[26];
 yp[9] = ((0.0- 11.385989897412))*y[0] + ((0.0- 0.005))*y[9];
 yp[10] = ((0.0- 0.005))*y[10] + ((0.0- 4.554395958965))*y[11];
 yp[11] = y[21] + ((0.0- 0.003182219341))*y[22] + 0.059524655342*y[23];
 yp[12] = ((0.0- 0.01))*y[12] + 0.243569095885*y[22] + ((0.0- 4.554395958965))*y[23];
 yp[13] = ((0.0- 8.5))*y[13] + ((0.0- 18.0))*y[14] + ((0.0- 4.554395958965))*y[21];
 yp[14] = y[13];
 yp[15] = ((0.0- 8.5))*y[15] + ((0.0- 18.0))*y[16] + ((0.0- 11.385989897412))*y[22];
 yp[16] = y[15];
 yp[17] = 0.514736886625*y[1] + 0.282998565164*y[2] + 0.440668616363*y[3] + ((0.0- 2.382738811465))*y[4] + ((0.0- 0.037424700426))*y[5] + ((0.0- 0.035002491999))*y[6] + 0.614952694278*y[7] + 14.829958398888*y[8] + ((0.0- 0.110759742503))*y[9] + ((0.0- 0.226034186438))*y[10] + 4.345468653096*y[12] + 0.001333027828*y[13] + 0.016376955559*y[14] + ((0.0- 0.010465240818))*y[15] + ((0.0- 0.0094224826))*y[16] + ((0.0- 6.14561518105))*y[17] + 0.061014181775*y[18] + 0.141165339638*y[19] + 0.141806743312*y[20] + 0.68318607598*y[27];
 yp[18] = 0.767400874818*y[1] + ((0.0- 0.190879388177))*y[2] + ((0.0- 11.678174370212))*y[3] + ((0.0- 0.041149877278))*y[4] + ((0.0- 0.026017271417))*y[5] + ((0.0- 0.026698725144))*y[6] + 0.036415219598*y[7] + 0.73865635835*y[8] + 6.810845841283*y[9] + ((0.0- 0.38478495798))*y[10] + ((0.0- 0.708557300741))*y[12] + ((0.0- 0.005524328707))*y[13] + 0.002522572903*y[14] + 0.171826920583*y[15] + 0.138368426838*y[16] + 0.071909684799*y[17] + ((0.0- 6.567495145681))*y[18] + 0.039293511274*y[19] + 0.006041152866*y[20] + ((0.0- 36.03935472971))*y[27];
 yp[19] = 13.482210983798*y[1] + 2.488520358003*y[2] + 0.076750797248*y[3] + 0.804972334222*y[4] + 0.023466195202*y[5] + ((0.0- 0.022740687251))*y[6] + 0.018646161041*y[7] + 0.436604617107*y[8] + ((0.0- 0.414374632569))*y[9] + ((0.0- 6.563020897889))*y[10] + ((0.0- 1.423460802051))*y[12] + ((0.0- 0.224998971426))*y[13] + ((0.0- 0.259852011779))*y[14] + ((0.0- 0.008437464875))*y[15] + ((0.0- 0.00394534411))*y[16] + 0.102235829031*y[17] + 0.191829027845*y[18] + ((0.0- 6.31242884154))*y[19] + ((0.0- 0.038075090345))*y[20] + 1.997224587333*y[27];
 yp[20] = ((0.0- 3.415298165208))*y[1] + ((0.0- 1.836225244248))*y[2] + ((0.0- 0.015605131825))*y[3] + 10.4868455956*y[4] + ((0.0- 0.031379180918))*y[5] + 0.00126674641*y[6] + 0.525873993847*y[7] + 9.808565668907*y[8] + ((0.0- 0.367529750255))*y[9] + 1.37040552413*y[10] + ((0.0- 12.076970057329))*y[12] + 0.004883176776*y[13] + ((0.0- 0.015765473705))*y[14] + ((0.0- 3.99777933E-4))*y[15] + ((0.0- 4.97333312E-4))*y[16] + 0.199818976539*y[17] + ((0.0- 0.002648145523))*y[18] + ((0.0- 0.101212258081))*y[19] + ((0.0- 5.199268943788))*y[20] + c*y[27];
 yp[21] = ((0.0- 16.213284674534))*y[1] + ((0.0- 2.984968535139))*y[2] + ((0.0- 0.493137919288))*y[3] + ((0.0- 1.186954196152))*y[4] + ((0.0- 0.031106608756))*y[5] + 0.024595252653*y[6] + 0.008231369923*y[7] + 0.231787619674*y[8] + 0.745302732591*y[9] + 7.895709940231*y[10] + 2.026930360369*y[12] + 0.271792657736*y[13] + 0.315196108541*y[14] + 0.01587684771*y[15] + 0.009288507454*y[16] + 0.087920280806*y[17] + ((0.0- 0.103727794204))*y[18] + ((0.0- 4.447282126346))*y[19] + 0.016271459306*y[20] + ((0.0- 11.570495605469))*y[21] + ((0.0- 2.544637680054))*y[22] + ((0.0- 0.063602626324))*y[23] + 0.106780529022*y[24] + ((0.0- 0.09491866827))*y[25] + 0.007107574493*y[26] + ((0.0- 3.700790207851))*y[27];
 yp[22] = 0.236494174025*y[1] + ((0.0- 0.028725044803))*y[2] + ((0.0- 2.442989538035))*y[3] + 0.03451055081*y[4] + ((0.0- 0.004683216652))*y[5] + ((0.0- 0.00515403869))*y[6] + ((0.0- 0.002104275246))*y[7] + ((0.0- 0.079935853309))*y[8] + 1.420125114638*y[9] + ((0.0- 0.117856066698))*y[10] + ((0.0- 0.226142434271))*y[12] + ((0.0- 0.002585832387))*y[13] + ((0.0- 0.001365917341))*y[14] + 0.035962654791*y[15] + 0.028993699893*y[16] + ((0.0- 0.045896888864))*y[17] + 0.716358354284*y[18] + 0.029085601036*y[19] + ((0.0- 0.001242728387))*y[20] + a*y[21] + ((0.0- 1.998182296753))*y[22] + 0.016651883721*y[24] + 0.018462046981*y[25] + ((0.0- 0.001187470742))*y[26] + ((0.0- 7.517319654181))*y[27];
 yp[23] = ((0.0- 2.555714688932))*y[1] + ((0.0- 0.339301128908))*y[2] + ((0.0- 0.033104023297))*y[3] + ((0.0- 1.446467788369))*y[4] + ((0.0- 0.007442776396))*y[5] + 0.030657946816*y[7] + 1.002118140789*y[8] + 0.153644862643*y[9] + 1.273828227991*y[10] + 1.983204935524*y[12] + 0.048757213739*y[13] + 0.060295617991*y[14] + 0.001605314985*y[15] + (5.54368427E-4)*y[16] + 0.475422075598*y[17] + ((0.0- 0.010880647601))*y[18] + ((0.0- 0.775712358056))*y[19] + ((0.0- 0.408545111762))*y[20] + ((0.0- 2.040895462036))*y[21] + ((0.0- 0.458999156952))*y[22] + ((0.0- 0.73502779007))*y[23] + 0.019255757332*y[24] + ((0.0- 0.00459562242))*y[25] + 0.002120360732*y[26] + ((0.0- 0.740775522612))*y[27];
 yp[24] = ((0.0- 32.103607177734))*y[0] + ((0.0- 0.215429806172))*y[1] + 0.063500560122*y[2] + 2.847523923644*y[3] + ((0.0- 0.297021616015))*y[4] + 0.001323463163*y[5] + 0.002124820781*y[6] + 0.068860932948*y[7] + 1.694077894544*y[8] + ((0.0- 1.639571645676))*y[9] + 0.110652545728*y[10] + 0.728735301618*y[12] + 0.003107735169*y[13] + 0.003335187976*y[14] + ((0.0- 0.042347579477))*y[15] + ((0.0- 0.034247794709))*y[16] + 0.469091132962*y[17] + ((0.0- 0.814424502262))*y[18] + ((0.0- 0.018082452136))*y[19] + 0.016747349252*y[20] + ((0.0- 0.503355026245))*y[21] + 2.297859191895*y[22] + ((0.0- 0.021215811372))*y[24] + ((0.0- 0.02116791904))*y[25] + 0.01581159234*y[26] + 8.689411857722*y[27];
 yp[25] = 0.102161169052*y[0] + ((0.0- 3.574948145694))*y[1] + ((0.0- 0.788176766644))*y[2] + ((0.0- 0.107590635594))*y[3] + 0.908657075077*y[4] + ((0.0- 0.008720966051))*y[5] + 0.005669792925*y[6] + 0.044884407612*y[7] + 0.788227489086*y[8] + 0.111065913657*y[9] + 1.709840089441*y[10] + 32.057830810547*y[11] + ((0.0- 0.946574755181))*y[12] + 0.054255711842*y[13] + 0.060392345409*y[14] + 0.003299051857*y[15] + 0.00196559253*y[16] + ((0.0- 0.03560723866))*y[17] + ((0.0- 0.021984114632))*y[18] + ((0.0- 0.893130060176))*y[19] + 0.503048977806*y[20] + ((0.0- 2.347217559814))*y[21] + ((0.0- 0.503611564636))*y[22] + 0.83494758606*y[23] + 0.02122657001*y[24] + ((0.0- 0.037879735231))*y[25] + (3.5400386E-4)*y[26] + ((0.0- 0.560681623936))*y[27];
 yp[26] = ((0.0- b))*y[0] + ((0.0- 1.089782421583))*y[1] + ((0.0- 0.599051729911))*y[2] + ((0.0- 0.930901394778))*y[3] + 5.04406072285*y[4] + 0.079229241316*y[5] + 0.074101747848*y[6] + ((0.0- 1.301808243838))*y[7] + ((0.0- 31.393874531397))*y[8] + 0.233327947688*y[9] + 0.478559456452*y[10] + 1.713829040527*y[11] + ((0.0- 9.198865975131))*y[12] + ((0.0- 0.002820980233))*y[13] + ((0.0- 0.034669033757))*y[14] + 0.022125233836*y[15] + 0.01992340894*y[16] + ((0.0- 8.159414332666))*y[17] + ((0.0- 0.129736796488))*y[18] + ((0.0- 0.298841506489))*y[19] + ((0.0- 0.30019373275))*y[20] + ((0.0- 0.004005432129))*y[21] + ((0.0- 0.057411193848))*y[22] + 0.013989634812*y[24] + ((0.0- 9.06753354E-4))*y[25] + ((0.0- 0.290513515472))*y[26] + ((0.0- 1.440209153996))*y[27];
 yp[27] = 0.050176870833*y[0] + 0.001301453941*y[1] + 0.213359280279*y[2] + 0.881596311923*y[3] + 0.051809053856*y[4] + ((0.0- 0.003161246171))*y[11] + ((0.0- 0.48616517519))*y[21] + 0.266534777047*y[22] + 0.003826227932*y[23] + ((0.0- 0.02065732397))*y[27];
}




int main()
{
// size of the system
const int n= 28;


/*************************************************************************
*
* Computing maximum of the reachable set 
*
*************************************************************************/

// number of changes of u_max control
int m=0;
FILE *fp = fopen("helicopter_Pontryagin_max.csv","r");
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
ifstream file("helicopter_Pontryagin_max.csv");
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
y[0]=10.0; coef[0]=1.0;
for (int i=1 ; i < n ; i++){
   y[i]= 10.0;
   coef[i]= 0.0;
}

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
fp = fopen("helicopter_Pontryagin_min.csv","r");
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
ifstream file2("helicopter_Pontryagin_min.csv");

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
for (int i=0.0; i < n ; i++)
   y[i]= 10.0;



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
