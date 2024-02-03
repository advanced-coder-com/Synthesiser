#include "pitches.h"

// Declare notes
#define F_C NOTE_C4
#define F_D NOTE_D4
#define F_E NOTE_E4
#define F_F NOTE_F4
#define F_G NOTE_G4
#define F_A NOTE_A4
#define F_B NOTE_B4
#define S_C NOTE_C5
#define S_D NOTE_D5
#define S_E NOTE_E5
#define S_F NOTE_F5
#define S_G NOTE_G5
#define S_A NOTE_A5
#define S_B NOTE_B5


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

// Note: row below is using only for version with function button 
// const int helpButtonPin = 3;

void setup()
{
  // Serial.begin(57600);
  //INPUT
  pinMode(OCT, INPUT);
  pinMode(C, INPUT);
  pinMode(D, INPUT);
  pinMode(E, INPUT);
  pinMode(F, INPUT);
  pinMode(G, INPUT);
  pinMode(A, INPUT);
  pinMode(B, INPUT);

  // Note: row below is using only for version with function button 
  // pinMode(helpButtonPin, INPUT);

  //OUTPUT
  pinMode(Buzz, OUTPUT);
  pinMode(LED, OUTPUT);
}

void loop()
{
  if(isSavedSongsMode()) {
    savedSongsModePlay();
  } else {
    pianoModePlay();
  }
}

bool isSavedSongsMode()
{
  // Note: row below is using only for version with function button 
  // return checkPush(helpButtonPin);
  return checkPush(A) && checkPush(B) && checkPush(OCTAVA);
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
      if (!checkPush(B)) {
        tone(Buzz,F_A);
      }
    }
    digitalWrite(LED,HIGH);
  }

  while(checkPush(B))
  {
    if(checkPush(OCTAVA)) {
      tone(Buzz,S_B);
    } else {
      if (!checkPush(A)){
        tone(Buzz,F_B);
      }
    }
    digitalWrite(LED,HIGH);
  }
  
  noTone(Buzz);
  digitalWrite(LED,LOW);
}

void savedSongsModePlay() 
{
  // 1
  if(checkPush(C)) {
    playHappyBirthday();
    return;
  }

  // 2
  if(checkPush(D)) {
    playMerryCristmas();
    return;
  }

  // 3
  if(checkPush(E)) {
    playHarryPotter();
    return;
  }

  // 4
  if(checkPush(F)) {
    playStarWars();
    return;
  }

  // 5
  if(checkPush(G)) {
    playGameOfThrones();
    return;
  }
}

void playHappyBirthday()
{
  int BUZZER_PIN = Buzz;
  int melody[] = {
    NOTE_C4, NOTE_C4, 
    NOTE_D4, NOTE_C4, NOTE_F4,
    NOTE_E4, NOTE_C4, NOTE_C4, 
    NOTE_D4, NOTE_C4, NOTE_G4,
    NOTE_F4, NOTE_C4, NOTE_C4,
    
    NOTE_C5, NOTE_A4, NOTE_F4, 
    NOTE_E4, NOTE_D4, NOTE_AS4, NOTE_AS4,
    NOTE_A4, NOTE_F4, NOTE_G4,
    NOTE_F4
  };

  int durations[] = {
    4, 8, 
    4, 4, 4,
    2, 4, 8, 
    4, 4, 4,
    2, 4, 8,
    
    4, 4, 4, 
    4, 4, 4, 8,
    4, 4, 4,
    2
  };

  int size = sizeof(durations) / sizeof(int);

  for (int note = 0; note < size; note++) {
    //to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int duration = 1000 / durations[note];
    tone(BUZZER_PIN, melody[note], duration);

    //to distinguish the notes, set a minimum time between them.
    //the note's duration + 30% seems to work well:
    int pauseBetweenNotes = duration * 1.30;
    delay(pauseBetweenNotes);
    
    //stop the tone playing:
    noTone(BUZZER_PIN);
  }
}

