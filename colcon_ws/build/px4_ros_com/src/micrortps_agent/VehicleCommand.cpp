// Copyright 2016 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/*!
 * @file VehicleCommand.cpp
 * This source file contains the definition of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */

#ifdef _WIN32
// Remove linker warning LNK4221 on Visual Studio
namespace { char dummy; }
#endif

#include "VehicleCommand.h"
#include <fastcdr/Cdr.h>

#include <fastcdr/exceptions/BadParamException.h>
using namespace eprosima::fastcdr::exception;

#include <utility>























































































































































px4_msgs::msg::VehicleCommand::VehicleCommand()
{
    // m_timestamp com.eprosima.idl.parser.typecode.PrimitiveTypeCode@7b227d8d
    m_timestamp = 0;
    // m_param1 com.eprosima.idl.parser.typecode.PrimitiveTypeCode@7219ec67
    m_param1 = 0.0;
    // m_param2 com.eprosima.idl.parser.typecode.PrimitiveTypeCode@45018215
    m_param2 = 0.0;
    // m_param3 com.eprosima.idl.parser.typecode.PrimitiveTypeCode@65d6b83b
    m_param3 = 0.0;
    // m_param4 com.eprosima.idl.parser.typecode.PrimitiveTypeCode@d706f19
    m_param4 = 0.0;
    // m_param5 com.eprosima.idl.parser.typecode.PrimitiveTypeCode@30b7c004
    m_param5 = 0.0;
    // m_param6 com.eprosima.idl.parser.typecode.PrimitiveTypeCode@79efed2d
    m_param6 = 0.0;
    // m_param7 com.eprosima.idl.parser.typecode.PrimitiveTypeCode@2928854b
    m_param7 = 0.0;
    // m_command com.eprosima.idl.parser.typecode.PrimitiveTypeCode@27ae2fd0
    m_command = 0;
    // m_target_system com.eprosima.idl.parser.typecode.PrimitiveTypeCode@29176cc1
    m_target_system = 0;
    // m_target_component com.eprosima.idl.parser.typecode.PrimitiveTypeCode@2f177a4b
    m_target_component = 0;
    // m_source_system com.eprosima.idl.parser.typecode.PrimitiveTypeCode@4278a03f
    m_source_system = 0;
    // m_source_component com.eprosima.idl.parser.typecode.PrimitiveTypeCode@147ed70f
    m_source_component = 0;
    // m_confirmation com.eprosima.idl.parser.typecode.PrimitiveTypeCode@61dd025
    m_confirmation = 0;
    // m_from_external com.eprosima.idl.parser.typecode.PrimitiveTypeCode@124c278f
    m_from_external = false;

}

px4_msgs::msg::VehicleCommand::~VehicleCommand()
{















}

px4_msgs::msg::VehicleCommand::VehicleCommand(const VehicleCommand &x)
{
    m_timestamp = x.m_timestamp;
    m_param1 = x.m_param1;
    m_param2 = x.m_param2;
    m_param3 = x.m_param3;
    m_param4 = x.m_param4;
    m_param5 = x.m_param5;
    m_param6 = x.m_param6;
    m_param7 = x.m_param7;
    m_command = x.m_command;
    m_target_system = x.m_target_system;
    m_target_component = x.m_target_component;
    m_source_system = x.m_source_system;
    m_source_component = x.m_source_component;
    m_confirmation = x.m_confirmation;
    m_from_external = x.m_from_external;
}

px4_msgs::msg::VehicleCommand::VehicleCommand(VehicleCommand &&x)
{
    m_timestamp = x.m_timestamp;
    m_param1 = x.m_param1;
    m_param2 = x.m_param2;
    m_param3 = x.m_param3;
    m_param4 = x.m_param4;
    m_param5 = x.m_param5;
    m_param6 = x.m_param6;
    m_param7 = x.m_param7;
    m_command = x.m_command;
    m_target_system = x.m_target_system;
    m_target_component = x.m_target_component;
    m_source_system = x.m_source_system;
    m_source_component = x.m_source_component;
    m_confirmation = x.m_confirmation;
    m_from_external = x.m_from_external;
}

