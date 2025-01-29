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
	this->Cells[0] = this->_Cell_0;
	this->Cells[1] = this->_Cell_1;
	this->Cells[2] = this->_Cell_2;
	this->Cells[3] = this->_Cell_3;

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
void SunSensor::serializeExt(simtg::SerializationStream& stream_) throw (simtg::SerializationException) {
	/*PROTECTED REGION ID(_Qlo1Yb1WEe-zAc57ptwKlgserializeExt) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void SunSensor::step() throw (simtg::Exception) {
	/*PROTECTED REGION ID(_Qlo1ZL1WEe-zAc57ptwKlg) ENABLED START*/
	//add user defined code here
	std::stringstream nbr;
	std::string msg;

	// debug
	msg = "\nSunSensor stepper called";
	this->log(msg);
	msg = "Input sun direction: ";
	for (int i = 0; i < 3; i++) {
		nbr << this->_in_sunDirection[i] << ", ";
	}
	msg += nbr.str();
	nbr.str("");
	msg += "Az/El:";
	nbr << this->_in_sunAz << ", " << this->_in_sunEl;
	msg += nbr.str();
	this->log(msg);
	nbr.str("");

	// update baffle coefficients
	this->_Baffle->_in_sunAzimuth = this->_in_sunAz;
	this->_Baffle->_in_sunElevation = this->_in_sunEl;
	this->_Baffle->computeBaffleCoefficients();

	this->_stepNbr++;
	nbr << this->_stepNbr;
	msg = "step number" + nbr.str();
	this->log(msg);
	nbr.str("");

	// debug
	msg = "baffle coefficients: ";
	for (int i = 0; i < 4; i++) {
		nbr << this->_Baffle->_out_baffleCoefficient[i] << ", ";
	}
	msg += nbr.str();
	this->log(msg);
	nbr.str("");

	// Calculate the current for each cell
	for (int cell_id = 0; cell_id < 4; cell_id++) {
		// Update the cells' parameters
		this->Cells[cell_id]->_baffleCoefficient = this->_Baffle->_out_baffleCoefficient[cell_id];
		for (int i = 0; i < 3; i++) {
			this->Cells[cell_id]->_input_sunDirection[i] = this->_in_sunDirection[i];
		}

		// calculate the current
		this->Cells[cell_id]->measureCurrent();

		// extract the current value
		this->_out_measuredCurrents[cell_id] = this->Cells[cell_id]->_measuredCurrent;
	}

	// debug
	nbr << "Measured currents: ";
	for (int i = 0; i < 4; i++) {
		nbr << this->_out_measuredCurrents[i] << ", ";
	}
	msg = nbr.str();
	this->log(msg);
	nbr.str("");

	/*PROTECTED REGION END*/

}
void SunSensor::log(std::string& msg_) {
	/*PROTECTED REGION ID(_gkmjcNc0Ee-pvalCSSrrfQ) ENABLED START*/
	//add user defined code here
	FILE *logFile = fopen("sunsensor.log", "a");
	fprintf(logFile, "%s\n", msg_.c_str());
	fclose(logFile);
	/*PROTECTED REGION END*/

}
void SunSensor::initLog() {
	/*PROTECTED REGION ID(_dVZvQN5VEe-81o-hP_uF1w) ENABLED START*/
	//add user defined code here
	FILE *logFile = fopen("sunsensor.log", "w");
	fprintf(logFile, "%s\n", "Initializing log file...");
	fclose(logFile);
	/*PROTECTED REGION END*/

}
void SunSensor::init() throw (simtg::Exception) {

	/*PROTECTED REGION ID(_Qlo1Yb1WEe-zAc57ptwKlg_startInit) ENABLED START*/
	// add user defined code here
	this->initLog();
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
