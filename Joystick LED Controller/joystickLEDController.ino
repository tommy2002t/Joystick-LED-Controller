const int sw_pin=2;
const int y_pin=0;
int step=0;

const int leds[]={13, 12, 11, 10};

void setup() {
 for (int i = 0; i < 4; i++) 
 {
    pinMode(leds[i], OUTPUT);
    digitalWrite(leds[i], LOW);
 }
 Serial.begin(9600);

}


void loop() {
 int yValue=analogRead(y_pin);
 Serial.print("Y-Axis:  ");
 Serial.println(yValue);

if(yValue>1000)
{
  step++;
  delay(300);
}
else if(yValue<20)
{
  step--;
  delay(300);
}

step=constrain(step, 0, 3);
for (int i = 0; i < 4; i++) {
  if (i == step) {
    digitalWrite(leds[i], HIGH); // Turn ON the active LED
  } else {
    digitalWrite(leds[i], LOW);  // Turn OFF the other LEDs
  }
}
delay(50);


 
}
