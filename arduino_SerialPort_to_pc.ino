unsigned long time_now = 0;
unsigned long time1_ant = 0, time2_ant = 0;
unsigned long count = 0;
float sum1 = 0, sum2 = 0;
char comando;

// Configure the relay digital pin, and the serial port interface
void setup() 
{

}

// Loop function
void loop() 
{
    // Check the current time in miliseconds
    time_now = 

    // First: check if there is any command from the computer to control the relay
    if (Serial.available() > 0)
    {
        // Read the message from the serial port

        // If the message, correspond to the command 'H' or 'L', change the state of the output pin

    }

    // Each 1 second, measure the A0 and A1 ports
    if (time_now - time1_ant > 1000) 
    {
      // Increment the time counter
      count++;
      // Acumulate the ADC measurements each second, to calculate latter and average value each 5 seconds
      sum1 += ;
      sum2 += ;
      // Udpate the "1 second" time flag
      time1_ant = time_now;
    }

    // Each 5 seconds, calculate the average value of the A0 and A1 measurments, and the state of the relay output pin
    // and write the values with the serial port using semicolons to separte them
    if (time_now - time2_ant > 5000) 
    {

      Serial.println(";");
      // Reset the variables to calculate the avarage results
      sum1 = 0;
      sum2 = 0;
      // Reset the time counter and update the "5 second" time flag
      count = 0;
      time2_ant = time_now;
    }
}
