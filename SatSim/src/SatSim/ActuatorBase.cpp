/*
 * File ActuatorBase.cpp
 *
 * Project SatSim
 *
 *
 * Copyright (c) Astrium 2011. All rights reserved.
 *
 */

/*PROTECTED REGION ID(_rn_dMeCcEe-JhMcKl8Urew_auto_cpp_before_includeauto) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/

#include "Actuator.hpp"
#include <simtg/smp/TimeKeeperAdapter.hpp>
#include <simtg/smp/ConnectionService.hpp>
#include <simtg/smp/LoggerMacros.hpp>
#include <simtg/kernel/MethodCallAsyncDataListener.hpp>

using namespace SatSim;

/*PROTECTED REGION ID(_rn_dMeCcEe-JhMcKl8Urew_auto_cpp_after_includeauto) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/

Actuator::Actuator(Smp::String8 name_, simtg::NamedObject* parent_, Smp::String8 description_) :
		AsyncModelBase(name_, parent_, description_),
				_out_sunDirection("out_sunDirection", 3, 1, "-", simtg::OUTPUT, &_data, this, 0)
						, _in_rotationAngles("in_rotationAngles", 2, 1, "-", simtg::INPUT, &_data, this, 0)
						, _in_sunDirection("in_sunDirection", 3, 1, "-", simtg::INPUT, &_data, this, 0)
						, _rotX("rotX", 3, 3, "-", simtg::OUTPUT, &_statesContainer, this, 0)
						, _rotY("rotY", 3, 3, "-", simtg::OUTPUT, &_statesContainer, this, 0)
						, _sunDirectionRotY("sunDirectionRotY", 3, 1, "-", simtg::OUTPUT, &_statesContainer, this, 0)
						, _sunDirectionRotX("sunDirectionRotX", 3, 1, "-", simtg::OUTPUT, &_statesContainer, this, 0)
						, _qPosOldArr("qPosOldArr", 4, 1, "-", simtg::OUTPUT, &_statesContainer, this, 0)
						, _qPosNewArr("qPosNewArr", 4, 1, "-", simtg::OUTPUT, &_statesContainer, this, 0)
						, _qRotArr("qRotArr", 4, 1, "-", simtg::OUTPUT, &_statesContainer, this, 0)
						, _qRotStarArr("qRotStarArr", 4, 1, "-", simtg::OUTPUT, &_statesContainer, this, 0)
						, _angle("angle", 1, 1, "-", simtg::OUTPUT, &_statesContainer, this, 0)
						, _axis("axis", 3, 1, "-", simtg::OUTPUT, &_statesContainer, this, 0)
						, _forceStep("forceStep", 1, 1, "-", simtg::INPUT, &_data, this, 0)

/*PROTECTED REGION ID(_rn_dMeCcEe-JhMcKl8Urew_defConst_constructor_init) ENABLED START*/
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

	/*PROTECTED REGION ID(_rn_dMeCcEe-JhMcKl8Urew_defConst) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
Actuator::Actuator(Smp::String8 name_, Smp::String8 description_, Smp::IComposite* parent_) :
		AsyncModelBase(name_, description_, parent_),
				_out_sunDirection("out_sunDirection", 3, 1, "-", simtg::OUTPUT, &_data, this, 0)
						, _in_rotationAngles("in_rotationAngles", 2, 1, "-", simtg::INPUT, &_data, this, 0)
						, _in_sunDirection("in_sunDirection", 3, 1, "-", simtg::INPUT, &_data, this, 0)
						, _rotX("rotX", 3, 3, "-", simtg::OUTPUT, &_statesContainer, this, 0)
						, _rotY("rotY", 3, 3, "-", simtg::OUTPUT, &_statesContainer, this, 0)
						, _sunDirectionRotY("sunDirectionRotY", 3, 1, "-", simtg::OUTPUT, &_statesContainer, this, 0)
						, _sunDirectionRotX("sunDirectionRotX", 3, 1, "-", simtg::OUTPUT, &_statesContainer, this, 0)
						, _qPosOldArr("qPosOldArr", 4, 1, "-", simtg::OUTPUT, &_statesContainer, this, 0)
						, _qPosNewArr("qPosNewArr", 4, 1, "-", simtg::OUTPUT, &_statesContainer, this, 0)
						, _qRotArr("qRotArr", 4, 1, "-", simtg::OUTPUT, &_statesContainer, this, 0)
						, _qRotStarArr("qRotStarArr", 4, 1, "-", simtg::OUTPUT, &_statesContainer, this, 0)
						, _angle("angle", 1, 1, "-", simtg::OUTPUT, &_statesContainer, this, 0)
						, _axis("axis", 3, 1, "-", simtg::OUTPUT, &_statesContainer, this, 0)
						, _forceStep("forceStep", 1, 1, "-", simtg::INPUT, &_data, this, 0)

/*PROTECTED REGION ID(_rn_dMeCcEe-JhMcKl8Urew_namedConst_constructor_init) ENABLED START*/
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

	/*PROTECTED REGION ID(_rn_dMeCcEe-JhMcKl8Urew_namedConst) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
Actuator::~Actuator() {

	destructor();

	/*PROTECTED REGION ID(_rn_dMeCcEe-JhMcKl8Urew_defDestr) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Actuator::Publish(Smp::IPublication* publication_) throw (Smp::IModel::InvalidModelState) {

	ModelBase::Publish(publication_);
	try {
		/*PROTECTED REGION ID(_rn_dMeCcEe-JhMcKl8Urew_publish_catching) ENABLED START*/
		//add user defined code here
		/*PROTECTED REGION END*/
	}
	catch (simtg::Exception& simtgException) {
		throw simtg::ModelBase::InvalidModelState(_state, simtgException);
	}
	catch (Smp::Exception& smpException) {
		throw simtg::ModelBase::InvalidModelState(_state, smpException);
	}

	/*PROTECTED REGION ID(_rn_dMeCcEe-JhMcKl8Urew_publish) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Actuator::Configure(Smp::Services::ILogger* logger_) throw (Smp::IModel::InvalidModelState) {

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

	/*PROTECTED REGION ID(_rn_dMeCcEe-JhMcKl8Urew_configure) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Actuator::Connect(Smp::ISimulator* sim_) throw (Smp::IModel::InvalidModelState) {

	ModelBase::Connect(sim_);

	try {
		//data connections 
		connectData();
		//interface connections
		//system interface connections

		/*PROTECTED REGION ID(_rn_dMeCcEe-JhMcKl8Urew_connect_catching) ENABLED START*/
		//add user defined code here
		/*PROTECTED REGION END*/
	}
	catch (simtg::Exception& simtgException) {
		throw simtg::ModelBase::InvalidModelState(_state, simtgException);
	}
	catch (Smp::Exception& smpException) {
		throw simtg::ModelBase::InvalidModelState(_state, smpException);
	}

	/*PROTECTED REGION ID(_rn_dMeCcEe-JhMcKl8Urew_connect) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Actuator::connectData() throw (Smp::IModel::InvalidModelState) {

	try {
		//data connections 

		/*PROTECTED REGION ID(_rn_dMeCcEe-JhMcKl8Urew_connectData_catching) ENABLED START*/
		//add user defined code here
		/*PROTECTED REGION END*/
	}
	catch (simtg::Exception& simtgException) {
		throw simtg::ModelBase::InvalidModelState(_state, simtgException);
	}
	catch (Smp::Exception& smpException) {
		throw simtg::ModelBase::InvalidModelState(_state, smpException);
	}

	/*PROTECTED REGION ID(_rn_dMeCcEe-JhMcKl8Urew_connectData) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Actuator::initDefaultValues() {

	//set init values of variables
	for (int row = 0; row < 3; row++) {
		_out_sunDirection[row] = 0.0;
	}
	for (int row = 0; row < 2; row++) {
		_in_rotationAngles[row] = 0.0;
	}
	for (int row = 0; row < 3; row++) {
		_in_sunDirection[row] = 0.0;
	}
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			_rotX.at(row, col) = 0.0;
		}
	}
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			_rotY.at(row, col) = 0.0;
		}
	}
	for (int row = 0; row < 3; row++) {
		_sunDirectionRotY[row] = 0.0;
	}
	for (int row = 0; row < 3; row++) {
		_sunDirectionRotX[row] = 0.0;
	}
	for (int row = 0; row < 4; row++) {
		_qPosOldArr[row] = 0.0;
	}
	for (int row = 0; row < 4; row++) {
		_qPosNewArr[row] = 0.0;
	}
	for (int row = 0; row < 4; row++) {
		_qRotArr[row] = 0.0;
	}
	for (int row = 0; row < 4; row++) {
		_qRotStarArr[row] = 0.0;
	}
	_maxRotationAngle = 10.0;
	_angle = 0.0;
	for (int row = 0; row < 3; row++) {
		_axis[row] = 0.0;
	}
	_forceStep = 0;

	initSubModelsDefaultValues();

	/*PROTECTED REGION ID(_rn_dMeCcEe-JhMcKl8Urew_initDefaultValues) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Actuator::initSubModelsDefaultValues() {

	/*PROTECTED REGION ID(_rn_dMeCcEe-JhMcKl8Urew_initSubModelsDefaultValues) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Actuator::initScheduling() {

	std::list<MethodInfo> methods;

	/*PROTECTED REGION ID(_rn_dMeCcEe-JhMcKl8Urew_initScheduling_before_pushback) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/
	try {
		registerMethods(methods);
	}
	catch (simtg::Exception& e) {
		std::cerr << "Exception:" << e.what() << std::endl;
	}

	/*PROTECTED REGION ID(_rn_dMeCcEe-JhMcKl8Urew_initSheduling) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Actuator::callMethod(uint32_t methodId_, BaseType* params_) throw (SchedulableObject::BreakPointReached, simtg::Exception) {

	preCompute();
	switch (methodId_) {
	/*PROTECTED REGION ID(_rn_dMeCcEe-JhMcKl8Urew_callMethod_switch) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/
	default:
		ModelBase::callMethod(methodId_, params_);
	}
	postCompute();
	/*PROTECTED REGION ID(_rn_dMeCcEe-JhMcKl8Urew_callMethod) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Actuator::serializeMembers(simtg::SerializationStream& stream_) throw (simtg::SerializationException) {

	/*PROTECTED REGION ID(_rn_dMeCcEe-JhMcKl8Urew_start_serializeMembers) ENABLED START*/
	// add user defined code here
	/*PROTECTED REGION END*/

	stream_.value(_maxRotationAngle);

	serializeExt(stream_);

	/*PROTECTED REGION ID(_rn_dMeCcEe-JhMcKl8Urew_serializeMembers) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}

/*PROTECTED REGION ID(_rn_dMeCcEe-JhMcKl8Urew_auto_cpp_end_extensionsauto) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/
