/*
 * quaternion.cpp
 *
 *  Created on: Feb 1, 2025
 *      Author: louis
 */

#include "quaternion.hpp"

#include <cmath>

Quaternion::Quaternion() {};

Quaternion::Quaternion(float w, float x, float y, float z){
	this->w = w;
	this->x = x;
	this->y = y;
	this->z = z;
}

Quaternion::~Quaternion() {}

float* Quaternion::toArray() {
	float* arr = new float[4];
	arr[0] = this->w;
	arr[1] = this->x;
	arr[2] = this->y;
	arr[3] = this->z;
	return arr;
}

Quaternion* Quaternion::multiply(Quaternion a, Quaternion b) {
	Quaternion *q = new Quaternion(
		a.w * b.w - a.x * b.x - a.y * b.y - a.z * b.z,
		a.w * b.x + a.x * b.w + a.y * b.z - a.z * b.y,
		a.w * b.y - a.x * b.z + a.y * b.w + a.z * b.x,
		a.w * b.z + a.x * b.y - a.y * b.x + a.z * b.w
	);
	return q;
}

Quaternion* Quaternion::getRotation(float* axis, float angle) {
	Quaternion *qRot = new Quaternion(
		cos(angle / 2),
		sin(angle / 2) * axis[0],
		sin(angle / 2) * axis[1],
		sin(angle / 2) * axis[2]
	);
	return qRot;
}

Quaternion* Quaternion::conjugate() {
	Quaternion *qStar = new Quaternion(
		this->w,
		-this->x,
		-this->y,
		-this->z
	);
	return qStar;
}


