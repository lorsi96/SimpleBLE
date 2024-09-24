#include <simplebluez/Advertisement.h>

#include <iostream>

using namespace SimpleBluez;

Advertisement::Advertisement(std::shared_ptr<SimpleDBus::Connection> conn, const std::string& bus_name, const std::string& path)
    : Proxy(conn, bus_name, path) {
    std::cout << "Advertisement::Advertisement() --> Path: " << path << "\n";
    _interfaces.emplace(std::make_pair(
        "org.bluez.LEAdvertisement1", std::static_pointer_cast<SimpleDBus::Interface>(std::make_shared<LEAdvertisement1>(_conn, _path))));
    // Print all interfaces
    for (auto it = _interfaces.begin(); it != _interfaces.end(); it++) {
        std::cout << "Interface: " << it->first << std::endl;
    }
}

std::shared_ptr<LEAdvertisement1> Advertisement::le_advertisement1() { 
    return std::dynamic_pointer_cast<LEAdvertisement1>(interface_get("org.bluez.LEAdvertisement1")); }


void Advertisement::test_configure() {
    std::cout << "Advertisement::test_configure()" << std::endl;
    // le_advertisement1()->Discoverable.set(true);
    std::cout <<  "After discoverable" << std::endl;
    le_advertisement1()->TxPower.set(16);
    // le_advertisement1()->LocalName.set("Test Peripheral");
    // le_advertisement1()->ServiceUUIDs.set({"00000001-0000-1000-8000-00805f9b34fb"});
    // le_advertisement1()->ManufacturerData.set({{0x00, 0x01}, {0x02, 0x03}});
}
