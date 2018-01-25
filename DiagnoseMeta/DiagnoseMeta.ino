#include <Gamebuino-Meta.h>

Image buttonsIcons = Image(Gamebuino_Meta::buttonsIconsData);
Image arrowsIcons = Image(Gamebuino_Meta::arrowsIconsData);

void setup() {
  gb.begin();
}

void loop() {

  while (!gb.update());
  gb.display.clear();

  //BUTTON A
  if (gb.buttons.repeat(BUTTON_A, 1)) {
    buttonsIcons.setFrame(1); //pressed
    gb.sound.playOK();
  } else {
    buttonsIcons.setFrame(0);
  }
  gb.display.drawImage(58,35, buttonsIcons);
  
  //BUTTON B
  if (gb.buttons.repeat(BUTTON_B, 1)) {
    buttonsIcons.setFrame(3); //pressed
    gb.sound.playOK();
  } else {
    buttonsIcons.setFrame(2);
  }
  gb.display.drawImage(70,30, buttonsIcons);
  
  //BUTTON MENU
  if (gb.buttons.repeat(BUTTON_MENU, 1)) {
    buttonsIcons.setFrame(5); //pressed
    gb.sound.playOK();
  } else {
    buttonsIcons.setFrame(4);
  }
  gb.display.drawImage(2,55, buttonsIcons);
  
  //BUTTON HOME
  if (gb.buttons.repeat(BUTTON_HOME, 1)) {
    gb.buttons.states[(int)BUTTON_HOME] = 0;
    buttonsIcons.setFrame(7); //pressed
    gb.sound.playOK();
  } else {
    buttonsIcons.setFrame(6);
  }
  gb.display.drawImage(62,55, buttonsIcons);

  int arrowX = 0;
  int arrowY = 30;
  
  //ARROW DOWN
  if (gb.buttons.repeat(BUTTON_DOWN, 1)) {
    arrowsIcons.setFrame(1); //pressed
    gb.sound.playOK();
  } else {
    arrowsIcons.setFrame(0);
  }
  gb.display.drawImage(arrowX + 5, arrowY + 10, arrowsIcons);

  //ARROW LEFT
  if (gb.buttons.repeat(BUTTON_LEFT, 1)) {
    arrowsIcons.setFrame(3); //pressed
    gb.sound.playOK();
  } else {
    arrowsIcons.setFrame(2);
  }
  gb.display.drawImage(arrowX,arrowY + 5, arrowsIcons);

  //ARROW RIGHT
  if (gb.buttons.repeat(BUTTON_RIGHT, 1)) {
    arrowsIcons.setFrame(5); //pressed
    gb.sound.playOK();
  } else {
    arrowsIcons.setFrame(4);
  }
  gb.display.drawImage(arrowX + 10, arrowY + 5, arrowsIcons);

  //ARROW UP
  if (gb.buttons.repeat(BUTTON_UP, 1)) {
    arrowsIcons.setFrame(7); //pressed
    gb.sound.playOK();
  } else {
    arrowsIcons.setFrame(6);
  }
  gb.display.drawImage(arrowX + 5, arrowY, arrowsIcons);
  
  

}

