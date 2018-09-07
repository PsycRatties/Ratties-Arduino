//Fixed Ratio (FR) program
//8/20/2018
//Albena Ammann, Ed Berg, Mark Berg

int switchState = 0; 
int delay_value = 500; // how fast the audible click is (higher=longer)
int fr = 5; // amount of button presses to start the relay
void setup() {

  pinMode(7, INPUT);  // left switch (spst momentary n.o.)
  pinMode(4, INPUT);  // right switch, bottom black (spst)
  pinMode(5, OUTPUT);  // LED left blue
  pinMode(2, INPUT); // right switch (spst momentary n.o.)
  pinMode(6, OUTPUT);  // LED right green
  pinMode(10, OUTPUT);  // relay
  pinMode(3, OUTPUT);  // LED red middle
  pinMode(8, INPUT);  // left switch, bottom green (spst)
}

void loop() {
  // put your main code here, to run repeatedly:
  int switchcounter2 = 0;
  int switchState2;
  int switchState7;
  int lastswitchstate2 = 0;
  int lastswitchstate7 = 0;

  if (digitalRead (4) == HIGH) {
    digitalWrite(6, digitalRead(4));
    
    do { 
      switchState2 = digitalRead(2);
      switchState7 = digitalRead(7);   
      
      if ((switchState2 != lastswitchstate2 ) and (switchState2 == HIGH))
        switchcounter2++;
     
      delay(50);
      
      lastswitchstate2 = switchState2;
    } while (switchcounter2 < fr);
  
    for(int i = 0; i < 10; i++) {  //repeat the next if/else 10 times
        digitalWrite(5, LOW);
        digitalWrite(10, LOW);
        digitalWrite(5, HIGH);
        digitalWrite(10, HIGH);
        delay(delay_value);
        digitalWrite(10, LOW);
        delay(delay_value);
        digitalWrite(10, HIGH);
        digitalWrite(10, LOW);
        digitalWrite(5, LOW);
        switchcounter2 = 0;
    }
  } else digitalWrite(6, LOW);

  if (digitalRead (8) == HIGH) {
    digitalWrite(3, digitalRead(8));
    
    do {
        switchState7 = digitalRead(7);   
       
        if ((switchState2 != lastswitchstate2 ) and ((switchState2 == HIGH) or (switchState7 == HIGH)))
          switchcounter2++;
       
        delay(50);
        
        lastswitchstate7 = switchState7;  
    } while (switchcounter2 < fr);
  
    for (int j = 0; j < 10; j++) {  //repeat the next if/else 10 times
      digitalWrite(5, LOW);
      digitalWrite(10, LOW);
      digitalWrite(5, HIGH);
      digitalWrite(10, HIGH);
      delay(delay_value);
      digitalWrite(10, LOW);
      delay(delay_value);
      digitalWrite(10, HIGH);
      digitalWrite(10, LOW);
      digitalWrite(5, LOW);
      switchcounter2 = 0;
    }
  } else digitalWrite(3, LOW); 
}
