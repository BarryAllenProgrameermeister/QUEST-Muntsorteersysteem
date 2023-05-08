// TCS230 or TCS3200 pins wiring to Arduino
#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define SENSOR_OUT 8

// Stores frequency read by the photodiodes
int redFrequency = 0;
int greenFrequency = 0;
int blueFrequency = 0;

bool WitGeweest= false;
bool goudGeweest= false;
bool zilverGeweest= false;
bool roodGeweest= false;
bool blauwGeweest= false;
bool groenGeweest= false;

void setup() {
// Setting the outputs
pinMode(S0, OUTPUT);
pinMode(S1, OUTPUT);
pinMode(S2, OUTPUT);
pinMode(S3, OUTPUT);

// Setting the sensorOut as an input
pinMode(SENSOR_OUT, INPUT);

// Setting frequency scaling to 100%
digitalWrite(S0, HIGH);
digitalWrite(S1, LOW);

// Begins serial communication
Serial.begin(9600);
}

void loop() {
// Setting RED (R) filtered photodiodes to be read
digitalWrite(S2, LOW);
digitalWrite(S3, LOW);

// Reading the output frequency
redFrequency = pulseIn(SENSOR_OUT, LOW);

// Setting GREEN (G) filtered photodiodes to be read
digitalWrite(S2, HIGH);
digitalWrite(S3, HIGH);

// Reading the output frequency
greenFrequency = pulseIn(SENSOR_OUT, LOW);

// Setting BLUE (B) filtered photodiodes to be read
digitalWrite(S2, LOW);
digitalWrite(S3, HIGH);

// Reading the output frequency
blueFrequency = pulseIn(SENSOR_OUT, LOW);

//redFrequency=redFrequency/100;
//greenFrequency=greenFrequency/100;
//blueFrequency=blueFrequency/100;

// Printing RGB values
//Serial.print("R = ");
//Serial.print(redFrequency);
//Serial.print(" G = ");
//Serial.print(greenFrequency);
//Serial.print(" B = ");
//Serial.println(blueFrequency);

// Identifying colors based on RGB values
if (redFrequency > 2800 && redFrequency < 4000 &&
greenFrequency > 1500 && greenFrequency < 2150 &&
blueFrequency > 600 && blueFrequency < 900) {
  if(!groenGeweest)
  {
    Serial.println("Green");
  }
   groenGeweest= true;
}

if (redFrequency > 750 && redFrequency < 1200 &&
greenFrequency > 1100 && greenFrequency < 1800 &&
blueFrequency > 300 && blueFrequency < 550) {
  if(!goudGeweest)
  {
    Serial.println("Goud");
  }
   goudGeweest= true;
}

if (redFrequency > 500 && redFrequency < 1100 &&
greenFrequency > 2400 && greenFrequency < 3300 &&
blueFrequency > 300 && blueFrequency < 700) {
  if(!roodGeweest)
  {
    Serial.println("rood");
    WitGeweest= false;
    goudGeweest= false;
    zilverGeweest= false;
    roodGeweest= false;
    blauwGeweest= false;
    groenGeweest= false;
  }
     roodGeweest= true;
}

if (redFrequency > 3900 && redFrequency < 5100 &&
greenFrequency > 2100 && greenFrequency < 3000 &&
blueFrequency > 300 && blueFrequency < 800) {
  if(!blauwGeweest)
  {
    Serial.println("blauw");
     WitGeweest= false;
    goudGeweest= false;
    zilverGeweest= false;
    roodGeweest= false;
    blauwGeweest= false;
    groenGeweest= false;
  }
     blauwGeweest= true;
}

if (redFrequency > 1300 && redFrequency < 1550 &&
greenFrequency > 1000 && greenFrequency < 1300 &&
blueFrequency > 200 && blueFrequency < 400) {
  if(!zilverGeweest)
  {
    Serial.println("zilver");
     WitGeweest= false;
    goudGeweest= false;
    zilverGeweest= false;
    roodGeweest= false;
    blauwGeweest= false;
    groenGeweest= false;
 }
     zilverGeweest= true;
}

if (redFrequency > 200 && redFrequency < 300 &&
greenFrequency > 250 && greenFrequency < 350 &&
blueFrequency > 1 && blueFrequency < 150) {

   if(!WitGeweest)
  {
    Serial.println("wit");
     WitGeweest= false;
    goudGeweest= false;
    zilverGeweest= false;
    roodGeweest= false;
    blauwGeweest= false;
    groenGeweest= false;
  }
   WitGeweest= true;
}

// Adding a delay to prevent flooding the serial monitor with data
delay(8);
}
