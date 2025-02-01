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

	// compute rotation axis
	float target[3] = { 0, 0, -1 };
	float position[3] = {
			this->_in_rotationAngles[1],
			this->_in_rotationAngles[0],
			0
	};

	float axis[3] = {
			position[1] * target[2] - position[2] * target[1],
			position[2] * target[0] - position[0] * target[2],
			position[0] * target[1] - position[1] * target[0]
	};

	this->_angle = sqrt(pow(this->_in_rotationAngles[0], 2) + pow(this->_in_rotationAngles[1], 2));
	if (this->_angle > this->_maxRotationAngle * M_PI / 180) {
		this->_angle = this->_maxRotationAngle * M_PI / 180;
	}

	Quaternion *qRot = Quaternion::getRotation(axis, (-1) * this->_angle);
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

	/*
	 * Rotate Satellite THIS IS A BIT BAD, BETTER USE QUATERNIONS!


	 float angles[2];
	 angles[0] = this->_in_rotationAngles[0];
	 angles[1] = this->_in_rotationAngles[1];

	 // build the rotation matrices
	 this->_rotY.at(0, 0) = cos(angles[0]);
	 this->_rotY.at(0, 1) = 0;
	 this->_rotY.at(0, 2) = sin(angles[0]);
	 this->_rotY.at(1, 0) = 0;
	 this->_rotY.at(1, 1) = 1;
	 this->_rotY.at(1, 2) = 0;
	 this->_rotY.at(2, 0) = -sin(angles[0]);
	 this->_rotY.at(2, 1) = 0;
	 this->_rotY.at(2, 2) = cos(angles[0]);

	 this->_rotX.at(0, 0) = 1;
	 this->_rotX.at(0, 1) = 0;
	 this->_rotX.at(0, 2) = 0;
	 this->_rotX.at(1, 0) = 0;
	 this->_rotX.at(1, 1) = cos(angles[1]);
	 this->_rotX.at(1, 2) = -sin(angles[1]);
	 this->_rotX.at(2, 0) = 0;
	 this->_rotX.at(2, 1) = sin(angles[1]);
	 this->_rotX.at(2, 2) = cos(angles[1]);

	 for (int i = 0; i < 3; i++) {
	 this->_sunDirectionRotY[i] = 0;
	 for (int j = 0; j < 3; j++) {
	 this->_sunDirectionRotY[i] += this->_rotY.at(i, j) * this->_in_sunDirection[j];
	 }
	 }

	 for (int i = 0; i < 3; i++) {
	 this->_sunDirectionRotX[i] = 0;
	 for (int j = 0; j < 3; j++) {
	 this->_sunDirectionRotX[i] += this->_rotX.at(i, j) * this->_sunDirectionRotY[j];
	 }
	 }

	 for (int i = 0; i < 3; i++) {
	 this->_out_sunDirection[i] = this->_sunDirectionRotX[i];
	 }
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
