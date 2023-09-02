#pragma once

#include <windows.h>
#include <string>

class Ram {
private:
    SIZE_T totalPhysicalMemory;
    MEMORYSTATUSEX memoryStatus;
    std::string computerName; // ��� ����������
    std::string userName; // ��� ������������

public:
    // �������� ����� ����� ������ � ������ �������� ��������� ������
    Ram() {
        memoryStatus.dwLength = sizeof(memoryStatus);
        GlobalMemoryStatusEx(&memoryStatus);
        totalPhysicalMemory = memoryStatus.ullTotalPhys;
        char buffer[MAX_COMPUTERNAME_LENGTH + 1];
        DWORD size = sizeof(buffer);
        GetComputerNameA(buffer, &size);
        computerName = buffer;
        size = sizeof(buffer);
        GetUserNameA(buffer, &size);
        userName = buffer;
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

    /*���������� ������� ����� ���������� ��� �� ���-�� ������ � ������
    ������ �������������:
        int i = 1;
        Ram::showSize(i); */
    template<typename T>
    static void showSize(const T& obj) {
        std::cout << "Size of the object: " << sizeof(obj) << " bytes." << std::endl;
    }

    // ������ ��� ����������
    std::string GetComputerName() {
        return computerName;
    }

    // ������ ��� ������������
    std::string GetUserName() {
        return userName;
    }
};