//Front US Sensor
const int OneTrigger = 6; // Trigger Pin of Ultrasonic Sensor Front
const int OneEcho = 7; // Echo Pin of Ultrasonic Sensor Front
//Right US Sensor
const int TwoTrigger = 8; // Trigger Pin of Ultrasonic Sensor Right
const int TwoEcho = 9; // Echo Pin of Ultrasonic Sensor Right
//Left US Sensor
const int ThreeTrigger = 10; // Trigger Pin of Ultrasonic Sensor Left
const int ThreeEcho = 11; // Echo Pin of Ultrasonic Sensor Left
//Back US Sensor
const int FourTrigger = 12; // Trigger Pin of Ultrasonic Sensor Back
const int FourEcho = 13; // Echo Pin of Ultrasonic Sensor Back

void setup() {
  Serial.begin(9600); // Starting Serial Terminal
}

void loop() {
  //Front Sensor
  long durationF, cmFront;  //Initialize the variables
  pinMode(OneTrigger, OUTPUT);  //Set Trigger Pin as Output Pin
  digitalWrite(OneTrigger, LOW);  //Trigger Pin not Activated
  delayMicroseconds(2); //Wait 2 Microseconds
  digitalWrite(OneTrigger, HIGH); //Activate Trigger Pin
  delayMicroseconds(10);  //Wait 10 Microseconds
  digitalWrite(OneTrigger, LOW);  //Deactivate Trigger Pin
  pinMode(OneEcho, INPUT);  //Set Echo Pin as an Input Pin
  durationF = pulseIn(OneEcho, HIGH); //Activate the Echo Pin and Find the Number of Microseconds it Takes for the Sound Wave to be Returned
  cmFront = microsecondsToCentimeters(durationF); //Call method to convert number of microseconds to centimeter
  delay(100); //delay

  //Right Sensor
  long durationR, cmRight;
  pinMode(TwoTrigger, OUTPUT);
  digitalWrite(TwoTrigger, LOW);
  delayMicroseconds(2);
  digitalWrite(TwoTrigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(TwoTrigger, LOW);
  pinMode(TwoEcho, INPUT);
  durationR = pulseIn(TwoEcho, HIGH);
  cmRight = microsecondsToCentimeters(durationR);
  delay(100);


  //Left Sensor
  long durationL, cmLeft;
  pinMode(ThreeTrigger, OUTPUT);
  digitalWrite(ThreeTrigger, LOW);
  delayMicroseconds(2);
  digitalWrite(ThreeTrigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(ThreeTrigger, LOW);
  pinMode(ThreeEcho, INPUT);
  durationL = pulseIn(ThreeEcho, HIGH);
  cmLeft = microsecondsToCentimeters(durationL);
  delay(100);

  //Back Sensor
  long durationB, cmBack;
  pinMode(FourTrigger, OUTPUT);
  digitalWrite(FourTrigger, LOW);
  delayMicroseconds(2);
  digitalWrite(FourTrigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(FourTrigger, LOW);
  pinMode(FourEcho, INPUT);
  durationB = pulseIn(FourEcho, HIGH);
  cmBack = microsecondsToCentimeters(durationB);
  delay(100);

  int directional; //initialize a variable for direction
  directional = checkdirection(cmFront, cmRight, cmLeft, cmBack); //call method to check empty side


}

long microsecondsToCentimeters(long microseconds) { //method to convert microseconds to centimeters
  return microseconds / 29 / 2;
}
int checkdirection(long cmFront, long cmRight, long cmLeft, long cmBack) { //method to find empty side
  if (cmFront < 366) { // checks if distance in front is less than 366 cm or 12 feet
    
    if (cmRight < 122) { //checks if distance in right is less than 122 cm or 4 feet
      
      if (cmLeft < 122) { //checks if distance in left is less than 122 cm or 4 feet
        
        if (cmBack < 366) { //checks if distance in back is less than 366 cm or 12 feet
          return 5; //returns 5 if no place to go
        }
        else {
          return 4; //returns 4 if back side is empty
        }
      }
      else {
        return 3; //returns 3 if left side is empty
      }
      
    }
    else {
      return 2; //returns 2 if right side is empty
    }
  }
  else {
    return 1; //returns 1 if front is empty
  }
}
