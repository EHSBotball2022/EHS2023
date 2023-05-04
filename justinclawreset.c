#include <kipr/wombat.h>

int main()
{
    enable_servos();
    if (digital(0) == 0)
    {
        set_servo_position(0,1500);
        msleep(500);
        set_servo_position(1,500);
    	msleep(500);
    }
    else
    {
        set_servo_position(0,100);
        msleep(500);
        set_servo_position(1,1500);
        msleep(500);
    }
        
    printf("done w/ reset\n");
    return 0;
}
