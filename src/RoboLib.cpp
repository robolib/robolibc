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




#include "RoboLib.h"
#include "DriverStation.h"
#include "HAL/HAL.hpp"

class DriverStation;

RoboLib* RoboLib::m_instance = NULL;

RoboLib::RoboLib()
    : m_task(NULL) {
    RoboLib::setInstance(this);

    FILE *file = NULL;
    file = fopen("/tmp/frc_versions/FRC_Lib_Version.ini", "w");

    fputs("RoboLibC 0.0.1", file);
    if(file != NULL)
        fclose(file);

}

RoboLib::~RoboLib() {
    delete m_task;
    m_task = NULL;
    m_instance = NULL;
}

void RoboLib::setInstance(RoboLib* robot){
    m_instance = robot;
}

RoboLib &RoboLib::getInstance(){
    return *m_instance;
}

void RoboLib::runBot(RoboLib *robot){
    robot->run();
}

void RoboLib::run(){


    robotInit();

    HALNetworkCommunicationObserveUserProgramStarting();

    while(true){
        
    }

}
