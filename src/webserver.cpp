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

#include <Arduino.h>
#include <functional>
#include <ESP8266WiFi.h>

#include "webserver.h"
#include "configs.h"


WebServer::WebServer(const std::shared_ptr<ESP8266WebServer> &server,
                     const std::shared_ptr<IReed> &reed,
                     const std::shared_ptr<IAlarm> &alarm):
                     server_(std::move(server)),
                     reed_(std::move(reed)),
                     alarm_(std::move(alarm))
{
}

void WebServer::start()
{
    server_->on("/", std::bind(&WebServer::indexHandler, this));
    server_->on("/secure", std::bind(&WebServer::secureHandler, this));
    server_->on("/alarm", std::bind(&WebServer::alarmHandler, this));
    server_->onNotFound(std::bind(&WebServer::notFoundHandler, this));
    server_->begin();
}

void WebServer::process()
{
    server_->handleClient();
}

/*
 * Private functions
 */

String WebServer::getDevId()
{
    String id = "";

    for (auto c : WiFi.macAddress())
        if (c != ':')
            id += c;
    id.toLowerCase();

    return id;
}

void WebServer::indexHandler()
{
    String response;

    response = "{\"module\":\"secure\",\"id\":\"" + getDevId() +
               "\",\"board\":\"" + CFG_BOARD_NAME + "\"}";

    server_->send(WEB_SERVER_RESPONSE_OK, "application/json", response);
}

void WebServer::secureHandler()
{
    String  response;
    uint8_t chan = static_cast<uint8_t>(server_->arg("chan").toInt());

    if (reed_->getLastState(chan))
        response = "{\"state\":true}";
    else
        response = "{\"state\":false}";

    server_->send(WEB_SERVER_RESPONSE_OK, "application/json", response);
}

void WebServer::alarmHandler()
{
    String  response;
    String state = server_->arg("state");

    if (state == "true")
        alarm_->switchOn();
    else
        alarm_->switchOff();

    server_->send(WEB_SERVER_RESPONSE_OK, "application/json", response);
}

void WebServer::notFoundHandler()
{
    String response;

    response = "{\"module\":\"meteo\",\"error\":\"Not found\"}";

    server_->send(WEB_SERVER_RESPONSE_OK, "application/json", response);
}
