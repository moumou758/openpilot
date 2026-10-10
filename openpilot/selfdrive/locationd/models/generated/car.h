#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_err_fun(double *nom_x, double *delta_x, double *out_846970993423390905);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_7688258081560496824);
void car_H_mod_fun(double *state, double *out_3454494615608712148);
void car_f_fun(double *state, double dt, double *out_1518223738615346199);
void car_F_fun(double *state, double dt, double *out_6380082957886893439);
void car_h_25(double *state, double *unused, double *out_4349936716124263382);
void car_H_25(double *state, double *unused, double *out_5738693610303525089);
void car_h_24(double *state, double *unused, double *out_8925951289511795298);
void car_H_24(double *state, double *unused, double *out_7911343209309024655);
void car_h_30(double *state, double *unused, double *out_5456929880866746350);
void car_H_30(double *state, double *unused, double *out_5868032557446765159);
void car_h_26(double *state, double *unused, double *out_8493715932311079035);
void car_H_26(double *state, double *unused, double *out_8966547144531970303);
void car_h_27(double *state, double *unused, double *out_4670606696316213060);
void car_H_27(double *state, double *unused, double *out_8042795869247190070);
void car_h_29(double *state, double *unused, double *out_4513420027965083915);
void car_H_29(double *state, double *unused, double *out_8690585477592810513);
void car_h_28(double *state, double *unused, double *out_1633820644871880375);
void car_H_28(double *state, double *unused, double *out_7792528324551414852);
void car_h_31(double *state, double *unused, double *out_606260633629138474);
void car_H_31(double *state, double *unused, double *out_5708047648426564661);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}