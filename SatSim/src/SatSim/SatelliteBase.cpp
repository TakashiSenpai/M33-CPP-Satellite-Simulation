/*
 * File SatelliteBase.cpp
 *
 * Project SatSim
 *
 *
 * Copyright (c) Astrium 2011. All rights reserved.
 *
 */

/*PROTECTED REGION ID(_Jcirwb1WEe-zAc57ptwKlg_auto_cpp_before_includeauto) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/

#include "Satellite.hpp"
#include <simtg/smp/TimeKeeperAdapter.hpp>
#include <simtg/smp/ConnectionService.hpp>
#include <simtg/smp/LoggerMacros.hpp>
#include <simtg/kernel/MethodCallAsyncDataListener.hpp>
#include "SunSensor.hpp"
#include "Orientation.hpp"

using namespace SatSim;

/*PROTECTED REGION ID(_Jcirwb1WEe-zAc57ptwKlg_auto_cpp_after_includeauto) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/

Satellite::Satellite(Smp::String8 name_, simtg::NamedObject* parent_,
		Smp::String8 description_) :
		AsyncModelBase(name_, parent_, description_), _sunDirection(
				"sunDirection", 3, 1, "-", simtg::INPUT, &_paramsContainer,
				this, 0), _input_sunDirection("input_sunDirection", 3, 1, "-",
				simtg::INPUT, &_data, this, 0), _out_measuredCurrents(
				"out_measuredCurrents", 4, 1, "-", simtg::OUTPUT, &_data, this,
				0), _out_cssSunDirection("out_cssSunDirection", 3, 1, "-",
				simtg::OUTPUT, &_data, this, 0), _out_elevation("out_elevation",
				1, 1, "-", simtg::OUTPUT, &_data, this, 0), _out_azimuth(
				"out_azimuth", 1, 1, "-", simtg::OUTPUT, &_data, this, 0), _out_test(
				"out_test", 40, 1, "-", simtg::OUTPUT, &_data, this, 0)

/*PROTECTED REGION ID(_Jcirwb1WEe-zAc57ptwKlg_defConst_constructor_init) ENABLED START*/
//add user defined code here
/*PROTECTED REGION END*/
{

	_SunSensor = new SunSensor("SunSensor", this, "");
	_Orientation = new Orientation("Orientation", this, "");

	_subModelsSequencer.push_back(_Orientation);
	_subModelsSequencer.push_back(_SunSensor);

	registerData();
	registerParams();
	registerStates();
	registerOthers();
	registerPorts();
	initDefaultValues();
	initScheduling();

	constructor();

	/*PROTECTED REGION ID(_Jcirwb1WEe-zAc57ptwKlg_defConst) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
Satellite::Satellite(Smp::String8 name_, Smp::String8 description_,
		Smp::IComposite* parent_) :
		AsyncModelBase(name_, description_, parent_), _sunDirection(
				"sunDirection", 3, 1, "-", simtg::INPUT, &_paramsContainer,
				this, 0), _input_sunDirection("input_sunDirection", 3, 1, "-",
				simtg::INPUT, &_data, this, 0), _out_measuredCurrents(
				"out_measuredCurrents", 4, 1, "-", simtg::OUTPUT, &_data, this,
				0), _out_cssSunDirection("out_cssSunDirection", 3, 1, "-",
				simtg::OUTPUT, &_data, this, 0), _out_elevation("out_elevation",
				1, 1, "-", simtg::OUTPUT, &_data, this, 0), _out_azimuth(
				"out_azimuth", 1, 1, "-", simtg::OUTPUT, &_data, this, 0), _out_test(
				"out_test", 40, 1, "-", simtg::OUTPUT, &_data, this, 0)

/*PROTECTED REGION ID(_Jcirwb1WEe-zAc57ptwKlg_namedConst_constructor_init) ENABLED START*/
//add user defined code here
/*PROTECTED REGION END*/
{

	_SunSensor = new SunSensor("SunSensor", this, "");
	_Orientation = new Orientation("Orientation", this, "");

	_subModelsSequencer.push_back(_Orientation);
	_subModelsSequencer.push_back(_SunSensor);

	registerData();
	registerParams();
	registerStates();
	registerOthers();
	registerPorts();
	initDefaultValues();
	initScheduling();

	constructor();

	/*PROTECTED REGION ID(_Jcirwb1WEe-zAc57ptwKlg_namedConst) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
Satellite::~Satellite() {

	delete _SunSensor;
	delete _Orientation;

	destructor();

	/*PROTECTED REGION ID(_Jcirwb1WEe-zAc57ptwKlg_defDestr) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Satellite::Publish(Smp::IPublication* publication_)
		throw (Smp::IModel::InvalidModelState) {

	ModelBase::Publish(publication_);
	try {
		/*PROTECTED REGION ID(_Jcirwb1WEe-zAc57ptwKlg_publish_catching) ENABLED START*/
		//add user defined code here
		/*PROTECTED REGION END*/
	} catch (simtg::Exception& simtgException) {
		throw simtg::ModelBase::InvalidModelState(_state, simtgException);
	} catch (Smp::Exception& smpException) {
		throw simtg::ModelBase::InvalidModelState(_state, smpException);
	}

	/*PROTECTED REGION ID(_Jcirwb1WEe-zAc57ptwKlg_publish) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Satellite::Configure(Smp::Services::ILogger* logger_)
		throw (Smp::IModel::InvalidModelState) {

	ModelBase::Configure(logger_);

	try {
		configure();
	} catch (simtg::Exception& simtgException) {
		throw simtg::ModelBase::InvalidModelState(_state, simtgException);
	} catch (Smp::Exception& smpException) {
		throw simtg::ModelBase::InvalidModelState(_state, smpException);
	}

	/*PROTECTED REGION ID(_Jcirwb1WEe-zAc57ptwKlg_configure) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Satellite::Connect(Smp::ISimulator* sim_)
		throw (Smp::IModel::InvalidModelState) {

	ModelBase::Connect(sim_);

	try {
		//data connections 
		connectData();
		//interface connections
		//system interface connections

		/*PROTECTED REGION ID(_Jcirwb1WEe-zAc57ptwKlg_connect_catching) ENABLED START*/
		//add user defined code here
		/*PROTECTED REGION END*/
	} catch (simtg::Exception& simtgException) {
		throw simtg::ModelBase::InvalidModelState(_state, simtgException);
	} catch (Smp::Exception& smpException) {
		throw simtg::ModelBase::InvalidModelState(_state, smpException);
	}

	/*PROTECTED REGION ID(_Jcirwb1WEe-zAc57ptwKlg_connect) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Satellite::connectData() throw (Smp::IModel::InvalidModelState) {

	try {
		//data connections 
		_SunSensor->getOutput("out_measuredCurrents").connect(
				&this->getOutput("out_measuredCurrents"), 0, 4, 0);
		this->getInput("input_sunDirection").connect(
				&_Orientation->getInput("in_satSunDirection"), 0, 3, 0);
		_Orientation->getOutput("out_cssSunDirection").connect(
				&_SunSensor->getInput("in_sunDirection"), 0, 3, 0);
		_Orientation->getOutput("out_cssSunDirection").connect(
				&this->getOutput("out_cssSunDirection"), 0, 3, 0);
		_Orientation->getOutput("sunAzimuth").connect(
				&this->getOutput("out_azimuth"));
		_Orientation->getOutput("sunLongitude").connect(
				&this->getOutput("out_elevation"));
		_Orientation->getOutput("sunLongitude").connect(
				&_SunSensor->getInput("in_sunEl"));
		_Orientation->getOutput("sunAzimuth").connect(
				&_SunSensor->getInput("in_sunAz"));
		_SunSensor->getOutput("out_test").connect(&this->getOutput("out_test"),
				0, 40, 0);

		/*PROTECTED REGION ID(_Jcirwb1WEe-zAc57ptwKlg_connectData_catching) ENABLED START*/
		//add user defined code here
		/*PROTECTED REGION END*/
	} catch (simtg::Exception& simtgException) {
		throw simtg::ModelBase::InvalidModelState(_state, simtgException);
	} catch (Smp::Exception& smpException) {
		throw simtg::ModelBase::InvalidModelState(_state, smpException);
	}

	/*PROTECTED REGION ID(_Jcirwb1WEe-zAc57ptwKlg_connectData) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Satellite::initDefaultValues() {

	//set init values of variables
	for (int row = 0; row < 3; row++) {
		_sunDirection[row] = 0.0;
	}
	for (int row = 0; row < 3; row++) {
		_input_sunDirection[row] = 0.0;
	}
	for (int row = 0; row < 4; row++) {
		_out_measuredCurrents[row] = 0.0;
	}
	for (int row = 0; row < 3; row++) {
		_out_cssSunDirection[row] = 0.0;
	}
	_out_elevation = 0.0;
	_out_azimuth = 0.0;
	for (int row = 0; row < 40; row++) {
		_out_test[row] = 0.0;
	}

	initSubModelsDefaultValues();

	/*PROTECTED REGION ID(_Jcirwb1WEe-zAc57ptwKlg_initDefaultValues) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Satellite::initSubModelsDefaultValues() {

	/*PROTECTED REGION ID(_Jcirwb1WEe-zAc57ptwKlg_initSubModelsDefaultValues) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Satellite::initScheduling() {

	std::list<MethodInfo> methods;

	/*PROTECTED REGION ID(_Jcirwb1WEe-zAc57ptwKlg_initScheduling_before_pushback) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/
	try {
		registerMethods(methods);
	} catch (simtg::Exception& e) {
		std::cerr << "Exception:" << e.what() << std::endl;
	}

	/*PROTECTED REGION ID(_Jcirwb1WEe-zAc57ptwKlg_initSheduling) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Satellite::callMethod(uint32_t methodId_, BaseType* params_)
		throw (SchedulableObject::BreakPointReached, simtg::Exception) {

	preCompute();
	switch (methodId_) {
	/*PROTECTED REGION ID(_Jcirwb1WEe-zAc57ptwKlg_callMethod_switch) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/
	default:
		ModelBase::callMethod(methodId_, params_);
	}
	postCompute();
	/*PROTECTED REGION ID(_Jcirwb1WEe-zAc57ptwKlg_callMethod) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Satellite::serializeMembers(simtg::SerializationStream& stream_)
		throw (simtg::SerializationException) {

	/*PROTECTED REGION ID(_Jcirwb1WEe-zAc57ptwKlg_start_serializeMembers) ENABLED START*/
	// add user defined code here
	/*PROTECTED REGION END*/

	_SunSensor->serialize(stream_);
	_Orientation->serialize(stream_);

	serializeExt(stream_);

	/*PROTECTED REGION ID(_Jcirwb1WEe-zAc57ptwKlg_serializeMembers) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}

/*PROTECTED REGION ID(_Jcirwb1WEe-zAc57ptwKlg_auto_cpp_end_extensionsauto) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/
