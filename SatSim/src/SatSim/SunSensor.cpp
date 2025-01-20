/*
 * File SunSensor.cpp
 *
 * Project SatSim
 *
 *
 * Copyright (c) Astrium 2011. All rights reserved.
 *
 */

/*PROTECTED REGION ID(_Qlo1Yb1WEe-zAc57ptwKlg_impl_cpp_before_includeimplementation) ENABLED START*/
//add user defined includes here
#include <cmath>
#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
//#include "log.h"
//#define LOGFILE "satsim.log"
/*PROTECTED REGION END*/

#include "SunSensor.hpp"
#include "Cell.hpp"
#include "Baffle.hpp"

using namespace SatSim;

OBJECT_MAKER(SunSensor)

/*PROTECTED REGION ID(_Qlo1Yb1WEe-zAc57ptwKlg_impl_cpp_after_includeimplementation) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/

void SunSensor::constructor() {
	/*PROTECTED REGION ID(_Qlo1Yb1WEe-zAc57ptwKlgdelegated_constructor) ENABLED START*/
	//add user defined code here
	float tmp[] = { sin(static_cast<float>(this->_angle * M_PI / 180)), cos(
			static_cast<float>(this->_angle * M_PI / 180)), cos(
			static_cast<float>(this->_angle * M_PI / 180)) };

	for (int i = 0; i < 3; i++) {
		this->_Cell_0->_normalVector[i] = this->_orientation_0[i] * tmp[i];
		this->_Cell_1->_normalVector[i] = this->_orientation_1[i] * tmp[i];
		this->_Cell_2->_normalVector[i] = this->_orientation_2[i] * tmp[i];
		this->_Cell_3->_normalVector[i] = this->_orientation_3[i] * tmp[i];
	}
	char msg[512];
	sprintf(msg, "Cell_0: %f, %f, %f", this->_Cell_0->_normalVector[0],
			this->_Cell_0->_normalVector[1], this->_Cell_0->_normalVector[2]);
	//this->log(msg);
	sprintf(msg, "Cell_1: %f, %f, %f", this->_Cell_1->_normalVector[0],
			this->_Cell_1->_normalVector[1], this->_Cell_1->_normalVector[2]);
	//this->log(msg);
	sprintf(msg, "Cell_2: %f, %f, %f", this->_Cell_2->_normalVector[0],
			this->_Cell_2->_normalVector[1], this->_Cell_2->_normalVector[2]);
	//this->log(msg);
	sprintf(msg, "Cell_3: %f, %f, %f", this->_Cell_3->_normalVector[0],
			this->_Cell_3->_normalVector[1], this->_Cell_3->_normalVector[2]);
	//this->log(msg);
	/*PROTECTED REGION END*/

}
void SunSensor::destructor() {
	/*PROTECTED REGION ID(_Qlo1Yb1WEe-zAc57ptwKlgdelegated_destructor) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void SunSensor::configure() throw (simtg::Exception) {
	/*PROTECTED REGION ID(_Qlo1Yb1WEe-zAc57ptwKlgdelegated_configure) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void SunSensor::serializeExt(simtg::SerializationStream& stream_)
		throw (simtg::SerializationException) {
	/*PROTECTED REGION ID(_Qlo1Yb1WEe-zAc57ptwKlgserializeExt) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void SunSensor::step() throw (simtg::Exception) {
	/*PROTECTED REGION ID(_Qlo1ZL1WEe-zAc57ptwKlg) ENABLED START*/
	//add user defined code here
	std::string msg = "SunSensor stepper called";
	this->log(msg);

	this->_Baffle->computeBaffleCoefficients();

	this->_stepNbr++;
	std::stringstream nbr;
	nbr << this->_stepNbr;
	msg = "step number" + nbr.str();
	this->log(msg);

	msg = "baffle coefficients: ";
	for (int i = 0; i < 4; i++) {
		nbr.str("");
		// clear the stringstream
		nbr << this->_Baffle->_out_baffleCoefficient[i];
		msg += nbr.str() + ", ";
	}
	this->log(msg);

	this->_Cell_0->_baffleCoefficient =
			this->_Baffle->_out_baffleCoefficient[0];
	this->_Cell_1->_baffleCoefficient =
			this->_Baffle->_out_baffleCoefficient[1];
	this->_Cell_2->_baffleCoefficient =
			this->_Baffle->_out_baffleCoefficient[2];
	this->_Cell_3->_baffleCoefficient =
			this->_Baffle->_out_baffleCoefficient[3];

	this->_Cell_0->measureCurrent();
	this->_Cell_1->measureCurrent();
	this->_Cell_2->measureCurrent();
	this->_Cell_3->measureCurrent();

	this->_out_measuredCurrents[0] = this->_Cell_0->_measuredCurrent;
	this->_out_measuredCurrents[1] = this->_Cell_1->_measuredCurrent;
	this->_out_measuredCurrents[2] = this->_Cell_2->_measuredCurrent;
	this->_out_measuredCurrents[3] = this->_Cell_3->_measuredCurrent;

	/*PROTECTED REGION END*/

}
void SunSensor::log(std::string& msg_) {
	/*PROTECTED REGION ID(_gkmjcNc0Ee-pvalCSSrrfQ) ENABLED START*/
	//add user defined code here
	FILE *logFile = fopen("sat.log", "a");
	fprintf(logFile, "%s\n", msg_.c_str());
	fclose(logFile);
	/*PROTECTED REGION END*/

}
void SunSensor::init() throw (simtg::Exception) {

	/*PROTECTED REGION ID(_Qlo1Yb1WEe-zAc57ptwKlg_startInit) ENABLED START*/
	// add user defined code here
	/*PROTECTED REGION END*/

	_Cell_0->init();
	_Cell_1->init();
	_Cell_2->init();
	_Cell_3->init();
	_Baffle->init();

	AsyncModelBase::init();

	/*PROTECTED REGION ID(_Qlo1Yb1WEe-zAc57ptwKlg_init) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}

/*PROTECTED REGION ID(_Qlo1Yb1WEe-zAc57ptwKlg_impl_cpp_end_extensionsimplementation) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/
