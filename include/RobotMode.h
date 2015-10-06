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

#ifndef ROBOTMODE_H_
#define ROBOTMODE_H_

enum GameMode {
    NONE = 0,
    DISABLED = 1,
    TEST = 2,
    AUTONOMOUS = 3,
    TELEOP = 4
};

class RobotMode {
public:
    RobotMode();
    ~RobotMode();

    GameMode getModeType();
    bool isActive();
    void setActive();

    void modeInit();
    void modeRun();
    void modeEnd();


protected:

    virtual void init();
    virtual void run();
    virtual void end();



};




#endif /* ROBOTMODE_H_ */
