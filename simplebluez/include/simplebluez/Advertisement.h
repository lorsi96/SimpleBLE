#pragma once

#include <simplebluez/interfaces/LEAdvertisement1.h>
#include <simpledbus/advanced/Proxy.h>

namespace SimpleBluez {

class Advertisement : public SimpleDBus::Proxy {
  public:
    Advertisement(std::shared_ptr<SimpleDBus::Connection> conn, const std::string& bus_name, const std::string& path);
    virtual ~Advertisement() = default;

    void test_configure();
    

  private:
    std::shared_ptr<LEAdvertisement1> le_advertisement1();
};

}  // namespace SimpleBluez
