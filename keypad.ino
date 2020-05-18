#include <Keyboard.h>
byte rows[] = {2, 3, 4};
byte cols[] = {5, 6, 7};
const int num_rows = sizeof(rows)/sizeof(rows[0]);
const int num_cols = sizeof(cols)/sizeof(cols[0]);


bool key_states[num_rows][num_cols];

void setup() {
  Keyboard.begin();
  init_pins();
  init_key_states();
}

void loop() {
  read_key_states();
  delay(10); // time to debounce
}

void init_pins() {
  for (int r = 0; r < num_rows; r++) {
    pinMode(rows[r], INPUT_PULLUP);
  }
  for (int c = 0; c < num_cols; c++) {
    pinMode(cols[c], INPUT_PULLUP);
  }
}

void init_key_states() {
  for (int r = 0; r < num_rows; r++) {
    for (int c = 0; c < num_cols; c++) {
      key_states[r][c] = 0;
    }
  }
}

void read_key_states() {
  for (int c = 0; c < num_cols; c++) {
    pinMode(cols[c], OUTPUT);
    digitalWrite(cols[c], LOW);
    
    for (int r = 0; r < num_rows; r++) {
      bool state = (digitalRead(rows[r]) == LOW);
      if (!key_states[r][c] && state) {
        press(r, c);
      } else if (key_states[r][c] && ! state) {
        release(r, c);
      }
      key_states[r][c] = state;
    }
    
    pinMode(cols[c], INPUT_PULLUP);
  }
}

void press(int row, int col) {
  switch (row * num_cols + col) {
    case 0: 
      Keyboard.press('0');
      break;
    case 1:
      Keyboard.press('1');
      break;
    case 2:
      Keyboard.press('2');
      break;
    case 3:
      Keyboard.press('3');
      break;
    case 4:
      Keyboard.press('4');
      break;
    case 5:
      Keyboard.press('5');
      break;
    case 6:
      Keyboard.press('6');
      break;
    case 7:
      Keyboard.press('7');
      break;
    case 8:
      Keyboard.press('8');
      break;
  }
}
void release(int row, int col) {
  switch (row * num_cols + col) {
    case 0:
      Keyboard.release('0');
      break;
    case 1:
      Keyboard.release('1');
      break;
    case 2:
      Keyboard.release('2');
      break;
    case 3:
      Keyboard.release('3');
      break;
    case 4:
      Keyboard.release('4');
      break;
    case 5:
      Keyboard.release('5');
      break;
    case 6:
      Keyboard.release('6');
      break;
    case 7:
      Keyboard.release('7');
      break;
    case 8:
      Keyboard.release('8');
      break;
  }
}
