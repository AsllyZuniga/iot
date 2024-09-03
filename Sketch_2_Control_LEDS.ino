#define GREEN_LED 11
#define RED_LED 12
#define YELLOW_LED 13

bool blinking = false;

void setup() {
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);

  Serial.begin(9600);
  
  Serial.println("MAIN MENU");
  Serial.println("[1]. Turn on green light");
  Serial.println("[2]. Turn off green light");
  Serial.println("[3]. Turn on red light");
  Serial.println("[4]. Turn off red light");
  Serial.println("[5]. Turn on yellow light");
  Serial.println("[6]. Turn off yellow light");
  Serial.println("[7]. Turn on all lights");
  Serial.println("[8]. Turn off all lights");
  Serial.println("[9]. Blinking mode");
}

void loop() {
  if (Serial.available() > 0) { 
    char opt = Serial.read();
    
    // Detener parpadeo si se recibe un comando diferente a [9]
    if (opt != '9') {
      blinking = false;
    }

    switch (opt) {
      case '1': // Turn on green light
        digitalWrite(GREEN_LED, HIGH);
        digitalWrite(RED_LED, LOW);
        digitalWrite(YELLOW_LED, LOW);
        Serial.println("Green light on");
        break;
      case '2': // Turn off green light
        digitalWrite(GREEN_LED, LOW);
        Serial.println("Green light off");
        break;
      case '3': // Turn on red light
        digitalWrite(RED_LED, HIGH);
        digitalWrite(GREEN_LED, LOW);
        digitalWrite(YELLOW_LED, LOW);
        Serial.println("Red light on");
        break;
      case '4': // Turn off red light
        digitalWrite(RED_LED, LOW);
        Serial.println("Red light off");
        break;
      case '5': // Turn on yellow light
        digitalWrite(YELLOW_LED, HIGH);
        digitalWrite(RED_LED, LOW);
        digitalWrite(GREEN_LED, LOW);
        Serial.println("Yellow light on");
        break;
      case '6': // Turn off yellow light
        digitalWrite(YELLOW_LED, LOW);
        Serial.println("Yellow light off");
        break;
      case '7': // Turn on all lights
        turnOnAll();
        Serial.println("All lights on");
        break;
      case '8': // Turn off all lights
        turnOffAll();
        Serial.println("All lights off");
        break;
      case '9': // Blinking mode
        blinking = true;
        Serial.println("Blinking mode activated");
        break;
      default:
        Serial.println("Command not recognized");
        break;
    }
  }

  if (blinking) {
    blinkingMode();
  }
}

// Function to turn on all lights
void turnOnAll() {
  digitalWrite(GREEN_LED, HIGH);
  digitalWrite(RED_LED, HIGH);
  digitalWrite(YELLOW_LED, HIGH);
}

// Function to turn off all lights
void turnOffAll() {
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(RED_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);
}

// Function to activate blinking mode
void blinkingMode() {
  turnOnAll();
  delay(500); 
  turnOffAll();
  delay(500); 
}
