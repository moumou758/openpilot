#include "car.h"

namespace {
#define DIM 9
#define EDIM 9
#define MEDIM 9
typedef void (*Hfun)(double *, double *, double *);

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
void err_fun(double *nom_x, double *delta_x, double *out_7177032040242842354) {
   out_7177032040242842354[0] = delta_x[0] + nom_x[0];
   out_7177032040242842354[1] = delta_x[1] + nom_x[1];
   out_7177032040242842354[2] = delta_x[2] + nom_x[2];
   out_7177032040242842354[3] = delta_x[3] + nom_x[3];
   out_7177032040242842354[4] = delta_x[4] + nom_x[4];
   out_7177032040242842354[5] = delta_x[5] + nom_x[5];
   out_7177032040242842354[6] = delta_x[6] + nom_x[6];
   out_7177032040242842354[7] = delta_x[7] + nom_x[7];
   out_7177032040242842354[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_9023220350846612165) {
   out_9023220350846612165[0] = -nom_x[0] + true_x[0];
   out_9023220350846612165[1] = -nom_x[1] + true_x[1];
   out_9023220350846612165[2] = -nom_x[2] + true_x[2];
   out_9023220350846612165[3] = -nom_x[3] + true_x[3];
   out_9023220350846612165[4] = -nom_x[4] + true_x[4];
   out_9023220350846612165[5] = -nom_x[5] + true_x[5];
   out_9023220350846612165[6] = -nom_x[6] + true_x[6];
   out_9023220350846612165[7] = -nom_x[7] + true_x[7];
   out_9023220350846612165[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_3101490908086573992) {
   out_3101490908086573992[0] = 1.0;
   out_3101490908086573992[1] = 0.0;
   out_3101490908086573992[2] = 0.0;
   out_3101490908086573992[3] = 0.0;
   out_3101490908086573992[4] = 0.0;
   out_3101490908086573992[5] = 0.0;
   out_3101490908086573992[6] = 0.0;
   out_3101490908086573992[7] = 0.0;
   out_3101490908086573992[8] = 0.0;
   out_3101490908086573992[9] = 0.0;
   out_3101490908086573992[10] = 1.0;
   out_3101490908086573992[11] = 0.0;
   out_3101490908086573992[12] = 0.0;
   out_3101490908086573992[13] = 0.0;
   out_3101490908086573992[14] = 0.0;
   out_3101490908086573992[15] = 0.0;
   out_3101490908086573992[16] = 0.0;
   out_3101490908086573992[17] = 0.0;
   out_3101490908086573992[18] = 0.0;
   out_3101490908086573992[19] = 0.0;
   out_3101490908086573992[20] = 1.0;
   out_3101490908086573992[21] = 0.0;
   out_3101490908086573992[22] = 0.0;
   out_3101490908086573992[23] = 0.0;
   out_3101490908086573992[24] = 0.0;
   out_3101490908086573992[25] = 0.0;
   out_3101490908086573992[26] = 0.0;
   out_3101490908086573992[27] = 0.0;
   out_3101490908086573992[28] = 0.0;
   out_3101490908086573992[29] = 0.0;
   out_3101490908086573992[30] = 1.0;
   out_3101490908086573992[31] = 0.0;
   out_3101490908086573992[32] = 0.0;
   out_3101490908086573992[33] = 0.0;
   out_3101490908086573992[34] = 0.0;
   out_3101490908086573992[35] = 0.0;
   out_3101490908086573992[36] = 0.0;
   out_3101490908086573992[37] = 0.0;
   out_3101490908086573992[38] = 0.0;
   out_3101490908086573992[39] = 0.0;
   out_3101490908086573992[40] = 1.0;
   out_3101490908086573992[41] = 0.0;
   out_3101490908086573992[42] = 0.0;
   out_3101490908086573992[43] = 0.0;
   out_3101490908086573992[44] = 0.0;
   out_3101490908086573992[45] = 0.0;
   out_3101490908086573992[46] = 0.0;
   out_3101490908086573992[47] = 0.0;
   out_3101490908086573992[48] = 0.0;
   out_3101490908086573992[49] = 0.0;
   out_3101490908086573992[50] = 1.0;
   out_3101490908086573992[51] = 0.0;
   out_3101490908086573992[52] = 0.0;
   out_3101490908086573992[53] = 0.0;
   out_3101490908086573992[54] = 0.0;
   out_3101490908086573992[55] = 0.0;
   out_3101490908086573992[56] = 0.0;
   out_3101490908086573992[57] = 0.0;
   out_3101490908086573992[58] = 0.0;
   out_3101490908086573992[59] = 0.0;
   out_3101490908086573992[60] = 1.0;
   out_3101490908086573992[61] = 0.0;
   out_3101490908086573992[62] = 0.0;
   out_3101490908086573992[63] = 0.0;
   out_3101490908086573992[64] = 0.0;
   out_3101490908086573992[65] = 0.0;
   out_3101490908086573992[66] = 0.0;
   out_3101490908086573992[67] = 0.0;
   out_3101490908086573992[68] = 0.0;
   out_3101490908086573992[69] = 0.0;
   out_3101490908086573992[70] = 1.0;
   out_3101490908086573992[71] = 0.0;
   out_3101490908086573992[72] = 0.0;
   out_3101490908086573992[73] = 0.0;
   out_3101490908086573992[74] = 0.0;
   out_3101490908086573992[75] = 0.0;
   out_3101490908086573992[76] = 0.0;
   out_3101490908086573992[77] = 0.0;
   out_3101490908086573992[78] = 0.0;
   out_3101490908086573992[79] = 0.0;
   out_3101490908086573992[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_8677058726288657801) {
   out_8677058726288657801[0] = state[0];
   out_8677058726288657801[1] = state[1];
   out_8677058726288657801[2] = state[2];
   out_8677058726288657801[3] = state[3];
   out_8677058726288657801[4] = state[4];
   out_8677058726288657801[5] = dt*(stiffness_front*(-state[2] - state[3] + state[7])*state[0]/state[1] + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/state[4] + ((-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/state[4] - state[4])*state[6] - 9.8100000000000005*state[8]) + state[5];
   out_8677058726288657801[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_8677058726288657801[7] = state[7];
   out_8677058726288657801[8] = state[8];
}
void F_fun(double *state, double dt, double *out_5446818266059794529) {
   out_5446818266059794529[0] = 1;
   out_5446818266059794529[1] = 0;
   out_5446818266059794529[2] = 0;
   out_5446818266059794529[3] = 0;
   out_5446818266059794529[4] = 0;
   out_5446818266059794529[5] = 0;
   out_5446818266059794529[6] = 0;
   out_5446818266059794529[7] = 0;
   out_5446818266059794529[8] = 0;
   out_5446818266059794529[9] = 0;
   out_5446818266059794529[10] = 1;
   out_5446818266059794529[11] = 0;
   out_5446818266059794529[12] = 0;
   out_5446818266059794529[13] = 0;
   out_5446818266059794529[14] = 0;
   out_5446818266059794529[15] = 0;
   out_5446818266059794529[16] = 0;
   out_5446818266059794529[17] = 0;
   out_5446818266059794529[18] = 0;
   out_5446818266059794529[19] = 0;
   out_5446818266059794529[20] = 1;
   out_5446818266059794529[21] = 0;
   out_5446818266059794529[22] = 0;
   out_5446818266059794529[23] = 0;
   out_5446818266059794529[24] = 0;
   out_5446818266059794529[25] = 0;
   out_5446818266059794529[26] = 0;
   out_5446818266059794529[27] = 0;
   out_5446818266059794529[28] = 0;
   out_5446818266059794529[29] = 0;
   out_5446818266059794529[30] = 1;
   out_5446818266059794529[31] = 0;
   out_5446818266059794529[32] = 0;
   out_5446818266059794529[33] = 0;
   out_5446818266059794529[34] = 0;
   out_5446818266059794529[35] = 0;
   out_5446818266059794529[36] = 0;
   out_5446818266059794529[37] = 0;
   out_5446818266059794529[38] = 0;
   out_5446818266059794529[39] = 0;
   out_5446818266059794529[40] = 1;
   out_5446818266059794529[41] = 0;
   out_5446818266059794529[42] = 0;
   out_5446818266059794529[43] = 0;
   out_5446818266059794529[44] = 0;
   out_5446818266059794529[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/state[1] + (-stiffness_front - stiffness_rear)*state[5]/state[4] + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/state[4]);
   out_5446818266059794529[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/pow(state[1], 2);
   out_5446818266059794529[47] = -dt*stiffness_front*state[0]/state[1];
   out_5446818266059794529[48] = -dt*stiffness_front*state[0]/state[1];
   out_5446818266059794529[49] = dt*(-(-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/pow(state[4], 2) + (-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/pow(state[4], 2) - 1)*state[6]);
   out_5446818266059794529[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/state[4] + 1;
   out_5446818266059794529[51] = dt*((-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/state[4] - state[4]);
   out_5446818266059794529[52] = dt*stiffness_front*state[0]/state[1];
   out_5446818266059794529[53] = -9.8100000000000005*dt;
   out_5446818266059794529[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_5446818266059794529[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_5446818266059794529[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_5446818266059794529[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_5446818266059794529[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_5446818266059794529[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_5446818266059794529[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_5446818266059794529[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_5446818266059794529[62] = 0;
   out_5446818266059794529[63] = 0;
   out_5446818266059794529[64] = 0;
   out_5446818266059794529[65] = 0;
   out_5446818266059794529[66] = 0;
   out_5446818266059794529[67] = 0;
   out_5446818266059794529[68] = 0;
   out_5446818266059794529[69] = 0;
   out_5446818266059794529[70] = 1;
   out_5446818266059794529[71] = 0;
   out_5446818266059794529[72] = 0;
   out_5446818266059794529[73] = 0;
   out_5446818266059794529[74] = 0;
   out_5446818266059794529[75] = 0;
   out_5446818266059794529[76] = 0;
   out_5446818266059794529[77] = 0;
   out_5446818266059794529[78] = 0;
   out_5446818266059794529[79] = 0;
   out_5446818266059794529[80] = 1;
}
void h_25(double *state, double *unused, double *out_3296569336439321591) {
   out_3296569336439321591[0] = state[6];
}
void H_25(double *state, double *unused, double *out_820152171234637209) {
   out_820152171234637209[0] = 0;
   out_820152171234637209[1] = 0;
   out_820152171234637209[2] = 0;
   out_820152171234637209[3] = 0;
   out_820152171234637209[4] = 0;
   out_820152171234637209[5] = 0;
   out_820152171234637209[6] = 1;
   out_820152171234637209[7] = 0;
   out_820152171234637209[8] = 0;
}
void h_24(double *state, double *unused, double *out_715430406046052225) {
   out_715430406046052225[0] = state[4];
   out_715430406046052225[1] = state[5];
}
void H_24(double *state, double *unused, double *out_5640473675890625472) {
   out_5640473675890625472[0] = 0;
   out_5640473675890625472[1] = 0;
   out_5640473675890625472[2] = 0;
   out_5640473675890625472[3] = 0;
   out_5640473675890625472[4] = 1;
   out_5640473675890625472[5] = 0;
   out_5640473675890625472[6] = 0;
   out_5640473675890625472[7] = 0;
   out_5640473675890625472[8] = 0;
   out_5640473675890625472[9] = 0;
   out_5640473675890625472[10] = 0;
   out_5640473675890625472[11] = 0;
   out_5640473675890625472[12] = 0;
   out_5640473675890625472[13] = 0;
   out_5640473675890625472[14] = 1;
   out_5640473675890625472[15] = 0;
   out_5640473675890625472[16] = 0;
   out_5640473675890625472[17] = 0;
}
void h_30(double *state, double *unused, double *out_3897987494052685145) {
   out_3897987494052685145[0] = state[4];
}
void H_30(double *state, double *unused, double *out_949491118377877279) {
   out_949491118377877279[0] = 0;
   out_949491118377877279[1] = 0;
   out_949491118377877279[2] = 0;
   out_949491118377877279[3] = 0;
   out_949491118377877279[4] = 1;
   out_949491118377877279[5] = 0;
   out_949491118377877279[6] = 0;
   out_949491118377877279[7] = 0;
   out_949491118377877279[8] = 0;
}
void h_26(double *state, double *unused, double *out_2320491961731214861) {
   out_2320491961731214861[0] = state[7];
}
void H_26(double *state, double *unused, double *out_163298107124325305) {
   out_163298107124325305[0] = 0;
   out_163298107124325305[1] = 0;
   out_163298107124325305[2] = 0;
   out_163298107124325305[3] = 0;
   out_163298107124325305[4] = 0;
   out_163298107124325305[5] = 0;
   out_163298107124325305[6] = 0;
   out_163298107124325305[7] = 1;
   out_163298107124325305[8] = 0;
}
void h_27(double *state, double *unused, double *out_1705103931221524054) {
   out_1705103931221524054[0] = state[3];
}
void H_27(double *state, double *unused, double *out_3124254430178302190) {
   out_3124254430178302190[0] = 0;
   out_3124254430178302190[1] = 0;
   out_3124254430178302190[2] = 0;
   out_3124254430178302190[3] = 1;
   out_3124254430178302190[4] = 0;
   out_3124254430178302190[5] = 0;
   out_3124254430178302190[6] = 0;
   out_3124254430178302190[7] = 0;
   out_3124254430178302190[8] = 0;
}
void h_29(double *state, double *unused, double *out_1980297993506029943) {
   out_1980297993506029943[0] = state[1];
}
void H_29(double *state, double *unused, double *out_439259774063485095) {
   out_439259774063485095[0] = 0;
   out_439259774063485095[1] = 1;
   out_439259774063485095[2] = 0;
   out_439259774063485095[3] = 0;
   out_439259774063485095[4] = 0;
   out_439259774063485095[5] = 0;
   out_439259774063485095[6] = 0;
   out_439259774063485095[7] = 0;
   out_439259774063485095[8] = 0;
}
void h_28(double *state, double *unused, double *out_14656096485843094) {
   out_14656096485843094[0] = state[0];
}
void H_28(double *state, double *unused, double *out_5521658791133015669) {
   out_5521658791133015669[0] = 1;
   out_5521658791133015669[1] = 0;
   out_5521658791133015669[2] = 0;
   out_5521658791133015669[3] = 0;
   out_5521658791133015669[4] = 0;
   out_5521658791133015669[5] = 0;
   out_5521658791133015669[6] = 0;
   out_5521658791133015669[7] = 0;
   out_5521658791133015669[8] = 0;
}
void h_31(double *state, double *unused, double *out_1845937943810438424) {
   out_1845937943810438424[0] = state[8];
}
void H_31(double *state, double *unused, double *out_789506209357676781) {
   out_789506209357676781[0] = 0;
   out_789506209357676781[1] = 0;
   out_789506209357676781[2] = 0;
   out_789506209357676781[3] = 0;
   out_789506209357676781[4] = 0;
   out_789506209357676781[5] = 0;
   out_789506209357676781[6] = 0;
   out_789506209357676781[7] = 0;
   out_789506209357676781[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_7177032040242842354) {
  err_fun(nom_x, delta_x, out_7177032040242842354);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_9023220350846612165) {
  inv_err_fun(nom_x, true_x, out_9023220350846612165);
}
void car_H_mod_fun(double *state, double *out_3101490908086573992) {
  H_mod_fun(state, out_3101490908086573992);
}
void car_f_fun(double *state, double dt, double *out_8677058726288657801) {
  f_fun(state,  dt, out_8677058726288657801);
}
void car_F_fun(double *state, double dt, double *out_5446818266059794529) {
  F_fun(state,  dt, out_5446818266059794529);
}
void car_h_25(double *state, double *unused, double *out_3296569336439321591) {
  h_25(state, unused, out_3296569336439321591);
}
void car_H_25(double *state, double *unused, double *out_820152171234637209) {
  H_25(state, unused, out_820152171234637209);
}
void car_h_24(double *state, double *unused, double *out_715430406046052225) {
  h_24(state, unused, out_715430406046052225);
}
void car_H_24(double *state, double *unused, double *out_5640473675890625472) {
  H_24(state, unused, out_5640473675890625472);
}
void car_h_30(double *state, double *unused, double *out_3897987494052685145) {
  h_30(state, unused, out_3897987494052685145);
}
void car_H_30(double *state, double *unused, double *out_949491118377877279) {
  H_30(state, unused, out_949491118377877279);
}
void car_h_26(double *state, double *unused, double *out_2320491961731214861) {
  h_26(state, unused, out_2320491961731214861);
}
void car_H_26(double *state, double *unused, double *out_163298107124325305) {
  H_26(state, unused, out_163298107124325305);
}
void car_h_27(double *state, double *unused, double *out_1705103931221524054) {
  h_27(state, unused, out_1705103931221524054);
}
void car_H_27(double *state, double *unused, double *out_3124254430178302190) {
  H_27(state, unused, out_3124254430178302190);
}
void car_h_29(double *state, double *unused, double *out_1980297993506029943) {
  h_29(state, unused, out_1980297993506029943);
}
void car_H_29(double *state, double *unused, double *out_439259774063485095) {
  H_29(state, unused, out_439259774063485095);
}
void car_h_28(double *state, double *unused, double *out_14656096485843094) {
  h_28(state, unused, out_14656096485843094);
}
void car_H_28(double *state, double *unused, double *out_5521658791133015669) {
  H_28(state, unused, out_5521658791133015669);
}
void car_h_31(double *state, double *unused, double *out_1845937943810438424) {
  h_31(state, unused, out_1845937943810438424);
}
void car_H_31(double *state, double *unused, double *out_789506209357676781) {
  H_31(state, unused, out_789506209357676781);
}
void car_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
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
