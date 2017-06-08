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
* Functions needed in order to make a functioning example of the USM propagator in action.
*/
//------------------------------------------------------------------------------
#include "aux_fun.h"
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>


//---------------------------------
// public methods
//---------------------------------

//------------------------------------------------------------------------------
// double arg_lat(double eccentricity_in, double mean_anomaly_in, double arg_perigee_in)
//------------------------------------------------------------------------------
/**
* This routine takes the Eccentricity, Mean Anomaly and Argument of Perigee Keplerian elements
* to calculate the Argument of Latitude.
*
* @param <eccentricity_in> the eccentrity.
* @param <mean_anomaly_in> the mean anormality on radians.
* @param <arg_perigee_in> the perigee on radians.
*
* @return the latitude on radians.
*/
//------------------------------------------------------------------------------
double arg_lat(double eccentricity_in, double mean_anomaly_in, double arg_perigee_in)
{
    double e = eccentricity_in;
    double error = 1;
    double E = mean_anomaly_in;
    double EE;
    while(error > pow(10, -12))
    {
        EE = E-((E-mean_anomaly_in-e*sin(E))/(1-e*cos(E)));
        error = abs(EE-E);
        E = EE;
    }
    double f = 2*atan(sqrt((1+e)/(1-e))*tan(E/2));
    return f+arg_perigee_in;
}

//------------------------------------------------------------------------------
// int get_elset_input(char * filename_in, double * epoch_in,int * object_in,int * rev_num_in,
//                     double * step_size_in_days,int * number_of_steps,double * semimajor_axis_earth_radii,
//                     double * inclination_deg, double * ra_asc_node_deg,double * eccentricity,
//                     double * arg_perigee_deg,double * mean_anomaly_deg, double * ballistic_coef,
//                     int * prmodel,int * pock, int * pzadachi, int * output_type)
//------------------------------------------------------------------------------
/**
* This method reeds the parameters from the expecifed file.
*
* @param <filename_in> filename from which to get the parameters.
* @param <epoch_in> the Modified Julian Day.
* @param <object_in> the object number.
* @param <rev_num_in> the revolution number.
* @param <step_size_in_days> fraction of a day to make each step.
* @param <number_of_steps> number of steps to propagate for.
* @param <semimajor_axis_earth_radii> the value of the semimajor axis of earth on radians.
* @param <inclination_deg> the inclination on degrees.
* @param <ra_asc_node_deg> the ra asc node.
* @param <eccentricity> the eccentricity.
* @param <arg_perigee_deg> the perigee.
* @param <mean_anomaly_deg> the mean anomaly.
* @param <ballistic_coef> the ballistic coeficent.
* @param <prmodel> this is the model switch passed to the bxprog structure passed to PROGNOZ.
* @param <pock> this is the in/out type switch passed to the bxprog structure passed to PROGNOZ.
* @param <pzadachi> this is another switch used in the bxprog structure..
* @param <output_type> the output type.
*
* @return 0 if read sucess or 1 if not.
*/
//------------------------------------------------------------------------------
int get_elset_input(char * filename_in, double * epoch_in,int * object_in,int * rev_num_in,double * step_size_in_days,int * number_of_steps,double * semimajor_axis_earth_radii,double * inclination_deg, 	double * ra_asc_node_deg,double * eccentricity,double * arg_perigee_deg,double * mean_anomaly_deg, double * ballistic_coef, int * prmodel,int * pock, int * pzadachi, int * output_type)
{
    FILE * archivo = fopen(filename_in, "r");
    if(archivo == NULL)
    {
        return 1;
    }
    else
    {
        fscanf(archivo, "epoch_in %lf \n", epoch_in);
        fscanf(archivo, "object_in %d \n", object_in);
        fscanf(archivo, "rev_num_in %d \n", rev_num_in);
        fscanf(archivo, "step_size_in_days %lf \n", step_size_in_days);
        fscanf(archivo, "number_of_steps %d \n", number_of_steps);
        fscanf(archivo, "semimajor_axis_km %lf \n", semimajor_axis_earth_radii);
        fscanf(archivo, "inclination_deg %lf \n", inclination_deg);
        fscanf(archivo, "ra_asc_node_deg %lf \n", ra_asc_node_deg);
        fscanf(archivo, "eccentricity %lf \n", eccentricity);
        fscanf(archivo, "arg_perigee_deg %lf \n", arg_perigee_deg);
        fscanf(archivo, "mean_anomaly_deg %lf \n", mean_anomaly_deg);
        fscanf(archivo, "ballistic_coef %lf \n", ballistic_coef);
        fscanf(archivo, "pock %d \n", pock);
        fscanf(archivo, "pzadachi %d \n", pzadachi);
        fscanf(archivo, "output_type %d \n", output_type);
        fscanf(archivo, "prmodel %d \n", prmodel);
    }
    fclose(archivo);
    return 0;
}

