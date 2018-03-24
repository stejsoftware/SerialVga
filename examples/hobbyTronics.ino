#include <Arduino.h>
#include <SerialVga.h>
#include <Color.h>

/*
  serialVGA - Test program for communicating with Hobbytronics serialVGA board
  
  Creates 5 windows and displays data
  
  Copyright www.hobbytronics.co.uk 2012
*/

unsigned long currentTime;
unsigned long loopTime;
unsigned int counter = 0;
unsigned long number_sum = 0;
unsigned long number_avg = 0;

void setup()
{
    // initialize
    SerialVga.begin(9600);                // Set baud rate for serialVGA board
    SerialVga.reboot();                   // reboot VGA board
    SerialVga.window(1, 0, 0, 100, 3, 1); // Create header
    SerialVga.print("                        ");
    SerialVga.print("HobbyTronics serialVGA Driver board Demonstration");
    SerialVga.window(2, 0, 3, 70, 32, 1, "Raw Data Display");   // Create Window2
    SerialVga.window(3, 70, 3, 30, 32, 1, "Calculated Values"); // Create Window3
    SerialVga.window(4, 0, 35, 100, 14, 1, "Terminal Input");   // Create Window4
    SerialVga.cursor(4, true);                                  // Turn text cursor ON in window 4
    SerialVga.window(5, 0, 49, 100, 1, 0);                      // Create footer
    SerialVga.print(" Hobbytronics Ltd                     www.hobbytronics.co.uk");
    SerialVga.print("                         serialVGA demo");
    SerialVga.lineColor(0, 2, Color::White, Color::Purple); // header window colour
    SerialVga.lineColor(35, 48, Color::White, Color::Blue); // window 4 colour
    SerialVga.lineColor(49, Color::Black, Color::Gray);     // footer window colour
    
    currentTime = millis();
    loopTime = currentTime;
}

void loop()
{
    currentTime = millis();

    if (currentTime >= (loopTime + 500))
    {
        // send every half second
        loopTime = currentTime; // Updates loopTime

        SerialVga.focus(2);                 // Set Window2 as focus
        SerialVga.print("This is data - "); // print data
        SerialVga.println(counter, DEC);

        SerialVga.focus(3);                   // Set Window3 as focus
        SerialVga.position(0, 0);             // Set Window3 text position to 0,0
        SerialVga.inverse("Summary of Data"); // print title in reverse
        SerialVga.print("\r\n\r\n");          // send 2x CR to move down 2 lines
        SerialVga.print("Largest Number - "); // print data
        SerialVga.println(counter, DEC);
        SerialVga.print("SUM of Numbers - "); // print data
        SerialVga.println(number_sum, DEC);
        SerialVga.print("AVG of Numbers - "); // print data
        SerialVga.println(number_avg, DEC);

        counter++;
        number_sum += counter;
        number_avg = number_sum / counter;
    }

    if (Serial.available() > 0)
    {
        // Data received into Arduino board, echo'd out to Window 4 (command window)
        int inByte = Serial.read();
        SerialVga.focus(4); // Set Window4 as focus
        SerialVga.write(inByte);
    }
}