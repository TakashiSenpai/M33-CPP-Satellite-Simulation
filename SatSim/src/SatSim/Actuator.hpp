/*
 * File Actuator.hpp
 *
 * Project SatSim
 *
 *
 * Copyright (c) Astrium 2011. All rights reserved.
 *
 */

#ifndef __ACTUATOR__HPP
#define __ACTUATOR__HPP

#include <simtg/model/AsyncModelBase.hpp>
#include <SatSim/SatSim.hpp>
#include <simtg/kernel/Data.hpp>
#include <simtg/kernel/AsyncData.hpp>

/*PROTECTED REGION ID(_rn_dMeCcEe-JhMcKl8Urew_header_hpp_include) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/

namespace SatSim {

/*PROTECTED REGION ID(_rn_dMeCcEe-JhMcKl8Urew_hpp_inside_namespace) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/

class Actuator: public
		simtg::AsyncModelBase {

public:
	/**
	 [OUTPUT]  [3]
	 */
	simtg::AsyncFloat _out_sunDirection;
	/**
	 [INPUT]  [2]
	 */
	simtg::AsyncFloat _in_rotationAngles;
	/**
	 [INPUT]  [3]
	 */
	simtg::AsyncFloat _in_sunDirection;
	/**
	 [STATE]  [3, 3]
	 */
	simtg::AsyncFloat _rotX;
	/**
	 [STATE]  [3, 3]
	 */
	simtg::AsyncFloat _rotY;
	/**
	 [STATE]  [3]
	 */
	simtg::AsyncFloat _sunDirectionRotY;
	/**
	 [STATE]  [3]
	 */
	simtg::AsyncFloat _sunDirectionRotX;
	/**
	 [STATE]  [4]
	 */
	simtg::AsyncFloat _qPosOldArr;
	/**
	 [STATE]  [4]
	 */
	simtg::AsyncFloat _qPosNewArr;
	/**
	 [STATE]  [4]
	 */
	simtg::AsyncFloat _qRotArr;
	/**
	 [STATE]  [4]
	 */
	simtg::AsyncFloat _qRotStarArr;
	/**
	 [LOCAL] 
	 */
	float _maxRotationAngle;
	/**
	 [STATE] 
	 */
	simtg::AsyncFloat _angle;
	/**
	 [STATE]  [3]
	 */
	simtg::AsyncFloat _axis;
	/**
	 [INPUT] 
	 */
	simtg::AsyncInt _forceStep;

private:
	/**
	 Delegated constructor
	 */
	void constructor();
	/**
	 Delegated destructor
	 */
	void destructor();
	/**
	 Delegated configure
	 */
	void configure() throw (simtg::Exception);
	/**
	 Delegated serialize method. Permits to serialize additional fields.
	 @param stream_         a serialization stream
	 */
	void serializeExt(simtg::SerializationStream& stream_) throw (simtg::SerializationException);

protected:
	/**
	 Init default values
	 */
	void initDefaultValues();
	/**
	 Init sub models default values
	 */
	void initSubModelsDefaultValues();
	/**
	 Init scheduling
	 */
	void initScheduling();
	/**
	 Serialization method:
	 @param stream_         a serialization stream
	 */
	void serializeMembers(simtg::SerializationStream& stream_) throw (simtg::SerializationException);

public:
	/**
	 Default constructor
	 @param name_         the model instance name
	 @param parent_         the model parent
	 @param description_         the model description
	 */
	Actuator(Smp::String8 name_ = "", simtg::NamedObject* parent_ = 0, Smp::String8 description_ = "");
	/**
	 SMP default Constructor
	 @param name_         the model instance name
	 @param description_         the model description
	 @param parent_         the model parent
	 */
	Actuator(Smp::String8 name_, Smp::String8 description_, Smp::IComposite* parent_);
	/**
	 Default Destructor
	 */
	virtual ~Actuator();
	/**
	 Default step method
	 */
	void step() throw (simtg::Exception);
	/**
	 InitMethod of Actuator
	 */
	void init() throw (simtg::Exception);
	/**
	 Publish method of Actuator
	 @param publication_         a SMP publishing interface
	 */
	void Publish(Smp::IPublication* publication_) throw (Smp::IModel::InvalidModelState);
	/**
	 Load configuration
	 @param logger_         a SMP logging interface
	 */
	void Configure(Smp::Services::ILogger* logger_) throw (Smp::IModel::InvalidModelState);
	/**
	 Connect Model to simulation environment.
	 @param sim_         a SMP simulation interface
	 */
	void Connect(Smp::ISimulator* sim_) throw (Smp::IModel::InvalidModelState);
	/**
	 Connect Models with each other.
	 */
	void connectData() throw (Smp::IModel::InvalidModelState);
	/**
	 Connect Model to simulation environment.
	 @param methodId_         a model method identifier
	 @param params_         a method parameters container
	 */
	void callMethod(uint32_t methodId_, BaseType* params_) throw (SchedulableObject::BreakPointReached, simtg::Exception);

public:
	CLASS_INFO(Actuator,simtg::AsyncModelBase,SatSim)

public:

	/*PROTECTED REGION ID(_rn_dMeCcEe-JhMcKl8Urew_methodIDEnum_hpp_inside_namespace) ENABLED START*/
	//add user defined includes here
	/*PROTECTED REGION END*/

	/**
	 Enumeration fo method IDs
	 */
	enum methodIDs {

	/*PROTECTED REGION ID(_rn_dMeCcEe-JhMcKl8Urew_methodIDEnum_hpp_enum_extensions) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

	};
	// end enum methodIDs

	/*PROTECTED REGION ID(_rn_dMeCcEe-JhMcKl8Urew_hpp_class_extensions) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

};
// end class Actuator
}//end SatSim

/*PROTECTED REGION ID(_rn_dMeCcEe-JhMcKl8Urew_header_hpp_end_extensions) ENABLED START*/
//add user defined code here
/*PROTECTED REGION END*/

#endif //end __ACTUATOR.HPP__H  

