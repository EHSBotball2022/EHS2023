#include <kipr/wombat.h>

int main()
{
    enable_servos();
    int i = 0;
    
    // moves forward out of box
    mav(0,750);
    mav(1,750);
    msleep(4000);
    
    // 90 degree turn
    mav(0,-500);
    mav(1,500);
    msleep(2000);
    
    // line follow
    while(i < 125){
        if(analog(0) > 700 && analog(1) < 700){
            mav(1,1000);
            mav(0,-500);
            msleep(100);
        }
        else if(analog(1) > 700 && analog(0) < 700){
            mav(1,-500);
            mav(0,1000);
            msleep(100);
        }
        else if(analog(0) > 700 && analog(1) > 700){
        	mav(1,500);
            mav(0,500);
            msleep(100);        
        }
        else{
        	mav(1,500);
            mav(0,500);
            msleep(100);
        }
        i++;
    }
    
    mav(0,0);
    mav(1,0);
    msleep(1000);
    
    // grabs the wireshark
    set_servo_position(0,500);
    msleep(500);
    set_servo_position(1,360);
    msleep(500);
    set_servo_position(0,1500);
    
    // back up a bit, then turn 180*
    mav(0,-100);
    mav(1,-100);
    msleep(1000);
    
    mav(0,500);
    mav(1,-500);
    msleep(4500);
    
    // line follow
    i = 0;
    while(i < 300){
        if(analog(0) > 700 && analog(1) < 700){
            mav(1,1000);
            mav(0,-500);
            msleep(100);
        }
        else if(analog(1) > 700 && analog(0) < 700){
            mav(1,-500);
            mav(0,1000);
            msleep(100);
        }
        else if(analog(0) > 700 && analog(1) > 700){
        	mav(1,500);
            mav(0,500);
            msleep(100);        
        }
        else{
        	mav(1,500);
            mav(0,500);
            msleep(100);
        }
        i++;
    }
    
    // back up too the rings
    mav(0,-100);
    mav(1,-100);
    msleep(3000);
    return 0;
}
