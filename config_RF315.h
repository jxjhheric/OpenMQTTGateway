/*  
  OpenMQTTGateway  - ESP8266 or Arduino program for home automation 

   Act as a wifi or ethernet gateway between your 433mhz/infrared IR signal  and a MQTT broker 
   Send and receiving command by MQTT
 
   This files enables to set your parameter for the radiofrequency gateways (ZgatewayRF and ZgatewayRF2) with RCswitch and newremoteswitch library
  
    Copyright: (c)Florian ROBERT
  
    This file is part of OpenMQTTGateway.
    
    OpenMQTTGateway is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenMQTTGateway is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/*-------------------RF topics & parameters----------------------*/
//315Mhz MQTT Subjects and keys
#define subjectMQTTtoRF315 "home/commands/MQTTto315"
#define subjectRF315toMQTT "home/315toMQTT"
#define subjectGTWRF315toMQTT "home/315toMQTT"
#define subjectRF315toMQTTprotocol "home/315toMQTT/protocol"
#define subjectRF315toMQTTbits "home/315toMQTT/bits"
#define subjectRF315toMQTTlength "home/315toMQTT/length"
#define RF315protocolKey "315_" // protocol will be defined if a subject contains RFprotocolKey followed by a value of 1 digit
#define RF315bitsKey "RF315BITS_" // bits  will be defined if a subject contains RFbitsKey followed by a value of 2 digits
#define repeatRF315wMQTT false // do we repeat a received signal by using mqtt
/*
RF supported protocols
433_1
433_2
433_3
433_4
433_5
433_6
*/
#define RF315pulselengthKey "315PLSL_" // pulselength will be defined if a subject contains RFprotocolKey followed by a value of 3 digits
// subject monitored to listen traffic processed by other gateways to store data and avoid ntuple
#define subjectMultiGTWRF315 "+/315toMQTT"
//RF number of signal repetition
#define RF315_EMITTER_REPEAT 20

/*-------------------PIN DEFINITIONS----------------------*/
#ifdef ESP8266
    #define RF315_RECEIVER_PIN 0 // D3 on nodemcu
    #define RF315_EMITTER_PIN 3 // RX on nodemcu
#elif defined(ESP32)
    #define RF315_RECEIVER_PIN 13 // D13 on DOIT ESP32
    #define RF315_EMITTER_PIN 12 // D12 on DOIT ESP32
#else
    //IMPORTANT NOTE: On arduino UNO connect IR emitter pin to D9 , comment #define IR_USE_TIMER2 and uncomment #define IR_USE_TIMER1 on library <library>IRremote/IRremoteInt.h so as to free pin D3 for RF RECEIVER PIN
    //RF PIN definition
    #define RF315_RECEIVER_PIN 1 //1 = D3 on arduino
    #define RF315_EMITTER_PIN 4 //4 = D4 on arduino
#endif
