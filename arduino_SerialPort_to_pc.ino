unsigned long time_now = 0;
unsigned long time1_ant = 0, time2_ant = 0;
unsigned long count = 0;
float sum1 = 0, sum2 = 0;
char comando;
byte Relay_pin = 3;
byte sensor_pin = A0;
double output1, output2;
double avarage1, avarage2;

// Configure the relay digital pin, and the serial port interface
void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);  
//  pinMode(3, INPUT);
//  pinMode(A0, INPUT);
}

// Loop function
void loop() 
{
    time_now = millis(); // time in milliseconds from when the Arduino turns on
    
    // First: check if there is any command from the computer to control the relay
    if (Serial.available() > 0)
    {
        // Read the message from the serial port
//        double sensor_output = analogRead(sensor_pin); 
        double realy_output = digitalRead(Relay_pin); 
//        comando = Serial.read();
        
        // if the message, correspond to the command 'H' or 'L', change the state of the output pin 
        if (realy_output == 'H') {
          digitalWrite(Relay_pin, LOW);
          }
        else if (realy_output == 'L') {
          output1 = 0;
          digitalWrite(Relay_pin, HIGH);
        }
        output2 = analogRead(sensor_pin); 
         
    }

    // Each 1 second, measure the A0 and A1 ports
    if (time_now - time1_ant > 1000) 
    {
      double output1 = analogRead(sensor_pin); 
      double output2 = digitalRead(Relay_pin); 
      // Increment the time counter
      count++;
      // Acumulate the ADC measurements each second, to calculate latter and average value each 5 seconds
      sum1 += output1;
      sum2 += output2; 
      // Udpate the "1 second" time flag
      time1_ant = time_now;
    }

    // Each 5 seconds, calculate the average value of the A0 and A1 measurments, and the state of the relay output pin
    // and write the values with the serial port using semicolons to separte them
    if (time_now - time2_ant > 5000) 
    {
      avarage1 = sum1/count;
      avarage2 = sum2/count;
      Serial.print(avarage1);
      Serial.print(";");
      Serial.print(avarage2);
      Serial.println();
      // Reset the variables to calculate the avarage results
      sum1 = 0;
      sum2 = 0;
      // Reset the time counter and update the "5 second" time flag
      count = 0;
      time2_ant = time_now;
    }
}
