/*
 * File Orientation.cpp
 *
 * Project SatSim
 *
 *
 * Copyright (c) Astrium 2011. All rights reserved.
 *
 */

/*PROTECTED REGION ID(_5y_NIc3hEe-dEfVxFIbKWQ_impl_cpp_before_includeimplementation) ENABLED START*/
//add user defined includes here
#include <cmath>
/*PROTECTED REGION END*/

#include "Orientation.hpp"

using namespace SatSim;

OBJECT_MAKER(Orientation)

/*PROTECTED REGION ID(_5y_NIc3hEe-dEfVxFIbKWQ_impl_cpp_after_includeimplementation) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/

void Orientation::constructor() {
	/*PROTECTED REGION ID(_5y_NIc3hEe-dEfVxFIbKWQdelegated_constructor) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Orientation::destructor() {
	/*PROTECTED REGION ID(_5y_NIc3hEe-dEfVxFIbKWQdelegated_destructor) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Orientation::configure() throw (simtg::Exception) {
	/*PROTECTED REGION ID(_5y_NIc3hEe-dEfVxFIbKWQdelegated_configure) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Orientation::serializeExt(simtg::SerializationStream& stream_)
		throw (simtg::SerializationException) {
	/*PROTECTED REGION ID(_5y_NIc3hEe-dEfVxFIbKWQserializeExt) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Orientation::step() throw (simtg::Exception) {
	/*PROTECTED REGION ID(_5y_NJM3hEe-dEfVxFIbKWQ) ENABLED START*/
	//add user defined code here
	//float *mat, float *in, float *out
	this->sat2cssFrameConvert();

	this->_sunAzimuth =
			(this->_out_cssSunDirection[1] <= 0) ?
					acos(this->_out_cssSunDirection[2]) :
					M_PI + acos(-this->_out_cssSunDirection[2]);
	this->_sunLongitude = acos(this->_out_cssSunDirection[0]);
	/*PROTECTED REGION END*/

}
void Orientation::css2satFrameConvert() {
	/*PROTECTED REGION ID(_sLJB8M3iEe-dEfVxFIbKWQ) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Orientation::sat2cssFrameConvert() {
	/*PROTECTED REGION ID(_vP3-QM3iEe-dEfVxFIbKWQ) ENABLED START*/
	//add user defined code here
	for (int i = 0; i < 3; i++) {
		this->_out_cssSunDirection[i] = 0.0;
		for (int j = 0; j < 3; j++) {
			this->_out_cssSunDirection[i] += this->_css2satFrame[i][j]
					* this->_in_satSunDirection[j];
		}
	}
	/*PROTECTED REGION END*/

}
void Orientation::init() throw (simtg::Exception) {

	/*PROTECTED REGION ID(_5y_NIc3hEe-dEfVxFIbKWQ_startInit) ENABLED START*/
	// add user defined code here
	/*PROTECTED REGION END*/

	AsyncModelBase::init();

	/*PROTECTED REGION ID(_5y_NIc3hEe-dEfVxFIbKWQ_init) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}

/*PROTECTED REGION ID(_5y_NIc3hEe-dEfVxFIbKWQ_impl_cpp_end_extensionsimplementation) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/
