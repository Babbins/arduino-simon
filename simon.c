/*Code for Arduino Simon game by Ali Mahmoud and Calvin Lee
 * CSE321 PROJECT 3
 */

#include <stdio.h>
#include <stdlib.h>

int LED_9 = 9;
int LED_8 = 8;
int LED_7 = 7;
int LED_6 = 6;
int but2 = 2;
int but3 = 3;
int but4 = 4;
int but5 = 5;
int a = 12;
int b = 13;
int c = 18;
int d = 16;
int e = 15;
int f = 11;
int g = 10;

int state = 1;			//boolean for the state of winning and losing winning =1 , loss = 0

int pattern[10];
int counter = 0;
int ra = 0;
int j = 0;

int lcd[10][7] = {		//2d array for 1-9 on the LCD display
  {1,1,1,1,1,1,0},
  {0,1,1,0,0,0,0},
  {1,1,0,1,1,0,1},
  {1,1,1,1,0,0,1},
  {0,1,1,0,0,1,1},
  {1,0,1,1,0,1,1},
  {1,0,1,1,1,1,1},
  {1,1,1,0,0,0,0},
  {1,1,1,1,1,1,1},
  {1,1,1,1,0,1,1}
};

int win[7] = {0,1,1,1,1,1,0};	//win and loss 
int lose[7] = {0,0,0,1,1,1,0};

void setup() {
	pinMode(LED_9, OUTPUT); 
	pinMode(LED_8, OUTPUT); 
	pinMode(LED_7, OUTPUT);
	pinMode(LED_6, OUTPUT);
	pinMode(but2, INPUT);
	pinMode(but3, INPUT);
	pinMode(but4, INPUT);
	pinMode(but5, INPUT);
        pinMode(a, OUTPUT);
        pinMode(b, OUTPUT);
        pinMode(c, OUTPUT);
        pinMode(d, OUTPUT);
        pinMode(e, OUTPUT);
        pinMode(f, OUTPUT);
        pinMode(g, OUTPUT);
	Serial.begin(9600);
	randomSeed(analogRead(0));
}

