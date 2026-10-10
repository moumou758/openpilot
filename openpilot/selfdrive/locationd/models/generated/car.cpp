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
void err_fun(double *nom_x, double *delta_x, double *out_846970993423390905) {
   out_846970993423390905[0] = delta_x[0] + nom_x[0];
   out_846970993423390905[1] = delta_x[1] + nom_x[1];
   out_846970993423390905[2] = delta_x[2] + nom_x[2];
   out_846970993423390905[3] = delta_x[3] + nom_x[3];
   out_846970993423390905[4] = delta_x[4] + nom_x[4];
   out_846970993423390905[5] = delta_x[5] + nom_x[5];
   out_846970993423390905[6] = delta_x[6] + nom_x[6];
   out_846970993423390905[7] = delta_x[7] + nom_x[7];
   out_846970993423390905[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_7688258081560496824) {
   out_7688258081560496824[0] = -nom_x[0] + true_x[0];
   out_7688258081560496824[1] = -nom_x[1] + true_x[1];
   out_7688258081560496824[2] = -nom_x[2] + true_x[2];
   out_7688258081560496824[3] = -nom_x[3] + true_x[3];
   out_7688258081560496824[4] = -nom_x[4] + true_x[4];
   out_7688258081560496824[5] = -nom_x[5] + true_x[5];
   out_7688258081560496824[6] = -nom_x[6] + true_x[6];
   out_7688258081560496824[7] = -nom_x[7] + true_x[7];
   out_7688258081560496824[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_3454494615608712148) {
   out_3454494615608712148[0] = 1.0;
   out_3454494615608712148[1] = 0.0;
   out_3454494615608712148[2] = 0.0;
   out_3454494615608712148[3] = 0.0;
   out_3454494615608712148[4] = 0.0;
   out_3454494615608712148[5] = 0.0;
   out_3454494615608712148[6] = 0.0;
   out_3454494615608712148[7] = 0.0;
   out_3454494615608712148[8] = 0.0;
   out_3454494615608712148[9] = 0.0;
   out_3454494615608712148[10] = 1.0;
   out_3454494615608712148[11] = 0.0;
   out_3454494615608712148[12] = 0.0;
   out_3454494615608712148[13] = 0.0;
   out_3454494615608712148[14] = 0.0;
   out_3454494615608712148[15] = 0.0;
   out_3454494615608712148[16] = 0.0;
   out_3454494615608712148[17] = 0.0;
   out_3454494615608712148[18] = 0.0;
   out_3454494615608712148[19] = 0.0;
   out_3454494615608712148[20] = 1.0;
   out_3454494615608712148[21] = 0.0;
   out_3454494615608712148[22] = 0.0;
   out_3454494615608712148[23] = 0.0;
   out_3454494615608712148[24] = 0.0;
   out_3454494615608712148[25] = 0.0;
   out_3454494615608712148[26] = 0.0;
   out_3454494615608712148[27] = 0.0;
   out_3454494615608712148[28] = 0.0;
   out_3454494615608712148[29] = 0.0;
   out_3454494615608712148[30] = 1.0;
   out_3454494615608712148[31] = 0.0;
   out_3454494615608712148[32] = 0.0;
   out_3454494615608712148[33] = 0.0;
   out_3454494615608712148[34] = 0.0;
   out_3454494615608712148[35] = 0.0;
   out_3454494615608712148[36] = 0.0;
   out_3454494615608712148[37] = 0.0;
   out_3454494615608712148[38] = 0.0;
   out_3454494615608712148[39] = 0.0;
   out_3454494615608712148[40] = 1.0;
   out_3454494615608712148[41] = 0.0;
   out_3454494615608712148[42] = 0.0;
   out_3454494615608712148[43] = 0.0;
   out_3454494615608712148[44] = 0.0;
   out_3454494615608712148[45] = 0.0;
   out_3454494615608712148[46] = 0.0;
   out_3454494615608712148[47] = 0.0;
   out_3454494615608712148[48] = 0.0;
   out_3454494615608712148[49] = 0.0;
   out_3454494615608712148[50] = 1.0;
   out_3454494615608712148[51] = 0.0;
   out_3454494615608712148[52] = 0.0;
   out_3454494615608712148[53] = 0.0;
   out_3454494615608712148[54] = 0.0;
   out_3454494615608712148[55] = 0.0;
   out_3454494615608712148[56] = 0.0;
   out_3454494615608712148[57] = 0.0;
   out_3454494615608712148[58] = 0.0;
   out_3454494615608712148[59] = 0.0;
   out_3454494615608712148[60] = 1.0;
   out_3454494615608712148[61] = 0.0;
   out_3454494615608712148[62] = 0.0;
   out_3454494615608712148[63] = 0.0;
   out_3454494615608712148[64] = 0.0;
   out_3454494615608712148[65] = 0.0;
   out_3454494615608712148[66] = 0.0;
   out_3454494615608712148[67] = 0.0;
   out_3454494615608712148[68] = 0.0;
   out_3454494615608712148[69] = 0.0;
   out_3454494615608712148[70] = 1.0;
   out_3454494615608712148[71] = 0.0;
   out_3454494615608712148[72] = 0.0;
   out_3454494615608712148[73] = 0.0;
   out_3454494615608712148[74] = 0.0;
   out_3454494615608712148[75] = 0.0;
   out_3454494615608712148[76] = 0.0;
   out_3454494615608712148[77] = 0.0;
   out_3454494615608712148[78] = 0.0;
   out_3454494615608712148[79] = 0.0;
   out_3454494615608712148[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_1518223738615346199) {
   out_1518223738615346199[0] = state[0];
   out_1518223738615346199[1] = state[1];
   out_1518223738615346199[2] = state[2];
   out_1518223738615346199[3] = state[3];
   out_1518223738615346199[4] = state[4];
   out_1518223738615346199[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8100000000000005*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_1518223738615346199[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_1518223738615346199[7] = state[7];
   out_1518223738615346199[8] = state[8];
}
void F_fun(double *state, double dt, double *out_6380082957886893439) {
   out_6380082957886893439[0] = 1;
   out_6380082957886893439[1] = 0;
   out_6380082957886893439[2] = 0;
   out_6380082957886893439[3] = 0;
   out_6380082957886893439[4] = 0;
   out_6380082957886893439[5] = 0;
   out_6380082957886893439[6] = 0;
   out_6380082957886893439[7] = 0;
   out_6380082957886893439[8] = 0;
   out_6380082957886893439[9] = 0;
   out_6380082957886893439[10] = 1;
   out_6380082957886893439[11] = 0;
   out_6380082957886893439[12] = 0;
   out_6380082957886893439[13] = 0;
   out_6380082957886893439[14] = 0;
   out_6380082957886893439[15] = 0;
   out_6380082957886893439[16] = 0;
   out_6380082957886893439[17] = 0;
   out_6380082957886893439[18] = 0;
   out_6380082957886893439[19] = 0;
   out_6380082957886893439[20] = 1;
   out_6380082957886893439[21] = 0;
   out_6380082957886893439[22] = 0;
   out_6380082957886893439[23] = 0;
   out_6380082957886893439[24] = 0;
   out_6380082957886893439[25] = 0;
   out_6380082957886893439[26] = 0;
   out_6380082957886893439[27] = 0;
   out_6380082957886893439[28] = 0;
   out_6380082957886893439[29] = 0;
   out_6380082957886893439[30] = 1;
   out_6380082957886893439[31] = 0;
   out_6380082957886893439[32] = 0;
   out_6380082957886893439[33] = 0;
   out_6380082957886893439[34] = 0;
   out_6380082957886893439[35] = 0;
   out_6380082957886893439[36] = 0;
   out_6380082957886893439[37] = 0;
   out_6380082957886893439[38] = 0;
   out_6380082957886893439[39] = 0;
   out_6380082957886893439[40] = 1;
   out_6380082957886893439[41] = 0;
   out_6380082957886893439[42] = 0;
   out_6380082957886893439[43] = 0;
   out_6380082957886893439[44] = 0;
   out_6380082957886893439[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_6380082957886893439[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_6380082957886893439[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_6380082957886893439[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_6380082957886893439[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_6380082957886893439[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_6380082957886893439[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_6380082957886893439[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_6380082957886893439[53] = -9.8100000000000005*dt;
   out_6380082957886893439[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_6380082957886893439[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_6380082957886893439[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_6380082957886893439[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_6380082957886893439[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_6380082957886893439[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_6380082957886893439[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_6380082957886893439[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_6380082957886893439[62] = 0;
   out_6380082957886893439[63] = 0;
   out_6380082957886893439[64] = 0;
   out_6380082957886893439[65] = 0;
   out_6380082957886893439[66] = 0;
   out_6380082957886893439[67] = 0;
   out_6380082957886893439[68] = 0;
   out_6380082957886893439[69] = 0;
   out_6380082957886893439[70] = 1;
   out_6380082957886893439[71] = 0;
   out_6380082957886893439[72] = 0;
   out_6380082957886893439[73] = 0;
   out_6380082957886893439[74] = 0;
   out_6380082957886893439[75] = 0;
   out_6380082957886893439[76] = 0;
   out_6380082957886893439[77] = 0;
   out_6380082957886893439[78] = 0;
   out_6380082957886893439[79] = 0;
   out_6380082957886893439[80] = 1;
}
void h_25(double *state, double *unused, double *out_4349936716124263382) {
   out_4349936716124263382[0] = state[6];
}
void H_25(double *state, double *unused, double *out_5738693610303525089) {
   out_5738693610303525089[0] = 0;
   out_5738693610303525089[1] = 0;
   out_5738693610303525089[2] = 0;
   out_5738693610303525089[3] = 0;
   out_5738693610303525089[4] = 0;
   out_5738693610303525089[5] = 0;
   out_5738693610303525089[6] = 1;
   out_5738693610303525089[7] = 0;
   out_5738693610303525089[8] = 0;
}
void h_24(double *state, double *unused, double *out_8925951289511795298) {
   out_8925951289511795298[0] = state[4];
   out_8925951289511795298[1] = state[5];
}
void H_24(double *state, double *unused, double *out_7911343209309024655) {
   out_7911343209309024655[0] = 0;
   out_7911343209309024655[1] = 0;
   out_7911343209309024655[2] = 0;
   out_7911343209309024655[3] = 0;
   out_7911343209309024655[4] = 1;
   out_7911343209309024655[5] = 0;
   out_7911343209309024655[6] = 0;
   out_7911343209309024655[7] = 0;
   out_7911343209309024655[8] = 0;
   out_7911343209309024655[9] = 0;
   out_7911343209309024655[10] = 0;
   out_7911343209309024655[11] = 0;
   out_7911343209309024655[12] = 0;
   out_7911343209309024655[13] = 0;
   out_7911343209309024655[14] = 1;
   out_7911343209309024655[15] = 0;
   out_7911343209309024655[16] = 0;
   out_7911343209309024655[17] = 0;
}
void h_30(double *state, double *unused, double *out_5456929880866746350) {
   out_5456929880866746350[0] = state[4];
}
void H_30(double *state, double *unused, double *out_5868032557446765159) {
   out_5868032557446765159[0] = 0;
   out_5868032557446765159[1] = 0;
   out_5868032557446765159[2] = 0;
   out_5868032557446765159[3] = 0;
   out_5868032557446765159[4] = 1;
   out_5868032557446765159[5] = 0;
   out_5868032557446765159[6] = 0;
   out_5868032557446765159[7] = 0;
   out_5868032557446765159[8] = 0;
}
void h_26(double *state, double *unused, double *out_8493715932311079035) {
   out_8493715932311079035[0] = state[7];
}
void H_26(double *state, double *unused, double *out_8966547144531970303) {
   out_8966547144531970303[0] = 0;
   out_8966547144531970303[1] = 0;
   out_8966547144531970303[2] = 0;
   out_8966547144531970303[3] = 0;
   out_8966547144531970303[4] = 0;
   out_8966547144531970303[5] = 0;
   out_8966547144531970303[6] = 0;
   out_8966547144531970303[7] = 1;
   out_8966547144531970303[8] = 0;
}
void h_27(double *state, double *unused, double *out_4670606696316213060) {
   out_4670606696316213060[0] = state[3];
}
void H_27(double *state, double *unused, double *out_8042795869247190070) {
   out_8042795869247190070[0] = 0;
   out_8042795869247190070[1] = 0;
   out_8042795869247190070[2] = 0;
   out_8042795869247190070[3] = 1;
   out_8042795869247190070[4] = 0;
   out_8042795869247190070[5] = 0;
   out_8042795869247190070[6] = 0;
   out_8042795869247190070[7] = 0;
   out_8042795869247190070[8] = 0;
}
void h_29(double *state, double *unused, double *out_4513420027965083915) {
   out_4513420027965083915[0] = state[1];
}
void H_29(double *state, double *unused, double *out_8690585477592810513) {
   out_8690585477592810513[0] = 0;
   out_8690585477592810513[1] = 1;
   out_8690585477592810513[2] = 0;
   out_8690585477592810513[3] = 0;
   out_8690585477592810513[4] = 0;
   out_8690585477592810513[5] = 0;
   out_8690585477592810513[6] = 0;
   out_8690585477592810513[7] = 0;
   out_8690585477592810513[8] = 0;
}
void h_28(double *state, double *unused, double *out_1633820644871880375) {
   out_1633820644871880375[0] = state[0];
}
void H_28(double *state, double *unused, double *out_7792528324551414852) {
   out_7792528324551414852[0] = 1;
   out_7792528324551414852[1] = 0;
   out_7792528324551414852[2] = 0;
   out_7792528324551414852[3] = 0;
   out_7792528324551414852[4] = 0;
   out_7792528324551414852[5] = 0;
   out_7792528324551414852[6] = 0;
   out_7792528324551414852[7] = 0;
   out_7792528324551414852[8] = 0;
}
void h_31(double *state, double *unused, double *out_606260633629138474) {
   out_606260633629138474[0] = state[8];
}
void H_31(double *state, double *unused, double *out_5708047648426564661) {
   out_5708047648426564661[0] = 0;
   out_5708047648426564661[1] = 0;
   out_5708047648426564661[2] = 0;
   out_5708047648426564661[3] = 0;
   out_5708047648426564661[4] = 0;
   out_5708047648426564661[5] = 0;
   out_5708047648426564661[6] = 0;
   out_5708047648426564661[7] = 0;
   out_5708047648426564661[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_846970993423390905) {
  err_fun(nom_x, delta_x, out_846970993423390905);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_7688258081560496824) {
  inv_err_fun(nom_x, true_x, out_7688258081560496824);
}
void car_H_mod_fun(double *state, double *out_3454494615608712148) {
  H_mod_fun(state, out_3454494615608712148);
}
void car_f_fun(double *state, double dt, double *out_1518223738615346199) {
  f_fun(state,  dt, out_1518223738615346199);
}
void car_F_fun(double *state, double dt, double *out_6380082957886893439) {
  F_fun(state,  dt, out_6380082957886893439);
}
void car_h_25(double *state, double *unused, double *out_4349936716124263382) {
  h_25(state, unused, out_4349936716124263382);
}
void car_H_25(double *state, double *unused, double *out_5738693610303525089) {
  H_25(state, unused, out_5738693610303525089);
}
void car_h_24(double *state, double *unused, double *out_8925951289511795298) {
  h_24(state, unused, out_8925951289511795298);
}
void car_H_24(double *state, double *unused, double *out_7911343209309024655) {
  H_24(state, unused, out_7911343209309024655);
}
void car_h_30(double *state, double *unused, double *out_5456929880866746350) {
  h_30(state, unused, out_5456929880866746350);
}
void car_H_30(double *state, double *unused, double *out_5868032557446765159) {
  H_30(state, unused, out_5868032557446765159);
}
void car_h_26(double *state, double *unused, double *out_8493715932311079035) {
  h_26(state, unused, out_8493715932311079035);
}
void car_H_26(double *state, double *unused, double *out_8966547144531970303) {
  H_26(state, unused, out_8966547144531970303);
}
void car_h_27(double *state, double *unused, double *out_4670606696316213060) {
  h_27(state, unused, out_4670606696316213060);
}
void car_H_27(double *state, double *unused, double *out_8042795869247190070) {
  H_27(state, unused, out_8042795869247190070);
}
void car_h_29(double *state, double *unused, double *out_4513420027965083915) {
  h_29(state, unused, out_4513420027965083915);
}
void car_H_29(double *state, double *unused, double *out_8690585477592810513) {
  H_29(state, unused, out_8690585477592810513);
}
void car_h_28(double *state, double *unused, double *out_1633820644871880375) {
  h_28(state, unused, out_1633820644871880375);
}
void car_H_28(double *state, double *unused, double *out_7792528324551414852) {
  H_28(state, unused, out_7792528324551414852);
}
void car_h_31(double *state, double *unused, double *out_606260633629138474) {
  h_31(state, unused, out_606260633629138474);
}
void car_H_31(double *state, double *unused, double *out_5708047648426564661) {
  H_31(state, unused, out_5708047648426564661);
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
