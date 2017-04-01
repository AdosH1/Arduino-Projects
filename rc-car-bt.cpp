//A remote controlled Arduino car by bluetooth
// Built to work with a HC-06 BT module and 2 motor H-bridge
// Used a freely available android app - Bluetooth Electronics on the Google Play store to control the rc car with my phone
// By Aden Huen

//Motor A pins (pinA1 = forward, pinA2 = backward)
int enableA = 11;
int pinA1 = 6;
int pinA2 = 5;

//Motor B pins (pinB1 = forward, pinB2 = backward)
int enableB = 10;
int pinB1 = 9;
int pinB2 = 3;

char BluetoothData = 0;

//Motor enablers
void motorAon() 
{
    digitalWrite(enableA, HIGH);
}
void motorBon() 
{
    digitalWrite(enableB, HIGH);
}
void enableMotors() 
{
    motorAon();
    motorBon();
}

//Motor disablers
void motorAoff() 
{
    digitalWrite(enableA, LOW);
}
void motorBoff() 
{
    digitalWrite(enableB, LOW);
}
void disableMotors() 
{
    motorAoff();
    motorBoff();
}

//Motor motions
void moveForward() 
{
    digitalWrite(pinA1, HIGH);
    digitalWrite(pinA2, LOW);
    digitalWrite(pinB1, HIGH);
    digitalWrite(pinB2, LOW);
}
void moveBackward() 
{
    digitalWrite(pinA1, LOW);
    digitalWrite(pinA2, HIGH);
    digitalWrite(pinB1, LOW);
    digitalWrite(pinB2, HIGH);
}
void turnRight() 
{
    digitalWrite(pinA1, LOW);
    digitalWrite(pinA2, HIGH);
    digitalWrite(pinB1, HIGH);
    digitalWrite(pinB2, LOW);
}
void turnLeft() 
{
    digitalWrite(pinA1, HIGH);
    digitalWrite(pinA2, LOW);
    digitalWrite(pinB1, LOW);
    digitalWrite(pinB2, HIGH);
}
void brake() 
{
    digitalWrite(pinA1, HIGH);
    digitalWrite(pinA2, HIGH);
    digitalWrite(pinB1, HIGH);
    digitalWrite(pinB2, HIGH);
}


void setup() {
    pinMode(enableA, OUTPUT);
    pinMode(pinA1, OUTPUT);
    pinMode(pinA2, OUTPUT);
  
    pinMode(enableB, OUTPUT);
    pinMode(pinB1, OUTPUT);
    pinMode(pinB2, OUTPUT);
    enableMotors();
    Serial.begin(9600);
}

void loop() {
    if (Serial.available()) 
    {
        BluetoothData = Serial.read(); 
        
        if (BluetoothData=='R')
            turnRight();
        
        else if (BluetoothData=='U') 
            moveForward();
        
        else if (BluetoothData=='D') 
            moveBackward();
        
        else if (BluetoothData=='L') 
            turnLeft();
        
        else if (BluetoothData=='0') 
            brake();
    }
}
