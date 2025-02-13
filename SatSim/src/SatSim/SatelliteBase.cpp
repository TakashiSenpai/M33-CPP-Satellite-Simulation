/*
 * File SatelliteBase.cpp
 *
 * Project SatSim
 *
 *
 * Copyright (c) Astrium 2011. All rights reserved.
 *
 */

/*PROTECTED REGION ID(_xuql8N_rEe-b8OOJcDFPdw_auto_cpp_before_includeauto) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/

#include "Satellite.hpp"
#include <simtg/smp/TimeKeeperAdapter.hpp>
#include <simtg/smp/ConnectionService.hpp>
#include <simtg/smp/LoggerMacros.hpp>
#include <simtg/kernel/MethodCallAsyncDataListener.hpp>
#include "SunSensor.hpp"
#include "AttitudeControlSystem.hpp"

using namespace SatSim;

/*PROTECTED REGION ID(_xuql8N_rEe-b8OOJcDFPdw_auto_cpp_after_includeauto) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/

Satellite::Satellite(Smp::String8 name_, simtg::NamedObject* parent_, Smp::String8 description_) :
		AsyncModelBase(name_, parent_, description_),
				_in_sunDirection("in_sunDirection", 3, 1, "-", simtg::INPUT, &_data, this, 0)
						, _out_sunDirection("out_sunDirection", 3, 1, "-", simtg::OUTPUT, &_data, this, 0)
						, _forceStep("forceStep", 1, 1, "-", simtg::INPUT, &_data, this, 0)

/*PROTECTED REGION ID(_xuql8N_rEe-b8OOJcDFPdw_defConst_constructor_init) ENABLED START*/
//add user defined code here
/*PROTECTED REGION END*/
{

	_SunSensor = new SunSensor("SunSensor", this, "");
	_ACS = new AttitudeControlSystem("ACS", this, "");

	_subModelsSequencer.push_back(_SunSensor);
	_subModelsSequencer.push_back(_ACS);

	registerData();
	registerParams();
	registerStates();
	registerOthers();
	registerPorts();
	initDefaultValues();
	initScheduling();

	constructor();

	/*PROTECTED REGION ID(_xuql8N_rEe-b8OOJcDFPdw_defConst) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
Satellite::Satellite(Smp::String8 name_, Smp::String8 description_, Smp::IComposite* parent_) :
		AsyncModelBase(name_, description_, parent_),
				_in_sunDirection("in_sunDirection", 3, 1, "-", simtg::INPUT, &_data, this, 0)
						, _out_sunDirection("out_sunDirection", 3, 1, "-", simtg::OUTPUT, &_data, this, 0)
						, _forceStep("forceStep", 1, 1, "-", simtg::INPUT, &_data, this, 0)

/*PROTECTED REGION ID(_xuql8N_rEe-b8OOJcDFPdw_namedConst_constructor_init) ENABLED START*/
//add user defined code here
/*PROTECTED REGION END*/
{

	_SunSensor = new SunSensor("SunSensor", this, "");
	_ACS = new AttitudeControlSystem("ACS", this, "");

	_subModelsSequencer.push_back(_SunSensor);
	_subModelsSequencer.push_back(_ACS);

	registerData();
	registerParams();
	registerStates();
	registerOthers();
	registerPorts();
	initDefaultValues();
	initScheduling();

	constructor();

	/*PROTECTED REGION ID(_xuql8N_rEe-b8OOJcDFPdw_namedConst) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
Satellite::~Satellite() {

	delete _SunSensor;
	delete _ACS;

	destructor();

	/*PROTECTED REGION ID(_xuql8N_rEe-b8OOJcDFPdw_defDestr) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Satellite::Publish(Smp::IPublication* publication_) throw (Smp::IModel::InvalidModelState) {

	ModelBase::Publish(publication_);
	try {
		/*PROTECTED REGION ID(_xuql8N_rEe-b8OOJcDFPdw_publish_catching) ENABLED START*/
		//add user defined code here
		/*PROTECTED REGION END*/
	}
	catch (simtg::Exception& simtgException) {
		throw simtg::ModelBase::InvalidModelState(_state, simtgException);
	}
	catch (Smp::Exception& smpException) {
		throw simtg::ModelBase::InvalidModelState(_state, smpException);
	}

	/*PROTECTED REGION ID(_xuql8N_rEe-b8OOJcDFPdw_publish) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Satellite::Configure(Smp::Services::ILogger* logger_) throw (Smp::IModel::InvalidModelState) {

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

	/*PROTECTED REGION ID(_xuql8N_rEe-b8OOJcDFPdw_configure) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Satellite::Connect(Smp::ISimulator* sim_) throw (Smp::IModel::InvalidModelState) {

	ModelBase::Connect(sim_);

	try {
		//data connections 
		connectData();
		//interface connections
		//system interface connections

		/*PROTECTED REGION ID(_xuql8N_rEe-b8OOJcDFPdw_connect_catching) ENABLED START*/
		//add user defined code here
		/*PROTECTED REGION END*/
	}
	catch (simtg::Exception& simtgException) {
		throw simtg::ModelBase::InvalidModelState(_state, simtgException);
	}
	catch (Smp::Exception& smpException) {
		throw simtg::ModelBase::InvalidModelState(_state, smpException);
	}

	/*PROTECTED REGION ID(_xuql8N_rEe-b8OOJcDFPdw_connect) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Satellite::connectData() throw (Smp::IModel::InvalidModelState) {

	try {
		//data connections 
		_SunSensor->getOutput("out_controlSignal").connect(&_ACS->getInput("in_controlSignal"), 0, 2, 0);
		_ACS->getOutput("out_sunDirection").connect(&this->getOutput("out_sunDirection"), 0, 3, 0);
		this->getInput("in_sunDirection").connect(&_ACS->getInput("in_sunDirection"), 0, 3, 0);
		this->getInput("in_sunDirection").connect(&_SunSensor->getInput("in_sunDirection"), 0, 3, 0);
		_SunSensor->getOutput("out_mode").connect(&_ACS->getInput("in_mode"));
		this->getInput("forceStep").connect(&_SunSensor->getInput("forceStep"));
		this->getInput("forceStep").connect(&_ACS->getInput("forceStep"));

		/*PROTECTED REGION ID(_xuql8N_rEe-b8OOJcDFPdw_connectData_catching) ENABLED START*/
		//add user defined code here
		/*PROTECTED REGION END*/
	}
	catch (simtg::Exception& simtgException) {
		throw simtg::ModelBase::InvalidModelState(_state, simtgException);
	}
	catch (Smp::Exception& smpException) {
		throw simtg::ModelBase::InvalidModelState(_state, smpException);
	}

	/*PROTECTED REGION ID(_xuql8N_rEe-b8OOJcDFPdw_connectData) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Satellite::initDefaultValues() {

	//set init values of variables
	for (int row = 0; row < 3; row++) {
		_in_sunDirection[row] = 0.0;
	}
	for (int row = 0; row < 3; row++) {
		_out_sunDirection[row] = 0.0;
	}
	_forceStep = 0;

	initSubModelsDefaultValues();

	/*PROTECTED REGION ID(_xuql8N_rEe-b8OOJcDFPdw_initDefaultValues) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Satellite::initSubModelsDefaultValues() {

	/*PROTECTED REGION ID(_xuql8N_rEe-b8OOJcDFPdw_initSubModelsDefaultValues) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Satellite::initScheduling() {

	std::list<MethodInfo> methods;

	/*PROTECTED REGION ID(_xuql8N_rEe-b8OOJcDFPdw_initScheduling_before_pushback) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/
	try {
		registerMethods(methods);
	}
	catch (simtg::Exception& e) {
		std::cerr << "Exception:" << e.what() << std::endl;
	}

	/*PROTECTED REGION ID(_xuql8N_rEe-b8OOJcDFPdw_initSheduling) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Satellite::callMethod(uint32_t methodId_, BaseType* params_) throw (SchedulableObject::BreakPointReached, simtg::Exception) {

	preCompute();
	switch (methodId_) {
	/*PROTECTED REGION ID(_xuql8N_rEe-b8OOJcDFPdw_callMethod_switch) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/
	default:
		ModelBase::callMethod(methodId_, params_);
	}
	postCompute();
	/*PROTECTED REGION ID(_xuql8N_rEe-b8OOJcDFPdw_callMethod) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Satellite::serializeMembers(simtg::SerializationStream& stream_) throw (simtg::SerializationException) {

	/*PROTECTED REGION ID(_xuql8N_rEe-b8OOJcDFPdw_start_serializeMembers) ENABLED START*/
	// add user defined code here
	/*PROTECTED REGION END*/

	_SunSensor->serialize(stream_);
	_ACS->serialize(stream_);

	serializeExt(stream_);

	/*PROTECTED REGION ID(_xuql8N_rEe-b8OOJcDFPdw_serializeMembers) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}

/*PROTECTED REGION ID(_xuql8N_rEe-b8OOJcDFPdw_auto_cpp_end_extensionsauto) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/
