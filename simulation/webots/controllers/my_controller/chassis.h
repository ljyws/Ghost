#ifndef _CHASSIS_H
#define _CHASSIS_H


#define K11 1.4577f
#define K12 2.0092f
#define K13 2.2112f
#define K14 -30.7266f
#define K15 10.4255f
#define K16 2.2108f
#define K21 2.6778f
#define K22 0.7911f
#define K23 5.2914f
#define K24 0.3484f
#define K25 2.9221f
#define K26 0.1290f

typedef struct
{

  float speed;           //电机轮轴位移速度
  float omg;             //电机输出轴旋转速度
  float torque;          //电机输出力矩
  float torque_set;      //电机输出力矩设定值

} chassis_motor_t;

//底盘运动数据结构体
typedef struct
{

  chassis_motor_t motor_chassis[2];          //底盘电机数据

  float vx;                          //底盘速度，前进为正后退为负，单位m/s
  float omg;                         //底盘合成轮的角速度，单位rad/s
  float vx_set;                      //底盘速度设定值，前进为正后退为负，单位m/s
  float chassis_yaw_set;             //底盘yaw轴角度设定值
  float delta_angle;                 //底盘yaw轴角度设定值与yaw轴角度当前值之差

  float vx_max_speed;                //前进方向最大速度，单位m/s
  float vx_min_speed;                //后退方向最大速度，单位m/s
  float chassis_yaw;                 //底盘陀螺仪反馈的当前yaw角度
  float chassis_pitch;               //底盘陀螺仪反馈的当前pitch角度
  float chassis_roll;                //底盘陀螺仪反馈的当前roll角度
  float chassis_yaw_speed;           //底盘陀螺仪反馈的当前yaw角速度
	float chassis_pitch_speed;         //底盘陀螺仪反馈的当前pitch角速度
	float chassis_roll_speed;          //底盘陀螺仪反馈的当前roll角速度
} chassis_move_t;

void chassis_task(void);

void chassis_control_loop(chassis_move_t *chassis_move_control_loop);

void chassis_feedback_update(chassis_move_t *chassis_feedback);

void chassis_set_control(chassis_move_t *chassis_set_control);



#endif

