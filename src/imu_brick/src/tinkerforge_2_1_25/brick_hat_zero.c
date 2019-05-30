/* ***********************************************************
 * This file was automatically generated on 2019-05-21.      *
 *                                                           *
 * C/C++ Bindings Version 2.1.25                             *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generators git repository on tinkerforge.com       *
 *************************************************************/


#define IPCON_EXPOSE_INTERNALS

#include "tinkerforge/brick_hat_zero.h"

#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif



#if defined _MSC_VER || defined __BORLANDC__
	#pragma pack(push)
	#pragma pack(1)
	#define ATTRIBUTE_PACKED
#elif defined __GNUC__
	#ifdef _WIN32
		// workaround struct packing bug in GCC 4.7 on Windows
		// http://gcc.gnu.org/bugzilla/show_bug.cgi?id=52991
		#define ATTRIBUTE_PACKED __attribute__((gcc_struct, packed))
	#else
		#define ATTRIBUTE_PACKED __attribute__((packed))
	#endif
#else
	#error unknown compiler, do not know how to enable struct packing
#endif

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetUSBVoltage_Request;

typedef struct {
	PacketHeader header;
	uint16_t voltage;
} ATTRIBUTE_PACKED GetUSBVoltage_Response;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetSPITFPErrorCount_Request;

typedef struct {
	PacketHeader header;
	uint32_t error_count_ack_checksum;
	uint32_t error_count_message_checksum;
	uint32_t error_count_frame;
	uint32_t error_count_overflow;
} ATTRIBUTE_PACKED GetSPITFPErrorCount_Response;

typedef struct {
	PacketHeader header;
	uint8_t mode;
} ATTRIBUTE_PACKED SetBootloaderMode_Request;

typedef struct {
	PacketHeader header;
	uint8_t status;
} ATTRIBUTE_PACKED SetBootloaderMode_Response;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetBootloaderMode_Request;

typedef struct {
	PacketHeader header;
	uint8_t mode;
} ATTRIBUTE_PACKED GetBootloaderMode_Response;

typedef struct {
	PacketHeader header;
	uint32_t pointer;
} ATTRIBUTE_PACKED SetWriteFirmwarePointer_Request;

typedef struct {
	PacketHeader header;
	uint8_t data[64];
} ATTRIBUTE_PACKED WriteFirmware_Request;

typedef struct {
	PacketHeader header;
	uint8_t status;
} ATTRIBUTE_PACKED WriteFirmware_Response;

typedef struct {
	PacketHeader header;
	uint8_t config;
} ATTRIBUTE_PACKED SetStatusLEDConfig_Request;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetStatusLEDConfig_Request;

typedef struct {
	PacketHeader header;
	uint8_t config;
} ATTRIBUTE_PACKED GetStatusLEDConfig_Response;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetChipTemperature_Request;

typedef struct {
	PacketHeader header;
	int16_t temperature;
} ATTRIBUTE_PACKED GetChipTemperature_Response;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED Reset_Request;

typedef struct {
	PacketHeader header;
	uint32_t uid;
} ATTRIBUTE_PACKED WriteUID_Request;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED ReadUID_Request;

typedef struct {
	PacketHeader header;
	uint32_t uid;
} ATTRIBUTE_PACKED ReadUID_Response;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetIdentity_Request;

typedef struct {
	PacketHeader header;
	char uid[8];
	char connected_uid[8];
	char position;
	uint8_t hardware_version[3];
	uint8_t firmware_version[3];
	uint16_t device_identifier;
} ATTRIBUTE_PACKED GetIdentity_Response;

#if defined _MSC_VER || defined __BORLANDC__
	#pragma pack(pop)
#endif
#undef ATTRIBUTE_PACKED

void hat_zero_create(HATZero *hat_zero, const char *uid, IPConnection *ipcon) {
	DevicePrivate *device_p;

	device_create(hat_zero, uid, ipcon->p, 2, 0, 0);

	device_p = hat_zero->p;

	device_p->response_expected[HAT_ZERO_FUNCTION_GET_USB_VOLTAGE] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	device_p->response_expected[HAT_ZERO_FUNCTION_GET_SPITFP_ERROR_COUNT] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	device_p->response_expected[HAT_ZERO_FUNCTION_SET_BOOTLOADER_MODE] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	device_p->response_expected[HAT_ZERO_FUNCTION_GET_BOOTLOADER_MODE] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	device_p->response_expected[HAT_ZERO_FUNCTION_SET_WRITE_FIRMWARE_POINTER] = DEVICE_RESPONSE_EXPECTED_FALSE;
	device_p->response_expected[HAT_ZERO_FUNCTION_WRITE_FIRMWARE] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	device_p->response_expected[HAT_ZERO_FUNCTION_SET_STATUS_LED_CONFIG] = DEVICE_RESPONSE_EXPECTED_FALSE;
	device_p->response_expected[HAT_ZERO_FUNCTION_GET_STATUS_LED_CONFIG] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	device_p->response_expected[HAT_ZERO_FUNCTION_GET_CHIP_TEMPERATURE] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	device_p->response_expected[HAT_ZERO_FUNCTION_RESET] = DEVICE_RESPONSE_EXPECTED_FALSE;
	device_p->response_expected[HAT_ZERO_FUNCTION_WRITE_UID] = DEVICE_RESPONSE_EXPECTED_FALSE;
	device_p->response_expected[HAT_ZERO_FUNCTION_READ_UID] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	device_p->response_expected[HAT_ZERO_FUNCTION_GET_IDENTITY] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;

}

