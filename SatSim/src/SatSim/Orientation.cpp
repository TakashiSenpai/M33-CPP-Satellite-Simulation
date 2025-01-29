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
#include <sstream>
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
void Orientation::serializeExt(simtg::SerializationStream& stream_) throw (simtg::SerializationException) {
	/*PROTECTED REGION ID(_5y_NIc3hEe-dEfVxFIbKWQserializeExt) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Orientation::step() throw (simtg::Exception) {
	/*PROTECTED REGION ID(_5y_NJM3hEe-dEfVxFIbKWQ) ENABLED START*/
	//add user defined code here
	//float *mat, float *in, float *out
	std::stringstream msg;
	msg << "\nOrientation stepper called";
	this->log(msg.str());
	msg.str("");

	msg << "SAT sun direction: ";
	for (int i = 0; i < 3; i++) {
		msg << this->_in_satSunDirection[i] << ", ";
	}
	this->log(msg.str());
	msg.str("");

	this->sat2cssFrameConvert();

	msg << "CSS sun direction: ";
	for (int i = 0; i < 3; i++) {
		msg << this->_out_cssSunDirection[i] << ", ";
	}
	this->log(msg.str());
	msg.str("");

	float uPrime[3] = { 0, this->_out_cssSunDirection[1],
			this->_out_cssSunDirection[2], };
	msg << "uPrime: ";
	for (int i = 0; i < 3; i++) {
		msg << uPrime[i] << ", ";
	}
	this->log(msg.str());
	msg.str("");

	float uPrimeNorm = sqrt(pow(uPrime[1], 2) + pow(uPrime[2], 2));
	msg << "uPrimeNorm: ";
	msg << uPrimeNorm;
	this->log(msg.str());
	msg.str("");

	// avoid divisions by very small numbers
	if (uPrimeNorm < 1e-6) {
		return;
	}

	this->_sunAzimuth =
			(this->_out_cssSunDirection[1] <= 0) ?
													acos(this->_out_cssSunDirection[2] / uPrimeNorm) :
													M_PI + acos(-this->_out_cssSunDirection[2] / uPrimeNorm);
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
			this->_out_cssSunDirection[i] += this->_sat2cssFrame[i][j] * this->_in_satSunDirection[j];
		}
	}
	/*PROTECTED REGION END*/

}
void Orientation::rotation(float* angles_) {
	/*PROTECTED REGION ID(_4YkpwNdGEe-pvalCSSrrfQ) ENABLED START*/
	//add user defined code here
	float a1 = angles_[0];
	float a2 = angles_[1];

	float m1[3][3] = { { cos(a1), 0, sin(a1) }, { 0, 1, 0 }, { -sin(a1), 0, cos(
			a1) } };

	float m2[3][3] = { { cos(a2), -sin(a2), 0 }, { sin(a2), cos(a2), 0 }, { 0,
			0, 1 }, };

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			this->_rotation[i][j] = 0;
			for (int k = 0; k < 3; k++) {
				this->_rotation[i][j] += m1[i][k] * m2[k][j];
			}
		}
	}
	/*PROTECTED REGION END*/

}
void Orientation::initLog() {
	/*PROTECTED REGION ID(_MXojYN5REe-81o-hP_uF1w) ENABLED START*/
	//add user defined code here
	FILE *logFile = fopen("orientation.log", "w");
	fprintf(logFile, "%s\n", "Initializing log file...");
	fclose(logFile);
	/*PROTECTED REGION END*/

}
void Orientation::log(std::string msg_) {
	/*PROTECTED REGION ID(_SaWTwN5REe-81o-hP_uF1w) ENABLED START*/
	//add user defined code here
	FILE *logFile = fopen("orientation.log", "a");
	fprintf(logFile, "%s\n", msg_.c_str());
	fclose(logFile);
	/*PROTECTED REGION END*/

}
void Orientation::init() throw (simtg::Exception) {

	/*PROTECTED REGION ID(_5y_NIc3hEe-dEfVxFIbKWQ_startInit) ENABLED START*/
	// add user defined code here
	this->initLog();
	/*PROTECTED REGION END*/

	AsyncModelBase::init();

	/*PROTECTED REGION ID(_5y_NIc3hEe-dEfVxFIbKWQ_init) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}

/*PROTECTED REGION ID(_5y_NIc3hEe-dEfVxFIbKWQ_impl_cpp_end_extensionsimplementation) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/
