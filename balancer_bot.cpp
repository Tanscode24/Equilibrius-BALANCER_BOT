#include <wire.h>
#include <MPU6050.h>
#include <PID_v1.h>
MPU6050 mpu;
// Motor A pins (L298N)
#define ENA 33     // PWM for Motor A
#define IN1 14     // Direction A
#define IN2 27     // Direction A

// Motor B pins (L298N)
#define ENB 32     // PWM for Motor B
#define IN3 26     // Direction B
#define IN4 25     // Direction B

// MPU6050 I2C Pins (default ESP32 I2C pins)
#define SDA_PIN 21   // I2C Data
#define SCL_PIN 22   // I2C Clock

// PID OBJECT 
double setpt = 0;
double input,output;
double kp = 35, ki = 0.7, kd = 1.2;
PID myPID(&input, &output, &setpoint, kp, ki, kd, DIRECT);

// SERIAL COMMUNICATION 
void setup()
{
  serial.begin(115200); //start serial 
  wire.begin(21,22);
  // MPU SETUP
  mpu.intialize(); // intializing the sensor 
  if (!mpu.testconnection()){
    serial.println("MPU6050 connection failed");
    while(1);
  }
  else {
    serial.println("MPU6050 connection successful");

  }
  // PIN MODE SETUP 
  pinMode(ENA, output);
  pinMode(ENB, output);
  pinMode(IN1, output);
  pinMode(IN2, output);
  pinMode(IN3, output);
  pinMode(IN4, output);

  pid.SetMode(AUTOMATIC);
  pid.SetSampleTime(10);
  pid.SetOutputLimits(-225,225);
  
  
}


  
  
  








