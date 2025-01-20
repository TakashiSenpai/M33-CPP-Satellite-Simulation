/*
 * File Baffle.cpp
 *
 * Project SatSim
 *
 *
 * Copyright (c) Astrium 2011. All rights reserved.
 *
 */

/*PROTECTED REGION ID(_o6L6MdNWEe-NefUk8IaYnw_impl_cpp_before_includeimplementation) ENABLED START*/
//add user defined includes here
#include <stdio.h>
#include <cmath>
/*PROTECTED REGION END*/

#include "Baffle.hpp"

using namespace SatSim;

OBJECT_MAKER(Baffle)

/*PROTECTED REGION ID(_o6L6MdNWEe-NefUk8IaYnw_impl_cpp_after_includeimplementation) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/

void Baffle::constructor() {
	/*PROTECTED REGION ID(_o6L6MdNWEe-NefUk8IaYnwdelegated_constructor) ENABLED START*/
	//add user defined code here
	FILE *file;
	char line[512];
	const char* filePath =
			"/home/louis/simtg/workspace/SatSim/src/SatSim/BaffleDefinition.csv";
	file = fopen(filePath, "r");

	if (file == NULL) {
		std::cout << "failed to open file";
		return;
	}
	int j = 0;

	fgets(line, sizeof(line), file);
	while (fscanf(file, "%*i,%f,%f,%f,%f,%f,%f,%f,%f", &(this->_zPlusMin[j]),
			&(this->_zPlusMax[j]), &(this->_yMinusMin[j]),
			&(this->_yMinusMax[j]), &(this->_zMinusMin[j]),
			&(this->_zMinusMax[j]), &(this->_yPlusMin[j]),
			&(this->_yPlusMax[j]))) {
		j++;
		if (j >= 41) {
			break;
		}
	}

	fclose(file);
	for (int i = 0; i < 40; i++) {
		this->_out_test[i] = this->_zPlusMin[i];
	}
	return;
	/*
	 */
	/*PROTECTED REGION END*/

}
void Baffle::destructor() {
	/*PROTECTED REGION ID(_o6L6MdNWEe-NefUk8IaYnwdelegated_destructor) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Baffle::configure() throw (simtg::Exception) {
	/*PROTECTED REGION ID(_o6L6MdNWEe-NefUk8IaYnwdelegated_configure) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Baffle::serializeExt(simtg::SerializationStream& stream_)
		throw (simtg::SerializationException) {
	/*PROTECTED REGION ID(_o6L6MdNWEe-NefUk8IaYnwserializeExt) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Baffle::step() throw (simtg::Exception) {
	/*PROTECTED REGION ID(_o6L6NNNWEe-NefUk8IaYnw) ENABLED START*/
	//add user defined code here
	// calculate sector
	int sector = static_cast<int>(remainder(
			this->_in_sunAzimuth * 180 / M_PI + 4.5, 360) / 9);

	// calculate k
	float min[4] = { this->_yMinusMin[sector], this->_yPlusMin[sector],
			this->_zMinusMin[sector], this->_yPlusMin[sector] };
	float max[4] = { this->_yMinusMax[sector], this->_yPlusMax[sector],
			this->_zMinusMax[sector], this->_yPlusMax[sector] };
	float el = this->_in_sunElevation;

	for (int i = 0; i < 4; i++) {
		if (el < min[i]) {
			this->_out_baffleCoefficient[i] = 1;
		} else if (el > max[i]) {
			this->_out_baffleCoefficient[i] = 0;
		} else {
			this->_out_baffleCoefficient[i] = sin(max[i] - el)
					/ sin(max[i] - min[i]);
		}
	}

	/*PROTECTED REGION END*/

}
void Baffle::init() throw (simtg::Exception) {

	/*PROTECTED REGION ID(_o6L6MdNWEe-NefUk8IaYnw_startInit) ENABLED START*/
	// add user defined code here
	/*PROTECTED REGION END*/

	AsyncModelBase::init();

	/*PROTECTED REGION ID(_o6L6MdNWEe-NefUk8IaYnw_init) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}

/*PROTECTED REGION ID(_o6L6MdNWEe-NefUk8IaYnw_impl_cpp_end_extensionsimplementation) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/