void loop() {
   if(state == 0) {                  //if the player is in the lose state.
    digitalWrite(LED_6, HIGH);
    digitalWrite(LED_7, HIGH);
    digitalWrite(LED_8, HIGH);
    digitalWrite(LED_9, HIGH);
    digitalWrite(a, lose[0]); 
    digitalWrite(b, lose[1]); 
    digitalWrite(c, lose[2]); 
    digitalWrite(d, lose[3]); 
    digitalWrite(e, lose[4]); 
    digitalWrite(f, lose[5]); 
    digitalWrite(g, lose[6]);
    delay(3000);
    digitalWrite(LED_6, LOW);
    digitalWrite(LED_7, LOW);
    digitalWrite(LED_8, LOW);
    digitalWrite(LED_9, LOW);
    delay(1000);
    counter = 0;
    state = 1;
  }
  digitalWrite(a, lcd[counter][0]); 
  digitalWrite(b, lcd[counter][1]); 
  digitalWrite(c, lcd[counter][2]); 
  digitalWrite(d, lcd[counter][3]); 
  digitalWrite(e, lcd[counter][4]); 
  digitalWrite(f, lcd[counter][5]); 
  digitalWrite(g, lcd[counter][6]); 
  if(counter < 10) {			//if statement to generate a random number and store it in the pattern array
	ra = random(0, 4);
	pattern[counter] = ra;
	counter++;
  }
  if(counter == 10 && state == 1) {     //if player is in the win state.
      digitalWrite(LED_6, HIGH);
      digitalWrite(LED_7, HIGH);
      digitalWrite(LED_8, HIGH);
      digitalWrite(LED_9, HIGH);
      digitalWrite(a, win[0]); 
      digitalWrite(b, win[1]); 
      digitalWrite(c, win[2]); 
      digitalWrite(d, win[3]); 
      digitalWrite(e, win[4]); 
      digitalWrite(f, win[5]); 
      digitalWrite(g, win[6]);
      delay(3000);
      digitalWrite(LED_6, LOW);
      digitalWrite(LED_7, LOW);
      digitalWrite(LED_8, LOW);
      digitalWrite(LED_9, LOW);
      delay(1000);
      counter = 0;
      state = 1;
  }
  for(j = 0; j < counter; j++){  			//loop for lighting up the pattern for the player
	switch(pattern[j]) {
		case 0: {
			digitalWrite(LED_6, HIGH); 
			delay(300);
			digitalWrite(LED_6, LOW);
			delay(300);
			break;
		}
		case 1: {
			digitalWrite(LED_7, HIGH); 
			delay(300);
			digitalWrite(LED_7, LOW);
			delay(300);
			break;
		}
		case 2: {
			digitalWrite(LED_8, HIGH); 
			delay(300);
			digitalWrite(LED_8, LOW);
			delay(300);
			break;
		}
		case 3: {
			digitalWrite(LED_9, HIGH); 
			delay(300);
			digitalWrite(LED_9, LOW);
			delay(300);
			break;
		}
	 }
  }
  for(j = 0; j < counter; j++) {			//loop for when the user is inputting the pattern
    if(state == 0) break;
    else if(pattern[j] == 0) {
       while(state) {
          if(digitalRead(but2) == HIGH){
            while(digitalRead(but2) == HIGH) digitalWrite(LED_6, HIGH);
            digitalWrite(LED_6, LOW);
            break; 
          }
        
          else if(digitalRead(but3) == HIGH) {
            while(digitalRead(but3) == HIGH) digitalWrite(LED_7, HIGH);
            digitalWrite(LED_7, LOW);
            state = 0; 
          }
          
          else if(digitalRead(but4) == HIGH) {
            while(digitalRead(but4) == HIGH) digitalWrite(LED_8, HIGH);
            digitalWrite(LED_8, LOW);
            state = 0;
          }
          
          else if(digitalRead(but5) == HIGH) {
            while(digitalRead(but5) == HIGH) digitalWrite(LED_9, HIGH);
            digitalWrite(LED_9, LOW);
            state = 0; 
          }
    }
    
  }
  else if(pattern[j] == 1) {
       while(state) {
          if(digitalRead(but3) == HIGH){
            while(digitalRead(but3) == HIGH) digitalWrite(LED_7, HIGH);
            digitalWrite(LED_7, LOW);
            break; 
          }
        
          else if(digitalRead(but2) == HIGH) {
            while(digitalRead(but2) == HIGH) digitalWrite(LED_6, HIGH);
            digitalWrite(LED_6, LOW);
            state = 0; 
          }
          
          else if(digitalRead(but4) == HIGH) {
            while(digitalRead(but4) == HIGH) digitalWrite(LED_8, HIGH);
            digitalWrite(LED_8, LOW);
            state = 0;
          }
          
          else if(digitalRead(but5) == HIGH) {
            while(digitalRead(but5) == HIGH) digitalWrite(LED_9, HIGH);
            digitalWrite(LED_9, LOW);
            state = 0; 
          }
    }
    
  }
  else if(pattern[j] == 2) {
       while(state) {
          if(digitalRead(but4) == HIGH){
            while(digitalRead(but4) == HIGH) digitalWrite(LED_8, HIGH);
            digitalWrite(LED_8, LOW);
            break; 
          }
        
          else if(digitalRead(but3) == HIGH) {
            while(digitalRead(but3) == HIGH) digitalWrite(LED_7, HIGH);
            digitalWrite(LED_7, LOW);
            state = 0; 
          }
          
          else if(digitalRead(but2) == HIGH) {
            while(digitalRead(but2) == HIGH) digitalWrite(LED_6, HIGH);
            digitalWrite(LED_6, LOW);
            state = 0;
          }
          
          else if(digitalRead(but5) == HIGH) {
            while(digitalRead(but5) == HIGH) digitalWrite(LED_9, HIGH);
            digitalWrite(LED_9, LOW);
            state = 0; 
          }
    }
    
  }
  else if(pattern[j] == 3) {
       while(state) {
          if(digitalRead(but5) == HIGH){
            while(digitalRead(but5) == HIGH) digitalWrite(LED_9, HIGH);
            digitalWrite(LED_9, LOW);
            break; 
          }
        
          else if(digitalRead(but3) == HIGH) {
            while(digitalRead(but3) == HIGH) digitalWrite(LED_7, HIGH);
            digitalWrite(LED_7, LOW);
            state = 0; 
          }
          
          else if(digitalRead(but4) == HIGH) {
            while(digitalRead(but4) == HIGH) digitalWrite(LED_8, HIGH);
            digitalWrite(LED_8, LOW);
            state = 0;
          }
          
          else if(digitalRead(but2) == HIGH) {
            while(digitalRead(but2) == HIGH) digitalWrite(LED_6, HIGH);
            digitalWrite(LED_6, LOW);
            state = 0; 
          }
      }
    }
  } 
  delay(1000);

}
