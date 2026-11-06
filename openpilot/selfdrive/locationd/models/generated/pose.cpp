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
void err_fun(double *nom_x, double *delta_x, double *out_1736746612172014874) {
   out_1736746612172014874[0] = delta_x[0] + nom_x[0];
   out_1736746612172014874[1] = delta_x[1] + nom_x[1];
   out_1736746612172014874[2] = delta_x[2] + nom_x[2];
   out_1736746612172014874[3] = delta_x[3] + nom_x[3];
   out_1736746612172014874[4] = delta_x[4] + nom_x[4];
   out_1736746612172014874[5] = delta_x[5] + nom_x[5];
   out_1736746612172014874[6] = delta_x[6] + nom_x[6];
   out_1736746612172014874[7] = delta_x[7] + nom_x[7];
   out_1736746612172014874[8] = delta_x[8] + nom_x[8];
   out_1736746612172014874[9] = delta_x[9] + nom_x[9];
   out_1736746612172014874[10] = delta_x[10] + nom_x[10];
   out_1736746612172014874[11] = delta_x[11] + nom_x[11];
   out_1736746612172014874[12] = delta_x[12] + nom_x[12];
   out_1736746612172014874[13] = delta_x[13] + nom_x[13];
   out_1736746612172014874[14] = delta_x[14] + nom_x[14];
   out_1736746612172014874[15] = delta_x[15] + nom_x[15];
   out_1736746612172014874[16] = delta_x[16] + nom_x[16];
   out_1736746612172014874[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_2621334881021189822) {
   out_2621334881021189822[0] = -nom_x[0] + true_x[0];
   out_2621334881021189822[1] = -nom_x[1] + true_x[1];
   out_2621334881021189822[2] = -nom_x[2] + true_x[2];
   out_2621334881021189822[3] = -nom_x[3] + true_x[3];
   out_2621334881021189822[4] = -nom_x[4] + true_x[4];
   out_2621334881021189822[5] = -nom_x[5] + true_x[5];
   out_2621334881021189822[6] = -nom_x[6] + true_x[6];
   out_2621334881021189822[7] = -nom_x[7] + true_x[7];
   out_2621334881021189822[8] = -nom_x[8] + true_x[8];
   out_2621334881021189822[9] = -nom_x[9] + true_x[9];
   out_2621334881021189822[10] = -nom_x[10] + true_x[10];
   out_2621334881021189822[11] = -nom_x[11] + true_x[11];
   out_2621334881021189822[12] = -nom_x[12] + true_x[12];
   out_2621334881021189822[13] = -nom_x[13] + true_x[13];
   out_2621334881021189822[14] = -nom_x[14] + true_x[14];
   out_2621334881021189822[15] = -nom_x[15] + true_x[15];
   out_2621334881021189822[16] = -nom_x[16] + true_x[16];
   out_2621334881021189822[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_976235760463129040) {
   out_976235760463129040[0] = 1.0;
   out_976235760463129040[1] = 0.0;
   out_976235760463129040[2] = 0.0;
   out_976235760463129040[3] = 0.0;
   out_976235760463129040[4] = 0.0;
   out_976235760463129040[5] = 0.0;
   out_976235760463129040[6] = 0.0;
   out_976235760463129040[7] = 0.0;
   out_976235760463129040[8] = 0.0;
   out_976235760463129040[9] = 0.0;
   out_976235760463129040[10] = 0.0;
   out_976235760463129040[11] = 0.0;
   out_976235760463129040[12] = 0.0;
   out_976235760463129040[13] = 0.0;
   out_976235760463129040[14] = 0.0;
   out_976235760463129040[15] = 0.0;
   out_976235760463129040[16] = 0.0;
   out_976235760463129040[17] = 0.0;
   out_976235760463129040[18] = 0.0;
   out_976235760463129040[19] = 1.0;
   out_976235760463129040[20] = 0.0;
   out_976235760463129040[21] = 0.0;
   out_976235760463129040[22] = 0.0;
   out_976235760463129040[23] = 0.0;
   out_976235760463129040[24] = 0.0;
   out_976235760463129040[25] = 0.0;
   out_976235760463129040[26] = 0.0;
   out_976235760463129040[27] = 0.0;
   out_976235760463129040[28] = 0.0;
   out_976235760463129040[29] = 0.0;
   out_976235760463129040[30] = 0.0;
   out_976235760463129040[31] = 0.0;
   out_976235760463129040[32] = 0.0;
   out_976235760463129040[33] = 0.0;
   out_976235760463129040[34] = 0.0;
   out_976235760463129040[35] = 0.0;
   out_976235760463129040[36] = 0.0;
   out_976235760463129040[37] = 0.0;
   out_976235760463129040[38] = 1.0;
   out_976235760463129040[39] = 0.0;
   out_976235760463129040[40] = 0.0;
   out_976235760463129040[41] = 0.0;
   out_976235760463129040[42] = 0.0;
   out_976235760463129040[43] = 0.0;
   out_976235760463129040[44] = 0.0;
   out_976235760463129040[45] = 0.0;
   out_976235760463129040[46] = 0.0;
   out_976235760463129040[47] = 0.0;
   out_976235760463129040[48] = 0.0;
   out_976235760463129040[49] = 0.0;
   out_976235760463129040[50] = 0.0;
   out_976235760463129040[51] = 0.0;
   out_976235760463129040[52] = 0.0;
   out_976235760463129040[53] = 0.0;
   out_976235760463129040[54] = 0.0;
   out_976235760463129040[55] = 0.0;
   out_976235760463129040[56] = 0.0;
   out_976235760463129040[57] = 1.0;
   out_976235760463129040[58] = 0.0;
   out_976235760463129040[59] = 0.0;
   out_976235760463129040[60] = 0.0;
   out_976235760463129040[61] = 0.0;
   out_976235760463129040[62] = 0.0;
   out_976235760463129040[63] = 0.0;
   out_976235760463129040[64] = 0.0;
   out_976235760463129040[65] = 0.0;
   out_976235760463129040[66] = 0.0;
   out_976235760463129040[67] = 0.0;
   out_976235760463129040[68] = 0.0;
   out_976235760463129040[69] = 0.0;
   out_976235760463129040[70] = 0.0;
   out_976235760463129040[71] = 0.0;
   out_976235760463129040[72] = 0.0;
   out_976235760463129040[73] = 0.0;
   out_976235760463129040[74] = 0.0;
   out_976235760463129040[75] = 0.0;
   out_976235760463129040[76] = 1.0;
   out_976235760463129040[77] = 0.0;
   out_976235760463129040[78] = 0.0;
   out_976235760463129040[79] = 0.0;
   out_976235760463129040[80] = 0.0;
   out_976235760463129040[81] = 0.0;
   out_976235760463129040[82] = 0.0;
   out_976235760463129040[83] = 0.0;
   out_976235760463129040[84] = 0.0;
   out_976235760463129040[85] = 0.0;
   out_976235760463129040[86] = 0.0;
   out_976235760463129040[87] = 0.0;
   out_976235760463129040[88] = 0.0;
   out_976235760463129040[89] = 0.0;
   out_976235760463129040[90] = 0.0;
   out_976235760463129040[91] = 0.0;
   out_976235760463129040[92] = 0.0;
   out_976235760463129040[93] = 0.0;
   out_976235760463129040[94] = 0.0;
   out_976235760463129040[95] = 1.0;
   out_976235760463129040[96] = 0.0;
   out_976235760463129040[97] = 0.0;
   out_976235760463129040[98] = 0.0;
   out_976235760463129040[99] = 0.0;
   out_976235760463129040[100] = 0.0;
   out_976235760463129040[101] = 0.0;
   out_976235760463129040[102] = 0.0;
   out_976235760463129040[103] = 0.0;
   out_976235760463129040[104] = 0.0;
   out_976235760463129040[105] = 0.0;
   out_976235760463129040[106] = 0.0;
   out_976235760463129040[107] = 0.0;
   out_976235760463129040[108] = 0.0;
   out_976235760463129040[109] = 0.0;
   out_976235760463129040[110] = 0.0;
   out_976235760463129040[111] = 0.0;
   out_976235760463129040[112] = 0.0;
   out_976235760463129040[113] = 0.0;
   out_976235760463129040[114] = 1.0;
   out_976235760463129040[115] = 0.0;
   out_976235760463129040[116] = 0.0;
   out_976235760463129040[117] = 0.0;
   out_976235760463129040[118] = 0.0;
   out_976235760463129040[119] = 0.0;
   out_976235760463129040[120] = 0.0;
   out_976235760463129040[121] = 0.0;
   out_976235760463129040[122] = 0.0;
   out_976235760463129040[123] = 0.0;
   out_976235760463129040[124] = 0.0;
   out_976235760463129040[125] = 0.0;
   out_976235760463129040[126] = 0.0;
   out_976235760463129040[127] = 0.0;
   out_976235760463129040[128] = 0.0;
   out_976235760463129040[129] = 0.0;
   out_976235760463129040[130] = 0.0;
   out_976235760463129040[131] = 0.0;
   out_976235760463129040[132] = 0.0;
   out_976235760463129040[133] = 1.0;
   out_976235760463129040[134] = 0.0;
   out_976235760463129040[135] = 0.0;
   out_976235760463129040[136] = 0.0;
   out_976235760463129040[137] = 0.0;
   out_976235760463129040[138] = 0.0;
   out_976235760463129040[139] = 0.0;
   out_976235760463129040[140] = 0.0;
   out_976235760463129040[141] = 0.0;
   out_976235760463129040[142] = 0.0;
   out_976235760463129040[143] = 0.0;
   out_976235760463129040[144] = 0.0;
   out_976235760463129040[145] = 0.0;
   out_976235760463129040[146] = 0.0;
   out_976235760463129040[147] = 0.0;
   out_976235760463129040[148] = 0.0;
   out_976235760463129040[149] = 0.0;
   out_976235760463129040[150] = 0.0;
   out_976235760463129040[151] = 0.0;
   out_976235760463129040[152] = 1.0;
   out_976235760463129040[153] = 0.0;
   out_976235760463129040[154] = 0.0;
   out_976235760463129040[155] = 0.0;
   out_976235760463129040[156] = 0.0;
   out_976235760463129040[157] = 0.0;
   out_976235760463129040[158] = 0.0;
   out_976235760463129040[159] = 0.0;
   out_976235760463129040[160] = 0.0;
   out_976235760463129040[161] = 0.0;
   out_976235760463129040[162] = 0.0;
   out_976235760463129040[163] = 0.0;
   out_976235760463129040[164] = 0.0;
   out_976235760463129040[165] = 0.0;
   out_976235760463129040[166] = 0.0;
   out_976235760463129040[167] = 0.0;
   out_976235760463129040[168] = 0.0;
   out_976235760463129040[169] = 0.0;
   out_976235760463129040[170] = 0.0;
   out_976235760463129040[171] = 1.0;
   out_976235760463129040[172] = 0.0;
   out_976235760463129040[173] = 0.0;
   out_976235760463129040[174] = 0.0;
   out_976235760463129040[175] = 0.0;
   out_976235760463129040[176] = 0.0;
   out_976235760463129040[177] = 0.0;
   out_976235760463129040[178] = 0.0;
   out_976235760463129040[179] = 0.0;
   out_976235760463129040[180] = 0.0;
   out_976235760463129040[181] = 0.0;
   out_976235760463129040[182] = 0.0;
   out_976235760463129040[183] = 0.0;
   out_976235760463129040[184] = 0.0;
   out_976235760463129040[185] = 0.0;
   out_976235760463129040[186] = 0.0;
   out_976235760463129040[187] = 0.0;
   out_976235760463129040[188] = 0.0;
   out_976235760463129040[189] = 0.0;
   out_976235760463129040[190] = 1.0;
   out_976235760463129040[191] = 0.0;
   out_976235760463129040[192] = 0.0;
   out_976235760463129040[193] = 0.0;
   out_976235760463129040[194] = 0.0;
   out_976235760463129040[195] = 0.0;
   out_976235760463129040[196] = 0.0;
   out_976235760463129040[197] = 0.0;
   out_976235760463129040[198] = 0.0;
   out_976235760463129040[199] = 0.0;
   out_976235760463129040[200] = 0.0;
   out_976235760463129040[201] = 0.0;
   out_976235760463129040[202] = 0.0;
   out_976235760463129040[203] = 0.0;
   out_976235760463129040[204] = 0.0;
   out_976235760463129040[205] = 0.0;
   out_976235760463129040[206] = 0.0;
   out_976235760463129040[207] = 0.0;
   out_976235760463129040[208] = 0.0;
   out_976235760463129040[209] = 1.0;
   out_976235760463129040[210] = 0.0;
   out_976235760463129040[211] = 0.0;
   out_976235760463129040[212] = 0.0;
   out_976235760463129040[213] = 0.0;
   out_976235760463129040[214] = 0.0;
   out_976235760463129040[215] = 0.0;
   out_976235760463129040[216] = 0.0;
   out_976235760463129040[217] = 0.0;
   out_976235760463129040[218] = 0.0;
   out_976235760463129040[219] = 0.0;
   out_976235760463129040[220] = 0.0;
   out_976235760463129040[221] = 0.0;
   out_976235760463129040[222] = 0.0;
   out_976235760463129040[223] = 0.0;
   out_976235760463129040[224] = 0.0;
   out_976235760463129040[225] = 0.0;
   out_976235760463129040[226] = 0.0;
   out_976235760463129040[227] = 0.0;
   out_976235760463129040[228] = 1.0;
   out_976235760463129040[229] = 0.0;
   out_976235760463129040[230] = 0.0;
   out_976235760463129040[231] = 0.0;
   out_976235760463129040[232] = 0.0;
   out_976235760463129040[233] = 0.0;
   out_976235760463129040[234] = 0.0;
   out_976235760463129040[235] = 0.0;
   out_976235760463129040[236] = 0.0;
   out_976235760463129040[237] = 0.0;
   out_976235760463129040[238] = 0.0;
   out_976235760463129040[239] = 0.0;
   out_976235760463129040[240] = 0.0;
   out_976235760463129040[241] = 0.0;
   out_976235760463129040[242] = 0.0;
   out_976235760463129040[243] = 0.0;
   out_976235760463129040[244] = 0.0;
   out_976235760463129040[245] = 0.0;
   out_976235760463129040[246] = 0.0;
   out_976235760463129040[247] = 1.0;
   out_976235760463129040[248] = 0.0;
   out_976235760463129040[249] = 0.0;
   out_976235760463129040[250] = 0.0;
   out_976235760463129040[251] = 0.0;
   out_976235760463129040[252] = 0.0;
   out_976235760463129040[253] = 0.0;
   out_976235760463129040[254] = 0.0;
   out_976235760463129040[255] = 0.0;
   out_976235760463129040[256] = 0.0;
   out_976235760463129040[257] = 0.0;
   out_976235760463129040[258] = 0.0;
   out_976235760463129040[259] = 0.0;
   out_976235760463129040[260] = 0.0;
   out_976235760463129040[261] = 0.0;
   out_976235760463129040[262] = 0.0;
   out_976235760463129040[263] = 0.0;
   out_976235760463129040[264] = 0.0;
   out_976235760463129040[265] = 0.0;
   out_976235760463129040[266] = 1.0;
   out_976235760463129040[267] = 0.0;
   out_976235760463129040[268] = 0.0;
   out_976235760463129040[269] = 0.0;
   out_976235760463129040[270] = 0.0;
   out_976235760463129040[271] = 0.0;
   out_976235760463129040[272] = 0.0;
   out_976235760463129040[273] = 0.0;
   out_976235760463129040[274] = 0.0;
   out_976235760463129040[275] = 0.0;
   out_976235760463129040[276] = 0.0;
   out_976235760463129040[277] = 0.0;
   out_976235760463129040[278] = 0.0;
   out_976235760463129040[279] = 0.0;
   out_976235760463129040[280] = 0.0;
   out_976235760463129040[281] = 0.0;
   out_976235760463129040[282] = 0.0;
   out_976235760463129040[283] = 0.0;
   out_976235760463129040[284] = 0.0;
   out_976235760463129040[285] = 1.0;
   out_976235760463129040[286] = 0.0;
   out_976235760463129040[287] = 0.0;
   out_976235760463129040[288] = 0.0;
   out_976235760463129040[289] = 0.0;
   out_976235760463129040[290] = 0.0;
   out_976235760463129040[291] = 0.0;
   out_976235760463129040[292] = 0.0;
   out_976235760463129040[293] = 0.0;
   out_976235760463129040[294] = 0.0;
   out_976235760463129040[295] = 0.0;
   out_976235760463129040[296] = 0.0;
   out_976235760463129040[297] = 0.0;
   out_976235760463129040[298] = 0.0;
   out_976235760463129040[299] = 0.0;
   out_976235760463129040[300] = 0.0;
   out_976235760463129040[301] = 0.0;
   out_976235760463129040[302] = 0.0;
   out_976235760463129040[303] = 0.0;
   out_976235760463129040[304] = 1.0;
   out_976235760463129040[305] = 0.0;
   out_976235760463129040[306] = 0.0;
   out_976235760463129040[307] = 0.0;
   out_976235760463129040[308] = 0.0;
   out_976235760463129040[309] = 0.0;
   out_976235760463129040[310] = 0.0;
   out_976235760463129040[311] = 0.0;
   out_976235760463129040[312] = 0.0;
   out_976235760463129040[313] = 0.0;
   out_976235760463129040[314] = 0.0;
   out_976235760463129040[315] = 0.0;
   out_976235760463129040[316] = 0.0;
   out_976235760463129040[317] = 0.0;
   out_976235760463129040[318] = 0.0;
   out_976235760463129040[319] = 0.0;
   out_976235760463129040[320] = 0.0;
   out_976235760463129040[321] = 0.0;
   out_976235760463129040[322] = 0.0;
   out_976235760463129040[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_8570715647887041589) {
   out_8570715647887041589[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_8570715647887041589[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_8570715647887041589[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_8570715647887041589[3] = dt*state[12] + state[3];
   out_8570715647887041589[4] = dt*state[13] + state[4];
   out_8570715647887041589[5] = dt*state[14] + state[5];
   out_8570715647887041589[6] = state[6];
   out_8570715647887041589[7] = state[7];
   out_8570715647887041589[8] = state[8];
   out_8570715647887041589[9] = state[9];
   out_8570715647887041589[10] = state[10];
   out_8570715647887041589[11] = state[11];
   out_8570715647887041589[12] = state[12];
   out_8570715647887041589[13] = state[13];
   out_8570715647887041589[14] = state[14];
   out_8570715647887041589[15] = state[15];
   out_8570715647887041589[16] = state[16];
   out_8570715647887041589[17] = state[17];
}
void F_fun(double *state, double dt, double *out_9195171490393905022) {
   out_9195171490393905022[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_9195171490393905022[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_9195171490393905022[2] = 0;
   out_9195171490393905022[3] = 0;
   out_9195171490393905022[4] = 0;
   out_9195171490393905022[5] = 0;
   out_9195171490393905022[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_9195171490393905022[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_9195171490393905022[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_9195171490393905022[9] = 0;
   out_9195171490393905022[10] = 0;
   out_9195171490393905022[11] = 0;
   out_9195171490393905022[12] = 0;
   out_9195171490393905022[13] = 0;
   out_9195171490393905022[14] = 0;
   out_9195171490393905022[15] = 0;
   out_9195171490393905022[16] = 0;
   out_9195171490393905022[17] = 0;
   out_9195171490393905022[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_9195171490393905022[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_9195171490393905022[20] = 0;
   out_9195171490393905022[21] = 0;
   out_9195171490393905022[22] = 0;
   out_9195171490393905022[23] = 0;
   out_9195171490393905022[24] = 0;
   out_9195171490393905022[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_9195171490393905022[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_9195171490393905022[27] = 0;
   out_9195171490393905022[28] = 0;
   out_9195171490393905022[29] = 0;
   out_9195171490393905022[30] = 0;
   out_9195171490393905022[31] = 0;
   out_9195171490393905022[32] = 0;
   out_9195171490393905022[33] = 0;
   out_9195171490393905022[34] = 0;
   out_9195171490393905022[35] = 0;
   out_9195171490393905022[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_9195171490393905022[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_9195171490393905022[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_9195171490393905022[39] = 0;
   out_9195171490393905022[40] = 0;
   out_9195171490393905022[41] = 0;
   out_9195171490393905022[42] = 0;
   out_9195171490393905022[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_9195171490393905022[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_9195171490393905022[45] = 0;
   out_9195171490393905022[46] = 0;
   out_9195171490393905022[47] = 0;
   out_9195171490393905022[48] = 0;
   out_9195171490393905022[49] = 0;
   out_9195171490393905022[50] = 0;
   out_9195171490393905022[51] = 0;
   out_9195171490393905022[52] = 0;
   out_9195171490393905022[53] = 0;
   out_9195171490393905022[54] = 0;
   out_9195171490393905022[55] = 0;
   out_9195171490393905022[56] = 0;
   out_9195171490393905022[57] = 1;
   out_9195171490393905022[58] = 0;
   out_9195171490393905022[59] = 0;
   out_9195171490393905022[60] = 0;
   out_9195171490393905022[61] = 0;
   out_9195171490393905022[62] = 0;
   out_9195171490393905022[63] = 0;
   out_9195171490393905022[64] = 0;
   out_9195171490393905022[65] = 0;
   out_9195171490393905022[66] = dt;
   out_9195171490393905022[67] = 0;
   out_9195171490393905022[68] = 0;
   out_9195171490393905022[69] = 0;
   out_9195171490393905022[70] = 0;
   out_9195171490393905022[71] = 0;
   out_9195171490393905022[72] = 0;
   out_9195171490393905022[73] = 0;
   out_9195171490393905022[74] = 0;
   out_9195171490393905022[75] = 0;
   out_9195171490393905022[76] = 1;
   out_9195171490393905022[77] = 0;
   out_9195171490393905022[78] = 0;
   out_9195171490393905022[79] = 0;
   out_9195171490393905022[80] = 0;
   out_9195171490393905022[81] = 0;
   out_9195171490393905022[82] = 0;
   out_9195171490393905022[83] = 0;
   out_9195171490393905022[84] = 0;
   out_9195171490393905022[85] = dt;
   out_9195171490393905022[86] = 0;
   out_9195171490393905022[87] = 0;
   out_9195171490393905022[88] = 0;
   out_9195171490393905022[89] = 0;
   out_9195171490393905022[90] = 0;
   out_9195171490393905022[91] = 0;
   out_9195171490393905022[92] = 0;
   out_9195171490393905022[93] = 0;
   out_9195171490393905022[94] = 0;
   out_9195171490393905022[95] = 1;
   out_9195171490393905022[96] = 0;
   out_9195171490393905022[97] = 0;
   out_9195171490393905022[98] = 0;
   out_9195171490393905022[99] = 0;
   out_9195171490393905022[100] = 0;
   out_9195171490393905022[101] = 0;
   out_9195171490393905022[102] = 0;
   out_9195171490393905022[103] = 0;
   out_9195171490393905022[104] = dt;
   out_9195171490393905022[105] = 0;
   out_9195171490393905022[106] = 0;
   out_9195171490393905022[107] = 0;
   out_9195171490393905022[108] = 0;
   out_9195171490393905022[109] = 0;
   out_9195171490393905022[110] = 0;
   out_9195171490393905022[111] = 0;
   out_9195171490393905022[112] = 0;
   out_9195171490393905022[113] = 0;
   out_9195171490393905022[114] = 1;
   out_9195171490393905022[115] = 0;
   out_9195171490393905022[116] = 0;
   out_9195171490393905022[117] = 0;
   out_9195171490393905022[118] = 0;
   out_9195171490393905022[119] = 0;
   out_9195171490393905022[120] = 0;
   out_9195171490393905022[121] = 0;
   out_9195171490393905022[122] = 0;
   out_9195171490393905022[123] = 0;
   out_9195171490393905022[124] = 0;
   out_9195171490393905022[125] = 0;
   out_9195171490393905022[126] = 0;
   out_9195171490393905022[127] = 0;
   out_9195171490393905022[128] = 0;
   out_9195171490393905022[129] = 0;
   out_9195171490393905022[130] = 0;
   out_9195171490393905022[131] = 0;
   out_9195171490393905022[132] = 0;
   out_9195171490393905022[133] = 1;
   out_9195171490393905022[134] = 0;
   out_9195171490393905022[135] = 0;
   out_9195171490393905022[136] = 0;
   out_9195171490393905022[137] = 0;
   out_9195171490393905022[138] = 0;
   out_9195171490393905022[139] = 0;
   out_9195171490393905022[140] = 0;
   out_9195171490393905022[141] = 0;
   out_9195171490393905022[142] = 0;
   out_9195171490393905022[143] = 0;
   out_9195171490393905022[144] = 0;
   out_9195171490393905022[145] = 0;
   out_9195171490393905022[146] = 0;
   out_9195171490393905022[147] = 0;
   out_9195171490393905022[148] = 0;
   out_9195171490393905022[149] = 0;
   out_9195171490393905022[150] = 0;
   out_9195171490393905022[151] = 0;
   out_9195171490393905022[152] = 1;
   out_9195171490393905022[153] = 0;
   out_9195171490393905022[154] = 0;
   out_9195171490393905022[155] = 0;
   out_9195171490393905022[156] = 0;
   out_9195171490393905022[157] = 0;
   out_9195171490393905022[158] = 0;
   out_9195171490393905022[159] = 0;
   out_9195171490393905022[160] = 0;
   out_9195171490393905022[161] = 0;
   out_9195171490393905022[162] = 0;
   out_9195171490393905022[163] = 0;
   out_9195171490393905022[164] = 0;
   out_9195171490393905022[165] = 0;
   out_9195171490393905022[166] = 0;
   out_9195171490393905022[167] = 0;
   out_9195171490393905022[168] = 0;
   out_9195171490393905022[169] = 0;
   out_9195171490393905022[170] = 0;
   out_9195171490393905022[171] = 1;
   out_9195171490393905022[172] = 0;
   out_9195171490393905022[173] = 0;
   out_9195171490393905022[174] = 0;
   out_9195171490393905022[175] = 0;
   out_9195171490393905022[176] = 0;
   out_9195171490393905022[177] = 0;
   out_9195171490393905022[178] = 0;
   out_9195171490393905022[179] = 0;
   out_9195171490393905022[180] = 0;
   out_9195171490393905022[181] = 0;
   out_9195171490393905022[182] = 0;
   out_9195171490393905022[183] = 0;
   out_9195171490393905022[184] = 0;
   out_9195171490393905022[185] = 0;
   out_9195171490393905022[186] = 0;
   out_9195171490393905022[187] = 0;
   out_9195171490393905022[188] = 0;
   out_9195171490393905022[189] = 0;
   out_9195171490393905022[190] = 1;
   out_9195171490393905022[191] = 0;
   out_9195171490393905022[192] = 0;
   out_9195171490393905022[193] = 0;
   out_9195171490393905022[194] = 0;
   out_9195171490393905022[195] = 0;
   out_9195171490393905022[196] = 0;
   out_9195171490393905022[197] = 0;
   out_9195171490393905022[198] = 0;
   out_9195171490393905022[199] = 0;
   out_9195171490393905022[200] = 0;
   out_9195171490393905022[201] = 0;
   out_9195171490393905022[202] = 0;
   out_9195171490393905022[203] = 0;
   out_9195171490393905022[204] = 0;
   out_9195171490393905022[205] = 0;
   out_9195171490393905022[206] = 0;
   out_9195171490393905022[207] = 0;
   out_9195171490393905022[208] = 0;
   out_9195171490393905022[209] = 1;
   out_9195171490393905022[210] = 0;
   out_9195171490393905022[211] = 0;
   out_9195171490393905022[212] = 0;
   out_9195171490393905022[213] = 0;
   out_9195171490393905022[214] = 0;
   out_9195171490393905022[215] = 0;
   out_9195171490393905022[216] = 0;
   out_9195171490393905022[217] = 0;
   out_9195171490393905022[218] = 0;
   out_9195171490393905022[219] = 0;
   out_9195171490393905022[220] = 0;
   out_9195171490393905022[221] = 0;
   out_9195171490393905022[222] = 0;
   out_9195171490393905022[223] = 0;
   out_9195171490393905022[224] = 0;
   out_9195171490393905022[225] = 0;
   out_9195171490393905022[226] = 0;
   out_9195171490393905022[227] = 0;
   out_9195171490393905022[228] = 1;
   out_9195171490393905022[229] = 0;
   out_9195171490393905022[230] = 0;
   out_9195171490393905022[231] = 0;
   out_9195171490393905022[232] = 0;
   out_9195171490393905022[233] = 0;
   out_9195171490393905022[234] = 0;
   out_9195171490393905022[235] = 0;
   out_9195171490393905022[236] = 0;
   out_9195171490393905022[237] = 0;
   out_9195171490393905022[238] = 0;
   out_9195171490393905022[239] = 0;
   out_9195171490393905022[240] = 0;
   out_9195171490393905022[241] = 0;
   out_9195171490393905022[242] = 0;
   out_9195171490393905022[243] = 0;
   out_9195171490393905022[244] = 0;
   out_9195171490393905022[245] = 0;
   out_9195171490393905022[246] = 0;
   out_9195171490393905022[247] = 1;
   out_9195171490393905022[248] = 0;
   out_9195171490393905022[249] = 0;
   out_9195171490393905022[250] = 0;
   out_9195171490393905022[251] = 0;
   out_9195171490393905022[252] = 0;
   out_9195171490393905022[253] = 0;
   out_9195171490393905022[254] = 0;
   out_9195171490393905022[255] = 0;
   out_9195171490393905022[256] = 0;
   out_9195171490393905022[257] = 0;
   out_9195171490393905022[258] = 0;
   out_9195171490393905022[259] = 0;
   out_9195171490393905022[260] = 0;
   out_9195171490393905022[261] = 0;
   out_9195171490393905022[262] = 0;
   out_9195171490393905022[263] = 0;
   out_9195171490393905022[264] = 0;
   out_9195171490393905022[265] = 0;
   out_9195171490393905022[266] = 1;
   out_9195171490393905022[267] = 0;
   out_9195171490393905022[268] = 0;
   out_9195171490393905022[269] = 0;
   out_9195171490393905022[270] = 0;
   out_9195171490393905022[271] = 0;
   out_9195171490393905022[272] = 0;
   out_9195171490393905022[273] = 0;
   out_9195171490393905022[274] = 0;
   out_9195171490393905022[275] = 0;
   out_9195171490393905022[276] = 0;
   out_9195171490393905022[277] = 0;
   out_9195171490393905022[278] = 0;
   out_9195171490393905022[279] = 0;
   out_9195171490393905022[280] = 0;
   out_9195171490393905022[281] = 0;
   out_9195171490393905022[282] = 0;
   out_9195171490393905022[283] = 0;
   out_9195171490393905022[284] = 0;
   out_9195171490393905022[285] = 1;
   out_9195171490393905022[286] = 0;
   out_9195171490393905022[287] = 0;
   out_9195171490393905022[288] = 0;
   out_9195171490393905022[289] = 0;
   out_9195171490393905022[290] = 0;
   out_9195171490393905022[291] = 0;
   out_9195171490393905022[292] = 0;
   out_9195171490393905022[293] = 0;
   out_9195171490393905022[294] = 0;
   out_9195171490393905022[295] = 0;
   out_9195171490393905022[296] = 0;
   out_9195171490393905022[297] = 0;
   out_9195171490393905022[298] = 0;
   out_9195171490393905022[299] = 0;
   out_9195171490393905022[300] = 0;
   out_9195171490393905022[301] = 0;
   out_9195171490393905022[302] = 0;
   out_9195171490393905022[303] = 0;
   out_9195171490393905022[304] = 1;
   out_9195171490393905022[305] = 0;
   out_9195171490393905022[306] = 0;
   out_9195171490393905022[307] = 0;
   out_9195171490393905022[308] = 0;
   out_9195171490393905022[309] = 0;
   out_9195171490393905022[310] = 0;
   out_9195171490393905022[311] = 0;
   out_9195171490393905022[312] = 0;
   out_9195171490393905022[313] = 0;
   out_9195171490393905022[314] = 0;
   out_9195171490393905022[315] = 0;
   out_9195171490393905022[316] = 0;
   out_9195171490393905022[317] = 0;
   out_9195171490393905022[318] = 0;
   out_9195171490393905022[319] = 0;
   out_9195171490393905022[320] = 0;
   out_9195171490393905022[321] = 0;
   out_9195171490393905022[322] = 0;
   out_9195171490393905022[323] = 1;
}
void h_4(double *state, double *unused, double *out_1784252823533360007) {
   out_1784252823533360007[0] = state[6] + state[9];
   out_1784252823533360007[1] = state[7] + state[10];
   out_1784252823533360007[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_4748042970307036612) {
   out_4748042970307036612[0] = 0;
   out_4748042970307036612[1] = 0;
   out_4748042970307036612[2] = 0;
   out_4748042970307036612[3] = 0;
   out_4748042970307036612[4] = 0;
   out_4748042970307036612[5] = 0;
   out_4748042970307036612[6] = 1;
   out_4748042970307036612[7] = 0;
   out_4748042970307036612[8] = 0;
   out_4748042970307036612[9] = 1;
   out_4748042970307036612[10] = 0;
   out_4748042970307036612[11] = 0;
   out_4748042970307036612[12] = 0;
   out_4748042970307036612[13] = 0;
   out_4748042970307036612[14] = 0;
   out_4748042970307036612[15] = 0;
   out_4748042970307036612[16] = 0;
   out_4748042970307036612[17] = 0;
   out_4748042970307036612[18] = 0;
   out_4748042970307036612[19] = 0;
   out_4748042970307036612[20] = 0;
   out_4748042970307036612[21] = 0;
   out_4748042970307036612[22] = 0;
   out_4748042970307036612[23] = 0;
   out_4748042970307036612[24] = 0;
   out_4748042970307036612[25] = 1;
   out_4748042970307036612[26] = 0;
   out_4748042970307036612[27] = 0;
   out_4748042970307036612[28] = 1;
   out_4748042970307036612[29] = 0;
   out_4748042970307036612[30] = 0;
   out_4748042970307036612[31] = 0;
   out_4748042970307036612[32] = 0;
   out_4748042970307036612[33] = 0;
   out_4748042970307036612[34] = 0;
   out_4748042970307036612[35] = 0;
   out_4748042970307036612[36] = 0;
   out_4748042970307036612[37] = 0;
   out_4748042970307036612[38] = 0;
   out_4748042970307036612[39] = 0;
   out_4748042970307036612[40] = 0;
   out_4748042970307036612[41] = 0;
   out_4748042970307036612[42] = 0;
   out_4748042970307036612[43] = 0;
   out_4748042970307036612[44] = 1;
   out_4748042970307036612[45] = 0;
   out_4748042970307036612[46] = 0;
   out_4748042970307036612[47] = 1;
   out_4748042970307036612[48] = 0;
   out_4748042970307036612[49] = 0;
   out_4748042970307036612[50] = 0;
   out_4748042970307036612[51] = 0;
   out_4748042970307036612[52] = 0;
   out_4748042970307036612[53] = 0;
}
void h_10(double *state, double *unused, double *out_2498286068008923995) {
   out_2498286068008923995[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_2498286068008923995[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_2498286068008923995[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_2995414732378888264) {
   out_2995414732378888264[0] = 0;
   out_2995414732378888264[1] = 9.8100000000000005*cos(state[1]);
   out_2995414732378888264[2] = 0;
   out_2995414732378888264[3] = 0;
   out_2995414732378888264[4] = -state[8];
   out_2995414732378888264[5] = state[7];
   out_2995414732378888264[6] = 0;
   out_2995414732378888264[7] = state[5];
   out_2995414732378888264[8] = -state[4];
   out_2995414732378888264[9] = 0;
   out_2995414732378888264[10] = 0;
   out_2995414732378888264[11] = 0;
   out_2995414732378888264[12] = 1;
   out_2995414732378888264[13] = 0;
   out_2995414732378888264[14] = 0;
   out_2995414732378888264[15] = 1;
   out_2995414732378888264[16] = 0;
   out_2995414732378888264[17] = 0;
   out_2995414732378888264[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_2995414732378888264[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_2995414732378888264[20] = 0;
   out_2995414732378888264[21] = state[8];
   out_2995414732378888264[22] = 0;
   out_2995414732378888264[23] = -state[6];
   out_2995414732378888264[24] = -state[5];
   out_2995414732378888264[25] = 0;
   out_2995414732378888264[26] = state[3];
   out_2995414732378888264[27] = 0;
   out_2995414732378888264[28] = 0;
   out_2995414732378888264[29] = 0;
   out_2995414732378888264[30] = 0;
   out_2995414732378888264[31] = 1;
   out_2995414732378888264[32] = 0;
   out_2995414732378888264[33] = 0;
   out_2995414732378888264[34] = 1;
   out_2995414732378888264[35] = 0;
   out_2995414732378888264[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_2995414732378888264[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_2995414732378888264[38] = 0;
   out_2995414732378888264[39] = -state[7];
   out_2995414732378888264[40] = state[6];
   out_2995414732378888264[41] = 0;
   out_2995414732378888264[42] = state[4];
   out_2995414732378888264[43] = -state[3];
   out_2995414732378888264[44] = 0;
   out_2995414732378888264[45] = 0;
   out_2995414732378888264[46] = 0;
   out_2995414732378888264[47] = 0;
   out_2995414732378888264[48] = 0;
   out_2995414732378888264[49] = 0;
   out_2995414732378888264[50] = 1;
   out_2995414732378888264[51] = 0;
   out_2995414732378888264[52] = 0;
   out_2995414732378888264[53] = 1;
}
void h_13(double *state, double *unused, double *out_2216808697285544655) {
   out_2216808697285544655[0] = state[3];
   out_2216808697285544655[1] = state[4];
   out_2216808697285544655[2] = state[5];
}
void H_13(double *state, double *unused, double *out_7960316795639369413) {
   out_7960316795639369413[0] = 0;
   out_7960316795639369413[1] = 0;
   out_7960316795639369413[2] = 0;
   out_7960316795639369413[3] = 1;
   out_7960316795639369413[4] = 0;
   out_7960316795639369413[5] = 0;
   out_7960316795639369413[6] = 0;
   out_7960316795639369413[7] = 0;
   out_7960316795639369413[8] = 0;
   out_7960316795639369413[9] = 0;
   out_7960316795639369413[10] = 0;
   out_7960316795639369413[11] = 0;
   out_7960316795639369413[12] = 0;
   out_7960316795639369413[13] = 0;
   out_7960316795639369413[14] = 0;
   out_7960316795639369413[15] = 0;
   out_7960316795639369413[16] = 0;
   out_7960316795639369413[17] = 0;
   out_7960316795639369413[18] = 0;
   out_7960316795639369413[19] = 0;
   out_7960316795639369413[20] = 0;
   out_7960316795639369413[21] = 0;
   out_7960316795639369413[22] = 1;
   out_7960316795639369413[23] = 0;
   out_7960316795639369413[24] = 0;
   out_7960316795639369413[25] = 0;
   out_7960316795639369413[26] = 0;
   out_7960316795639369413[27] = 0;
   out_7960316795639369413[28] = 0;
   out_7960316795639369413[29] = 0;
   out_7960316795639369413[30] = 0;
   out_7960316795639369413[31] = 0;
   out_7960316795639369413[32] = 0;
   out_7960316795639369413[33] = 0;
   out_7960316795639369413[34] = 0;
   out_7960316795639369413[35] = 0;
   out_7960316795639369413[36] = 0;
   out_7960316795639369413[37] = 0;
   out_7960316795639369413[38] = 0;
   out_7960316795639369413[39] = 0;
   out_7960316795639369413[40] = 0;
   out_7960316795639369413[41] = 1;
   out_7960316795639369413[42] = 0;
   out_7960316795639369413[43] = 0;
   out_7960316795639369413[44] = 0;
   out_7960316795639369413[45] = 0;
   out_7960316795639369413[46] = 0;
   out_7960316795639369413[47] = 0;
   out_7960316795639369413[48] = 0;
   out_7960316795639369413[49] = 0;
   out_7960316795639369413[50] = 0;
   out_7960316795639369413[51] = 0;
   out_7960316795639369413[52] = 0;
   out_7960316795639369413[53] = 0;
}
void h_14(double *state, double *unused, double *out_4203114798521230693) {
   out_4203114798521230693[0] = state[6];
   out_4203114798521230693[1] = state[7];
   out_4203114798521230693[2] = state[8];
}
void H_14(double *state, double *unused, double *out_8711283826646521141) {
   out_8711283826646521141[0] = 0;
   out_8711283826646521141[1] = 0;
   out_8711283826646521141[2] = 0;
   out_8711283826646521141[3] = 0;
   out_8711283826646521141[4] = 0;
   out_8711283826646521141[5] = 0;
   out_8711283826646521141[6] = 1;
   out_8711283826646521141[7] = 0;
   out_8711283826646521141[8] = 0;
   out_8711283826646521141[9] = 0;
   out_8711283826646521141[10] = 0;
   out_8711283826646521141[11] = 0;
   out_8711283826646521141[12] = 0;
   out_8711283826646521141[13] = 0;
   out_8711283826646521141[14] = 0;
   out_8711283826646521141[15] = 0;
   out_8711283826646521141[16] = 0;
   out_8711283826646521141[17] = 0;
   out_8711283826646521141[18] = 0;
   out_8711283826646521141[19] = 0;
   out_8711283826646521141[20] = 0;
   out_8711283826646521141[21] = 0;
   out_8711283826646521141[22] = 0;
   out_8711283826646521141[23] = 0;
   out_8711283826646521141[24] = 0;
   out_8711283826646521141[25] = 1;
   out_8711283826646521141[26] = 0;
   out_8711283826646521141[27] = 0;
   out_8711283826646521141[28] = 0;
   out_8711283826646521141[29] = 0;
   out_8711283826646521141[30] = 0;
   out_8711283826646521141[31] = 0;
   out_8711283826646521141[32] = 0;
   out_8711283826646521141[33] = 0;
   out_8711283826646521141[34] = 0;
   out_8711283826646521141[35] = 0;
   out_8711283826646521141[36] = 0;
   out_8711283826646521141[37] = 0;
   out_8711283826646521141[38] = 0;
   out_8711283826646521141[39] = 0;
   out_8711283826646521141[40] = 0;
   out_8711283826646521141[41] = 0;
   out_8711283826646521141[42] = 0;
   out_8711283826646521141[43] = 0;
   out_8711283826646521141[44] = 1;
   out_8711283826646521141[45] = 0;
   out_8711283826646521141[46] = 0;
   out_8711283826646521141[47] = 0;
   out_8711283826646521141[48] = 0;
   out_8711283826646521141[49] = 0;
   out_8711283826646521141[50] = 0;
   out_8711283826646521141[51] = 0;
   out_8711283826646521141[52] = 0;
   out_8711283826646521141[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_1736746612172014874) {
  err_fun(nom_x, delta_x, out_1736746612172014874);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_2621334881021189822) {
  inv_err_fun(nom_x, true_x, out_2621334881021189822);
}
void pose_H_mod_fun(double *state, double *out_976235760463129040) {
  H_mod_fun(state, out_976235760463129040);
}
void pose_f_fun(double *state, double dt, double *out_8570715647887041589) {
  f_fun(state,  dt, out_8570715647887041589);
}
void pose_F_fun(double *state, double dt, double *out_9195171490393905022) {
  F_fun(state,  dt, out_9195171490393905022);
}
void pose_h_4(double *state, double *unused, double *out_1784252823533360007) {
  h_4(state, unused, out_1784252823533360007);
}
void pose_H_4(double *state, double *unused, double *out_4748042970307036612) {
  H_4(state, unused, out_4748042970307036612);
}
void pose_h_10(double *state, double *unused, double *out_2498286068008923995) {
  h_10(state, unused, out_2498286068008923995);
}
void pose_H_10(double *state, double *unused, double *out_2995414732378888264) {
  H_10(state, unused, out_2995414732378888264);
}
void pose_h_13(double *state, double *unused, double *out_2216808697285544655) {
  h_13(state, unused, out_2216808697285544655);
}
void pose_H_13(double *state, double *unused, double *out_7960316795639369413) {
  H_13(state, unused, out_7960316795639369413);
}
void pose_h_14(double *state, double *unused, double *out_4203114798521230693) {
  h_14(state, unused, out_4203114798521230693);
}
void pose_H_14(double *state, double *unused, double *out_8711283826646521141) {
  H_14(state, unused, out_8711283826646521141);
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
