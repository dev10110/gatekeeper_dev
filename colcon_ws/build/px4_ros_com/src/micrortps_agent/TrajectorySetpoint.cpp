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
 * @file TrajectorySetpoint.cpp
 * This source file contains the definition of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */

#ifdef _WIN32
// Remove linker warning LNK4221 on Visual Studio
namespace { char dummy; }
#endif

#include "TrajectorySetpoint.h"
#include <fastcdr/Cdr.h>

#include <fastcdr/exceptions/BadParamException.h>
using namespace eprosima::fastcdr::exception;

#include <utility>


px4_msgs::msg::TrajectorySetpoint::TrajectorySetpoint()
{
    // m_timestamp com.eprosima.idl.parser.typecode.PrimitiveTypeCode@4b5a5ed1
    m_timestamp = 0;
    // m_x com.eprosima.idl.parser.typecode.PrimitiveTypeCode@59d016c9
    m_x = 0.0;
    // m_y com.eprosima.idl.parser.typecode.PrimitiveTypeCode@3cc2931c
    m_y = 0.0;
    // m_z com.eprosima.idl.parser.typecode.PrimitiveTypeCode@20d28811
    m_z = 0.0;
    // m_yaw com.eprosima.idl.parser.typecode.PrimitiveTypeCode@3967e60c
    m_yaw = 0.0;
    // m_yawspeed com.eprosima.idl.parser.typecode.PrimitiveTypeCode@60d8c9b7
    m_yawspeed = 0.0;
    // m_vx com.eprosima.idl.parser.typecode.PrimitiveTypeCode@48aaecc3
    m_vx = 0.0;
    // m_vy com.eprosima.idl.parser.typecode.PrimitiveTypeCode@7c0c77c7
    m_vy = 0.0;
    // m_vz com.eprosima.idl.parser.typecode.PrimitiveTypeCode@7adda9cc
    m_vz = 0.0;
    // m_acceleration com.eprosima.idl.parser.typecode.AliasTypeCode@5cee5251
    memset(&m_acceleration, 0, (3) * 4);
    // m_jerk com.eprosima.idl.parser.typecode.AliasTypeCode@5cee5251
    memset(&m_jerk, 0, (3) * 4);
    // m_thrust com.eprosima.idl.parser.typecode.AliasTypeCode@5cee5251
    memset(&m_thrust, 0, (3) * 4);

}

px4_msgs::msg::TrajectorySetpoint::~TrajectorySetpoint()
{












}

px4_msgs::msg::TrajectorySetpoint::TrajectorySetpoint(const TrajectorySetpoint &x)
{
    m_timestamp = x.m_timestamp;
    m_x = x.m_x;
    m_y = x.m_y;
    m_z = x.m_z;
    m_yaw = x.m_yaw;
    m_yawspeed = x.m_yawspeed;
    m_vx = x.m_vx;
    m_vy = x.m_vy;
    m_vz = x.m_vz;
    m_acceleration = x.m_acceleration;
    m_jerk = x.m_jerk;
    m_thrust = x.m_thrust;
}

px4_msgs::msg::TrajectorySetpoint::TrajectorySetpoint(TrajectorySetpoint &&x)
{
    m_timestamp = x.m_timestamp;
    m_x = x.m_x;
    m_y = x.m_y;
    m_z = x.m_z;
    m_yaw = x.m_yaw;
    m_yawspeed = x.m_yawspeed;
    m_vx = x.m_vx;
    m_vy = x.m_vy;
    m_vz = x.m_vz;
    m_acceleration = std::move(x.m_acceleration);
    m_jerk = std::move(x.m_jerk);
    m_thrust = std::move(x.m_thrust);
}

