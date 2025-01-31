/*
 * File BaffleBase.cpp
 *
 * Project SatSim
 *
 *
 * Copyright (c) Astrium 2011. All rights reserved.
 *
 */

/*PROTECTED REGION ID(_ME22kN_sEe-b8OOJcDFPdw_auto_cpp_before_includeauto) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/

#include "Baffle.hpp"
#include <simtg/smp/TimeKeeperAdapter.hpp>
#include <simtg/smp/ConnectionService.hpp>
#include <simtg/smp/LoggerMacros.hpp>
#include <simtg/kernel/MethodCallAsyncDataListener.hpp>

using namespace SatSim;

/*PROTECTED REGION ID(_ME22kN_sEe-b8OOJcDFPdw_auto_cpp_after_includeauto) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/

Baffle::Baffle(Smp::String8 name_, simtg::NamedObject* parent_, Smp::String8 description_) :
		AsyncModelBase(name_, parent_, description_),
				_in_sunAz("in_sunAz", 1, 1, "-", simtg::INPUT, &_data, this, 0)
						, _in_sunEl("in_sunEl", 1, 1, "-", simtg::INPUT, &_data, this, 0)
						, _baffleCoefficients("baffleCoefficients", 4, 1, "-", simtg::OUTPUT, &_statesContainer, this, 0)
						, _sector("sector", 1, 1, "-", simtg::OUTPUT, &_statesContainer, this, 0)
						, _out_baffleCoefficientPlusY("out_baffleCoefficientPlusY", 1, 1, "-", simtg::OUTPUT, &_data, this, 0)
						, _out_baffleCoefficientPlusZ("out_baffleCoefficientPlusZ", 1, 1, "-", simtg::OUTPUT, &_data, this, 0)
						, _out_baffleCoefficientMinusY("out_baffleCoefficientMinusY", 1, 1, "-", simtg::OUTPUT, &_data, this, 0)
						, _out_baffleCoefficientMinusZ("out_baffleCoefficientMinusZ", 1, 1, "-", simtg::OUTPUT, &_data, this, 0)

/*PROTECTED REGION ID(_ME22kN_sEe-b8OOJcDFPdw_defConst_constructor_init) ENABLED START*/
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

	/*PROTECTED REGION ID(_ME22kN_sEe-b8OOJcDFPdw_defConst) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
Baffle::Baffle(Smp::String8 name_, Smp::String8 description_, Smp::IComposite* parent_) :
		AsyncModelBase(name_, description_, parent_),
				_in_sunAz("in_sunAz", 1, 1, "-", simtg::INPUT, &_data, this, 0)
						, _in_sunEl("in_sunEl", 1, 1, "-", simtg::INPUT, &_data, this, 0)
						, _baffleCoefficients("baffleCoefficients", 4, 1, "-", simtg::OUTPUT, &_statesContainer, this, 0)
						, _sector("sector", 1, 1, "-", simtg::OUTPUT, &_statesContainer, this, 0)
						, _out_baffleCoefficientPlusY("out_baffleCoefficientPlusY", 1, 1, "-", simtg::OUTPUT, &_data, this, 0)
						, _out_baffleCoefficientPlusZ("out_baffleCoefficientPlusZ", 1, 1, "-", simtg::OUTPUT, &_data, this, 0)
						, _out_baffleCoefficientMinusY("out_baffleCoefficientMinusY", 1, 1, "-", simtg::OUTPUT, &_data, this, 0)
						, _out_baffleCoefficientMinusZ("out_baffleCoefficientMinusZ", 1, 1, "-", simtg::OUTPUT, &_data, this, 0)

/*PROTECTED REGION ID(_ME22kN_sEe-b8OOJcDFPdw_namedConst_constructor_init) ENABLED START*/
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

	/*PROTECTED REGION ID(_ME22kN_sEe-b8OOJcDFPdw_namedConst) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
Baffle::~Baffle() {

	destructor();

	/*PROTECTED REGION ID(_ME22kN_sEe-b8OOJcDFPdw_defDestr) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Baffle::Publish(Smp::IPublication* publication_) throw (Smp::IModel::InvalidModelState) {

	ModelBase::Publish(publication_);
	try {
		/*PROTECTED REGION ID(_ME22kN_sEe-b8OOJcDFPdw_publish_catching) ENABLED START*/
		//add user defined code here
		/*PROTECTED REGION END*/
	}
	catch (simtg::Exception& simtgException) {
		throw simtg::ModelBase::InvalidModelState(_state, simtgException);
	}
	catch (Smp::Exception& smpException) {
		throw simtg::ModelBase::InvalidModelState(_state, smpException);
	}

	/*PROTECTED REGION ID(_ME22kN_sEe-b8OOJcDFPdw_publish) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Baffle::Configure(Smp::Services::ILogger* logger_) throw (Smp::IModel::InvalidModelState) {

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

	/*PROTECTED REGION ID(_ME22kN_sEe-b8OOJcDFPdw_configure) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Baffle::Connect(Smp::ISimulator* sim_) throw (Smp::IModel::InvalidModelState) {

	ModelBase::Connect(sim_);

	try {
		//data connections 
		connectData();
		//interface connections
		//system interface connections

		/*PROTECTED REGION ID(_ME22kN_sEe-b8OOJcDFPdw_connect_catching) ENABLED START*/
		//add user defined code here
		/*PROTECTED REGION END*/
	}
	catch (simtg::Exception& simtgException) {
		throw simtg::ModelBase::InvalidModelState(_state, simtgException);
	}
	catch (Smp::Exception& smpException) {
		throw simtg::ModelBase::InvalidModelState(_state, smpException);
	}

	/*PROTECTED REGION ID(_ME22kN_sEe-b8OOJcDFPdw_connect) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Baffle::connectData() throw (Smp::IModel::InvalidModelState) {

	try {
		//data connections 

		/*PROTECTED REGION ID(_ME22kN_sEe-b8OOJcDFPdw_connectData_catching) ENABLED START*/
		//add user defined code here
		/*PROTECTED REGION END*/
	}
	catch (simtg::Exception& simtgException) {
		throw simtg::ModelBase::InvalidModelState(_state, simtgException);
	}
	catch (Smp::Exception& smpException) {
		throw simtg::ModelBase::InvalidModelState(_state, smpException);
	}

	/*PROTECTED REGION ID(_ME22kN_sEe-b8OOJcDFPdw_connectData) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Baffle::initDefaultValues() {

	//set init values of variables
	_in_sunAz = 0.0;
	for (int row = 0; row < 2; row++) {
		for (int col = 0; col < 40; col++) {
			_yMinusFov[row][col] = 0.0;
		}
	}
	for (int row = 0; row < 2; row++) {
		for (int col = 0; col < 40; col++) {
			_yPlusFov[row][col] = 0.0;
		}
	}
	for (int row = 0; row < 2; row++) {
		for (int col = 0; col < 40; col++) {
			_zMinusFov[row][col] = 0.0;
		}
	}
	for (int row = 0; row < 2; row++) {
		for (int col = 0; col < 40; col++) {
			_zPlusFov[row][col] = 0.0;
		}
	}
	_in_sunEl = 0.0;
	for (int row = 0; row < 4; row++) {
		_baffleCoefficients[row] = 0.0;
	}
	_sector = 0;
	_out_baffleCoefficientPlusY = 0.0;
	_out_baffleCoefficientPlusZ = 0.0;
	_out_baffleCoefficientMinusY = 0.0;
	_out_baffleCoefficientMinusZ = 0.0;

	initSubModelsDefaultValues();

	/*PROTECTED REGION ID(_ME22kN_sEe-b8OOJcDFPdw_initDefaultValues) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Baffle::initSubModelsDefaultValues() {

	/*PROTECTED REGION ID(_ME22kN_sEe-b8OOJcDFPdw_initSubModelsDefaultValues) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Baffle::initScheduling() {

	std::list<MethodInfo> methods;

	/*PROTECTED REGION ID(_ME22kN_sEe-b8OOJcDFPdw_initScheduling_before_pushback) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/
	try {
		registerMethods(methods);
	}
	catch (simtg::Exception& e) {
		std::cerr << "Exception:" << e.what() << std::endl;
	}

	/*PROTECTED REGION ID(_ME22kN_sEe-b8OOJcDFPdw_initSheduling) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Baffle::callMethod(uint32_t methodId_, BaseType* params_) throw (SchedulableObject::BreakPointReached, simtg::Exception) {

	preCompute();
	switch (methodId_) {
	/*PROTECTED REGION ID(_ME22kN_sEe-b8OOJcDFPdw_callMethod_switch) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/
	default:
		ModelBase::callMethod(methodId_, params_);
	}
	postCompute();
	/*PROTECTED REGION ID(_ME22kN_sEe-b8OOJcDFPdw_callMethod) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Baffle::serializeMembers(simtg::SerializationStream& stream_) throw (simtg::SerializationException) {

	/*PROTECTED REGION ID(_ME22kN_sEe-b8OOJcDFPdw_start_serializeMembers) ENABLED START*/
	// add user defined code here
	/*PROTECTED REGION END*/

	stream_.array(&_yMinusFov[0][0], 80);
	stream_.array(&_yPlusFov[0][0], 80);
	stream_.array(&_zMinusFov[0][0], 80);
	stream_.array(&_zPlusFov[0][0], 80);

	serializeExt(stream_);

	/*PROTECTED REGION ID(_ME22kN_sEe-b8OOJcDFPdw_serializeMembers) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}

/*PROTECTED REGION ID(_ME22kN_sEe-b8OOJcDFPdw_auto_cpp_end_extensionsauto) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/
