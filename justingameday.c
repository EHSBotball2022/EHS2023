#include <kipr/wombat.h>


// SET THE CLAW TO BE 1000
int main()
{
    enable_servos();
    int i = 0;
    
    set_servo_position(1,360);
    set_servo_position(0,1400);
    msleep(500);    
    
    // moves forward out of box
    mav(0,1500);
    mav(1,1500);
    msleep(2000);
    
    // 90 degree turn
    mav(0,-500);
    mav(1,500);
    msleep(2000);
    
    // line follow
    while(i < 45){
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
        	mav(1,1000);
            mav(0,1000);
            msleep(100);        
        }
        else{
        	mav(1,1000);
            mav(0,1000);
            msleep(100);
        }
        i++;
    }
    
    mav(0,0);
    mav(1,0);
    msleep(10);
    
    set_servo_position(0,100);
    msleep(500);
    set_servo_position(1,1500);
    msleep(500);
    
    while(i < 70){
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

    // grabs the wireshark
    set_servo_position(1,360);
    msleep(500);
    set_servo_position(0,1400);
    
    // back up a bit, then turn 180*
    mav(0,-500);
    mav(1,-500);
    msleep(3000);
    
    mav(0,500);
    mav(1,-500);
    msleep(5000);
    
    // line follow
    i = 0;
    while(i < 265){
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
        
    mav(0,0);
    mav(1,0);
    msleep(5000);
    
    set_servo_position(0,2047);
    msleep(500);  
    
    mav(0,500);
    mav(1,-500);
    msleep(4500);
    
    set_servo_position(0,100);
    msleep(500);
    set_servo_position(1,1500);
    msleep(500);
    
    mav(0,-500);
    mav(1,-500);
    msleep(1000);
    
    while(1)
    {
    	mav(0, 250);
        mav(1, -250);
        if (analog(2) >= 2700)
            break;
    }
    
    mav(0,500);
    mav(1,500);
	msleep(1000);
    
    set_servo_position(1,360);
    msleep(500);
    set_servo_position(0,1500);
    msleep(500);
    set_servo_position(0,2047);
    msleep(500);    
    return 0;
}
