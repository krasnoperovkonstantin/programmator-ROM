// address counter
//
// A0/PC0- reset
// A1/PC1 - count
// 0-13 - address bus A0-A13

byte count_pin, count_pin_store;

void setup() {
  DDRD = 0xFF;
  DDRB = 0b00111111;
  PORTC = 0b00000011;

}

void loop() {
  if(!(PINC & 0b00000001)) {
    PORTB = 0x00;
    PORTD = 0x00;
  } else {
    count_pin = PINC & 0b00000010;
    if (count_pin != count_pin_store) {
      count_pin_store = count_pin;
      if(!count_pin) {
        if (PORTD == 0xFF) {
          PORTD = 0x00;
          PORTB++;
        } else {
          PORTD++;
        }
      }
    }
  }
}
