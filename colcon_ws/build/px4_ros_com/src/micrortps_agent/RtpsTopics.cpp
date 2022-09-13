/****************************************************************************
 *
 * Copyright 2017 Proyectos y Sistemas de Mantenimiento SL (eProsima).
 * Copyright (c) 2018-2021 PX4 Development Team. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its contributors
 * may be used to endorse or promote products derived from this software without
 * specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

#include "RtpsTopics.h"

bool RtpsTopics::init(std::condition_variable *t_send_queue_cv, std::mutex *t_send_queue_mutex,
		      std::queue<uint8_t> *t_send_queue, const std::string &ns)
{
	// Initialise subscribers
	std::cout << "\033[0;36m---   Subscribers   ---\033[0m" << std::endl;

	if (_Timesync_sub.init(1, t_send_queue_cv, t_send_queue_mutex, t_send_queue, ns)) {
		std::cout << "- Timesync subscriber started" << std::endl;

	} else {
		std::cerr << "Failed starting Timesync subscriber" << std::endl;
		return false;
	}


	if (_OffboardControlMode_sub.init(5, t_send_queue_cv, t_send_queue_mutex, t_send_queue, ns)) {
		std::cout << "- OffboardControlMode subscriber started" << std::endl;

	} else {
		std::cerr << "Failed starting OffboardControlMode subscriber" << std::endl;
		return false;
	}


	if (_VehicleLocalPositionSetpoint_sub.init(6, t_send_queue_cv, t_send_queue_mutex, t_send_queue, ns)) {
		std::cout << "- VehicleLocalPositionSetpoint subscriber started" << std::endl;

	} else {
		std::cerr << "Failed starting VehicleLocalPositionSetpoint subscriber" << std::endl;
		return false;
	}


	if (_VehicleCommand_sub.init(8, t_send_queue_cv, t_send_queue_mutex, t_send_queue, ns)) {
		std::cout << "- VehicleCommand subscriber started" << std::endl;

	} else {
		std::cerr << "Failed starting VehicleCommand subscriber" << std::endl;
		return false;
	}


	if (_VehicleAttitudeSetpoint_sub.init(9, t_send_queue_cv, t_send_queue_mutex, t_send_queue, ns)) {
		std::cout << "- VehicleAttitudeSetpoint subscriber started" << std::endl;

	} else {
		std::cerr << "Failed starting VehicleAttitudeSetpoint subscriber" << std::endl;
		return false;
	}


	if (_VehicleRatesSetpoint_sub.init(10, t_send_queue_cv, t_send_queue_mutex, t_send_queue, ns)) {
		std::cout << "- VehicleRatesSetpoint subscriber started" << std::endl;

	} else {
		std::cerr << "Failed starting VehicleRatesSetpoint subscriber" << std::endl;
		return false;
	}


	if (_VehicleOdometry_sub.init(11, t_send_queue_cv, t_send_queue_mutex, t_send_queue, ns)) {
		std::cout << "- VehicleOdometry subscriber started" << std::endl;

	} else {
		std::cerr << "Failed starting VehicleOdometry subscriber" << std::endl;
		return false;
	}


	if (_SensorGps_sub.init(14, t_send_queue_cv, t_send_queue_mutex, t_send_queue, ns)) {
		std::cout << "- SensorGps subscriber started" << std::endl;

	} else {
		std::cerr << "Failed starting SensorGps subscriber" << std::endl;
		return false;
	}


	if (_ManualControlSetpoint_sub.init(16, t_send_queue_cv, t_send_queue_mutex, t_send_queue, ns)) {
		std::cout << "- ManualControlSetpoint subscriber started" << std::endl;

	} else {
		std::cerr << "Failed starting ManualControlSetpoint subscriber" << std::endl;
		return false;
	}


	if (_GpsInjectData_sub.init(18, t_send_queue_cv, t_send_queue_mutex, t_send_queue, ns)) {
		std::cout << "- GpsInjectData subscriber started" << std::endl;

	} else {
		std::cerr << "Failed starting GpsInjectData subscriber" << std::endl;
		return false;
	}


	if (_ExternalController_sub.init(19, t_send_queue_cv, t_send_queue_mutex, t_send_queue, ns)) {
		std::cout << "- ExternalController subscriber started" << std::endl;

	} else {
		std::cerr << "Failed starting ExternalController subscriber" << std::endl;
		return false;
	}


	if (_TrajectorySetpoint_sub.init(7, t_send_queue_cv, t_send_queue_mutex, t_send_queue, ns)) {
		std::cout << "- TrajectorySetpoint subscriber started" << std::endl;

	} else {
		std::cerr << "Failed starting TrajectorySetpoint subscriber" << std::endl;
		return false;
	}


	if (_VehicleVisualOdometry_sub.init(12, t_send_queue_cv, t_send_queue_mutex, t_send_queue, ns)) {
		std::cout << "- VehicleVisualOdometry subscriber started" << std::endl;

	} else {
		std::cerr << "Failed starting VehicleVisualOdometry subscriber" << std::endl;
		return false;
	}

	std::cout << "\033[0;36m-----------------------\033[0m" << std::endl << std::endl;

	// Initialise publishers
	std::cout << "\033[0;36m----   Publishers  ----\033[0m" << std::endl;

	if (_Timesync_pub.init(ns)) {
		if (_Timesync_fmu_in_pub.init(ns, std::string("fmu/timesync/in"))) {
			_timesync->start(&_Timesync_fmu_in_pub);
			std::cout << "- Timesync publishers started" << std::endl;
		}

	} else {
		std::cerr << "ERROR starting Timesync publisher" << std::endl;
		return false;
	}


	if (_SensorCombined_pub.init(ns)) {
		std::cout << "- SensorCombined publisher started" << std::endl;

	} else {
		std::cerr << "ERROR starting SensorCombined publisher" << std::endl;
		return false;
	}


	if (_VehicleAttitude_pub.init(ns)) {
		std::cout << "- VehicleAttitude publisher started" << std::endl;

	} else {
		std::cerr << "ERROR starting VehicleAttitude publisher" << std::endl;
		return false;
	}


	if (_VehicleLocalPosition_pub.init(ns)) {
		std::cout << "- VehicleLocalPosition publisher started" << std::endl;

	} else {
		std::cerr << "ERROR starting VehicleLocalPosition publisher" << std::endl;
		return false;
	}


	if (_TimesyncStatus_pub.init(ns, std::string("timesync_status"))) {
		_timesync->init_status_pub(&_TimesyncStatus_pub);
		std::cout << "- TimesyncStatus publisher started" << std::endl;

	} else {
		std::cerr << "ERROR starting TimesyncStatus publisher" << std::endl;
		return false;
	}


	if (_VehicleStatus_pub.init(ns)) {
		std::cout << "- VehicleStatus publisher started" << std::endl;

	} else {
		std::cerr << "ERROR starting VehicleStatus publisher" << std::endl;
		return false;
	}


	if (_BatteryStatus_pub.init(ns)) {
		std::cout << "- BatteryStatus publisher started" << std::endl;

	} else {
		std::cerr << "ERROR starting BatteryStatus publisher" << std::endl;
		return false;
	}

	std::cout << "\033[0;36m-----------------------\033[0m" << std::endl;
	return true;
}

template <typename T>
void RtpsTopics::sync_timestamp_of_incoming_data(T &msg) {
	uint64_t timestamp = getMsgTimestamp(&msg);
	uint64_t timestamp_sample = getMsgTimestampSample(&msg);
	_timesync->subtractOffset(timestamp);
	setMsgTimestamp(&msg, timestamp);
	_timesync->subtractOffset(timestamp_sample);
	setMsgTimestampSample(&msg, timestamp_sample);
}

void RtpsTopics::publish(const uint8_t topic_ID, char data_buffer[], size_t len)
{
	switch (topic_ID) {

	case 1: { // Timesync publisher
		Timesync_msg_t st;
		eprosima::fastcdr::FastBuffer cdrbuffer(data_buffer, len);
		eprosima::fastcdr::Cdr cdr_des(cdrbuffer);
		st.deserialize(cdr_des);
		_timesync->processTimesyncMsg(&st, &_Timesync_pub);

		// apply timestamp offset
		sync_timestamp_of_incoming_data(st);

		_Timesync_pub.publish(&st);
	}
	break;

	case 2: { // SensorCombined publisher
		SensorCombined_msg_t st;
		eprosima::fastcdr::FastBuffer cdrbuffer(data_buffer, len);
		eprosima::fastcdr::Cdr cdr_des(cdrbuffer);
		st.deserialize(cdr_des);

		// apply timestamp offset
		sync_timestamp_of_incoming_data(st);

		_SensorCombined_pub.publish(&st);
	}
	break;

	case 3: { // VehicleAttitude publisher
		VehicleAttitude_msg_t st;
		eprosima::fastcdr::FastBuffer cdrbuffer(data_buffer, len);
		eprosima::fastcdr::Cdr cdr_des(cdrbuffer);
		st.deserialize(cdr_des);

		// apply timestamp offset
		sync_timestamp_of_incoming_data(st);

		_VehicleAttitude_pub.publish(&st);
	}
	break;

	case 4: { // VehicleLocalPosition publisher
		VehicleLocalPosition_msg_t st;
		eprosima::fastcdr::FastBuffer cdrbuffer(data_buffer, len);
		eprosima::fastcdr::Cdr cdr_des(cdrbuffer);
		st.deserialize(cdr_des);

		// apply timestamp offset
		sync_timestamp_of_incoming_data(st);

		_VehicleLocalPosition_pub.publish(&st);
	}
	break;

	case 13: { // TimesyncStatus publisher
		TimesyncStatus_msg_t st;
		eprosima::fastcdr::FastBuffer cdrbuffer(data_buffer, len);
		eprosima::fastcdr::Cdr cdr_des(cdrbuffer);
		st.deserialize(cdr_des);

		// apply timestamp offset
		sync_timestamp_of_incoming_data(st);

		_TimesyncStatus_pub.publish(&st);
	}
	break;

	case 15: { // VehicleStatus publisher
		VehicleStatus_msg_t st;
		eprosima::fastcdr::FastBuffer cdrbuffer(data_buffer, len);
		eprosima::fastcdr::Cdr cdr_des(cdrbuffer);
		st.deserialize(cdr_des);

		// apply timestamp offset
		sync_timestamp_of_incoming_data(st);

		_VehicleStatus_pub.publish(&st);
	}
	break;

	case 17: { // BatteryStatus publisher
		BatteryStatus_msg_t st;
		eprosima::fastcdr::FastBuffer cdrbuffer(data_buffer, len);
		eprosima::fastcdr::Cdr cdr_des(cdrbuffer);
		st.deserialize(cdr_des);

		// apply timestamp offset
		sync_timestamp_of_incoming_data(st);

		_BatteryStatus_pub.publish(&st);
	}
	break;

	default:
		printf("\033[1;33m[   micrortps_agent   ]\tUnexpected topic ID '%hhu' to publish. Please make sure the agent is capable of parsing the message associated to the topic ID '%hhu'\033[0m\n",
		       topic_ID, topic_ID);
		break;
	}
}
template <typename T>
void RtpsTopics::sync_timestamp_of_outgoing_data(T &msg) {
	uint64_t timestamp = getMsgTimestamp(&msg);
	uint64_t timestamp_sample = getMsgTimestampSample(&msg);
	_timesync->addOffset(timestamp);
	setMsgTimestamp(&msg, timestamp);
	_timesync->addOffset(timestamp_sample);
	setMsgTimestampSample(&msg, timestamp_sample);
}

bool RtpsTopics::getMsg(const uint8_t topic_ID, eprosima::fastcdr::Cdr &scdr)
{
	bool ret = false;

	switch (topic_ID) {

	case 1: // Timesync subscriber
		if (_Timesync_sub.hasMsg()) {
			Timesync_msg_t msg = _Timesync_sub.getMsg();

			// apply timestamp offset
			sync_timestamp_of_outgoing_data(msg);

			msg.serialize(scdr);
			ret = true;

			_Timesync_sub.unlockMsg();
		}

		break;

	case 5: // OffboardControlMode subscriber
		if (_OffboardControlMode_sub.hasMsg()) {
			OffboardControlMode_msg_t msg = _OffboardControlMode_sub.getMsg();

			// apply timestamp offset
			sync_timestamp_of_outgoing_data(msg);

			msg.serialize(scdr);
			ret = true;

			_OffboardControlMode_sub.unlockMsg();
		}

		break;

	case 6: // VehicleLocalPositionSetpoint subscriber
		if (_VehicleLocalPositionSetpoint_sub.hasMsg()) {
			VehicleLocalPositionSetpoint_msg_t msg = _VehicleLocalPositionSetpoint_sub.getMsg();

			// apply timestamp offset
			sync_timestamp_of_outgoing_data(msg);

			msg.serialize(scdr);
			ret = true;

			_VehicleLocalPositionSetpoint_sub.unlockMsg();
		}

		break;

	case 8: // VehicleCommand subscriber
		if (_VehicleCommand_sub.hasMsg()) {
			VehicleCommand_msg_t msg = _VehicleCommand_sub.getMsg();

			// apply timestamp offset
			sync_timestamp_of_outgoing_data(msg);

			msg.serialize(scdr);
			ret = true;

			_VehicleCommand_sub.unlockMsg();
		}

		break;

	case 9: // VehicleAttitudeSetpoint subscriber
		if (_VehicleAttitudeSetpoint_sub.hasMsg()) {
			VehicleAttitudeSetpoint_msg_t msg = _VehicleAttitudeSetpoint_sub.getMsg();

			// apply timestamp offset
			sync_timestamp_of_outgoing_data(msg);

			msg.serialize(scdr);
			ret = true;

			_VehicleAttitudeSetpoint_sub.unlockMsg();
		}

		break;

	case 10: // VehicleRatesSetpoint subscriber
		if (_VehicleRatesSetpoint_sub.hasMsg()) {
			VehicleRatesSetpoint_msg_t msg = _VehicleRatesSetpoint_sub.getMsg();

			// apply timestamp offset
			sync_timestamp_of_outgoing_data(msg);

			msg.serialize(scdr);
			ret = true;

			_VehicleRatesSetpoint_sub.unlockMsg();
		}

		break;

	case 11: // VehicleOdometry subscriber
		if (_VehicleOdometry_sub.hasMsg()) {
			VehicleOdometry_msg_t msg = _VehicleOdometry_sub.getMsg();

			// apply timestamp offset
			sync_timestamp_of_outgoing_data(msg);

			msg.serialize(scdr);
			ret = true;

			_VehicleOdometry_sub.unlockMsg();
		}

		break;

	case 14: // SensorGps subscriber
		if (_SensorGps_sub.hasMsg()) {
			SensorGps_msg_t msg = _SensorGps_sub.getMsg();

			// apply timestamp offset
			sync_timestamp_of_outgoing_data(msg);

			msg.serialize(scdr);
			ret = true;

			_SensorGps_sub.unlockMsg();
		}

		break;

	case 16: // ManualControlSetpoint subscriber
		if (_ManualControlSetpoint_sub.hasMsg()) {
			ManualControlSetpoint_msg_t msg = _ManualControlSetpoint_sub.getMsg();

			// apply timestamp offset
			sync_timestamp_of_outgoing_data(msg);

			msg.serialize(scdr);
			ret = true;

			_ManualControlSetpoint_sub.unlockMsg();
		}

		break;

	case 18: // GpsInjectData subscriber
		if (_GpsInjectData_sub.hasMsg()) {
			GpsInjectData_msg_t msg = _GpsInjectData_sub.getMsg();

			// apply timestamp offset
			sync_timestamp_of_outgoing_data(msg);

			msg.serialize(scdr);
			ret = true;

			_GpsInjectData_sub.unlockMsg();
		}

		break;

	case 19: // ExternalController subscriber
		if (_ExternalController_sub.hasMsg()) {
			ExternalController_msg_t msg = _ExternalController_sub.getMsg();

			// apply timestamp offset
			sync_timestamp_of_outgoing_data(msg);

			msg.serialize(scdr);
			ret = true;

			_ExternalController_sub.unlockMsg();
		}

		break;

	case 7: // TrajectorySetpoint subscriber
		if (_TrajectorySetpoint_sub.hasMsg()) {
			TrajectorySetpoint_msg_t msg = _TrajectorySetpoint_sub.getMsg();

			// apply timestamp offset
			sync_timestamp_of_outgoing_data(msg);

			msg.serialize(scdr);
			ret = true;

			_TrajectorySetpoint_sub.unlockMsg();
		}

		break;

	case 12: // VehicleVisualOdometry subscriber
		if (_VehicleVisualOdometry_sub.hasMsg()) {
			VehicleVisualOdometry_msg_t msg = _VehicleVisualOdometry_sub.getMsg();

			// apply timestamp offset
			sync_timestamp_of_outgoing_data(msg);

			msg.serialize(scdr);
			ret = true;

			_VehicleVisualOdometry_sub.unlockMsg();
		}

		break;

	default:
		printf("\033[1;33m[   micrortps_agent   ]\tUnexpected topic ID '%hhu' to getMsg. Please make sure the agent is capable of parsing the message associated to the topic ID '%hhu'\033[0m\n",
		       topic_ID, topic_ID);
		break;
	}

	return ret;
}
