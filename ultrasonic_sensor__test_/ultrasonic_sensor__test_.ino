#define echoPin 7 
#define trigPin 8 
int red_light_pin= 2;
int green_light_pin = 3;
int blue_light_pin = 4;

  long duration; 
  int distance; 

void setup() {
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);
   pinMode(red_light_pin, OUTPUT);
  pinMode(green_light_pin, OUTPUT);
  pinMode(blue_light_pin, OUTPUT); 
  Serial.begin(9600); 
  
}
void loop() {
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  if(distance>30)
  {
    RGB_color(0, 255, 0); // Green
  
  }
  else if(distance<30&&distance>20)
  {
     RGB_color(0, 0, 255); // Blue
 
  }
  else if(distance<10)
  {
     RGB_color(255, 0, 0); // Red
 
  }
  
}
 void RGB_color(int red_light_value, int green_light_value, int blue_light_value)
 {
  analogWrite(red_light_pin, red_light_value);
  analogWrite(green_light_pin, green_light_value);
  analogWrite(blue_light_pin, blue_light_value);
}
