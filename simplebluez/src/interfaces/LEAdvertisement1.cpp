#include "simplebluez/interfaces/LEAdvertisement1.h"
#include <iostream>

using namespace SimpleBluez;

LEAdvertisement1::LEAdvertisement1(std::shared_ptr<SimpleDBus::Connection> conn, std::string path)
    : SimpleDBus::Interface(conn, "org.bluez", path, "org.bluez.LEAdvertisement1") {
        std::cout << "LEAdvertisement1::LEAdvertisement1() --> Path: " << path << "\n";

    }

void LEAdvertisement1::property_changed(std::string option_name) {


}
