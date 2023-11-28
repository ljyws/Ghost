#include "webots/robot.h"
#include "my_robot.h"
#include "stdio.h"
Robot_s robot;

void robot_setup()
{
    pps_setup();
    motor_setup();
}

void motor_setup()
{
    robot.motor.left  = wb_robot_get_device("left");
    robot.motor.right = wb_robot_get_device("right");
    robot.motor.lf    = wb_robot_get_device("lf1");
    robot.motor.lr    = wb_robot_get_device("lr1");
    robot.motor.rf    = wb_robot_get_device("rf1");
    robot.motor.rr    = wb_robot_get_device("rr1");

    wb_motor_set_position(robot.motor.left,INFINITY);
    wb_motor_set_position(robot.motor.right,INFINITY);
    wb_motor_set_position(robot.motor.lf,0);
    wb_motor_set_position(robot.motor.lr,0);
    wb_motor_set_position(robot.motor.rf,0);
    wb_motor_set_position(robot.motor.rr,0);

    wb_motor_set_velocity(robot.motor.left,0);
    wb_motor_set_velocity(robot.motor.right,0);

}

void pps_setup()
{
    robot.pps.imu = wb_robot_get_device("inertial_unit");
    robot.pps.acc = wb_robot_get_device("acc");
    robot.pps.gyro = wb_robot_get_device("gyro");

    wb_inertial_unit_enable(robot.pps.imu,32);
    wb_accelerometer_enable(robot.pps.acc,32);
    wb_gyro_enable(robot.pps.gyro,32);
}                                                                                                                  

void robot_update()
{
    robot.pps.pitch  = wb_inertial_unit_get_roll_pitch_yaw(robot.pps.imu)[0];
    robot.pps.roll   = wb_inertial_unit_get_roll_pitch_yaw(robot.pps.imu)[1];
    robot.pps.yaw    = wb_inertial_unit_get_roll_pitch_yaw(robot.pps.imu)[2];

    robot.pps.dpitch = wb_gyro_get_values(robot.pps.gyro)[0];
    robot.pps.droll  = wb_gyro_get_values(robot.pps.gyro)[1];
    robot.pps.dyaw   = wb_gyro_get_values(robot.pps.gyro)[2];

    robot.pps.ddx = wb_accelerometer_get_values(robot.pps.acc)[0];
    robot.pps.ddy = wb_accelerometer_get_values(robot.pps.acc)[1];
    robot.pps.ddz = wb_accelerometer_get_values(robot.pps.acc)[2];

    robot.pps.dx += robot.pps.ddx;
    robot.pps.dy += robot.pps.ddy;
    robot.pps.dz += robot.pps.ddz;


}