px4_msgs::msg::VehicleCommand& px4_msgs::msg::VehicleCommand::operator=(const VehicleCommand &x)
{

    m_timestamp = x.m_timestamp;
    m_param1 = x.m_param1;
    m_param2 = x.m_param2;
    m_param3 = x.m_param3;
    m_param4 = x.m_param4;
    m_param5 = x.m_param5;
    m_param6 = x.m_param6;
    m_param7 = x.m_param7;
    m_command = x.m_command;
    m_target_system = x.m_target_system;
    m_target_component = x.m_target_component;
    m_source_system = x.m_source_system;
    m_source_component = x.m_source_component;
    m_confirmation = x.m_confirmation;
    m_from_external = x.m_from_external;

    return *this;
}

px4_msgs::msg::VehicleCommand& px4_msgs::msg::VehicleCommand::operator=(VehicleCommand &&x)
{

    m_timestamp = x.m_timestamp;
    m_param1 = x.m_param1;
    m_param2 = x.m_param2;
    m_param3 = x.m_param3;
    m_param4 = x.m_param4;
    m_param5 = x.m_param5;
    m_param6 = x.m_param6;
    m_param7 = x.m_param7;
    m_command = x.m_command;
    m_target_system = x.m_target_system;
    m_target_component = x.m_target_component;
    m_source_system = x.m_source_system;
    m_source_component = x.m_source_component;
    m_confirmation = x.m_confirmation;
    m_from_external = x.m_from_external;

    return *this;
}

size_t px4_msgs::msg::VehicleCommand::getMaxCdrSerializedSize(size_t current_alignment)
{
    size_t initial_alignment = current_alignment;


    current_alignment += 8 + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 8 + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);


    current_alignment += 8 + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 1 + eprosima::fastcdr::Cdr::alignment(current_alignment, 1);


    current_alignment += 1 + eprosima::fastcdr::Cdr::alignment(current_alignment, 1);


    current_alignment += 1 + eprosima::fastcdr::Cdr::alignment(current_alignment, 1);


    current_alignment += 1 + eprosima::fastcdr::Cdr::alignment(current_alignment, 1);


    current_alignment += 1 + eprosima::fastcdr::Cdr::alignment(current_alignment, 1);


    current_alignment += 1 + eprosima::fastcdr::Cdr::alignment(current_alignment, 1);



    return current_alignment - initial_alignment;
}

size_t px4_msgs::msg::VehicleCommand::getCdrSerializedSize(const px4_msgs::msg::VehicleCommand& data, size_t current_alignment)
{
    (void)data;
    size_t initial_alignment = current_alignment;


    current_alignment += 8 + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 8 + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);


    current_alignment += 8 + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 1 + eprosima::fastcdr::Cdr::alignment(current_alignment, 1);


    current_alignment += 1 + eprosima::fastcdr::Cdr::alignment(current_alignment, 1);


    current_alignment += 1 + eprosima::fastcdr::Cdr::alignment(current_alignment, 1);


    current_alignment += 1 + eprosima::fastcdr::Cdr::alignment(current_alignment, 1);


    current_alignment += 1 + eprosima::fastcdr::Cdr::alignment(current_alignment, 1);


    current_alignment += 1 + eprosima::fastcdr::Cdr::alignment(current_alignment, 1);



    return current_alignment - initial_alignment;
}

void px4_msgs::msg::VehicleCommand::serialize(eprosima::fastcdr::Cdr &scdr) const
{

    scdr << m_timestamp;
    scdr << m_param1;
    scdr << m_param2;
    scdr << m_param3;
    scdr << m_param4;
    scdr << m_param5;
    scdr << m_param6;
    scdr << m_param7;
    scdr << m_command;
    scdr << m_target_system;
    scdr << m_target_component;
    scdr << m_source_system;
    scdr << m_source_component;
    scdr << m_confirmation;
    scdr << m_from_external;
}

void px4_msgs::msg::VehicleCommand::deserialize(eprosima::fastcdr::Cdr &dcdr)
{

    dcdr >> m_timestamp;
    dcdr >> m_param1;
    dcdr >> m_param2;
    dcdr >> m_param3;
    dcdr >> m_param4;
    dcdr >> m_param5;
    dcdr >> m_param6;
    dcdr >> m_param7;
    dcdr >> m_command;
    dcdr >> m_target_system;
    dcdr >> m_target_component;
    dcdr >> m_source_system;
    dcdr >> m_source_component;
    dcdr >> m_confirmation;
    dcdr >> m_from_external;
}

/*!
 * @brief This function sets a value in member timestamp
 * @param _timestamp New value for member timestamp
 */
void px4_msgs::msg::VehicleCommand::timestamp(uint64_t _timestamp)
{
m_timestamp = _timestamp;
}

/*!
 * @brief This function returns the value of member timestamp
 * @return Value of member timestamp
 */
