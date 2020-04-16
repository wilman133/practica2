const int irReceiverPin = 2;
const int numberOfEntries = 64;
volatile unsigned long microseconds;
volatile byte index = 0;
volatile unsigned long results[numberOfEntries];
void setup(){
pinMode(irReceiverPin, INPUT);
Serial.begin(9600);
attachInterrupt(0, analyze, CHANGE);
results[0]=0;
}
// encoder pin on interrupt 0 (pin 2);
void loop(){
if(index >= numberOfEntries){
Serial.println("Durations in Microseconds are:") ;
for( byte i=0; i < numberOfEntries; i++){
Serial.println(results[i]);
}
while(1);

}
delay(1000);
}
void analyze(){
if(index < numberOfEntries ){
if(index > 0){
results[index] = micros() - microseconds;
}
index = index + 1;
}
microseconds = micros();
}
