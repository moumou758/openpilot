#include "pose.h"

namespace {
#define DIM 18
#define EDIM 18
#define MEDIM 18
typedef void (*Hfun)(double *, double *, double *);
const static double MAHA_THRESH_4 = 7.814727903251177;
const static double MAHA_THRESH_10 = 7.814727903251177;
const static double MAHA_THRESH_13 = 7.814727903251177;
const static double MAHA_THRESH_14 = 7.814727903251177;

/******************************************************************************
 *                      Code generated with SymPy 1.14.0                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_5153672272046342551) {
   out_5153672272046342551[0] = delta_x[0] + nom_x[0];
   out_5153672272046342551[1] = delta_x[1] + nom_x[1];
   out_5153672272046342551[2] = delta_x[2] + nom_x[2];
   out_5153672272046342551[3] = delta_x[3] + nom_x[3];
   out_5153672272046342551[4] = delta_x[4] + nom_x[4];
   out_5153672272046342551[5] = delta_x[5] + nom_x[5];
   out_5153672272046342551[6] = delta_x[6] + nom_x[6];
   out_5153672272046342551[7] = delta_x[7] + nom_x[7];
   out_5153672272046342551[8] = delta_x[8] + nom_x[8];
   out_5153672272046342551[9] = delta_x[9] + nom_x[9];
   out_5153672272046342551[10] = delta_x[10] + nom_x[10];
   out_5153672272046342551[11] = delta_x[11] + nom_x[11];
   out_5153672272046342551[12] = delta_x[12] + nom_x[12];
   out_5153672272046342551[13] = delta_x[13] + nom_x[13];
   out_5153672272046342551[14] = delta_x[14] + nom_x[14];
   out_5153672272046342551[15] = delta_x[15] + nom_x[15];
   out_5153672272046342551[16] = delta_x[16] + nom_x[16];
   out_5153672272046342551[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_7756557426239194035) {
   out_7756557426239194035[0] = -nom_x[0] + true_x[0];
   out_7756557426239194035[1] = -nom_x[1] + true_x[1];
   out_7756557426239194035[2] = -nom_x[2] + true_x[2];
   out_7756557426239194035[3] = -nom_x[3] + true_x[3];
   out_7756557426239194035[4] = -nom_x[4] + true_x[4];
   out_7756557426239194035[5] = -nom_x[5] + true_x[5];
   out_7756557426239194035[6] = -nom_x[6] + true_x[6];
   out_7756557426239194035[7] = -nom_x[7] + true_x[7];
   out_7756557426239194035[8] = -nom_x[8] + true_x[8];
   out_7756557426239194035[9] = -nom_x[9] + true_x[9];
   out_7756557426239194035[10] = -nom_x[10] + true_x[10];
   out_7756557426239194035[11] = -nom_x[11] + true_x[11];
   out_7756557426239194035[12] = -nom_x[12] + true_x[12];
   out_7756557426239194035[13] = -nom_x[13] + true_x[13];
   out_7756557426239194035[14] = -nom_x[14] + true_x[14];
   out_7756557426239194035[15] = -nom_x[15] + true_x[15];
   out_7756557426239194035[16] = -nom_x[16] + true_x[16];
   out_7756557426239194035[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_1488824774377298388) {
   out_1488824774377298388[0] = 1.0;
   out_1488824774377298388[1] = 0.0;
   out_1488824774377298388[2] = 0.0;
   out_1488824774377298388[3] = 0.0;
   out_1488824774377298388[4] = 0.0;
   out_1488824774377298388[5] = 0.0;
   out_1488824774377298388[6] = 0.0;
   out_1488824774377298388[7] = 0.0;
   out_1488824774377298388[8] = 0.0;
   out_1488824774377298388[9] = 0.0;
   out_1488824774377298388[10] = 0.0;
   out_1488824774377298388[11] = 0.0;
   out_1488824774377298388[12] = 0.0;
   out_1488824774377298388[13] = 0.0;
   out_1488824774377298388[14] = 0.0;
   out_1488824774377298388[15] = 0.0;
   out_1488824774377298388[16] = 0.0;
   out_1488824774377298388[17] = 0.0;
   out_1488824774377298388[18] = 0.0;
   out_1488824774377298388[19] = 1.0;
   out_1488824774377298388[20] = 0.0;
   out_1488824774377298388[21] = 0.0;
   out_1488824774377298388[22] = 0.0;
   out_1488824774377298388[23] = 0.0;
   out_1488824774377298388[24] = 0.0;
   out_1488824774377298388[25] = 0.0;
   out_1488824774377298388[26] = 0.0;
   out_1488824774377298388[27] = 0.0;
   out_1488824774377298388[28] = 0.0;
   out_1488824774377298388[29] = 0.0;
   out_1488824774377298388[30] = 0.0;
   out_1488824774377298388[31] = 0.0;
   out_1488824774377298388[32] = 0.0;
   out_1488824774377298388[33] = 0.0;
   out_1488824774377298388[34] = 0.0;
   out_1488824774377298388[35] = 0.0;
   out_1488824774377298388[36] = 0.0;
   out_1488824774377298388[37] = 0.0;
   out_1488824774377298388[38] = 1.0;
   out_1488824774377298388[39] = 0.0;
   out_1488824774377298388[40] = 0.0;
   out_1488824774377298388[41] = 0.0;
   out_1488824774377298388[42] = 0.0;
   out_1488824774377298388[43] = 0.0;
   out_1488824774377298388[44] = 0.0;
   out_1488824774377298388[45] = 0.0;
   out_1488824774377298388[46] = 0.0;
   out_1488824774377298388[47] = 0.0;
   out_1488824774377298388[48] = 0.0;
   out_1488824774377298388[49] = 0.0;
   out_1488824774377298388[50] = 0.0;
   out_1488824774377298388[51] = 0.0;
   out_1488824774377298388[52] = 0.0;
   out_1488824774377298388[53] = 0.0;
   out_1488824774377298388[54] = 0.0;
   out_1488824774377298388[55] = 0.0;
   out_1488824774377298388[56] = 0.0;
   out_1488824774377298388[57] = 1.0;
   out_1488824774377298388[58] = 0.0;
   out_1488824774377298388[59] = 0.0;
   out_1488824774377298388[60] = 0.0;
   out_1488824774377298388[61] = 0.0;
   out_1488824774377298388[62] = 0.0;
   out_1488824774377298388[63] = 0.0;
   out_1488824774377298388[64] = 0.0;
   out_1488824774377298388[65] = 0.0;
   out_1488824774377298388[66] = 0.0;
   out_1488824774377298388[67] = 0.0;
   out_1488824774377298388[68] = 0.0;
   out_1488824774377298388[69] = 0.0;
   out_1488824774377298388[70] = 0.0;
   out_1488824774377298388[71] = 0.0;
   out_1488824774377298388[72] = 0.0;
   out_1488824774377298388[73] = 0.0;
   out_1488824774377298388[74] = 0.0;
   out_1488824774377298388[75] = 0.0;
   out_1488824774377298388[76] = 1.0;
   out_1488824774377298388[77] = 0.0;
   out_1488824774377298388[78] = 0.0;
   out_1488824774377298388[79] = 0.0;
   out_1488824774377298388[80] = 0.0;
   out_1488824774377298388[81] = 0.0;
   out_1488824774377298388[82] = 0.0;
   out_1488824774377298388[83] = 0.0;
   out_1488824774377298388[84] = 0.0;
   out_1488824774377298388[85] = 0.0;
   out_1488824774377298388[86] = 0.0;
   out_1488824774377298388[87] = 0.0;
   out_1488824774377298388[88] = 0.0;
   out_1488824774377298388[89] = 0.0;
   out_1488824774377298388[90] = 0.0;
   out_1488824774377298388[91] = 0.0;
   out_1488824774377298388[92] = 0.0;
   out_1488824774377298388[93] = 0.0;
   out_1488824774377298388[94] = 0.0;
   out_1488824774377298388[95] = 1.0;
   out_1488824774377298388[96] = 0.0;
   out_1488824774377298388[97] = 0.0;
   out_1488824774377298388[98] = 0.0;
   out_1488824774377298388[99] = 0.0;
   out_1488824774377298388[100] = 0.0;
   out_1488824774377298388[101] = 0.0;
   out_1488824774377298388[102] = 0.0;
   out_1488824774377298388[103] = 0.0;
   out_1488824774377298388[104] = 0.0;
   out_1488824774377298388[105] = 0.0;
   out_1488824774377298388[106] = 0.0;
   out_1488824774377298388[107] = 0.0;
   out_1488824774377298388[108] = 0.0;
   out_1488824774377298388[109] = 0.0;
   out_1488824774377298388[110] = 0.0;
   out_1488824774377298388[111] = 0.0;
   out_1488824774377298388[112] = 0.0;
   out_1488824774377298388[113] = 0.0;
   out_1488824774377298388[114] = 1.0;
   out_1488824774377298388[115] = 0.0;
   out_1488824774377298388[116] = 0.0;
   out_1488824774377298388[117] = 0.0;
   out_1488824774377298388[118] = 0.0;
   out_1488824774377298388[119] = 0.0;
   out_1488824774377298388[120] = 0.0;
   out_1488824774377298388[121] = 0.0;
   out_1488824774377298388[122] = 0.0;
   out_1488824774377298388[123] = 0.0;
   out_1488824774377298388[124] = 0.0;
   out_1488824774377298388[125] = 0.0;
   out_1488824774377298388[126] = 0.0;
   out_1488824774377298388[127] = 0.0;
   out_1488824774377298388[128] = 0.0;
   out_1488824774377298388[129] = 0.0;
   out_1488824774377298388[130] = 0.0;
   out_1488824774377298388[131] = 0.0;
   out_1488824774377298388[132] = 0.0;
   out_1488824774377298388[133] = 1.0;
   out_1488824774377298388[134] = 0.0;
   out_1488824774377298388[135] = 0.0;
   out_1488824774377298388[136] = 0.0;
   out_1488824774377298388[137] = 0.0;
   out_1488824774377298388[138] = 0.0;
   out_1488824774377298388[139] = 0.0;
   out_1488824774377298388[140] = 0.0;
   out_1488824774377298388[141] = 0.0;
   out_1488824774377298388[142] = 0.0;
   out_1488824774377298388[143] = 0.0;
   out_1488824774377298388[144] = 0.0;
   out_1488824774377298388[145] = 0.0;
   out_1488824774377298388[146] = 0.0;
   out_1488824774377298388[147] = 0.0;
   out_1488824774377298388[148] = 0.0;
   out_1488824774377298388[149] = 0.0;
   out_1488824774377298388[150] = 0.0;
   out_1488824774377298388[151] = 0.0;
   out_1488824774377298388[152] = 1.0;
   out_1488824774377298388[153] = 0.0;
   out_1488824774377298388[154] = 0.0;
   out_1488824774377298388[155] = 0.0;
   out_1488824774377298388[156] = 0.0;
   out_1488824774377298388[157] = 0.0;
   out_1488824774377298388[158] = 0.0;
   out_1488824774377298388[159] = 0.0;
   out_1488824774377298388[160] = 0.0;
   out_1488824774377298388[161] = 0.0;
   out_1488824774377298388[162] = 0.0;
   out_1488824774377298388[163] = 0.0;
   out_1488824774377298388[164] = 0.0;
   out_1488824774377298388[165] = 0.0;
   out_1488824774377298388[166] = 0.0;
   out_1488824774377298388[167] = 0.0;
   out_1488824774377298388[168] = 0.0;
   out_1488824774377298388[169] = 0.0;
   out_1488824774377298388[170] = 0.0;
   out_1488824774377298388[171] = 1.0;
   out_1488824774377298388[172] = 0.0;
   out_1488824774377298388[173] = 0.0;
   out_1488824774377298388[174] = 0.0;
   out_1488824774377298388[175] = 0.0;
   out_1488824774377298388[176] = 0.0;
   out_1488824774377298388[177] = 0.0;
   out_1488824774377298388[178] = 0.0;
   out_1488824774377298388[179] = 0.0;
   out_1488824774377298388[180] = 0.0;
   out_1488824774377298388[181] = 0.0;
   out_1488824774377298388[182] = 0.0;
   out_1488824774377298388[183] = 0.0;
   out_1488824774377298388[184] = 0.0;
   out_1488824774377298388[185] = 0.0;
   out_1488824774377298388[186] = 0.0;
   out_1488824774377298388[187] = 0.0;
   out_1488824774377298388[188] = 0.0;
   out_1488824774377298388[189] = 0.0;
   out_1488824774377298388[190] = 1.0;
   out_1488824774377298388[191] = 0.0;
   out_1488824774377298388[192] = 0.0;
   out_1488824774377298388[193] = 0.0;
   out_1488824774377298388[194] = 0.0;
   out_1488824774377298388[195] = 0.0;
   out_1488824774377298388[196] = 0.0;
   out_1488824774377298388[197] = 0.0;
   out_1488824774377298388[198] = 0.0;
   out_1488824774377298388[199] = 0.0;
   out_1488824774377298388[200] = 0.0;
   out_1488824774377298388[201] = 0.0;
   out_1488824774377298388[202] = 0.0;
   out_1488824774377298388[203] = 0.0;
   out_1488824774377298388[204] = 0.0;
   out_1488824774377298388[205] = 0.0;
   out_1488824774377298388[206] = 0.0;
   out_1488824774377298388[207] = 0.0;
   out_1488824774377298388[208] = 0.0;
   out_1488824774377298388[209] = 1.0;
   out_1488824774377298388[210] = 0.0;
   out_1488824774377298388[211] = 0.0;
   out_1488824774377298388[212] = 0.0;
   out_1488824774377298388[213] = 0.0;
   out_1488824774377298388[214] = 0.0;
   out_1488824774377298388[215] = 0.0;
   out_1488824774377298388[216] = 0.0;
   out_1488824774377298388[217] = 0.0;
   out_1488824774377298388[218] = 0.0;
   out_1488824774377298388[219] = 0.0;
   out_1488824774377298388[220] = 0.0;
   out_1488824774377298388[221] = 0.0;
   out_1488824774377298388[222] = 0.0;
   out_1488824774377298388[223] = 0.0;
   out_1488824774377298388[224] = 0.0;
   out_1488824774377298388[225] = 0.0;
   out_1488824774377298388[226] = 0.0;
   out_1488824774377298388[227] = 0.0;
   out_1488824774377298388[228] = 1.0;
   out_1488824774377298388[229] = 0.0;
   out_1488824774377298388[230] = 0.0;
   out_1488824774377298388[231] = 0.0;
   out_1488824774377298388[232] = 0.0;
   out_1488824774377298388[233] = 0.0;
   out_1488824774377298388[234] = 0.0;
   out_1488824774377298388[235] = 0.0;
   out_1488824774377298388[236] = 0.0;
   out_1488824774377298388[237] = 0.0;
   out_1488824774377298388[238] = 0.0;
   out_1488824774377298388[239] = 0.0;
   out_1488824774377298388[240] = 0.0;
   out_1488824774377298388[241] = 0.0;
   out_1488824774377298388[242] = 0.0;
   out_1488824774377298388[243] = 0.0;
   out_1488824774377298388[244] = 0.0;
   out_1488824774377298388[245] = 0.0;
   out_1488824774377298388[246] = 0.0;
   out_1488824774377298388[247] = 1.0;
   out_1488824774377298388[248] = 0.0;
   out_1488824774377298388[249] = 0.0;
   out_1488824774377298388[250] = 0.0;
   out_1488824774377298388[251] = 0.0;
   out_1488824774377298388[252] = 0.0;
   out_1488824774377298388[253] = 0.0;
   out_1488824774377298388[254] = 0.0;
   out_1488824774377298388[255] = 0.0;
   out_1488824774377298388[256] = 0.0;
   out_1488824774377298388[257] = 0.0;
   out_1488824774377298388[258] = 0.0;
   out_1488824774377298388[259] = 0.0;
   out_1488824774377298388[260] = 0.0;
   out_1488824774377298388[261] = 0.0;
   out_1488824774377298388[262] = 0.0;
   out_1488824774377298388[263] = 0.0;
   out_1488824774377298388[264] = 0.0;
   out_1488824774377298388[265] = 0.0;
   out_1488824774377298388[266] = 1.0;
   out_1488824774377298388[267] = 0.0;
   out_1488824774377298388[268] = 0.0;
   out_1488824774377298388[269] = 0.0;
   out_1488824774377298388[270] = 0.0;
   out_1488824774377298388[271] = 0.0;
   out_1488824774377298388[272] = 0.0;
   out_1488824774377298388[273] = 0.0;
   out_1488824774377298388[274] = 0.0;
   out_1488824774377298388[275] = 0.0;
   out_1488824774377298388[276] = 0.0;
   out_1488824774377298388[277] = 0.0;
   out_1488824774377298388[278] = 0.0;
   out_1488824774377298388[279] = 0.0;
   out_1488824774377298388[280] = 0.0;
   out_1488824774377298388[281] = 0.0;
   out_1488824774377298388[282] = 0.0;
   out_1488824774377298388[283] = 0.0;
   out_1488824774377298388[284] = 0.0;
   out_1488824774377298388[285] = 1.0;
   out_1488824774377298388[286] = 0.0;
   out_1488824774377298388[287] = 0.0;
   out_1488824774377298388[288] = 0.0;
   out_1488824774377298388[289] = 0.0;
   out_1488824774377298388[290] = 0.0;
   out_1488824774377298388[291] = 0.0;
   out_1488824774377298388[292] = 0.0;
   out_1488824774377298388[293] = 0.0;
   out_1488824774377298388[294] = 0.0;
   out_1488824774377298388[295] = 0.0;
   out_1488824774377298388[296] = 0.0;
   out_1488824774377298388[297] = 0.0;
   out_1488824774377298388[298] = 0.0;
   out_1488824774377298388[299] = 0.0;
   out_1488824774377298388[300] = 0.0;
   out_1488824774377298388[301] = 0.0;
   out_1488824774377298388[302] = 0.0;
   out_1488824774377298388[303] = 0.0;
   out_1488824774377298388[304] = 1.0;
   out_1488824774377298388[305] = 0.0;
   out_1488824774377298388[306] = 0.0;
   out_1488824774377298388[307] = 0.0;
   out_1488824774377298388[308] = 0.0;
   out_1488824774377298388[309] = 0.0;
   out_1488824774377298388[310] = 0.0;
   out_1488824774377298388[311] = 0.0;
   out_1488824774377298388[312] = 0.0;
   out_1488824774377298388[313] = 0.0;
   out_1488824774377298388[314] = 0.0;
   out_1488824774377298388[315] = 0.0;
   out_1488824774377298388[316] = 0.0;
   out_1488824774377298388[317] = 0.0;
   out_1488824774377298388[318] = 0.0;
   out_1488824774377298388[319] = 0.0;
   out_1488824774377298388[320] = 0.0;
   out_1488824774377298388[321] = 0.0;
   out_1488824774377298388[322] = 0.0;
   out_1488824774377298388[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_3252374166331305954) {
   out_3252374166331305954[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_3252374166331305954[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_3252374166331305954[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_3252374166331305954[3] = dt*state[12] + state[3];
   out_3252374166331305954[4] = dt*state[13] + state[4];
   out_3252374166331305954[5] = dt*state[14] + state[5];
   out_3252374166331305954[6] = state[6];
   out_3252374166331305954[7] = state[7];
   out_3252374166331305954[8] = state[8];
   out_3252374166331305954[9] = state[9];
   out_3252374166331305954[10] = state[10];
   out_3252374166331305954[11] = state[11];
   out_3252374166331305954[12] = state[12];
   out_3252374166331305954[13] = state[13];
   out_3252374166331305954[14] = state[14];
   out_3252374166331305954[15] = state[15];
   out_3252374166331305954[16] = state[16];
   out_3252374166331305954[17] = state[17];
}
void F_fun(double *state, double dt, double *out_7799911489866690446) {
   out_7799911489866690446[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_7799911489866690446[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_7799911489866690446[2] = 0;
   out_7799911489866690446[3] = 0;
   out_7799911489866690446[4] = 0;
   out_7799911489866690446[5] = 0;
   out_7799911489866690446[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_7799911489866690446[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_7799911489866690446[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_7799911489866690446[9] = 0;
   out_7799911489866690446[10] = 0;
   out_7799911489866690446[11] = 0;
   out_7799911489866690446[12] = 0;
   out_7799911489866690446[13] = 0;
   out_7799911489866690446[14] = 0;
   out_7799911489866690446[15] = 0;
   out_7799911489866690446[16] = 0;
   out_7799911489866690446[17] = 0;
   out_7799911489866690446[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_7799911489866690446[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_7799911489866690446[20] = 0;
   out_7799911489866690446[21] = 0;
   out_7799911489866690446[22] = 0;
   out_7799911489866690446[23] = 0;
   out_7799911489866690446[24] = 0;
   out_7799911489866690446[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_7799911489866690446[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_7799911489866690446[27] = 0;
   out_7799911489866690446[28] = 0;
   out_7799911489866690446[29] = 0;
   out_7799911489866690446[30] = 0;
   out_7799911489866690446[31] = 0;
   out_7799911489866690446[32] = 0;
   out_7799911489866690446[33] = 0;
   out_7799911489866690446[34] = 0;
   out_7799911489866690446[35] = 0;
   out_7799911489866690446[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_7799911489866690446[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_7799911489866690446[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_7799911489866690446[39] = 0;
   out_7799911489866690446[40] = 0;
   out_7799911489866690446[41] = 0;
   out_7799911489866690446[42] = 0;
   out_7799911489866690446[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_7799911489866690446[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_7799911489866690446[45] = 0;
   out_7799911489866690446[46] = 0;
   out_7799911489866690446[47] = 0;
   out_7799911489866690446[48] = 0;
   out_7799911489866690446[49] = 0;
   out_7799911489866690446[50] = 0;
   out_7799911489866690446[51] = 0;
   out_7799911489866690446[52] = 0;
   out_7799911489866690446[53] = 0;
   out_7799911489866690446[54] = 0;
   out_7799911489866690446[55] = 0;
   out_7799911489866690446[56] = 0;
   out_7799911489866690446[57] = 1;
   out_7799911489866690446[58] = 0;
   out_7799911489866690446[59] = 0;
   out_7799911489866690446[60] = 0;
   out_7799911489866690446[61] = 0;
   out_7799911489866690446[62] = 0;
   out_7799911489866690446[63] = 0;
   out_7799911489866690446[64] = 0;
   out_7799911489866690446[65] = 0;
   out_7799911489866690446[66] = dt;
   out_7799911489866690446[67] = 0;
   out_7799911489866690446[68] = 0;
   out_7799911489866690446[69] = 0;
   out_7799911489866690446[70] = 0;
   out_7799911489866690446[71] = 0;
   out_7799911489866690446[72] = 0;
   out_7799911489866690446[73] = 0;
   out_7799911489866690446[74] = 0;
   out_7799911489866690446[75] = 0;
   out_7799911489866690446[76] = 1;
   out_7799911489866690446[77] = 0;
   out_7799911489866690446[78] = 0;
   out_7799911489866690446[79] = 0;
   out_7799911489866690446[80] = 0;
   out_7799911489866690446[81] = 0;
   out_7799911489866690446[82] = 0;
   out_7799911489866690446[83] = 0;
   out_7799911489866690446[84] = 0;
   out_7799911489866690446[85] = dt;
   out_7799911489866690446[86] = 0;
   out_7799911489866690446[87] = 0;
   out_7799911489866690446[88] = 0;
   out_7799911489866690446[89] = 0;
   out_7799911489866690446[90] = 0;
   out_7799911489866690446[91] = 0;
   out_7799911489866690446[92] = 0;
   out_7799911489866690446[93] = 0;
   out_7799911489866690446[94] = 0;
   out_7799911489866690446[95] = 1;
   out_7799911489866690446[96] = 0;
   out_7799911489866690446[97] = 0;
   out_7799911489866690446[98] = 0;
   out_7799911489866690446[99] = 0;
   out_7799911489866690446[100] = 0;
   out_7799911489866690446[101] = 0;
   out_7799911489866690446[102] = 0;
   out_7799911489866690446[103] = 0;
   out_7799911489866690446[104] = dt;
   out_7799911489866690446[105] = 0;
   out_7799911489866690446[106] = 0;
   out_7799911489866690446[107] = 0;
   out_7799911489866690446[108] = 0;
   out_7799911489866690446[109] = 0;
   out_7799911489866690446[110] = 0;
   out_7799911489866690446[111] = 0;
   out_7799911489866690446[112] = 0;
   out_7799911489866690446[113] = 0;
   out_7799911489866690446[114] = 1;
   out_7799911489866690446[115] = 0;
   out_7799911489866690446[116] = 0;
   out_7799911489866690446[117] = 0;
   out_7799911489866690446[118] = 0;
   out_7799911489866690446[119] = 0;
   out_7799911489866690446[120] = 0;
   out_7799911489866690446[121] = 0;
   out_7799911489866690446[122] = 0;
   out_7799911489866690446[123] = 0;
   out_7799911489866690446[124] = 0;
   out_7799911489866690446[125] = 0;
   out_7799911489866690446[126] = 0;
   out_7799911489866690446[127] = 0;
   out_7799911489866690446[128] = 0;
   out_7799911489866690446[129] = 0;
   out_7799911489866690446[130] = 0;
   out_7799911489866690446[131] = 0;
   out_7799911489866690446[132] = 0;
   out_7799911489866690446[133] = 1;
   out_7799911489866690446[134] = 0;
   out_7799911489866690446[135] = 0;
   out_7799911489866690446[136] = 0;
   out_7799911489866690446[137] = 0;
   out_7799911489866690446[138] = 0;
   out_7799911489866690446[139] = 0;
   out_7799911489866690446[140] = 0;
   out_7799911489866690446[141] = 0;
   out_7799911489866690446[142] = 0;
   out_7799911489866690446[143] = 0;
   out_7799911489866690446[144] = 0;
   out_7799911489866690446[145] = 0;
   out_7799911489866690446[146] = 0;
   out_7799911489866690446[147] = 0;
   out_7799911489866690446[148] = 0;
   out_7799911489866690446[149] = 0;
   out_7799911489866690446[150] = 0;
   out_7799911489866690446[151] = 0;
   out_7799911489866690446[152] = 1;
   out_7799911489866690446[153] = 0;
   out_7799911489866690446[154] = 0;
   out_7799911489866690446[155] = 0;
   out_7799911489866690446[156] = 0;
   out_7799911489866690446[157] = 0;
   out_7799911489866690446[158] = 0;
   out_7799911489866690446[159] = 0;
   out_7799911489866690446[160] = 0;
   out_7799911489866690446[161] = 0;
   out_7799911489866690446[162] = 0;
   out_7799911489866690446[163] = 0;
   out_7799911489866690446[164] = 0;
   out_7799911489866690446[165] = 0;
   out_7799911489866690446[166] = 0;
   out_7799911489866690446[167] = 0;
   out_7799911489866690446[168] = 0;
   out_7799911489866690446[169] = 0;
   out_7799911489866690446[170] = 0;
   out_7799911489866690446[171] = 1;
   out_7799911489866690446[172] = 0;
   out_7799911489866690446[173] = 0;
   out_7799911489866690446[174] = 0;
   out_7799911489866690446[175] = 0;
   out_7799911489866690446[176] = 0;
   out_7799911489866690446[177] = 0;
   out_7799911489866690446[178] = 0;
   out_7799911489866690446[179] = 0;
   out_7799911489866690446[180] = 0;
   out_7799911489866690446[181] = 0;
   out_7799911489866690446[182] = 0;
   out_7799911489866690446[183] = 0;
   out_7799911489866690446[184] = 0;
   out_7799911489866690446[185] = 0;
   out_7799911489866690446[186] = 0;
   out_7799911489866690446[187] = 0;
   out_7799911489866690446[188] = 0;
   out_7799911489866690446[189] = 0;
   out_7799911489866690446[190] = 1;
   out_7799911489866690446[191] = 0;
   out_7799911489866690446[192] = 0;
   out_7799911489866690446[193] = 0;
   out_7799911489866690446[194] = 0;
   out_7799911489866690446[195] = 0;
   out_7799911489866690446[196] = 0;
   out_7799911489866690446[197] = 0;
   out_7799911489866690446[198] = 0;
   out_7799911489866690446[199] = 0;
   out_7799911489866690446[200] = 0;
   out_7799911489866690446[201] = 0;
   out_7799911489866690446[202] = 0;
   out_7799911489866690446[203] = 0;
   out_7799911489866690446[204] = 0;
   out_7799911489866690446[205] = 0;
   out_7799911489866690446[206] = 0;
   out_7799911489866690446[207] = 0;
   out_7799911489866690446[208] = 0;
   out_7799911489866690446[209] = 1;
   out_7799911489866690446[210] = 0;
   out_7799911489866690446[211] = 0;
   out_7799911489866690446[212] = 0;
   out_7799911489866690446[213] = 0;
   out_7799911489866690446[214] = 0;
   out_7799911489866690446[215] = 0;
   out_7799911489866690446[216] = 0;
   out_7799911489866690446[217] = 0;
   out_7799911489866690446[218] = 0;
   out_7799911489866690446[219] = 0;
   out_7799911489866690446[220] = 0;
   out_7799911489866690446[221] = 0;
   out_7799911489866690446[222] = 0;
   out_7799911489866690446[223] = 0;
   out_7799911489866690446[224] = 0;
   out_7799911489866690446[225] = 0;
   out_7799911489866690446[226] = 0;
   out_7799911489866690446[227] = 0;
   out_7799911489866690446[228] = 1;
   out_7799911489866690446[229] = 0;
   out_7799911489866690446[230] = 0;
   out_7799911489866690446[231] = 0;
   out_7799911489866690446[232] = 0;
   out_7799911489866690446[233] = 0;
   out_7799911489866690446[234] = 0;
   out_7799911489866690446[235] = 0;
   out_7799911489866690446[236] = 0;
   out_7799911489866690446[237] = 0;
   out_7799911489866690446[238] = 0;
   out_7799911489866690446[239] = 0;
   out_7799911489866690446[240] = 0;
   out_7799911489866690446[241] = 0;
   out_7799911489866690446[242] = 0;
   out_7799911489866690446[243] = 0;
   out_7799911489866690446[244] = 0;
   out_7799911489866690446[245] = 0;
   out_7799911489866690446[246] = 0;
   out_7799911489866690446[247] = 1;
   out_7799911489866690446[248] = 0;
   out_7799911489866690446[249] = 0;
   out_7799911489866690446[250] = 0;
   out_7799911489866690446[251] = 0;
   out_7799911489866690446[252] = 0;
   out_7799911489866690446[253] = 0;
   out_7799911489866690446[254] = 0;
   out_7799911489866690446[255] = 0;
   out_7799911489866690446[256] = 0;
   out_7799911489866690446[257] = 0;
   out_7799911489866690446[258] = 0;
   out_7799911489866690446[259] = 0;
   out_7799911489866690446[260] = 0;
   out_7799911489866690446[261] = 0;
   out_7799911489866690446[262] = 0;
   out_7799911489866690446[263] = 0;
   out_7799911489866690446[264] = 0;
   out_7799911489866690446[265] = 0;
   out_7799911489866690446[266] = 1;
   out_7799911489866690446[267] = 0;
   out_7799911489866690446[268] = 0;
   out_7799911489866690446[269] = 0;
   out_7799911489866690446[270] = 0;
   out_7799911489866690446[271] = 0;
   out_7799911489866690446[272] = 0;
   out_7799911489866690446[273] = 0;
   out_7799911489866690446[274] = 0;
   out_7799911489866690446[275] = 0;
   out_7799911489866690446[276] = 0;
   out_7799911489866690446[277] = 0;
   out_7799911489866690446[278] = 0;
   out_7799911489866690446[279] = 0;
   out_7799911489866690446[280] = 0;
   out_7799911489866690446[281] = 0;
   out_7799911489866690446[282] = 0;
   out_7799911489866690446[283] = 0;
   out_7799911489866690446[284] = 0;
   out_7799911489866690446[285] = 1;
   out_7799911489866690446[286] = 0;
   out_7799911489866690446[287] = 0;
   out_7799911489866690446[288] = 0;
   out_7799911489866690446[289] = 0;
   out_7799911489866690446[290] = 0;
   out_7799911489866690446[291] = 0;
   out_7799911489866690446[292] = 0;
   out_7799911489866690446[293] = 0;
   out_7799911489866690446[294] = 0;
   out_7799911489866690446[295] = 0;
   out_7799911489866690446[296] = 0;
   out_7799911489866690446[297] = 0;
   out_7799911489866690446[298] = 0;
   out_7799911489866690446[299] = 0;
   out_7799911489866690446[300] = 0;
   out_7799911489866690446[301] = 0;
   out_7799911489866690446[302] = 0;
   out_7799911489866690446[303] = 0;
   out_7799911489866690446[304] = 1;
   out_7799911489866690446[305] = 0;
   out_7799911489866690446[306] = 0;
   out_7799911489866690446[307] = 0;
   out_7799911489866690446[308] = 0;
   out_7799911489866690446[309] = 0;
   out_7799911489866690446[310] = 0;
   out_7799911489866690446[311] = 0;
   out_7799911489866690446[312] = 0;
   out_7799911489866690446[313] = 0;
   out_7799911489866690446[314] = 0;
   out_7799911489866690446[315] = 0;
   out_7799911489866690446[316] = 0;
   out_7799911489866690446[317] = 0;
   out_7799911489866690446[318] = 0;
   out_7799911489866690446[319] = 0;
   out_7799911489866690446[320] = 0;
   out_7799911489866690446[321] = 0;
   out_7799911489866690446[322] = 0;
   out_7799911489866690446[323] = 1;
}
void h_4(double *state, double *unused, double *out_3548480780703373814) {
   out_3548480780703373814[0] = state[6] + state[9];
   out_3548480780703373814[1] = state[7] + state[10];
   out_3548480780703373814[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_9039098698091417951) {
   out_9039098698091417951[0] = 0;
   out_9039098698091417951[1] = 0;
   out_9039098698091417951[2] = 0;
   out_9039098698091417951[3] = 0;
   out_9039098698091417951[4] = 0;
   out_9039098698091417951[5] = 0;
   out_9039098698091417951[6] = 1;
   out_9039098698091417951[7] = 0;
   out_9039098698091417951[8] = 0;
   out_9039098698091417951[9] = 1;
   out_9039098698091417951[10] = 0;
   out_9039098698091417951[11] = 0;
   out_9039098698091417951[12] = 0;
   out_9039098698091417951[13] = 0;
   out_9039098698091417951[14] = 0;
   out_9039098698091417951[15] = 0;
   out_9039098698091417951[16] = 0;
   out_9039098698091417951[17] = 0;
   out_9039098698091417951[18] = 0;
   out_9039098698091417951[19] = 0;
   out_9039098698091417951[20] = 0;
   out_9039098698091417951[21] = 0;
   out_9039098698091417951[22] = 0;
   out_9039098698091417951[23] = 0;
   out_9039098698091417951[24] = 0;
   out_9039098698091417951[25] = 1;
   out_9039098698091417951[26] = 0;
   out_9039098698091417951[27] = 0;
   out_9039098698091417951[28] = 1;
   out_9039098698091417951[29] = 0;
   out_9039098698091417951[30] = 0;
   out_9039098698091417951[31] = 0;
   out_9039098698091417951[32] = 0;
   out_9039098698091417951[33] = 0;
   out_9039098698091417951[34] = 0;
   out_9039098698091417951[35] = 0;
   out_9039098698091417951[36] = 0;
   out_9039098698091417951[37] = 0;
   out_9039098698091417951[38] = 0;
   out_9039098698091417951[39] = 0;
   out_9039098698091417951[40] = 0;
   out_9039098698091417951[41] = 0;
   out_9039098698091417951[42] = 0;
   out_9039098698091417951[43] = 0;
   out_9039098698091417951[44] = 1;
   out_9039098698091417951[45] = 0;
   out_9039098698091417951[46] = 0;
   out_9039098698091417951[47] = 1;
   out_9039098698091417951[48] = 0;
   out_9039098698091417951[49] = 0;
   out_9039098698091417951[50] = 0;
   out_9039098698091417951[51] = 0;
   out_9039098698091417951[52] = 0;
   out_9039098698091417951[53] = 0;
}
void h_10(double *state, double *unused, double *out_6772598767194441225) {
   out_6772598767194441225[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_6772598767194441225[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_6772598767194441225[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_4194114852527038040) {
   out_4194114852527038040[0] = 0;
   out_4194114852527038040[1] = 9.8100000000000005*cos(state[1]);
   out_4194114852527038040[2] = 0;
   out_4194114852527038040[3] = 0;
   out_4194114852527038040[4] = -state[8];
   out_4194114852527038040[5] = state[7];
   out_4194114852527038040[6] = 0;
   out_4194114852527038040[7] = state[5];
   out_4194114852527038040[8] = -state[4];
   out_4194114852527038040[9] = 0;
   out_4194114852527038040[10] = 0;
   out_4194114852527038040[11] = 0;
   out_4194114852527038040[12] = 1;
   out_4194114852527038040[13] = 0;
   out_4194114852527038040[14] = 0;
   out_4194114852527038040[15] = 1;
   out_4194114852527038040[16] = 0;
   out_4194114852527038040[17] = 0;
   out_4194114852527038040[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_4194114852527038040[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_4194114852527038040[20] = 0;
   out_4194114852527038040[21] = state[8];
   out_4194114852527038040[22] = 0;
   out_4194114852527038040[23] = -state[6];
   out_4194114852527038040[24] = -state[5];
   out_4194114852527038040[25] = 0;
   out_4194114852527038040[26] = state[3];
   out_4194114852527038040[27] = 0;
   out_4194114852527038040[28] = 0;
   out_4194114852527038040[29] = 0;
   out_4194114852527038040[30] = 0;
   out_4194114852527038040[31] = 1;
   out_4194114852527038040[32] = 0;
   out_4194114852527038040[33] = 0;
   out_4194114852527038040[34] = 1;
   out_4194114852527038040[35] = 0;
   out_4194114852527038040[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_4194114852527038040[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_4194114852527038040[38] = 0;
   out_4194114852527038040[39] = -state[7];
   out_4194114852527038040[40] = state[6];
   out_4194114852527038040[41] = 0;
   out_4194114852527038040[42] = state[4];
   out_4194114852527038040[43] = -state[3];
   out_4194114852527038040[44] = 0;
   out_4194114852527038040[45] = 0;
   out_4194114852527038040[46] = 0;
   out_4194114852527038040[47] = 0;
   out_4194114852527038040[48] = 0;
   out_4194114852527038040[49] = 0;
   out_4194114852527038040[50] = 1;
   out_4194114852527038040[51] = 0;
   out_4194114852527038040[52] = 0;
   out_4194114852527038040[53] = 1;
}
void h_13(double *state, double *unused, double *out_781619376527489648) {
   out_781619376527489648[0] = state[3];
   out_781619376527489648[1] = state[4];
   out_781619376527489648[2] = state[5];
}
void H_13(double *state, double *unused, double *out_5826824872759085150) {
   out_5826824872759085150[0] = 0;
   out_5826824872759085150[1] = 0;
   out_5826824872759085150[2] = 0;
   out_5826824872759085150[3] = 1;
   out_5826824872759085150[4] = 0;
   out_5826824872759085150[5] = 0;
   out_5826824872759085150[6] = 0;
   out_5826824872759085150[7] = 0;
   out_5826824872759085150[8] = 0;
   out_5826824872759085150[9] = 0;
   out_5826824872759085150[10] = 0;
   out_5826824872759085150[11] = 0;
   out_5826824872759085150[12] = 0;
   out_5826824872759085150[13] = 0;
   out_5826824872759085150[14] = 0;
   out_5826824872759085150[15] = 0;
   out_5826824872759085150[16] = 0;
   out_5826824872759085150[17] = 0;
   out_5826824872759085150[18] = 0;
   out_5826824872759085150[19] = 0;
   out_5826824872759085150[20] = 0;
   out_5826824872759085150[21] = 0;
   out_5826824872759085150[22] = 1;
   out_5826824872759085150[23] = 0;
   out_5826824872759085150[24] = 0;
   out_5826824872759085150[25] = 0;
   out_5826824872759085150[26] = 0;
   out_5826824872759085150[27] = 0;
   out_5826824872759085150[28] = 0;
   out_5826824872759085150[29] = 0;
   out_5826824872759085150[30] = 0;
   out_5826824872759085150[31] = 0;
   out_5826824872759085150[32] = 0;
   out_5826824872759085150[33] = 0;
   out_5826824872759085150[34] = 0;
   out_5826824872759085150[35] = 0;
   out_5826824872759085150[36] = 0;
   out_5826824872759085150[37] = 0;
   out_5826824872759085150[38] = 0;
   out_5826824872759085150[39] = 0;
   out_5826824872759085150[40] = 0;
   out_5826824872759085150[41] = 1;
   out_5826824872759085150[42] = 0;
   out_5826824872759085150[43] = 0;
   out_5826824872759085150[44] = 0;
   out_5826824872759085150[45] = 0;
   out_5826824872759085150[46] = 0;
   out_5826824872759085150[47] = 0;
   out_5826824872759085150[48] = 0;
   out_5826824872759085150[49] = 0;
   out_5826824872759085150[50] = 0;
   out_5826824872759085150[51] = 0;
   out_5826824872759085150[52] = 0;
   out_5826824872759085150[53] = 0;
}
void h_14(double *state, double *unused, double *out_5521513375942515480) {
   out_5521513375942515480[0] = state[6];
   out_5521513375942515480[1] = state[7];
   out_5521513375942515480[2] = state[8];
}
void H_14(double *state, double *unused, double *out_6324856943322761369) {
   out_6324856943322761369[0] = 0;
   out_6324856943322761369[1] = 0;
   out_6324856943322761369[2] = 0;
   out_6324856943322761369[3] = 0;
   out_6324856943322761369[4] = 0;
   out_6324856943322761369[5] = 0;
   out_6324856943322761369[6] = 1;
   out_6324856943322761369[7] = 0;
   out_6324856943322761369[8] = 0;
   out_6324856943322761369[9] = 0;
   out_6324856943322761369[10] = 0;
   out_6324856943322761369[11] = 0;
   out_6324856943322761369[12] = 0;
   out_6324856943322761369[13] = 0;
   out_6324856943322761369[14] = 0;
   out_6324856943322761369[15] = 0;
   out_6324856943322761369[16] = 0;
   out_6324856943322761369[17] = 0;
   out_6324856943322761369[18] = 0;
   out_6324856943322761369[19] = 0;
   out_6324856943322761369[20] = 0;
   out_6324856943322761369[21] = 0;
   out_6324856943322761369[22] = 0;
   out_6324856943322761369[23] = 0;
   out_6324856943322761369[24] = 0;
   out_6324856943322761369[25] = 1;
   out_6324856943322761369[26] = 0;
   out_6324856943322761369[27] = 0;
   out_6324856943322761369[28] = 0;
   out_6324856943322761369[29] = 0;
   out_6324856943322761369[30] = 0;
   out_6324856943322761369[31] = 0;
   out_6324856943322761369[32] = 0;
   out_6324856943322761369[33] = 0;
   out_6324856943322761369[34] = 0;
   out_6324856943322761369[35] = 0;
   out_6324856943322761369[36] = 0;
   out_6324856943322761369[37] = 0;
   out_6324856943322761369[38] = 0;
   out_6324856943322761369[39] = 0;
   out_6324856943322761369[40] = 0;
   out_6324856943322761369[41] = 0;
   out_6324856943322761369[42] = 0;
   out_6324856943322761369[43] = 0;
   out_6324856943322761369[44] = 1;
   out_6324856943322761369[45] = 0;
   out_6324856943322761369[46] = 0;
   out_6324856943322761369[47] = 0;
   out_6324856943322761369[48] = 0;
   out_6324856943322761369[49] = 0;
   out_6324856943322761369[50] = 0;
   out_6324856943322761369[51] = 0;
   out_6324856943322761369[52] = 0;
   out_6324856943322761369[53] = 0;
}
#include <eigen3/Eigen/Dense>
#include <iostream>

typedef Eigen::Matrix<double, DIM, DIM, Eigen::RowMajor> DDM;
typedef Eigen::Matrix<double, EDIM, EDIM, Eigen::RowMajor> EEM;
typedef Eigen::Matrix<double, DIM, EDIM, Eigen::RowMajor> DEM;

void predict(double *in_x, double *in_P, double *in_Q, double dt) {
  typedef Eigen::Matrix<double, MEDIM, MEDIM, Eigen::RowMajor> RRM;

  double nx[DIM] = {0};
  double in_F[EDIM*EDIM] = {0};

  // functions from sympy
  f_fun(in_x, dt, nx);
  F_fun(in_x, dt, in_F);


  EEM F(in_F);
  EEM P(in_P);
  EEM Q(in_Q);

  RRM F_main = F.topLeftCorner(MEDIM, MEDIM);
  P.topLeftCorner(MEDIM, MEDIM) = (F_main * P.topLeftCorner(MEDIM, MEDIM)) * F_main.transpose();
  P.topRightCorner(MEDIM, EDIM - MEDIM) = F_main * P.topRightCorner(MEDIM, EDIM - MEDIM);
  P.bottomLeftCorner(EDIM - MEDIM, MEDIM) = P.bottomLeftCorner(EDIM - MEDIM, MEDIM) * F_main.transpose();

  P = P + dt*Q;

  // copy out state
  memcpy(in_x, nx, DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
}

// note: extra_args dim only correct when null space projecting
// otherwise 1
template <int ZDIM, int EADIM, bool MAHA_TEST>
void update(double *in_x, double *in_P, Hfun h_fun, Hfun H_fun, Hfun Hea_fun, double *in_z, double *in_R, double *in_ea, double MAHA_THRESHOLD) {
  typedef Eigen::Matrix<double, ZDIM, ZDIM, Eigen::RowMajor> ZZM;
  typedef Eigen::Matrix<double, ZDIM, DIM, Eigen::RowMajor> ZDM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, EDIM, Eigen::RowMajor> XEM;
  //typedef Eigen::Matrix<double, EDIM, ZDIM, Eigen::RowMajor> EZM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 1> X1M;
  typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> XXM;

  double in_hx[ZDIM] = {0};
  double in_H[ZDIM * DIM] = {0};
  double in_H_mod[EDIM * DIM] = {0};
  double delta_x[EDIM] = {0};
  double x_new[DIM] = {0};


  // state x, P
  Eigen::Matrix<double, ZDIM, 1> z(in_z);
  EEM P(in_P);
  ZZM pre_R(in_R);

  // functions from sympy
  h_fun(in_x, in_ea, in_hx);
  H_fun(in_x, in_ea, in_H);
  ZDM pre_H(in_H);

  // get y (y = z - hx)
  Eigen::Matrix<double, ZDIM, 1> pre_y(in_hx); pre_y = z - pre_y;
  X1M y; XXM H; XXM R;
  if (Hea_fun){
    typedef Eigen::Matrix<double, ZDIM, EADIM, Eigen::RowMajor> ZAM;
    double in_Hea[ZDIM * EADIM] = {0};
    Hea_fun(in_x, in_ea, in_Hea);
    ZAM Hea(in_Hea);
    XXM A = Hea.transpose().fullPivLu().kernel();


    y = A.transpose() * pre_y;
    H = A.transpose() * pre_H;
    R = A.transpose() * pre_R * A;
  } else {
    y = pre_y;
    H = pre_H;
    R = pre_R;
  }
  // get modified H
  H_mod_fun(in_x, in_H_mod);
  DEM H_mod(in_H_mod);
  XEM H_err = H * H_mod;

  // Do mahalobis distance test
  if (MAHA_TEST){
    XXM a = (H_err * P * H_err.transpose() + R).inverse();
    double maha_dist = y.transpose() * a * y;
    if (maha_dist > MAHA_THRESHOLD){
      R = 1.0e16 * R;
    }
  }

  // Outlier resilient weighting
  double weight = 1;//(1.5)/(1 + y.squaredNorm()/R.sum());

  // kalman gains and I_KH
  XXM S = ((H_err * P) * H_err.transpose()) + R/weight;
  XEM KT = S.fullPivLu().solve(H_err * P.transpose());
  //EZM K = KT.transpose(); TODO: WHY DOES THIS NOT COMPILE?
  //EZM K = S.fullPivLu().solve(H_err * P.transpose()).transpose();
  //std::cout << "Here is the matrix rot:\n" << K << std::endl;
  EEM I_KH = Eigen::Matrix<double, EDIM, EDIM>::Identity() - (KT.transpose() * H_err);

  // update state by injecting dx
  Eigen::Matrix<double, EDIM, 1> dx(delta_x);
  dx  = (KT.transpose() * y);
  memcpy(delta_x, dx.data(), EDIM * sizeof(double));
  err_fun(in_x, delta_x, x_new);
  Eigen::Matrix<double, DIM, 1> x(x_new);

  // update cov
  P = ((I_KH * P) * I_KH.transpose()) + ((KT.transpose() * R) * KT);

  // copy out state
  memcpy(in_x, x.data(), DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
  memcpy(in_z, y.data(), y.rows() * sizeof(double));
}




}
extern "C" {

void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_4, H_4, NULL, in_z, in_R, in_ea, MAHA_THRESH_4);
}
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_10, H_10, NULL, in_z, in_R, in_ea, MAHA_THRESH_10);
}
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_13, H_13, NULL, in_z, in_R, in_ea, MAHA_THRESH_13);
}
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_14, H_14, NULL, in_z, in_R, in_ea, MAHA_THRESH_14);
}
void pose_err_fun(double *nom_x, double *delta_x, double *out_5153672272046342551) {
  err_fun(nom_x, delta_x, out_5153672272046342551);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_7756557426239194035) {
  inv_err_fun(nom_x, true_x, out_7756557426239194035);
}
void pose_H_mod_fun(double *state, double *out_1488824774377298388) {
  H_mod_fun(state, out_1488824774377298388);
}
void pose_f_fun(double *state, double dt, double *out_3252374166331305954) {
  f_fun(state,  dt, out_3252374166331305954);
}
void pose_F_fun(double *state, double dt, double *out_7799911489866690446) {
  F_fun(state,  dt, out_7799911489866690446);
}
void pose_h_4(double *state, double *unused, double *out_3548480780703373814) {
  h_4(state, unused, out_3548480780703373814);
}
void pose_H_4(double *state, double *unused, double *out_9039098698091417951) {
  H_4(state, unused, out_9039098698091417951);
}
void pose_h_10(double *state, double *unused, double *out_6772598767194441225) {
  h_10(state, unused, out_6772598767194441225);
}
void pose_H_10(double *state, double *unused, double *out_4194114852527038040) {
  H_10(state, unused, out_4194114852527038040);
}
void pose_h_13(double *state, double *unused, double *out_781619376527489648) {
  h_13(state, unused, out_781619376527489648);
}
void pose_H_13(double *state, double *unused, double *out_5826824872759085150) {
  H_13(state, unused, out_5826824872759085150);
}
void pose_h_14(double *state, double *unused, double *out_5521513375942515480) {
  h_14(state, unused, out_5521513375942515480);
}
void pose_H_14(double *state, double *unused, double *out_6324856943322761369) {
  H_14(state, unused, out_6324856943322761369);
}
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
}

const EKF pose = {
  .name = "pose",
  .kinds = { 4, 10, 13, 14 },
  .feature_kinds = {  },
  .f_fun = pose_f_fun,
  .F_fun = pose_F_fun,
  .err_fun = pose_err_fun,
  .inv_err_fun = pose_inv_err_fun,
  .H_mod_fun = pose_H_mod_fun,
  .predict = pose_predict,
  .hs = {
    { 4, pose_h_4 },
    { 10, pose_h_10 },
    { 13, pose_h_13 },
    { 14, pose_h_14 },
  },
  .Hs = {
    { 4, pose_H_4 },
    { 10, pose_H_10 },
    { 13, pose_H_13 },
    { 14, pose_H_14 },
  },
  .updates = {
    { 4, pose_update_4 },
    { 10, pose_update_10 },
    { 13, pose_update_13 },
    { 14, pose_update_14 },
  },
  .Hes = {
  },
  .sets = {
  },
  .extra_routines = {
  },
};

ekf_lib_init(pose)
