/*
 * File AnalogToDigitalConverter.cpp
 *
 * Project SatSim
 *
 *
 * Copyright (c) Astrium 2011. All rights reserved.
 *
 */

/*PROTECTED REGION ID(_Nfy0MeCUEe-JhMcKl8Urew_impl_cpp_before_includeimplementation) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/

#include "AnalogToDigitalConverter.hpp"

using namespace SatSim;

OBJECT_MAKER(AnalogToDigitalConverter)

/*PROTECTED REGION ID(_Nfy0MeCUEe-JhMcKl8Urew_impl_cpp_after_includeimplementation) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/

void AnalogToDigitalConverter::constructor() {
	/*PROTECTED REGION ID(_Nfy0MeCUEe-JhMcKl8Urewdelegated_constructor) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void AnalogToDigitalConverter::destructor() {
	/*PROTECTED REGION ID(_Nfy0MeCUEe-JhMcKl8Urewdelegated_destructor) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void AnalogToDigitalConverter::configure() throw (simtg::Exception) {
	/*PROTECTED REGION ID(_Nfy0MeCUEe-JhMcKl8Urewdelegated_configure) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void AnalogToDigitalConverter::serializeExt(simtg::SerializationStream& stream_) throw (simtg::SerializationException) {
	/*PROTECTED REGION ID(_Nfy0MeCUEe-JhMcKl8UrewserializeExt) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void AnalogToDigitalConverter::step() throw (simtg::Exception) {
	/*PROTECTED REGION ID(_Nfy0NOCUEe-JhMcKl8Urew) ENABLED START*/
	//add user defined code here
	// output signal should remain between 0 and 1
	this->_out_controlSignal[0] = (this->_in_measuredCurrentPlusY - this->_in_measuredCurrentMinusY) / this->_maxCurrent;
	this->_out_controlSignal[1] = (this->_in_measuredCurrentPlusZ - this->_in_measuredCurrentMinusZ) / this->_maxCurrent;

	/*PROTECTED REGION END*/

}
void AnalogToDigitalConverter::init() throw (simtg::Exception) {

	/*PROTECTED REGION ID(_Nfy0MeCUEe-JhMcKl8Urew_startInit) ENABLED START*/
	// add user defined code here
	/*PROTECTED REGION END*/

	AsyncModelBase::init();

	/*PROTECTED REGION ID(_Nfy0MeCUEe-JhMcKl8Urew_init) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}

/*PROTECTED REGION ID(_Nfy0MeCUEe-JhMcKl8Urew_impl_cpp_end_extensionsimplementation) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/
