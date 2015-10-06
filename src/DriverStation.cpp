/*
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

#include "DriverStation.h"

DriverStation::DriverStation() :
    m_task ("DriverStation JS Thread", (FUNCPTR) DriverStation::initTask),
    m_newControlData(0),
    m_packetDataAvailableMultiWait(0),
    m_packetDataAvailableMutex(0),
    m_waitForDataSem(0),
    m_waitForDataMutex(0){
        
}

DriverStation::~DriverStation() {
}


