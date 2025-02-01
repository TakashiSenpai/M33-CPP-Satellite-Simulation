/*
 * File Controller.cpp
 *
 * Project SatSim
 *
 *
 * Copyright (c) Astrium 2011. All rights reserved.
 *
 */

/*PROTECTED REGION ID(_6P4s8eCXEe-JhMcKl8Urew_impl_cpp_before_includeimplementation) ENABLED START*/
//add user defined includes here
#include <cmath>
/*PROTECTED REGION END*/

#include "Controller.hpp"

using namespace SatSim;

OBJECT_MAKER(Controller)

/*PROTECTED REGION ID(_6P4s8eCXEe-JhMcKl8Urew_impl_cpp_after_includeimplementation) ENABLED START*/
//add user defined includes here
#define YS 0
#define XS 1
/*PROTECTED REGION END*/

void Controller::constructor() {
	/*PROTECTED REGION ID(_6P4s8eCXEe-JhMcKl8Urewdelegated_constructor) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Controller::destructor() {
	/*PROTECTED REGION ID(_6P4s8eCXEe-JhMcKl8Urewdelegated_destructor) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Controller::configure() throw (simtg::Exception) {
	/*PROTECTED REGION ID(_6P4s8eCXEe-JhMcKl8Urewdelegated_configure) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Controller::serializeExt(simtg::SerializationStream& stream_) throw (simtg::SerializationException) {
	/*PROTECTED REGION ID(_6P4s8eCXEe-JhMcKl8UrewserializeExt) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Controller::step() throw (simtg::Exception) {
	/*PROTECTED REGION ID(_6P4s9OCXEe-JhMcKl8Urew) ENABLED START*/
	//add user defined code here
	float error[2] = {
			this->_setPoint[YS] - this->_in_controlSignal[YS],
			this->_setPoint[XS] - this->_in_controlSignal[XS]
	};
	errorHistoryY.push_back(error[YS]);
	errorHistoryX.push_back(error[XS]);

	this->_prop[YS] = this->_coefficientProportional * error[YS];
	this->_inte[YS] += this->_coefficientIntegral * errorHistoryY.back(); // time interval is assumed to be unity
	this->_diff[YS] = this->_coefficientDifferential * (errorHistoryY.back() - errorHistoryY.at(errorHistoryY.size() - 2));

	float controlVariableY;
	controlVariableY = this->_prop[YS] + this->_inte[YS] + this->_diff[YS];

	// clamp the maximum angle
	if (controlVariableY > this->_maxRotationAngle) {
		controlVariableY = this->_maxRotationAngle;
	}

	this->_out_rotationAngles[YS] = controlVariableY;
	/*PROTECTED REGION END*/

}
void Controller::init() throw (simtg::Exception) {

	/*PROTECTED REGION ID(_6P4s8eCXEe-JhMcKl8Urew_startInit) ENABLED START*/
	// add user defined code here
	this->errorHistoryY.push_back(0.0);
	this->errorHistoryX.push_back(0.0);
	/*PROTECTED REGION END*/

	AsyncModelBase::init();

	/*PROTECTED REGION ID(_6P4s8eCXEe-JhMcKl8Urew_init) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}

/*PROTECTED REGION ID(_6P4s8eCXEe-JhMcKl8Urew_impl_cpp_end_extensionsimplementation) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/