void playMerryCristmas()
{
    int BUZZER_PIN = Buzz;
    int melody[] = {
    NOTE_E5, NOTE_E5, NOTE_E5,
    NOTE_E5, NOTE_E5, NOTE_E5,
    NOTE_E5, NOTE_G5, NOTE_C5, NOTE_D5,
    NOTE_E5,
    NOTE_F5, NOTE_F5, NOTE_F5, NOTE_F5,
    NOTE_F5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_E5,
    NOTE_E5, NOTE_D5, NOTE_D5, NOTE_E5,
    NOTE_D5, NOTE_G5
  };

  int durations[] = {
    8, 8, 4,
    8, 8, 4,
    8, 8, 8, 8,
    2,
    8, 8, 8, 8,
    8, 8, 8, 16, 16,
    8, 8, 8, 8,
    4, 4
  };
  int size = sizeof(durations) / sizeof(int);

  for (int note = 0; note < size; note++) {
    //to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int duration = 1000 / durations[note];
    tone(BUZZER_PIN, melody[note], duration);

    //to distinguish the notes, set a minimum time between them.
    //the note's duration + 30% seems to work well:
    int pauseBetweenNotes = duration * 1.30;
    delay(pauseBetweenNotes);
    
    //stop the tone playing:
    noTone(BUZZER_PIN);
  }
}

void playHarryPotter()
{
    int BUZZER_PIN = Buzz;
    int melody[] = {
    REST, NOTE_D4,
    NOTE_G4, NOTE_AS4, NOTE_A4,
    NOTE_G4, NOTE_D5,
    NOTE_C5, 
    NOTE_A4,
    NOTE_G4, NOTE_AS4, NOTE_A4,
    NOTE_F4, NOTE_GS4,
    NOTE_D4, 
    NOTE_D4,
    
    NOTE_G4, NOTE_AS4, NOTE_A4,
    NOTE_G4, NOTE_D5,
    NOTE_F5, NOTE_E5,
    NOTE_DS5, NOTE_B4,
    NOTE_DS5, NOTE_D5, NOTE_CS5,
    NOTE_CS4, NOTE_B4,
    NOTE_G4,
    NOTE_AS4,
    
    NOTE_D5, NOTE_AS4,
    NOTE_D5, NOTE_AS4,
    NOTE_DS5, NOTE_D5,
    NOTE_CS5, NOTE_A4,
    NOTE_AS4, NOTE_D5, NOTE_CS5,
    NOTE_CS4, NOTE_D4,
    NOTE_D5, 
    REST, NOTE_AS4,  
    
    NOTE_D5, NOTE_AS4,
    NOTE_D5, NOTE_AS4,
    NOTE_F5, NOTE_E5,
    NOTE_DS5, NOTE_B4,
    NOTE_DS5, NOTE_D5, NOTE_CS5,
    NOTE_CS4, NOTE_AS4,
    NOTE_G4
  };

  int durations[] = {
    2, 4,
    4, 8, 4,
    2, 4,
    2, 
    2,
    4, 8, 4,
    2, 4,
    1, 
    4,
    
    4, 8, 4,
    2, 4,
    2, 4,
    2, 4,
    4, 8, 4,
    2, 4,
    1,
    4,
    
    2, 4,
    2, 4,
    2, 4,
    2, 4,
    4, 8, 4,
    2, 4,
    1, 
    4, 4,  
    
    2, 4,
    2, 4,
    2, 4,
    2, 4,
    4, 8, 4,
    2, 4,
    1
  };
  
  int size = sizeof(durations) / sizeof(int);

  for (int note = 0; note < size; note++) {
    //to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int duration = 1000 / durations[note];
    tone(BUZZER_PIN, melody[note], duration);

    //to distinguish the notes, set a minimum time between them.
    //the note's duration + 30% seems to work well:
    int pauseBetweenNotes = duration * 1.30;
    delay(pauseBetweenNotes);
    
    //stop the tone playing:
    noTone(BUZZER_PIN);
  }
}

