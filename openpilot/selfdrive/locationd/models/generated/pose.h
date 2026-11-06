#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_1736746612172014874);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_2621334881021189822);
void pose_H_mod_fun(double *state, double *out_976235760463129040);
void pose_f_fun(double *state, double dt, double *out_8570715647887041589);
void pose_F_fun(double *state, double dt, double *out_9195171490393905022);
void pose_h_4(double *state, double *unused, double *out_1784252823533360007);
void pose_H_4(double *state, double *unused, double *out_4748042970307036612);
void pose_h_10(double *state, double *unused, double *out_2498286068008923995);
void pose_H_10(double *state, double *unused, double *out_2995414732378888264);
void pose_h_13(double *state, double *unused, double *out_2216808697285544655);
void pose_H_13(double *state, double *unused, double *out_7960316795639369413);
void pose_h_14(double *state, double *unused, double *out_4203114798521230693);
void pose_H_14(double *state, double *unused, double *out_8711283826646521141);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}