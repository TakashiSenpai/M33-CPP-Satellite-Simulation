/*
 * File AttitudeControlSystem.cpp
 *
 * Project SatSim
 *
 *
 * Copyright (c) Astrium 2011. All rights reserved.
 *
 */

/*PROTECTED REGION ID(_4bXJYeCZEe-JhMcKl8Urew_impl_cpp_before_includeimplementation) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/

#include "AttitudeControlSystem.hpp"
#include "Controller.hpp"
#include "Actuator.hpp"

using namespace SatSim;

OBJECT_MAKER(AttitudeControlSystem)

/*PROTECTED REGION ID(_4bXJYeCZEe-JhMcKl8Urew_impl_cpp_after_includeimplementation) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/

void AttitudeControlSystem::constructor() {
	/*PROTECTED REGION ID(_4bXJYeCZEe-JhMcKl8Urewdelegated_constructor) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void AttitudeControlSystem::destructor() {
	/*PROTECTED REGION ID(_4bXJYeCZEe-JhMcKl8Urewdelegated_destructor) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void AttitudeControlSystem::configure() throw (simtg::Exception) {
	/*PROTECTED REGION ID(_4bXJYeCZEe-JhMcKl8Urewdelegated_configure) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void AttitudeControlSystem::serializeExt(simtg::SerializationStream& stream_) throw (simtg::SerializationException) {
	/*PROTECTED REGION ID(_4bXJYeCZEe-JhMcKl8UrewserializeExt) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void AttitudeControlSystem::step() throw (simtg::Exception) {
	/*PROTECTED REGION ID(_4bXJZOCZEe-JhMcKl8Urew) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void AttitudeControlSystem::init() throw (simtg::Exception) {

	/*PROTECTED REGION ID(_4bXJYeCZEe-JhMcKl8Urew_startInit) ENABLED START*/
	// add user defined code here
	/*PROTECTED REGION END*/

	_Controller->init();
	_Actuator->init();

	AsyncModelBase::init();

	/*PROTECTED REGION ID(_4bXJYeCZEe-JhMcKl8Urew_init) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}

/*PROTECTED REGION ID(_4bXJYeCZEe-JhMcKl8Urew_impl_cpp_end_extensionsimplementation) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/