px4_msgs::msg::TrajectorySetpoint& px4_msgs::msg::TrajectorySetpoint::operator=(const TrajectorySetpoint &x)
{

    m_timestamp = x.m_timestamp;
    m_x = x.m_x;
    m_y = x.m_y;
    m_z = x.m_z;
    m_yaw = x.m_yaw;
    m_yawspeed = x.m_yawspeed;
    m_vx = x.m_vx;
    m_vy = x.m_vy;
    m_vz = x.m_vz;
    m_acceleration = x.m_acceleration;
    m_jerk = x.m_jerk;
    m_thrust = x.m_thrust;

    return *this;
}

px4_msgs::msg::TrajectorySetpoint& px4_msgs::msg::TrajectorySetpoint::operator=(TrajectorySetpoint &&x)
{

    m_timestamp = x.m_timestamp;
    m_x = x.m_x;
    m_y = x.m_y;
    m_z = x.m_z;
    m_yaw = x.m_yaw;
    m_yawspeed = x.m_yawspeed;
    m_vx = x.m_vx;
    m_vy = x.m_vy;
    m_vz = x.m_vz;
    m_acceleration = std::move(x.m_acceleration);
    m_jerk = std::move(x.m_jerk);
    m_thrust = std::move(x.m_thrust);

    return *this;
}

size_t px4_msgs::msg::TrajectorySetpoint::getMaxCdrSerializedSize(size_t current_alignment)
{
    size_t initial_alignment = current_alignment;


    current_alignment += 8 + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += ((3) * 4) + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += ((3) * 4) + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += ((3) * 4) + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);



    return current_alignment - initial_alignment;
}

size_t px4_msgs::msg::TrajectorySetpoint::getCdrSerializedSize(const px4_msgs::msg::TrajectorySetpoint& data, size_t current_alignment)
{
    (void)data;
    size_t initial_alignment = current_alignment;


    current_alignment += 8 + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    if ((3) > 0)
    {
        current_alignment += ((3) * 4) + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);
    }

    if ((3) > 0)
    {
        current_alignment += ((3) * 4) + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);
    }

    if ((3) > 0)
    {
        current_alignment += ((3) * 4) + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);
    }


    return current_alignment - initial_alignment;
}

void px4_msgs::msg::TrajectorySetpoint::serialize(eprosima::fastcdr::Cdr &scdr) const
{

    scdr << m_timestamp;
    scdr << m_x;
    scdr << m_y;
    scdr << m_z;
    scdr << m_yaw;
    scdr << m_yawspeed;
    scdr << m_vx;
    scdr << m_vy;
    scdr << m_vz;
    scdr << m_acceleration;

    scdr << m_jerk;

    scdr << m_thrust;

}

void px4_msgs::msg::TrajectorySetpoint::deserialize(eprosima::fastcdr::Cdr &dcdr)
{

    dcdr >> m_timestamp;
    dcdr >> m_x;
    dcdr >> m_y;
    dcdr >> m_z;
    dcdr >> m_yaw;
    dcdr >> m_yawspeed;
    dcdr >> m_vx;
    dcdr >> m_vy;
    dcdr >> m_vz;
    dcdr >> m_acceleration;

    dcdr >> m_jerk;

    dcdr >> m_thrust;

}

/*!
 * @brief This function sets a value in member timestamp
 * @param _timestamp New value for member timestamp
 */
void px4_msgs::msg::TrajectorySetpoint::timestamp(uint64_t _timestamp)
{
m_timestamp = _timestamp;
}

/*!
 * @brief This function returns the value of member timestamp
 * @return Value of member timestamp
 */
uint64_t px4_msgs::msg::TrajectorySetpoint::timestamp() const
{
    return m_timestamp;
}

/*!
 * @brief This function returns a reference to member timestamp
 * @return Reference to member timestamp
 */
uint64_t& px4_msgs::msg::TrajectorySetpoint::timestamp()
{
    return m_timestamp;
}

/*!
 * @brief This function sets a value in member x
 * @param _x New value for member x
 */
void px4_msgs::msg::TrajectorySetpoint::x(float _x)
{
m_x = _x;
}

/*!
 * @brief This function returns the value of member x
 * @return Value of member x
 */
float px4_msgs::msg::TrajectorySetpoint::x() const
{
    return m_x;
}

