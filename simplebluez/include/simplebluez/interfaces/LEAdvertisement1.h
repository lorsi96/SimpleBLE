#pragma once

#include <simpledbus/advanced/Interface.h>
#include <simpledbus/advanced/Property.h>

#include <optional>
#include <string>
#include <vector>

namespace SimpleBluez {

class LEAdvertisement1 : public SimpleDBus::Interface {
  public:
    // ----- TYPES -----


    // ----- CONSTRUCTORS -----
    LEAdvertisement1(std::shared_ptr<SimpleDBus::Connection> conn, std::string path);
    virtual ~LEAdvertisement1() = default;

    // ----- METHODS -----
    void RegisterAdvertisement(std::string advertisement_path);
    void UnregisterAdvertisement(std::string advertisement_path);

    // ----- PROPERTIES -----
    SimpleDBus::Property<std::string> Type = create_property<std::string>("Type");
    SimpleDBus::Property<std::vector<std::string>> ServiceUUIDs = create_property<std::vector<std::string>>("ServiceUUIDs");
    SimpleDBus::Property<std::map<uint16_t, std::vector<uint8_t>>> ManufacturerData = create_property<std::map<uint16_t, std::vector<uint8_t>>>("ManufacturerData");
    SimpleDBus::Property<std::vector<std::string>> SolicitUUIDs = create_property<std::vector<std::string>>("SolicitUUIDs");
    SimpleDBus::Property<std::map<std::string, std::vector<uint8_t>>> ServiceData = create_property<std::map<std::string, std::vector<uint8_t>>>("ServiceData");
    SimpleDBus::Property<std::map<std::string, std::vector<uint8_t>>> Data = create_property<std::map<std::string, std::vector<uint8_t>>>("Data");
    SimpleDBus::Property<bool> Discoverable = create_property<bool>("Discoverable");
    SimpleDBus::Property<uint16_t> DiscoverableTimeout = create_property<uint16_t>("DiscoverableTimeout");
    SimpleDBus::Property<std::vector<std::string>> Includes = create_property<std::vector<std::string>>("Includes");
    SimpleDBus::Property<std::string> LocalName = create_property<std::string>("LocalName");
    SimpleDBus::Property<uint16_t> Appearance = create_property<uint16_t>("Appearance");
    SimpleDBus::Property<uint16_t> Duration = create_property<uint16_t>("Duration");
    SimpleDBus::Property<uint16_t> Timeout = create_property<uint16_t>("Timeout");
    SimpleDBus::Property<std::string> SecondaryChannel = create_property<std::string>("SecondaryChannel");
    SimpleDBus::Property<uint32_t> MinInterval = create_property<uint32_t>("MinInterval");
    SimpleDBus::Property<uint32_t> MaxInterval = create_property<uint32_t>("MaxInterval");
    SimpleDBus::Property<int16_t> TxPower = create_property<int16_t>("TxPower");

  protected:
    void property_changed(std::string option_name) override;
    void message_handle(SimpleDBus::Message& msg) override;
    void reply_error(SimpleDBus::Message& msg, const std::string& error_name, const std::string& error_message);
};

}  // namespace SimpleBluez



