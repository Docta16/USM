//$Header$
//------------------------------------------------------------------------------
// aux_fun
//------------------------------------------------------------------------------
// USM
//
// Author: Enrique Miguel Gil
// Created: 2003/04/06
//
/**
* This header file contains auxiliary routine prototypes for functions
* needed in order to make a functioning example of the USM propagator in action.
*/
//------------------------------------------------------------------------------
#ifndef AUX_FUN
#define AUX_FUN

double arg_lat(double eccentricity_in,
               double mean_anomaly_in,
               double arg_perigee_in);


int get_elset_input(char * filename_in,
                    double * epoch_in,
                    int * object_in,
                    int * rev_num_in,
                    double * step_size_in_days,
                    int * number_of_steps,
                    double * semimajor_axis_earth_radii,
                    double * inclination_deg,
                    double * ra_asc_node_deg,
                    double * eccentricity,
                    double * arg_perigee_deg,
                    double * mean_anomaly_deg,
                    double * ballistic_coef,
                    int * prmodel,
                    int * pock,
                    int * pzadachi,
                    int * output_type);

#endif /* AUX_FUN*/
