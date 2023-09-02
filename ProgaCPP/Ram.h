#pragma once

#include <windows.h>
#include <string>

class Ram {
private:
    SIZE_T totalPhysicalMemory;
    MEMORYSTATUSEX memoryStatus;
    std::string computerName; // Имя компьютера
    std::string userName; // Имя пользователя

public:
    // Получает общий объем памяти и другие свойства системной памяти
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

    /*Показывает сколько весит переменная или же что-то другое в байтах
    Пример использования:
        int i = 1;
        Ram::showSize(i); */
    template<typename T>
    static void showSize(const T& obj) {
        std::cout << "Size of the object: " << sizeof(obj) << " bytes." << std::endl;
    }

    // Узнать имя компьютера
    std::string GetComputerName() {
        return computerName;
    }

    // Узнать имя пользователя
    std::string GetUserName() {
        return userName;
    }
};