void hat_zero_destroy(HATZero *hat_zero) {
	device_release(hat_zero->p);
}

int hat_zero_get_response_expected(HATZero *hat_zero, uint8_t function_id, bool *ret_response_expected) {
	return device_get_response_expected(hat_zero->p, function_id, ret_response_expected);
}

int hat_zero_set_response_expected(HATZero *hat_zero, uint8_t function_id, bool response_expected) {
	return device_set_response_expected(hat_zero->p, function_id, response_expected);
}

int hat_zero_set_response_expected_all(HATZero *hat_zero, bool response_expected) {
	return device_set_response_expected_all(hat_zero->p, response_expected);
}


int hat_zero_get_api_version(HATZero *hat_zero, uint8_t ret_api_version[3]) {
	return device_get_api_version(hat_zero->p, ret_api_version);
}

int hat_zero_get_usb_voltage(HATZero *hat_zero, uint16_t *ret_voltage) {
	DevicePrivate *device_p = hat_zero->p;
	GetUSBVoltage_Request request;
	GetUSBVoltage_Response response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), HAT_ZERO_FUNCTION_GET_USB_VOLTAGE, device_p->ipcon_p, device_p);

	if (ret < 0) {
		return ret;
	}

	ret = device_send_request(device_p, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}

	*ret_voltage = leconvert_uint16_from(response.voltage);

	return ret;
}

int hat_zero_get_spitfp_error_count(HATZero *hat_zero, uint32_t *ret_error_count_ack_checksum, uint32_t *ret_error_count_message_checksum, uint32_t *ret_error_count_frame, uint32_t *ret_error_count_overflow) {
	DevicePrivate *device_p = hat_zero->p;
	GetSPITFPErrorCount_Request request;
	GetSPITFPErrorCount_Response response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), HAT_ZERO_FUNCTION_GET_SPITFP_ERROR_COUNT, device_p->ipcon_p, device_p);

	if (ret < 0) {
		return ret;
	}

	ret = device_send_request(device_p, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}

	*ret_error_count_ack_checksum = leconvert_uint32_from(response.error_count_ack_checksum);
	*ret_error_count_message_checksum = leconvert_uint32_from(response.error_count_message_checksum);
	*ret_error_count_frame = leconvert_uint32_from(response.error_count_frame);
	*ret_error_count_overflow = leconvert_uint32_from(response.error_count_overflow);

	return ret;
}

int hat_zero_set_bootloader_mode(HATZero *hat_zero, uint8_t mode, uint8_t *ret_status) {
	DevicePrivate *device_p = hat_zero->p;
	SetBootloaderMode_Request request;
	SetBootloaderMode_Response response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), HAT_ZERO_FUNCTION_SET_BOOTLOADER_MODE, device_p->ipcon_p, device_p);

	if (ret < 0) {
		return ret;
	}

	request.mode = mode;

	ret = device_send_request(device_p, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}

	*ret_status = response.status;

	return ret;
}

int hat_zero_get_bootloader_mode(HATZero *hat_zero, uint8_t *ret_mode) {
	DevicePrivate *device_p = hat_zero->p;
	GetBootloaderMode_Request request;
	GetBootloaderMode_Response response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), HAT_ZERO_FUNCTION_GET_BOOTLOADER_MODE, device_p->ipcon_p, device_p);

	if (ret < 0) {
		return ret;
	}

	ret = device_send_request(device_p, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}

	*ret_mode = response.mode;

	return ret;
}

int hat_zero_set_write_firmware_pointer(HATZero *hat_zero, uint32_t pointer) {
	DevicePrivate *device_p = hat_zero->p;
	SetWriteFirmwarePointer_Request request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), HAT_ZERO_FUNCTION_SET_WRITE_FIRMWARE_POINTER, device_p->ipcon_p, device_p);

	if (ret < 0) {
		return ret;
	}

	request.pointer = leconvert_uint32_to(pointer);

	ret = device_send_request(device_p, (Packet *)&request, NULL);

	return ret;
}

