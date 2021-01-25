/*
 * Nom: compteur 32 bits
 * Copyright (C) 2005 Matthew Khouzam
 * License http://www.gnu.org/copyleft/gpl.html GNU/GPL
 * Description: Ceci est un exemple simple de programme 
 * Version: 1.1
 */

#define F_CPU 8000000UL


#include <avr/io.h> 
#include <util/delay.h>

int main()
{
  DDRA = 0xFF; // PORT A est en mode sortie
  DDRD = 0x00; // PORT D est en mode entrée
  
  bool debounceCheck = false;

  while(true)  // boucle sans fin
  {
    //Wait 10 ms
    _delay_ms(10);

    //If the pin D is on and it was 10 ms ago
    if((PIND & 0x04) && debounceCheck)
    {
      _delay_ms(100);
      //Adding to port A make the led flicker
      PORTA++;
    }

    debounceCheck = PIND & 0x04;
  }

  return 0; 
}