/*!
 * @brief This function returns a reference to member x
 * @return Reference to member x
 */
float& px4_msgs::msg::TrajectorySetpoint::x()
{
    return m_x;
}

/*!
 * @brief This function sets a value in member y
 * @param _y New value for member y
 */
void px4_msgs::msg::TrajectorySetpoint::y(float _y)
{
m_y = _y;
}

/*!
 * @brief This function returns the value of member y
 * @return Value of member y
 */
float px4_msgs::msg::TrajectorySetpoint::y() const
{
    return m_y;
}

/*!
 * @brief This function returns a reference to member y
 * @return Reference to member y
 */
float& px4_msgs::msg::TrajectorySetpoint::y()
{
    return m_y;
}

/*!
 * @brief This function sets a value in member z
 * @param _z New value for member z
 */
void px4_msgs::msg::TrajectorySetpoint::z(float _z)
{
m_z = _z;
}

/*!
 * @brief This function returns the value of member z
 * @return Value of member z
 */
float px4_msgs::msg::TrajectorySetpoint::z() const
{
    return m_z;
}

/*!
 * @brief This function returns a reference to member z
 * @return Reference to member z
 */
float& px4_msgs::msg::TrajectorySetpoint::z()
{
    return m_z;
}

/*!
 * @brief This function sets a value in member yaw
 * @param _yaw New value for member yaw
 */
void px4_msgs::msg::TrajectorySetpoint::yaw(float _yaw)
{
m_yaw = _yaw;
}

/*!
 * @brief This function returns the value of member yaw
 * @return Value of member yaw
 */
float px4_msgs::msg::TrajectorySetpoint::yaw() const
{
    return m_yaw;
}

/*!
 * @brief This function returns a reference to member yaw
 * @return Reference to member yaw
 */
float& px4_msgs::msg::TrajectorySetpoint::yaw()
{
    return m_yaw;
}

/*!
 * @brief This function sets a value in member yawspeed
 * @param _yawspeed New value for member yawspeed
 */
void px4_msgs::msg::TrajectorySetpoint::yawspeed(float _yawspeed)
{
m_yawspeed = _yawspeed;
}

/*!
 * @brief This function returns the value of member yawspeed
 * @return Value of member yawspeed
 */
float px4_msgs::msg::TrajectorySetpoint::yawspeed() const
{
    return m_yawspeed;
}

/*!
 * @brief This function returns a reference to member yawspeed
 * @return Reference to member yawspeed
 */
float& px4_msgs::msg::TrajectorySetpoint::yawspeed()
{
    return m_yawspeed;
}

/*!
 * @brief This function sets a value in member vx
 * @param _vx New value for member vx
 */
void px4_msgs::msg::TrajectorySetpoint::vx(float _vx)
{
m_vx = _vx;
}

/*!
 * @brief This function returns the value of member vx
 * @return Value of member vx
 */
float px4_msgs::msg::TrajectorySetpoint::vx() const
{
    return m_vx;
}

/*!
 * @brief This function returns a reference to member vx
 * @return Reference to member vx
 */
float& px4_msgs::msg::TrajectorySetpoint::vx()
{
    return m_vx;
}

/*!
 * @brief This function sets a value in member vy
 * @param _vy New value for member vy
 */
void px4_msgs::msg::TrajectorySetpoint::vy(float _vy)
{
m_vy = _vy;
}

/*!
 * @brief This function returns the value of member vy
 * @return Value of member vy
 */
float px4_msgs::msg::TrajectorySetpoint::vy() const
{
    return m_vy;
}

/*!
 * @brief This function returns a reference to member vy
 * @return Reference to member vy
 */
float& px4_msgs::msg::TrajectorySetpoint::vy()
{
    return m_vy;
}

/*!
 * @brief This function sets a value in member vz
 * @param _vz New value for member vz
 */
void px4_msgs::msg::TrajectorySetpoint::vz(float _vz)
{
m_vz = _vz;
}