void playStarWars()
{
  int BUZZER_PIN = Buzz;

  int melody[] = {
  NOTE_AS4, NOTE_AS4, NOTE_AS4,
  NOTE_F5, NOTE_C6,
  NOTE_AS5, NOTE_A5, NOTE_G5, NOTE_F6, NOTE_C6,
  NOTE_AS5, NOTE_A5, NOTE_G5, NOTE_F6, NOTE_C6,
  NOTE_AS5, NOTE_A5, NOTE_AS5, NOTE_G5, NOTE_C5, NOTE_C5, NOTE_C5,
  NOTE_F5, NOTE_C6,
  NOTE_AS5, NOTE_A5, NOTE_G5, NOTE_F6, NOTE_C6,

  NOTE_AS5, NOTE_A5, NOTE_G5, NOTE_F6, NOTE_C6,
  NOTE_AS5, NOTE_A5, NOTE_AS5, NOTE_G5, NOTE_C5, NOTE_C5,
  NOTE_D5, NOTE_D5, NOTE_AS5, NOTE_A5, NOTE_G5, NOTE_F5,
  NOTE_F5, NOTE_G5, NOTE_A5, NOTE_G5, NOTE_D5, NOTE_E5, NOTE_C5, NOTE_C5,
  NOTE_D5, NOTE_D5, NOTE_AS5, NOTE_A5, NOTE_G5, NOTE_F5,

  NOTE_C6, NOTE_G5, NOTE_G5, REST, NOTE_C5,
  NOTE_D5, NOTE_D5, NOTE_AS5, NOTE_A5, NOTE_G5, NOTE_F5,
  NOTE_F5, NOTE_G5, NOTE_A5, NOTE_G5, NOTE_D5, NOTE_E5, NOTE_C6, NOTE_C6,
  NOTE_F6, NOTE_DS6, NOTE_CS6, NOTE_C6, NOTE_AS5, NOTE_GS5, NOTE_G5, NOTE_F5,
  NOTE_C6
  };

  int durations[] = {
    8, 8, 8,
    2, 2,
    8, 8, 8, 2, 4,
    8, 8, 8, 2, 4,
    8, 8, 8, 2, 8, 8, 8,
    2, 2,
    8, 8, 8, 2, 4,

    8, 8, 8, 2, 4,
    8, 8, 8, 2, 8, 16,
    4, 8, 8, 8, 8, 8,
    8, 8, 8, 4, 8, 4, 8, 16,
    4, 8, 8, 8, 8, 8,

    8, 16, 2, 8, 8,
    4, 8, 8, 8, 8, 8,
    8, 8, 8, 4, 8, 4, 8, 16,
    4, 8, 4, 8, 4, 8, 4, 8,
    1
  };

  int size = sizeof(durations) / sizeof(int);

  for (int note = 0; note < size; note++) {
    //to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int duration = 1000 / durations[note];
    tone(BUZZER_PIN, melody[note], duration);

    //to distinguish the notes, set a minimum time between them.
    //the note's duration + 30% seems to work well:
    int pauseBetweenNotes = duration * 1.30;
    delay(pauseBetweenNotes);

    //stop the tone playing:
    noTone(BUZZER_PIN);
  }
}

