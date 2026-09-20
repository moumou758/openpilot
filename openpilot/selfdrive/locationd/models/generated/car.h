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
void car_err_fun(double *nom_x, double *delta_x, double *out_865702802355291203);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_2817795773869963671);
void car_H_mod_fun(double *state, double *out_6495550314774613536);
void car_f_fun(double *state, double dt, double *out_4170096922626973971);
void car_F_fun(double *state, double dt, double *out_4322574903008772197);
void car_h_25(double *state, double *unused, double *out_1540359977116304995);
void car_H_25(double *state, double *unused, double *out_1591858489589948696);
void car_h_24(double *state, double *unused, double *out_1148075365840781748);
void car_H_24(double *state, double *unused, double *out_4983713317001569405);
void car_h_30(double *state, double *unused, double *out_4488085967471789956);
void car_H_30(double *state, double *unused, double *out_5324831851901668059);
void car_h_26(double *state, double *unused, double *out_5431595820373452391);
void car_H_26(double *state, double *unused, double *out_5333361808464004920);
void car_h_27(double *state, double *unused, double *out_9102504662797570986);
void car_H_27(double *state, double *unused, double *out_3150068540101243148);
void car_h_29(double *state, double *unused, double *out_8956984838576916015);
void car_H_29(double *state, double *unused, double *out_1436705813231692115);
void car_h_28(double *state, double *unused, double *out_4100831395136725341);
void car_H_28(double *state, double *unused, double *out_3645693203837838459);
void car_h_31(double *state, double *unused, double *out_6340912673637744190);
void car_H_31(double *state, double *unused, double *out_1561212527712988268);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}