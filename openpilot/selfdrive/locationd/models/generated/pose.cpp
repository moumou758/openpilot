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
void err_fun(double *nom_x, double *delta_x, double *out_7734263280416187077) {
   out_7734263280416187077[0] = delta_x[0] + nom_x[0];
   out_7734263280416187077[1] = delta_x[1] + nom_x[1];
   out_7734263280416187077[2] = delta_x[2] + nom_x[2];
   out_7734263280416187077[3] = delta_x[3] + nom_x[3];
   out_7734263280416187077[4] = delta_x[4] + nom_x[4];
   out_7734263280416187077[5] = delta_x[5] + nom_x[5];
   out_7734263280416187077[6] = delta_x[6] + nom_x[6];
   out_7734263280416187077[7] = delta_x[7] + nom_x[7];
   out_7734263280416187077[8] = delta_x[8] + nom_x[8];
   out_7734263280416187077[9] = delta_x[9] + nom_x[9];
   out_7734263280416187077[10] = delta_x[10] + nom_x[10];
   out_7734263280416187077[11] = delta_x[11] + nom_x[11];
   out_7734263280416187077[12] = delta_x[12] + nom_x[12];
   out_7734263280416187077[13] = delta_x[13] + nom_x[13];
   out_7734263280416187077[14] = delta_x[14] + nom_x[14];
   out_7734263280416187077[15] = delta_x[15] + nom_x[15];
   out_7734263280416187077[16] = delta_x[16] + nom_x[16];
   out_7734263280416187077[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_6670314649637788989) {
   out_6670314649637788989[0] = -nom_x[0] + true_x[0];
   out_6670314649637788989[1] = -nom_x[1] + true_x[1];
   out_6670314649637788989[2] = -nom_x[2] + true_x[2];
   out_6670314649637788989[3] = -nom_x[3] + true_x[3];
   out_6670314649637788989[4] = -nom_x[4] + true_x[4];
   out_6670314649637788989[5] = -nom_x[5] + true_x[5];
   out_6670314649637788989[6] = -nom_x[6] + true_x[6];
   out_6670314649637788989[7] = -nom_x[7] + true_x[7];
   out_6670314649637788989[8] = -nom_x[8] + true_x[8];
   out_6670314649637788989[9] = -nom_x[9] + true_x[9];
   out_6670314649637788989[10] = -nom_x[10] + true_x[10];
   out_6670314649637788989[11] = -nom_x[11] + true_x[11];
   out_6670314649637788989[12] = -nom_x[12] + true_x[12];
   out_6670314649637788989[13] = -nom_x[13] + true_x[13];
   out_6670314649637788989[14] = -nom_x[14] + true_x[14];
   out_6670314649637788989[15] = -nom_x[15] + true_x[15];
   out_6670314649637788989[16] = -nom_x[16] + true_x[16];
   out_6670314649637788989[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_6269518418037593252) {
   out_6269518418037593252[0] = 1.0;
   out_6269518418037593252[1] = 0.0;
   out_6269518418037593252[2] = 0.0;
   out_6269518418037593252[3] = 0.0;
   out_6269518418037593252[4] = 0.0;
   out_6269518418037593252[5] = 0.0;
   out_6269518418037593252[6] = 0.0;
   out_6269518418037593252[7] = 0.0;
   out_6269518418037593252[8] = 0.0;
   out_6269518418037593252[9] = 0.0;
   out_6269518418037593252[10] = 0.0;
   out_6269518418037593252[11] = 0.0;
   out_6269518418037593252[12] = 0.0;
   out_6269518418037593252[13] = 0.0;
   out_6269518418037593252[14] = 0.0;
   out_6269518418037593252[15] = 0.0;
   out_6269518418037593252[16] = 0.0;
   out_6269518418037593252[17] = 0.0;
   out_6269518418037593252[18] = 0.0;
   out_6269518418037593252[19] = 1.0;
   out_6269518418037593252[20] = 0.0;
   out_6269518418037593252[21] = 0.0;
   out_6269518418037593252[22] = 0.0;
   out_6269518418037593252[23] = 0.0;
   out_6269518418037593252[24] = 0.0;
   out_6269518418037593252[25] = 0.0;
   out_6269518418037593252[26] = 0.0;
   out_6269518418037593252[27] = 0.0;
   out_6269518418037593252[28] = 0.0;
   out_6269518418037593252[29] = 0.0;
   out_6269518418037593252[30] = 0.0;
   out_6269518418037593252[31] = 0.0;
   out_6269518418037593252[32] = 0.0;
   out_6269518418037593252[33] = 0.0;
   out_6269518418037593252[34] = 0.0;
   out_6269518418037593252[35] = 0.0;
   out_6269518418037593252[36] = 0.0;
   out_6269518418037593252[37] = 0.0;
   out_6269518418037593252[38] = 1.0;
   out_6269518418037593252[39] = 0.0;
   out_6269518418037593252[40] = 0.0;
   out_6269518418037593252[41] = 0.0;
   out_6269518418037593252[42] = 0.0;
   out_6269518418037593252[43] = 0.0;
   out_6269518418037593252[44] = 0.0;
   out_6269518418037593252[45] = 0.0;
   out_6269518418037593252[46] = 0.0;
   out_6269518418037593252[47] = 0.0;
   out_6269518418037593252[48] = 0.0;
   out_6269518418037593252[49] = 0.0;
   out_6269518418037593252[50] = 0.0;
   out_6269518418037593252[51] = 0.0;
   out_6269518418037593252[52] = 0.0;
   out_6269518418037593252[53] = 0.0;
   out_6269518418037593252[54] = 0.0;
   out_6269518418037593252[55] = 0.0;
   out_6269518418037593252[56] = 0.0;
   out_6269518418037593252[57] = 1.0;
   out_6269518418037593252[58] = 0.0;
   out_6269518418037593252[59] = 0.0;
   out_6269518418037593252[60] = 0.0;
   out_6269518418037593252[61] = 0.0;
   out_6269518418037593252[62] = 0.0;
   out_6269518418037593252[63] = 0.0;
   out_6269518418037593252[64] = 0.0;
   out_6269518418037593252[65] = 0.0;
   out_6269518418037593252[66] = 0.0;
   out_6269518418037593252[67] = 0.0;
   out_6269518418037593252[68] = 0.0;
   out_6269518418037593252[69] = 0.0;
   out_6269518418037593252[70] = 0.0;
   out_6269518418037593252[71] = 0.0;
   out_6269518418037593252[72] = 0.0;
   out_6269518418037593252[73] = 0.0;
   out_6269518418037593252[74] = 0.0;
   out_6269518418037593252[75] = 0.0;
   out_6269518418037593252[76] = 1.0;
   out_6269518418037593252[77] = 0.0;
   out_6269518418037593252[78] = 0.0;
   out_6269518418037593252[79] = 0.0;
   out_6269518418037593252[80] = 0.0;
   out_6269518418037593252[81] = 0.0;
   out_6269518418037593252[82] = 0.0;
   out_6269518418037593252[83] = 0.0;
   out_6269518418037593252[84] = 0.0;
   out_6269518418037593252[85] = 0.0;
   out_6269518418037593252[86] = 0.0;
   out_6269518418037593252[87] = 0.0;
   out_6269518418037593252[88] = 0.0;
   out_6269518418037593252[89] = 0.0;
   out_6269518418037593252[90] = 0.0;
   out_6269518418037593252[91] = 0.0;
   out_6269518418037593252[92] = 0.0;
   out_6269518418037593252[93] = 0.0;
   out_6269518418037593252[94] = 0.0;
   out_6269518418037593252[95] = 1.0;
   out_6269518418037593252[96] = 0.0;
   out_6269518418037593252[97] = 0.0;
   out_6269518418037593252[98] = 0.0;
   out_6269518418037593252[99] = 0.0;
   out_6269518418037593252[100] = 0.0;
   out_6269518418037593252[101] = 0.0;
   out_6269518418037593252[102] = 0.0;
   out_6269518418037593252[103] = 0.0;
   out_6269518418037593252[104] = 0.0;
   out_6269518418037593252[105] = 0.0;
   out_6269518418037593252[106] = 0.0;
   out_6269518418037593252[107] = 0.0;
   out_6269518418037593252[108] = 0.0;
   out_6269518418037593252[109] = 0.0;
   out_6269518418037593252[110] = 0.0;
   out_6269518418037593252[111] = 0.0;
   out_6269518418037593252[112] = 0.0;
   out_6269518418037593252[113] = 0.0;
   out_6269518418037593252[114] = 1.0;
   out_6269518418037593252[115] = 0.0;
   out_6269518418037593252[116] = 0.0;
   out_6269518418037593252[117] = 0.0;
   out_6269518418037593252[118] = 0.0;
   out_6269518418037593252[119] = 0.0;
   out_6269518418037593252[120] = 0.0;
   out_6269518418037593252[121] = 0.0;
   out_6269518418037593252[122] = 0.0;
   out_6269518418037593252[123] = 0.0;
   out_6269518418037593252[124] = 0.0;
   out_6269518418037593252[125] = 0.0;
   out_6269518418037593252[126] = 0.0;
   out_6269518418037593252[127] = 0.0;
   out_6269518418037593252[128] = 0.0;
   out_6269518418037593252[129] = 0.0;
   out_6269518418037593252[130] = 0.0;
   out_6269518418037593252[131] = 0.0;
   out_6269518418037593252[132] = 0.0;
   out_6269518418037593252[133] = 1.0;
   out_6269518418037593252[134] = 0.0;
   out_6269518418037593252[135] = 0.0;
   out_6269518418037593252[136] = 0.0;
   out_6269518418037593252[137] = 0.0;
   out_6269518418037593252[138] = 0.0;
   out_6269518418037593252[139] = 0.0;
   out_6269518418037593252[140] = 0.0;
   out_6269518418037593252[141] = 0.0;
   out_6269518418037593252[142] = 0.0;
   out_6269518418037593252[143] = 0.0;
   out_6269518418037593252[144] = 0.0;
   out_6269518418037593252[145] = 0.0;
   out_6269518418037593252[146] = 0.0;
   out_6269518418037593252[147] = 0.0;
   out_6269518418037593252[148] = 0.0;
   out_6269518418037593252[149] = 0.0;
   out_6269518418037593252[150] = 0.0;
   out_6269518418037593252[151] = 0.0;
   out_6269518418037593252[152] = 1.0;
   out_6269518418037593252[153] = 0.0;
   out_6269518418037593252[154] = 0.0;
   out_6269518418037593252[155] = 0.0;
   out_6269518418037593252[156] = 0.0;
   out_6269518418037593252[157] = 0.0;
   out_6269518418037593252[158] = 0.0;
   out_6269518418037593252[159] = 0.0;
   out_6269518418037593252[160] = 0.0;
   out_6269518418037593252[161] = 0.0;
   out_6269518418037593252[162] = 0.0;
   out_6269518418037593252[163] = 0.0;
   out_6269518418037593252[164] = 0.0;
   out_6269518418037593252[165] = 0.0;
   out_6269518418037593252[166] = 0.0;
   out_6269518418037593252[167] = 0.0;
   out_6269518418037593252[168] = 0.0;
   out_6269518418037593252[169] = 0.0;
   out_6269518418037593252[170] = 0.0;
   out_6269518418037593252[171] = 1.0;
   out_6269518418037593252[172] = 0.0;
   out_6269518418037593252[173] = 0.0;
   out_6269518418037593252[174] = 0.0;
   out_6269518418037593252[175] = 0.0;
   out_6269518418037593252[176] = 0.0;
   out_6269518418037593252[177] = 0.0;
   out_6269518418037593252[178] = 0.0;
   out_6269518418037593252[179] = 0.0;
   out_6269518418037593252[180] = 0.0;
   out_6269518418037593252[181] = 0.0;
   out_6269518418037593252[182] = 0.0;
   out_6269518418037593252[183] = 0.0;
   out_6269518418037593252[184] = 0.0;
   out_6269518418037593252[185] = 0.0;
   out_6269518418037593252[186] = 0.0;
   out_6269518418037593252[187] = 0.0;
   out_6269518418037593252[188] = 0.0;
   out_6269518418037593252[189] = 0.0;
   out_6269518418037593252[190] = 1.0;
   out_6269518418037593252[191] = 0.0;
   out_6269518418037593252[192] = 0.0;
   out_6269518418037593252[193] = 0.0;
   out_6269518418037593252[194] = 0.0;
   out_6269518418037593252[195] = 0.0;
   out_6269518418037593252[196] = 0.0;
   out_6269518418037593252[197] = 0.0;
   out_6269518418037593252[198] = 0.0;
   out_6269518418037593252[199] = 0.0;
   out_6269518418037593252[200] = 0.0;
   out_6269518418037593252[201] = 0.0;
   out_6269518418037593252[202] = 0.0;
   out_6269518418037593252[203] = 0.0;
   out_6269518418037593252[204] = 0.0;
   out_6269518418037593252[205] = 0.0;
   out_6269518418037593252[206] = 0.0;
   out_6269518418037593252[207] = 0.0;
   out_6269518418037593252[208] = 0.0;
   out_6269518418037593252[209] = 1.0;
   out_6269518418037593252[210] = 0.0;
   out_6269518418037593252[211] = 0.0;
   out_6269518418037593252[212] = 0.0;
   out_6269518418037593252[213] = 0.0;
   out_6269518418037593252[214] = 0.0;
   out_6269518418037593252[215] = 0.0;
   out_6269518418037593252[216] = 0.0;
   out_6269518418037593252[217] = 0.0;
   out_6269518418037593252[218] = 0.0;
   out_6269518418037593252[219] = 0.0;
   out_6269518418037593252[220] = 0.0;
   out_6269518418037593252[221] = 0.0;
   out_6269518418037593252[222] = 0.0;
   out_6269518418037593252[223] = 0.0;
   out_6269518418037593252[224] = 0.0;
   out_6269518418037593252[225] = 0.0;
   out_6269518418037593252[226] = 0.0;
   out_6269518418037593252[227] = 0.0;
   out_6269518418037593252[228] = 1.0;
   out_6269518418037593252[229] = 0.0;
   out_6269518418037593252[230] = 0.0;
   out_6269518418037593252[231] = 0.0;
   out_6269518418037593252[232] = 0.0;
   out_6269518418037593252[233] = 0.0;
   out_6269518418037593252[234] = 0.0;
   out_6269518418037593252[235] = 0.0;
   out_6269518418037593252[236] = 0.0;
   out_6269518418037593252[237] = 0.0;
   out_6269518418037593252[238] = 0.0;
   out_6269518418037593252[239] = 0.0;
   out_6269518418037593252[240] = 0.0;
   out_6269518418037593252[241] = 0.0;
   out_6269518418037593252[242] = 0.0;
   out_6269518418037593252[243] = 0.0;
   out_6269518418037593252[244] = 0.0;
   out_6269518418037593252[245] = 0.0;
   out_6269518418037593252[246] = 0.0;
   out_6269518418037593252[247] = 1.0;
   out_6269518418037593252[248] = 0.0;
   out_6269518418037593252[249] = 0.0;
   out_6269518418037593252[250] = 0.0;
   out_6269518418037593252[251] = 0.0;
   out_6269518418037593252[252] = 0.0;
   out_6269518418037593252[253] = 0.0;
   out_6269518418037593252[254] = 0.0;
   out_6269518418037593252[255] = 0.0;
   out_6269518418037593252[256] = 0.0;
   out_6269518418037593252[257] = 0.0;
   out_6269518418037593252[258] = 0.0;
   out_6269518418037593252[259] = 0.0;
   out_6269518418037593252[260] = 0.0;
   out_6269518418037593252[261] = 0.0;
   out_6269518418037593252[262] = 0.0;
   out_6269518418037593252[263] = 0.0;
   out_6269518418037593252[264] = 0.0;
   out_6269518418037593252[265] = 0.0;
   out_6269518418037593252[266] = 1.0;
   out_6269518418037593252[267] = 0.0;
   out_6269518418037593252[268] = 0.0;
   out_6269518418037593252[269] = 0.0;
   out_6269518418037593252[270] = 0.0;
   out_6269518418037593252[271] = 0.0;
   out_6269518418037593252[272] = 0.0;
   out_6269518418037593252[273] = 0.0;
   out_6269518418037593252[274] = 0.0;
   out_6269518418037593252[275] = 0.0;
   out_6269518418037593252[276] = 0.0;
   out_6269518418037593252[277] = 0.0;
   out_6269518418037593252[278] = 0.0;
   out_6269518418037593252[279] = 0.0;
   out_6269518418037593252[280] = 0.0;
   out_6269518418037593252[281] = 0.0;
   out_6269518418037593252[282] = 0.0;
   out_6269518418037593252[283] = 0.0;
   out_6269518418037593252[284] = 0.0;
   out_6269518418037593252[285] = 1.0;
   out_6269518418037593252[286] = 0.0;
   out_6269518418037593252[287] = 0.0;
   out_6269518418037593252[288] = 0.0;
   out_6269518418037593252[289] = 0.0;
   out_6269518418037593252[290] = 0.0;
   out_6269518418037593252[291] = 0.0;
   out_6269518418037593252[292] = 0.0;
   out_6269518418037593252[293] = 0.0;
   out_6269518418037593252[294] = 0.0;
   out_6269518418037593252[295] = 0.0;
   out_6269518418037593252[296] = 0.0;
   out_6269518418037593252[297] = 0.0;
   out_6269518418037593252[298] = 0.0;
   out_6269518418037593252[299] = 0.0;
   out_6269518418037593252[300] = 0.0;
   out_6269518418037593252[301] = 0.0;
   out_6269518418037593252[302] = 0.0;
   out_6269518418037593252[303] = 0.0;
   out_6269518418037593252[304] = 1.0;
   out_6269518418037593252[305] = 0.0;
   out_6269518418037593252[306] = 0.0;
   out_6269518418037593252[307] = 0.0;
   out_6269518418037593252[308] = 0.0;
   out_6269518418037593252[309] = 0.0;
   out_6269518418037593252[310] = 0.0;
   out_6269518418037593252[311] = 0.0;
   out_6269518418037593252[312] = 0.0;
   out_6269518418037593252[313] = 0.0;
   out_6269518418037593252[314] = 0.0;
   out_6269518418037593252[315] = 0.0;
   out_6269518418037593252[316] = 0.0;
   out_6269518418037593252[317] = 0.0;
   out_6269518418037593252[318] = 0.0;
   out_6269518418037593252[319] = 0.0;
   out_6269518418037593252[320] = 0.0;
   out_6269518418037593252[321] = 0.0;
   out_6269518418037593252[322] = 0.0;
   out_6269518418037593252[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_3363277910375281634) {
   out_3363277910375281634[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_3363277910375281634[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_3363277910375281634[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_3363277910375281634[3] = dt*state[12] + state[3];
   out_3363277910375281634[4] = dt*state[13] + state[4];
   out_3363277910375281634[5] = dt*state[14] + state[5];
   out_3363277910375281634[6] = state[6];
   out_3363277910375281634[7] = state[7];
   out_3363277910375281634[8] = state[8];
   out_3363277910375281634[9] = state[9];
   out_3363277910375281634[10] = state[10];
   out_3363277910375281634[11] = state[11];
   out_3363277910375281634[12] = state[12];
   out_3363277910375281634[13] = state[13];
   out_3363277910375281634[14] = state[14];
   out_3363277910375281634[15] = state[15];
   out_3363277910375281634[16] = state[16];
   out_3363277910375281634[17] = state[17];
}
void F_fun(double *state, double dt, double *out_3554420891246199959) {
   out_3554420891246199959[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_3554420891246199959[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_3554420891246199959[2] = 0;
   out_3554420891246199959[3] = 0;
   out_3554420891246199959[4] = 0;
   out_3554420891246199959[5] = 0;
   out_3554420891246199959[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_3554420891246199959[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_3554420891246199959[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_3554420891246199959[9] = 0;
   out_3554420891246199959[10] = 0;
   out_3554420891246199959[11] = 0;
   out_3554420891246199959[12] = 0;
   out_3554420891246199959[13] = 0;
   out_3554420891246199959[14] = 0;
   out_3554420891246199959[15] = 0;
   out_3554420891246199959[16] = 0;
   out_3554420891246199959[17] = 0;
   out_3554420891246199959[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_3554420891246199959[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_3554420891246199959[20] = 0;
   out_3554420891246199959[21] = 0;
   out_3554420891246199959[22] = 0;
   out_3554420891246199959[23] = 0;
   out_3554420891246199959[24] = 0;
   out_3554420891246199959[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_3554420891246199959[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_3554420891246199959[27] = 0;
   out_3554420891246199959[28] = 0;
   out_3554420891246199959[29] = 0;
   out_3554420891246199959[30] = 0;
   out_3554420891246199959[31] = 0;
   out_3554420891246199959[32] = 0;
   out_3554420891246199959[33] = 0;
   out_3554420891246199959[34] = 0;
   out_3554420891246199959[35] = 0;
   out_3554420891246199959[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_3554420891246199959[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_3554420891246199959[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_3554420891246199959[39] = 0;
   out_3554420891246199959[40] = 0;
   out_3554420891246199959[41] = 0;
   out_3554420891246199959[42] = 0;
   out_3554420891246199959[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_3554420891246199959[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_3554420891246199959[45] = 0;
   out_3554420891246199959[46] = 0;
   out_3554420891246199959[47] = 0;
   out_3554420891246199959[48] = 0;
   out_3554420891246199959[49] = 0;
   out_3554420891246199959[50] = 0;
   out_3554420891246199959[51] = 0;
   out_3554420891246199959[52] = 0;
   out_3554420891246199959[53] = 0;
   out_3554420891246199959[54] = 0;
   out_3554420891246199959[55] = 0;
   out_3554420891246199959[56] = 0;
   out_3554420891246199959[57] = 1;
   out_3554420891246199959[58] = 0;
   out_3554420891246199959[59] = 0;
   out_3554420891246199959[60] = 0;
   out_3554420891246199959[61] = 0;
   out_3554420891246199959[62] = 0;
   out_3554420891246199959[63] = 0;
   out_3554420891246199959[64] = 0;
   out_3554420891246199959[65] = 0;
   out_3554420891246199959[66] = dt;
   out_3554420891246199959[67] = 0;
   out_3554420891246199959[68] = 0;
   out_3554420891246199959[69] = 0;
   out_3554420891246199959[70] = 0;
   out_3554420891246199959[71] = 0;
   out_3554420891246199959[72] = 0;
   out_3554420891246199959[73] = 0;
   out_3554420891246199959[74] = 0;
   out_3554420891246199959[75] = 0;
   out_3554420891246199959[76] = 1;
   out_3554420891246199959[77] = 0;
   out_3554420891246199959[78] = 0;
   out_3554420891246199959[79] = 0;
   out_3554420891246199959[80] = 0;
   out_3554420891246199959[81] = 0;
   out_3554420891246199959[82] = 0;
   out_3554420891246199959[83] = 0;
   out_3554420891246199959[84] = 0;
   out_3554420891246199959[85] = dt;
   out_3554420891246199959[86] = 0;
   out_3554420891246199959[87] = 0;
   out_3554420891246199959[88] = 0;
   out_3554420891246199959[89] = 0;
   out_3554420891246199959[90] = 0;
   out_3554420891246199959[91] = 0;
   out_3554420891246199959[92] = 0;
   out_3554420891246199959[93] = 0;
   out_3554420891246199959[94] = 0;
   out_3554420891246199959[95] = 1;
   out_3554420891246199959[96] = 0;
   out_3554420891246199959[97] = 0;
   out_3554420891246199959[98] = 0;
   out_3554420891246199959[99] = 0;
   out_3554420891246199959[100] = 0;
   out_3554420891246199959[101] = 0;
   out_3554420891246199959[102] = 0;
   out_3554420891246199959[103] = 0;
   out_3554420891246199959[104] = dt;
   out_3554420891246199959[105] = 0;
   out_3554420891246199959[106] = 0;
   out_3554420891246199959[107] = 0;
   out_3554420891246199959[108] = 0;
   out_3554420891246199959[109] = 0;
   out_3554420891246199959[110] = 0;
   out_3554420891246199959[111] = 0;
   out_3554420891246199959[112] = 0;
   out_3554420891246199959[113] = 0;
   out_3554420891246199959[114] = 1;
   out_3554420891246199959[115] = 0;
   out_3554420891246199959[116] = 0;
   out_3554420891246199959[117] = 0;
   out_3554420891246199959[118] = 0;
   out_3554420891246199959[119] = 0;
   out_3554420891246199959[120] = 0;
   out_3554420891246199959[121] = 0;
   out_3554420891246199959[122] = 0;
   out_3554420891246199959[123] = 0;
   out_3554420891246199959[124] = 0;
   out_3554420891246199959[125] = 0;
   out_3554420891246199959[126] = 0;
   out_3554420891246199959[127] = 0;
   out_3554420891246199959[128] = 0;
   out_3554420891246199959[129] = 0;
   out_3554420891246199959[130] = 0;
   out_3554420891246199959[131] = 0;
   out_3554420891246199959[132] = 0;
   out_3554420891246199959[133] = 1;
   out_3554420891246199959[134] = 0;
   out_3554420891246199959[135] = 0;
   out_3554420891246199959[136] = 0;
   out_3554420891246199959[137] = 0;
   out_3554420891246199959[138] = 0;
   out_3554420891246199959[139] = 0;
   out_3554420891246199959[140] = 0;
   out_3554420891246199959[141] = 0;
   out_3554420891246199959[142] = 0;
   out_3554420891246199959[143] = 0;
   out_3554420891246199959[144] = 0;
   out_3554420891246199959[145] = 0;
   out_3554420891246199959[146] = 0;
   out_3554420891246199959[147] = 0;
   out_3554420891246199959[148] = 0;
   out_3554420891246199959[149] = 0;
   out_3554420891246199959[150] = 0;
   out_3554420891246199959[151] = 0;
   out_3554420891246199959[152] = 1;
   out_3554420891246199959[153] = 0;
   out_3554420891246199959[154] = 0;
   out_3554420891246199959[155] = 0;
   out_3554420891246199959[156] = 0;
   out_3554420891246199959[157] = 0;
   out_3554420891246199959[158] = 0;
   out_3554420891246199959[159] = 0;
   out_3554420891246199959[160] = 0;
   out_3554420891246199959[161] = 0;
   out_3554420891246199959[162] = 0;
   out_3554420891246199959[163] = 0;
   out_3554420891246199959[164] = 0;
   out_3554420891246199959[165] = 0;
   out_3554420891246199959[166] = 0;
   out_3554420891246199959[167] = 0;
   out_3554420891246199959[168] = 0;
   out_3554420891246199959[169] = 0;
   out_3554420891246199959[170] = 0;
   out_3554420891246199959[171] = 1;
   out_3554420891246199959[172] = 0;
   out_3554420891246199959[173] = 0;
   out_3554420891246199959[174] = 0;
   out_3554420891246199959[175] = 0;
   out_3554420891246199959[176] = 0;
   out_3554420891246199959[177] = 0;
   out_3554420891246199959[178] = 0;
   out_3554420891246199959[179] = 0;
   out_3554420891246199959[180] = 0;
   out_3554420891246199959[181] = 0;
   out_3554420891246199959[182] = 0;
   out_3554420891246199959[183] = 0;
   out_3554420891246199959[184] = 0;
   out_3554420891246199959[185] = 0;
   out_3554420891246199959[186] = 0;
   out_3554420891246199959[187] = 0;
   out_3554420891246199959[188] = 0;
   out_3554420891246199959[189] = 0;
   out_3554420891246199959[190] = 1;
   out_3554420891246199959[191] = 0;
   out_3554420891246199959[192] = 0;
   out_3554420891246199959[193] = 0;
   out_3554420891246199959[194] = 0;
   out_3554420891246199959[195] = 0;
   out_3554420891246199959[196] = 0;
   out_3554420891246199959[197] = 0;
   out_3554420891246199959[198] = 0;
   out_3554420891246199959[199] = 0;
   out_3554420891246199959[200] = 0;
   out_3554420891246199959[201] = 0;
   out_3554420891246199959[202] = 0;
   out_3554420891246199959[203] = 0;
   out_3554420891246199959[204] = 0;
   out_3554420891246199959[205] = 0;
   out_3554420891246199959[206] = 0;
   out_3554420891246199959[207] = 0;
   out_3554420891246199959[208] = 0;
   out_3554420891246199959[209] = 1;
   out_3554420891246199959[210] = 0;
   out_3554420891246199959[211] = 0;
   out_3554420891246199959[212] = 0;
   out_3554420891246199959[213] = 0;
   out_3554420891246199959[214] = 0;
   out_3554420891246199959[215] = 0;
   out_3554420891246199959[216] = 0;
   out_3554420891246199959[217] = 0;
   out_3554420891246199959[218] = 0;
   out_3554420891246199959[219] = 0;
   out_3554420891246199959[220] = 0;
   out_3554420891246199959[221] = 0;
   out_3554420891246199959[222] = 0;
   out_3554420891246199959[223] = 0;
   out_3554420891246199959[224] = 0;
   out_3554420891246199959[225] = 0;
   out_3554420891246199959[226] = 0;
   out_3554420891246199959[227] = 0;
   out_3554420891246199959[228] = 1;
   out_3554420891246199959[229] = 0;
   out_3554420891246199959[230] = 0;
   out_3554420891246199959[231] = 0;
   out_3554420891246199959[232] = 0;
   out_3554420891246199959[233] = 0;
   out_3554420891246199959[234] = 0;
   out_3554420891246199959[235] = 0;
   out_3554420891246199959[236] = 0;
   out_3554420891246199959[237] = 0;
   out_3554420891246199959[238] = 0;
   out_3554420891246199959[239] = 0;
   out_3554420891246199959[240] = 0;
   out_3554420891246199959[241] = 0;
   out_3554420891246199959[242] = 0;
   out_3554420891246199959[243] = 0;
   out_3554420891246199959[244] = 0;
   out_3554420891246199959[245] = 0;
   out_3554420891246199959[246] = 0;
   out_3554420891246199959[247] = 1;
   out_3554420891246199959[248] = 0;
   out_3554420891246199959[249] = 0;
   out_3554420891246199959[250] = 0;
   out_3554420891246199959[251] = 0;
   out_3554420891246199959[252] = 0;
   out_3554420891246199959[253] = 0;
   out_3554420891246199959[254] = 0;
   out_3554420891246199959[255] = 0;
   out_3554420891246199959[256] = 0;
   out_3554420891246199959[257] = 0;
   out_3554420891246199959[258] = 0;
   out_3554420891246199959[259] = 0;
   out_3554420891246199959[260] = 0;
   out_3554420891246199959[261] = 0;
   out_3554420891246199959[262] = 0;
   out_3554420891246199959[263] = 0;
   out_3554420891246199959[264] = 0;
   out_3554420891246199959[265] = 0;
   out_3554420891246199959[266] = 1;
   out_3554420891246199959[267] = 0;
   out_3554420891246199959[268] = 0;
   out_3554420891246199959[269] = 0;
   out_3554420891246199959[270] = 0;
   out_3554420891246199959[271] = 0;
   out_3554420891246199959[272] = 0;
   out_3554420891246199959[273] = 0;
   out_3554420891246199959[274] = 0;
   out_3554420891246199959[275] = 0;
   out_3554420891246199959[276] = 0;
   out_3554420891246199959[277] = 0;
   out_3554420891246199959[278] = 0;
   out_3554420891246199959[279] = 0;
   out_3554420891246199959[280] = 0;
   out_3554420891246199959[281] = 0;
   out_3554420891246199959[282] = 0;
   out_3554420891246199959[283] = 0;
   out_3554420891246199959[284] = 0;
   out_3554420891246199959[285] = 1;
   out_3554420891246199959[286] = 0;
   out_3554420891246199959[287] = 0;
   out_3554420891246199959[288] = 0;
   out_3554420891246199959[289] = 0;
   out_3554420891246199959[290] = 0;
   out_3554420891246199959[291] = 0;
   out_3554420891246199959[292] = 0;
   out_3554420891246199959[293] = 0;
   out_3554420891246199959[294] = 0;
   out_3554420891246199959[295] = 0;
   out_3554420891246199959[296] = 0;
   out_3554420891246199959[297] = 0;
   out_3554420891246199959[298] = 0;
   out_3554420891246199959[299] = 0;
   out_3554420891246199959[300] = 0;
   out_3554420891246199959[301] = 0;
   out_3554420891246199959[302] = 0;
   out_3554420891246199959[303] = 0;
   out_3554420891246199959[304] = 1;
   out_3554420891246199959[305] = 0;
   out_3554420891246199959[306] = 0;
   out_3554420891246199959[307] = 0;
   out_3554420891246199959[308] = 0;
   out_3554420891246199959[309] = 0;
   out_3554420891246199959[310] = 0;
   out_3554420891246199959[311] = 0;
   out_3554420891246199959[312] = 0;
   out_3554420891246199959[313] = 0;
   out_3554420891246199959[314] = 0;
   out_3554420891246199959[315] = 0;
   out_3554420891246199959[316] = 0;
   out_3554420891246199959[317] = 0;
   out_3554420891246199959[318] = 0;
   out_3554420891246199959[319] = 0;
   out_3554420891246199959[320] = 0;
   out_3554420891246199959[321] = 0;
   out_3554420891246199959[322] = 0;
   out_3554420891246199959[323] = 1;
}
void h_4(double *state, double *unused, double *out_7237947965692212456) {
   out_7237947965692212456[0] = state[6] + state[9];
   out_7237947965692212456[1] = state[7] + state[10];
   out_7237947965692212456[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_3439029423588969226) {
   out_3439029423588969226[0] = 0;
   out_3439029423588969226[1] = 0;
   out_3439029423588969226[2] = 0;
   out_3439029423588969226[3] = 0;
   out_3439029423588969226[4] = 0;
   out_3439029423588969226[5] = 0;
   out_3439029423588969226[6] = 1;
   out_3439029423588969226[7] = 0;
   out_3439029423588969226[8] = 0;
   out_3439029423588969226[9] = 1;
   out_3439029423588969226[10] = 0;
   out_3439029423588969226[11] = 0;
   out_3439029423588969226[12] = 0;
   out_3439029423588969226[13] = 0;
   out_3439029423588969226[14] = 0;
   out_3439029423588969226[15] = 0;
   out_3439029423588969226[16] = 0;
   out_3439029423588969226[17] = 0;
   out_3439029423588969226[18] = 0;
   out_3439029423588969226[19] = 0;
   out_3439029423588969226[20] = 0;
   out_3439029423588969226[21] = 0;
   out_3439029423588969226[22] = 0;
   out_3439029423588969226[23] = 0;
   out_3439029423588969226[24] = 0;
   out_3439029423588969226[25] = 1;
   out_3439029423588969226[26] = 0;
   out_3439029423588969226[27] = 0;
   out_3439029423588969226[28] = 1;
   out_3439029423588969226[29] = 0;
   out_3439029423588969226[30] = 0;
   out_3439029423588969226[31] = 0;
   out_3439029423588969226[32] = 0;
   out_3439029423588969226[33] = 0;
   out_3439029423588969226[34] = 0;
   out_3439029423588969226[35] = 0;
   out_3439029423588969226[36] = 0;
   out_3439029423588969226[37] = 0;
   out_3439029423588969226[38] = 0;
   out_3439029423588969226[39] = 0;
   out_3439029423588969226[40] = 0;
   out_3439029423588969226[41] = 0;
   out_3439029423588969226[42] = 0;
   out_3439029423588969226[43] = 0;
   out_3439029423588969226[44] = 1;
   out_3439029423588969226[45] = 0;
   out_3439029423588969226[46] = 0;
   out_3439029423588969226[47] = 1;
   out_3439029423588969226[48] = 0;
   out_3439029423588969226[49] = 0;
   out_3439029423588969226[50] = 0;
   out_3439029423588969226[51] = 0;
   out_3439029423588969226[52] = 0;
   out_3439029423588969226[53] = 0;
}
void h_10(double *state, double *unused, double *out_2371083028992154474) {
   out_2371083028992154474[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_2371083028992154474[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_2371083028992154474[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_38933642061620654) {
   out_38933642061620654[0] = 0;
   out_38933642061620654[1] = 9.8100000000000005*cos(state[1]);
   out_38933642061620654[2] = 0;
   out_38933642061620654[3] = 0;
   out_38933642061620654[4] = -state[8];
   out_38933642061620654[5] = state[7];
   out_38933642061620654[6] = 0;
   out_38933642061620654[7] = state[5];
   out_38933642061620654[8] = -state[4];
   out_38933642061620654[9] = 0;
   out_38933642061620654[10] = 0;
   out_38933642061620654[11] = 0;
   out_38933642061620654[12] = 1;
   out_38933642061620654[13] = 0;
   out_38933642061620654[14] = 0;
   out_38933642061620654[15] = 1;
   out_38933642061620654[16] = 0;
   out_38933642061620654[17] = 0;
   out_38933642061620654[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_38933642061620654[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_38933642061620654[20] = 0;
   out_38933642061620654[21] = state[8];
   out_38933642061620654[22] = 0;
   out_38933642061620654[23] = -state[6];
   out_38933642061620654[24] = -state[5];
   out_38933642061620654[25] = 0;
   out_38933642061620654[26] = state[3];
   out_38933642061620654[27] = 0;
   out_38933642061620654[28] = 0;
   out_38933642061620654[29] = 0;
   out_38933642061620654[30] = 0;
   out_38933642061620654[31] = 1;
   out_38933642061620654[32] = 0;
   out_38933642061620654[33] = 0;
   out_38933642061620654[34] = 1;
   out_38933642061620654[35] = 0;
   out_38933642061620654[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_38933642061620654[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_38933642061620654[38] = 0;
   out_38933642061620654[39] = -state[7];
   out_38933642061620654[40] = state[6];
   out_38933642061620654[41] = 0;
   out_38933642061620654[42] = state[4];
   out_38933642061620654[43] = -state[3];
   out_38933642061620654[44] = 0;
   out_38933642061620654[45] = 0;
   out_38933642061620654[46] = 0;
   out_38933642061620654[47] = 0;
   out_38933642061620654[48] = 0;
   out_38933642061620654[49] = 0;
   out_38933642061620654[50] = 1;
   out_38933642061620654[51] = 0;
   out_38933642061620654[52] = 0;
   out_38933642061620654[53] = 1;
}
void h_13(double *state, double *unused, double *out_7386501727190268544) {
   out_7386501727190268544[0] = state[3];
   out_7386501727190268544[1] = state[4];
   out_7386501727190268544[2] = state[5];
}
void H_13(double *state, double *unused, double *out_226755598256636425) {
   out_226755598256636425[0] = 0;
   out_226755598256636425[1] = 0;
   out_226755598256636425[2] = 0;
   out_226755598256636425[3] = 1;
   out_226755598256636425[4] = 0;
   out_226755598256636425[5] = 0;
   out_226755598256636425[6] = 0;
   out_226755598256636425[7] = 0;
   out_226755598256636425[8] = 0;
   out_226755598256636425[9] = 0;
   out_226755598256636425[10] = 0;
   out_226755598256636425[11] = 0;
   out_226755598256636425[12] = 0;
   out_226755598256636425[13] = 0;
   out_226755598256636425[14] = 0;
   out_226755598256636425[15] = 0;
   out_226755598256636425[16] = 0;
   out_226755598256636425[17] = 0;
   out_226755598256636425[18] = 0;
   out_226755598256636425[19] = 0;
   out_226755598256636425[20] = 0;
   out_226755598256636425[21] = 0;
   out_226755598256636425[22] = 1;
   out_226755598256636425[23] = 0;
   out_226755598256636425[24] = 0;
   out_226755598256636425[25] = 0;
   out_226755598256636425[26] = 0;
   out_226755598256636425[27] = 0;
   out_226755598256636425[28] = 0;
   out_226755598256636425[29] = 0;
   out_226755598256636425[30] = 0;
   out_226755598256636425[31] = 0;
   out_226755598256636425[32] = 0;
   out_226755598256636425[33] = 0;
   out_226755598256636425[34] = 0;
   out_226755598256636425[35] = 0;
   out_226755598256636425[36] = 0;
   out_226755598256636425[37] = 0;
   out_226755598256636425[38] = 0;
   out_226755598256636425[39] = 0;
   out_226755598256636425[40] = 0;
   out_226755598256636425[41] = 1;
   out_226755598256636425[42] = 0;
   out_226755598256636425[43] = 0;
   out_226755598256636425[44] = 0;
   out_226755598256636425[45] = 0;
   out_226755598256636425[46] = 0;
   out_226755598256636425[47] = 0;
   out_226755598256636425[48] = 0;
   out_226755598256636425[49] = 0;
   out_226755598256636425[50] = 0;
   out_226755598256636425[51] = 0;
   out_226755598256636425[52] = 0;
   out_226755598256636425[53] = 0;
}
void h_14(double *state, double *unused, double *out_2463349857534616744) {
   out_2463349857534616744[0] = state[6];
   out_2463349857534616744[1] = state[7];
   out_2463349857534616744[2] = state[8];
}
void H_14(double *state, double *unused, double *out_6521817855884341522) {
   out_6521817855884341522[0] = 0;
   out_6521817855884341522[1] = 0;
   out_6521817855884341522[2] = 0;
   out_6521817855884341522[3] = 0;
   out_6521817855884341522[4] = 0;
   out_6521817855884341522[5] = 0;
   out_6521817855884341522[6] = 1;
   out_6521817855884341522[7] = 0;
   out_6521817855884341522[8] = 0;
   out_6521817855884341522[9] = 0;
   out_6521817855884341522[10] = 0;
   out_6521817855884341522[11] = 0;
   out_6521817855884341522[12] = 0;
   out_6521817855884341522[13] = 0;
   out_6521817855884341522[14] = 0;
   out_6521817855884341522[15] = 0;
   out_6521817855884341522[16] = 0;
   out_6521817855884341522[17] = 0;
   out_6521817855884341522[18] = 0;
   out_6521817855884341522[19] = 0;
   out_6521817855884341522[20] = 0;
   out_6521817855884341522[21] = 0;
   out_6521817855884341522[22] = 0;
   out_6521817855884341522[23] = 0;
   out_6521817855884341522[24] = 0;
   out_6521817855884341522[25] = 1;
   out_6521817855884341522[26] = 0;
   out_6521817855884341522[27] = 0;
   out_6521817855884341522[28] = 0;
   out_6521817855884341522[29] = 0;
   out_6521817855884341522[30] = 0;
   out_6521817855884341522[31] = 0;
   out_6521817855884341522[32] = 0;
   out_6521817855884341522[33] = 0;
   out_6521817855884341522[34] = 0;
   out_6521817855884341522[35] = 0;
   out_6521817855884341522[36] = 0;
   out_6521817855884341522[37] = 0;
   out_6521817855884341522[38] = 0;
   out_6521817855884341522[39] = 0;
   out_6521817855884341522[40] = 0;
   out_6521817855884341522[41] = 0;
   out_6521817855884341522[42] = 0;
   out_6521817855884341522[43] = 0;
   out_6521817855884341522[44] = 1;
   out_6521817855884341522[45] = 0;
   out_6521817855884341522[46] = 0;
   out_6521817855884341522[47] = 0;
   out_6521817855884341522[48] = 0;
   out_6521817855884341522[49] = 0;
   out_6521817855884341522[50] = 0;
   out_6521817855884341522[51] = 0;
   out_6521817855884341522[52] = 0;
   out_6521817855884341522[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_7734263280416187077) {
  err_fun(nom_x, delta_x, out_7734263280416187077);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_6670314649637788989) {
  inv_err_fun(nom_x, true_x, out_6670314649637788989);
}
void pose_H_mod_fun(double *state, double *out_6269518418037593252) {
  H_mod_fun(state, out_6269518418037593252);
}
void pose_f_fun(double *state, double dt, double *out_3363277910375281634) {
  f_fun(state,  dt, out_3363277910375281634);
}
void pose_F_fun(double *state, double dt, double *out_3554420891246199959) {
  F_fun(state,  dt, out_3554420891246199959);
}
void pose_h_4(double *state, double *unused, double *out_7237947965692212456) {
  h_4(state, unused, out_7237947965692212456);
}
void pose_H_4(double *state, double *unused, double *out_3439029423588969226) {
  H_4(state, unused, out_3439029423588969226);
}
void pose_h_10(double *state, double *unused, double *out_2371083028992154474) {
  h_10(state, unused, out_2371083028992154474);
}
void pose_H_10(double *state, double *unused, double *out_38933642061620654) {
  H_10(state, unused, out_38933642061620654);
}
void pose_h_13(double *state, double *unused, double *out_7386501727190268544) {
  h_13(state, unused, out_7386501727190268544);
}
void pose_H_13(double *state, double *unused, double *out_226755598256636425) {
  H_13(state, unused, out_226755598256636425);
}
void pose_h_14(double *state, double *unused, double *out_2463349857534616744) {
  h_14(state, unused, out_2463349857534616744);
}
void pose_H_14(double *state, double *unused, double *out_6521817855884341522) {
  H_14(state, unused, out_6521817855884341522);
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
