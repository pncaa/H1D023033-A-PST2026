const int segmentPins[8] = {2, 3, 4, 5, 6, 7, 8};

const int ledMerah = 9;
const int ledKuning = 10;


const int tombol = 11;

byte digitPattern[16][8] = {

{1,1,1,1,1,1,0,0}, //0
{0,1,1,0,0,0,0,0}, //1
{1,1,0,1,1,0,1,0}, //2
{1,1,1,1,0,0,1,0}, //3
{0,1,1,0,0,1,1,0}, //4
{1,0,1,1,0,1,1,0}, //5
{1,0,1,1,1,1,1,0}, //6
{1,1,1,0,0,0,0,0}, //7
{1,1,1,1,1,1,1,0}, //8
{1,1,1,1,0,1,1,0}, //9
};

void setup() {

  pinMode(ledMerah, OUTPUT);
  pinMode(ledKuning, OUTPUT);

  pinMode(tombol, INPUT_PULLUP);

  for (int i = 0; i < 7; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }

  kondisiNormal();

}

void loop() {
    if (digitalRead(tombol) == LOW) {

    delay(50); // debounce

    if (digitalRead(tombol) == LOW) {

      mulaiPenyeberangan();

      // Tunggu tombol dilepas
      while (digitalRead(tombol) == LOW);
    }
  }
}

void mulaiPenyeberangan() {

  digitalWrite(ledKuning, LOW);
  digitalWrite(ledMerah, HIGH);
  for (int i = 9; i >= 0; i--) {

    tampilkanAngka(i);
    delay(1000);
  }
  digitalWrite(ledMerah, LOW);
  kondisiNormal();
}


  for (int i = 0; i < 7; i++) {

    digitalWrite(segmentPins[i], angka[num][i]);
  }
}



