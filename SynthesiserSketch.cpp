// Declare notes
#define F_C 262
#define F_D 294
#define F_E 330
#define F_F 349
#define F_G 392
#define F_A 440
#define F_B 493
#define S_C 262
#define S_D 294
#define S_E 330
#define S_F 349
#define S_G 392
#define S_A 440
#define S_B 493
#define T_X 493
#define T_Y 493


const int C = 6;
const int D = 7;
const int E = 8;
const int F = 9;
const int G = 10;
const int A = 11;
const int B = 12;

const int OCTAVA = 5;

const int Buzz = 2;
const int LED = 13;
const int helpButtonPin = 3;


void setup()
{
  Serial.begin(57600);
  //INPUT
  pinMode(OCT, INPUT);
  pinMode(C, INPUT);
  pinMode(D, INPUT);
  pinMode(E, INPUT);
  pinMode(F, INPUT);
  pinMode(G, INPUT);
  pinMode(A, INPUT);
  pinMode(B, INPUT);
  pinMode(helpButtonPin, INPUT);

  //OUTPUT
  pinMode(Buzz, OUTPUT);
  pinMode(LED, OUTPUT);
}

void loop()
{
  if(checkPush(helpButtonPin)) {
    savedSongsModePlay();
  } else {
    pianoModePlay();
  }
}

bool checkPush(int pinNumber) 
{
  return digitalRead(pinNumber) == HIGH;
}

void pianoModePlay()
{
    while(checkPush(C))
  {
    if(checkPush(OCT)) {
      tone(Buzz,S_C);
    } else {
      tone(Buzz,F_C);
    }
    digitalWrite(LED,HIGH);
  }

  while(checkPush(D))
  {
    if(checkPush(OCTAVA)) {
      tone(Buzz,S_D);
    } else {
      tone(Buzz,F_D);
    }
    digitalWrite(LED,HIGH);
  }

  while(checkPush(E))
  {
    if(checkPush(OCTAVA)) {
      tone(Buzz,S_E);
    } else {
      tone(Buzz,F_E);
    }
    digitalWrite(LED,HIGH);
  }

  while(checkPush(F))
  {
    if(checkPush(OCTAVA)) {
      tone(Buzz,S_F);
    } else {
      tone(Buzz,F_F);
    }
    digitalWrite(LED,HIGH);
  }

  while(checkPush(G))
  {
    if(checkPush(OCTAVA)) {
      tone(Buzz,S_G);
    } else {
      tone(Buzz,F_G);
    }
    digitalWrite(LED,HIGH);
  }

  while(checkPush(A))
  {
    if(checkPush(OCTAVA)) {
      tone(Buzz,S_A);
    } else {
      tone(Buzz,F_A);
    }
    digitalWrite(LED,HIGH);
  }

  while(checkPush(B))
  {
    if(checkPush(OCTAVA)) {
      tone(Buzz,S_B);
    } else {
      tone(Buzz,F_B);
    }
    digitalWrite(LED,HIGH);
  }
  
  noTone(Buzz);
  digitalWrite(LED,LOW);
}

void savedSongsModePlay() 
{
  digitalWrite(LED,HIGH);
  delay(200);
  digitalWrite(LED,LOW);
  delay(200);
}