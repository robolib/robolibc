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

#include <stdio.h>
#include <string.h>

#include "Task.h"


Task::Task(const char* name, FUNCPTR function, int32_t priority, uint32_t stackSize){
    m_taskId = NULL_TASK;
    m_function = function;
    m_priority = priority;
    m_stackSize = stackSize;
    m_taskName = new char[strlen(name) + 5];
    strcpy(m_taskName, "FRC_");
    strcpy(m_taskName + 4, name);

    static int32_t instances = 0;
    instances++;

}

bool Task::start(uint32_t arg0, uint32_t arg1, uint32_t arg2, uint32_t arg3,
        uint32_t arg4, uint32_t arg5, uint32_t arg6, uint32_t arg7,
        uint32_t arg8, uint32_t arg9){

    m_taskId = spawnTask(m_taskName, m_priority,
                         VXWORKS_FP_TASK, m_stackSize,
                         m_function, arg0, arg1, arg2, arg3,
                         arg4, arg5, arg6, arg7, arg8, arg9);

    if(m_taskId  == NULL_TASK){
        //handleerror(error);
        return false;
    }
    return true;

}

bool Task::restart(){
    return restartTask(m_taskId);
}

bool Task::stop(){
    bool ok = true;
    if(verify()){
        ok = deleteTask(m_taskId);
    }

    m_taskId = NULL_TASK;

    return ok;
}


Task::~Task(){
    if(m_taskId != NULL_TASK) stop();
    delete[] m_taskName;
    m_taskName = NULL;
}
