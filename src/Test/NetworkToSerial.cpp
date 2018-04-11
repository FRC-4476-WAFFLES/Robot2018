/*
 * NetworkToSerial.cpp
 *
 *  Created on: Apr 8, 2018
 *      Author: DuncanS
 */
#include <iostream>
#include <unistd.h>
#include "networktables/NetworkTable.h"
#include <stdio.h>
#include <SerialPort.h>
#include <Serial.h>
#include <string>
#include <assert.h>

int main(){
	NetworkTable::SetClientMode();
	NetworkTable::SetTeam(4476);
	  std::shared_ptr<NetworkTable> table = NetworkTable::GetTable("SmartDashboard");
	  bool hascube = table->GetBoolean("/Arm/Infrared/Has Cube?", 0);
	  CSerial serial;
	  bool hascube = 0;
	  while(1==1){
		  hascube = table->GetBoolean("/Arm/Infrared/Has Cube?", 0);
		  if (serial.Open(2, 9600))
		  {
		   const char szMessage[] = hascube;
		   int nBytesSent = serial.SendData(szMessage, strlen(szMessage));
		   assert(nBytesSent == strlen(szMessage));
		  }
		  else
			  table->PutString("computer port", "Failed to open port!");
	  }

}



