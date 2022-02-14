#include <deprecated.h>
#include <MFRC522.h>
#include <MFRC522Extended.h>
#include <require_cpp11.h>

#include <Servo.h>

#include <SPI.h>

int  pos = 0;
Servo servo_9;
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);

void setup() {
  servo_9.attach(6);
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  Serial.println("put your card to the reader .....");
  Serial.println();

}
void loop() {
  if (!mfrc522.PICC_IsNewCardPresent())
  {
    return ;
  }

  if (!mfrc522.PICC_ReadCardSerial())
  {
    return ;
  }

  Serial.println("UID tag");
  String content = "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++)
  {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
    content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));

    content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.println("Message : ");
  content.toUpperCase();
  if (content.substring(1) == "B3 35 5B 11")
  {
    for (pos = 90; pos >= 0; pos--)
    {
      servo_9.write(pos);
      delay(15);
    };
    delay(3000);

    for (pos = 0; pos <= 90; pos++)
    {
      servo_9.write(pos);
      delay(15);
    };
    delay(500);
    Serial.println("Authorized access");
    Serial.println();
    delay(400);
  }
  else {

    Serial.println("Authorized denied");
  }
}
