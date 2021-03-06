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

#ifndef ROBOLIB_H_
#define ROBOLIB_H_

#include "Base.h"
#include "Task.h"
#include "RobotMode.h"

#define START_ROBOT_CLASS(_ClassName_) \
    int main() { \
        if(!HALInitialize()){std::cerr << "Could not Initialize HAL!" << std::endl; return -1;} \
        _ClassName_ *robot = new _ClassName_(); \
        RoboLib::run(); \
        return 0; \
    }

class RoboLib {

public:
    static RoboLib &getInstance();
    static void setInstance(RoboLib* robot);

    static void startRobotTask(FUNCPTR factory);
    static void robotTask(FUNCPTR factory, Task *task);
    static void run();
    static void runBot(RoboLib *robot);

    static void setRobotMode(GameMode *)

protected:
    virtual ~RoboLib();
    RoboLib();

    virtual void robotInit();

    Task *m_task;


private:
    static RoboLib *m_instance;

    static RobotMode m_modes[4];

    static GameMode m_currentMode;

    DISALLOW_COPY_AND_ASSIGN(RoboLib);
};

#endif /* ROBOLIB_H_ */
