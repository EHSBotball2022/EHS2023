#include <kipr/wombat.h>

void move_forward(const int dist)
{
    set_create_distance(0);
    while(get_create_distance() < dist)  // Continue moving until Create distance is greater than dist parameter value.
    {
    	create_drive_direct(100, 100);
        msleep(500);
    }
}
void reset_arm()
{
    const int initial_values[3] = {300, 1810, 1850};
    int i;
    for(i=3; i>=0; i--)				
        set_servo_position(i, *(initial_values+i)); // Set position of each of 3 servos to constant values stored in above array.
}
void raise_arm(const int value[3])
{
    int i;
    for(i=2; i>=0; i--)					
        set_servo_position(i, *(value+i)); // Set position of each of 3 servos to values passed in array parameter.
}

void connect() // Connect function enables each of the 3 servos and calls create_connect().
{
    int i;
    for(i=0; i<3; i++)
        enable_servo(i);
	create_connect();
}
void disconnect() // Disconnect function disabled each of the three servos and calls create_disconnect().
{
    int i;
    for(i=0; i<3; i++)
        disable_servo(i);
    create_disconnect();
}

int main(void) // Main function
{
    connect(); 		  // Calls connect to enable various functionalities. 
	    
    reset_arm();	  // Reset arm to default position
    
    msleep(2500);
    int v[3] = {1450, 0, 1850};
    raise_arm(v); 	  // Raises arm to values defined in above array.
    
    move_forward(50); // Moves Create bot a certain distance.
    
    disconnect(); 	  // Calls connect to disables various functionalities.
    return 0;
}

