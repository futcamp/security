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

#include "reed.h"
#include "configs.h"


Reed::Reed(const std::shared_ptr<IHdk> &hdk):
           hdk_(std::move(hdk))
{
    pins_[0] = CFG_REED_PIN_1;
    pins_[1] = CFG_REED_PIN_2;

    hdk_->switchPinMode(pins_[0], HDK_PIN_MODE_IN);
    hdk_->switchPinMode(pins_[1], HDK_PIN_MODE_IN);
}

bool Reed::readState(uint8_t sensor)
{
    return hdk_->readPin(pins_[sensor]);
}

bool Reed::getLastState(uint8_t sensor)
{
    return states_[sensor];
}

void Reed::setLastState(uint8_t sensor, bool state)
{
    states_[sensor] = state;
}
