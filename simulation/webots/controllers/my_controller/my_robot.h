#ifndef _ROBOT_H
#define _ROBOT_H


#include "webots/motor.h"
#include "webots/robot.h"
#include "webots/inertial_unit.h"
#include "webots/accelerometer.h"
#include "webots/gyro.h"

typedef struct 
{
    /* data */
    WbDeviceTag left,right;
    WbDeviceTag lf,lr,rf,rr;
    
} Motor_s;


typedef struct 
{
    /* data */
    float x,y,z;
    float dx,dy,dz;
    float ddx,ddy,ddz;
    float roll,pitch,yaw;
    float droll,dpitch,dyaw;
    WbDeviceTag imu;
    WbDeviceTag acc;
    WbDeviceTag gyro;
} PPS_s;



typedef struct 
{
    /* data */
    Motor_s motor;
    PPS_s pps;
}Robot_s;



extern Robot_s robot;
void robot_setup(void);
void pps_setup();
void motor_setup(void);

void robot_update();


#endif