uint64_t px4_msgs::msg::VehicleCommand::timestamp() const
{
    return m_timestamp;
}

/*!
 * @brief This function returns a reference to member timestamp
 * @return Reference to member timestamp
 */
uint64_t& px4_msgs::msg::VehicleCommand::timestamp()
{
    return m_timestamp;
}

/*!
 * @brief This function sets a value in member param1
 * @param _param1 New value for member param1
 */
void px4_msgs::msg::VehicleCommand::param1(float _param1)
{
m_param1 = _param1;
}

/*!
 * @brief This function returns the value of member param1
 * @return Value of member param1
 */
float px4_msgs::msg::VehicleCommand::param1() const
{
    return m_param1;
}

/*!
 * @brief This function returns a reference to member param1
 * @return Reference to member param1
 */
float& px4_msgs::msg::VehicleCommand::param1()
{
    return m_param1;
}

/*!
 * @brief This function sets a value in member param2
 * @param _param2 New value for member param2
 */
void px4_msgs::msg::VehicleCommand::param2(float _param2)
{
m_param2 = _param2;
}

/*!
 * @brief This function returns the value of member param2
 * @return Value of member param2
 */
float px4_msgs::msg::VehicleCommand::param2() const
{
    return m_param2;
}

/*!
 * @brief This function returns a reference to member param2
 * @return Reference to member param2
 */
float& px4_msgs::msg::VehicleCommand::param2()
{
    return m_param2;
}

/*!
 * @brief This function sets a value in member param3
 * @param _param3 New value for member param3
 */
void px4_msgs::msg::VehicleCommand::param3(float _param3)
{
m_param3 = _param3;
}

/*!
 * @brief This function returns the value of member param3
 * @return Value of member param3
 */
float px4_msgs::msg::VehicleCommand::param3() const
{
    return m_param3;
}

/*!
 * @brief This function returns a reference to member param3
 * @return Reference to member param3
 */
float& px4_msgs::msg::VehicleCommand::param3()
{
    return m_param3;
}

/*!
 * @brief This function sets a value in member param4
 * @param _param4 New value for member param4
 */
void px4_msgs::msg::VehicleCommand::param4(float _param4)
{
m_param4 = _param4;
}

/*!
 * @brief This function returns the value of member param4
 * @return Value of member param4
 */
float px4_msgs::msg::VehicleCommand::param4() const
{
    return m_param4;
}

/*!
 * @brief This function returns a reference to member param4
 * @return Reference to member param4
 */
float& px4_msgs::msg::VehicleCommand::param4()
{
    return m_param4;
}

/*!
 * @brief This function sets a value in member param5
 * @param _param5 New value for member param5
 */
void px4_msgs::msg::VehicleCommand::param5(double _param5)
{
m_param5 = _param5;
}

/*!
 * @brief This function returns the value of member param5
 * @return Value of member param5
 */
double px4_msgs::msg::VehicleCommand::param5() const
{
    return m_param5;
}

/*!
 * @brief This function returns a reference to member param5
 * @return Reference to member param5
 */
double& px4_msgs::msg::VehicleCommand::param5()
{
    return m_param5;
}

/*!
 * @brief This function sets a value in member param6
 * @param _param6 New value for member param6
 */
void px4_msgs::msg::VehicleCommand::param6(double _param6)
{
m_param6 = _param6;
}

/*!
 * @brief This function returns the value of member param6
 * @return Value of member param6
 */
double px4_msgs::msg::VehicleCommand::param6() const
{
    return m_param6;
}

/*!
 * @brief This function returns a reference to member param6
 * @return Reference to member param6
 */
double& px4_msgs::msg::VehicleCommand::param6()
{
    return m_param6;
}

/*!
 * @brief This function sets a value in member param7
 * @param _param7 New value for member param7
 */
void px4_msgs::msg::VehicleCommand::param7(float _param7)
{
m_param7 = _param7;
}

/*!
 * @brief This function returns the value of member param7
 * @return Value of member param7
 */
float px4_msgs::msg::VehicleCommand::param7() const
{
    return m_param7;
}

/*!
 * @brief This function returns a reference to member param7
 * @return Reference to member param7
 */
float& px4_msgs::msg::VehicleCommand::param7()
{
    return m_param7;
}

/*!
 * @brief This function sets a value in member command
 * @param _command New value for member command
 */
void px4_msgs::msg::VehicleCommand::command(uint32_t _command)
{
m_command = _command;
}

/*!
 * @brief This function returns the value of member command
 * @return Value of member command
 */
