// for optical communication experiment
// with two LEDs
// one as Tx and the other as Rx
// 20201230 jeffy890

void setup() {
  boolean m[512];
  boolean val;
  int Rx_data[512];
  int i;
  int threshold = 400;
  int ber = 0;
  
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);

  Mseq(m);

  digitalWrite(2, LOW);
  for (i = 0; i < 512; i++) {
    digitalWrite(3, m[i]);
    delay(10);
    Rx_data[i] = analogRead(A0);
  }
  digitalWrite(2, HIGH);
  
  for (i = 0; i < 512; i++) {
    Serial.print(Rx_data[i]);
    Serial.print("   ");
    Serial.println(m[i]);
    if(Rx_data[i]>threshold) val =true;
    else val = false;

    if(val != m[i]) ber += 1;
  }
  Serial.print("ber : ");
  Serial.println(ber);
}

void loop() {
}

void Mseq(boolean *m) {
  int i, j; //for counting
  int leng = 512;

  boolean m9[9] = {1, 1, 1, 1, 1, 1, 1, 1, 1};  //for storing data right before outputting
  for (i = 0; i < leng - 2; i++) {
    m[i] = m9[8];  //output 1bit data
    for (j = 9; j > 1; j--) {
      m9[j - 1] = m9[j - 2]; //1bit shift
    }
    m9[0] = m9[5] ^ m[i]; //xor

  }
  m[leng-1] = 0;  //last bit is 0
}
