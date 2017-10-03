/*74:*/
#line 54 "./binding6.w"

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
 interval kUnbind2 = 0.1, kBind3 = 9.99995, kUnbind3 = 0.1;
 interval kBind4 = 10.0, kUnbind4 = 0.1, kBind5 = 10.00005, kUnbind5 = 0.1;
 interval kBind6 = 10.0001, kUnbind6 = 0.1;

	yp[0] = ((0.0 - kBind6)+(0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind3)+(0.0 - kBind2)+(0.0 - kBind1))*y[0]*y[1] + kUnbind1*y[2] + kUnbind2*y[3] + kUnbind3*y[4] + kUnbind4*y[5] + kUnbind5*y[6] + kUnbind6*y[7];
	yp[1] = ((0.0 - kBind6)+(0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind3)+(0.0 - kBind2)+(0.0 - kBind1))*y[0]*y[1] + ((0.0 - kBind6)+(0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind3)+(0.0 - kBind2))*y[1]*y[2] + ((0.0 - kBind6)+(0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind3)+(0.0 - kBind1))*y[1]*y[3] + ((0.0 - kBind6)+(0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[4] + ((0.0 - kBind6)+(0.0 - kBind5)+(0.0 - kBind3)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[5] + ((0.0 - kBind6)+(0.0 - kBind4)+(0.0 - kBind3)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[6] + ((0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind3)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[7] + ((0.0 - kBind6)+(0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind3))*y[1]*y[8] + ((0.0 - kBind6)+(0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind2))*y[1]*y[9] + ((0.0 - kBind6)+(0.0 - kBind5)+(0.0 - kBind3)+(0.0 - kBind2))*y[1]*y[10] + ((0.0 - kBind6)+(0.0 - kBind4)+(0.0 - kBind3)+(0.0 - kBind2))*y[1]*y[11] + ((0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind3)+(0.0 - kBind2))*y[1]*y[12] + ((0.0 - kBind6)+(0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind1))*y[1]*y[13] + ((0.0 - kBind6)+(0.0 - kBind5)+(0.0 - kBind3)+(0.0 - kBind1))*y[1]*y[14] + ((0.0 - kBind6)+(0.0 - kBind4)+(0.0 - kBind3)+(0.0 - kBind1))*y[1]*y[15] + ((0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind3)+(0.0 - kBind1))*y[1]*y[16] + ((0.0 - kBind6)+(0.0 - kBind5)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[17] + ((0.0 - kBind6)+(0.0 - kBind4)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[18] + ((0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[19] + ((0.0 - kBind6)+(0.0 - kBind3)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[20] + ((0.0 - kBind5)+(0.0 - kBind3)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[21] + ((0.0 - kBind4)+(0.0 - kBind3)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[22] + ((0.0 - kBind6)+(0.0 - kBind5)+(0.0 - kBind4))*y[1]*y[23] + ((0.0 - kBind6)+(0.0 - kBind5)+(0.0 - kBind3))*y[1]*y[24] + ((0.0 - kBind6)+(0.0 - kBind4)+(0.0 - kBind3))*y[1]*y[25] + ((0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind3))*y[1]*y[26] + ((0.0 - kBind6)+(0.0 - kBind5)+(0.0 - kBind2))*y[1]*y[27] + ((0.0 - kBind6)+(0.0 - kBind4)+(0.0 - kBind2))*y[1]*y[28] + ((0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind2))*y[1]*y[29] + ((0.0 - kBind6)+(0.0 - kBind3)+(0.0 - kBind2))*y[1]*y[30] + ((0.0 - kBind5)+(0.0 - kBind3)+(0.0 - kBind2))*y[1]*y[31] + ((0.0 - kBind4)+(0.0 - kBind3)+(0.0 - kBind2))*y[1]*y[32] + ((0.0 - kBind6)+(0.0 - kBind5)+(0.0 - kBind1))*y[1]*y[33] + ((0.0 - kBind6)+(0.0 - kBind4)+(0.0 - kBind1))*y[1]*y[34] + ((0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind1))*y[1]*y[35] + ((0.0 - kBind6)+(0.0 - kBind3)+(0.0 - kBind1))*y[1]*y[36] + ((0.0 - kBind5)+(0.0 - kBind3)+(0.0 - kBind1))*y[1]*y[37] + ((0.0 - kBind4)+(0.0 - kBind3)+(0.0 - kBind1))*y[1]*y[38] + ((0.0 - kBind6)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[39] + ((0.0 - kBind5)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[40] + ((0.0 - kBind4)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[41] + ((0.0 - kBind3)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[42] + ((0.0 - kBind6)+(0.0 - kBind5))*y[1]*y[43] + ((0.0 - kBind6)+(0.0 - kBind4))*y[1]*y[44] + ((0.0 - kBind5)+(0.0 - kBind4))*y[1]*y[45] + ((0.0 - kBind6)+(0.0 - kBind3))*y[1]*y[46] + ((0.0 - kBind5)+(0.0 - kBind3))*y[1]*y[47] + ((0.0 - kBind4)+(0.0 - kBind3))*y[1]*y[48] + ((0.0 - kBind6)+(0.0 - kBind2))*y[1]*y[49] + ((0.0 - kBind5)+(0.0 - kBind2))*y[1]*y[50] + ((0.0 - kBind4)+(0.0 - kBind2))*y[1]*y[51] + ((0.0 - kBind3)+(0.0 - kBind2))*y[1]*y[52] + ((0.0 - kBind6)+(0.0 - kBind1))*y[1]*y[53] + ((0.0 - kBind5)+(0.0 - kBind1))*y[1]*y[54] + ((0.0 - kBind4)+(0.0 - kBind1))*y[1]*y[55] + ((0.0 - kBind3)+(0.0 - kBind1))*y[1]*y[56] + ((0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[57] + ((0.0 - kBind6))*y[1]*y[58] + ((0.0 - kBind5))*y[1]*y[59] + ((0.0 - kBind4))*y[1]*y[60] + ((0.0 - kBind3))*y[1]*y[61] + ((0.0 - kBind2))*y[1]*y[62] + ((0.0 - kBind1))*y[1]*y[63] + kUnbind1*y[2] + kUnbind2*y[3] + kUnbind3*y[4] + kUnbind4*y[5] + kUnbind5*y[6] + kUnbind6*y[7] + (kUnbind1+kUnbind2)*y[8] + (kUnbind1+kUnbind3)*y[9] + (kUnbind1+kUnbind4)*y[10] + (kUnbind1+kUnbind5)*y[11] + (kUnbind1+kUnbind6)*y[12] + (kUnbind2+kUnbind3)*y[13] + (kUnbind2+kUnbind4)*y[14] + (kUnbind2+kUnbind5)*y[15] + (kUnbind2+kUnbind6)*y[16] + (kUnbind3+kUnbind4)*y[17] + (kUnbind3+kUnbind5)*y[18] + (kUnbind3+kUnbind6)*y[19] + (kUnbind4+kUnbind5)*y[20] + (kUnbind4+kUnbind6)*y[21] + (kUnbind5+kUnbind6)*y[22] + (kUnbind1+kUnbind2+kUnbind3)*y[23] + (kUnbind1+kUnbind2+kUnbind4)*y[24] + (kUnbind1+kUnbind2+kUnbind5)*y[25] + (kUnbind1+kUnbind2+kUnbind6)*y[26] + (kUnbind1+kUnbind3+kUnbind4)*y[27] + (kUnbind1+kUnbind3+kUnbind5)*y[28] + (kUnbind1+kUnbind3+kUnbind6)*y[29] + (kUnbind1+kUnbind4+kUnbind5)*y[30] + (kUnbind1+kUnbind4+kUnbind6)*y[31] + (kUnbind1+kUnbind5+kUnbind6)*y[32] + (kUnbind2+kUnbind3+kUnbind4)*y[33] + (kUnbind2+kUnbind3+kUnbind5)*y[34] + (kUnbind2+kUnbind3+kUnbind6)*y[35] + (kUnbind2+kUnbind4+kUnbind5)*y[36] + (kUnbind2+kUnbind4+kUnbind6)*y[37] + (kUnbind2+kUnbind5+kUnbind6)*y[38] + (kUnbind3+kUnbind4+kUnbind5)*y[39] + (kUnbind3+kUnbind4+kUnbind6)*y[40] + (kUnbind3+kUnbind5+kUnbind6)*y[41] + (kUnbind4+kUnbind5+kUnbind6)*y[42] + (kUnbind1+kUnbind2+kUnbind3+kUnbind4)*y[43] + (kUnbind1+kUnbind2+kUnbind3+kUnbind5)*y[44] + (kUnbind1+kUnbind2+kUnbind3+kUnbind6)*y[45] + (kUnbind1+kUnbind2+kUnbind4+kUnbind5)*y[46] + (kUnbind1+kUnbind2+kUnbind4+kUnbind6)*y[47] + (kUnbind1+kUnbind2+kUnbind5+kUnbind6)*y[48] + (kUnbind1+kUnbind3+kUnbind4+kUnbind5)*y[49] + (kUnbind1+kUnbind3+kUnbind4+kUnbind6)*y[50] + (kUnbind1+kUnbind3+kUnbind5+kUnbind6)*y[51] + (kUnbind1+kUnbind4+kUnbind5+kUnbind6)*y[52] + (kUnbind2+kUnbind3+kUnbind4+kUnbind5)*y[53] + (kUnbind2+kUnbind3+kUnbind4+kUnbind6)*y[54] + (kUnbind2+kUnbind3+kUnbind5+kUnbind6)*y[55] + (kUnbind2+kUnbind4+kUnbind5+kUnbind6)*y[56] + (kUnbind3+kUnbind4+kUnbind5+kUnbind6)*y[57] + (kUnbind1+kUnbind2+kUnbind3+kUnbind4+kUnbind5)*y[58] + (kUnbind1+kUnbind2+kUnbind3+kUnbind4+kUnbind6)*y[59] + (kUnbind1+kUnbind2+kUnbind3+kUnbind5+kUnbind6)*y[60] + (kUnbind1+kUnbind2+kUnbind4+kUnbind5+kUnbind6)*y[61] + (kUnbind1+kUnbind3+kUnbind4+kUnbind5+kUnbind6)*y[62] + (kUnbind2+kUnbind3+kUnbind4+kUnbind5+kUnbind6)*y[63] + (kUnbind1+kUnbind2+kUnbind3+kUnbind4+kUnbind5+kUnbind6)*y[64];
	yp[2] = kBind1*y[0]*y[1] + ((0.0 - kBind6)+(0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind3)+(0.0 - kBind2))*y[1]*y[2] + ((0.0 - kUnbind1))*y[2] + kUnbind2*y[8] + kUnbind3*y[9] + kUnbind4*y[10] + kUnbind5*y[11] + kUnbind6*y[12];
	yp[3] = kBind2*y[0]*y[1] + ((0.0 - kBind6)+(0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind3)+(0.0 - kBind1))*y[1]*y[3] + ((0.0 - kUnbind2))*y[3] + kUnbind1*y[8] + kUnbind3*y[13] + kUnbind4*y[14] + kUnbind5*y[15] + kUnbind6*y[16];
	yp[4] = kBind3*y[0]*y[1] + ((0.0 - kBind6)+(0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[4] + ((0.0 - kUnbind3))*y[4] + kUnbind1*y[9] + kUnbind2*y[13] + kUnbind4*y[17] + kUnbind5*y[18] + kUnbind6*y[19];
	yp[5] = kBind4*y[0]*y[1] + ((0.0 - kBind6)+(0.0 - kBind5)+(0.0 - kBind3)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[5] + ((0.0 - kUnbind4))*y[5] + kUnbind1*y[10] + kUnbind2*y[14] + kUnbind3*y[17] + kUnbind5*y[20] + kUnbind6*y[21];
	yp[6] = kBind5*y[0]*y[1] + ((0.0 - kBind6)+(0.0 - kBind4)+(0.0 - kBind3)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[6] + ((0.0 - kUnbind5))*y[6] + kUnbind1*y[11] + kUnbind2*y[15] + kUnbind3*y[18] + kUnbind4*y[20] + kUnbind6*y[22];
	yp[7] = kBind6*y[0]*y[1] + ((0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind3)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[7] + ((0.0 - kUnbind6))*y[7] + kUnbind1*y[12] + kUnbind2*y[16] + kUnbind3*y[19] + kUnbind4*y[21] + kUnbind5*y[22];
	yp[8] = kBind2*y[1]*y[2] + kBind1*y[1]*y[3] + ((0.0 - kBind6)+(0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind3))*y[1]*y[8] + ((0.0 - kUnbind1)+(0.0 - kUnbind2))*y[8] + kUnbind3*y[23] + kUnbind4*y[24] + kUnbind5*y[25] + kUnbind6*y[26];
	yp[9] = kBind3*y[1]*y[2] + kBind1*y[1]*y[4] + ((0.0 - kBind6)+(0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind2))*y[1]*y[9] + ((0.0 - kUnbind1)+(0.0 - kUnbind3))*y[9] + kUnbind2*y[23] + kUnbind4*y[27] + kUnbind5*y[28] + kUnbind6*y[29];
	yp[10] = kBind4*y[1]*y[2] + kBind1*y[1]*y[5] + ((0.0 - kBind6)+(0.0 - kBind5)+(0.0 - kBind3)+(0.0 - kBind2))*y[1]*y[10] + ((0.0 - kUnbind1)+(0.0 - kUnbind4))*y[10] + kUnbind2*y[24] + kUnbind3*y[27] + kUnbind5*y[30] + kUnbind6*y[31];
	yp[11] = kBind5*y[1]*y[2] + kBind1*y[1]*y[6] + ((0.0 - kBind6)+(0.0 - kBind4)+(0.0 - kBind3)+(0.0 - kBind2))*y[1]*y[11] + ((0.0 - kUnbind1)+(0.0 - kUnbind5))*y[11] + kUnbind2*y[25] + kUnbind3*y[28] + kUnbind4*y[30] + kUnbind6*y[32];
	yp[12] = kBind6*y[1]*y[2] + kBind1*y[1]*y[7] + ((0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind3)+(0.0 - kBind2))*y[1]*y[12] + ((0.0 - kUnbind1)+(0.0 - kUnbind6))*y[12] + kUnbind2*y[26] + kUnbind3*y[29] + kUnbind4*y[31] + kUnbind5*y[32];
	yp[13] = kBind3*y[1]*y[3] + kBind2*y[1]*y[4] + ((0.0 - kBind6)+(0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind1))*y[1]*y[13] + ((0.0 - kUnbind2)+(0.0 - kUnbind3))*y[13] + kUnbind1*y[23] + kUnbind4*y[33] + kUnbind5*y[34] + kUnbind6*y[35];
	yp[14] = kBind4*y[1]*y[3] + kBind2*y[1]*y[5] + ((0.0 - kBind6)+(0.0 - kBind5)+(0.0 - kBind3)+(0.0 - kBind1))*y[1]*y[14] + ((0.0 - kUnbind2)+(0.0 - kUnbind4))*y[14] + kUnbind1*y[24] + kUnbind3*y[33] + kUnbind5*y[36] + kUnbind6*y[37];
	yp[15] = kBind5*y[1]*y[3] + kBind2*y[1]*y[6] + ((0.0 - kBind6)+(0.0 - kBind4)+(0.0 - kBind3)+(0.0 - kBind1))*y[1]*y[15] + ((0.0 - kUnbind2)+(0.0 - kUnbind5))*y[15] + kUnbind1*y[25] + kUnbind3*y[34] + kUnbind4*y[36] + kUnbind6*y[38];
	yp[16] = kBind6*y[1]*y[3] + kBind2*y[1]*y[7] + ((0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind3)+(0.0 - kBind1))*y[1]*y[16] + ((0.0 - kUnbind2)+(0.0 - kUnbind6))*y[16] + kUnbind1*y[26] + kUnbind3*y[35] + kUnbind4*y[37] + kUnbind5*y[38];
	yp[17] = kBind4*y[1]*y[4] + kBind3*y[1]*y[5] + ((0.0 - kBind6)+(0.0 - kBind5)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[17] + ((0.0 - kUnbind3)+(0.0 - kUnbind4))*y[17] + kUnbind1*y[27] + kUnbind2*y[33] + kUnbind5*y[39] + kUnbind6*y[40];
	yp[18] = kBind5*y[1]*y[4] + kBind3*y[1]*y[6] + ((0.0 - kBind6)+(0.0 - kBind4)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[18] + ((0.0 - kUnbind3)+(0.0 - kUnbind5))*y[18] + kUnbind1*y[28] + kUnbind2*y[34] + kUnbind4*y[39] + kUnbind6*y[41];
	yp[19] = kBind6*y[1]*y[4] + kBind3*y[1]*y[7] + ((0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[19] + ((0.0 - kUnbind3)+(0.0 - kUnbind6))*y[19] + kUnbind1*y[29] + kUnbind2*y[35] + kUnbind4*y[40] + kUnbind5*y[41];
	yp[20] = kBind5*y[1]*y[5] + kBind4*y[1]*y[6] + ((0.0 - kBind6)+(0.0 - kBind3)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[20] + ((0.0 - kUnbind4)+(0.0 - kUnbind5))*y[20] + kUnbind1*y[30] + kUnbind2*y[36] + kUnbind3*y[39] + kUnbind6*y[42];
	yp[21] = kBind6*y[1]*y[5] + kBind4*y[1]*y[7] + ((0.0 - kBind5)+(0.0 - kBind3)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[21] + ((0.0 - kUnbind4)+(0.0 - kUnbind6))*y[21] + kUnbind1*y[31] + kUnbind2*y[37] + kUnbind3*y[40] + kUnbind5*y[42];
	yp[22] = kBind6*y[1]*y[6] + kBind5*y[1]*y[7] + ((0.0 - kBind4)+(0.0 - kBind3)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[22] + ((0.0 - kUnbind5)+(0.0 - kUnbind6))*y[22] + kUnbind1*y[32] + kUnbind2*y[38] + kUnbind3*y[41] + kUnbind4*y[42];
	yp[23] = kBind3*y[1]*y[8] + kBind2*y[1]*y[9] + kBind1*y[1]*y[13] + ((0.0 - kBind6)+(0.0 - kBind5)+(0.0 - kBind4))*y[1]*y[23] + ((0.0 - kUnbind1)+(0.0 - kUnbind2)+(0.0 - kUnbind3))*y[23] + kUnbind4*y[43] + kUnbind5*y[44] + kUnbind6*y[45];
	yp[24] = kBind4*y[1]*y[8] + kBind2*y[1]*y[10] + kBind1*y[1]*y[14] + ((0.0 - kBind6)+(0.0 - kBind5)+(0.0 - kBind3))*y[1]*y[24] + ((0.0 - kUnbind1)+(0.0 - kUnbind2)+(0.0 - kUnbind4))*y[24] + kUnbind3*y[43] + kUnbind5*y[46] + kUnbind6*y[47];
	yp[25] = kBind5*y[1]*y[8] + kBind2*y[1]*y[11] + kBind1*y[1]*y[15] + ((0.0 - kBind6)+(0.0 - kBind4)+(0.0 - kBind3))*y[1]*y[25] + ((0.0 - kUnbind1)+(0.0 - kUnbind2)+(0.0 - kUnbind5))*y[25] + kUnbind3*y[44] + kUnbind4*y[46] + kUnbind6*y[48];
	yp[26] = kBind6*y[1]*y[8] + kBind2*y[1]*y[12] + kBind1*y[1]*y[16] + ((0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind3))*y[1]*y[26] + ((0.0 - kUnbind1)+(0.0 - kUnbind2)+(0.0 - kUnbind6))*y[26] + kUnbind3*y[45] + kUnbind4*y[47] + kUnbind5*y[48];
	yp[27] = kBind4*y[1]*y[9] + kBind3*y[1]*y[10] + kBind1*y[1]*y[17] + ((0.0 - kBind6)+(0.0 - kBind5)+(0.0 - kBind2))*y[1]*y[27] + ((0.0 - kUnbind1)+(0.0 - kUnbind3)+(0.0 - kUnbind4))*y[27] + kUnbind2*y[43] + kUnbind5*y[49] + kUnbind6*y[50];
	yp[28] = kBind5*y[1]*y[9] + kBind3*y[1]*y[11] + kBind1*y[1]*y[18] + ((0.0 - kBind6)+(0.0 - kBind4)+(0.0 - kBind2))*y[1]*y[28] + ((0.0 - kUnbind1)+(0.0 - kUnbind3)+(0.0 - kUnbind5))*y[28] + kUnbind2*y[44] + kUnbind4*y[49] + kUnbind6*y[51];
	yp[29] = kBind6*y[1]*y[9] + kBind3*y[1]*y[12] + kBind1*y[1]*y[19] + ((0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind2))*y[1]*y[29] + ((0.0 - kUnbind1)+(0.0 - kUnbind3)+(0.0 - kUnbind6))*y[29] + kUnbind2*y[45] + kUnbind4*y[50] + kUnbind5*y[51];
	yp[30] = kBind5*y[1]*y[10] + kBind4*y[1]*y[11] + kBind1*y[1]*y[20] + ((0.0 - kBind6)+(0.0 - kBind3)+(0.0 - kBind2))*y[1]*y[30] + ((0.0 - kUnbind1)+(0.0 - kUnbind4)+(0.0 - kUnbind5))*y[30] + kUnbind2*y[46] + kUnbind3*y[49] + kUnbind6*y[52];
	yp[31] = kBind6*y[1]*y[10] + kBind4*y[1]*y[12] + kBind1*y[1]*y[21] + ((0.0 - kBind5)+(0.0 - kBind3)+(0.0 - kBind2))*y[1]*y[31] + ((0.0 - kUnbind1)+(0.0 - kUnbind4)+(0.0 - kUnbind6))*y[31] + kUnbind2*y[47] + kUnbind3*y[50] + kUnbind5*y[52];
	yp[32] = kBind6*y[1]*y[11] + kBind5*y[1]*y[12] + kBind1*y[1]*y[22] + ((0.0 - kBind4)+(0.0 - kBind3)+(0.0 - kBind2))*y[1]*y[32] + ((0.0 - kUnbind1)+(0.0 - kUnbind5)+(0.0 - kUnbind6))*y[32] + kUnbind2*y[48] + kUnbind3*y[51] + kUnbind4*y[52];
	yp[33] = kBind4*y[1]*y[13] + kBind3*y[1]*y[14] + kBind2*y[1]*y[17] + ((0.0 - kBind6)+(0.0 - kBind5)+(0.0 - kBind1))*y[1]*y[33] + ((0.0 - kUnbind2)+(0.0 - kUnbind3)+(0.0 - kUnbind4))*y[33] + kUnbind1*y[43] + kUnbind5*y[53] + kUnbind6*y[54];
	yp[34] = kBind5*y[1]*y[13] + kBind3*y[1]*y[15] + kBind2*y[1]*y[18] + ((0.0 - kBind6)+(0.0 - kBind4)+(0.0 - kBind1))*y[1]*y[34] + ((0.0 - kUnbind2)+(0.0 - kUnbind3)+(0.0 - kUnbind5))*y[34] + kUnbind1*y[44] + kUnbind4*y[53] + kUnbind6*y[55];
	yp[35] = kBind6*y[1]*y[13] + kBind3*y[1]*y[16] + kBind2*y[1]*y[19] + ((0.0 - kBind5)+(0.0 - kBind4)+(0.0 - kBind1))*y[1]*y[35] + ((0.0 - kUnbind2)+(0.0 - kUnbind3)+(0.0 - kUnbind6))*y[35] + kUnbind1*y[45] + kUnbind4*y[54] + kUnbind5*y[55];
	yp[36] = kBind5*y[1]*y[14] + kBind4*y[1]*y[15] + kBind2*y[1]*y[20] + ((0.0 - kBind6)+(0.0 - kBind3)+(0.0 - kBind1))*y[1]*y[36] + ((0.0 - kUnbind2)+(0.0 - kUnbind4)+(0.0 - kUnbind5))*y[36] + kUnbind1*y[46] + kUnbind3*y[53] + kUnbind6*y[56];
	yp[37] = kBind6*y[1]*y[14] + kBind4*y[1]*y[16] + kBind2*y[1]*y[21] + ((0.0 - kBind5)+(0.0 - kBind3)+(0.0 - kBind1))*y[1]*y[37] + ((0.0 - kUnbind2)+(0.0 - kUnbind4)+(0.0 - kUnbind6))*y[37] + kUnbind1*y[47] + kUnbind3*y[54] + kUnbind5*y[56];
	yp[38] = kBind6*y[1]*y[15] + kBind5*y[1]*y[16] + kBind2*y[1]*y[22] + ((0.0 - kBind4)+(0.0 - kBind3)+(0.0 - kBind1))*y[1]*y[38] + ((0.0 - kUnbind2)+(0.0 - kUnbind5)+(0.0 - kUnbind6))*y[38] + kUnbind1*y[48] + kUnbind3*y[55] + kUnbind4*y[56];
	yp[39] = kBind5*y[1]*y[17] + kBind4*y[1]*y[18] + kBind3*y[1]*y[20] + ((0.0 - kBind6)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[39] + ((0.0 - kUnbind3)+(0.0 - kUnbind4)+(0.0 - kUnbind5))*y[39] + kUnbind1*y[49] + kUnbind2*y[53] + kUnbind6*y[57];
	yp[40] = kBind6*y[1]*y[17] + kBind4*y[1]*y[19] + kBind3*y[1]*y[21] + ((0.0 - kBind5)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[40] + ((0.0 - kUnbind3)+(0.0 - kUnbind4)+(0.0 - kUnbind6))*y[40] + kUnbind1*y[50] + kUnbind2*y[54] + kUnbind5*y[57];
	yp[41] = kBind6*y[1]*y[18] + kBind5*y[1]*y[19] + kBind3*y[1]*y[22] + ((0.0 - kBind4)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[41] + ((0.0 - kUnbind3)+(0.0 - kUnbind5)+(0.0 - kUnbind6))*y[41] + kUnbind1*y[51] + kUnbind2*y[55] + kUnbind4*y[57];
	yp[42] = kBind6*y[1]*y[20] + kBind5*y[1]*y[21] + kBind4*y[1]*y[22] + ((0.0 - kBind3)+(0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[42] + ((0.0 - kUnbind4)+(0.0 - kUnbind5)+(0.0 - kUnbind6))*y[42] + kUnbind1*y[52] + kUnbind2*y[56] + kUnbind3*y[57];
	yp[43] = kBind4*y[1]*y[23] + kBind3*y[1]*y[24] + kBind2*y[1]*y[27] + kBind1*y[1]*y[33] + ((0.0 - kBind6)+(0.0 - kBind5))*y[1]*y[43] + ((0.0 - kUnbind1)+(0.0 - kUnbind2)+(0.0 - kUnbind3)+(0.0 - kUnbind4))*y[43] + kUnbind5*y[58] + kUnbind6*y[59];
	yp[44] = kBind5*y[1]*y[23] + kBind3*y[1]*y[25] + kBind2*y[1]*y[28] + kBind1*y[1]*y[34] + ((0.0 - kBind6)+(0.0 - kBind4))*y[1]*y[44] + ((0.0 - kUnbind1)+(0.0 - kUnbind2)+(0.0 - kUnbind3)+(0.0 - kUnbind5))*y[44] + kUnbind4*y[58] + kUnbind6*y[60];
	yp[45] = kBind6*y[1]*y[23] + kBind3*y[1]*y[26] + kBind2*y[1]*y[29] + kBind1*y[1]*y[35] + ((0.0 - kBind5)+(0.0 - kBind4))*y[1]*y[45] + ((0.0 - kUnbind1)+(0.0 - kUnbind2)+(0.0 - kUnbind3)+(0.0 - kUnbind6))*y[45] + kUnbind4*y[59] + kUnbind5*y[60];
	yp[46] = kBind5*y[1]*y[24] + kBind4*y[1]*y[25] + kBind2*y[1]*y[30] + kBind1*y[1]*y[36] + ((0.0 - kBind6)+(0.0 - kBind3))*y[1]*y[46] + ((0.0 - kUnbind1)+(0.0 - kUnbind2)+(0.0 - kUnbind4)+(0.0 - kUnbind5))*y[46] + kUnbind3*y[58] + kUnbind6*y[61];
	yp[47] = kBind6*y[1]*y[24] + kBind4*y[1]*y[26] + kBind2*y[1]*y[31] + kBind1*y[1]*y[37] + ((0.0 - kBind5)+(0.0 - kBind3))*y[1]*y[47] + ((0.0 - kUnbind1)+(0.0 - kUnbind2)+(0.0 - kUnbind4)+(0.0 - kUnbind6))*y[47] + kUnbind3*y[59] + kUnbind5*y[61];
	yp[48] = kBind6*y[1]*y[25] + kBind5*y[1]*y[26] + kBind2*y[1]*y[32] + kBind1*y[1]*y[38] + ((0.0 - kBind4)+(0.0 - kBind3))*y[1]*y[48] + ((0.0 - kUnbind1)+(0.0 - kUnbind2)+(0.0 - kUnbind5)+(0.0 - kUnbind6))*y[48] + kUnbind3*y[60] + kUnbind4*y[61];
	yp[49] = kBind5*y[1]*y[27] + kBind4*y[1]*y[28] + kBind3*y[1]*y[30] + kBind1*y[1]*y[39] + ((0.0 - kBind6)+(0.0 - kBind2))*y[1]*y[49] + ((0.0 - kUnbind1)+(0.0 - kUnbind3)+(0.0 - kUnbind4)+(0.0 - kUnbind5))*y[49] + kUnbind2*y[58] + kUnbind6*y[62];
	yp[50] = kBind6*y[1]*y[27] + kBind4*y[1]*y[29] + kBind3*y[1]*y[31] + kBind1*y[1]*y[40] + ((0.0 - kBind5)+(0.0 - kBind2))*y[1]*y[50] + ((0.0 - kUnbind1)+(0.0 - kUnbind3)+(0.0 - kUnbind4)+(0.0 - kUnbind6))*y[50] + kUnbind2*y[59] + kUnbind5*y[62];
	yp[51] = kBind6*y[1]*y[28] + kBind5*y[1]*y[29] + kBind3*y[1]*y[32] + kBind1*y[1]*y[41] + ((0.0 - kBind4)+(0.0 - kBind2))*y[1]*y[51] + ((0.0 - kUnbind1)+(0.0 - kUnbind3)+(0.0 - kUnbind5)+(0.0 - kUnbind6))*y[51] + kUnbind2*y[60] + kUnbind4*y[62];
	yp[52] = kBind6*y[1]*y[30] + kBind5*y[1]*y[31] + kBind4*y[1]*y[32] + kBind1*y[1]*y[42] + ((0.0 - kBind3)+(0.0 - kBind2))*y[1]*y[52] + ((0.0 - kUnbind1)+(0.0 - kUnbind4)+(0.0 - kUnbind5)+(0.0 - kUnbind6))*y[52] + kUnbind2*y[61] + kUnbind3*y[62];
	yp[53] = kBind5*y[1]*y[33] + kBind4*y[1]*y[34] + kBind3*y[1]*y[36] + kBind2*y[1]*y[39] + ((0.0 - kBind6)+(0.0 - kBind1))*y[1]*y[53] + ((0.0 - kUnbind2)+(0.0 - kUnbind3)+(0.0 - kUnbind4)+(0.0 - kUnbind5))*y[53] + kUnbind1*y[58] + kUnbind6*y[63];
	yp[54] = kBind6*y[1]*y[33] + kBind4*y[1]*y[35] + kBind3*y[1]*y[37] + kBind2*y[1]*y[40] + ((0.0 - kBind5)+(0.0 - kBind1))*y[1]*y[54] + ((0.0 - kUnbind2)+(0.0 - kUnbind3)+(0.0 - kUnbind4)+(0.0 - kUnbind6))*y[54] + kUnbind1*y[59] + kUnbind5*y[63];
	yp[55] = kBind6*y[1]*y[34] + kBind5*y[1]*y[35] + kBind3*y[1]*y[38] + kBind2*y[1]*y[41] + ((0.0 - kBind4)+(0.0 - kBind1))*y[1]*y[55] + ((0.0 - kUnbind2)+(0.0 - kUnbind3)+(0.0 - kUnbind5)+(0.0 - kUnbind6))*y[55] + kUnbind1*y[60] + kUnbind4*y[63];
	yp[56] = kBind6*y[1]*y[36] + kBind5*y[1]*y[37] + kBind4*y[1]*y[38] + kBind2*y[1]*y[42] + ((0.0 - kBind3)+(0.0 - kBind1))*y[1]*y[56] + ((0.0 - kUnbind2)+(0.0 - kUnbind4)+(0.0 - kUnbind5)+(0.0 - kUnbind6))*y[56] + kUnbind1*y[61] + kUnbind3*y[63];
	yp[57] = kBind6*y[1]*y[39] + kBind5*y[1]*y[40] + kBind4*y[1]*y[41] + kBind3*y[1]*y[42] + ((0.0 - kBind2)+(0.0 - kBind1))*y[1]*y[57] + ((0.0 - kUnbind3)+(0.0 - kUnbind4)+(0.0 - kUnbind5)+(0.0 - kUnbind6))*y[57] + kUnbind1*y[62] + kUnbind2*y[63];
	yp[58] = kBind5*y[1]*y[43] + kBind4*y[1]*y[44] + kBind3*y[1]*y[46] + kBind2*y[1]*y[49] + kBind1*y[1]*y[53] + ((0.0 - kBind6))*y[1]*y[58] + ((0.0 - kUnbind1)+(0.0 - kUnbind2)+(0.0 - kUnbind3)+(0.0 - kUnbind4)+(0.0 - kUnbind5))*y[58] + kUnbind6*y[64];
	yp[59] = kBind6*y[1]*y[43] + kBind4*y[1]*y[45] + kBind3*y[1]*y[47] + kBind2*y[1]*y[50] + kBind1*y[1]*y[54] + ((0.0 - kBind5))*y[1]*y[59] + ((0.0 - kUnbind1)+(0.0 - kUnbind2)+(0.0 - kUnbind3)+(0.0 - kUnbind4)+(0.0 - kUnbind6))*y[59] + kUnbind5*y[64];
	yp[60] = kBind6*y[1]*y[44] + kBind5*y[1]*y[45] + kBind3*y[1]*y[48] + kBind2*y[1]*y[51] + kBind1*y[1]*y[55] + ((0.0 - kBind4))*y[1]*y[60] + ((0.0 - kUnbind1)+(0.0 - kUnbind2)+(0.0 - kUnbind3)+(0.0 - kUnbind5)+(0.0 - kUnbind6))*y[60] + kUnbind4*y[64];
	yp[61] = kBind6*y[1]*y[46] + kBind5*y[1]*y[47] + kBind4*y[1]*y[48] + kBind2*y[1]*y[52] + kBind1*y[1]*y[56] + ((0.0 - kBind3))*y[1]*y[61] + ((0.0 - kUnbind1)+(0.0 - kUnbind2)+(0.0 - kUnbind4)+(0.0 - kUnbind5)+(0.0 - kUnbind6))*y[61] + kUnbind3*y[64];
	yp[62] = kBind6*y[1]*y[49] + kBind5*y[1]*y[50] + kBind4*y[1]*y[51] + kBind3*y[1]*y[52] + kBind1*y[1]*y[57] + ((0.0 - kBind2))*y[1]*y[62] + ((0.0 - kUnbind1)+(0.0 - kUnbind3)+(0.0 - kUnbind4)+(0.0 - kUnbind5)+(0.0 - kUnbind6))*y[62] + kUnbind2*y[64];
	yp[63] = kBind6*y[1]*y[53] + kBind5*y[1]*y[54] + kBind4*y[1]*y[55] + kBind3*y[1]*y[56] + kBind2*y[1]*y[57] + ((0.0 - kBind1))*y[1]*y[63] + ((0.0 - kUnbind2)+(0.0 - kUnbind3)+(0.0 - kUnbind4)+(0.0 - kUnbind5)+(0.0 - kUnbind6))*y[63] + kUnbind1*y[64];
	yp[64] = kBind6*y[1]*y[58] + kBind5*y[1]*y[59] + kBind4*y[1]*y[60] + kBind3*y[1]*y[61] + kBind2*y[1]*y[62] + kBind1*y[1]*y[63] + ((0.0 - kUnbind1)+(0.0 - kUnbind2)+(0.0 - kUnbind3)+(0.0 - kUnbind4)+(0.0 - kUnbind5)+(0.0 - kUnbind6))*y[64];
}



int main()
{
// size of the system
const int n= 65;


/*************************************************************************
*
* Computing maximum of the reachable set 
*
*************************************************************************/

// number of changes of u_max control
int m=0;
FILE *fp = fopen("replicatedBindingSite6Asymm_Pontryagin_max.csv","r");
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
ifstream file("replicatedBindingSite6Asymm_Pontryagin_max.csv");
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

y[0]=0.0114; y[1]=0.0064; y[2]=0.0082;
y[3]=0.0201; y[4]=0.0154; y[5]=0.0115;
y[6]=0.0271; y[7]=0.0191; y[8]=0.0179;
y[9]=0.0299; y[10]=0.0093; y[11]=0.0247;
y[12]=0.0246; y[13]=0.0124; y[14]=0.0185;
y[15]=0.0025; y[16]=0.0018; y[17]=0.0042; y[18]=0.0185;
y[19]=0.0153; y[20]=0.0004; y[21]=0.011;
y[22]=0.0053; y[23]=0.0259; y[24]=0.0101;
y[25]=0.0172; y[26]=0.0054; y[27]=0.0196; y[28]=0.0086;
y[29]=0.0213; y[30]=0.0225; y[31]= 0.0244; y[32]=0.0147;
y[33]=0.0027; y[34]=0.0075; y[35]=0.0298;
y[36]=0.005; y[37]=0.0269; y[38]=0.0175;
y[39]=0.0325; y[40]=0.0025; y[41]=0.0144;
y[42]=0.0035; y[43]=0.0314; y[44]=0.0004;
y[45]=0.0253; y[46]=0.0266; y[47]=0.0283; y[48]=0.0028;
y[49]=0.013; y[50]=0.0085; y[51]=0.0261;
y[52]=0.0141; y[53]=0.0297; y[54]=0.0059; y[55]=0.0086;
y[56]=0.0047; y[57]=0.0044; y[58]=0.0283;
y[59]=0.0189; y[60]=0.0189; y[61]=0.0047;
y[62]=0.0266; y[63]=0.0174; y[64]=0.0115;
coef[0]=0.0; coef[1]=1.0; coef[2]=0.0;
coef[3]=0.0; coef[4]=0.0; coef[5]=0.0; 
coef[6]=0.0; coef[7]=0.0; coef[8]=0.0; coef[9]=0.0;
coef[10]=0.0; coef[11]=0.0; coef[12]=0.0;
coef[13]=0.0; coef[14]=0.0; coef[15]=0.0; 
coef[16]=0.0; coef[17]=0.0; coef[18]=0.0; coef[19]=0.0;
coef[20]=0.0; coef[21]=0.0; coef[22]=0.0;
coef[23]=0.0; coef[24]=0.0; coef[25]=0.0; 
coef[26]=0.0; coef[27]=0.0; coef[28]=0.0; coef[29]=0.0;
coef[30]=0.0; coef[1]=1.0; coef[2]=0.0;
coef[33]=0.0; coef[4]=0.0; coef[5]=0.0; 
coef[36]=0.0; coef[7]=0.0; coef[8]=0.0; coef[9]=0.0;
coef[40]=0.0; coef[11]=0.0; coef[12]=0.0;
coef[43]=0.0; coef[14]=0.0; coef[15]=0.0; 
coef[46]=0.0; coef[17]=0.0; coef[18]=0.0; coef[19]=0.0;
coef[50]=0.0; coef[21]=0.0; coef[22]=0.0;
coef[53]=0.0; coef[54]=0.0; coef[55]=0.0; 
coef[56]=0.0; coef[57]=0.0; coef[58]=0.0; coef[59]=0.0;
coef[60]=0.0; coef[61]=0.0; coef[62]=0.0;
coef[63]=0.0; coef[64]=0.0;

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
fp = fopen("replicatedBindingSite6Asymm_Pontryagin_min.csv","r");
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
ifstream file2("replicatedBindingSite6Asymm_Pontryagin_min.csv");

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
y[0]=0.0114; y[1]=0.0064; y[2]=0.0082;
y[3]=0.0201; y[4]=0.0154; y[5]=0.0115;
y[6]=0.0271; y[7]=0.0191; y[8]=0.0179;
y[9]=0.0299; y[10]=0.0093; y[11]=0.0247;
y[12]=0.0246; y[13]=0.0124; y[14]=0.0185;
y[15]=0.0025; y[16]=0.0018; y[17]=0.0042; y[18]=0.0185;
y[19]=0.0153; y[20]=0.0004; y[21]=0.011;
y[22]=0.0053; y[23]=0.0259; y[24]=0.0101;
y[25]=0.0172; y[26]=0.0054; y[27]=0.0196; y[28]=0.0086;
y[29]=0.0213; y[30]=0.0225; y[31]= 0.0244; y[32]=0.0147;
y[33]=0.0027; y[34]=0.0075; y[35]=0.0298;
y[36]=0.005; y[37]=0.0269; y[38]=0.0175;
y[39]=0.0325; y[40]=0.0025; y[41]=0.0144;
y[42]=0.0035; y[43]=0.0314; y[44]=0.0004;
y[45]=0.0253; y[46]=0.0266; y[47]=0.0283; y[48]=0.0028;
y[49]=0.013; y[50]=0.0085; y[51]=0.0261;
y[52]=0.0141; y[53]=0.0297; y[54]=0.0059; y[55]=0.0086;
y[56]=0.0047; y[57]=0.0044; y[58]=0.0283;
y[59]=0.0189; y[60]=0.0189; y[61]=0.0047;
y[62]=0.0266; y[63]=0.0174; y[64]=0.0115;


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

