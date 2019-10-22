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

#ifndef __CONFIGS_H__
#define __CONFIGS_H__

#define CFG_BOARD_ESP01
//#define CFG_BOARD_ESP8266

#define CFG_WIFI_SSID    ""
#define CFG_WIFI_PASSWD  ""

#define CFG_SERVER   "192.168.1.100:8080"
#define CFG_API_VER  "v3"

#ifdef CFG_BOARD_ESP8266
#define CFG_REED_PIN_1    D3
#define CFG_REED_PIN_2    D4

#define CFG_SPEAKER_PIN   A0

#define CFG_BOARD_NAME  "esp8266"
#endif

#ifdef CFG_BOARD_ESP01
#define CFG_REED_PIN_1    0
#define CFG_REED_PIN_2    2

#define CFG_SPEAKER_PIN   3

#define CFG_BOARD_NAME  "esp01"
#endif

#define CFG_SENSORS_COUNT 2


#endif
