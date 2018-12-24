//
// Created by evya on 12/23/18.
//

#ifndef UAV_PROJECT_XMLFORMAT_H
#define UAV_PROJECT_XMLFORMAT_H

#include <list>
#include <string>

static std::list<std::string> m_xmlHandler = {
        "airspeed-indicator_indicated-speed-kt",
        "/instrumentation/airspeed-indicator/indicated-speed-kt",
        "altimeter_indicated-altitude-ft",
        "/instrumentation/altimeter/indicated-altitude-ft",
        "altimeter_pressure-alt-ft",
        "/instrumentation/altimeter/pressure-alt-ft",
        "attitude-indicator_indicated-pitch-deg",
        "/instrumentation/attitude-indicator/indicated-pitch-deg",
        "attitude-indicator_indicated-roll-deg",
        "/instrumentation/attitude-indicator/indicated-roll-deg",
        "attitude-indicator_internal-pitch-deg",
        "/instrumentation/attitude-indicator/internal-pitch-deg",
        "attitude-indicator_internal-roll-deg",
        "/instrumentation/attitude-indicator/internal-roll-deg",
        "encoder_indicated-altitude-ft",
        "/instrumentation/encoder/indicated-altitude-ft",
        "encoder_pressure-alt-ft",
        "/instrumentation/encoder/pressure-alt-ft",
        "gps_indicated-altitude-f",
        "/instrumentation/gps/indicated-altitude-ft",
        "gps_indicated-altitude-f",
        "/instrumentation/gps/indicated-altitude-ft",
        "gps_indicated-ground-speed-kt",
        "/instrumentation/gps/indicated-ground-speed-kt",
        "gps_indicated-vertical-speed",
        "/instrumentation/gps/indicated-vertical-speed",
        "indicated-heading-deg",
        "/instrumentation/heading-indicator/indicated-heading-deg",
        "magnetic-compass_indicated-heading-deg",
        "/instrumentation/magnetic-compass/indicated-heading-deg",
        "slip-skid-ball_indicated-slip-skid",
        "/instrumentation/slip-skid-ball/indicated-slip-skid",
        "turn-indicator_indicated-turn-rate",
        "/instrumentation/turn-indicator/indicated-turn-rate",
        "vertical-speed-indicator_indicated-speed-fpm",
        "/instrumentation/vertical-speed-indicator/indicated-speed-fpm",
        "flight_aileron",
        "/controls/flight/aileron",
        "flight_elevator",
        "/controls/flight/elevator",
        "flight_rudder",
        "/controls/flight/rudde",
        "flight_flaps",
        "/controls/flight/flaps",
        "engine_throttle",
        "/controls/engines/engine/throttle",
        "engine_rpm",
        "/engines/engine/rpm"
};

#endif //UAV_PROJECT_XMLFORMAT_H
