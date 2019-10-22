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

#ifndef __REED_H__
#define __REED_H__

#include <Arduino.h>

#include "hdk.h"
#include "configs.h"


class IReed
{
public:
    virtual bool readState(uint8_t sensor) = 0;
    virtual void setLastState(uint8_t sensor, bool state) = 0;
    virtual bool getLastState(uint8_t sensor) = 0;
};


class Reed: public IReed
{
public:
    Reed(const std::shared_ptr<IHdk> &hdk);

    /*
     * @breif Reading current reed state
     * 
     * @param [in] sensor sensor number
     * 
     * @returns current state
     */
    bool readState(uint8_t sensor);

    /*
     * @breif Set new reed state
     * 
     * @param [in] sensor sensor number
     * @param [in] state New state
     */
    void setLastState(uint8_t sensor, bool state);

    /*
     * @breif Get last reed state
     * 
     * @returns last state
     */
    bool getLastState(uint8_t sensor);

private:
    const std::shared_ptr<IHdk> hdk_;
    bool states_[CFG_SENSORS_COUNT];
    uint8_t pins_[CFG_SENSORS_COUNT];
};


#endif
