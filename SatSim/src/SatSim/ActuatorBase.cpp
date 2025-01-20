/*
 * File ActuatorBase.cpp
 *
 * Project SatSim
 *
 *
 * Copyright (c) Astrium 2011. All rights reserved.
 *
 */

/*PROTECTED REGION ID(_LVfTodcvEe-g-_tbVlfW3w_auto_cpp_before_includeauto) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/

#include "Actuator.hpp"
#include <simtg/smp/TimeKeeperAdapter.hpp>
#include <simtg/smp/ConnectionService.hpp>
#include <simtg/smp/LoggerMacros.hpp>

using namespace SatSim;

/*PROTECTED REGION ID(_LVfTodcvEe-g-_tbVlfW3w_auto_cpp_after_includeauto) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/

Actuator::Actuator(Smp::String8 name_, simtg::NamedObject* parent_,
		Smp::String8 description_) :
		ModelBase(name_, parent_, description_),
				_in_measuredCurrents("in_measuredCurrents", 4, 1, "-", simtg::INPUT, &_data, 0)

/*PROTECTED REGION ID(_LVfTodcvEe-g-_tbVlfW3w_defConst_constructor_init) ENABLED START*/
//add user defined code here
/*PROTECTED REGION END*/
{

	registerData();
	registerParams();
	registerStates();
	registerOthers();
	registerPorts();
	initDefaultValues();
	initScheduling();

	constructor();

	/*PROTECTED REGION ID(_LVfTodcvEe-g-_tbVlfW3w_defConst) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
Actuator::Actuator(Smp::String8 name_, Smp::String8 description_,
		Smp::IComposite* parent_) :
		ModelBase(name_, description_, parent_),
				_in_measuredCurrents("in_measuredCurrents", 4, 1, "-", simtg::INPUT, &_data, 0)

/*PROTECTED REGION ID(_LVfTodcvEe-g-_tbVlfW3w_namedConst_constructor_init) ENABLED START*/
//add user defined code here
/*PROTECTED REGION END*/
{

	registerData();
	registerParams();
	registerStates();
	registerOthers();
	registerPorts();
	initDefaultValues();
	initScheduling();

	constructor();

	/*PROTECTED REGION ID(_LVfTodcvEe-g-_tbVlfW3w_namedConst) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
Actuator::~Actuator() {

	destructor();

	/*PROTECTED REGION ID(_LVfTodcvEe-g-_tbVlfW3w_defDestr) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Actuator::Publish(Smp::IPublication* publication_)
		throw (Smp::IModel::InvalidModelState) {

	ModelBase::Publish(publication_);
	try {
		/*PROTECTED REGION ID(_LVfTodcvEe-g-_tbVlfW3w_publish_catching) ENABLED START*/
		//add user defined code here
		/*PROTECTED REGION END*/
	}
	catch (simtg::Exception& simtgException) {
		throw simtg::ModelBase::InvalidModelState(_state, simtgException);
	}
	catch (Smp::Exception& smpException) {
		throw simtg::ModelBase::InvalidModelState(_state, smpException);
	}

	/*PROTECTED REGION ID(_LVfTodcvEe-g-_tbVlfW3w_publish) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Actuator::Configure(Smp::Services::ILogger* logger_)
		throw (Smp::IModel::InvalidModelState) {

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

	/*PROTECTED REGION ID(_LVfTodcvEe-g-_tbVlfW3w_configure) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Actuator::Connect(Smp::ISimulator* sim_)
		throw (Smp::IModel::InvalidModelState) {

	ModelBase::Connect(sim_);

	try {
		//data connections 
		connectData();
		//interface connections
		//system interface connections

		/*PROTECTED REGION ID(_LVfTodcvEe-g-_tbVlfW3w_connect_catching) ENABLED START*/
		//add user defined code here
		/*PROTECTED REGION END*/
	}
	catch (simtg::Exception& simtgException) {
		throw simtg::ModelBase::InvalidModelState(_state, simtgException);
	}
	catch (Smp::Exception& smpException) {
		throw simtg::ModelBase::InvalidModelState(_state, smpException);
	}

	/*PROTECTED REGION ID(_LVfTodcvEe-g-_tbVlfW3w_connect) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Actuator::connectData() throw (Smp::IModel::InvalidModelState) {

	try {
		//data connections 

		/*PROTECTED REGION ID(_LVfTodcvEe-g-_tbVlfW3w_connectData_catching) ENABLED START*/
		//add user defined code here
		/*PROTECTED REGION END*/
	}
	catch (simtg::Exception& simtgException) {
		throw simtg::ModelBase::InvalidModelState(_state, simtgException);
	}
	catch (Smp::Exception& smpException) {
		throw simtg::ModelBase::InvalidModelState(_state, smpException);
	}

	/*PROTECTED REGION ID(_LVfTodcvEe-g-_tbVlfW3w_connectData) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Actuator::initDefaultValues() {

	//set init values of variables
	for (int row = 0; row < 4; row++) {
		_in_measuredCurrents[row] = 0.0;
	}
	for (int row = 0; row < 2; row++) {
		_out_actuationAngle[row] = 0.0;
	}
	for (int row = 0; row < 4; row++) {
		_measuredCurrents[row] = 0.0;
	}
	for (int row = 0; row < 3; row++) {
		_cssSunDirections[row] = 0.0;
	}
	for (int row = 0; row < 2; row++) {
		_calculatedPosition[row] = 0.0;
	}
	for (int row = 0; row < 2; row++) {
		_lastPosition[row] = 0.0;
	}
	for (int row = 0; row < 2; row++) {
		_sumPositions[row] = 0.0;
	}
	_coefficientProportional = 0.0;
	_coefficientIntegration = 0.0;
	_coefficientDifferential = 0.0;
	_numSteps = 0;

	initSubModelsDefaultValues();

	/*PROTECTED REGION ID(_LVfTodcvEe-g-_tbVlfW3w_initDefaultValues) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Actuator::initSubModelsDefaultValues() {

	/*PROTECTED REGION ID(_LVfTodcvEe-g-_tbVlfW3w_initSubModelsDefaultValues) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Actuator::initScheduling() {

	std::list<MethodInfo> methods;

	/*PROTECTED REGION ID(_LVfTodcvEe-g-_tbVlfW3w_initScheduling_before_pushback) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/
	try {
		registerMethods(methods);
	}
	catch (simtg::Exception& e) {
		std::cerr << "Exception:" << e.what() << std::endl;
	}

	/*PROTECTED REGION ID(_LVfTodcvEe-g-_tbVlfW3w_initSheduling) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Actuator::callMethod(uint32_t methodId_, BaseType* params_)
		throw (SchedulableObject::BreakPointReached, simtg::Exception) {

	switch (methodId_) {
	/*PROTECTED REGION ID(_LVfTodcvEe-g-_tbVlfW3w_callMethod_switch) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/
	default:
		ModelBase::callMethod(methodId_, params_);
	}

	/*PROTECTED REGION ID(_LVfTodcvEe-g-_tbVlfW3w_callMethod) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Actuator::serializeMembers(simtg::SerializationStream& stream_)
		throw (simtg::SerializationException) {

	/*PROTECTED REGION ID(_LVfTodcvEe-g-_tbVlfW3w_start_serializeMembers) ENABLED START*/
	// add user defined code here
	/*PROTECTED REGION END*/

	stream_.array(&_out_actuationAngle[0], 2);
	stream_.array(&_measuredCurrents[0], 4);
	stream_.array(&_cssSunDirections[0], 3);
	stream_.array(&_calculatedPosition[0], 2);
	stream_.array(&_lastPosition[0], 2);
	stream_.array(&_sumPositions[0], 2);
	stream_.value(_coefficientProportional);
	stream_.value(_coefficientIntegration);
	stream_.value(_coefficientDifferential);
	stream_.value(_numSteps);

	serializeExt(stream_);

	/*PROTECTED REGION ID(_LVfTodcvEe-g-_tbVlfW3w_serializeMembers) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}

/*PROTECTED REGION ID(_LVfTodcvEe-g-_tbVlfW3w_auto_cpp_end_extensionsauto) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/
