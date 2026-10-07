#include "car.h"

namespace {
#define DIM 9
#define EDIM 9
#define MEDIM 9
typedef void (*Hfun)(double *, double *, double *);

double mass;

void set_mass(double x){ mass = x;}

double rotational_inertia;

void set_rotational_inertia(double x){ rotational_inertia = x;}

double center_to_front;

void set_center_to_front(double x){ center_to_front = x;}

double center_to_rear;

void set_center_to_rear(double x){ center_to_rear = x;}

double stiffness_front;

void set_stiffness_front(double x){ stiffness_front = x;}

double stiffness_rear;

void set_stiffness_rear(double x){ stiffness_rear = x;}
const static double MAHA_THRESH_25 = 3.8414588206941227;
const static double MAHA_THRESH_24 = 5.991464547107981;
const static double MAHA_THRESH_30 = 3.8414588206941227;
const static double MAHA_THRESH_26 = 3.8414588206941227;
const static double MAHA_THRESH_27 = 3.8414588206941227;
const static double MAHA_THRESH_29 = 3.8414588206941227;
const static double MAHA_THRESH_28 = 3.8414588206941227;
const static double MAHA_THRESH_31 = 3.8414588206941227;

/******************************************************************************
 *                      Code generated with SymPy 1.14.0                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_865702802355291203) {
   out_865702802355291203[0] = delta_x[0] + nom_x[0];
   out_865702802355291203[1] = delta_x[1] + nom_x[1];
   out_865702802355291203[2] = delta_x[2] + nom_x[2];
   out_865702802355291203[3] = delta_x[3] + nom_x[3];
   out_865702802355291203[4] = delta_x[4] + nom_x[4];
   out_865702802355291203[5] = delta_x[5] + nom_x[5];
   out_865702802355291203[6] = delta_x[6] + nom_x[6];
   out_865702802355291203[7] = delta_x[7] + nom_x[7];
   out_865702802355291203[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_2817795773869963671) {
   out_2817795773869963671[0] = -nom_x[0] + true_x[0];
   out_2817795773869963671[1] = -nom_x[1] + true_x[1];
   out_2817795773869963671[2] = -nom_x[2] + true_x[2];
   out_2817795773869963671[3] = -nom_x[3] + true_x[3];
   out_2817795773869963671[4] = -nom_x[4] + true_x[4];
   out_2817795773869963671[5] = -nom_x[5] + true_x[5];
   out_2817795773869963671[6] = -nom_x[6] + true_x[6];
   out_2817795773869963671[7] = -nom_x[7] + true_x[7];
   out_2817795773869963671[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_6495550314774613536) {
   out_6495550314774613536[0] = 1.0;
   out_6495550314774613536[1] = 0.0;
   out_6495550314774613536[2] = 0.0;
   out_6495550314774613536[3] = 0.0;
   out_6495550314774613536[4] = 0.0;
   out_6495550314774613536[5] = 0.0;
   out_6495550314774613536[6] = 0.0;
   out_6495550314774613536[7] = 0.0;
   out_6495550314774613536[8] = 0.0;
   out_6495550314774613536[9] = 0.0;
   out_6495550314774613536[10] = 1.0;
   out_6495550314774613536[11] = 0.0;
   out_6495550314774613536[12] = 0.0;
   out_6495550314774613536[13] = 0.0;
   out_6495550314774613536[14] = 0.0;
   out_6495550314774613536[15] = 0.0;
   out_6495550314774613536[16] = 0.0;
   out_6495550314774613536[17] = 0.0;
   out_6495550314774613536[18] = 0.0;
   out_6495550314774613536[19] = 0.0;
   out_6495550314774613536[20] = 1.0;
   out_6495550314774613536[21] = 0.0;
   out_6495550314774613536[22] = 0.0;
   out_6495550314774613536[23] = 0.0;
   out_6495550314774613536[24] = 0.0;
   out_6495550314774613536[25] = 0.0;
   out_6495550314774613536[26] = 0.0;
   out_6495550314774613536[27] = 0.0;
   out_6495550314774613536[28] = 0.0;
   out_6495550314774613536[29] = 0.0;
   out_6495550314774613536[30] = 1.0;
   out_6495550314774613536[31] = 0.0;
   out_6495550314774613536[32] = 0.0;
   out_6495550314774613536[33] = 0.0;
   out_6495550314774613536[34] = 0.0;
   out_6495550314774613536[35] = 0.0;
   out_6495550314774613536[36] = 0.0;
   out_6495550314774613536[37] = 0.0;
   out_6495550314774613536[38] = 0.0;
   out_6495550314774613536[39] = 0.0;
   out_6495550314774613536[40] = 1.0;
   out_6495550314774613536[41] = 0.0;
   out_6495550314774613536[42] = 0.0;
   out_6495550314774613536[43] = 0.0;
   out_6495550314774613536[44] = 0.0;
   out_6495550314774613536[45] = 0.0;
   out_6495550314774613536[46] = 0.0;
   out_6495550314774613536[47] = 0.0;
   out_6495550314774613536[48] = 0.0;
   out_6495550314774613536[49] = 0.0;
   out_6495550314774613536[50] = 1.0;
   out_6495550314774613536[51] = 0.0;
   out_6495550314774613536[52] = 0.0;
   out_6495550314774613536[53] = 0.0;
   out_6495550314774613536[54] = 0.0;
   out_6495550314774613536[55] = 0.0;
   out_6495550314774613536[56] = 0.0;
   out_6495550314774613536[57] = 0.0;
   out_6495550314774613536[58] = 0.0;
   out_6495550314774613536[59] = 0.0;
   out_6495550314774613536[60] = 1.0;
   out_6495550314774613536[61] = 0.0;
   out_6495550314774613536[62] = 0.0;
   out_6495550314774613536[63] = 0.0;
   out_6495550314774613536[64] = 0.0;
   out_6495550314774613536[65] = 0.0;
   out_6495550314774613536[66] = 0.0;
   out_6495550314774613536[67] = 0.0;
   out_6495550314774613536[68] = 0.0;
   out_6495550314774613536[69] = 0.0;
   out_6495550314774613536[70] = 1.0;
   out_6495550314774613536[71] = 0.0;
   out_6495550314774613536[72] = 0.0;
   out_6495550314774613536[73] = 0.0;
   out_6495550314774613536[74] = 0.0;
   out_6495550314774613536[75] = 0.0;
   out_6495550314774613536[76] = 0.0;
   out_6495550314774613536[77] = 0.0;
   out_6495550314774613536[78] = 0.0;
   out_6495550314774613536[79] = 0.0;
   out_6495550314774613536[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_4170096922626973971) {
   out_4170096922626973971[0] = state[0];
   out_4170096922626973971[1] = state[1];
   out_4170096922626973971[2] = state[2];
   out_4170096922626973971[3] = state[3];
   out_4170096922626973971[4] = state[4];
   out_4170096922626973971[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8100000000000005*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_4170096922626973971[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_4170096922626973971[7] = state[7];
   out_4170096922626973971[8] = state[8];
}
void F_fun(double *state, double dt, double *out_4322574903008772197) {
   out_4322574903008772197[0] = 1;
   out_4322574903008772197[1] = 0;
   out_4322574903008772197[2] = 0;
   out_4322574903008772197[3] = 0;
   out_4322574903008772197[4] = 0;
   out_4322574903008772197[5] = 0;
   out_4322574903008772197[6] = 0;
   out_4322574903008772197[7] = 0;
   out_4322574903008772197[8] = 0;
   out_4322574903008772197[9] = 0;
   out_4322574903008772197[10] = 1;
   out_4322574903008772197[11] = 0;
   out_4322574903008772197[12] = 0;
   out_4322574903008772197[13] = 0;
   out_4322574903008772197[14] = 0;
   out_4322574903008772197[15] = 0;
   out_4322574903008772197[16] = 0;
   out_4322574903008772197[17] = 0;
   out_4322574903008772197[18] = 0;
   out_4322574903008772197[19] = 0;
   out_4322574903008772197[20] = 1;
   out_4322574903008772197[21] = 0;
   out_4322574903008772197[22] = 0;
   out_4322574903008772197[23] = 0;
   out_4322574903008772197[24] = 0;
   out_4322574903008772197[25] = 0;
   out_4322574903008772197[26] = 0;
   out_4322574903008772197[27] = 0;
   out_4322574903008772197[28] = 0;
   out_4322574903008772197[29] = 0;
   out_4322574903008772197[30] = 1;
   out_4322574903008772197[31] = 0;
   out_4322574903008772197[32] = 0;
   out_4322574903008772197[33] = 0;
   out_4322574903008772197[34] = 0;
   out_4322574903008772197[35] = 0;
   out_4322574903008772197[36] = 0;
   out_4322574903008772197[37] = 0;
   out_4322574903008772197[38] = 0;
   out_4322574903008772197[39] = 0;
   out_4322574903008772197[40] = 1;
   out_4322574903008772197[41] = 0;
   out_4322574903008772197[42] = 0;
   out_4322574903008772197[43] = 0;
   out_4322574903008772197[44] = 0;
   out_4322574903008772197[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_4322574903008772197[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_4322574903008772197[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_4322574903008772197[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_4322574903008772197[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_4322574903008772197[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_4322574903008772197[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_4322574903008772197[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_4322574903008772197[53] = -9.8100000000000005*dt;
   out_4322574903008772197[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_4322574903008772197[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_4322574903008772197[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_4322574903008772197[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_4322574903008772197[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_4322574903008772197[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_4322574903008772197[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_4322574903008772197[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_4322574903008772197[62] = 0;
   out_4322574903008772197[63] = 0;
   out_4322574903008772197[64] = 0;
   out_4322574903008772197[65] = 0;
   out_4322574903008772197[66] = 0;
   out_4322574903008772197[67] = 0;
   out_4322574903008772197[68] = 0;
   out_4322574903008772197[69] = 0;
   out_4322574903008772197[70] = 1;
   out_4322574903008772197[71] = 0;
   out_4322574903008772197[72] = 0;
   out_4322574903008772197[73] = 0;
   out_4322574903008772197[74] = 0;
   out_4322574903008772197[75] = 0;
   out_4322574903008772197[76] = 0;
   out_4322574903008772197[77] = 0;
   out_4322574903008772197[78] = 0;
   out_4322574903008772197[79] = 0;
   out_4322574903008772197[80] = 1;
}
void h_25(double *state, double *unused, double *out_1540359977116304995) {
   out_1540359977116304995[0] = state[6];
}
void H_25(double *state, double *unused, double *out_1591858489589948696) {
   out_1591858489589948696[0] = 0;
   out_1591858489589948696[1] = 0;
   out_1591858489589948696[2] = 0;
   out_1591858489589948696[3] = 0;
   out_1591858489589948696[4] = 0;
   out_1591858489589948696[5] = 0;
   out_1591858489589948696[6] = 1;
   out_1591858489589948696[7] = 0;
   out_1591858489589948696[8] = 0;
}
void h_24(double *state, double *unused, double *out_1148075365840781748) {
   out_1148075365840781748[0] = state[4];
   out_1148075365840781748[1] = state[5];
}
void H_24(double *state, double *unused, double *out_4983713317001569405) {
   out_4983713317001569405[0] = 0;
   out_4983713317001569405[1] = 0;
   out_4983713317001569405[2] = 0;
   out_4983713317001569405[3] = 0;
   out_4983713317001569405[4] = 1;
   out_4983713317001569405[5] = 0;
   out_4983713317001569405[6] = 0;
   out_4983713317001569405[7] = 0;
   out_4983713317001569405[8] = 0;
   out_4983713317001569405[9] = 0;
   out_4983713317001569405[10] = 0;
   out_4983713317001569405[11] = 0;
   out_4983713317001569405[12] = 0;
   out_4983713317001569405[13] = 0;
   out_4983713317001569405[14] = 1;
   out_4983713317001569405[15] = 0;
   out_4983713317001569405[16] = 0;
   out_4983713317001569405[17] = 0;
}
void h_30(double *state, double *unused, double *out_4488085967471789956) {
   out_4488085967471789956[0] = state[4];
}
void H_30(double *state, double *unused, double *out_5324831851901668059) {
   out_5324831851901668059[0] = 0;
   out_5324831851901668059[1] = 0;
   out_5324831851901668059[2] = 0;
   out_5324831851901668059[3] = 0;
   out_5324831851901668059[4] = 1;
   out_5324831851901668059[5] = 0;
   out_5324831851901668059[6] = 0;
   out_5324831851901668059[7] = 0;
   out_5324831851901668059[8] = 0;
}
void h_26(double *state, double *unused, double *out_5431595820373452391) {
   out_5431595820373452391[0] = state[7];
}
void H_26(double *state, double *unused, double *out_5333361808464004920) {
   out_5333361808464004920[0] = 0;
   out_5333361808464004920[1] = 0;
   out_5333361808464004920[2] = 0;
   out_5333361808464004920[3] = 0;
   out_5333361808464004920[4] = 0;
   out_5333361808464004920[5] = 0;
   out_5333361808464004920[6] = 0;
   out_5333361808464004920[7] = 1;
   out_5333361808464004920[8] = 0;
}
void h_27(double *state, double *unused, double *out_9102504662797570986) {
   out_9102504662797570986[0] = state[3];
}
void H_27(double *state, double *unused, double *out_3150068540101243148) {
   out_3150068540101243148[0] = 0;
   out_3150068540101243148[1] = 0;
   out_3150068540101243148[2] = 0;
   out_3150068540101243148[3] = 1;
   out_3150068540101243148[4] = 0;
   out_3150068540101243148[5] = 0;
   out_3150068540101243148[6] = 0;
   out_3150068540101243148[7] = 0;
   out_3150068540101243148[8] = 0;
}
void h_29(double *state, double *unused, double *out_8956984838576916015) {
   out_8956984838576916015[0] = state[1];
}
void H_29(double *state, double *unused, double *out_1436705813231692115) {
   out_1436705813231692115[0] = 0;
   out_1436705813231692115[1] = 1;
   out_1436705813231692115[2] = 0;
   out_1436705813231692115[3] = 0;
   out_1436705813231692115[4] = 0;
   out_1436705813231692115[5] = 0;
   out_1436705813231692115[6] = 0;
   out_1436705813231692115[7] = 0;
   out_1436705813231692115[8] = 0;
}
void h_28(double *state, double *unused, double *out_4100831395136725341) {
   out_4100831395136725341[0] = state[0];
}
void H_28(double *state, double *unused, double *out_3645693203837838459) {
   out_3645693203837838459[0] = 1;
   out_3645693203837838459[1] = 0;
   out_3645693203837838459[2] = 0;
   out_3645693203837838459[3] = 0;
   out_3645693203837838459[4] = 0;
   out_3645693203837838459[5] = 0;
   out_3645693203837838459[6] = 0;
   out_3645693203837838459[7] = 0;
   out_3645693203837838459[8] = 0;
}
void h_31(double *state, double *unused, double *out_6340912673637744190) {
   out_6340912673637744190[0] = state[8];
}
void H_31(double *state, double *unused, double *out_1561212527712988268) {
   out_1561212527712988268[0] = 0;
   out_1561212527712988268[1] = 0;
   out_1561212527712988268[2] = 0;
   out_1561212527712988268[3] = 0;
   out_1561212527712988268[4] = 0;
   out_1561212527712988268[5] = 0;
   out_1561212527712988268[6] = 0;
   out_1561212527712988268[7] = 0;
   out_1561212527712988268[8] = 1;
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

void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_25, H_25, NULL, in_z, in_R, in_ea, MAHA_THRESH_25);
}
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<2, 3, 0>(in_x, in_P, h_24, H_24, NULL, in_z, in_R, in_ea, MAHA_THRESH_24);
}
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_30, H_30, NULL, in_z, in_R, in_ea, MAHA_THRESH_30);
}
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_26, H_26, NULL, in_z, in_R, in_ea, MAHA_THRESH_26);
}
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_27, H_27, NULL, in_z, in_R, in_ea, MAHA_THRESH_27);
}
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_29, H_29, NULL, in_z, in_R, in_ea, MAHA_THRESH_29);
}
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_28, H_28, NULL, in_z, in_R, in_ea, MAHA_THRESH_28);
}
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_31, H_31, NULL, in_z, in_R, in_ea, MAHA_THRESH_31);
}
void car_err_fun(double *nom_x, double *delta_x, double *out_865702802355291203) {
  err_fun(nom_x, delta_x, out_865702802355291203);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_2817795773869963671) {
  inv_err_fun(nom_x, true_x, out_2817795773869963671);
}
void car_H_mod_fun(double *state, double *out_6495550314774613536) {
  H_mod_fun(state, out_6495550314774613536);
}
void car_f_fun(double *state, double dt, double *out_4170096922626973971) {
  f_fun(state,  dt, out_4170096922626973971);
}
void car_F_fun(double *state, double dt, double *out_4322574903008772197) {
  F_fun(state,  dt, out_4322574903008772197);
}
void car_h_25(double *state, double *unused, double *out_1540359977116304995) {
  h_25(state, unused, out_1540359977116304995);
}
void car_H_25(double *state, double *unused, double *out_1591858489589948696) {
  H_25(state, unused, out_1591858489589948696);
}
void car_h_24(double *state, double *unused, double *out_1148075365840781748) {
  h_24(state, unused, out_1148075365840781748);
}
void car_H_24(double *state, double *unused, double *out_4983713317001569405) {
  H_24(state, unused, out_4983713317001569405);
}
void car_h_30(double *state, double *unused, double *out_4488085967471789956) {
  h_30(state, unused, out_4488085967471789956);
}
void car_H_30(double *state, double *unused, double *out_5324831851901668059) {
  H_30(state, unused, out_5324831851901668059);
}
void car_h_26(double *state, double *unused, double *out_5431595820373452391) {
  h_26(state, unused, out_5431595820373452391);
}
void car_H_26(double *state, double *unused, double *out_5333361808464004920) {
  H_26(state, unused, out_5333361808464004920);
}
void car_h_27(double *state, double *unused, double *out_9102504662797570986) {
  h_27(state, unused, out_9102504662797570986);
}
void car_H_27(double *state, double *unused, double *out_3150068540101243148) {
  H_27(state, unused, out_3150068540101243148);
}
void car_h_29(double *state, double *unused, double *out_8956984838576916015) {
  h_29(state, unused, out_8956984838576916015);
}
void car_H_29(double *state, double *unused, double *out_1436705813231692115) {
  H_29(state, unused, out_1436705813231692115);
}
void car_h_28(double *state, double *unused, double *out_4100831395136725341) {
  h_28(state, unused, out_4100831395136725341);
}
void car_H_28(double *state, double *unused, double *out_3645693203837838459) {
  H_28(state, unused, out_3645693203837838459);
}
void car_h_31(double *state, double *unused, double *out_6340912673637744190) {
  h_31(state, unused, out_6340912673637744190);
}
void car_H_31(double *state, double *unused, double *out_1561212527712988268) {
  H_31(state, unused, out_1561212527712988268);
}
void car_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
void car_set_mass(double x) {
  set_mass(x);
}
void car_set_rotational_inertia(double x) {
  set_rotational_inertia(x);
}
void car_set_center_to_front(double x) {
  set_center_to_front(x);
}
void car_set_center_to_rear(double x) {
  set_center_to_rear(x);
}
void car_set_stiffness_front(double x) {
  set_stiffness_front(x);
}
void car_set_stiffness_rear(double x) {
  set_stiffness_rear(x);
}
}

const EKF car = {
  .name = "car",
  .kinds = { 25, 24, 30, 26, 27, 29, 28, 31 },
  .feature_kinds = {  },
  .f_fun = car_f_fun,
  .F_fun = car_F_fun,
  .err_fun = car_err_fun,
  .inv_err_fun = car_inv_err_fun,
  .H_mod_fun = car_H_mod_fun,
  .predict = car_predict,
  .hs = {
    { 25, car_h_25 },
    { 24, car_h_24 },
    { 30, car_h_30 },
    { 26, car_h_26 },
    { 27, car_h_27 },
    { 29, car_h_29 },
    { 28, car_h_28 },
    { 31, car_h_31 },
  },
  .Hs = {
    { 25, car_H_25 },
    { 24, car_H_24 },
    { 30, car_H_30 },
    { 26, car_H_26 },
    { 27, car_H_27 },
    { 29, car_H_29 },
    { 28, car_H_28 },
    { 31, car_H_31 },
  },
  .updates = {
    { 25, car_update_25 },
    { 24, car_update_24 },
    { 30, car_update_30 },
    { 26, car_update_26 },
    { 27, car_update_27 },
    { 29, car_update_29 },
    { 28, car_update_28 },
    { 31, car_update_31 },
  },
  .Hes = {
  },
  .sets = {
    { "mass", car_set_mass },
    { "rotational_inertia", car_set_rotational_inertia },
    { "center_to_front", car_set_center_to_front },
    { "center_to_rear", car_set_center_to_rear },
    { "stiffness_front", car_set_stiffness_front },
    { "stiffness_rear", car_set_stiffness_rear },
  },
  .extra_routines = {
  },
};

ekf_lib_init(car)
