/*
 * File AnalogToDigitalConverterBase.cpp
 *
 * Project SatSim
 *
 *
 * Copyright (c) Astrium 2011. All rights reserved.
 *
 */

/*PROTECTED REGION ID(_Nfy0MeCUEe-JhMcKl8Urew_auto_cpp_before_includeauto) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/

#include "AnalogToDigitalConverter.hpp"
#include <simtg/smp/TimeKeeperAdapter.hpp>
#include <simtg/smp/ConnectionService.hpp>
#include <simtg/smp/LoggerMacros.hpp>
#include <simtg/kernel/MethodCallAsyncDataListener.hpp>

using namespace SatSim;

/*PROTECTED REGION ID(_Nfy0MeCUEe-JhMcKl8Urew_auto_cpp_after_includeauto) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/

AnalogToDigitalConverter::AnalogToDigitalConverter(Smp::String8 name_, simtg::NamedObject* parent_, Smp::String8 description_) :
		AsyncModelBase(name_, parent_, description_),
				_in_measuredCurrentPlusY("in_measuredCurrentPlusY", 1, 1, "-", simtg::INPUT, &_data, this, 0)
						, _in_measuredCurrentPlusZ("in_measuredCurrentPlusZ", 1, 1, "-", simtg::INPUT, &_data, this, 0)
						, _in_measuredCurrentMinusY("in_measuredCurrentMinusY", 1, 1, "-", simtg::INPUT, &_data, this, 0)
						, _in_measuredCurrentMinusZ("in_measuredCurrentMinusZ", 1, 1, "-", simtg::INPUT, &_data, this, 0)
						, _out_controlSignal("out_controlSignal", 2, 1, "-", simtg::OUTPUT, &_data, this, 0)
						, _out_mode("out_mode", 1, 1, "-", simtg::OUTPUT, &_data, this, 0)

/*PROTECTED REGION ID(_Nfy0MeCUEe-JhMcKl8Urew_defConst_constructor_init) ENABLED START*/
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

	/*PROTECTED REGION ID(_Nfy0MeCUEe-JhMcKl8Urew_defConst) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
AnalogToDigitalConverter::AnalogToDigitalConverter(Smp::String8 name_, Smp::String8 description_, Smp::IComposite* parent_) :
		AsyncModelBase(name_, description_, parent_),
				_in_measuredCurrentPlusY("in_measuredCurrentPlusY", 1, 1, "-", simtg::INPUT, &_data, this, 0)
						, _in_measuredCurrentPlusZ("in_measuredCurrentPlusZ", 1, 1, "-", simtg::INPUT, &_data, this, 0)
						, _in_measuredCurrentMinusY("in_measuredCurrentMinusY", 1, 1, "-", simtg::INPUT, &_data, this, 0)
						, _in_measuredCurrentMinusZ("in_measuredCurrentMinusZ", 1, 1, "-", simtg::INPUT, &_data, this, 0)
						, _out_controlSignal("out_controlSignal", 2, 1, "-", simtg::OUTPUT, &_data, this, 0)
						, _out_mode("out_mode", 1, 1, "-", simtg::OUTPUT, &_data, this, 0)

/*PROTECTED REGION ID(_Nfy0MeCUEe-JhMcKl8Urew_namedConst_constructor_init) ENABLED START*/
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

	/*PROTECTED REGION ID(_Nfy0MeCUEe-JhMcKl8Urew_namedConst) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
AnalogToDigitalConverter::~AnalogToDigitalConverter() {

	destructor();

	/*PROTECTED REGION ID(_Nfy0MeCUEe-JhMcKl8Urew_defDestr) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void AnalogToDigitalConverter::Publish(Smp::IPublication* publication_) throw (Smp::IModel::InvalidModelState) {

	ModelBase::Publish(publication_);
	try {
		/*PROTECTED REGION ID(_Nfy0MeCUEe-JhMcKl8Urew_publish_catching) ENABLED START*/
		//add user defined code here
		/*PROTECTED REGION END*/
	}
	catch (simtg::Exception& simtgException) {
		throw simtg::ModelBase::InvalidModelState(_state, simtgException);
	}
	catch (Smp::Exception& smpException) {
		throw simtg::ModelBase::InvalidModelState(_state, smpException);
	}

	/*PROTECTED REGION ID(_Nfy0MeCUEe-JhMcKl8Urew_publish) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void AnalogToDigitalConverter::Configure(Smp::Services::ILogger* logger_) throw (Smp::IModel::InvalidModelState) {

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

	/*PROTECTED REGION ID(_Nfy0MeCUEe-JhMcKl8Urew_configure) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void AnalogToDigitalConverter::Connect(Smp::ISimulator* sim_) throw (Smp::IModel::InvalidModelState) {

	ModelBase::Connect(sim_);

	try {
		//data connections 
		connectData();
		//interface connections
		//system interface connections

		/*PROTECTED REGION ID(_Nfy0MeCUEe-JhMcKl8Urew_connect_catching) ENABLED START*/
		//add user defined code here
		/*PROTECTED REGION END*/
	}
	catch (simtg::Exception& simtgException) {
		throw simtg::ModelBase::InvalidModelState(_state, simtgException);
	}
	catch (Smp::Exception& smpException) {
		throw simtg::ModelBase::InvalidModelState(_state, smpException);
	}

	/*PROTECTED REGION ID(_Nfy0MeCUEe-JhMcKl8Urew_connect) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void AnalogToDigitalConverter::connectData() throw (Smp::IModel::InvalidModelState) {

	try {
		//data connections 

		/*PROTECTED REGION ID(_Nfy0MeCUEe-JhMcKl8Urew_connectData_catching) ENABLED START*/
		//add user defined code here
		/*PROTECTED REGION END*/
	}
	catch (simtg::Exception& simtgException) {
		throw simtg::ModelBase::InvalidModelState(_state, simtgException);
	}
	catch (Smp::Exception& smpException) {
		throw simtg::ModelBase::InvalidModelState(_state, smpException);
	}

	/*PROTECTED REGION ID(_Nfy0MeCUEe-JhMcKl8Urew_connectData) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void AnalogToDigitalConverter::initDefaultValues() {

	//set init values of variables
	_in_measuredCurrentPlusY = 0.0;
	_in_measuredCurrentPlusZ = 0.0;
	_in_measuredCurrentMinusY = 0.0;
	_in_measuredCurrentMinusZ = 0.0;
	for (int row = 0; row < 2; row++) {
		_out_controlSignal[row] = 0.0;
	}
	_maxCurrent = 31e3;
	_noiseLevel = 2.3e-4;
	_out_mode = 0;

	initSubModelsDefaultValues();

	/*PROTECTED REGION ID(_Nfy0MeCUEe-JhMcKl8Urew_initDefaultValues) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void AnalogToDigitalConverter::initSubModelsDefaultValues() {

	/*PROTECTED REGION ID(_Nfy0MeCUEe-JhMcKl8Urew_initSubModelsDefaultValues) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void AnalogToDigitalConverter::initScheduling() {

	std::list<MethodInfo> methods;

	/*PROTECTED REGION ID(_Nfy0MeCUEe-JhMcKl8Urew_initScheduling_before_pushback) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/
	try {
		registerMethods(methods);
	}
	catch (simtg::Exception& e) {
		std::cerr << "Exception:" << e.what() << std::endl;
	}

	/*PROTECTED REGION ID(_Nfy0MeCUEe-JhMcKl8Urew_initSheduling) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void AnalogToDigitalConverter::callMethod(uint32_t methodId_, BaseType* params_) throw (SchedulableObject::BreakPointReached, simtg::Exception) {

	preCompute();
	switch (methodId_) {
	/*PROTECTED REGION ID(_Nfy0MeCUEe-JhMcKl8Urew_callMethod_switch) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/
	default:
		ModelBase::callMethod(methodId_, params_);
	}
	postCompute();
	/*PROTECTED REGION ID(_Nfy0MeCUEe-JhMcKl8Urew_callMethod) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void AnalogToDigitalConverter::serializeMembers(simtg::SerializationStream& stream_) throw (simtg::SerializationException) {

	/*PROTECTED REGION ID(_Nfy0MeCUEe-JhMcKl8Urew_start_serializeMembers) ENABLED START*/
	// add user defined code here
	/*PROTECTED REGION END*/

	stream_.value(_maxCurrent);
	stream_.value(_noiseLevel);

	serializeExt(stream_);

	/*PROTECTED REGION ID(_Nfy0MeCUEe-JhMcKl8Urew_serializeMembers) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}

/*PROTECTED REGION ID(_Nfy0MeCUEe-JhMcKl8Urew_auto_cpp_end_extensionsauto) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/
