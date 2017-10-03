/*74:*/
#line 54 "./binding7.w"

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
 interval kUnbind2 = 0.1, kBind3 = 9.99999, kUnbind3 = 0.1, kBind4 = 10.0;
 interval kUnbind4 = 0.1, kBind5 = 10.00001, kUnbind5 = 0.1,kBind6 = 10.00002;
 interval kUnbind6 = 0.1, kBind7 = 10.00003, kUnbind7 = 0.1;

	yp[0] = ((0.0 - kBind7)+(0.0 - kBind6)+(0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind3)+(0.0 - kBind2)+(0.0 - kBind1))*y[0]*y[1] + kUnbind1*y[2] + kUnbind2*y[3] + kUnbind3*y[4] + kUnbind4*y[5] + kUnbind5*y[6] + kUnbind6*y[7] + kUnbind7*y[8];
	yp[1] = ((0.0 - kBind7)+(0.0 - kBind6)+(0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind3)+(0.0 - kBind2)+(0.0 - kBind1))*y[0]*y[1] + ((0.0 - kBind7)+(0.0 - kBind6)+(0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind3)+(0.0 - kBind2))*y[1]*y[2] + ((0.0 - kBind7)+(0.0 - kBind6)+(0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind3)+(0.0 - kBind1))*y[1]*y[3] + ((0.0 - kBind7)+(0.0 - kBind6)+(0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[4] + ((0.0 - kBind7)+(0.0 - kBind6)+(0.0 - kBind5)+(0.0 - kBind3)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[5] + ((0.0 - kBind7)+(0.0 - kBind6)+(0.0 - kBind4)+(0.0 - kBind3)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[6] + ((0.0 - kBind7)+(0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind3)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[7] + ((0.0 - kBind6)+(0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind3)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[8] + ((0.0 - kBind7)+(0.0 - kBind6)+(0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind3))*y[1]*y[9] + ((0.0 - kBind7)+(0.0 - kBind6)+(0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind2))*y[1]*y[10] + ((0.0 - kBind7)+(0.0 - kBind6)+(0.0 - kBind5)+(0.0 - kBind3)+(0.0 - kBind2))*y[1]*y[11] + ((0.0 - kBind7)+(0.0 - kBind6)+(0.0 - kBind4)+(0.0 - kBind3)+(0.0 - kBind2))*y[1]*y[12] + ((0.0 - kBind7)+(0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind3)+(0.0 - kBind2))*y[1]*y[13] + ((0.0 - kBind6)+(0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind3)+(0.0 - kBind2))*y[1]*y[14] + ((0.0 - kBind7)+(0.0 - kBind6)+(0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind1))*y[1]*y[15] + ((0.0 - kBind7)+(0.0 - kBind6)+(0.0 - kBind5)+(0.0 - kBind3)+(0.0 - kBind1))*y[1]*y[16] + ((0.0 - kBind7)+(0.0 - kBind6)+(0.0 - kBind4)+(0.0 - kBind3)+(0.0 - kBind1))*y[1]*y[17] + ((0.0 - kBind7)+(0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind3)+(0.0 - kBind1))*y[1]*y[18] + ((0.0 - kBind6)+(0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind3)+(0.0 - kBind1))*y[1]*y[19] + ((0.0 - kBind7)+(0.0 - kBind6)+(0.0 - kBind5)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[20] + ((0.0 - kBind7)+(0.0 - kBind6)+(0.0 - kBind4)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[21] + ((0.0 - kBind7)+(0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[22] + ((0.0 - kBind6)+(0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[23] + ((0.0 - kBind7)+(0.0 - kBind6)+(0.0 - kBind3)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[24] + ((0.0 - kBind7)+(0.0 - kBind5)+(0.0 - kBind3)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[25] + ((0.0 - kBind6)+(0.0 - kBind5)+(0.0 - kBind3)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[26] + ((0.0 - kBind7)+(0.0 - kBind4)+(0.0 - kBind3)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[27] + ((0.0 - kBind6)+(0.0 - kBind4)+(0.0 - kBind3)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[28] + ((0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind3)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[29] + ((0.0 - kBind7)+(0.0 - kBind6)+(0.0 - kBind5)+(0.0 - kBind4))*y[1]*y[30] + ((0.0 - kBind7)+(0.0 - kBind6)+(0.0 - kBind5)+(0.0 - kBind3))*y[1]*y[31] + ((0.0 - kBind7)+(0.0 - kBind6)+(0.0 - kBind4)+(0.0 - kBind3))*y[1]*y[32] + ((0.0 - kBind7)+(0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind3))*y[1]*y[33] + ((0.0 - kBind6)+(0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind3))*y[1]*y[34] + ((0.0 - kBind7)+(0.0 - kBind6)+(0.0 - kBind5)+(0.0 - kBind2))*y[1]*y[35] + ((0.0 - kBind7)+(0.0 - kBind6)+(0.0 - kBind4)+(0.0 - kBind2))*y[1]*y[36] + ((0.0 - kBind7)+(0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind2))*y[1]*y[37] + ((0.0 - kBind6)+(0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind2))*y[1]*y[38] + ((0.0 - kBind7)+(0.0 - kBind6)+(0.0 - kBind3)+(0.0 - kBind2))*y[1]*y[39] + ((0.0 - kBind7)+(0.0 - kBind5)+(0.0 - kBind3)+(0.0 - kBind2))*y[1]*y[40] + ((0.0 - kBind6)+(0.0 - kBind5)+(0.0 - kBind3)+(0.0 - kBind2))*y[1]*y[41] + ((0.0 - kBind7)+(0.0 - kBind4)+(0.0 - kBind3)+(0.0 - kBind2))*y[1]*y[42] + ((0.0 - kBind6)+(0.0 - kBind4)+(0.0 - kBind3)+(0.0 - kBind2))*y[1]*y[43] + ((0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind3)+(0.0 - kBind2))*y[1]*y[44] + ((0.0 - kBind7)+(0.0 - kBind6)+(0.0 - kBind5)+(0.0 - kBind1))*y[1]*y[45] + ((0.0 - kBind7)+(0.0 - kBind6)+(0.0 - kBind4)+(0.0 - kBind1))*y[1]*y[46] + ((0.0 - kBind7)+(0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind1))*y[1]*y[47] + ((0.0 - kBind6)+(0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind1))*y[1]*y[48] + ((0.0 - kBind7)+(0.0 - kBind6)+(0.0 - kBind3)+(0.0 - kBind1))*y[1]*y[49] + ((0.0 - kBind7)+(0.0 - kBind5)+(0.0 - kBind3)+(0.0 - kBind1))*y[1]*y[50] + ((0.0 - kBind6)+(0.0 - kBind5)+(0.0 - kBind3)+(0.0 - kBind1))*y[1]*y[51] + ((0.0 - kBind7)+(0.0 - kBind4)+(0.0 - kBind3)+(0.0 - kBind1))*y[1]*y[52] + ((0.0 - kBind6)+(0.0 - kBind4)+(0.0 - kBind3)+(0.0 - kBind1))*y[1]*y[53] + ((0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind3)+(0.0 - kBind1))*y[1]*y[54] + ((0.0 - kBind7)+(0.0 - kBind6)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[55] + ((0.0 - kBind7)+(0.0 - kBind5)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[56] + ((0.0 - kBind6)+(0.0 - kBind5)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[57] + ((0.0 - kBind7)+(0.0 - kBind4)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[58] + ((0.0 - kBind6)+(0.0 - kBind4)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[59] + ((0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[60] + ((0.0 - kBind7)+(0.0 - kBind3)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[61] + ((0.0 - kBind6)+(0.0 - kBind3)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[62] + ((0.0 - kBind5)+(0.0 - kBind3)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[63] + ((0.0 - kBind4)+(0.0 - kBind3)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[64] + ((0.0 - kBind7)+(0.0 - kBind6)+(0.0 - kBind5))*y[1]*y[65] + ((0.0 - kBind7)+(0.0 - kBind6)+(0.0 - kBind4))*y[1]*y[66] + ((0.0 - kBind7)+(0.0 - kBind5)+(0.0 - kBind4))*y[1]*y[67] + ((0.0 - kBind6)+(0.0 - kBind5)+(0.0 - kBind4))*y[1]*y[68] + ((0.0 - kBind7)+(0.0 - kBind6)+(0.0 - kBind3))*y[1]*y[69] + ((0.0 - kBind7)+(0.0 - kBind5)+(0.0 - kBind3))*y[1]*y[70] + ((0.0 - kBind6)+(0.0 - kBind5)+(0.0 - kBind3))*y[1]*y[71] + ((0.0 - kBind7)+(0.0 - kBind4)+(0.0 - kBind3))*y[1]*y[72] + ((0.0 - kBind6)+(0.0 - kBind4)+(0.0 - kBind3))*y[1]*y[73] + ((0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind3))*y[1]*y[74] + ((0.0 - kBind7)+(0.0 - kBind6)+(0.0 - kBind2))*y[1]*y[75] + ((0.0 - kBind7)+(0.0 - kBind5)+(0.0 - kBind2))*y[1]*y[76] + ((0.0 - kBind6)+(0.0 - kBind5)+(0.0 - kBind2))*y[1]*y[77] + ((0.0 - kBind7)+(0.0 - kBind4)+(0.0 - kBind2))*y[1]*y[78] + ((0.0 - kBind6)+(0.0 - kBind4)+(0.0 - kBind2))*y[1]*y[79] + ((0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind2))*y[1]*y[80] + ((0.0 - kBind7)+(0.0 - kBind3)+(0.0 - kBind2))*y[1]*y[81] + ((0.0 - kBind6)+(0.0 - kBind3)+(0.0 - kBind2))*y[1]*y[82] + ((0.0 - kBind5)+(0.0 - kBind3)+(0.0 - kBind2))*y[1]*y[83] + ((0.0 - kBind4)+(0.0 - kBind3)+(0.0 - kBind2))*y[1]*y[84] + ((0.0 - kBind7)+(0.0 - kBind6)+(0.0 - kBind1))*y[1]*y[85] + ((0.0 - kBind7)+(0.0 - kBind5)+(0.0 - kBind1))*y[1]*y[86] + ((0.0 - kBind6)+(0.0 - kBind5)+(0.0 - kBind1))*y[1]*y[87] + ((0.0 - kBind7)+(0.0 - kBind4)+(0.0 - kBind1))*y[1]*y[88] + ((0.0 - kBind6)+(0.0 - kBind4)+(0.0 - kBind1))*y[1]*y[89] + ((0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind1))*y[1]*y[90] + ((0.0 - kBind7)+(0.0 - kBind3)+(0.0 - kBind1))*y[1]*y[91] + ((0.0 - kBind6)+(0.0 - kBind3)+(0.0 - kBind1))*y[1]*y[92] + ((0.0 - kBind5)+(0.0 - kBind3)+(0.0 - kBind1))*y[1]*y[93] + ((0.0 - kBind4)+(0.0 - kBind3)+(0.0 - kBind1))*y[1]*y[94] + ((0.0 - kBind7)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[95] + ((0.0 - kBind6)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[96] + ((0.0 - kBind5)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[97] + ((0.0 - kBind4)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[98] + ((0.0 - kBind3)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[99] + ((0.0 - kBind7)+(0.0 - kBind6))*y[1]*y[100] + ((0.0 - kBind7)+(0.0 - kBind5))*y[1]*y[101] + ((0.0 - kBind6)+(0.0 - kBind5))*y[1]*y[102] + ((0.0 - kBind7)+(0.0 - kBind4))*y[1]*y[103] + ((0.0 - kBind6)+(0.0 - kBind4))*y[1]*y[104] + ((0.0 - kBind5)+(0.0 - kBind4))*y[1]*y[105] + ((0.0 - kBind7)+(0.0 - kBind3))*y[1]*y[106] + ((0.0 - kBind6)+(0.0 - kBind3))*y[1]*y[107] + ((0.0 - kBind5)+(0.0 - kBind3))*y[1]*y[108] + ((0.0 - kBind4)+(0.0 - kBind3))*y[1]*y[109] + ((0.0 - kBind7)+(0.0 - kBind2))*y[1]*y[110] + ((0.0 - kBind6)+(0.0 - kBind2))*y[1]*y[111] + ((0.0 - kBind5)+(0.0 - kBind2))*y[1]*y[112] + ((0.0 - kBind4)+(0.0 - kBind2))*y[1]*y[113] + ((0.0 - kBind3)+(0.0 - kBind2))*y[1]*y[114] + ((0.0 - kBind7)+(0.0 - kBind1))*y[1]*y[115] + ((0.0 - kBind6)+(0.0 - kBind1))*y[1]*y[116] + ((0.0 - kBind5)+(0.0 - kBind1))*y[1]*y[117] + ((0.0 - kBind4)+(0.0 - kBind1))*y[1]*y[118] + ((0.0 - kBind3)+(0.0 - kBind1))*y[1]*y[119] + ((0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[120] + ((0.0 - kBind7))*y[1]*y[121] + ((0.0 - kBind6))*y[1]*y[122] + ((0.0 - kBind5))*y[1]*y[123] + ((0.0 - kBind4))*y[1]*y[124] + ((0.0 - kBind3))*y[1]*y[125] + ((0.0 - kBind2))*y[1]*y[126] + ((0.0 - kBind1))*y[1]*y[127] + kUnbind1*y[2] + kUnbind2*y[3] + kUnbind3*y[4] + kUnbind4*y[5] + kUnbind5*y[6] + kUnbind6*y[7] + kUnbind7*y[8] + (kUnbind1+kUnbind2)*y[9] + (kUnbind1+kUnbind3)*y[10] + (kUnbind1+kUnbind4)*y[11] + (kUnbind1+kUnbind5)*y[12] + (kUnbind1+kUnbind6)*y[13] + (kUnbind1+kUnbind7)*y[14] + (kUnbind2+kUnbind3)*y[15] + (kUnbind2+kUnbind4)*y[16] + (kUnbind2+kUnbind5)*y[17] + (kUnbind2+kUnbind6)*y[18] + (kUnbind2+kUnbind7)*y[19] + (kUnbind3+kUnbind4)*y[20] + (kUnbind3+kUnbind5)*y[21] + (kUnbind3+kUnbind6)*y[22] + (kUnbind3+kUnbind7)*y[23] + (kUnbind4+kUnbind5)*y[24] + (kUnbind4+kUnbind6)*y[25] + (kUnbind4+kUnbind7)*y[26] + (kUnbind5+kUnbind6)*y[27] + (kUnbind5+kUnbind7)*y[28] + (kUnbind6+kUnbind7)*y[29] + (kUnbind1+kUnbind2+kUnbind3)*y[30] + (kUnbind1+kUnbind2+kUnbind4)*y[31] + (kUnbind1+kUnbind2+kUnbind5)*y[32] + (kUnbind1+kUnbind2+kUnbind6)*y[33] + (kUnbind1+kUnbind2+kUnbind7)*y[34] + (kUnbind1+kUnbind3+kUnbind4)*y[35] + (kUnbind1+kUnbind3+kUnbind5)*y[36] + (kUnbind1+kUnbind3+kUnbind6)*y[37] + (kUnbind1+kUnbind3+kUnbind7)*y[38] + (kUnbind1+kUnbind4+kUnbind5)*y[39] + (kUnbind1+kUnbind4+kUnbind6)*y[40] + (kUnbind1+kUnbind4+kUnbind7)*y[41] + (kUnbind1+kUnbind5+kUnbind6)*y[42] + (kUnbind1+kUnbind5+kUnbind7)*y[43] + (kUnbind1+kUnbind6+kUnbind7)*y[44] + (kUnbind2+kUnbind3+kUnbind4)*y[45] + (kUnbind2+kUnbind3+kUnbind5)*y[46] + (kUnbind2+kUnbind3+kUnbind6)*y[47] + (kUnbind2+kUnbind3+kUnbind7)*y[48] + (kUnbind2+kUnbind4+kUnbind5)*y[49] + (kUnbind2+kUnbind4+kUnbind6)*y[50] + (kUnbind2+kUnbind4+kUnbind7)*y[51] + (kUnbind2+kUnbind5+kUnbind6)*y[52] + (kUnbind2+kUnbind5+kUnbind7)*y[53] + (kUnbind2+kUnbind6+kUnbind7)*y[54] + (kUnbind3+kUnbind4+kUnbind5)*y[55] + (kUnbind3+kUnbind4+kUnbind6)*y[56] + (kUnbind3+kUnbind4+kUnbind7)*y[57] + (kUnbind3+kUnbind5+kUnbind6)*y[58] + (kUnbind3+kUnbind5+kUnbind7)*y[59] + (kUnbind3+kUnbind6+kUnbind7)*y[60] + (kUnbind4+kUnbind5+kUnbind6)*y[61] + (kUnbind4+kUnbind5+kUnbind7)*y[62] + (kUnbind4+kUnbind6+kUnbind7)*y[63] + (kUnbind5+kUnbind6+kUnbind7)*y[64] + (kUnbind1+kUnbind2+kUnbind3+kUnbind4)*y[65] + (kUnbind1+kUnbind2+kUnbind3+kUnbind5)*y[66] + (kUnbind1+kUnbind2+kUnbind3+kUnbind6)*y[67] + (kUnbind1+kUnbind2+kUnbind3+kUnbind7)*y[68] + (kUnbind1+kUnbind2+kUnbind4+kUnbind5)*y[69] + (kUnbind1+kUnbind2+kUnbind4+kUnbind6)*y[70] + (kUnbind1+kUnbind2+kUnbind4+kUnbind7)*y[71] + (kUnbind1+kUnbind2+kUnbind5+kUnbind6)*y[72] + (kUnbind1+kUnbind2+kUnbind5+kUnbind7)*y[73] + (kUnbind1+kUnbind2+kUnbind6+kUnbind7)*y[74] + (kUnbind1+kUnbind3+kUnbind4+kUnbind5)*y[75] + (kUnbind1+kUnbind3+kUnbind4+kUnbind6)*y[76] + (kUnbind1+kUnbind3+kUnbind4+kUnbind7)*y[77] + (kUnbind1+kUnbind3+kUnbind5+kUnbind6)*y[78] + (kUnbind1+kUnbind3+kUnbind5+kUnbind7)*y[79] + (kUnbind1+kUnbind3+kUnbind6+kUnbind7)*y[80] + (kUnbind1+kUnbind4+kUnbind5+kUnbind6)*y[81] + (kUnbind1+kUnbind4+kUnbind5+kUnbind7)*y[82] + (kUnbind1+kUnbind4+kUnbind6+kUnbind7)*y[83] + (kUnbind1+kUnbind5+kUnbind6+kUnbind7)*y[84] + (kUnbind2+kUnbind3+kUnbind4+kUnbind5)*y[85] + (kUnbind2+kUnbind3+kUnbind4+kUnbind6)*y[86] + (kUnbind2+kUnbind3+kUnbind4+kUnbind7)*y[87] + (kUnbind2+kUnbind3+kUnbind5+kUnbind6)*y[88] + (kUnbind2+kUnbind3+kUnbind5+kUnbind7)*y[89] + (kUnbind2+kUnbind3+kUnbind6+kUnbind7)*y[90] + (kUnbind2+kUnbind4+kUnbind5+kUnbind6)*y[91] + (kUnbind2+kUnbind4+kUnbind5+kUnbind7)*y[92] + (kUnbind2+kUnbind4+kUnbind6+kUnbind7)*y[93] + (kUnbind2+kUnbind5+kUnbind6+kUnbind7)*y[94] + (kUnbind3+kUnbind4+kUnbind5+kUnbind6)*y[95] + (kUnbind3+kUnbind4+kUnbind5+kUnbind7)*y[96] + (kUnbind3+kUnbind4+kUnbind6+kUnbind7)*y[97] + (kUnbind3+kUnbind5+kUnbind6+kUnbind7)*y[98] + (kUnbind4+kUnbind5+kUnbind6+kUnbind7)*y[99] + (kUnbind1+kUnbind2+kUnbind3+kUnbind4+kUnbind5)*y[100] + (kUnbind1+kUnbind2+kUnbind3+kUnbind4+kUnbind6)*y[101] + (kUnbind1+kUnbind2+kUnbind3+kUnbind4+kUnbind7)*y[102] + (kUnbind1+kUnbind2+kUnbind3+kUnbind5+kUnbind6)*y[103] + (kUnbind1+kUnbind2+kUnbind3+kUnbind5+kUnbind7)*y[104] + (kUnbind1+kUnbind2+kUnbind3+kUnbind6+kUnbind7)*y[105] + (kUnbind1+kUnbind2+kUnbind4+kUnbind5+kUnbind6)*y[106] + (kUnbind1+kUnbind2+kUnbind4+kUnbind5+kUnbind7)*y[107] + (kUnbind1+kUnbind2+kUnbind4+kUnbind6+kUnbind7)*y[108] + (kUnbind1+kUnbind2+kUnbind5+kUnbind6+kUnbind7)*y[109] + (kUnbind1+kUnbind3+kUnbind4+kUnbind5+kUnbind6)*y[110] + (kUnbind1+kUnbind3+kUnbind4+kUnbind5+kUnbind7)*y[111] + (kUnbind1+kUnbind3+kUnbind4+kUnbind6+kUnbind7)*y[112] + (kUnbind1+kUnbind3+kUnbind5+kUnbind6+kUnbind7)*y[113] + (kUnbind1+kUnbind4+kUnbind5+kUnbind6+kUnbind7)*y[114] + (kUnbind2+kUnbind3+kUnbind4+kUnbind5+kUnbind6)*y[115] + (kUnbind2+kUnbind3+kUnbind4+kUnbind5+kUnbind7)*y[116] + (kUnbind2+kUnbind3+kUnbind4+kUnbind6+kUnbind7)*y[117] + (kUnbind2+kUnbind3+kUnbind5+kUnbind6+kUnbind7)*y[118] + (kUnbind2+kUnbind4+kUnbind5+kUnbind6+kUnbind7)*y[119] + (kUnbind3+kUnbind4+kUnbind5+kUnbind6+kUnbind7)*y[120] + (kUnbind1+kUnbind2+kUnbind3+kUnbind4+kUnbind5+kUnbind6)*y[121] + (kUnbind1+kUnbind2+kUnbind3+kUnbind4+kUnbind5+kUnbind7)*y[122] + (kUnbind1+kUnbind2+kUnbind3+kUnbind4+kUnbind6+kUnbind7)*y[123] + (kUnbind1+kUnbind2+kUnbind3+kUnbind5+kUnbind6+kUnbind7)*y[124] + (kUnbind1+kUnbind2+kUnbind4+kUnbind5+kUnbind6+kUnbind7)*y[125] + (kUnbind1+kUnbind3+kUnbind4+kUnbind5+kUnbind6+kUnbind7)*y[126] + (kUnbind2+kUnbind3+kUnbind4+kUnbind5+kUnbind6+kUnbind7)*y[127] + (kUnbind1+kUnbind2+kUnbind3+kUnbind4+kUnbind5+kUnbind6+kUnbind7)*y[128];
	yp[2] = kBind1*y[0]*y[1] + ((0.0 - kBind7)+(0.0 - kBind6)+(0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind3)+(0.0 - kBind2))*y[1]*y[2] + ((0.0 - kUnbind1))*y[2] + kUnbind2*y[9] + kUnbind3*y[10] + kUnbind4*y[11] + kUnbind5*y[12] + kUnbind6*y[13] + kUnbind7*y[14];
	yp[3] = kBind2*y[0]*y[1] + ((0.0 - kBind7)+(0.0 - kBind6)+(0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind3)+(0.0 - kBind1))*y[1]*y[3] + ((0.0 - kUnbind2))*y[3] + kUnbind1*y[9] + kUnbind3*y[15] + kUnbind4*y[16] + kUnbind5*y[17] + kUnbind6*y[18] + kUnbind7*y[19];
	yp[4] = kBind3*y[0]*y[1] + ((0.0 - kBind7)+(0.0 - kBind6)+(0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[4] + ((0.0 - kUnbind3))*y[4] + kUnbind1*y[10] + kUnbind2*y[15] + kUnbind4*y[20] + kUnbind5*y[21] + kUnbind6*y[22] + kUnbind7*y[23];
	yp[5] = kBind4*y[0]*y[1] + ((0.0 - kBind7)+(0.0 - kBind6)+(0.0 - kBind5)+(0.0 - kBind3)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[5] + ((0.0 - kUnbind4))*y[5] + kUnbind1*y[11] + kUnbind2*y[16] + kUnbind3*y[20] + kUnbind5*y[24] + kUnbind6*y[25] + kUnbind7*y[26];
	yp[6] = kBind5*y[0]*y[1] + ((0.0 - kBind7)+(0.0 - kBind6)+(0.0 - kBind4)+(0.0 - kBind3)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[6] + ((0.0 - kUnbind5))*y[6] + kUnbind1*y[12] + kUnbind2*y[17] + kUnbind3*y[21] + kUnbind4*y[24] + kUnbind6*y[27] + kUnbind7*y[28];
	yp[7] = kBind6*y[0]*y[1] + ((0.0 - kBind7)+(0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind3)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[7] + ((0.0 - kUnbind6))*y[7] + kUnbind1*y[13] + kUnbind2*y[18] + kUnbind3*y[22] + kUnbind4*y[25] + kUnbind5*y[27] + kUnbind7*y[29];
	yp[8] = kBind7*y[0]*y[1] + ((0.0 - kBind6)+(0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind3)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[8] + ((0.0 - kUnbind7))*y[8] + kUnbind1*y[14] + kUnbind2*y[19] + kUnbind3*y[23] + kUnbind4*y[26] + kUnbind5*y[28] + kUnbind6*y[29];
	yp[9] = kBind2*y[1]*y[2] + kBind1*y[1]*y[3] + ((0.0 - kBind7)+(0.0 - kBind6)+(0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind3))*y[1]*y[9] + ((0.0 - kUnbind1)+(0.0 - kUnbind2))*y[9] + kUnbind3*y[30] + kUnbind4*y[31] + kUnbind5*y[32] + kUnbind6*y[33] + kUnbind7*y[34];
	yp[10] = kBind3*y[1]*y[2] + kBind1*y[1]*y[4] + ((0.0 - kBind7)+(0.0 - kBind6)+(0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind2))*y[1]*y[10] + ((0.0 - kUnbind1)+(0.0 - kUnbind3))*y[10] + kUnbind2*y[30] + kUnbind4*y[35] + kUnbind5*y[36] + kUnbind6*y[37] + kUnbind7*y[38];
	yp[11] = kBind4*y[1]*y[2] + kBind1*y[1]*y[5] + ((0.0 - kBind7)+(0.0 - kBind6)+(0.0 - kBind5)+(0.0 - kBind3)+(0.0 - kBind2))*y[1]*y[11] + ((0.0 - kUnbind1)+(0.0 - kUnbind4))*y[11] + kUnbind2*y[31] + kUnbind3*y[35] + kUnbind5*y[39] + kUnbind6*y[40] + kUnbind7*y[41];
	yp[12] = kBind5*y[1]*y[2] + kBind1*y[1]*y[6] + ((0.0 - kBind7)+(0.0 - kBind6)+(0.0 - kBind4)+(0.0 - kBind3)+(0.0 - kBind2))*y[1]*y[12] + ((0.0 - kUnbind1)+(0.0 - kUnbind5))*y[12] + kUnbind2*y[32] + kUnbind3*y[36] + kUnbind4*y[39] + kUnbind6*y[42] + kUnbind7*y[43];
	yp[13] = kBind6*y[1]*y[2] + kBind1*y[1]*y[7] + ((0.0 - kBind7)+(0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind3)+(0.0 - kBind2))*y[1]*y[13] + ((0.0 - kUnbind1)+(0.0 - kUnbind6))*y[13] + kUnbind2*y[33] + kUnbind3*y[37] + kUnbind4*y[40] + kUnbind5*y[42] + kUnbind7*y[44];
	yp[14] = kBind7*y[1]*y[2] + kBind1*y[1]*y[8] + ((0.0 - kBind6)+(0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind3)+(0.0 - kBind2))*y[1]*y[14] + ((0.0 - kUnbind1)+(0.0 - kUnbind7))*y[14] + kUnbind2*y[34] + kUnbind3*y[38] + kUnbind4*y[41] + kUnbind5*y[43] + kUnbind6*y[44];
	yp[15] = kBind3*y[1]*y[3] + kBind2*y[1]*y[4] + ((0.0 - kBind7)+(0.0 - kBind6)+(0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind1))*y[1]*y[15] + ((0.0 - kUnbind2)+(0.0 - kUnbind3))*y[15] + kUnbind1*y[30] + kUnbind4*y[45] + kUnbind5*y[46] + kUnbind6*y[47] + kUnbind7*y[48];
	yp[16] = kBind4*y[1]*y[3] + kBind2*y[1]*y[5] + ((0.0 - kBind7)+(0.0 - kBind6)+(0.0 - kBind5)+(0.0 - kBind3)+(0.0 - kBind1))*y[1]*y[16] + ((0.0 - kUnbind2)+(0.0 - kUnbind4))*y[16] + kUnbind1*y[31] + kUnbind3*y[45] + kUnbind5*y[49] + kUnbind6*y[50] + kUnbind7*y[51];
	yp[17] = kBind5*y[1]*y[3] + kBind2*y[1]*y[6] + ((0.0 - kBind7)+(0.0 - kBind6)+(0.0 - kBind4)+(0.0 - kBind3)+(0.0 - kBind1))*y[1]*y[17] + ((0.0 - kUnbind2)+(0.0 - kUnbind5))*y[17] + kUnbind1*y[32] + kUnbind3*y[46] + kUnbind4*y[49] + kUnbind6*y[52] + kUnbind7*y[53];
	yp[18] = kBind6*y[1]*y[3] + kBind2*y[1]*y[7] + ((0.0 - kBind7)+(0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind3)+(0.0 - kBind1))*y[1]*y[18] + ((0.0 - kUnbind2)+(0.0 - kUnbind6))*y[18] + kUnbind1*y[33] + kUnbind3*y[47] + kUnbind4*y[50] + kUnbind5*y[52] + kUnbind7*y[54];
	yp[19] = kBind7*y[1]*y[3] + kBind2*y[1]*y[8] + ((0.0 - kBind6)+(0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind3)+(0.0 - kBind1))*y[1]*y[19] + ((0.0 - kUnbind2)+(0.0 - kUnbind7))*y[19] + kUnbind1*y[34] + kUnbind3*y[48] + kUnbind4*y[51] + kUnbind5*y[53] + kUnbind6*y[54];
	yp[20] = kBind4*y[1]*y[4] + kBind3*y[1]*y[5] + ((0.0 - kBind7)+(0.0 - kBind6)+(0.0 - kBind5)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[20] + ((0.0 - kUnbind3)+(0.0 - kUnbind4))*y[20] + kUnbind1*y[35] + kUnbind2*y[45] + kUnbind5*y[55] + kUnbind6*y[56] + kUnbind7*y[57];
	yp[21] = kBind5*y[1]*y[4] + kBind3*y[1]*y[6] + ((0.0 - kBind7)+(0.0 - kBind6)+(0.0 - kBind4)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[21] + ((0.0 - kUnbind3)+(0.0 - kUnbind5))*y[21] + kUnbind1*y[36] + kUnbind2*y[46] + kUnbind4*y[55] + kUnbind6*y[58] + kUnbind7*y[59];
	yp[22] = kBind6*y[1]*y[4] + kBind3*y[1]*y[7] + ((0.0 - kBind7)+(0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[22] + ((0.0 - kUnbind3)+(0.0 - kUnbind6))*y[22] + kUnbind1*y[37] + kUnbind2*y[47] + kUnbind4*y[56] + kUnbind5*y[58] + kUnbind7*y[60];
	yp[23] = kBind7*y[1]*y[4] + kBind3*y[1]*y[8] + ((0.0 - kBind6)+(0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[23] + ((0.0 - kUnbind3)+(0.0 - kUnbind7))*y[23] + kUnbind1*y[38] + kUnbind2*y[48] + kUnbind4*y[57] + kUnbind5*y[59] + kUnbind6*y[60];
	yp[24] = kBind5*y[1]*y[5] + kBind4*y[1]*y[6] + ((0.0 - kBind7)+(0.0 - kBind6)+(0.0 - kBind3)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[24] + ((0.0 - kUnbind4)+(0.0 - kUnbind5))*y[24] + kUnbind1*y[39] + kUnbind2*y[49] + kUnbind3*y[55] + kUnbind6*y[61] + kUnbind7*y[62];
	yp[25] = kBind6*y[1]*y[5] + kBind4*y[1]*y[7] + ((0.0 - kBind7)+(0.0 - kBind5)+(0.0 - kBind3)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[25] + ((0.0 - kUnbind4)+(0.0 - kUnbind6))*y[25] + kUnbind1*y[40] + kUnbind2*y[50] + kUnbind3*y[56] + kUnbind5*y[61] + kUnbind7*y[63];
	yp[26] = kBind7*y[1]*y[5] + kBind4*y[1]*y[8] + ((0.0 - kBind6)+(0.0 - kBind5)+(0.0 - kBind3)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[26] + ((0.0 - kUnbind4)+(0.0 - kUnbind7))*y[26] + kUnbind1*y[41] + kUnbind2*y[51] + kUnbind3*y[57] + kUnbind5*y[62] + kUnbind6*y[63];
	yp[27] = kBind6*y[1]*y[6] + kBind5*y[1]*y[7] + ((0.0 - kBind7)+(0.0 - kBind4)+(0.0 - kBind3)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[27] + ((0.0 - kUnbind5)+(0.0 - kUnbind6))*y[27] + kUnbind1*y[42] + kUnbind2*y[52] + kUnbind3*y[58] + kUnbind4*y[61] + kUnbind7*y[64];
	yp[28] = kBind7*y[1]*y[6] + kBind5*y[1]*y[8] + ((0.0 - kBind6)+(0.0 - kBind4)+(0.0 - kBind3)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[28] + ((0.0 - kUnbind5)+(0.0 - kUnbind7))*y[28] + kUnbind1*y[43] + kUnbind2*y[53] + kUnbind3*y[59] + kUnbind4*y[62] + kUnbind6*y[64];
	yp[29] = kBind7*y[1]*y[7] + kBind6*y[1]*y[8] + ((0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind3)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[29] + ((0.0 - kUnbind6)+(0.0 - kUnbind7))*y[29] + kUnbind1*y[44] + kUnbind2*y[54] + kUnbind3*y[60] + kUnbind4*y[63] + kUnbind5*y[64];
	yp[30] = kBind3*y[1]*y[9] + kBind2*y[1]*y[10] + kBind1*y[1]*y[15] + ((0.0 - kBind7)+(0.0 - kBind6)+(0.0 - kBind5)+(0.0 - kBind4))*y[1]*y[30] + ((0.0 - kUnbind1)+(0.0 - kUnbind2)+(0.0 - kUnbind3))*y[30] + kUnbind4*y[65] + kUnbind5*y[66] + kUnbind6*y[67] + kUnbind7*y[68];
	yp[31] = kBind4*y[1]*y[9] + kBind2*y[1]*y[11] + kBind1*y[1]*y[16] + ((0.0 - kBind7)+(0.0 - kBind6)+(0.0 - kBind5)+(0.0 - kBind3))*y[1]*y[31] + ((0.0 - kUnbind1)+(0.0 - kUnbind2)+(0.0 - kUnbind4))*y[31] + kUnbind3*y[65] + kUnbind5*y[69] + kUnbind6*y[70] + kUnbind7*y[71];
	yp[32] = kBind5*y[1]*y[9] + kBind2*y[1]*y[12] + kBind1*y[1]*y[17] + ((0.0 - kBind7)+(0.0 - kBind6)+(0.0 - kBind4)+(0.0 - kBind3))*y[1]*y[32] + ((0.0 - kUnbind1)+(0.0 - kUnbind2)+(0.0 - kUnbind5))*y[32] + kUnbind3*y[66] + kUnbind4*y[69] + kUnbind6*y[72] + kUnbind7*y[73];
	yp[33] = kBind6*y[1]*y[9] + kBind2*y[1]*y[13] + kBind1*y[1]*y[18] + ((0.0 - kBind7)+(0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind3))*y[1]*y[33] + ((0.0 - kUnbind1)+(0.0 - kUnbind2)+(0.0 - kUnbind6))*y[33] + kUnbind3*y[67] + kUnbind4*y[70] + kUnbind5*y[72] + kUnbind7*y[74];
	yp[34] = kBind7*y[1]*y[9] + kBind2*y[1]*y[14] + kBind1*y[1]*y[19] + ((0.0 - kBind6)+(0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind3))*y[1]*y[34] + ((0.0 - kUnbind1)+(0.0 - kUnbind2)+(0.0 - kUnbind7))*y[34] + kUnbind3*y[68] + kUnbind4*y[71] + kUnbind5*y[73] + kUnbind6*y[74];
	yp[35] = kBind4*y[1]*y[10] + kBind3*y[1]*y[11] + kBind1*y[1]*y[20] + ((0.0 - kBind7)+(0.0 - kBind6)+(0.0 - kBind5)+(0.0 - kBind2))*y[1]*y[35] + ((0.0 - kUnbind1)+(0.0 - kUnbind3)+(0.0 - kUnbind4))*y[35] + kUnbind2*y[65] + kUnbind5*y[75] + kUnbind6*y[76] + kUnbind7*y[77];
	yp[36] = kBind5*y[1]*y[10] + kBind3*y[1]*y[12] + kBind1*y[1]*y[21] + ((0.0 - kBind7)+(0.0 - kBind6)+(0.0 - kBind4)+(0.0 - kBind2))*y[1]*y[36] + ((0.0 - kUnbind1)+(0.0 - kUnbind3)+(0.0 - kUnbind5))*y[36] + kUnbind2*y[66] + kUnbind4*y[75] + kUnbind6*y[78] + kUnbind7*y[79];
	yp[37] = kBind6*y[1]*y[10] + kBind3*y[1]*y[13] + kBind1*y[1]*y[22] + ((0.0 - kBind7)+(0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind2))*y[1]*y[37] + ((0.0 - kUnbind1)+(0.0 - kUnbind3)+(0.0 - kUnbind6))*y[37] + kUnbind2*y[67] + kUnbind4*y[76] + kUnbind5*y[78] + kUnbind7*y[80];
	yp[38] = kBind7*y[1]*y[10] + kBind3*y[1]*y[14] + kBind1*y[1]*y[23] + ((0.0 - kBind6)+(0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind2))*y[1]*y[38] + ((0.0 - kUnbind1)+(0.0 - kUnbind3)+(0.0 - kUnbind7))*y[38] + kUnbind2*y[68] + kUnbind4*y[77] + kUnbind5*y[79] + kUnbind6*y[80];
	yp[39] = kBind5*y[1]*y[11] + kBind4*y[1]*y[12] + kBind1*y[1]*y[24] + ((0.0 - kBind7)+(0.0 - kBind6)+(0.0 - kBind3)+(0.0 - kBind2))*y[1]*y[39] + ((0.0 - kUnbind1)+(0.0 - kUnbind4)+(0.0 - kUnbind5))*y[39] + kUnbind2*y[69] + kUnbind3*y[75] + kUnbind6*y[81] + kUnbind7*y[82];
	yp[40] = kBind6*y[1]*y[11] + kBind4*y[1]*y[13] + kBind1*y[1]*y[25] + ((0.0 - kBind7)+(0.0 - kBind5)+(0.0 - kBind3)+(0.0 - kBind2))*y[1]*y[40] + ((0.0 - kUnbind1)+(0.0 - kUnbind4)+(0.0 - kUnbind6))*y[40] + kUnbind2*y[70] + kUnbind3*y[76] + kUnbind5*y[81] + kUnbind7*y[83];
	yp[41] = kBind7*y[1]*y[11] + kBind4*y[1]*y[14] + kBind1*y[1]*y[26] + ((0.0 - kBind6)+(0.0 - kBind5)+(0.0 - kBind3)+(0.0 - kBind2))*y[1]*y[41] + ((0.0 - kUnbind1)+(0.0 - kUnbind4)+(0.0 - kUnbind7))*y[41] + kUnbind2*y[71] + kUnbind3*y[77] + kUnbind5*y[82] + kUnbind6*y[83];
	yp[42] = kBind6*y[1]*y[12] + kBind5*y[1]*y[13] + kBind1*y[1]*y[27] + ((0.0 - kBind7)+(0.0 - kBind4)+(0.0 - kBind3)+(0.0 - kBind2))*y[1]*y[42] + ((0.0 - kUnbind1)+(0.0 - kUnbind5)+(0.0 - kUnbind6))*y[42] + kUnbind2*y[72] + kUnbind3*y[78] + kUnbind4*y[81] + kUnbind7*y[84];
	yp[43] = kBind7*y[1]*y[12] + kBind5*y[1]*y[14] + kBind1*y[1]*y[28] + ((0.0 - kBind6)+(0.0 - kBind4)+(0.0 - kBind3)+(0.0 - kBind2))*y[1]*y[43] + ((0.0 - kUnbind1)+(0.0 - kUnbind5)+(0.0 - kUnbind7))*y[43] + kUnbind2*y[73] + kUnbind3*y[79] + kUnbind4*y[82] + kUnbind6*y[84];
	yp[44] = kBind7*y[1]*y[13] + kBind6*y[1]*y[14] + kBind1*y[1]*y[29] + ((0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind3)+(0.0 - kBind2))*y[1]*y[44] + ((0.0 - kUnbind1)+(0.0 - kUnbind6)+(0.0 - kUnbind7))*y[44] + kUnbind2*y[74] + kUnbind3*y[80] + kUnbind4*y[83] + kUnbind5*y[84];
	yp[45] = kBind4*y[1]*y[15] + kBind3*y[1]*y[16] + kBind2*y[1]*y[20] + ((0.0 - kBind7)+(0.0 - kBind6)+(0.0 - kBind5)+(0.0 - kBind1))*y[1]*y[45] + ((0.0 - kUnbind2)+(0.0 - kUnbind3)+(0.0 - kUnbind4))*y[45] + kUnbind1*y[65] + kUnbind5*y[85] + kUnbind6*y[86] + kUnbind7*y[87];
	yp[46] = kBind5*y[1]*y[15] + kBind3*y[1]*y[17] + kBind2*y[1]*y[21] + ((0.0 - kBind7)+(0.0 - kBind6)+(0.0 - kBind4)+(0.0 - kBind1))*y[1]*y[46] + ((0.0 - kUnbind2)+(0.0 - kUnbind3)+(0.0 - kUnbind5))*y[46] + kUnbind1*y[66] + kUnbind4*y[85] + kUnbind6*y[88] + kUnbind7*y[89];
	yp[47] = kBind6*y[1]*y[15] + kBind3*y[1]*y[18] + kBind2*y[1]*y[22] + ((0.0 - kBind7)+(0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind1))*y[1]*y[47] + ((0.0 - kUnbind2)+(0.0 - kUnbind3)+(0.0 - kUnbind6))*y[47] + kUnbind1*y[67] + kUnbind4*y[86] + kUnbind5*y[88] + kUnbind7*y[90];
	yp[48] = kBind7*y[1]*y[15] + kBind3*y[1]*y[19] + kBind2*y[1]*y[23] + ((0.0 - kBind6)+(0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind1))*y[1]*y[48] + ((0.0 - kUnbind2)+(0.0 - kUnbind3)+(0.0 - kUnbind7))*y[48] + kUnbind1*y[68] + kUnbind4*y[87] + kUnbind5*y[89] + kUnbind6*y[90];
	yp[49] = kBind5*y[1]*y[16] + kBind4*y[1]*y[17] + kBind2*y[1]*y[24] + ((0.0 - kBind7)+(0.0 - kBind6)+(0.0 - kBind3)+(0.0 - kBind1))*y[1]*y[49] + ((0.0 - kUnbind2)+(0.0 - kUnbind4)+(0.0 - kUnbind5))*y[49] + kUnbind1*y[69] + kUnbind3*y[85] + kUnbind6*y[91] + kUnbind7*y[92];
	yp[50] = kBind6*y[1]*y[16] + kBind4*y[1]*y[18] + kBind2*y[1]*y[25] + ((0.0 - kBind7)+(0.0 - kBind5)+(0.0 - kBind3)+(0.0 - kBind1))*y[1]*y[50] + ((0.0 - kUnbind2)+(0.0 - kUnbind4)+(0.0 - kUnbind6))*y[50] + kUnbind1*y[70] + kUnbind3*y[86] + kUnbind5*y[91] + kUnbind7*y[93];
	yp[51] = kBind7*y[1]*y[16] + kBind4*y[1]*y[19] + kBind2*y[1]*y[26] + ((0.0 - kBind6)+(0.0 - kBind5)+(0.0 - kBind3)+(0.0 - kBind1))*y[1]*y[51] + ((0.0 - kUnbind2)+(0.0 - kUnbind4)+(0.0 - kUnbind7))*y[51] + kUnbind1*y[71] + kUnbind3*y[87] + kUnbind5*y[92] + kUnbind6*y[93];
	yp[52] = kBind6*y[1]*y[17] + kBind5*y[1]*y[18] + kBind2*y[1]*y[27] + ((0.0 - kBind7)+(0.0 - kBind4)+(0.0 - kBind3)+(0.0 - kBind1))*y[1]*y[52] + ((0.0 - kUnbind2)+(0.0 - kUnbind5)+(0.0 - kUnbind6))*y[52] + kUnbind1*y[72] + kUnbind3*y[88] + kUnbind4*y[91] + kUnbind7*y[94];
	yp[53] = kBind7*y[1]*y[17] + kBind5*y[1]*y[19] + kBind2*y[1]*y[28] + ((0.0 - kBind6)+(0.0 - kBind4)+(0.0 - kBind3)+(0.0 - kBind1))*y[1]*y[53] + ((0.0 - kUnbind2)+(0.0 - kUnbind5)+(0.0 - kUnbind7))*y[53] + kUnbind1*y[73] + kUnbind3*y[89] + kUnbind4*y[92] + kUnbind6*y[94];
	yp[54] = kBind7*y[1]*y[18] + kBind6*y[1]*y[19] + kBind2*y[1]*y[29] + ((0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind3)+(0.0 - kBind1))*y[1]*y[54] + ((0.0 - kUnbind2)+(0.0 - kUnbind6)+(0.0 - kUnbind7))*y[54] + kUnbind1*y[74] + kUnbind3*y[90] + kUnbind4*y[93] + kUnbind5*y[94];
	yp[55] = kBind5*y[1]*y[20] + kBind4*y[1]*y[21] + kBind3*y[1]*y[24] + ((0.0 - kBind7)+(0.0 - kBind6)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[55] + ((0.0 - kUnbind3)+(0.0 - kUnbind4)+(0.0 - kUnbind5))*y[55] + kUnbind1*y[75] + kUnbind2*y[85] + kUnbind6*y[95] + kUnbind7*y[96];
	yp[56] = kBind6*y[1]*y[20] + kBind4*y[1]*y[22] + kBind3*y[1]*y[25] + ((0.0 - kBind7)+(0.0 - kBind5)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[56] + ((0.0 - kUnbind3)+(0.0 - kUnbind4)+(0.0 - kUnbind6))*y[56] + kUnbind1*y[76] + kUnbind2*y[86] + kUnbind5*y[95] + kUnbind7*y[97];
	yp[57] = kBind7*y[1]*y[20] + kBind4*y[1]*y[23] + kBind3*y[1]*y[26] + ((0.0 - kBind6)+(0.0 - kBind5)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[57] + ((0.0 - kUnbind3)+(0.0 - kUnbind4)+(0.0 - kUnbind7))*y[57] + kUnbind1*y[77] + kUnbind2*y[87] + kUnbind5*y[96] + kUnbind6*y[97];
	yp[58] = kBind6*y[1]*y[21] + kBind5*y[1]*y[22] + kBind3*y[1]*y[27] + ((0.0 - kBind7)+(0.0 - kBind4)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[58] + ((0.0 - kUnbind3)+(0.0 - kUnbind5)+(0.0 - kUnbind6))*y[58] + kUnbind1*y[78] + kUnbind2*y[88] + kUnbind4*y[95] + kUnbind7*y[98];
	yp[59] = kBind7*y[1]*y[21] + kBind5*y[1]*y[23] + kBind3*y[1]*y[28] + ((0.0 - kBind6)+(0.0 - kBind4)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[59] + ((0.0 - kUnbind3)+(0.0 - kUnbind5)+(0.0 - kUnbind7))*y[59] + kUnbind1*y[79] + kUnbind2*y[89] + kUnbind4*y[96] + kUnbind6*y[98];
	yp[60] = kBind7*y[1]*y[22] + kBind6*y[1]*y[23] + kBind3*y[1]*y[29] + ((0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[60] + ((0.0 - kUnbind3)+(0.0 - kUnbind6)+(0.0 - kUnbind7))*y[60] + kUnbind1*y[80] + kUnbind2*y[90] + kUnbind4*y[97] + kUnbind5*y[98];
	yp[61] = kBind6*y[1]*y[24] + kBind5*y[1]*y[25] + kBind4*y[1]*y[27] + ((0.0 - kBind7)+(0.0 - kBind3)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[61] + ((0.0 - kUnbind4)+(0.0 - kUnbind5)+(0.0 - kUnbind6))*y[61] + kUnbind1*y[81] + kUnbind2*y[91] + kUnbind3*y[95] + kUnbind7*y[99];
	yp[62] = kBind7*y[1]*y[24] + kBind5*y[1]*y[26] + kBind4*y[1]*y[28] + ((0.0 - kBind6)+(0.0 - kBind3)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[62] + ((0.0 - kUnbind4)+(0.0 - kUnbind5)+(0.0 - kUnbind7))*y[62] + kUnbind1*y[82] + kUnbind2*y[92] + kUnbind3*y[96] + kUnbind6*y[99];
	yp[63] = kBind7*y[1]*y[25] + kBind6*y[1]*y[26] + kBind4*y[1]*y[29] + ((0.0 - kBind5)+(0.0 - kBind3)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[63] + ((0.0 - kUnbind4)+(0.0 - kUnbind6)+(0.0 - kUnbind7))*y[63] + kUnbind1*y[83] + kUnbind2*y[93] + kUnbind3*y[97] + kUnbind5*y[99];
	yp[64] = kBind7*y[1]*y[27] + kBind6*y[1]*y[28] + kBind5*y[1]*y[29] + ((0.0 - kBind4)+(0.0 - kBind3)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[64] + ((0.0 - kUnbind5)+(0.0 - kUnbind6)+(0.0 - kUnbind7))*y[64] + kUnbind1*y[84] + kUnbind2*y[94] + kUnbind3*y[98] + kUnbind4*y[99];
	yp[65] = kBind4*y[1]*y[30] + kBind3*y[1]*y[31] + kBind2*y[1]*y[35] + kBind1*y[1]*y[45] + ((0.0 - kBind7)+(0.0 - kBind6)+(0.0 - kBind5))*y[1]*y[65] + ((0.0 - kUnbind1)+(0.0 - kUnbind2)+(0.0 - kUnbind3)+(0.0 - kUnbind4))*y[65] + kUnbind5*y[100] + kUnbind6*y[101] + kUnbind7*y[102];
	yp[66] = kBind5*y[1]*y[30] + kBind3*y[1]*y[32] + kBind2*y[1]*y[36] + kBind1*y[1]*y[46] + ((0.0 - kBind7)+(0.0 - kBind6)+(0.0 - kBind4))*y[1]*y[66] + ((0.0 - kUnbind1)+(0.0 - kUnbind2)+(0.0 - kUnbind3)+(0.0 - kUnbind5))*y[66] + kUnbind4*y[100] + kUnbind6*y[103] + kUnbind7*y[104];
	yp[67] = kBind6*y[1]*y[30] + kBind3*y[1]*y[33] + kBind2*y[1]*y[37] + kBind1*y[1]*y[47] + ((0.0 - kBind7)+(0.0 - kBind5)+(0.0 - kBind4))*y[1]*y[67] + ((0.0 - kUnbind1)+(0.0 - kUnbind2)+(0.0 - kUnbind3)+(0.0 - kUnbind6))*y[67] + kUnbind4*y[101] + kUnbind5*y[103] + kUnbind7*y[105];
	yp[68] = kBind7*y[1]*y[30] + kBind3*y[1]*y[34] + kBind2*y[1]*y[38] + kBind1*y[1]*y[48] + ((0.0 - kBind6)+(0.0 - kBind5)+(0.0 - kBind4))*y[1]*y[68] + ((0.0 - kUnbind1)+(0.0 - kUnbind2)+(0.0 - kUnbind3)+(0.0 - kUnbind7))*y[68] + kUnbind4*y[102] + kUnbind5*y[104] + kUnbind6*y[105];
	yp[69] = kBind5*y[1]*y[31] + kBind4*y[1]*y[32] + kBind2*y[1]*y[39] + kBind1*y[1]*y[49] + ((0.0 - kBind7)+(0.0 - kBind6)+(0.0 - kBind3))*y[1]*y[69] + ((0.0 - kUnbind1)+(0.0 - kUnbind2)+(0.0 - kUnbind4)+(0.0 - kUnbind5))*y[69] + kUnbind3*y[100] + kUnbind6*y[106] + kUnbind7*y[107];
	yp[70] = kBind6*y[1]*y[31] + kBind4*y[1]*y[33] + kBind2*y[1]*y[40] + kBind1*y[1]*y[50] + ((0.0 - kBind7)+(0.0 - kBind5)+(0.0 - kBind3))*y[1]*y[70] + ((0.0 - kUnbind1)+(0.0 - kUnbind2)+(0.0 - kUnbind4)+(0.0 - kUnbind6))*y[70] + kUnbind3*y[101] + kUnbind5*y[106] + kUnbind7*y[108];
	yp[71] = kBind7*y[1]*y[31] + kBind4*y[1]*y[34] + kBind2*y[1]*y[41] + kBind1*y[1]*y[51] + ((0.0 - kBind6)+(0.0 - kBind5)+(0.0 - kBind3))*y[1]*y[71] + ((0.0 - kUnbind1)+(0.0 - kUnbind2)+(0.0 - kUnbind4)+(0.0 - kUnbind7))*y[71] + kUnbind3*y[102] + kUnbind5*y[107] + kUnbind6*y[108];
	yp[72] = kBind6*y[1]*y[32] + kBind5*y[1]*y[33] + kBind2*y[1]*y[42] + kBind1*y[1]*y[52] + ((0.0 - kBind7)+(0.0 - kBind4)+(0.0 - kBind3))*y[1]*y[72] + ((0.0 - kUnbind1)+(0.0 - kUnbind2)+(0.0 - kUnbind5)+(0.0 - kUnbind6))*y[72] + kUnbind3*y[103] + kUnbind4*y[106] + kUnbind7*y[109];
	yp[73] = kBind7*y[1]*y[32] + kBind5*y[1]*y[34] + kBind2*y[1]*y[43] + kBind1*y[1]*y[53] + ((0.0 - kBind6)+(0.0 - kBind4)+(0.0 - kBind3))*y[1]*y[73] + ((0.0 - kUnbind1)+(0.0 - kUnbind2)+(0.0 - kUnbind5)+(0.0 - kUnbind7))*y[73] + kUnbind3*y[104] + kUnbind4*y[107] + kUnbind6*y[109];
	yp[74] = kBind7*y[1]*y[33] + kBind6*y[1]*y[34] + kBind2*y[1]*y[44] + kBind1*y[1]*y[54] + ((0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind3))*y[1]*y[74] + ((0.0 - kUnbind1)+(0.0 - kUnbind2)+(0.0 - kUnbind6)+(0.0 - kUnbind7))*y[74] + kUnbind3*y[105] + kUnbind4*y[108] + kUnbind5*y[109];
	yp[75] = kBind5*y[1]*y[35] + kBind4*y[1]*y[36] + kBind3*y[1]*y[39] + kBind1*y[1]*y[55] + ((0.0 - kBind7)+(0.0 - kBind6)+(0.0 - kBind2))*y[1]*y[75] + ((0.0 - kUnbind1)+(0.0 - kUnbind3)+(0.0 - kUnbind4)+(0.0 - kUnbind5))*y[75] + kUnbind2*y[100] + kUnbind6*y[110] + kUnbind7*y[111];
	yp[76] = kBind6*y[1]*y[35] + kBind4*y[1]*y[37] + kBind3*y[1]*y[40] + kBind1*y[1]*y[56] + ((0.0 - kBind7)+(0.0 - kBind5)+(0.0 - kBind2))*y[1]*y[76] + ((0.0 - kUnbind1)+(0.0 - kUnbind3)+(0.0 - kUnbind4)+(0.0 - kUnbind6))*y[76] + kUnbind2*y[101] + kUnbind5*y[110] + kUnbind7*y[112];
	yp[77] = kBind7*y[1]*y[35] + kBind4*y[1]*y[38] + kBind3*y[1]*y[41] + kBind1*y[1]*y[57] + ((0.0 - kBind6)+(0.0 - kBind5)+(0.0 - kBind2))*y[1]*y[77] + ((0.0 - kUnbind1)+(0.0 - kUnbind3)+(0.0 - kUnbind4)+(0.0 - kUnbind7))*y[77] + kUnbind2*y[102] + kUnbind5*y[111] + kUnbind6*y[112];
	yp[78] = kBind6*y[1]*y[36] + kBind5*y[1]*y[37] + kBind3*y[1]*y[42] + kBind1*y[1]*y[58] + ((0.0 - kBind7)+(0.0 - kBind4)+(0.0 - kBind2))*y[1]*y[78] + ((0.0 - kUnbind1)+(0.0 - kUnbind3)+(0.0 - kUnbind5)+(0.0 - kUnbind6))*y[78] + kUnbind2*y[103] + kUnbind4*y[110] + kUnbind7*y[113];
	yp[79] = kBind7*y[1]*y[36] + kBind5*y[1]*y[38] + kBind3*y[1]*y[43] + kBind1*y[1]*y[59] + ((0.0 - kBind6)+(0.0 - kBind4)+(0.0 - kBind2))*y[1]*y[79] + ((0.0 - kUnbind1)+(0.0 - kUnbind3)+(0.0 - kUnbind5)+(0.0 - kUnbind7))*y[79] + kUnbind2*y[104] + kUnbind4*y[111] + kUnbind6*y[113];
	yp[80] = kBind7*y[1]*y[37] + kBind6*y[1]*y[38] + kBind3*y[1]*y[44] + kBind1*y[1]*y[60] + ((0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind2))*y[1]*y[80] + ((0.0 - kUnbind1)+(0.0 - kUnbind3)+(0.0 - kUnbind6)+(0.0 - kUnbind7))*y[80] + kUnbind2*y[105] + kUnbind4*y[112] + kUnbind5*y[113];
	yp[81] = kBind6*y[1]*y[39] + kBind5*y[1]*y[40] + kBind4*y[1]*y[42] + kBind1*y[1]*y[61] + ((0.0 - kBind7)+(0.0 - kBind3)+(0.0 - kBind2))*y[1]*y[81] + ((0.0 - kUnbind1)+(0.0 - kUnbind4)+(0.0 - kUnbind5)+(0.0 - kUnbind6))*y[81] + kUnbind2*y[106] + kUnbind3*y[110] + kUnbind7*y[114];
	yp[82] = kBind7*y[1]*y[39] + kBind5*y[1]*y[41] + kBind4*y[1]*y[43] + kBind1*y[1]*y[62] + ((0.0 - kBind6)+(0.0 - kBind3)+(0.0 - kBind2))*y[1]*y[82] + ((0.0 - kUnbind1)+(0.0 - kUnbind4)+(0.0 - kUnbind5)+(0.0 - kUnbind7))*y[82] + kUnbind2*y[107] + kUnbind3*y[111] + kUnbind6*y[114];
	yp[83] = kBind7*y[1]*y[40] + kBind6*y[1]*y[41] + kBind4*y[1]*y[44] + kBind1*y[1]*y[63] + ((0.0 - kBind5)+(0.0 - kBind3)+(0.0 - kBind2))*y[1]*y[83] + ((0.0 - kUnbind1)+(0.0 - kUnbind4)+(0.0 - kUnbind6)+(0.0 - kUnbind7))*y[83] + kUnbind2*y[108] + kUnbind3*y[112] + kUnbind5*y[114];
	yp[84] = kBind7*y[1]*y[42] + kBind6*y[1]*y[43] + kBind5*y[1]*y[44] + kBind1*y[1]*y[64] + ((0.0 - kBind4)+(0.0 - kBind3)+(0.0 - kBind2))*y[1]*y[84] + ((0.0 - kUnbind1)+(0.0 - kUnbind5)+(0.0 - kUnbind6)+(0.0 - kUnbind7))*y[84] + kUnbind2*y[109] + kUnbind3*y[113] + kUnbind4*y[114];
	yp[85] = kBind5*y[1]*y[45] + kBind4*y[1]*y[46] + kBind3*y[1]*y[49] + kBind2*y[1]*y[55] + ((0.0 - kBind7)+(0.0 - kBind6)+(0.0 - kBind1))*y[1]*y[85] + ((0.0 - kUnbind2)+(0.0 - kUnbind3)+(0.0 - kUnbind4)+(0.0 - kUnbind5))*y[85] + kUnbind1*y[100] + kUnbind6*y[115] + kUnbind7*y[116];
	yp[86] = kBind6*y[1]*y[45] + kBind4*y[1]*y[47] + kBind3*y[1]*y[50] + kBind2*y[1]*y[56] + ((0.0 - kBind7)+(0.0 - kBind5)+(0.0 - kBind1))*y[1]*y[86] + ((0.0 - kUnbind2)+(0.0 - kUnbind3)+(0.0 - kUnbind4)+(0.0 - kUnbind6))*y[86] + kUnbind1*y[101] + kUnbind5*y[115] + kUnbind7*y[117];
	yp[87] = kBind7*y[1]*y[45] + kBind4*y[1]*y[48] + kBind3*y[1]*y[51] + kBind2*y[1]*y[57] + ((0.0 - kBind6)+(0.0 - kBind5)+(0.0 - kBind1))*y[1]*y[87] + ((0.0 - kUnbind2)+(0.0 - kUnbind3)+(0.0 - kUnbind4)+(0.0 - kUnbind7))*y[87] + kUnbind1*y[102] + kUnbind5*y[116] + kUnbind6*y[117];
	yp[88] = kBind6*y[1]*y[46] + kBind5*y[1]*y[47] + kBind3*y[1]*y[52] + kBind2*y[1]*y[58] + ((0.0 - kBind7)+(0.0 - kBind4)+(0.0 - kBind1))*y[1]*y[88] + ((0.0 - kUnbind2)+(0.0 - kUnbind3)+(0.0 - kUnbind5)+(0.0 - kUnbind6))*y[88] + kUnbind1*y[103] + kUnbind4*y[115] + kUnbind7*y[118];
	yp[89] = kBind7*y[1]*y[46] + kBind5*y[1]*y[48] + kBind3*y[1]*y[53] + kBind2*y[1]*y[59] + ((0.0 - kBind6)+(0.0 - kBind4)+(0.0 - kBind1))*y[1]*y[89] + ((0.0 - kUnbind2)+(0.0 - kUnbind3)+(0.0 - kUnbind5)+(0.0 - kUnbind7))*y[89] + kUnbind1*y[104] + kUnbind4*y[116] + kUnbind6*y[118];
	yp[90] = kBind7*y[1]*y[47] + kBind6*y[1]*y[48] + kBind3*y[1]*y[54] + kBind2*y[1]*y[60] + ((0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind1))*y[1]*y[90] + ((0.0 - kUnbind2)+(0.0 - kUnbind3)+(0.0 - kUnbind6)+(0.0 - kUnbind7))*y[90] + kUnbind1*y[105] + kUnbind4*y[117] + kUnbind5*y[118];
	yp[91] = kBind6*y[1]*y[49] + kBind5*y[1]*y[50] + kBind4*y[1]*y[52] + kBind2*y[1]*y[61] + ((0.0 - kBind7)+(0.0 - kBind3)+(0.0 - kBind1))*y[1]*y[91] + ((0.0 - kUnbind2)+(0.0 - kUnbind4)+(0.0 - kUnbind5)+(0.0 - kUnbind6))*y[91] + kUnbind1*y[106] + kUnbind3*y[115] + kUnbind7*y[119];
	yp[92] = kBind7*y[1]*y[49] + kBind5*y[1]*y[51] + kBind4*y[1]*y[53] + kBind2*y[1]*y[62] + ((0.0 - kBind6)+(0.0 - kBind3)+(0.0 - kBind1))*y[1]*y[92] + ((0.0 - kUnbind2)+(0.0 - kUnbind4)+(0.0 - kUnbind5)+(0.0 - kUnbind7))*y[92] + kUnbind1*y[107] + kUnbind3*y[116] + kUnbind6*y[119];
	yp[93] = kBind7*y[1]*y[50] + kBind6*y[1]*y[51] + kBind4*y[1]*y[54] + kBind2*y[1]*y[63] + ((0.0 - kBind5)+(0.0 - kBind3)+(0.0 - kBind1))*y[1]*y[93] + ((0.0 - kUnbind2)+(0.0 - kUnbind4)+(0.0 - kUnbind6)+(0.0 - kUnbind7))*y[93] + kUnbind1*y[108] + kUnbind3*y[117] + kUnbind5*y[119];
	yp[94] = kBind7*y[1]*y[52] + kBind6*y[1]*y[53] + kBind5*y[1]*y[54] + kBind2*y[1]*y[64] + ((0.0 - kBind4)+(0.0 - kBind3)+(0.0 - kBind1))*y[1]*y[94] + ((0.0 - kUnbind2)+(0.0 - kUnbind5)+(0.0 - kUnbind6)+(0.0 - kUnbind7))*y[94] + kUnbind1*y[109] + kUnbind3*y[118] + kUnbind4*y[119];
	yp[95] = kBind6*y[1]*y[55] + kBind5*y[1]*y[56] + kBind4*y[1]*y[58] + kBind3*y[1]*y[61] + ((0.0 - kBind7)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[95] + ((0.0 - kUnbind3)+(0.0 - kUnbind4)+(0.0 - kUnbind5)+(0.0 - kUnbind6))*y[95] + kUnbind1*y[110] + kUnbind2*y[115] + kUnbind7*y[120];
	yp[96] = kBind7*y[1]*y[55] + kBind5*y[1]*y[57] + kBind4*y[1]*y[59] + kBind3*y[1]*y[62] + ((0.0 - kBind6)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[96] + ((0.0 - kUnbind3)+(0.0 - kUnbind4)+(0.0 - kUnbind5)+(0.0 - kUnbind7))*y[96] + kUnbind1*y[111] + kUnbind2*y[116] + kUnbind6*y[120];
	yp[97] = kBind7*y[1]*y[56] + kBind6*y[1]*y[57] + kBind4*y[1]*y[60] + kBind3*y[1]*y[63] + ((0.0 - kBind5)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[97] + ((0.0 - kUnbind3)+(0.0 - kUnbind4)+(0.0 - kUnbind6)+(0.0 - kUnbind7))*y[97] + kUnbind1*y[112] + kUnbind2*y[117] + kUnbind5*y[120];
	yp[98] = kBind7*y[1]*y[58] + kBind6*y[1]*y[59] + kBind5*y[1]*y[60] + kBind3*y[1]*y[64] + ((0.0 - kBind4)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[98] + ((0.0 - kUnbind3)+(0.0 - kUnbind5)+(0.0 - kUnbind6)+(0.0 - kUnbind7))*y[98] + kUnbind1*y[113] + kUnbind2*y[118] + kUnbind4*y[120];
	yp[99] = kBind7*y[1]*y[61] + kBind6*y[1]*y[62] + kBind5*y[1]*y[63] + kBind4*y[1]*y[64] + ((0.0 - kBind3)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[99] + ((0.0 - kUnbind4)+(0.0 - kUnbind5)+(0.0 - kUnbind6)+(0.0 - kUnbind7))*y[99] + kUnbind1*y[114] + kUnbind2*y[119] + kUnbind3*y[120];
	yp[100] = kBind5*y[1]*y[65] + kBind4*y[1]*y[66] + kBind3*y[1]*y[69] + kBind2*y[1]*y[75] + kBind1*y[1]*y[85] + ((0.0 - kBind7)+(0.0 - kBind6))*y[1]*y[100] + ((0.0 - kUnbind1)+(0.0 - kUnbind2)+(0.0 - kUnbind3)+(0.0 - kUnbind4)+(0.0 - kUnbind5))*y[100] + kUnbind6*y[121] + kUnbind7*y[122];
	yp[101] = kBind6*y[1]*y[65] + kBind4*y[1]*y[67] + kBind3*y[1]*y[70] + kBind2*y[1]*y[76] + kBind1*y[1]*y[86] + ((0.0 - kBind7)+(0.0 - kBind5))*y[1]*y[101] + ((0.0 - kUnbind1)+(0.0 - kUnbind2)+(0.0 - kUnbind3)+(0.0 - kUnbind4)+(0.0 - kUnbind6))*y[101] + kUnbind5*y[121] + kUnbind7*y[123];
	yp[102] = kBind7*y[1]*y[65] + kBind4*y[1]*y[68] + kBind3*y[1]*y[71] + kBind2*y[1]*y[77] + kBind1*y[1]*y[87] + ((0.0 - kBind6)+(0.0 - kBind5))*y[1]*y[102] + ((0.0 - kUnbind1)+(0.0 - kUnbind2)+(0.0 - kUnbind3)+(0.0 - kUnbind4)+(0.0 - kUnbind7))*y[102] + kUnbind5*y[122] + kUnbind6*y[123];
	yp[103] = kBind6*y[1]*y[66] + kBind5*y[1]*y[67] + kBind3*y[1]*y[72] + kBind2*y[1]*y[78] + kBind1*y[1]*y[88] + ((0.0 - kBind7)+(0.0 - kBind4))*y[1]*y[103] + ((0.0 - kUnbind1)+(0.0 - kUnbind2)+(0.0 - kUnbind3)+(0.0 - kUnbind5)+(0.0 - kUnbind6))*y[103] + kUnbind4*y[121] + kUnbind7*y[124];
	yp[104] = kBind7*y[1]*y[66] + kBind5*y[1]*y[68] + kBind3*y[1]*y[73] + kBind2*y[1]*y[79] + kBind1*y[1]*y[89] + ((0.0 - kBind6)+(0.0 - kBind4))*y[1]*y[104] + ((0.0 - kUnbind1)+(0.0 - kUnbind2)+(0.0 - kUnbind3)+(0.0 - kUnbind5)+(0.0 - kUnbind7))*y[104] + kUnbind4*y[122] + kUnbind6*y[124];
	yp[105] = kBind7*y[1]*y[67] + kBind6*y[1]*y[68] + kBind3*y[1]*y[74] + kBind2*y[1]*y[80] + kBind1*y[1]*y[90] + ((0.0 - kBind5)+(0.0 - kBind4))*y[1]*y[105] + ((0.0 - kUnbind1)+(0.0 - kUnbind2)+(0.0 - kUnbind3)+(0.0 - kUnbind6)+(0.0 - kUnbind7))*y[105] + kUnbind4*y[123] + kUnbind5*y[124];
	yp[106] = kBind6*y[1]*y[69] + kBind5*y[1]*y[70] + kBind4*y[1]*y[72] + kBind2*y[1]*y[81] + kBind1*y[1]*y[91] + ((0.0 - kBind7)+(0.0 - kBind3))*y[1]*y[106] + ((0.0 - kUnbind1)+(0.0 - kUnbind2)+(0.0 - kUnbind4)+(0.0 - kUnbind5)+(0.0 - kUnbind6))*y[106] + kUnbind3*y[121] + kUnbind7*y[125];
	yp[107] = kBind7*y[1]*y[69] + kBind5*y[1]*y[71] + kBind4*y[1]*y[73] + kBind2*y[1]*y[82] + kBind1*y[1]*y[92] + ((0.0 - kBind6)+(0.0 - kBind3))*y[1]*y[107] + ((0.0 - kUnbind1)+(0.0 - kUnbind2)+(0.0 - kUnbind4)+(0.0 - kUnbind5)+(0.0 - kUnbind7))*y[107] + kUnbind3*y[122] + kUnbind6*y[125];
	yp[108] = kBind7*y[1]*y[70] + kBind6*y[1]*y[71] + kBind4*y[1]*y[74] + kBind2*y[1]*y[83] + kBind1*y[1]*y[93] + ((0.0 - kBind5)+(0.0 - kBind3))*y[1]*y[108] + ((0.0 - kUnbind1)+(0.0 - kUnbind2)+(0.0 - kUnbind4)+(0.0 - kUnbind6)+(0.0 - kUnbind7))*y[108] + kUnbind3*y[123] + kUnbind5*y[125];
	yp[109] = kBind7*y[1]*y[72] + kBind6*y[1]*y[73] + kBind5*y[1]*y[74] + kBind2*y[1]*y[84] + kBind1*y[1]*y[94] + ((0.0 - kBind4)+(0.0 - kBind3))*y[1]*y[109] + ((0.0 - kUnbind1)+(0.0 - kUnbind2)+(0.0 - kUnbind5)+(0.0 - kUnbind6)+(0.0 - kUnbind7))*y[109] + kUnbind3*y[124] + kUnbind4*y[125];
	yp[110] = kBind6*y[1]*y[75] + kBind5*y[1]*y[76] + kBind4*y[1]*y[78] + kBind3*y[1]*y[81] + kBind1*y[1]*y[95] + ((0.0 - kBind7)+(0.0 - kBind2))*y[1]*y[110] + ((0.0 - kUnbind1)+(0.0 - kUnbind3)+(0.0 - kUnbind4)+(0.0 - kUnbind5)+(0.0 - kUnbind6))*y[110] + kUnbind2*y[121] + kUnbind7*y[126];
	yp[111] = kBind7*y[1]*y[75] + kBind5*y[1]*y[77] + kBind4*y[1]*y[79] + kBind3*y[1]*y[82] + kBind1*y[1]*y[96] + ((0.0 - kBind6)+(0.0 - kBind2))*y[1]*y[111] + ((0.0 - kUnbind1)+(0.0 - kUnbind3)+(0.0 - kUnbind4)+(0.0 - kUnbind5)+(0.0 - kUnbind7))*y[111] + kUnbind2*y[122] + kUnbind6*y[126];
	yp[112] = kBind7*y[1]*y[76] + kBind6*y[1]*y[77] + kBind4*y[1]*y[80] + kBind3*y[1]*y[83] + kBind1*y[1]*y[97] + ((0.0 - kBind5)+(0.0 - kBind2))*y[1]*y[112] + ((0.0 - kUnbind1)+(0.0 - kUnbind3)+(0.0 - kUnbind4)+(0.0 - kUnbind6)+(0.0 - kUnbind7))*y[112] + kUnbind2*y[123] + kUnbind5*y[126];
	yp[113] = kBind7*y[1]*y[78] + kBind6*y[1]*y[79] + kBind5*y[1]*y[80] + kBind3*y[1]*y[84] + kBind1*y[1]*y[98] + ((0.0 - kBind4)+(0.0 - kBind2))*y[1]*y[113] + ((0.0 - kUnbind1)+(0.0 - kUnbind3)+(0.0 - kUnbind5)+(0.0 - kUnbind6)+(0.0 - kUnbind7))*y[113] + kUnbind2*y[124] + kUnbind4*y[126];
	yp[114] = kBind7*y[1]*y[81] + kBind6*y[1]*y[82] + kBind5*y[1]*y[83] + kBind4*y[1]*y[84] + kBind1*y[1]*y[99] + ((0.0 - kBind3)+(0.0 - kBind2))*y[1]*y[114] + ((0.0 - kUnbind1)+(0.0 - kUnbind4)+(0.0 - kUnbind5)+(0.0 - kUnbind6)+(0.0 - kUnbind7))*y[114] + kUnbind2*y[125] + kUnbind3*y[126];
	yp[115] = kBind6*y[1]*y[85] + kBind5*y[1]*y[86] + kBind4*y[1]*y[88] + kBind3*y[1]*y[91] + kBind2*y[1]*y[95] + ((0.0 - kBind7)+(0.0 - kBind1))*y[1]*y[115] + ((0.0 - kUnbind2)+(0.0 - kUnbind3)+(0.0 - kUnbind4)+(0.0 - kUnbind5)+(0.0 - kUnbind6))*y[115] + kUnbind1*y[121] + kUnbind7*y[127];
	yp[116] = kBind7*y[1]*y[85] + kBind5*y[1]*y[87] + kBind4*y[1]*y[89] + kBind3*y[1]*y[92] + kBind2*y[1]*y[96] + ((0.0 - kBind6)+(0.0 - kBind1))*y[1]*y[116] + ((0.0 - kUnbind2)+(0.0 - kUnbind3)+(0.0 - kUnbind4)+(0.0 - kUnbind5)+(0.0 - kUnbind7))*y[116] + kUnbind1*y[122] + kUnbind6*y[127];
	yp[117] = kBind7*y[1]*y[86] + kBind6*y[1]*y[87] + kBind4*y[1]*y[90] + kBind3*y[1]*y[93] + kBind2*y[1]*y[97] + ((0.0 - kBind5)+(0.0 - kBind1))*y[1]*y[117] + ((0.0 - kUnbind2)+(0.0 - kUnbind3)+(0.0 - kUnbind4)+(0.0 - kUnbind6)+(0.0 - kUnbind7))*y[117] + kUnbind1*y[123] + kUnbind5*y[127];
	yp[118] = kBind7*y[1]*y[88] + kBind6*y[1]*y[89] + kBind5*y[1]*y[90] + kBind3*y[1]*y[94] + kBind2*y[1]*y[98] + ((0.0 - kBind4)+(0.0 - kBind1))*y[1]*y[118] + ((0.0 - kUnbind2)+(0.0 - kUnbind3)+(0.0 - kUnbind5)+(0.0 - kUnbind6)+(0.0 - kUnbind7))*y[118] + kUnbind1*y[124] + kUnbind4*y[127];
	yp[119] = kBind7*y[1]*y[91] + kBind6*y[1]*y[92] + kBind5*y[1]*y[93] + kBind4*y[1]*y[94] + kBind2*y[1]*y[99] + ((0.0 - kBind3)+(0.0 - kBind1))*y[1]*y[119] + ((0.0 - kUnbind2)+(0.0 - kUnbind4)+(0.0 - kUnbind5)+(0.0 - kUnbind6)+(0.0 - kUnbind7))*y[119] + kUnbind1*y[125] + kUnbind3*y[127];
	yp[120] = kBind7*y[1]*y[95] + kBind6*y[1]*y[96] + kBind5*y[1]*y[97] + kBind4*y[1]*y[98] + kBind3*y[1]*y[99] + ((0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[120] + ((0.0 - kUnbind3)+(0.0 - kUnbind4)+(0.0 - kUnbind5)+(0.0 - kUnbind6)+(0.0 - kUnbind7))*y[120] + kUnbind1*y[126] + kUnbind2*y[127];
	yp[121] = kBind6*y[1]*y[100] + kBind5*y[1]*y[101] + kBind4*y[1]*y[103] + kBind3*y[1]*y[106] + kBind2*y[1]*y[110] + kBind1*y[1]*y[115] + ((0.0 - kBind7))*y[1]*y[121] + ((0.0 - kUnbind1)+(0.0 - kUnbind2)+(0.0 - kUnbind3)+(0.0 - kUnbind4)+(0.0 - kUnbind5)+(0.0 - kUnbind6))*y[121] + kUnbind7*y[128];
	yp[122] = kBind7*y[1]*y[100] + kBind5*y[1]*y[102] + kBind4*y[1]*y[104] + kBind3*y[1]*y[107] + kBind2*y[1]*y[111] + kBind1*y[1]*y[116] + ((0.0 - kBind6))*y[1]*y[122] + ((0.0 - kUnbind1)+(0.0 - kUnbind2)+(0.0 - kUnbind3)+(0.0 - kUnbind4)+(0.0 - kUnbind5)+(0.0 - kUnbind7))*y[122] + kUnbind6*y[128];
	yp[123] = kBind7*y[1]*y[101] + kBind6*y[1]*y[102] + kBind4*y[1]*y[105] + kBind3*y[1]*y[108] + kBind2*y[1]*y[112] + kBind1*y[1]*y[117] + ((0.0 - kBind5))*y[1]*y[123] + ((0.0 - kUnbind1)+(0.0 - kUnbind2)+(0.0 - kUnbind3)+(0.0 - kUnbind4)+(0.0 - kUnbind6)+(0.0 - kUnbind7))*y[123] + kUnbind5*y[128];
	yp[124] = kBind7*y[1]*y[103] + kBind6*y[1]*y[104] + kBind5*y[1]*y[105] + kBind3*y[1]*y[109] + kBind2*y[1]*y[113] + kBind1*y[1]*y[118] + ((0.0 - kBind4))*y[1]*y[124] + ((0.0 - kUnbind1)+(0.0 - kUnbind2)+(0.0 - kUnbind3)+(0.0 - kUnbind5)+(0.0 - kUnbind6)+(0.0 - kUnbind7))*y[124] + kUnbind4*y[128];
	yp[125] = kBind7*y[1]*y[106] + kBind6*y[1]*y[107] + kBind5*y[1]*y[108] + kBind4*y[1]*y[109] + kBind2*y[1]*y[114] + kBind1*y[1]*y[119] + ((0.0 - kBind3))*y[1]*y[125] + ((0.0 - kUnbind1)+(0.0 - kUnbind2)+(0.0 - kUnbind4)+(0.0 - kUnbind5)+(0.0 - kUnbind6)+(0.0 - kUnbind7))*y[125] + kUnbind3*y[128];
	yp[126] = kBind7*y[1]*y[110] + kBind6*y[1]*y[111] + kBind5*y[1]*y[112] + kBind4*y[1]*y[113] + kBind3*y[1]*y[114] + kBind1*y[1]*y[120] + ((0.0 - kBind2))*y[1]*y[126] + ((0.0 - kUnbind1)+(0.0 - kUnbind3)+(0.0 - kUnbind4)+(0.0 - kUnbind5)+(0.0 - kUnbind6)+(0.0 - kUnbind7))*y[126] + kUnbind2*y[128];
	yp[127] = kBind7*y[1]*y[115] + kBind6*y[1]*y[116] + kBind5*y[1]*y[117] + kBind4*y[1]*y[118] + kBind3*y[1]*y[119] + kBind2*y[1]*y[120] + ((0.0 - kBind1))*y[1]*y[127] + ((0.0 - kUnbind2)+(0.0 - kUnbind3)+(0.0 - kUnbind4)+(0.0 - kUnbind5)+(0.0 - kUnbind6)+(0.0 - kUnbind7))*y[127] + kUnbind1*y[128];
	yp[128] = kBind7*y[1]*y[121] + kBind6*y[1]*y[122] + kBind5*y[1]*y[123] + kBind4*y[1]*y[124] + kBind3*y[1]*y[125] + kBind2*y[1]*y[126] + kBind1*y[1]*y[127] + ((0.0 - kUnbind1)+(0.0 - kUnbind2)+(0.0 - kUnbind3)+(0.0 - kUnbind4)+(0.0 - kUnbind5)+(0.0 - kUnbind6)+(0.0 - kUnbind7))*y[128];
}



int main()
{
// size of the system
const int n= 129;


/************************************************************************
*
* Computing maximum of the reachable set 
*
*************************************************************************/


// number of changes of u_max control
int m=0;
FILE *fp = fopen("replicatedBindingSite7Asymm_Pontryagin_max.csv","r");
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
ifstream file("replicatedBindingSite7Asymm_Pontryagin_max.csv");
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
y[0]=0.0026; y[1]=0.0017; y[2]=0.0059;
y[3]=0.0031; y[4]=0.0078; y[5]=0.0054;
y[6]=0.0152; y[7]=0.0147; y[8]=0.0008;
y[9]=0.0118; y[10]=0.0043; y[11]=0.0067;
y[12]=0.00882; y[13]=0.0151; y[14]=0.0067;
y[15]=0.0157; y[16]=0.0048; y[17]=0.0112; y[18]=0.0107;
y[19]=0.0086; y[20]=0.0112; y[21]=0.0107;
y[22]=0.0028; y[23]=0.002; y[24]=0.016;
y[25]=0.0027; y[26]=0.0005; y[27]=0.009; y[28]=0.0141;
y[29]=0.0107; y[30]=0.003; y[31]=0.0059; y[32]=0.0074;
y[33]=0.0157; y[34]=0.0025; y[35]=0.0137;
y[36]=0.0103; y[37]=0.006; y[38]=0.003;
y[39]=0.0068; y[40]=0.0077; y[41]=0.0019;
y[42]=0.0094; y[43]=0.0036; y[44]=0.0061;
y[45]=0.0093; y[46]=0.0046; y[47]=0.0099;
y[48]=0.0042; y[49]=0.0132; y[50]=0.0157; y[51]=0.0117; 
y[52]=0.0055; y[53]=0.0093; y[54]=0.0017; y[55]=0.0145;
y[56]=0.0141; y[57]=0.0131; y[58]=0.0041;
y[59]=0.0095; y[60]=0.0003; y[61]=0.0068; y[62]=0.005;
y[63]=0.0025; y[64]=0.0028; y[65]=0.0067; y[66]=0.0015;
y[67]=0.0096; y[68]=0.0075; y[69]=0.0111;
y[70]=0.0112; y[71]=0.0102; y[72]=0.0005;
y[73]=0.0011; y[74]=0.0051; y[75]=0.0085;
y[76]=0.0105; y[77]=0.0065; y[78]=0.0131;
y[79]=0.0115; y[80]=0.0115; y[81]=0.0085;
y[82]=0.0052; y[83]=0.0016; y[84]=0.0098; y[85]=0.0125;
y[86]=0.0068; y[87]=0.0014; y[88]=0.0042;
y[89]=0.0024; y[90]=0.0045; y[91]=0.007;
y[92]=0.0084; y[93]=0.0073; y[94]=0.014; y[95]=0.0083;
y[96]=0.0151; y[97]=0.0102; y[98]=0.0153; y[99]=0.0038;
y[100]=0.0108; y[101]=0.0046; y[102]=0.0107;
y[103]=0.0111; y[104]=0.001; y[105]=0.004;
y[106]=0.0036; y[107]=0.0107; y[108]=0.0135;
y[109]=0.0055; y[110]=0.0125; y[111]=0.0108;
y[112]=0.0004; y[113]=0.0096; y[114]=0.0062;
y[115]=0.0174; y[116]=0.0065; y[117]=0.0074; y[118]=0.0068;
y[119]=0.0074; y[120]=0.0123; y[121]=0.0051;
y[122]=0.0126; y[124]=0.0075; y[125]=0.0005;
y[125]=0.0028; y[126]=0.0115; y[127]=0.0076; y[128]=0.0014;
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
coef[33]=0.0; coef[34]=0.0; coef[35]=0.0;
coef[36]=0.0; coef[37]=0.0; coef[38]=0.0; 
coef[39]=0.0; coef[40]=0.0; coef[41]=0.0; coef[42]=0.0;
coef[43]=0.0; coef[44]=0.0; coef[45]=0.0;
coef[46]=0.0; coef[47]=0.0; coef[48]=0.0; 
coef[49]=0.0; coef[50]=0.0; coef[51]=0.0; coef[52]=0.0;
coef[53]=0.0; coef[54]=0.0; coef[55]=0.0;
coef[56]=0.0; coef[57]=0.0; coef[58]=0.0; 
coef[59]=0.0; coef[60]=0.0; coef[61]=0.0; coef[62]=0.0;
coef[63]=0.0; coef[64]=0.0; coef[65]=0.0;
coef[66]=0.0; coef[67]=0.0; coef[68]=0.0;
coef[69]=0.0; coef[70]=0.0; coef[71]=0.0; 
coef[72]=0.0; coef[73]=0.0; coef[74]=0.0; coef[75]=0.0;
coef[76]=0.0; coef[77]=0.0; coef[78]=0.0;
coef[79]=0.0; coef[80]=0.0; coef[81]=0.0; 
coef[82]=0.0; coef[83]=0.0; coef[84]=0.0; coef[85]=0.0;
coef[86]=0.0; coef[87]=0.0; coef[88]=0.0;
coef[89]=0.0; coef[90]=0.0; coef[91]=0.0; 
coef[92]=0.0; coef[93]=0.0; coef[94]=0.0; coef[95]=0.0;
coef[96]=0.0; coef[97]=0.0; coef[98]=0.0; coef[99]=0.0;
coef[100]=0.0; coef[101]=0.0; coef[102]=0.0;
coef[103]=0.0; coef[104]=0.0; coef[105]=0.0; 
coef[106]=0.0; coef[107]=0.0; coef[108]=0.0; coef[109]=0.0;
coef[110]=0.0; coef[111]=0.0; coef[112]=0.0;
coef[113]=0.0; coef[114]=0.0; coef[115]=0.0; 
coef[116]=0.0; coef[117]=0.0; coef[118]=0.0; coef[119]=0.0;
coef[120]=0.0; coef[121]=0.0; coef[122]=0.0;
coef[123]=0.0; coef[124]=0.0; coef[125]=0.0; 
coef[126]=0.0; coef[127]=0.0; coef[128]=0.0;
 
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
fp = fopen("replicatedBindingSite7Asymm_Pontryagin_min.csv","r");
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
ifstream file2("replicatedBindingSite7Asymm_Pontryagin_min.csv");

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
for (int i; i<n ; i++)
    y[i]=0.008;

// reachability problem parameters
y[0]=0.0026; y[1]=0.0017; y[2]=0.0059;
y[3]=0.0031; y[4]=0.0078; y[5]=0.0054;
y[6]=0.0152; y[7]=0.0147; y[8]=0.0008;
y[9]=0.0118; y[10]=0.0043; y[11]=0.0067;
y[12]=0.00882; y[13]=0.0151; y[14]=0.0067;
y[15]=0.0157; y[16]=0.0048; y[17]=0.0112; y[18]=0.0107;
y[19]=0.0086; y[20]=0.0112; y[21]=0.0107;
y[22]=0.0028; y[23]=0.002; y[24]=0.016;
y[25]=0.0027; y[26]=0.0005; y[27]=0.009; y[28]=0.0141;
y[29]=0.0107; y[30]=0.003; y[31]=0.0059; y[32]=0.0074;
y[33]=0.0157; y[34]=0.0025; y[35]=0.0137;
y[36]=0.0103; y[37]=0.006; y[38]=0.003;
y[39]=0.0068; y[40]=0.0077; y[41]=0.0019;
y[42]=0.0094; y[43]=0.0036; y[44]=0.0061;
y[45]=0.0093; y[46]=0.0046; y[47]=0.0099;
y[48]=0.0042; y[49]=0.0132; y[50]=0.0157; y[51]=0.0117; 
y[52]=0.0055; y[53]=0.0093; y[54]=0.0017; y[55]=0.0145;
y[56]=0.0141; y[57]=0.0131; y[58]=0.0041;
y[59]=0.0095; y[60]=0.0003; y[61]=0.0068; y[62]=0.005;
y[63]=0.0025; y[64]=0.0028; y[65]=0.0067; y[66]=0.0015;
y[67]=0.0096; y[68]=0.0075; y[69]=0.0111;
y[70]=0.0112; y[71]=0.0102; y[72]=0.0005;
y[73]=0.0011; y[74]=0.0051; y[75]=0.0085;
y[76]=0.0105; y[77]=0.0065; y[78]=0.0131;
y[79]=0.0115; y[80]=0.0115; y[81]=0.0085;
y[82]=0.0052; y[83]=0.0016; y[84]=0.0098; y[85]=0.0125;
y[86]=0.0068; y[87]=0.0014; y[88]=0.0042;
y[89]=0.0024; y[90]=0.0045; y[91]=0.007;
y[92]=0.0084; y[93]=0.0073; y[94]=0.014; y[95]=0.0083;
y[96]=0.0151; y[97]=0.0102; y[98]=0.0153; y[99]=0.0038;
y[100]=0.0108; y[101]=0.0046; y[102]=0.0107;
y[103]=0.0111; y[104]=0.001; y[105]=0.004;
y[106]=0.0036; y[107]=0.0107; y[108]=0.0135;
y[109]=0.0055; y[110]=0.0125; y[111]=0.0108;
y[112]=0.0004; y[113]=0.0096; y[114]=0.0062;
y[115]=0.0174; y[116]=0.0065; y[117]=0.0074; y[118]=0.0068;
y[119]=0.0074; y[120]=0.0123; y[121]=0.0051;
y[122]=0.0126; y[124]=0.0075; y[125]=0.0005;
y[125]=0.0028; y[126]=0.0115; y[127]=0.0076; y[128]=0.0014;

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
cout<<"Minimum reachable point enclosure at t = "<<t_[m-1] <<endl;
for (int i=0;i<n;i++)
   res += coef[i]*y[i];
cout << res << endl;

return 0;
}

