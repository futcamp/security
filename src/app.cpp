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

#include "app.h"
#include "configs.h"


App::App(const std::shared_ptr<IHdk> &hdk,
         const std::shared_ptr<IReed> &reed,
         const std::shared_ptr<IWebClient> &client,
         const std::shared_ptr<IWebServer> &server,
         const std::shared_ptr<IAlarm> &alarm):
         hdk_(std::move(hdk)),
         reed_(std::move(reed)),
         client_(std::move(client)),
         server_(std::move(server)),
         alarm_(std::move(alarm))
{
}

void App::start()
{
    hdk_->connectWifi(CFG_WIFI_SSID, CFG_WIFI_PASSWD);
    server_->start();
}

void App::loop()
{
    bool curState;

    for (uint8_t i = 0; i < CFG_SENSORS_COUNT; i++)
    {
        curState = reed_->readState(i);
        if (curState != reed_->getLastState(i))
        {
            reed_->setLastState(i, curState);
            if (curState)
                sendChangeState(i);
        }
    }

    server_->process();
    alarm_->process();
}

void App::sendChangeState(uint8_t sensor)
{
    for (uint8_t r = 0; r < CLIENT_MAX_RETRIES; r++)
    {
        if (client_->sendRequest(CFG_SERVER, CFG_API_VER, "security/reed", sensor))
            break;
        else
            hdk_->sleep(500);
    }
}
