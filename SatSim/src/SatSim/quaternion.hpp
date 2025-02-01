/*
 * quaternion.hpp
 *
 *  Created on: Feb 1, 2025
 *      Author: louis
 */

#ifndef SRC_SATSIM_QUATERNION_HPP_
#define SRC_SATSIM_QUATERNION_HPP_


class Quaternion {
public:
	float w;
	float x;
	float y;
	float z;

	Quaternion();
	Quaternion(float w, float x, float y, float z);
	~Quaternion();

	Quaternion* conjugate();
	static Quaternion* multiply(Quaternion a, Quaternion b);
	static Quaternion* getRotation(float *axis, float angle);
	float* toArray();
};


#endif /* SRC_SATSIM_QUATERNION_HPP_ */
