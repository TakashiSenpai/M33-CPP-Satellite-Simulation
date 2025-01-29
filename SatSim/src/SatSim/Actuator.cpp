/*
 * File Actuator.cpp
 *
 * Project SatSim
 *
 *
 * Copyright (c) Astrium 2011. All rights reserved.
 *
 */

/*PROTECTED REGION ID(_LVfTodcvEe-g-_tbVlfW3w_impl_cpp_before_includeimplementation) ENABLED START*/
//add user defined includes here
#include <cmath>
#include <sstream>
/*PROTECTED REGION END*/

#include "Actuator.hpp"

using namespace SatSim;

OBJECT_MAKER(Actuator)

/*PROTECTED REGION ID(_LVfTodcvEe-g-_tbVlfW3w_impl_cpp_after_includeimplementation) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/

void Actuator::constructor() {
	/*PROTECTED REGION ID(_LVfTodcvEe-g-_tbVlfW3wdelegated_constructor) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Actuator::destructor() {
	/*PROTECTED REGION ID(_LVfTodcvEe-g-_tbVlfW3wdelegated_destructor) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Actuator::configure() throw (simtg::Exception) {
	/*PROTECTED REGION ID(_LVfTodcvEe-g-_tbVlfW3wdelegated_configure) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Actuator::serializeExt(simtg::SerializationStream& stream_) throw (simtg::SerializationException) {
	/*PROTECTED REGION ID(_LVfTodcvEe-g-_tbVlfW3wserializeExt) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Actuator::step() throw (simtg::Exception) {
	/*PROTECTED REGION ID(_LVfTpNcvEe-g-_tbVlfW3w) ENABLED START*/
	//add user defined code here
	std::stringstream msg;

	msg << "\nCalling Actuator stepper";
	this->log(msg.str());
	msg.str("");

	this->_numSteps++;

	float yPosition = this->_in_measuredCurrents[1] - this->_in_measuredCurrents[0];
	float zPosition = this->_in_measuredCurrents[3] - this->_in_measuredCurrents[2];

	msg << "Measured positions: ";
	msg << yPosition << ", ";
	msg << zPosition;
	this->log(msg.str());
	msg.str("");

	int actuationDirection = 0;
	if (abs(yPosition) < abs(zPosition)) {
		actuationDirection = 1;
	}
	float scalingFactor = 1 / sqrt(pow(yPosition, 2) + pow(zPosition, 2));
	this->_calculatedPosition[0] = scalingFactor * yPosition;
	this->_calculatedPosition[1] = scalingFactor * zPosition;

	this->_sumPositions[0] += this->_calculatedPosition[0];
	this->_sumPositions[1] += this->_calculatedPosition[1];

	float prop = this->_coefficientProportional * this->_calculatedPosition[actuationDirection];
	float inte = 1 / this->_numSteps * this->_coefficientIntegration * this->_sumPositions[actuationDirection];
	float diff = this->_coefficientDifferential * (this->_calculatedPosition[actuationDirection] - this->_lastPosition[actuationDirection]);

	this->_out_actuationAngle[actuationDirection] = M_PI / 18 * (prop); // + inte + diff);
	this->_out_actuationAngle[1 - actuationDirection] = 0;

	this->_lastPosition[0] += this->_calculatedPosition[0];
	this->_lastPosition[1] += this->_calculatedPosition[1];

	/*PROTECTED REGION END*/

}
void Actuator::log(std::string msg_) {
	/*PROTECTED REGION ID(_DzYM4N5dEe-81o-hP_uF1w) ENABLED START*/
	//add user defined code here
	FILE *logFile = fopen("actuator.log", "a");
	fprintf(logFile, "%s\n", msg_.c_str());
	fclose(logFile);
	/*PROTECTED REGION END*/

}
void Actuator::initLog() {
	/*PROTECTED REGION ID(_FiZ6gN5dEe-81o-hP_uF1w) ENABLED START*/
	//add user defined code here
	FILE *logFile = fopen("actuator.log", "w");
	fprintf(logFile, "%s\n", "Initializing log file...");
	fclose(logFile);
	/*PROTECTED REGION END*/

}
void Actuator::init() throw (simtg::Exception) {

	/*PROTECTED REGION ID(_LVfTodcvEe-g-_tbVlfW3w_startInit) ENABLED START*/
	// add user defined code here
	this->initLog();
	this->_coefficientProportional = 1;
	this->_coefficientDifferential = 0;
	this->_coefficientIntegration = 0;
	/*PROTECTED REGION END*/

	AsyncModelBase::init();

	/*PROTECTED REGION ID(_LVfTodcvEe-g-_tbVlfW3w_init) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}

/*PROTECTED REGION ID(_LVfTodcvEe-g-_tbVlfW3w_impl_cpp_end_extensionsimplementation) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/
