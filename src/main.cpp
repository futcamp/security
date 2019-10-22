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

#include "configs.h"
#include "hdk.h"
#include "reed.h"
#include "webclient.h"
#include "webserver.h"
#include "app.h"
#include "alarm.h"


auto hdk = std::make_shared<Hdk>();
auto client = std::make_shared<WiFiClient>();
auto http = std::make_shared<HTTPClient>();
auto server = std::make_shared<ESP8266WebServer>();
auto webClient = std::make_shared<WebClient>(client, http);
auto reed = std::make_shared<Reed>(hdk);
auto alarm = std::make_shared<Alarm>(hdk);
auto webServer = std::make_shared<WebServer>(server, reed, alarm);
auto app = std::make_shared<App>(hdk, reed, webClient, webServer, alarm);


void setup()
{
    app->start();
}

void loop()
{
    app->loop();
}
