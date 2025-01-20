/*
 * File SunSensorBase.cpp
 *
 * Project SatSim
 *
 *
 * Copyright (c) Astrium 2011. All rights reserved.
 *
 */

/*PROTECTED REGION ID(_Qlo1Yb1WEe-zAc57ptwKlg_auto_cpp_before_includeauto) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/

#include "SunSensor.hpp"
#include <simtg/smp/TimeKeeperAdapter.hpp>
#include <simtg/smp/ConnectionService.hpp>
#include <simtg/smp/LoggerMacros.hpp>
#include <simtg/kernel/MethodCallAsyncDataListener.hpp>
#include "Cell.hpp"
#include "Baffle.hpp"

using namespace SatSim;

/*PROTECTED REGION ID(_Qlo1Yb1WEe-zAc57ptwKlg_auto_cpp_after_includeauto) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/

SunSensor::SunSensor(Smp::String8 name_, simtg::NamedObject* parent_,
		Smp::String8 description_) :
		AsyncModelBase(name_, parent_, description_),
				_in_sunDirection("in_sunDirection", 3, 1, "-", simtg::INPUT, &_data, this, 0)
						, _out_measuredCurrents("out_measuredCurrents", 4, 1, "-", simtg::OUTPUT, &_data, this, 0)
						, _in_sunAz("in_sunAz", 1, 1, "-", simtg::INPUT, &_data, this, 0)
						, _in_sunEl("in_sunEl", 1, 1, "-", simtg::INPUT, &_data, this, 0)
						, _out_test("out_test", 40, 1, "-", simtg::OUTPUT, &_data, this, 0)

/*PROTECTED REGION ID(_Qlo1Yb1WEe-zAc57ptwKlg_defConst_constructor_init) ENABLED START*/
//add user defined code here
/*PROTECTED REGION END*/
{

	_Cell_0 = new Cell("Cell_0", this, "");
	_Cell_1 = new Cell("Cell_1", this, "");
	_Cell_2 = new Cell("Cell_2", this, "");
	_Cell_3 = new Cell("Cell_3", this, "");
	_Baffle = new Baffle("Baffle", this, "");

	_subModelsSequencer.push_back(_Cell_1);
	_subModelsSequencer.push_back(_Cell_2);
	_subModelsSequencer.push_back(_Cell_0);
	_subModelsSequencer.push_back(_Cell_3);
	_subModelsSequencer.push_back(_Baffle);

	registerData();
	registerParams();
	registerStates();
	registerOthers();
	registerPorts();
	initDefaultValues();
	initScheduling();

	constructor();

	/*PROTECTED REGION ID(_Qlo1Yb1WEe-zAc57ptwKlg_defConst) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
SunSensor::SunSensor(Smp::String8 name_, Smp::String8 description_,
		Smp::IComposite* parent_) :
		AsyncModelBase(name_, description_, parent_),
				_in_sunDirection("in_sunDirection", 3, 1, "-", simtg::INPUT, &_data, this, 0)
						, _out_measuredCurrents("out_measuredCurrents", 4, 1, "-", simtg::OUTPUT, &_data, this, 0)
						, _in_sunAz("in_sunAz", 1, 1, "-", simtg::INPUT, &_data, this, 0)
						, _in_sunEl("in_sunEl", 1, 1, "-", simtg::INPUT, &_data, this, 0)
						, _out_test("out_test", 40, 1, "-", simtg::OUTPUT, &_data, this, 0)

/*PROTECTED REGION ID(_Qlo1Yb1WEe-zAc57ptwKlg_namedConst_constructor_init) ENABLED START*/
//add user defined code here
/*PROTECTED REGION END*/
{

	_Cell_0 = new Cell("Cell_0", this, "");
	_Cell_1 = new Cell("Cell_1", this, "");
	_Cell_2 = new Cell("Cell_2", this, "");
	_Cell_3 = new Cell("Cell_3", this, "");
	_Baffle = new Baffle("Baffle", this, "");

	_subModelsSequencer.push_back(_Cell_1);
	_subModelsSequencer.push_back(_Cell_2);
	_subModelsSequencer.push_back(_Cell_0);
	_subModelsSequencer.push_back(_Cell_3);
	_subModelsSequencer.push_back(_Baffle);

	registerData();
	registerParams();
	registerStates();
	registerOthers();
	registerPorts();
	initDefaultValues();
	initScheduling();

	constructor();

	/*PROTECTED REGION ID(_Qlo1Yb1WEe-zAc57ptwKlg_namedConst) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
SunSensor::~SunSensor() {

	delete _Cell_0;
	delete _Cell_1;
	delete _Cell_2;
	delete _Cell_3;
	delete _Baffle;

	destructor();

	/*PROTECTED REGION ID(_Qlo1Yb1WEe-zAc57ptwKlg_defDestr) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void SunSensor::Publish(Smp::IPublication* publication_)
		throw (Smp::IModel::InvalidModelState) {

	ModelBase::Publish(publication_);
	try {
		/*PROTECTED REGION ID(_Qlo1Yb1WEe-zAc57ptwKlg_publish_catching) ENABLED START*/
		//add user defined code here
		/*PROTECTED REGION END*/
	}
	catch (simtg::Exception& simtgException) {
		throw simtg::ModelBase::InvalidModelState(_state, simtgException);
	}
	catch (Smp::Exception& smpException) {
		throw simtg::ModelBase::InvalidModelState(_state, smpException);
	}

	/*PROTECTED REGION ID(_Qlo1Yb1WEe-zAc57ptwKlg_publish) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void SunSensor::Configure(Smp::Services::ILogger* logger_)
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

	/*PROTECTED REGION ID(_Qlo1Yb1WEe-zAc57ptwKlg_configure) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void SunSensor::Connect(Smp::ISimulator* sim_)
		throw (Smp::IModel::InvalidModelState) {

	ModelBase::Connect(sim_);

	try {
		//data connections 
		connectData();
		//interface connections
		//system interface connections

		/*PROTECTED REGION ID(_Qlo1Yb1WEe-zAc57ptwKlg_connect_catching) ENABLED START*/
		//add user defined code here
		/*PROTECTED REGION END*/
	}
	catch (simtg::Exception& simtgException) {
		throw simtg::ModelBase::InvalidModelState(_state, simtgException);
	}
	catch (Smp::Exception& smpException) {
		throw simtg::ModelBase::InvalidModelState(_state, smpException);
	}

	/*PROTECTED REGION ID(_Qlo1Yb1WEe-zAc57ptwKlg_connect) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void SunSensor::connectData() throw (Smp::IModel::InvalidModelState) {

	try {
		//data connections 
		this->getInput("in_sunDirection").connect(&_Cell_1->getInput("input_sunDirection"), 0, 3, 0);
		this->getInput("in_sunDirection").connect(&_Cell_2->getInput("input_sunDirection"), 0, 3, 0);
		this->getInput("in_sunDirection").connect(&_Cell_0->getInput("input_sunDirection"), 0, 3, 0);
		this->getInput("in_sunDirection").connect(&_Cell_3->getInput("input_sunDirection"), 0, 3, 0);
		_Baffle->getOutput("out_baffleCoefficient").connect(&this->getOutput("out_test"), 0, 4, 0);
		this->getInput("in_sunAz").connect(&_Baffle->getInput("in_sunAzimuth"));
		this->getInput("in_sunEl").connect(&_Baffle->getInput("in_sunElevation"));

		/*PROTECTED REGION ID(_Qlo1Yb1WEe-zAc57ptwKlg_connectData_catching) ENABLED START*/
		//add user defined code here
		/*PROTECTED REGION END*/
	}
	catch (simtg::Exception& simtgException) {
		throw simtg::ModelBase::InvalidModelState(_state, simtgException);
	}
	catch (Smp::Exception& smpException) {
		throw simtg::ModelBase::InvalidModelState(_state, smpException);
	}

	/*PROTECTED REGION ID(_Qlo1Yb1WEe-zAc57ptwKlg_connectData) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void SunSensor::initDefaultValues() {

	//set init values of variables
	for (int row = 0; row < 3; row++) {
		_in_sunDirection[row] = 0.0;
	}
	for (int row = 0; row < 4; row++) {
		_out_measuredCurrents[row] = 0.0;
	}
	_orientation_0[0] = 1.0;
	_orientation_0[1] = -1.0;
	_orientation_0[2] = 0.0;
	_orientation_1[0] = 1.0;
	_orientation_1[1] = 1.0;
	_orientation_1[2] = 0.0;
	_orientation_2[0] = 1.0;
	_orientation_2[1] = 0.0;
	_orientation_2[2] = -1.0;
	_orientation_3[0] = 1.0;
	_orientation_3[1] = 0.0;
	_orientation_3[2] = 1.0;
	_angle = 22.0;
	_in_sunAz = 0.0;
	_in_sunEl = 0.0;
	for (int row = 0; row < 40; row++) {
		_out_test[row] = 0.0;
	}
	_stepNbr = 0;

	initSubModelsDefaultValues();

	/*PROTECTED REGION ID(_Qlo1Yb1WEe-zAc57ptwKlg_initDefaultValues) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void SunSensor::initSubModelsDefaultValues() {

	/*PROTECTED REGION ID(_Qlo1Yb1WEe-zAc57ptwKlg_initSubModelsDefaultValues) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void SunSensor::initScheduling() {

	std::list<MethodInfo> methods;

	/*PROTECTED REGION ID(_Qlo1Yb1WEe-zAc57ptwKlg_initScheduling_before_pushback) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/
	try {
		registerMethods(methods);
	}
	catch (simtg::Exception& e) {
		std::cerr << "Exception:" << e.what() << std::endl;
	}

	/*PROTECTED REGION ID(_Qlo1Yb1WEe-zAc57ptwKlg_initSheduling) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void SunSensor::callMethod(uint32_t methodId_, BaseType* params_)
		throw (SchedulableObject::BreakPointReached, simtg::Exception) {

	preCompute();
	switch (methodId_) {
	/*PROTECTED REGION ID(_Qlo1Yb1WEe-zAc57ptwKlg_callMethod_switch) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/
	default:
		ModelBase::callMethod(methodId_, params_);
	}
	postCompute();
	/*PROTECTED REGION ID(_Qlo1Yb1WEe-zAc57ptwKlg_callMethod) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void SunSensor::serializeMembers(simtg::SerializationStream& stream_)
		throw (simtg::SerializationException) {

	/*PROTECTED REGION ID(_Qlo1Yb1WEe-zAc57ptwKlg_start_serializeMembers) ENABLED START*/
	// add user defined code here
	/*PROTECTED REGION END*/

	stream_.array(&_orientation_0[0], 3);
	stream_.array(&_orientation_1[0], 3);
	stream_.array(&_orientation_2[0], 3);
	stream_.array(&_orientation_3[0], 3);
	stream_.value(_angle);
	stream_.value(_stepNbr);

	_Cell_0->serialize(stream_);
	_Cell_1->serialize(stream_);
	_Cell_2->serialize(stream_);
	_Cell_3->serialize(stream_);
	_Baffle->serialize(stream_);

	serializeExt(stream_);

	/*PROTECTED REGION ID(_Qlo1Yb1WEe-zAc57ptwKlg_serializeMembers) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}

/*PROTECTED REGION ID(_Qlo1Yb1WEe-zAc57ptwKlg_auto_cpp_end_extensionsauto) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/
