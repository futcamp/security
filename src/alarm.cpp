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

#include "alarm.h"
#include "configs.h"


Alarm::Alarm(const std::shared_ptr<IHdk> &hdk):
             hdk_(std::move(hdk))
{
    alarmPin_ = CFG_SPEAKER_PIN;
    alarmState_ = false;

    hdk_->switchPinMode(alarmPin_, HDK_PIN_MODE_OUT);
}

void Alarm::switchOn()
{
    alarmState_ = true;
}

void Alarm::switchOff()
{
    alarmState_ = false;
}

void Alarm::process()
{
    if (alarmState_)
    {
        hdk_->pinHigh(alarmPin_);
        hdk_->sleep(250);
        hdk_->pinLow(alarmPin_);
        hdk_->sleep(250);
    }
    else
    {
        hdk_->pinLow(alarmPin_);
    }
}
