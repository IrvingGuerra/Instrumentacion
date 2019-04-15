#define LED GREEN_LED
void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);   
}

void loop() {
  String NTC = String(map(analogRead(A0), 0, 1023, 0, 50));
  String FOCO = String (map(analogRead(A4), 0, 1023, 0, 1023));
  String MAGNETIC = String (map(analogRead(A5), 0, 1023, -1600, 400));
  Serial.println(NTC+","+FOCO+","+MAGNETIC+","); 
  digitalWrite(LED, HIGH);
  delay(500);
  digitalWrite(LED, LOW);
  delay(500);    
}
