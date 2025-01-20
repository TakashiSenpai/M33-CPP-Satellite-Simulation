/*
 * File Satellite.cpp
 *
 * Project SatSim
 *
 *
 * Copyright (c) Astrium 2011. All rights reserved.
 *
 */

/*PROTECTED REGION ID(_Jcirwb1WEe-zAc57ptwKlg_impl_cpp_before_includeimplementation) ENABLED START*/
//add user defined includes here
#include <stdio.h>
#include <sstream>
/*PROTECTED REGION END*/

#include "Satellite.hpp"
#include "SunSensor.hpp"
#include "Orientation.hpp"
#include "Actuator.hpp"

using namespace SatSim;

OBJECT_MAKER(Satellite)

/*PROTECTED REGION ID(_Jcirwb1WEe-zAc57ptwKlg_impl_cpp_after_includeimplementation) ENABLED START*/
//add user defined includes here
void initLog() {
	FILE *logFile = fopen("sat.log", "w");
	fprintf(logFile, "%s\n", "Initializing log file...");
	fclose(logFile);
}
/*
 void writeLog(const std::string &msg) {
 FILE *logFile = fopen("sat.log", "a");
 fprintf(logFile, "%s\n", msg.c_str());
 fclose(logFile);
 }*/
/*PROTECTED REGION END*/

void Satellite::constructor() {
	/*PROTECTED REGION ID(_Jcirwb1WEe-zAc57ptwKlgdelegated_constructor) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Satellite::destructor() {
	/*PROTECTED REGION ID(_Jcirwb1WEe-zAc57ptwKlgdelegated_destructor) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Satellite::configure() throw (simtg::Exception) {
	/*PROTECTED REGION ID(_Jcirwb1WEe-zAc57ptwKlgdelegated_configure) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Satellite::serializeExt(simtg::SerializationStream& stream_) throw (simtg::SerializationException) {
	/*PROTECTED REGION ID(_Jcirwb1WEe-zAc57ptwKlgserializeExt) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Satellite::step() throw (simtg::Exception) {
	/*PROTECTED REGION ID(_JcirxL1WEe-zAc57ptwKlg) ENABLED START*/
	//add user defined code here
	std::string msg = "\nSatellite stepper called";
	this->log(msg);

	std::stringstream tmp;
	tmp << this->_Actuator->_calculatedPosition[0]
			<< this->_Actuator->_calculatedPosition[1];
	msg = "Calculated position:" + tmp.str();
	this->log(msg);

	for (int i = 0; i < 3; i++) {
		this->_Orientation->_in_satSunDirection[i] = this->_sunDirection[i];
	}

	this->_Orientation->step();
	this->_SunSensor->step();
	this->_Actuator->step();

	tmp.str("");
	tmp << this->_Actuator->_out_actuationAngle[0]
			<< this->_Actuator->_out_actuationAngle[1];
	msg = "Actuation angle:" + tmp.str();
	this->log(msg);

	this->_Orientation->rotation(this->_Actuator->_out_actuationAngle);

	float out[3];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			out[i] += this->_Orientation->_rotation[i][j]
					* this->_sunDirection[j];
		}
	}
	for (int i = 0; i < 3; i++) {
		this->_sunDirection[i] = out[i];
	}
	/*PROTECTED REGION END*/

}
void Satellite::log(std::string& msg_) {
	/*PROTECTED REGION ID(__T9CINczEe-pvalCSSrrfQ) ENABLED START*/
	//add user defined code here
	FILE *logFile = fopen("sat.log", "a");
	fprintf(logFile, "%s\n", msg_.c_str());
	fclose(logFile);
	/*PROTECTED REGION END*/

}
void Satellite::init() throw (simtg::Exception) {

	/*PROTECTED REGION ID(_Jcirwb1WEe-zAc57ptwKlg_startInit) ENABLED START*/
	// add user defined code here
	/*PROTECTED REGION END*/

	_SunSensor->init();
	_Orientation->init();
	_Actuator->init();

	AsyncModelBase::init();

	/*PROTECTED REGION ID(_Jcirwb1WEe-zAc57ptwKlg_init) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}

/*PROTECTED REGION ID(_Jcirwb1WEe-zAc57ptwKlg_impl_cpp_end_extensionsimplementation) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/
