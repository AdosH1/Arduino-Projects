//A die consisting of 3x3 LEDs  to imitate a die face
// This program uses a shift register, allowing us to control 8 pins with 3
// By Aden Huen

#define lonelyled 5
#define trigger 6
int dataPin = 2;
int latchPin = 3;
int clockPin = 4; 
int singleled[] = {0, 1, 2, 4, 8, 16, 32, 64, 128};

//turns random leds on to represent rolling animation
void scramble() 
{
    for (int i = 0; i < 15; i++) 
    {
    int k = random(0, 8);
    
    if (singleled[k] == 0) 
        {
            digitalWrite(lonelyled, HIGH);
            delay(10);
            digitalWrite(lonelyled,LOW);
            delay(10);
        }
        
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, singleled[k]);
    digitalWrite(latchPin, HIGH);

    delay(10);

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, 0);
    digitalWrite(latchPin, HIGH);
    
    } // for loop bracket
} // scramble() bracket

void reset() 
{
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, 0);
    digitalWrite(latchPin, HIGH);
    digitalWrite(lonelyled, LOW);
}

void roll() 
{
    int k = random(1,7);
    Serial.print(k);
    Serial.println();
    
    if (k == 1) 
    {
        for (int i = 0; i < 3; i++) 
        {
            digitalWrite(latchPin, LOW);
            shiftOut(dataPin, clockPin, MSBFIRST, 16);
            digitalWrite(latchPin, HIGH);
            delay(500);
            digitalWrite(latchPin, LOW);
            shiftOut(dataPin, clockPin, MSBFIRST, 0);
            digitalWrite(latchPin, HIGH);
            delay(500);
        }
    }
    
    if (k == 2) 
    {
        for (int i = 0; i < 3; i++) 
        {
            digitalWrite(latchPin, LOW);
            shiftOut(dataPin, clockPin, MSBFIRST, 68);
            digitalWrite(latchPin, HIGH);
            delay(500);
            digitalWrite(latchPin, LOW);
            shiftOut(dataPin, clockPin, MSBFIRST, 0);
            digitalWrite(latchPin, HIGH);
            delay(500);
        }
    }
  
    if (k == 3) 
    {
        for (int i = 0; i < 3; i++) 
        {
            digitalWrite(latchPin, LOW);
            shiftOut(dataPin, clockPin, MSBFIRST, 84);
            digitalWrite(latchPin, HIGH);
            delay(500);
            digitalWrite(latchPin, LOW);
            shiftOut(dataPin, clockPin, MSBFIRST, 0);
            digitalWrite(latchPin, HIGH);
            delay(500);
        }
    }
    if (k == 4) 
    {
        for (int i = 0; i < 3; i++) 
        {
            digitalWrite(latchPin, LOW);
            shiftOut(dataPin, clockPin, MSBFIRST, 197);
            digitalWrite(latchPin, HIGH);
            delay(500);
            digitalWrite(latchPin, LOW);
            shiftOut(dataPin, clockPin, MSBFIRST, 0);
            digitalWrite(latchPin, HIGH);
            delay(500);
        }
    }
  
    if (k == 5) 
    {
        for (int i = 0; i < 3; i++) 
        {
            digitalWrite(latchPin, LOW);
            shiftOut(dataPin, clockPin, MSBFIRST, 213);
            digitalWrite(latchPin, HIGH);
            delay(500);
            digitalWrite(latchPin, LOW);
            shiftOut(dataPin, clockPin, MSBFIRST, 0);
            digitalWrite(latchPin, HIGH);
            delay(500);
        }
    }
  
    if (k == 6) 
    {
        for (int i = 0; i < 3; i++) 
        {
            digitalWrite(latchPin, LOW);
            shiftOut(dataPin, clockPin, MSBFIRST, 199);
            digitalWrite(latchPin, HIGH);
            digitalWrite(lonelyled, HIGH);
            delay(500);
            digitalWrite(latchPin, LOW);
            shiftOut(dataPin, clockPin, MSBFIRST, 0);
            digitalWrite(latchPin, HIGH);
            digitalWrite(lonelyled, LOW);
            delay(500);
        }
    }
} // void roll() bracket

void setup() 
{
    pinMode(dataPin, OUTPUT);
    pinMode(latchPin, OUTPUT);
    pinMode(clockPin, OUTPUT);
    pinMode(lonelyled, OUTPUT);
    pinMode(trigger, INPUT);
    Serial.begin(9600);
}

void loop() 
{
    while(digitalRead(trigger) == HIGH) 
    {
        scramble();
        roll();
    }
}
