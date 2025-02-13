/*
 * File Actuator.cpp
 *
 * Project SatSim
 *
 *
 * Copyright (c) Astrium 2011. All rights reserved.
 *
 */

/*PROTECTED REGION ID(_rn_dMeCcEe-JhMcKl8Urew_impl_cpp_before_includeimplementation) ENABLED START*/
//add user defined includes here
#include <cmath>
#include "quaternion.hpp"
/*PROTECTED REGION END*/

#include "Actuator.hpp"

using namespace SatSim;

OBJECT_MAKER(Actuator)

/*PROTECTED REGION ID(_rn_dMeCcEe-JhMcKl8Urew_impl_cpp_after_includeimplementation) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/

void Actuator::constructor() {
	/*PROTECTED REGION ID(_rn_dMeCcEe-JhMcKl8Urewdelegated_constructor) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Actuator::destructor() {
	/*PROTECTED REGION ID(_rn_dMeCcEe-JhMcKl8Urewdelegated_destructor) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Actuator::configure() throw (simtg::Exception) {
	/*PROTECTED REGION ID(_rn_dMeCcEe-JhMcKl8Urewdelegated_configure) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Actuator::serializeExt(simtg::SerializationStream& stream_) throw (simtg::SerializationException) {
	/*PROTECTED REGION ID(_rn_dMeCcEe-JhMcKl8UrewserializeExt) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Actuator::step() throw (simtg::Exception) {
	/*PROTECTED REGION ID(_rn_dNOCcEe-JhMcKl8Urew) ENABLED START*/

	//add user defined code here
	/*
	 * Quaternion rotation
	 */

	if ((this->_in_rotationAngles[0] == 0.0) && (this->_in_rotationAngles[1] == 0.0)) {
		for (int i = 0; i < 3; i++) {
			this->_out_sunDirection[i] = this->_in_sunDirection[i];
		}
		return;
	}

	// compute rotation axis
	float position[2] = {
			this->_in_rotationAngles[1],
			this->_in_rotationAngles[0],
	};

	float norm = sqrt(pow(position[0], 2) + pow(position[1], 2));
	this->_axis[0] = position[1] / norm;
	this->_axis[1] = -position[0] / norm;
	this->_axis[2] = 0;

	float axis[3] = {
			this->_axis[0],
			this->_axis[1],
			this->_axis[2]
	};

	this->_angle = sqrt(pow(this->_in_rotationAngles[0], 2) + pow(this->_in_rotationAngles[1], 2));
	if (this->_angle > this->_maxRotationAngle * M_PI / 180) {
		this->_angle = this->_maxRotationAngle * M_PI / 180;
	}

	Quaternion *qRot = Quaternion::getRotation(axis, (+1) * this->_angle);
	Quaternion *qRotStar = qRot->conjugate();
	Quaternion *qPosOld = new Quaternion(0, this->_in_sunDirection[0], this->_in_sunDirection[1], this->_in_sunDirection[2]);

	Quaternion *qTmp = Quaternion::multiply(*qPosOld, *qRotStar);
	Quaternion *qPosNew = Quaternion::multiply(*qRot, *qTmp);

	// debug
	for (int i = 0; i < 4; i++) {
		this->_qRotArr[i] = qRot->toArray()[i];
		this->_qRotStarArr[i] = qRotStar->toArray()[i];
		this->_qPosOldArr[i] = qPosOld->toArray()[i];
		this->_qPosNewArr[i] = qPosNew->toArray()[i];
	}

	for (int i = 0; i < 3; i++) {
		this->_out_sunDirection[i] = this->_qPosNewArr[i + 1];
	}

	delete qRot;
	delete qRotStar;
	delete qPosOld;
	delete qPosNew;
	delete qTmp;

	/*PROTECTED REGION END*/

}
void Actuator::init() throw (simtg::Exception) {

	/*PROTECTED REGION ID(_rn_dMeCcEe-JhMcKl8Urew_startInit) ENABLED START*/
	// add user defined code here
	/*PROTECTED REGION END*/

	AsyncModelBase::init();

	/*PROTECTED REGION ID(_rn_dMeCcEe-JhMcKl8Urew_init) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}

/*PROTECTED REGION ID(_rn_dMeCcEe-JhMcKl8Urew_impl_cpp_end_extensionsimplementation) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/
