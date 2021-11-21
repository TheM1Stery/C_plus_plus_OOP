#include "Device.h"



Device::Device(const std::string& name, size_t id)
	: m_name(name), m_id(id) {}

void Device::on()
{
	m_state = true;
}

void Device::off()
{
	m_state = false;
}

std::string Device::get_current_state()
{
	if(m_state) return "ON";
	return "OFF";

}

std::string Device::name()
{
	return m_name;
}

size_t Device::id()
{
	return m_id;
}