/*
 * File Cell.cpp
 *
 * Project SatSim
 *
 *
 * Copyright (c) Astrium 2011. All rights reserved.
 *
 */

/*PROTECTED REGION ID(_DuiE0d_sEe-b8OOJcDFPdw_impl_cpp_before_includeimplementation) ENABLED START*/
//add user defined includes here
#include <cmath>
/*PROTECTED REGION END*/

#include "Cell.hpp"

using namespace SatSim;

OBJECT_MAKER(Cell)

/*PROTECTED REGION ID(_DuiE0d_sEe-b8OOJcDFPdw_impl_cpp_after_includeimplementation) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/

void Cell::constructor() {
	/*PROTECTED REGION ID(_DuiE0d_sEe-b8OOJcDFPdwdelegated_constructor) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Cell::destructor() {
	/*PROTECTED REGION ID(_DuiE0d_sEe-b8OOJcDFPdwdelegated_destructor) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Cell::configure() throw (simtg::Exception) {
	/*PROTECTED REGION ID(_DuiE0d_sEe-b8OOJcDFPdwdelegated_configure) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Cell::serializeExt(simtg::SerializationStream& stream_) throw (simtg::SerializationException) {
	/*PROTECTED REGION ID(_DuiE0d_sEe-b8OOJcDFPdwserializeExt) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Cell::step() throw (simtg::Exception) {
	/*PROTECTED REGION ID(_DuiE1N_sEe-b8OOJcDFPdw) ENABLED START*/
	//add user defined code here
	float dot = 0;
	for (int i = 0; i < 3; i++) {
		dot += this->_normalVector[i] * this->_in_cssSunDirection[i];
	}

	this->_out_measuredCurrent = dot * this->_maxCurrent;
	this->_out_measuredCurrent *= (1 - pow(2 * acos(dot) / M_PI, this->_largeIncidenceExponent));
	this->_out_measuredCurrent *= this->_in_baffleCoefficient;

	// Edge case: if cell upside down (shun on from behind), clamp current to 0
	if (this->_out_measuredCurrent < 0) {
		this->_out_measuredCurrent = 0;
	}

	/*PROTECTED REGION END*/

}
void Cell::init() throw (simtg::Exception) {

	/*PROTECTED REGION ID(_DuiE0d_sEe-b8OOJcDFPdw_startInit) ENABLED START*/
	// add user defined code here
	/*PROTECTED REGION END*/

	AsyncModelBase::init();

	/*PROTECTED REGION ID(_DuiE0d_sEe-b8OOJcDFPdw_init) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}

/*PROTECTED REGION ID(_DuiE0d_sEe-b8OOJcDFPdw_impl_cpp_end_extensionsimplementation) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/
