/*
 * File OrientationBase.cpp
 *
 * Project SatSim
 *
 *
 * Copyright (c) Astrium 2011. All rights reserved.
 *
 */

/*PROTECTED REGION ID(_5y_NIc3hEe-dEfVxFIbKWQ_auto_cpp_before_includeauto) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/

#include "Orientation.hpp"
#include <simtg/smp/TimeKeeperAdapter.hpp>
#include <simtg/smp/ConnectionService.hpp>
#include <simtg/smp/LoggerMacros.hpp>
#include <simtg/kernel/MethodCallAsyncDataListener.hpp>

using namespace SatSim;

/*PROTECTED REGION ID(_5y_NIc3hEe-dEfVxFIbKWQ_auto_cpp_after_includeauto) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/

Orientation::Orientation(Smp::String8 name_, simtg::NamedObject* parent_, Smp::String8 description_) :
		AsyncModelBase(name_, parent_, description_)

/*PROTECTED REGION ID(_5y_NIc3hEe-dEfVxFIbKWQ_defConst_constructor_init) ENABLED START*/
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

	/*PROTECTED REGION ID(_5y_NIc3hEe-dEfVxFIbKWQ_defConst) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
Orientation::Orientation(Smp::String8 name_, Smp::String8 description_, Smp::IComposite* parent_) :
		AsyncModelBase(name_, description_, parent_)

/*PROTECTED REGION ID(_5y_NIc3hEe-dEfVxFIbKWQ_namedConst_constructor_init) ENABLED START*/
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

	/*PROTECTED REGION ID(_5y_NIc3hEe-dEfVxFIbKWQ_namedConst) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
Orientation::~Orientation() {

	destructor();

	/*PROTECTED REGION ID(_5y_NIc3hEe-dEfVxFIbKWQ_defDestr) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Orientation::Publish(Smp::IPublication* publication_) throw (Smp::IModel::InvalidModelState) {

	ModelBase::Publish(publication_);
	try {
		/*PROTECTED REGION ID(_5y_NIc3hEe-dEfVxFIbKWQ_publish_catching) ENABLED START*/
		//add user defined code here
		/*PROTECTED REGION END*/
	}
	catch (simtg::Exception& simtgException) {
		throw simtg::ModelBase::InvalidModelState(_state, simtgException);
	}
	catch (Smp::Exception& smpException) {
		throw simtg::ModelBase::InvalidModelState(_state, smpException);
	}

	/*PROTECTED REGION ID(_5y_NIc3hEe-dEfVxFIbKWQ_publish) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Orientation::Configure(Smp::Services::ILogger* logger_) throw (Smp::IModel::InvalidModelState) {

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

	/*PROTECTED REGION ID(_5y_NIc3hEe-dEfVxFIbKWQ_configure) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Orientation::Connect(Smp::ISimulator* sim_) throw (Smp::IModel::InvalidModelState) {

	ModelBase::Connect(sim_);

	try {
		//data connections 
		connectData();
		//interface connections
		//system interface connections

		/*PROTECTED REGION ID(_5y_NIc3hEe-dEfVxFIbKWQ_connect_catching) ENABLED START*/
		//add user defined code here
		/*PROTECTED REGION END*/
	}
	catch (simtg::Exception& simtgException) {
		throw simtg::ModelBase::InvalidModelState(_state, simtgException);
	}
	catch (Smp::Exception& smpException) {
		throw simtg::ModelBase::InvalidModelState(_state, smpException);
	}

	/*PROTECTED REGION ID(_5y_NIc3hEe-dEfVxFIbKWQ_connect) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Orientation::connectData() throw (Smp::IModel::InvalidModelState) {

	try {
		//data connections 

		/*PROTECTED REGION ID(_5y_NIc3hEe-dEfVxFIbKWQ_connectData_catching) ENABLED START*/
		//add user defined code here
		/*PROTECTED REGION END*/
	}
	catch (simtg::Exception& simtgException) {
		throw simtg::ModelBase::InvalidModelState(_state, simtgException);
	}
	catch (Smp::Exception& smpException) {
		throw simtg::ModelBase::InvalidModelState(_state, smpException);
	}

	/*PROTECTED REGION ID(_5y_NIc3hEe-dEfVxFIbKWQ_connectData) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Orientation::initDefaultValues() {

	//set init values of variables
	_in_satSunDirection[0] = 1.0;
	_in_satSunDirection[1] = 0.0;
	_in_satSunDirection[2] = 0.0;
	_out_cssSunDirection[0] = 1.0;
	_out_cssSunDirection[1] = 0.0;
	_out_cssSunDirection[2] = 0.0;
	_sat2cssFrame[0][0] = 0;
	_sat2cssFrame[0][1] = 0;
	_sat2cssFrame[0][2] = -1;
	_sat2cssFrame[1][0] = 0;
	_sat2cssFrame[1][1] = 1;
	_sat2cssFrame[1][2] = 0;
	_sat2cssFrame[2][0] = 1;
	_sat2cssFrame[2][1] = 0;
	_sat2cssFrame[2][2] = 0;
	_css2satFrame[0][0] = 0;
	_css2satFrame[0][1] = 0;
	_css2satFrame[0][2] = 1;
	_css2satFrame[1][0] = 0;
	_css2satFrame[1][1] = 1;
	_css2satFrame[1][2] = 0;
	_css2satFrame[2][0] = -1;
	_css2satFrame[2][1] = 0;
	_css2satFrame[2][2] = 0;
	_isInEclipse = false;
	_sunAzimuth = 0.0;
	_sunElevation = 0.0;
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			_rotation[row][col] = 0.0;
		}
	}

	initSubModelsDefaultValues();

	/*PROTECTED REGION ID(_5y_NIc3hEe-dEfVxFIbKWQ_initDefaultValues) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Orientation::initSubModelsDefaultValues() {

	/*PROTECTED REGION ID(_5y_NIc3hEe-dEfVxFIbKWQ_initSubModelsDefaultValues) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Orientation::initScheduling() {

	std::list<MethodInfo> methods;

	/*PROTECTED REGION ID(_5y_NIc3hEe-dEfVxFIbKWQ_initScheduling_before_pushback) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/
	try {
		registerMethods(methods);
	}
	catch (simtg::Exception& e) {
		std::cerr << "Exception:" << e.what() << std::endl;
	}

	/*PROTECTED REGION ID(_5y_NIc3hEe-dEfVxFIbKWQ_initSheduling) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Orientation::callMethod(uint32_t methodId_, BaseType* params_) throw (SchedulableObject::BreakPointReached, simtg::Exception) {

	preCompute();
	switch (methodId_) {
	/*PROTECTED REGION ID(_5y_NIc3hEe-dEfVxFIbKWQ_callMethod_switch) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/
	default:
		ModelBase::callMethod(methodId_, params_);
	}
	postCompute();
	/*PROTECTED REGION ID(_5y_NIc3hEe-dEfVxFIbKWQ_callMethod) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Orientation::serializeMembers(simtg::SerializationStream& stream_) throw (simtg::SerializationException) {

	/*PROTECTED REGION ID(_5y_NIc3hEe-dEfVxFIbKWQ_start_serializeMembers) ENABLED START*/
	// add user defined code here
	/*PROTECTED REGION END*/

	stream_.array(&_in_satSunDirection[0], 3);
	stream_.array(&_out_cssSunDirection[0], 3);
	stream_.array(&_sat2cssFrame[0][0], 9);
	stream_.array(&_css2satFrame[0][0], 9);
	stream_.value(_isInEclipse);
	stream_.value(_sunAzimuth);
	stream_.value(_sunElevation);
	stream_.array(&_rotation[0][0], 9);

	serializeExt(stream_);

	/*PROTECTED REGION ID(_5y_NIc3hEe-dEfVxFIbKWQ_serializeMembers) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}

/*PROTECTED REGION ID(_5y_NIc3hEe-dEfVxFIbKWQ_auto_cpp_end_extensionsauto) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/
