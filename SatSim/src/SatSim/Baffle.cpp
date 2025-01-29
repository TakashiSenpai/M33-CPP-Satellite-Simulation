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
#include <stdio.h>

#define BLOGFILE "baffles.log"
/*PROTECTED REGION END*/

#include "Baffle.hpp"

using namespace SatSim;

OBJECT_MAKER(Baffle)

/*PROTECTED REGION ID(_o6L6MdNWEe-NefUk8IaYnw_impl_cpp_after_includeimplementation) ENABLED START*/
//add user defined includes here
void BinitLogFile() {
	FILE *logFile = fopen(BLOGFILE, "w");
	fclose(logFile);
}

void BlogToFile(char *msg) {
	FILE *logFile = fopen(BLOGFILE, "a");
	fprintf(logFile, msg);
	fprintf(logFile, "\n");
	fclose(logFile);
}
/*PROTECTED REGION END*/

void Baffle::constructor() {
	/*PROTECTED REGION ID(_o6L6MdNWEe-NefUk8IaYnwdelegated_constructor) ENABLED START*/
	//add user defined code here
	FILE *file;
	char line[512];
	const char* filePath = "BaffleDefinition.csv";
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

	BinitLogFile();
	// convert degrees to rad
	for (int i = 0; i < 40; i++) {
		/*
		 sprintf(line, "%f %f", this->_yMinusMin[i],
		 this->_yMinusMin[i] * M_PI / 180);
		 BlogToFile(line);
		 */
		this->_zPlusMin[i] *= M_PI / 180;
		this->_zPlusMax[i] *= M_PI / 180;
		this->_yMinusMin[i] *= M_PI / 180;
		this->_yMinusMax[i] *= M_PI / 180;
		this->_zMinusMin[i] *= M_PI / 180;
		this->_zMinusMax[i] *= M_PI / 180;
		this->_yPlusMin[i] *= M_PI / 180;
		this->_yPlusMax[i] *= M_PI / 180;
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
void Baffle::serializeExt(simtg::SerializationStream& stream_) throw (simtg::SerializationException) {
	/*PROTECTED REGION ID(_o6L6MdNWEe-NefUk8IaYnwserializeExt) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Baffle::step() throw (simtg::Exception) {
	/*PROTECTED REGION ID(_o6L6NNNWEe-NefUk8IaYnw) ENABLED START*/
	//add user defined code here
	// calculate sector
	/*PROTECTED REGION END*/

}
void Baffle::computeBaffleCoefficients() {
	/*PROTECTED REGION ID(_ZBm6oNcJEe-2FqChB99MmQ) ENABLED START*/
	//add user defined code here
	char msg[512];
	int sector;
	float tmp = 0;
	float el = this->_in_sunElevation;
	float az = this->_in_sunAzimuth;

	sprintf(msg, "\ntmp, az : %f %f", tmp, az);
	BlogToFile(msg);

	tmp = az * 180 / M_PI + 4.5;
	BlogToFile(msg);

	if (tmp > 360) {
		tmp -= 360;
	}
	tmp /= 9;

	sector = static_cast<int>(tmp);
	if (sector < 0 || sector > 40) {
		sector = 0;
		sprintf(msg, "\nFaulty Sector");
		BlogToFile(msg);
	}
	sprintf(msg, "\nSector id: %d", sector);
	BlogToFile(msg);

	// calculate k
	float min[4] = { this->_yMinusMin[sector], this->_yPlusMin[sector],
			this->_zMinusMin[sector], this->_zPlusMin[sector] };
	float max[4] = { this->_yMinusMax[sector], this->_yPlusMax[sector],
			this->_zMinusMax[sector], this->_zPlusMax[sector] };

	sprintf(msg, "mins: %f, %f, %f, %f", min[0], min[1], min[2], min[3]);
	BlogToFile(msg);
	sprintf(msg, "maxs: %f, %f, %f, %f", max[0], max[1], max[2], max[3]);
	BlogToFile(msg);

	sprintf(msg, "Elevation: %f, Azimuth: %f", el, az);
	BlogToFile(msg);

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
