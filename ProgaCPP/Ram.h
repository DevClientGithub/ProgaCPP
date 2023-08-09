#pragma once

#include <windows.h>

class Ram {
private:
    SIZE_T totalPhysicalMemory;
    MEMORYSTATUSEX memoryStatus;

public:
    // �������� ����� ����� ������ � ������ �������� ��������� ������
    Ram() {
        memoryStatus.dwLength = sizeof(memoryStatus);
        GlobalMemoryStatusEx(&memoryStatus);
        totalPhysicalMemory = memoryStatus.ullTotalPhys;
    }

    // ������ ������� ������ ������ � ���������
    double GetMemoryUsagePercentage() {
        return (1.0 - static_cast<double>(memoryStatus.ullAvailPhys) / totalPhysicalMemory) * 100.0;
    }

    // ������ ������� ������ ������ � ���� ������
    double GetMemoryUsedGB() {
        return (static_cast<double>(totalPhysicalMemory - memoryStatus.ullAvailPhys) / (1024 * 1024 * 1024));
    }

    // ������ ������� ������ ������ � ���� ������
    double GetMemoryUsedMB() {
        return (static_cast<double>(totalPhysicalMemory - memoryStatus.ullAvailPhys) / (1024 * 1024));
    }

    // ���������� ����� ����� ������ � ������
    SIZE_T GetTotalPhysicalMemory() {
        return totalPhysicalMemory;
    }
};