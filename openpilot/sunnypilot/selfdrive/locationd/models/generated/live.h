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
void live_H(double *in_vec, double *out_2101522381924775217);
void live_err_fun(double *nom_x, double *delta_x, double *out_799235330131850129);
void live_inv_err_fun(double *nom_x, double *true_x, double *out_4745567687862396812);
void live_H_mod_fun(double *state, double *out_4916168446750896640);
void live_f_fun(double *state, double dt, double *out_4971401614517168168);
void live_F_fun(double *state, double dt, double *out_5267012482179951648);
void live_h_4(double *state, double *unused, double *out_8156968150995158674);
void live_H_4(double *state, double *unused, double *out_4490620315044427338);
void live_h_9(double *state, double *unused, double *out_2575332847129826803);
void live_H_9(double *state, double *unused, double *out_8647788051399204821);
void live_h_10(double *state, double *unused, double *out_6233836800055802419);
void live_H_10(double *state, double *unused, double *out_6813882551036620619);
void live_h_12(double *state, double *unused, double *out_3640338182763508246);
void live_H_12(double *state, double *unused, double *out_3869521289996833671);
void live_h_35(double *state, double *unused, double *out_3170577463989375468);
void live_H_35(double *state, double *unused, double *out_1123958257671819962);
void live_h_32(double *state, double *unused, double *out_8850440190430286905);
void live_H_32(double *state, double *unused, double *out_4677346114535792596);
void live_h_13(double *state, double *unused, double *out_5775898568646839721);
void live_H_13(double *state, double *unused, double *out_4434099427308081868);
void live_h_14(double *state, double *unused, double *out_2575332847129826803);
void live_H_14(double *state, double *unused, double *out_8647788051399204821);
void live_h_33(double *state, double *unused, double *out_3005598157591934958);
void live_H_33(double *state, double *unused, double *out_2026598746967037642);
void live_predict(double *in_x, double *in_P, double *in_Q, double dt);
}