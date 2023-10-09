void pistonSetup()
{
  pinMode(pistonPin1, OUTPUT);
  pinMode(pistonPin2, OUTPUT);
  pinMode(pistonPin3, OUTPUT);
  pinMode(pistonPin4, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(buzzerPin, LOW);
  digitalWrite(ledPin, LOW);
  digitalWrite(pistonPin1, LOW);
  digitalWrite(pistonPin2, LOW);
  digitalWrite(pistonPin3, LOW);
  digitalWrite(pistonPin4, LOW);
}

void TZ1Piston()
{
  digitalWrite(pistonPin4, HIGH);
  delay(1000);
  digitalWrite(buzzerPin, HIGH);
  digitalWrite(ledPin, HIGH);
  delay(200);
  digitalWrite(pistonPin1, HIGH);
  delay(2000);
  digitalWrite(pistonPin4, LOW);
  digitalWrite(pistonPin1, LOW);
  digitalWrite(buzzerPin, LOW);
  digitalWrite(ledPin, LOW);
}

void TZ2Piston()
{
  digitalWrite(pistonPin4, HIGH);
  delay(1000);
  digitalWrite(buzzerPin, HIGH);
  digitalWrite(ledPin, HIGH);
  delay(200);
  digitalWrite(pistonPin2, HIGH);
  delay(2000);
  digitalWrite(pistonPin4, LOW);
  digitalWrite(pistonPin2, LOW);
  digitalWrite(buzzerPin, LOW);
  digitalWrite(ledPin, LOW);
}

void TZ3Piston()
{
  digitalWrite(pistonPin4, HIGH);
  delay(1000);
  digitalWrite(buzzerPin, HIGH);
  digitalWrite(ledPin, HIGH);
  delay(200);
  digitalWrite(pistonPin3, HIGH);
  delay(2000);
  digitalWrite(pistonPin4, LOW);
  digitalWrite(pistonPin3, LOW);
  digitalWrite(buzzerPin, LOW);
  digitalWrite(ledPin, LOW);
}

