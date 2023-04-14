#include <kipr/wombat.h>

int main()
{
    int x = 0;
    enable_servo(1);
    set_servo_position(1,480);
    msleep(200);
    while(analog(0)<3000)
     {
      	mav(0,1000);
    	mav(1,1000);
     }
    mav(0,1000);
    mav(1,1000);
    msleep(1200);
    printf("Turning\n");
    mav(0,-850);
    mav(1,850);
    msleep(1100);
    while( x < 2500)
     {
        if(analog(0)<3000)
    	{
        	mav(0,1100);
    		mav(1,1000);
    	}
    	else
    	{
        	mav(0,1100);
    		mav(1,1000);
    	}
        x++;
     }
    mav(0,-610);
    mav(1,610);
    msleep(700);
    printf("cube\n");
    mav(0,1100);
    mav(1,1100);
    msleep(1500);
    mav(0,0);
    mav(1,0);
    msleep(500);
    set_servo_position(1,300);
    mav(0,1100);
    mav(1,1100);
    msleep(1700);
    set_servo_position(1,0);
    mav(0,0);
    mav(1,0);
    set_servo_position(1,480);
    msleep(400);
    printf("CUBE!\n");
    mav(0,-900);
    mav(1,-900);
    msleep(2000);
    mav(0,-800);
    mav(1,800);
    msleep(2500);
    // this is the end
    set_servo_position(1,480);
    disable_servo(1);
    return 0;
}
