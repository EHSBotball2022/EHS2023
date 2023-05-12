#include <kipr/wombat.h>
#include <stdlib.h>
#include <pthread.h>

void move(const int dist, const char direc)
{
    const int dv = direc=='b'?-1:1;
    set_create_distance(0);
    while(abs(get_create_distance()) < dist)
    {
    	create_drive_direct(dv*300, dv*300);
        msleep(100);
    }
}

void turn(const int angle, const char direc)
{
    const int dv = direc=='l'?-1:1;
    set_create_total_angle(0);
    while(abs(get_create_total_angle()) < angle)
    {
    	create_drive_direct(dv*100, -dv*100);
        msleep(100);
    }
}

void set_arm(const int v[2])
{
    int i;
    const int div = 25, initial_position = get_servo_position(0);
    if(abs(*v-initial_position) < 30)
        set_servo_position(0, *v);
    else
    {
        for(i=1; i<=div; i++) 
        {
            set_servo_position(0, initial_position+i*(*v-initial_position)/div);
            msleep(50);
        }
    }
    set_servo_position(1, v[1]);
    msleep(50);
}

void initiation(void)
{
    int i;
    for(i=0; i<2; i++)
        enable_servo(i);   
    create_connect();
}

void disconnection(void)
{
    int i;
    for(i=0; i<2; i++)
        disable_servo(i);
    create_disconnect();
}

#define TWO_MIN 119000
void* exit_on_time(void* p)
{
    msleep(TWO_MIN);
    printf("Exiting\n");
    disconnection();
    exit(0);
    return (void*)0;
}

void timing_thread(void)
{
    pthread_t thread;
    pthread_create(&thread, NULL, exit_on_time, NULL);
    pthread_detach(thread);
}

void retrievePayload(void)
{
    const int closed_claw[2] = {1890, 950};
    
    int v[2] = {0, 0};
    set_arm(v);
    *v = 1870;
    set_arm(v);
    move(165,'f'); 
    create_drive_direct(0,0);
    set_arm(closed_claw);
    v[0] = 750;
    v[1] = 950;
    set_arm(v);
}

void toAnalysisLab(void)
{
    move(400,'b'); 
    turn(10,'r');
    create_drive_direct(0,0);
    const int v[2] = {150,0};
    set_arm(v);
}

int main(void)
{
    wait_for_light(0);
    initiation();
    timing_thread();
    
    // To center pillar
    move(450,'f');
    turn(50,'r');
    move(720,'f');
    turn(80,'l');
    
    create_drive_direct(0,0);
	retrievePayload();
    toAnalysisLab();
    
    // To pillar to the right of center
    move(150,'f');
    turn(10,'l');
    
    //retrievePayload();
    disconnection();
    return 0;
}
