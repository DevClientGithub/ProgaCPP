#pragma once

#include <windows.h>

class Ram {
private:
    SIZE_T totalPhysicalMemory;
    MEMORYSTATUSEX memoryStatus;

public:
    // Получает общий объем памяти и другие свойства системной памяти
    Ram() {
        memoryStatus.dwLength = sizeof(memoryStatus);
        GlobalMemoryStatusEx(&memoryStatus);
        totalPhysicalMemory = memoryStatus.ullTotalPhys;
    }

    // Узнать сколько занято памяти в процентах
    double GetMemoryUsagePercentage() {
        return (1.0 - static_cast<double>(memoryStatus.ullAvailPhys) / totalPhysicalMemory) * 100.0;
    }

    // Узнать сколько занято памяти в Гига Байтах
    double GetMemoryUsedGB() {
        return (static_cast<double>(totalPhysicalMemory - memoryStatus.ullAvailPhys) / (1024 * 1024 * 1024));
    }

    // Узнать сколько занято памяти в Мега Байтах
    double GetMemoryUsedMB() {
        return (static_cast<double>(totalPhysicalMemory - memoryStatus.ullAvailPhys) / (1024 * 1024));
    }

    // Возвращает общий объём памяти в Байтах
    SIZE_T GetTotalPhysicalMemory() {
        return totalPhysicalMemory;
    }
};