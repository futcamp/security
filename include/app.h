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

#ifndef __APP_H__
#define __APP_H__

#include "webclient.h"
#include "webserver.h"
#include "reed.h"
#include "hdk.h"


#define CLIENT_MAX_RETRIES  5


class App
{
public:
    App(const std::shared_ptr<IHdk> &hdk,
        const std::shared_ptr<IReed> &reed,
        const std::shared_ptr<IWebClient> &client,
        const std::shared_ptr<IWebServer> &server,
        const std::shared_ptr<IAlarm> &alarm);

    /*
     * @breif Start application
     */
    void start();

    /*
     * @breif Main application loop
     */
    void loop();

private:
    const std::shared_ptr<IHdk> hdk_;
    const std::shared_ptr<IReed> reed_;
    const std::shared_ptr<IWebClient> client_;
    const std::shared_ptr<IWebServer> server_;
    const std::shared_ptr<IAlarm> alarm_;

    /*
     * @breif Send new state to server
     * 
     * @param sensor Sensor number
     */
    void sendChangeState(uint8_t sensor);
};


#endif
