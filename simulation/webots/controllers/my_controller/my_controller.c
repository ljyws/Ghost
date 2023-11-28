/*
 * @Author: ljyws 945706034@qq,com
 * @Date: 2023-03-22 17:43:41
 * @LastEditors: ljyws 945706034@qq,com
 * @LastEditTime: 2023-03-24 15:03:49
 * @FilePath: \controllers\my_controller\my_controller.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

#include <webots/robot.h>
#include "my_robot.h"
#include "chassis.h"
/*
 * You may want to add macros here.
 */
#define TIME_STEP 64


int main(int argc, char **argv) 
{
  /* necessary to initialize webots stuff */
  wb_robot_init();
  robot_setup();

  while (wb_robot_step(TIME_STEP) != -1) 
  {
    robot_update();
    chassis_task();
  };

  /* Enter your cleanup code here */

  /* This is necessary to cleanup webots resources */
  wb_robot_cleanup();

  return 0;
}