/*!
 * @brief This function returns the value of member vz
 * @return Value of member vz
 */
float px4_msgs::msg::TrajectorySetpoint::vz() const
{
    return m_vz;
}

/*!
 * @brief This function returns a reference to member vz
 * @return Reference to member vz
 */
float& px4_msgs::msg::TrajectorySetpoint::vz()
{
    return m_vz;
}

/*!
 * @brief This function copies the value in member acceleration
 * @param _acceleration New value to be copied in member acceleration
 */
void px4_msgs::msg::TrajectorySetpoint::acceleration(const px4_msgs::msg::float__3 &_acceleration)
{
m_acceleration = _acceleration;
}

/*!
 * @brief This function moves the value in member acceleration
 * @param _acceleration New value to be moved in member acceleration
 */
void px4_msgs::msg::TrajectorySetpoint::acceleration(px4_msgs::msg::float__3 &&_acceleration)
{
m_acceleration = std::move(_acceleration);
}

/*!
 * @brief This function returns a constant reference to member acceleration
 * @return Constant reference to member acceleration
 */
const px4_msgs::msg::float__3& px4_msgs::msg::TrajectorySetpoint::acceleration() const
{
    return m_acceleration;
}

/*!
 * @brief This function returns a reference to member acceleration
 * @return Reference to member acceleration
 */
px4_msgs::msg::float__3& px4_msgs::msg::TrajectorySetpoint::acceleration()
{
    return m_acceleration;
}
/*!
 * @brief This function copies the value in member jerk
 * @param _jerk New value to be copied in member jerk
 */
void px4_msgs::msg::TrajectorySetpoint::jerk(const px4_msgs::msg::float__3 &_jerk)
{
m_jerk = _jerk;
}

/*!
 * @brief This function moves the value in member jerk
 * @param _jerk New value to be moved in member jerk
 */
void px4_msgs::msg::TrajectorySetpoint::jerk(px4_msgs::msg::float__3 &&_jerk)
{
m_jerk = std::move(_jerk);
}

/*!
 * @brief This function returns a constant reference to member jerk
 * @return Constant reference to member jerk
 */
const px4_msgs::msg::float__3& px4_msgs::msg::TrajectorySetpoint::jerk() const
{
    return m_jerk;
}

/*!
 * @brief This function returns a reference to member jerk
 * @return Reference to member jerk
 */
px4_msgs::msg::float__3& px4_msgs::msg::TrajectorySetpoint::jerk()
{
    return m_jerk;
}
/*!
 * @brief This function copies the value in member thrust
 * @param _thrust New value to be copied in member thrust
 */
void px4_msgs::msg::TrajectorySetpoint::thrust(const px4_msgs::msg::float__3 &_thrust)
{
m_thrust = _thrust;
}

/*!
 * @brief This function moves the value in member thrust
 * @param _thrust New value to be moved in member thrust
 */
void px4_msgs::msg::TrajectorySetpoint::thrust(px4_msgs::msg::float__3 &&_thrust)
{
m_thrust = std::move(_thrust);
}

/*!
 * @brief This function returns a constant reference to member thrust
 * @return Constant reference to member thrust
 */
const px4_msgs::msg::float__3& px4_msgs::msg::TrajectorySetpoint::thrust() const
{
    return m_thrust;
}

/*!
 * @brief This function returns a reference to member thrust
 * @return Reference to member thrust
 */
px4_msgs::msg::float__3& px4_msgs::msg::TrajectorySetpoint::thrust()
{
    return m_thrust;
}

size_t px4_msgs::msg::TrajectorySetpoint::getKeyMaxCdrSerializedSize(size_t current_alignment)
{
    size_t current_align = current_alignment;















    return current_align;
}

bool px4_msgs::msg::TrajectorySetpoint::isKeyDefined()
{
   return false;
}

void px4_msgs::msg::TrajectorySetpoint::serializeKey(eprosima::fastcdr::Cdr &scdr) const
{
    (void) scdr;
     
     
     
     
     
     
     
     
     
     
     
     
}


