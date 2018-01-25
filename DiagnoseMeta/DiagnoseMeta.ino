#include <Gamebuino-Meta.h>

Image buttonsIcons = Image(Gamebuino_Meta::buttonsIconsData);
Image arrowsIcons = Image(Gamebuino_Meta::arrowsIconsData);

void setup() {
  gb.begin();
  gb.sound.playTick();
}

void loop() {
  while (!gb.update());
  gb.display.clear();

  drawLights();
  drawButtons();
  draw13();
  drawSound();
  //drawSDCS();
}

void drawButtons() {
  //BUTTON A
  if (gb.buttons.repeat(BUTTON_A, 1)) {
    buttonsIcons.setFrame(1); //pressed
    gb.sound.playTick();
  } else {
    buttonsIcons.setFrame(0);
  }
  gb.display.drawImage(58, 35, buttonsIcons);

  //BUTTON B
  if (gb.buttons.repeat(BUTTON_B, 1)) {
    buttonsIcons.setFrame(3); //pressed
    gb.sound.playTick();
  } else {
    buttonsIcons.setFrame(2);
  }
  gb.display.drawImage(70, 30, buttonsIcons);

  //BUTTON MENU
  if (gb.buttons.repeat(BUTTON_MENU, 1)) {
    buttonsIcons.setFrame(5); //pressed
    gb.sound.playTick();
  } else {
    buttonsIcons.setFrame(4);
  }
  gb.display.drawImage(2, 55, buttonsIcons);

  //BUTTON HOME
  if (gb.buttons.repeat(BUTTON_HOME, 1)) {
    //gb.buttons.states[(int)BUTTON_HOME] = 0; //disable home menu
    buttonsIcons.setFrame(7); //pressed
    gb.sound.playTick();
  } else {
    buttonsIcons.setFrame(6);
  }
  gb.display.drawImage(62, 55, buttonsIcons);

  int arrowX = 0;
  int arrowY = 28;

  //ARROW DOWN
  if (gb.buttons.repeat(BUTTON_DOWN, 1)) {
    arrowsIcons.setFrame(1); //pressed
    gb.sound.playTick();
  } else {
    arrowsIcons.setFrame(0);
  }
  gb.display.drawImage(arrowX + 5, arrowY + 10, arrowsIcons);

  //ARROW LEFT
  if (gb.buttons.repeat(BUTTON_LEFT, 1)) {
    arrowsIcons.setFrame(3); //pressed
    gb.sound.playTick();
  } else {
    arrowsIcons.setFrame(2);
  }
  gb.display.drawImage(arrowX, arrowY + 5, arrowsIcons);

  //ARROW RIGHT
  if (gb.buttons.repeat(BUTTON_RIGHT, 1)) {
    arrowsIcons.setFrame(5); //pressed
    gb.sound.playTick();
  } else {
    arrowsIcons.setFrame(4);
  }
  gb.display.drawImage(arrowX + 10, arrowY + 5, arrowsIcons);

  //ARROW UP
  if (gb.buttons.repeat(BUTTON_UP, 1)) {
    arrowsIcons.setFrame(7); //pressed
    gb.sound.playTick();
  } else {
    arrowsIcons.setFrame(6);
  }
  gb.display.drawImage(arrowX + 5, arrowY, arrowsIcons);
}

void drawLights() {
  switch ((gb.frameCount / 20) % 5) {
    case 0:
      gb.lights.fill((Color)0x39E7); //white
      gb.display.fill((Color)0x39E7); //white
      break;
    case 1:
      gb.lights.fill((Color)0x7800); //red
      gb.display.fill((Color)0x7800); //red
      break;
    case 2:
      gb.lights.fill((Color)0x03E0); //green
      gb.display.fill((Color)0x03E0); //green
      break;
    case 3:
      gb.lights.fill((Color)0x000F); //blue
      gb.display.fill((Color)0x000F); //blue
      break;
    case 4:
      gb.lights.fill((Color)0x0000); //black
      gb.display.fill((Color)0x0000); //black
      break;
  }
}

void draw13() {
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  delay(30);
  digitalWrite(13, HIGH);
  pinMode(13, INPUT);
}

void drawSDCS() {
  pinMode(SD_CS, OUTPUT);
  delay(30);
  digitalWrite(SD_CS, LOW);
  delay(30);
  digitalWrite(SD_CS, HIGH);
}

void drawSound(){
  if((gb.frameCount%25) == 0){
    gb.sound.playOK();
  }
}

