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

#include "webclient.h"


WebClient::WebClient(const std::shared_ptr<WiFiClient> &client,
                     const std::shared_ptr<HTTPClient> &http):
                     client_(std::move(client)),
                     http_(std::move(http))
{
}

bool WebClient::sendRequest(const String &server, const String &api, const String &request, uint8_t chan)
{
    int     httpCode;
    String  req;
    
    req = "http://" + server + "/api/" + api + "/" + request + "?chan=" + String(chan);

    http_->begin(*client_, req);
    httpCode = http_->PUT("");
    http_->end();

    if (httpCode == 200)
        return true;

    return false;
}
