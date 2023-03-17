
#include <webots/robot.h>
#include <webots/motor.h>


#define TIME_STEP 64


int main(int argc, char **argv) 
{

  wb_robot_init();

  while (wb_robot_step(TIME_STEP) != -1) 
  {

  };

  /* Enter your cleanup code here */

  /* This is necessary to cleanup webots resources */
  wb_robot_cleanup();

  return 0;
}
