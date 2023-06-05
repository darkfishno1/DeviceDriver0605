#pragma once
#include "FlashMemoryDevice.h"

class DeviceDriver
{
public:
    DeviceDriver(FlashMemoryDevice* hardware);
    int read(long address);
    void write(long address, int data);

public:
    FlashMemoryDevice* m_hardware;
public:
    const int TotalReadTryCount = 5;
};