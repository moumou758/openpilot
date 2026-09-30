#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void live_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_9(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_12(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_35(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_32(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_33(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_H(double *in_vec, double *out_6629208848931826692);
void live_err_fun(double *nom_x, double *delta_x, double *out_1105781810983568552);
void live_inv_err_fun(double *nom_x, double *true_x, double *out_8317358201382032893);
void live_H_mod_fun(double *state, double *out_6704039319207999339);
void live_f_fun(double *state, double dt, double *out_528916182274031360);
void live_F_fun(double *state, double dt, double *out_1036049331191296893);
void live_h_4(double *state, double *unused, double *out_3579172152000045781);
void live_H_4(double *state, double *unused, double *out_5129734869626349589);
void live_h_9(double *state, double *unused, double *out_3399355132212928636);
void live_H_9(double *state, double *unused, double *out_6029790268818754557);
void live_h_10(double *state, double *unused, double *out_8070402578888577633);
void live_H_10(double *state, double *unused, double *out_8833494426128869197);
void live_h_12(double *state, double *unused, double *out_7028008153790991303);
void live_H_12(double *state, double *unused, double *out_8297552796051240232);
void live_h_35(double *state, double *unused, double *out_5809373015691805790);
void live_H_35(double *state, double *unused, double *out_8496396926998956965);
void live_h_32(double *state, double *unused, double *out_7496786111432112193);
void live_H_32(double *state, double *unused, double *out_7245322633808844714);
void live_h_13(double *state, double *unused, double *out_1913475456093440476);
void live_H_13(double *state, double *unused, double *out_2991993501322906033);
void live_h_14(double *state, double *unused, double *out_3399355132212928636);
void live_H_14(double *state, double *unused, double *out_6029790268818754557);
void live_h_33(double *state, double *unused, double *out_8581910634778994170);
void live_H_33(double *state, double *unused, double *out_6799790142071737047);
void live_predict(double *in_x, double *in_P, double *in_Q, double dt);
}