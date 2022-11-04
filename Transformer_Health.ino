/*
Calculating the life of the transformer.
*/

float temp_amb;
const int PT100_PIN = A1;
const float vt_factor = 1.88;
const float offset = -18;
float temp_hst;
float R;
const float B=15000;
const float NIL=20.55;
int href=95;
float C,D,LOL,FAA,RL;
int t=1;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println(&quot;CLEARDATA&quot;);
  Serial.println(&quot;Voltage , Resistance, H_Temperature, Amb_Temperature, RLife&quot;);
}
void loop() {
  // put your main code here, to run repeatedly:
  temp_amb = analogRead(A0);
  temp_amb = temp_amb * 0.48828125;
  int sensorvalue = analogRead(PT100_PIN);
  float voltage = sensorvalue * (5.0 / 1023.0);
  temp_hst = (((voltage * 100)/ vt_factor)+offset);
  R=(100*(1+(0.00385*temp_hst)));
  C=B/(href+273);
  D=B/(temp_hst+273);
  FAA=exp(C-D);
  LOL=(FAA*t*100)/NIL;
  if(FAA&gt;=1)
  {
    RL=NIL/FAA;
  }
  else{
    RL=NIL;
  }
  Serial.print(voltage);
  Serial.print(&quot;,&quot;);
  Serial.print(R);
  Serial.print(&quot;,&quot;);
  //Serial.print(&quot;HST_Temp: &quot;);
  Serial.print(temp_hst);
  //Serial.print(&quot;c&quot;);
  Serial.print(&quot;,&quot;);
  Serial.print(temp_amb);
  Serial.print(&quot;,&quot;);
  Serial.print(RL);
  Serial.println();
  delay(1000);
}