//An ultrasonic distance sensing device that displays distance from objects
// and sends that information via. bluetooth as well as shown on an LED display
// Assumes use of the HC-06 BT module and TM1637 display
// By Aden Huen

#include <TM1637.h>

#define echo 13
#define trig 12
#define blue 11
#define green 10
#define red 9
#define CLK 4
#define DIO 3

int duration = 0;
int distance = 0;


TM1637 tm1637(CLK, DIO);

void show_LED() 
{
    for (int k = 0; k < 3; k++) 
    {
        int one_digit = distance % 10;
        distance = floor(distance / 10);
        tm1637.display(3-k, one_digit);
    }
}

void setup() 
{
    Serial.begin(9600);
    pinMode(echo, INPUT);
    pinMode(trig, OUTPUT);
    pinMode(red, OUTPUT);
    pinMode(green, OUTPUT);
    pinMode(blue, OUTPUT);
    tm1637.init();
    tm1637.set(BRIGHT_TYPICAL); //brightness 0-7, typical = 2
    digitalWrite(trig, LOW);
    delay(1500); //dely for sys boot
}

void loop() 
{
    //pulse echo measurement
    digitalWrite(trig, LOW);
    delay(10);
    digitalWrite(trig, HIGH);
    delay(10);
    digitalWrite(trig, LOW);
      
        duration = pulseIn(echo, HIGH);
        distance = (duration/2) / 29.1;

    Serial.print("*T"+String(duration)+"*");
    Serial.print("*D"+String(distance)+"*");

    show_LED();

    delay(1000);

}
