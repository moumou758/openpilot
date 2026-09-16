#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_5153672272046342551);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_7756557426239194035);
void pose_H_mod_fun(double *state, double *out_1488824774377298388);
void pose_f_fun(double *state, double dt, double *out_3252374166331305954);
void pose_F_fun(double *state, double dt, double *out_7799911489866690446);
void pose_h_4(double *state, double *unused, double *out_3548480780703373814);
void pose_H_4(double *state, double *unused, double *out_9039098698091417951);
void pose_h_10(double *state, double *unused, double *out_6772598767194441225);
void pose_H_10(double *state, double *unused, double *out_4194114852527038040);
void pose_h_13(double *state, double *unused, double *out_781619376527489648);
void pose_H_13(double *state, double *unused, double *out_5826824872759085150);
void pose_h_14(double *state, double *unused, double *out_5521513375942515480);
void pose_H_14(double *state, double *unused, double *out_6324856943322761369);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}