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

#ifndef TASK_H_
#define TASK_H_

#include "Base.h"
#include "HAL/Task.hpp"

#define TASK_DEFAULT_PRIORITY 101


class Task {
public:
    Task(const char* name, FUNCPTR function,
         int32_t priority = TASK_DEFAULT_PRIORITY,
         uint32_t stackSize = 2000);

    virtual ~Task();

    bool start(uint32_t arg0 = 0, uint32_t arg1 = 0, uint32_t arg2 = 0,
            uint32_t arg3 = 0, uint32_t arg4 = 0, uint32_t arg5 = 0,
            uint32_t arg6 = 0, uint32_t arg7 = 0, uint32_t arg8 = 0,
            uint32_t arg9 = 0);
    bool restart();
    bool stop();
    bool isReady();
    bool isSuspended();
    bool suspend();
    bool resume();
    bool verify();
    int32_t getPriority();
    bool setPriority(int32_t priority);
    const char* getName();

    TASK getId();


private:
    FUNCPTR m_function;
    char* m_taskName;
    TASK m_taskId;
    uint32_t m_stackSize;
    int m_priority;
    bool handleError(STATUS results);

    DISALLOW_COPY_AND_ASSIGN(Task);

};

#endif /* TASK_H_ */
