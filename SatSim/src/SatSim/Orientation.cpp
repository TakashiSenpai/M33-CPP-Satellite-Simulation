/*
 * File Orientation.cpp
 *
 * Project SatSim
 *
 *
 * Copyright (c) Astrium 2011. All rights reserved.
 *
 */

/*PROTECTED REGION ID(_5UEREN_rEe-b8OOJcDFPdw_impl_cpp_before_includeimplementation) ENABLED START*/
//add user defined includes here
#include <cmath>
/*PROTECTED REGION END*/

#include "Orientation.hpp"

using namespace SatSim;

OBJECT_MAKER(Orientation)

/*PROTECTED REGION ID(_5UEREN_rEe-b8OOJcDFPdw_impl_cpp_after_includeimplementation) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/

void Orientation::constructor() {
	/*PROTECTED REGION ID(_5UEREN_rEe-b8OOJcDFPdwdelegated_constructor) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Orientation::destructor() {
	/*PROTECTED REGION ID(_5UEREN_rEe-b8OOJcDFPdwdelegated_destructor) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Orientation::configure() throw (simtg::Exception) {
	/*PROTECTED REGION ID(_5UEREN_rEe-b8OOJcDFPdwdelegated_configure) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Orientation::serializeExt(simtg::SerializationStream& stream_) throw (simtg::SerializationException) {
	/*PROTECTED REGION ID(_5UEREN_rEe-b8OOJcDFPdwserializeExt) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Orientation::step() throw (simtg::Exception) {
	/*PROTECTED REGION ID(_5UERE9_rEe-b8OOJcDFPdw) ENABLED START*/
	//add user defined code here
	/*
	 * Convert the sun direction in the satellite frame to the sun sensor coordinate frame
	 */

	// Use simple matrix multiplication
	for (int i = 0; i < 3; i++) {
		this->_out_cssFrameVector[i] = 0.0;
		for (int j = 0; j < 3; j++) {
			this->_out_cssFrameVector[i] += this->_sat2cssFrame[i][j] * this->_in_satFrameVector[j];
		}
	}

	/*
	 * Calculate azimuth and elevation in the sun sensor coordinate frame
	 */

	// Projection of the sun direction in the (Y_c, Z_c) plane
	float uPrime[3] = {
			0,
			this->_out_cssFrameVector[1],
			this->_out_cssFrameVector[2]
	};
	float uPrimeNorm = sqrt(pow(uPrime[1], 2) + pow(uPrime[2], 2));

	// calculate azimuth and elevation
	this->_out_sunEl = acos(this->_out_cssFrameVector[0]);
	this->_out_sunAz =
			(this->_out_cssFrameVector[1] <= 0) ?
													acos(this->_out_cssFrameVector[2] / uPrimeNorm) :
													M_PI + acos(-this->_out_cssFrameVector[2] / uPrimeNorm);

	/*
	 * Convert Sun sensor Sun direction to satellite coordinate frame
	 */

	// Use simple matrix multiplication
	for (int i = 0; i < 3; i++) {
		this->_out_satFrameVector[i] = 0.0;
		for (int j = 0; j < 3; j++) {
			this->_out_satFrameVector[i] += this->_css2satFrame[i][j] * this->_in_cssFrameVector[j];
		}
	}

	/*PROTECTED REGION END*/

}
void Orientation::init() throw (simtg::Exception) {

	/*PROTECTED REGION ID(_5UEREN_rEe-b8OOJcDFPdw_startInit) ENABLED START*/
	// add user defined code here
	/*PROTECTED REGION END*/

	AsyncModelBase::init();

	/*PROTECTED REGION ID(_5UEREN_rEe-b8OOJcDFPdw_init) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}

/*PROTECTED REGION ID(_5UEREN_rEe-b8OOJcDFPdw_impl_cpp_end_extensionsimplementation) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/