uint32_t px4_msgs::msg::VehicleCommand::command() const
{
    return m_command;
}

/*!
 * @brief This function returns a reference to member command
 * @return Reference to member command
 */
uint32_t& px4_msgs::msg::VehicleCommand::command()
{
    return m_command;
}

/*!
 * @brief This function sets a value in member target_system
 * @param _target_system New value for member target_system
 */
void px4_msgs::msg::VehicleCommand::target_system(uint8_t _target_system)
{
m_target_system = _target_system;
}

/*!
 * @brief This function returns the value of member target_system
 * @return Value of member target_system
 */
uint8_t px4_msgs::msg::VehicleCommand::target_system() const
{
    return m_target_system;
}

/*!
 * @brief This function returns a reference to member target_system
 * @return Reference to member target_system
 */
uint8_t& px4_msgs::msg::VehicleCommand::target_system()
{
    return m_target_system;
}

/*!
 * @brief This function sets a value in member target_component
 * @param _target_component New value for member target_component
 */
void px4_msgs::msg::VehicleCommand::target_component(uint8_t _target_component)
{
m_target_component = _target_component;
}

/*!
 * @brief This function returns the value of member target_component
 * @return Value of member target_component
 */
uint8_t px4_msgs::msg::VehicleCommand::target_component() const
{
    return m_target_component;
}

/*!
 * @brief This function returns a reference to member target_component
 * @return Reference to member target_component
 */
uint8_t& px4_msgs::msg::VehicleCommand::target_component()
{
    return m_target_component;
}

/*!
 * @brief This function sets a value in member source_system
 * @param _source_system New value for member source_system
 */
void px4_msgs::msg::VehicleCommand::source_system(uint8_t _source_system)
{
m_source_system = _source_system;
}

/*!
 * @brief This function returns the value of member source_system
 * @return Value of member source_system
 */
uint8_t px4_msgs::msg::VehicleCommand::source_system() const
{
    return m_source_system;
}

/*!
 * @brief This function returns a reference to member source_system
 * @return Reference to member source_system
 */
uint8_t& px4_msgs::msg::VehicleCommand::source_system()
{
    return m_source_system;
}

/*!
 * @brief This function sets a value in member source_component
 * @param _source_component New value for member source_component
 */
void px4_msgs::msg::VehicleCommand::source_component(uint8_t _source_component)
{
m_source_component = _source_component;
}

/*!
 * @brief This function returns the value of member source_component
 * @return Value of member source_component
 */
uint8_t px4_msgs::msg::VehicleCommand::source_component() const
{
    return m_source_component;
}

/*!
 * @brief This function returns a reference to member source_component
 * @return Reference to member source_component
 */
uint8_t& px4_msgs::msg::VehicleCommand::source_component()
{
    return m_source_component;
}

/*!
 * @brief This function sets a value in member confirmation
 * @param _confirmation New value for member confirmation
 */
void px4_msgs::msg::VehicleCommand::confirmation(uint8_t _confirmation)
{
m_confirmation = _confirmation;
}

/*!
 * @brief This function returns the value of member confirmation
 * @return Value of member confirmation
 */
uint8_t px4_msgs::msg::VehicleCommand::confirmation() const
{
    return m_confirmation;
}

/*!
 * @brief This function returns a reference to member confirmation
 * @return Reference to member confirmation
 */
uint8_t& px4_msgs::msg::VehicleCommand::confirmation()
{
    return m_confirmation;
}

/*!
 * @brief This function sets a value in member from_external
 * @param _from_external New value for member from_external
 */
void px4_msgs::msg::VehicleCommand::from_external(bool _from_external)
{
m_from_external = _from_external;
}

/*!
 * @brief This function returns the value of member from_external
 * @return Value of member from_external
 */
bool px4_msgs::msg::VehicleCommand::from_external() const
{
    return m_from_external;
}

/*!
 * @brief This function returns a reference to member from_external
 * @return Reference to member from_external
 */
bool& px4_msgs::msg::VehicleCommand::from_external()
{
    return m_from_external;
}


size_t px4_msgs::msg::VehicleCommand::getKeyMaxCdrSerializedSize(size_t current_alignment)
{
    size_t current_align = current_alignment;


















    return current_align;
}

bool px4_msgs::msg::VehicleCommand::isKeyDefined()
{
   return false;
}

void px4_msgs::msg::VehicleCommand::serializeKey(eprosima::fastcdr::Cdr &scdr) const
{
    (void) scdr;
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
}

