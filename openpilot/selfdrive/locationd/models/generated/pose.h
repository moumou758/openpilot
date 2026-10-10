#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_7734263280416187077);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_6670314649637788989);
void pose_H_mod_fun(double *state, double *out_6269518418037593252);
void pose_f_fun(double *state, double dt, double *out_3363277910375281634);
void pose_F_fun(double *state, double dt, double *out_3554420891246199959);
void pose_h_4(double *state, double *unused, double *out_7237947965692212456);
void pose_H_4(double *state, double *unused, double *out_3439029423588969226);
void pose_h_10(double *state, double *unused, double *out_2371083028992154474);
void pose_H_10(double *state, double *unused, double *out_38933642061620654);
void pose_h_13(double *state, double *unused, double *out_7386501727190268544);
void pose_H_13(double *state, double *unused, double *out_226755598256636425);
void pose_h_14(double *state, double *unused, double *out_2463349857534616744);
void pose_H_14(double *state, double *unused, double *out_6521817855884341522);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}