/*
 * File SunSensor.cpp
 *
 * Project SatSim
 *
 *
 * Copyright (c) Astrium 2011. All rights reserved.
 *
 */

/*PROTECTED REGION ID(_-xPEYN_rEe-b8OOJcDFPdw_impl_cpp_before_includeimplementation) ENABLED START*/
//add user defined includes here
#include <cmath>
/*PROTECTED REGION END*/

#include "SunSensor.hpp"
#include "Baffle.hpp"
#include "Cell.hpp"

using namespace SatSim;

OBJECT_MAKER(SunSensor)

/*PROTECTED REGION ID(_-xPEYN_rEe-b8OOJcDFPdw_impl_cpp_after_includeimplementation) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/

void SunSensor::constructor() {
	/*PROTECTED REGION ID(_-xPEYN_rEe-b8OOJcDFPdwdelegated_constructor) ENABLED START*/
	//add user defined code here
	/*
	 * Construct the geometry of the cells
	 */

	// helper vector
	float tmp[] = {
			sin(static_cast<float>(this->_angle * M_PI / 180)),
			cos(static_cast<float>(this->_angle * M_PI / 180)),
			cos(static_cast<float>(this->_angle * M_PI / 180))
	};

	// set the normal vectors of the cells
	for (int i = 0; i < 3; i++) {
		this->_Cell_PlusY->_normalVector[i] = this->_orientationPlusY[i] * tmp[i];
		this->_Cell_PlusZ->_normalVector[i] = this->_orientationPlusZ[i] * tmp[i];
		this->_Cell_MinusY->_normalVector[i] = this->_orientationMinusY[i] * tmp[i];
		this->_Cell_MinusZ->_normalVector[i] = this->_orientationMinusZ[i] * tmp[i];
	}

	/*PROTECTED REGION END*/

}
void SunSensor::destructor() {
	/*PROTECTED REGION ID(_-xPEYN_rEe-b8OOJcDFPdwdelegated_destructor) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void SunSensor::configure() throw (simtg::Exception) {
	/*PROTECTED REGION ID(_-xPEYN_rEe-b8OOJcDFPdwdelegated_configure) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void SunSensor::serializeExt(simtg::SerializationStream& stream_) throw (simtg::SerializationException) {
	/*PROTECTED REGION ID(_-xPEYN_rEe-b8OOJcDFPdwserializeExt) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void SunSensor::step() throw (simtg::Exception) {
	/*PROTECTED REGION ID(_-xPEY9_rEe-b8OOJcDFPdw) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void SunSensor::init() throw (simtg::Exception) {

	/*PROTECTED REGION ID(_-xPEYN_rEe-b8OOJcDFPdw_startInit) ENABLED START*/
	// add user defined code here
	/*PROTECTED REGION END*/

	_Baffle->init();
	_Cell_PlusY->init();
	_Cell_MinusY->init();
	_Cell_PlusZ->init();
	_Cell_MinusZ->init();

	AsyncModelBase::init();

	/*PROTECTED REGION ID(_-xPEYN_rEe-b8OOJcDFPdw_init) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}

/*PROTECTED REGION ID(_-xPEYN_rEe-b8OOJcDFPdw_impl_cpp_end_extensionsimplementation) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/
