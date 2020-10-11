//variable declaration:
int echo_pin = 9;
int trig_pin = 10;

float distance = 0;
double duration;

void setup() {
  /* put your setup code here, to run once: */

  // this code is about which pin use for input or which pin use for output
  pinMode(echo_pin, INPUT);
  pinMode(trig_pin, OUTPUT);

  //this line for desplay content in serial monitor
  Serial.begin(9600);

}

void loop() {
  /* put your main code here, to run repeatedly: */

  //set ZERO voltage at trigger pin for exclude Error
  digitalWrite(trig_pin, LOW);
  delayMicroseconds(9);

  //Provide voltage at trigger pin to emit ultrasound
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(2);

  //Calculate the Duration between emit to recieve ultrasound
  duration = pulseIn(echo_pin,HIGH);  // this time is in Microsecond

  /* from simple logic::
   *  
   * sound speed in air = 343 m/s
   * sound speed in air = 343 x(100/1000000) cm/Ms
   * sound speed in air = 0.0343 cm/Ms
   * 
   * distance travelled by sound = speed x duration
   * 
   * we have distance for going to the subject and returning from object so,
   * Required distance = distance travelled by sound / 2
   * 
   */
  distance = (0.0343 * duration)/2;    // distance in centimeter

  // show the distance on serial monitor:
  Serial.print("Distance:  ");
  Serial.println(distance);

}
