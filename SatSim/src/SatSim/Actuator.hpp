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

#include <simtg/model/ModelBase.hpp>
#include <SatSim/SatSim.hpp>
#include <simtg/kernel/Data.hpp>

/*PROTECTED REGION ID(_LVfTodcvEe-g-_tbVlfW3w_header_hpp_include) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/

namespace SatSim {

/*PROTECTED REGION ID(_LVfTodcvEe-g-_tbVlfW3w_hpp_inside_namespace) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/

class Actuator: public
		simtg::ModelBase {

public:
	/**
	 [INPUT]  [4]
	 */
	simtg::Float _in_measuredCurrents;
	/**
	 [LOCAL]  [2]
	 */
	float _out_actuationAngle[2];
	/**
	 [LOCAL]  [4]
	 */
	float _measuredCurrents[4];
	/**
	 [LOCAL]  [3]
	 */
	float _cssSunDirections[3];
	/**
	 [LOCAL]  [2]
	 */
	float _calculatedPosition[2];
	/**
	 [LOCAL]  [2]
	 */
	float _lastPosition[2];
	/**
	 [LOCAL]  [2]
	 */
	float _sumPositions[2];
	/**
	 [LOCAL] 
	 */
	float _coefficientProportional;
	/**
	 [LOCAL] 
	 */
	float _coefficientIntegration;
	/**
	 [LOCAL] 
	 */
	float _coefficientDifferential;
	/**
	 [LOCAL] 
	 */
	int32_t _numSteps;

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
	void serializeExt(simtg::SerializationStream& stream_)
			throw (simtg::SerializationException);

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
	void serializeMembers(simtg::SerializationStream& stream_)
			throw (simtg::SerializationException);

public:
	/**
	 Default constructor
	 @param name_         the model instance name
	 @param parent_         the model parent
	 @param description_         the model description
	 */
	Actuator(Smp::String8 name_ = "", simtg::NamedObject* parent_ = 0,
			Smp::String8 description_ = "");
	/**
	 SMP default Constructor
	 @param name_         the model instance name
	 @param description_         the model description
	 @param parent_         the model parent
	 */
	Actuator(Smp::String8 name_, Smp::String8 description_,
			Smp::IComposite* parent_);
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
	void Publish(Smp::IPublication* publication_)
			throw (Smp::IModel::InvalidModelState);
	/**
	 Load configuration
	 @param logger_         a SMP logging interface
	 */
	void Configure(Smp::Services::ILogger* logger_)
			throw (Smp::IModel::InvalidModelState);
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
	void callMethod(uint32_t methodId_, BaseType* params_)
			throw (SchedulableObject::BreakPointReached, simtg::Exception);

public:
	CLASS_INFO(Actuator,simtg::ModelBase,SatSim)

public:

	/*PROTECTED REGION ID(_LVfTodcvEe-g-_tbVlfW3w_methodIDEnum_hpp_inside_namespace) ENABLED START*/
	//add user defined includes here
	/*PROTECTED REGION END*/

	/**
	 Enumeration fo method IDs
	 */
	enum methodIDs {

	/*PROTECTED REGION ID(_LVfTodcvEe-g-_tbVlfW3w_methodIDEnum_hpp_enum_extensions) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

	};
	// end enum methodIDs

	/*PROTECTED REGION ID(_LVfTodcvEe-g-_tbVlfW3w_hpp_class_extensions) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

};
// end class Actuator
}//end SatSim

/*PROTECTED REGION ID(_LVfTodcvEe-g-_tbVlfW3w_header_hpp_end_extensions) ENABLED START*/
//add user defined code here
/*PROTECTED REGION END*/

#endif //end __ACTUATOR.HPP__H  

