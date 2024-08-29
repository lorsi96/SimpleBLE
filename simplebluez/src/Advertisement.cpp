#include <simplebluez/Advertisement.h>

#include <iostream>

using namespace SimpleBluez;

Advertisement::Advertisement(std::shared_ptr<SimpleDBus::Connection> conn, const std::string& bus_name, const std::string& path)
    : Proxy(conn, bus_name, path) {
    _interfaces.emplace(std::make_pair(
        "org.bluez.LEAdverisement1", std::static_pointer_cast<SimpleDBus::Interface>(std::make_shared<LEAdverisement1>(_conn, _path))));
}

std::shared_ptr<LEAdvertisement1> Advertisement::le_advertisement1() { 
    return std::dynamic_pointer_cast<LEAdvertisement1>(interface_get("org.bluez.LEAdvetisement1")); }
