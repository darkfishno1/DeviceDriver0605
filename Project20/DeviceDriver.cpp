#include <Windows.h>
#include <exception>
#include "DeviceDriver.h"

DeviceDriver::DeviceDriver(FlashMemoryDevice* hardware) : m_hardware(hardware)
{}


int DeviceDriver::read(long address)
{
    // TODO: implement this method properly

    int firstReadTryValue = (int)(m_hardware->read(address));
    for(int tryCount = 1; tryCount < TotalReadTryCount; tryCount++)
    {
        int nextReadTryValue = (int)(m_hardware->read(address));
        if (firstReadTryValue == nextReadTryValue) continue;

    	throw std::exception("Exception!!");
        
    }

    return firstReadTryValue;

}

void DeviceDriver::write(long address, int data)
{
    // TODO: implement this method

    int readValue = (int)(m_hardware->read(address));
    if (readValue != 0xFF)
        throw std::exception("WriteFailException");

    m_hardware->write(address, (unsigned char)data);
}