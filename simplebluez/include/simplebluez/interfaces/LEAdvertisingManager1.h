#pragma once

#include <simpledbus/advanced/Interface.h>
#include <simpledbus/advanced/Property.h>

#include <optional>
#include <string>
#include <vector>

namespace SimpleBluez {

class LEAdvertisingManager1 : public SimpleDBus::Interface {
  public:
    // ----- TYPES -----


    // ----- CONSTRUCTORS -----
    LEAdvertisingManager1(std::shared_ptr<SimpleDBus::Connection> conn, std::string path);
    virtual ~LEAdvertisingManager1() = default;

    // ----- METHODS -----
    void RegisterAdvertisement(std::string advertisement_path);
    void UnregisterAdvertisement(std::string advertisement_path);


    // ----- PROPERTIES -----
    SimpleDBus::Property<uint8_t> ActiveInstances = create_property<uint8_t>("ActiveInstances");
    SimpleDBus::Property<uint8_t> SupportedInstances = create_property<uint8_t>("SupportedInstances");
    SimpleDBus::Property<std::vector<std::string>> SupportedIncludes = create_property<std::vector<std::string>>("SupportedIncludes");

  protected:
    void property_changed(std::string option_name) override;
};

}  // namespace SimpleBluez