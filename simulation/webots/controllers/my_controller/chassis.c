#include "webots/robot.h"
#include "chassis.h"
#include "my_robot.h"
#include <stdio.h>

chassis_move_t chassis_move;

void chassis_task()
{
    // chassis_init();

    chassis_feedback_update(&chassis_move);

    chassis_set_control(&chassis_move);

    chassis_control_loop(&chassis_move);
    
    // printf("left_T:%.2f  right_T:%.2f\r\n",&chassis_move.motor_chassis[0].torque_set, &chassis_move.motor_chassis[1].torque_set);

}

void chassis_control_loop(chassis_move_t *chassis_move_control_loop)
{
    float max_torque = 0.0f, torque_rate = 0.0f;
    float temp = 0.0f;

    chassis_move_control_loop->motor_chassis[0].torque_set = 
    (K11 * chassis_move_control_loop->chassis_pitch + K12 * chassis_move_control_loop->chassis_pitch_speed     
    + K13 * chassis_move_control_loop->vx + K14 * chassis_move_control_loop->vx                                   
    + K15 * chassis_move_control_loop->chassis_pitch + K16 * chassis_move_control_loop->chassis_pitch_speed);

    chassis_move_control_loop->motor_chassis[1].torque_set = 
    -(K11 * chassis_move_control_loop->chassis_pitch + K12 * chassis_move_control_loop->chassis_pitch_speed     
    + K13 * chassis_move_control_loop->vx + K14 * chassis_move_control_loop->vx                                   
    + K15 * chassis_move_control_loop->chassis_pitch + K16 * chassis_move_control_loop->chassis_pitch_speed);

    // printf("left_T:%.2f   right_T:%.2f\r\n",chassis_move_control_loop->motor_chassis[0].torque_set,chassis_move_control_loop->motor_chassis[1].torque_set);
    wb_motor_set_torque(robot.motor.left,chassis_move_control_loop->motor_chassis[1].torque_set/10.0f);
    wb_motor_set_torque(robot.motor.right,chassis_move_control_loop->motor_chassis[0].torque_set/10.0f);
}


void chassis_feedback_update(chassis_move_t *chassis_feedback)
{

    for(int i = 0; i < 2; i++)
    {
        chassis_feedback->chassis_roll  = robot.pps.roll;
        chassis_feedback->chassis_pitch = robot.pps.pitch;
        chassis_feedback->chassis_yaw   = robot.pps.yaw;

        chassis_feedback->chassis_roll_speed  = robot.pps.droll;
        chassis_feedback->chassis_pitch_speed = robot.pps.dpitch;
        chassis_feedback->chassis_yaw_speed   = robot.pps.dyaw;
        chassis_feedback->vx = robot.pps.dx;
        // printf("chassis_roll:%.2f  chassis_pitch:%.2f  chassis_yaw:%.2f  chassis_droll:%.2f  chassis_dpitch:%.2f  chassis_dyaw:%.2f  chassis_dx:%.2f\r\n",
        // chassis_feedback->chassis_roll,chassis_feedback->chassis_pitch,chassis_feedback->chassis_yaw,                               
        // chassis_feedback->chassis_roll_speed,chassis_feedback->chassis_pitch_speed,chassis_feedback->chassis_yaw_speed,chassis_feedback->vx);
    }
}

void chassis_set_control(chassis_move_t *chassis_set_control)
{

    float vx_set = 0.0f;
    float w_set = 0.0f;

    chassis_set_control->delta_angle = 0.0f;
    chassis_set_control->chassis_yaw_set = w_set;
    chassis_set_control->delta_angle = chassis_set_control->chassis_yaw_set - chassis_set_control->chassis_yaw;
    chassis_set_control->vx = vx_set;

    
}