void playGameOfThrones()
{
  int BUZZER_PIN = Buzz;
  int melody[] = {
    NOTE_G4, NOTE_C4, NOTE_DS4, NOTE_F4, NOTE_G4, NOTE_C4, NOTE_DS4, NOTE_F4,
    NOTE_G4, NOTE_C4, NOTE_DS4, NOTE_F4, NOTE_G4, NOTE_C4, NOTE_DS4, NOTE_F4,
    NOTE_G4, NOTE_C4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_C4, NOTE_E4, NOTE_F4,
    NOTE_G4, NOTE_C4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_C4, NOTE_E4, NOTE_F4,
    NOTE_G4, NOTE_C4,
    
    NOTE_DS4, NOTE_F4, NOTE_G4, NOTE_C4, NOTE_DS4, NOTE_F4,
    NOTE_D4,
    NOTE_F4, NOTE_AS3,
    NOTE_DS4, NOTE_D4, NOTE_F4, NOTE_AS3,
    NOTE_DS4, NOTE_D4, NOTE_C4,
    
    NOTE_G4, NOTE_C4,
    
    NOTE_DS4, NOTE_F4, NOTE_G4, NOTE_C4, NOTE_DS4, NOTE_F4,
    NOTE_D4,
    NOTE_F4, NOTE_AS3,
    NOTE_DS4, NOTE_D4, NOTE_F4, NOTE_AS3,
    NOTE_DS4, NOTE_D4, NOTE_C4,
    NOTE_G4, NOTE_C4,
    NOTE_DS4, NOTE_F4, NOTE_G4,  NOTE_C4, NOTE_DS4, NOTE_F4,
    
    NOTE_D4,
    NOTE_F4, NOTE_AS3,
    NOTE_D4, NOTE_DS4, NOTE_D4, NOTE_AS3,
    NOTE_C4,
    NOTE_C5,
    NOTE_AS4,
    NOTE_C4,
    NOTE_G4,
    NOTE_DS4,
    NOTE_DS4, NOTE_F4,
    NOTE_G4,
    
    NOTE_C5,
    NOTE_AS4,
    NOTE_C4,
    NOTE_G4,
    NOTE_DS4,
    NOTE_DS4, NOTE_D4,
    NOTE_C5, NOTE_G4, NOTE_GS4, NOTE_AS4, NOTE_C5, NOTE_G4, NOTE_GS4, NOTE_AS4,
    NOTE_C5, NOTE_G4, NOTE_GS4, NOTE_AS4, NOTE_C5, NOTE_G4, NOTE_GS4, NOTE_AS4,
    
    REST, NOTE_GS5, NOTE_AS5, NOTE_C6, NOTE_G5, NOTE_GS5, NOTE_AS5,
    NOTE_C6, NOTE_G5, NOTE_GS5, NOTE_AS5, NOTE_C6, NOTE_G5, NOTE_GS5, NOTE_AS5
  };

  int durations[] = {
    8, 8, 16, 16, 8, 8, 16, 16,
    8, 8, 16, 16, 8, 8, 16, 16,
    8, 8, 16, 16, 8, 8, 16, 16,
    8, 8, 16, 16, 8, 8, 16, 16,
    4, 4,
    
    16, 16, 4, 4, 16, 16,
    1,
    4, 4,
    16, 16, 4, 4,
    16, 16, 1,
    
    4, 4,
    
    16, 16, 4, 4, 16, 16,
    1,
    4, 4,
    16, 16, 4, 4,
    16, 16, 1,
    4, 4,
    16, 16, 4, 4, 16, 16,
    
    2,
    4, 4,
    8, 8, 8, 8,
    1,
    2,
    2,
    2,
    2,
    2,
    4, 4,
    1,
    
    2,
    2,
    2,
    2,
    2,
    4, 4,
    8, 8, 16, 16, 8, 8, 16, 16,
    8, 8, 16, 16, 8, 8, 16, 16,
    
    4, 16, 16, 8, 8, 16, 16,
    8, 16, 16, 16, 8, 8, 16, 16
  };
  
  int size = sizeof(durations) / sizeof(int);

  for (int note = 0; note < size; note++) {
    //to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int duration = 1000 / durations[note];
    tone(BUZZER_PIN, melody[note], duration);

    //to distinguish the notes, set a minimum time between them.
    //the note's duration + 30% seems to work well:
    int pauseBetweenNotes = duration * 1.30;
    delay(pauseBetweenNotes);

    //stop the tone playing:
    noTone(BUZZER_PIN);
  }
}



