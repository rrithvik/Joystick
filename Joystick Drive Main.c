#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTServo)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     motorD,        tmotorTetrix, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     motorE,        tmotorTetrix, PIDControl, reversed, encoder)
#pragma config(Motor,  mtr_S1_C2_1,     motorF,        tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C2_2,     motorG,        tmotorTetrix, openLoop, reversed, encoder)
#pragma config(Motor,  mtr_S1_C3_1,     motorH,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     motorI,        tmotorTetrix, openLoop, reversed)
#pragma config(Servo,  srvo_S1_C4_1,    servo1,               tServoStandard)
#pragma config(Servo,  srvo_S1_C4_2,    servo2,               tServoStandard)
#pragma config(Servo,  srvo_S1_C4_3,    servo3,               tServoStandard)
#pragma config(Servo,  srvo_S1_C4_4,    servo4,               tServoContinuousRotation)
#pragma config(Servo,  srvo_S1_C4_5,    servo5,               tServoContinuousRotation)
#pragma config(Servo,  srvo_S1_C4_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

int motor1speed;
int motor2speed;
int motor3speed;
int motor4speed;

void initializeRobot()
{
	servo[servo1] = 0;
	servo[servo2] = 244;

	return;
}

task main()
{

	initializeRobot();

	while(true) // Infinite loop:
	{
		getJoystickSettings(joystick);

		motor1speed = joystick.joy1_y1;
		motor2speed = joystick.joy1_y2;
		motor3speed = joystick.joy1_y1;
		motor4speed = joystick.joy1_y2;

		if(joystick.joy1_y1 || joystick.joy1_y2) //reducing the motor speed by half
		{
			motor[motorD] = motor1speed/2;
			motor[motorE] = motor2speed/2;
			motor[motorF] = motor3speed/2;
			motor[motorG] = motor4speed/2;
		}

		else //brake when there is no joystick value
		{
			motor[motorD] = 0;
			motor[motorE] = 0;
			motor[motorF] = 0;
			motor[motorG] = 0;
		}

		if(joy1Btn(1) == 1) //move the scoop up when button 1 is pressed
		{
			servo[servo4] = 225;
			servo[servo5] = -225;
			wait1Msec(800);

			servo[servo6] = 255;
			wait1Msec(30);
		}

		if(joy1Btn(2) == 1) //move the scoop down when button 2 is pressed
		{
			servo[servo4] = 127;
			servo[servo5] = 127;
			servo[servo6] = 127
		}

		if(joy1Btn(3) == 1)
			{
				servo[servo4] = -255;
				servo[servp5] = -255;
				wait1Msec(800);

				servo[servo6] = 0;
				wait1Msec(30);
			}

		if(joy1Btn(5) == 1)
		{
			motor[motorH] = 30;
			motor[motorI] = 30;
			wait1Msec(3);
			motor[motorH] = 0;
			motor[motorI] = 0;
		}

		if(joy1Btn(6) == 1)
		{
			motor[motorH] = -30;
			motor[motorI] = -30;
			wait1Msec(3);
			motor[motorH] = 0;
			motor[motorI] = 0;
		}

		if(joy1Btn(7) == 1)
		{
			servo[servo1] = 0;
			servo[servo2] = 244;
			wait1Msec(200);
		}

		if(joy1Btn(8) == 1)
		{
			servo[servo1] = 244;
			servo[servo2] = 0;
			wait1Msec(200);
		}
	}
}

//The Metal Magicians
//Jeffles
