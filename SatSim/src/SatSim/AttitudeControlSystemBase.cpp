/*
 * File AttitudeControlSystemBase.cpp
 *
 * Project SatSim
 *
 *
 * Copyright (c) Astrium 2011. All rights reserved.
 *
 */

/*PROTECTED REGION ID(_4bXJYeCZEe-JhMcKl8Urew_auto_cpp_before_includeauto) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/

#include "AttitudeControlSystem.hpp"
#include <simtg/smp/TimeKeeperAdapter.hpp>
#include <simtg/smp/ConnectionService.hpp>
#include <simtg/smp/LoggerMacros.hpp>
#include <simtg/kernel/MethodCallAsyncDataListener.hpp>
#include "Controller.hpp"
#include "Actuator.hpp"

using namespace SatSim;

/*PROTECTED REGION ID(_4bXJYeCZEe-JhMcKl8Urew_auto_cpp_after_includeauto) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/

AttitudeControlSystem::AttitudeControlSystem(Smp::String8 name_, simtg::NamedObject* parent_, Smp::String8 description_) :
		AsyncModelBase(name_, parent_, description_),
				_in_controlSignal("in_controlSignal", 2, 1, "-", simtg::INPUT, &_data, this, 0)
						, _out_sunDirection("out_sunDirection", 3, 1, "-", simtg::OUTPUT, &_data, this, 0)
						, _in_sunDirection("in_sunDirection", 3, 1, "-", simtg::INPUT, &_data, this, 0)
						, _in_mode("in_mode", 1, 1, "-", simtg::INPUT, &_data, this, 0)
						, _forceStep("forceStep", 1, 1, "-", simtg::INPUT, &_data, this, 0)

/*PROTECTED REGION ID(_4bXJYeCZEe-JhMcKl8Urew_defConst_constructor_init) ENABLED START*/
//add user defined code here
/*PROTECTED REGION END*/
{

	_Controller = new Controller("Controller", this, "");
	_Actuator = new Actuator("Actuator", this, "");

	_subModelsSequencer.push_back(_Controller);
	_subModelsSequencer.push_back(_Actuator);

	registerData();
	registerParams();
	registerStates();
	registerOthers();
	registerPorts();
	initDefaultValues();
	initScheduling();

	constructor();

	/*PROTECTED REGION ID(_4bXJYeCZEe-JhMcKl8Urew_defConst) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
AttitudeControlSystem::AttitudeControlSystem(Smp::String8 name_, Smp::String8 description_, Smp::IComposite* parent_) :
		AsyncModelBase(name_, description_, parent_),
				_in_controlSignal("in_controlSignal", 2, 1, "-", simtg::INPUT, &_data, this, 0)
						, _out_sunDirection("out_sunDirection", 3, 1, "-", simtg::OUTPUT, &_data, this, 0)
						, _in_sunDirection("in_sunDirection", 3, 1, "-", simtg::INPUT, &_data, this, 0)
						, _in_mode("in_mode", 1, 1, "-", simtg::INPUT, &_data, this, 0)
						, _forceStep("forceStep", 1, 1, "-", simtg::INPUT, &_data, this, 0)

/*PROTECTED REGION ID(_4bXJYeCZEe-JhMcKl8Urew_namedConst_constructor_init) ENABLED START*/
//add user defined code here
/*PROTECTED REGION END*/
{

	_Controller = new Controller("Controller", this, "");
	_Actuator = new Actuator("Actuator", this, "");

	_subModelsSequencer.push_back(_Controller);
	_subModelsSequencer.push_back(_Actuator);

	registerData();
	registerParams();
	registerStates();
	registerOthers();
	registerPorts();
	initDefaultValues();
	initScheduling();

	constructor();

	/*PROTECTED REGION ID(_4bXJYeCZEe-JhMcKl8Urew_namedConst) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
AttitudeControlSystem::~AttitudeControlSystem() {

	delete _Controller;
	delete _Actuator;

	destructor();

	/*PROTECTED REGION ID(_4bXJYeCZEe-JhMcKl8Urew_defDestr) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void AttitudeControlSystem::Publish(Smp::IPublication* publication_) throw (Smp::IModel::InvalidModelState) {

	ModelBase::Publish(publication_);
	try {
		/*PROTECTED REGION ID(_4bXJYeCZEe-JhMcKl8Urew_publish_catching) ENABLED START*/
		//add user defined code here
		/*PROTECTED REGION END*/
	}
	catch (simtg::Exception& simtgException) {
		throw simtg::ModelBase::InvalidModelState(_state, simtgException);
	}
	catch (Smp::Exception& smpException) {
		throw simtg::ModelBase::InvalidModelState(_state, smpException);
	}

	/*PROTECTED REGION ID(_4bXJYeCZEe-JhMcKl8Urew_publish) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void AttitudeControlSystem::Configure(Smp::Services::ILogger* logger_) throw (Smp::IModel::InvalidModelState) {

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

	/*PROTECTED REGION ID(_4bXJYeCZEe-JhMcKl8Urew_configure) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void AttitudeControlSystem::Connect(Smp::ISimulator* sim_) throw (Smp::IModel::InvalidModelState) {

	ModelBase::Connect(sim_);

	try {
		//data connections 
		connectData();
		//interface connections
		//system interface connections

		/*PROTECTED REGION ID(_4bXJYeCZEe-JhMcKl8Urew_connect_catching) ENABLED START*/
		//add user defined code here
		/*PROTECTED REGION END*/
	}
	catch (simtg::Exception& simtgException) {
		throw simtg::ModelBase::InvalidModelState(_state, simtgException);
	}
	catch (Smp::Exception& smpException) {
		throw simtg::ModelBase::InvalidModelState(_state, smpException);
	}

	/*PROTECTED REGION ID(_4bXJYeCZEe-JhMcKl8Urew_connect) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void AttitudeControlSystem::connectData() throw (Smp::IModel::InvalidModelState) {

	try {
		//data connections 
		this->getInput("in_controlSignal").connect(&_Controller->getInput("in_controlSignal"), 0, 2, 0);
		_Controller->getOutput("out_rotationAngles").connect(&_Actuator->getInput("in_rotationAngles"), 0, 2, 0);
		_Actuator->getOutput("out_sunDirection").connect(&this->getOutput("out_sunDirection"), 0, 3, 0);
		this->getInput("in_sunDirection").connect(&_Actuator->getInput("in_sunDirection"), 0, 3, 0);
		this->getInput("in_mode").connect(&_Controller->getInput("in_mode"));
		this->getInput("forceStep").connect(&_Controller->getInput("forceStep"));
		this->getInput("forceStep").connect(&_Actuator->getInput("forceStep"));

		/*PROTECTED REGION ID(_4bXJYeCZEe-JhMcKl8Urew_connectData_catching) ENABLED START*/
		//add user defined code here
		/*PROTECTED REGION END*/
	}
	catch (simtg::Exception& simtgException) {
		throw simtg::ModelBase::InvalidModelState(_state, simtgException);
	}
	catch (Smp::Exception& smpException) {
		throw simtg::ModelBase::InvalidModelState(_state, smpException);
	}

	/*PROTECTED REGION ID(_4bXJYeCZEe-JhMcKl8Urew_connectData) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void AttitudeControlSystem::initDefaultValues() {

	//set init values of variables
	for (int row = 0; row < 2; row++) {
		_in_controlSignal[row] = 0.0;
	}
	for (int row = 0; row < 3; row++) {
		_out_sunDirection[row] = 0.0;
	}
	for (int row = 0; row < 3; row++) {
		_in_sunDirection[row] = 0.0;
	}
	_in_mode = 0;
	_forceStep = 0;

	initSubModelsDefaultValues();

	/*PROTECTED REGION ID(_4bXJYeCZEe-JhMcKl8Urew_initDefaultValues) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void AttitudeControlSystem::initSubModelsDefaultValues() {

	/*PROTECTED REGION ID(_4bXJYeCZEe-JhMcKl8Urew_initSubModelsDefaultValues) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void AttitudeControlSystem::initScheduling() {

	std::list<MethodInfo> methods;

	/*PROTECTED REGION ID(_4bXJYeCZEe-JhMcKl8Urew_initScheduling_before_pushback) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/
	try {
		registerMethods(methods);
	}
	catch (simtg::Exception& e) {
		std::cerr << "Exception:" << e.what() << std::endl;
	}

	/*PROTECTED REGION ID(_4bXJYeCZEe-JhMcKl8Urew_initSheduling) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void AttitudeControlSystem::callMethod(uint32_t methodId_, BaseType* params_) throw (SchedulableObject::BreakPointReached, simtg::Exception) {

	preCompute();
	switch (methodId_) {
	/*PROTECTED REGION ID(_4bXJYeCZEe-JhMcKl8Urew_callMethod_switch) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/
	default:
		ModelBase::callMethod(methodId_, params_);
	}
	postCompute();
	/*PROTECTED REGION ID(_4bXJYeCZEe-JhMcKl8Urew_callMethod) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void AttitudeControlSystem::serializeMembers(simtg::SerializationStream& stream_) throw (simtg::SerializationException) {

	/*PROTECTED REGION ID(_4bXJYeCZEe-JhMcKl8Urew_start_serializeMembers) ENABLED START*/
	// add user defined code here
	/*PROTECTED REGION END*/

	_Controller->serialize(stream_);
	_Actuator->serialize(stream_);

	serializeExt(stream_);

	/*PROTECTED REGION ID(_4bXJYeCZEe-JhMcKl8Urew_serializeMembers) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}

/*PROTECTED REGION ID(_4bXJYeCZEe-JhMcKl8Urew_auto_cpp_end_extensionsauto) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/
