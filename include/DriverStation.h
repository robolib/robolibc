/*
 * Copyright (c) 2015 Westwood Robotics <code.westwoodrobotics@gmail.com>
 * Copyright (c) 2015 Austin Reuland <amreuland@gmail.com>
 * 
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 * 
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 */

#ifndef DRIVERSTATION_H_
#define DRIVERSTATION_H_


#include <string.h>

#include "Task.h"
#include "HAL/HAL.hpp"

class DriverStation {
 public:
    virtual ~DriverStation();

    static DriverStation *getInstance();

    void waitForData();
    bool isNewControlData();
    bool hasModeChanged();

    static bool isDisabled();
    static bool isEnabled();
    static bool isAutonomous();
    static bool isTest();
    static bool isEStopped();
    static bool isFMSAttached();
    static bool isDSAttached();
    static bool isOperatorControl();
    static bool isSysActive();
    static bool isBrownedOut();


    static void reportError(std::string error);

 protected:
    DriverStation();


 private:
    static DriverStation *m_instance;

    static void initTask(DriverStation *ds);

    void run();

    Task m_task;
    SEMAPHORE_ID m_newControlData;
    MULTIWAIT_ID m_packetDataAvailableMultiWait;
    MUTEX_ID m_packetDataAvailableMutex;
    MULTIWAIT_ID m_waitForDataSem;
    MUTEX_ID m_waitForDataMutex;
};

#endif /* DRIVERSTATION_H_ */
