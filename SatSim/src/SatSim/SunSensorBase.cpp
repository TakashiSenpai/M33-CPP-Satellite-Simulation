/*
 * File SunSensorBase.cpp
 *
 * Project SatSim
 *
 *
 * Copyright (c) Astrium 2011. All rights reserved.
 *
 */

/*PROTECTED REGION ID(_-xPEYN_rEe-b8OOJcDFPdw_auto_cpp_before_includeauto) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/

#include "SunSensor.hpp"
#include <simtg/smp/TimeKeeperAdapter.hpp>
#include <simtg/smp/ConnectionService.hpp>
#include <simtg/smp/LoggerMacros.hpp>
#include <simtg/kernel/MethodCallAsyncDataListener.hpp>
#include "Baffle.hpp"
#include "Cell.hpp"
#include "Orientation.hpp"
#include "AnalogToDigitalConverter.hpp"

using namespace SatSim;

/*PROTECTED REGION ID(_-xPEYN_rEe-b8OOJcDFPdw_auto_cpp_after_includeauto) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/

SunSensor::SunSensor(Smp::String8 name_, simtg::NamedObject* parent_, Smp::String8 description_) :
		AsyncModelBase(name_, parent_, description_),
				_in_sunDirection("in_sunDirection", 3, 1, "-", simtg::INPUT, &_data, this, 0)
						, _out_controlSignal("out_controlSignal", 2, 1, "-", simtg::OUTPUT, &_data, this, 0)
						, _out_mode("out_mode", 1, 1, "-", simtg::OUTPUT, &_data, this, 0)
						, _forceStep("forceStep", 1, 1, "-", simtg::INPUT, &_data, this, 0)

/*PROTECTED REGION ID(_-xPEYN_rEe-b8OOJcDFPdw_defConst_constructor_init) ENABLED START*/
//add user defined code here
/*PROTECTED REGION END*/
{

	_Baffle = new Baffle("Baffle", this, "");
	_Cell_PlusY = new Cell("Cell_PlusY", this, "");
	_Cell_MinusY = new Cell("Cell_MinusY", this, "");
	_Cell_PlusZ = new Cell("Cell_PlusZ", this, "");
	_Cell_MinusZ = new Cell("Cell_MinusZ", this, "");
	_Orientation = new Orientation("Orientation", this, "");
	_ADC = new AnalogToDigitalConverter("ADC", this, "");

	_subModelsSequencer.push_back(_Orientation);
	_subModelsSequencer.push_back(_Baffle);
	_subModelsSequencer.push_back(_Cell_PlusY);
	_subModelsSequencer.push_back(_Cell_PlusZ);
	_subModelsSequencer.push_back(_Cell_MinusY);
	_subModelsSequencer.push_back(_Cell_MinusZ);
	_subModelsSequencer.push_back(_ADC);

	registerData();
	registerParams();
	registerStates();
	registerOthers();
	registerPorts();
	initDefaultValues();
	initScheduling();

	constructor();

	/*PROTECTED REGION ID(_-xPEYN_rEe-b8OOJcDFPdw_defConst) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
SunSensor::SunSensor(Smp::String8 name_, Smp::String8 description_, Smp::IComposite* parent_) :
		AsyncModelBase(name_, description_, parent_),
				_in_sunDirection("in_sunDirection", 3, 1, "-", simtg::INPUT, &_data, this, 0)
						, _out_controlSignal("out_controlSignal", 2, 1, "-", simtg::OUTPUT, &_data, this, 0)
						, _out_mode("out_mode", 1, 1, "-", simtg::OUTPUT, &_data, this, 0)
						, _forceStep("forceStep", 1, 1, "-", simtg::INPUT, &_data, this, 0)

/*PROTECTED REGION ID(_-xPEYN_rEe-b8OOJcDFPdw_namedConst_constructor_init) ENABLED START*/
//add user defined code here
/*PROTECTED REGION END*/
{

	_Baffle = new Baffle("Baffle", this, "");
	_Cell_PlusY = new Cell("Cell_PlusY", this, "");
	_Cell_MinusY = new Cell("Cell_MinusY", this, "");
	_Cell_PlusZ = new Cell("Cell_PlusZ", this, "");
	_Cell_MinusZ = new Cell("Cell_MinusZ", this, "");
	_Orientation = new Orientation("Orientation", this, "");
	_ADC = new AnalogToDigitalConverter("ADC", this, "");

	_subModelsSequencer.push_back(_Orientation);
	_subModelsSequencer.push_back(_Baffle);
	_subModelsSequencer.push_back(_Cell_PlusY);
	_subModelsSequencer.push_back(_Cell_PlusZ);
	_subModelsSequencer.push_back(_Cell_MinusY);
	_subModelsSequencer.push_back(_Cell_MinusZ);
	_subModelsSequencer.push_back(_ADC);

	registerData();
	registerParams();
	registerStates();
	registerOthers();
	registerPorts();
	initDefaultValues();
	initScheduling();

	constructor();

	/*PROTECTED REGION ID(_-xPEYN_rEe-b8OOJcDFPdw_namedConst) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
SunSensor::~SunSensor() {

	delete _Baffle;
	delete _Cell_PlusY;
	delete _Cell_MinusY;
	delete _Cell_PlusZ;
	delete _Cell_MinusZ;
	delete _Orientation;
	delete _ADC;

	destructor();

	/*PROTECTED REGION ID(_-xPEYN_rEe-b8OOJcDFPdw_defDestr) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void SunSensor::Publish(Smp::IPublication* publication_) throw (Smp::IModel::InvalidModelState) {

	ModelBase::Publish(publication_);
	try {
		/*PROTECTED REGION ID(_-xPEYN_rEe-b8OOJcDFPdw_publish_catching) ENABLED START*/
		//add user defined code here
		/*PROTECTED REGION END*/
	}
	catch (simtg::Exception& simtgException) {
		throw simtg::ModelBase::InvalidModelState(_state, simtgException);
	}
	catch (Smp::Exception& smpException) {
		throw simtg::ModelBase::InvalidModelState(_state, smpException);
	}

	/*PROTECTED REGION ID(_-xPEYN_rEe-b8OOJcDFPdw_publish) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void SunSensor::Configure(Smp::Services::ILogger* logger_) throw (Smp::IModel::InvalidModelState) {

	ModelBase::Configure(logger_);

	try {
		configure();
	}
	catch (simtg::Exception& simtgException) {
		throw simtg::ModelBase::InvalidModelState(_state, simtgException);
	}
	catch (Smp::Exception& smpException) {
		throw simtg::ModelBase::InvalidModelState(_state, smpException);
	}

	/*PROTECTED REGION ID(_-xPEYN_rEe-b8OOJcDFPdw_configure) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void SunSensor::Connect(Smp::ISimulator* sim_) throw (Smp::IModel::InvalidModelState) {

	ModelBase::Connect(sim_);

	try {
		//data connections 
		connectData();
		//interface connections
		//system interface connections

		/*PROTECTED REGION ID(_-xPEYN_rEe-b8OOJcDFPdw_connect_catching) ENABLED START*/
		//add user defined code here
		/*PROTECTED REGION END*/
	}
	catch (simtg::Exception& simtgException) {
		throw simtg::ModelBase::InvalidModelState(_state, simtgException);
	}
	catch (Smp::Exception& smpException) {
		throw simtg::ModelBase::InvalidModelState(_state, smpException);
	}

	/*PROTECTED REGION ID(_-xPEYN_rEe-b8OOJcDFPdw_connect) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void SunSensor::connectData() throw (Smp::IModel::InvalidModelState) {

	try {
		//data connections 
		_Baffle->getOutput("out_baffleCoefficientPlusY").connect(&_Cell_PlusY->getInput("in_baffleCoefficient"));
		_Baffle->getOutput("out_baffleCoefficientMinusZ").connect(&_Cell_MinusZ->getInput("in_baffleCoefficient"));
		_Baffle->getOutput("out_baffleCoefficientPlusZ").connect(&_Cell_PlusZ->getInput("in_baffleCoefficient"));
		_Baffle->getOutput("out_baffleCoefficientMinusY").connect(&_Cell_MinusY->getInput("in_baffleCoefficient"));
		this->getInput("in_sunDirection").connect(&_Orientation->getInput("in_satFrameVector"), 0, 3, 0);
		_Orientation->getOutput("out_sunEl").connect(&_Baffle->getInput("in_sunEl"));
		_Orientation->getOutput("out_sunAz").connect(&_Baffle->getInput("in_sunAz"));
		_Orientation->getOutput("out_cssFrameVector").connect(&_Cell_PlusY->getInput("in_cssSunDirection"), 0, 3, 0);
		_Orientation->getOutput("out_cssFrameVector").connect(&_Cell_MinusY->getInput("in_cssSunDirection"), 0, 3, 0);
		_Orientation->getOutput("out_cssFrameVector").connect(&_Cell_PlusZ->getInput("in_cssSunDirection"), 0, 3, 0);
		_Orientation->getOutput("out_cssFrameVector").connect(&_Cell_MinusZ->getInput("in_cssSunDirection"), 0, 3, 0);
		_Cell_PlusY->getOutput("out_measuredCurrent").connect(&_ADC->getInput("in_measuredCurrentPlusY"));
		_Cell_MinusY->getOutput("out_measuredCurrent").connect(&_ADC->getInput("in_measuredCurrentMinusY"));
		_Cell_PlusZ->getOutput("out_measuredCurrent").connect(&_ADC->getInput("in_measuredCurrentPlusZ"));
		_Cell_MinusZ->getOutput("out_measuredCurrent").connect(&_ADC->getInput("in_measuredCurrentMinusZ"));
		_ADC->getOutput("out_controlSignal").connect(&this->getOutput("out_controlSignal"), 0, 2, 0);
		_ADC->getOutput("out_mode").connect(&this->getOutput("out_mode"));
		this->getInput("forceStep").connect(&_Cell_PlusY->getInput("forceStep"));
		this->getInput("forceStep").connect(&_Cell_MinusY->getInput("forceStep"));
		this->getInput("forceStep").connect(&_Cell_PlusZ->getInput("forceStep"));
		this->getInput("forceStep").connect(&_Cell_MinusZ->getInput("forceStep"));
		this->getInput("forceStep").connect(&_Orientation->getInput("forceStep"));
		this->getInput("forceStep").connect(&_Baffle->getInput("forceStep"));
		this->getInput("forceStep").connect(&_ADC->getInput("forceStep"));

		/*PROTECTED REGION ID(_-xPEYN_rEe-b8OOJcDFPdw_connectData_catching) ENABLED START*/
		//add user defined code here
		/*PROTECTED REGION END*/
	}
	catch (simtg::Exception& simtgException) {
		throw simtg::ModelBase::InvalidModelState(_state, simtgException);
	}
	catch (Smp::Exception& smpException) {
		throw simtg::ModelBase::InvalidModelState(_state, smpException);
	}

	/*PROTECTED REGION ID(_-xPEYN_rEe-b8OOJcDFPdw_connectData) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void SunSensor::initDefaultValues() {

	//set init values of variables
	for (int row = 0; row < 3; row++) {
		_in_sunDirection[row] = 0.0;
	}
	_orientationPlusY[0] = 1.0;
	_orientationPlusY[1] = 1.0;
	_orientationPlusY[2] = 0.0;
	_orientationPlusZ[0] = 1.0;
	_orientationPlusZ[1] = 0.0;
	_orientationPlusZ[2] = 1.0;
	_orientationMinusY[0] = 1.0;
	_orientationMinusY[1] = -1.0;
	_orientationMinusY[2] = 0.0;
	_orientationMinusZ[0] = 1.0;
	_orientationMinusZ[1] = 0.0;
	_orientationMinusZ[2] = -1.0;
	_angle = 22;
	for (int row = 0; row < 2; row++) {
		_out_controlSignal[row] = 0.0;
	}
	_out_mode = 0;
	_forceStep = 0;

	initSubModelsDefaultValues();

	/*PROTECTED REGION ID(_-xPEYN_rEe-b8OOJcDFPdw_initDefaultValues) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void SunSensor::initSubModelsDefaultValues() {

	/*PROTECTED REGION ID(_-xPEYN_rEe-b8OOJcDFPdw_initSubModelsDefaultValues) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void SunSensor::initScheduling() {

	std::list<MethodInfo> methods;

	/*PROTECTED REGION ID(_-xPEYN_rEe-b8OOJcDFPdw_initScheduling_before_pushback) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/
	try {
		registerMethods(methods);
	}
	catch (simtg::Exception& e) {
		std::cerr << "Exception:" << e.what() << std::endl;
	}

	/*PROTECTED REGION ID(_-xPEYN_rEe-b8OOJcDFPdw_initSheduling) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void SunSensor::callMethod(uint32_t methodId_, BaseType* params_) throw (SchedulableObject::BreakPointReached, simtg::Exception) {

	preCompute();
	switch (methodId_) {
	/*PROTECTED REGION ID(_-xPEYN_rEe-b8OOJcDFPdw_callMethod_switch) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/
	default:
		ModelBase::callMethod(methodId_, params_);
	}
	postCompute();
	/*PROTECTED REGION ID(_-xPEYN_rEe-b8OOJcDFPdw_callMethod) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void SunSensor::serializeMembers(simtg::SerializationStream& stream_) throw (simtg::SerializationException) {

	/*PROTECTED REGION ID(_-xPEYN_rEe-b8OOJcDFPdw_start_serializeMembers) ENABLED START*/
	// add user defined code here
	/*PROTECTED REGION END*/

	stream_.array(&_orientationPlusY[0], 3);
	stream_.array(&_orientationPlusZ[0], 3);
	stream_.array(&_orientationMinusY[0], 3);
	stream_.array(&_orientationMinusZ[0], 3);
	stream_.value(_angle);

	_Baffle->serialize(stream_);
	_Cell_PlusY->serialize(stream_);
	_Cell_MinusY->serialize(stream_);
	_Cell_PlusZ->serialize(stream_);
	_Cell_MinusZ->serialize(stream_);
	_Orientation->serialize(stream_);
	_ADC->serialize(stream_);

	serializeExt(stream_);

	/*PROTECTED REGION ID(_-xPEYN_rEe-b8OOJcDFPdw_serializeMembers) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}

/*PROTECTED REGION ID(_-xPEYN_rEe-b8OOJcDFPdw_auto_cpp_end_extensionsauto) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/
