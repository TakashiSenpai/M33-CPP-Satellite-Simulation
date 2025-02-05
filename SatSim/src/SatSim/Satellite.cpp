/*
 * File Satellite.cpp
 *
 * Project SatSim
 *
 *
 * Copyright (c) Astrium 2011. All rights reserved.
 *
 */

/*PROTECTED REGION ID(_xuql8N_rEe-b8OOJcDFPdw_impl_cpp_before_includeimplementation) ENABLED START*/
//add user defined includes here
#include <stdio.h>
/*PROTECTED REGION END*/

#include "Satellite.hpp"
#include "SunSensor.hpp"
#include "AttitudeControlSystem.hpp"

using namespace SatSim;

OBJECT_MAKER(Satellite)

/*PROTECTED REGION ID(_xuql8N_rEe-b8OOJcDFPdw_impl_cpp_after_includeimplementation) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/

void Satellite::constructor() {
	/*PROTECTED REGION ID(_xuql8N_rEe-b8OOJcDFPdwdelegated_constructor) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Satellite::destructor() {
	/*PROTECTED REGION ID(_xuql8N_rEe-b8OOJcDFPdwdelegated_destructor) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Satellite::configure() throw (simtg::Exception) {
	/*PROTECTED REGION ID(_xuql8N_rEe-b8OOJcDFPdwdelegated_configure) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Satellite::serializeExt(simtg::SerializationStream& stream_) throw (simtg::SerializationException) {
	/*PROTECTED REGION ID(_xuql8N_rEe-b8OOJcDFPdwserializeExt) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Satellite::step() throw (simtg::Exception) {
	/*PROTECTED REGION ID(_xuql89_rEe-b8OOJcDFPdw) ENABLED START*/
	//add user defined code here
	FILE *f = fopen("o.csv", "a");
	char msg[512];

	sprintf(msg, "%f, %f, %f,\n", this->_in_sunDirection[0], this->_in_sunDirection[1], this->_in_sunDirection[2]);
	fprintf(f, msg);
	fclose(f);
	/*PROTECTED REGION END*/

}
void Satellite::init() throw (simtg::Exception) {

	/*PROTECTED REGION ID(_xuql8N_rEe-b8OOJcDFPdw_startInit) ENABLED START*/
	// add user defined code here
	FILE *f = fopen("o.csv", "w");
	fclose(f);
	/*PROTECTED REGION END*/

	_SunSensor->init();
	_ACS->init();

	AsyncModelBase::init();

	/*PROTECTED REGION ID(_xuql8N_rEe-b8OOJcDFPdw_init) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}

/*PROTECTED REGION ID(_xuql8N_rEe-b8OOJcDFPdw_impl_cpp_end_extensionsimplementation) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/
