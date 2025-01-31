/*
 * File Baffle.cpp
 *
 * Project SatSim
 *
 *
 * Copyright (c) Astrium 2011. All rights reserved.
 *
 */

/*PROTECTED REGION ID(_ME22kN_sEe-b8OOJcDFPdw_impl_cpp_before_includeimplementation) ENABLED START*/
//add user defined includes here
#include <cmath>
/*PROTECTED REGION END*/

#include "Baffle.hpp"

using namespace SatSim;

OBJECT_MAKER(Baffle)

/*PROTECTED REGION ID(_ME22kN_sEe-b8OOJcDFPdw_impl_cpp_after_includeimplementation) ENABLED START*/
//add user defined includes here
#define MIN 0
#define MAX 1
/*PROTECTED REGION END*/

void Baffle::constructor() {
	/*PROTECTED REGION ID(_ME22kN_sEe-b8OOJcDFPdwdelegated_constructor) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Baffle::destructor() {
	/*PROTECTED REGION ID(_ME22kN_sEe-b8OOJcDFPdwdelegated_destructor) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Baffle::configure() throw (simtg::Exception) {
	/*PROTECTED REGION ID(_ME22kN_sEe-b8OOJcDFPdwdelegated_configure) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Baffle::serializeExt(simtg::SerializationStream& stream_) throw (simtg::SerializationException) {
	/*PROTECTED REGION ID(_ME22kN_sEe-b8OOJcDFPdwserializeExt) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Baffle::step() throw (simtg::Exception) {
	/*PROTECTED REGION ID(_ME22k9_sEe-b8OOJcDFPdw) ENABLED START*/
	//add user defined code here
	float el = this->_in_sunEl;
	float az = this->_in_sunAz;

	/*
	 * Calculate baffle sector based on sun azimuth and elevation
	 */

	float angle;

	// angle wrt. to sectors
	angle = az * 180 / M_PI + 4.5;

	// periodic boundary condition
	if (angle > 360) {
		angle -= 360;
	}

	this->_sector = static_cast<int>(angle / 9);

	// failsafe
	if (this->_sector < 0 || this->_sector > 40) {
		this->_sector = 0;
	}

	/*
	 * Calculate baffle coefficients
	 */

	// store current mins and maxs in helper variables
	float min[4] = {
			this->_yMinusFov[MIN][this->_sector],
			this->_yPlusFov[MIN][this->_sector],
			this->_zMinusFov[MIN][this->_sector],
			this->_zPlusFov[MIN][this->_sector]
	};
	float max[4] = {
			this->_yMinusFov[MAX][this->_sector],
			this->_yPlusFov[MAX][this->_sector],
			this->_zMinusFov[MAX][this->_sector],
			this->_zPlusFov[MAX][this->_sector]
	};

	for (int i = 0; i < 4; i++) {
		if (el < min[i]) {
			this->_baffleCoefficients[i] = 1;
		} else if (el > max[i]) {
			this->_baffleCoefficients[i] = 0;
		} else {
			this->_baffleCoefficients[i] = sin(max[i] - el) / sin(max[i] - min[i]);
		}
	}

	this->_out_baffleCoefficientMinusY = this->_baffleCoefficients[0];
	this->_out_baffleCoefficientPlusY = this->_baffleCoefficients[1];
	this->_out_baffleCoefficientMinusZ = this->_baffleCoefficients[2];
	this->_out_baffleCoefficientPlusZ = this->_baffleCoefficients[3];

	/*PROTECTED REGION END*/

}
void Baffle::init() throw (simtg::Exception) {

	/*PROTECTED REGION ID(_ME22kN_sEe-b8OOJcDFPdw_startInit) ENABLED START*/
	// add user defined code here
	/*
	 * Load the baffle field of view values from the csv file
	 */

	FILE *file;
	char line[512];
	const char* filePath = "BaffleDefinition.csv";
	file = fopen(filePath, "r");

	// failsafe
	if (file == NULL) {
		return;
	}

	// skip the first header line
	fgets(line, sizeof(line), file);

	int j = 0;
	while (fscanf(file, "%*i,%f,%f,%f,%f,%f,%f,%f,%f",
			&(this->_zPlusFov[MIN][j]), &(this->_zPlusFov[MAX][j]),
			&(this->_yMinusFov[MIN][j]), &(this->_yMinusFov[MAX][j]),
			&(this->_zMinusFov[MIN][j]), &(this->_zMinusFov[MAX][j]),
			&(this->_yPlusFov[MIN][j]), &(this->_yPlusFov[MAX][j]))) {
		j++;
		if (j >= 41) {
			break;
		}
	}

	fclose(file);

	// convert degrees to rad
	for (int i = 0; i < 40; i++) {
		this->_zPlusFov[MIN][i] *= M_PI / 180;
		this->_zPlusFov[MAX][i] *= M_PI / 180;
		this->_yMinusFov[MIN][i] *= M_PI / 180;
		this->_yMinusFov[MAX][i] *= M_PI / 180;
		this->_zMinusFov[MIN][i] *= M_PI / 180;
		this->_zMinusFov[MAX][i] *= M_PI / 180;
		this->_yPlusFov[MIN][i] *= M_PI / 180;
		this->_yPlusFov[MAX][i] *= M_PI / 180;
	}

	/*PROTECTED REGION END*/

	AsyncModelBase::init();

	/*PROTECTED REGION ID(_ME22kN_sEe-b8OOJcDFPdw_init) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}

/*PROTECTED REGION ID(_ME22kN_sEe-b8OOJcDFPdw_impl_cpp_end_extensionsimplementation) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/