int hat_zero_write_firmware(HATZero *hat_zero, uint8_t data[64], uint8_t *ret_status) {
	DevicePrivate *device_p = hat_zero->p;
	WriteFirmware_Request request;
	WriteFirmware_Response response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), HAT_ZERO_FUNCTION_WRITE_FIRMWARE, device_p->ipcon_p, device_p);

	if (ret < 0) {
		return ret;
	}

	memcpy(request.data, data, 64 * sizeof(uint8_t));

	ret = device_send_request(device_p, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}

	*ret_status = response.status;

	return ret;
}

int hat_zero_set_status_led_config(HATZero *hat_zero, uint8_t config) {
	DevicePrivate *device_p = hat_zero->p;
	SetStatusLEDConfig_Request request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), HAT_ZERO_FUNCTION_SET_STATUS_LED_CONFIG, device_p->ipcon_p, device_p);

	if (ret < 0) {
		return ret;
	}

	request.config = config;

	ret = device_send_request(device_p, (Packet *)&request, NULL);

	return ret;
}

int hat_zero_get_status_led_config(HATZero *hat_zero, uint8_t *ret_config) {
	DevicePrivate *device_p = hat_zero->p;
	GetStatusLEDConfig_Request request;
	GetStatusLEDConfig_Response response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), HAT_ZERO_FUNCTION_GET_STATUS_LED_CONFIG, device_p->ipcon_p, device_p);

	if (ret < 0) {
		return ret;
	}

	ret = device_send_request(device_p, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}

	*ret_config = response.config;

	return ret;
}

int hat_zero_get_chip_temperature(HATZero *hat_zero, int16_t *ret_temperature) {
	DevicePrivate *device_p = hat_zero->p;
	GetChipTemperature_Request request;
	GetChipTemperature_Response response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), HAT_ZERO_FUNCTION_GET_CHIP_TEMPERATURE, device_p->ipcon_p, device_p);

	if (ret < 0) {
		return ret;
	}

	ret = device_send_request(device_p, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}

	*ret_temperature = leconvert_int16_from(response.temperature);

	return ret;
}

int hat_zero_reset(HATZero *hat_zero) {
	DevicePrivate *device_p = hat_zero->p;
	Reset_Request request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), HAT_ZERO_FUNCTION_RESET, device_p->ipcon_p, device_p);

	if (ret < 0) {
		return ret;
	}

	ret = device_send_request(device_p, (Packet *)&request, NULL);

	return ret;
}

int hat_zero_write_uid(HATZero *hat_zero, uint32_t uid) {
	DevicePrivate *device_p = hat_zero->p;
	WriteUID_Request request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), HAT_ZERO_FUNCTION_WRITE_UID, device_p->ipcon_p, device_p);

	if (ret < 0) {
		return ret;
	}

	request.uid = leconvert_uint32_to(uid);

	ret = device_send_request(device_p, (Packet *)&request, NULL);

	return ret;
}

int hat_zero_read_uid(HATZero *hat_zero, uint32_t *ret_uid) {
	DevicePrivate *device_p = hat_zero->p;
	ReadUID_Request request;
	ReadUID_Response response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), HAT_ZERO_FUNCTION_READ_UID, device_p->ipcon_p, device_p);

	if (ret < 0) {
		return ret;
	}

	ret = device_send_request(device_p, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}

	*ret_uid = leconvert_uint32_from(response.uid);

	return ret;
}

int hat_zero_get_identity(HATZero *hat_zero, char ret_uid[8], char ret_connected_uid[8], char *ret_position, uint8_t ret_hardware_version[3], uint8_t ret_firmware_version[3], uint16_t *ret_device_identifier) {
	DevicePrivate *device_p = hat_zero->p;
	GetIdentity_Request request;
	GetIdentity_Response response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), HAT_ZERO_FUNCTION_GET_IDENTITY, device_p->ipcon_p, device_p);

	if (ret < 0) {
		return ret;
	}

	ret = device_send_request(device_p, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}

	memcpy(ret_uid, response.uid, 8);
	memcpy(ret_connected_uid, response.connected_uid, 8);
	*ret_position = response.position;
	memcpy(ret_hardware_version, response.hardware_version, 3 * sizeof(uint8_t));
	memcpy(ret_firmware_version, response.firmware_version, 3 * sizeof(uint8_t));
	*ret_device_identifier = leconvert_uint16_from(response.device_identifier);

	return ret;
}

#ifdef __cplusplus
}
#endif
