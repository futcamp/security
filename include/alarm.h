//*******************************************************************
//
// Future Camp Project
//
// Copyright(C) 2019 Sergey Denisov.
//
// Written by Sergey Denisov aka LittleBuster(DenisovS21@gmail.com)
// Github:  https://github.com/LittleBuster
//          https://github.com/futcamp
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public Licence 3
// as published by the Free Software Foundation; either version 3
// of the Licence, or(at your option) any later version.
//
//*******************************************************************

#ifndef __ALARM_H__
#define __ALARM_H__

#include <Arduino.h>

#include "hdk.h"
#include "configs.h"


class IAlarm
{
public:
    virtual void switchOn() = 0;
    virtual void switchOff() = 0;
    virtual void process() = 0;
};


class Alarm: public IAlarm
{
public:
    Alarm(const std::shared_ptr<IHdk> &hdk);

    /*
     * @breif Switch on alarm
     */
    void switchOn();

    /*
     * @breif Switch off alarm
     */
    void switchOff();

    /*
     * @breif Process alarm
     */
    void process();

private:
    const std::shared_ptr<IHdk> hdk_;
    uint8_t alarmPin_;
    bool alarmState_;
};


#endif