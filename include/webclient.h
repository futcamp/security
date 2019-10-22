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

#ifndef __WEB_CLIENT_H__
#define __WEB_CLIENT_H__

#include <Arduino.h>
#include <WiFiClient.h>
#include <ESP8266HTTPClient.h>
#include <memory>


class IWebClient
{
public:
    virtual bool sendRequest(const String &server, const String &api, const String &request, uint8_t chan) = 0;
};


class WebClient: public IWebClient
{
public:
    WebClient(const std::shared_ptr<WiFiClient> &client,
              const std::shared_ptr<HTTPClient> &http);

    /**
     * @breif Sending http request to web server
     * 
     * @param [in] server Server address
     * @param [in] api API version
     * @param [in] request Http request string
     * @param [in] chan sensor channel
     * 
     * @returns true If sended success
     * @returns false If fail to send
     */
    bool sendRequest(const String &server, const String &api, const String &request, uint8_t chan);

private:
    const std::shared_ptr<WiFiClient> client_;
    const std::shared_ptr<HTTPClient> http_;
};



#endif
