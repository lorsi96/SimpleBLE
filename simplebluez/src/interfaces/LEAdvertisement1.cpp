#include "simplebluez/interfaces/LEAdvertisement1.h"
#include <iostream>

using namespace SimpleBluez;

LEAdvertisement1::LEAdvertisement1(std::shared_ptr<SimpleDBus::Connection> conn, std::string path)
    : SimpleDBus::Interface(conn, "org.bluez", path, "org.bluez.LEAdvertisement1") {
        std::cout << "LEAdvertisement1::LEAdvertisement1() --> Path: " << path << "\n";
    }

void LEAdvertisement1::property_changed(std::string option_name) {
 std::cout << "LEAdvertisement1::property_changed() --> " << option_name << "\n";
}


void LEAdvertisement1::message_handle(SimpleDBus::Message& msg) {
    std::cout << "LEAdvertisement1::message_handle()" << std::endl;
    SimpleDBus::Message reply = SimpleDBus::Message::create_method_return(msg);
    if (msg.get_member() == "GetAll") {
        SimpleDBus::Holder options = SimpleDBus::Holder::create_dict();
        options.dict_append(SimpleDBus::Holder::Type::STRING, "Type", SimpleDBus::Holder::create_string("Peripheral"));
        reply.append_argument(options, "a{sv}");
    }
    _conn->send(reply);
}

void LEAdvertisement1::reply_error(SimpleDBus::Message& msg, const std::string& error_name, const std::string& error_message) {
    std::cout << "LEAdvertisement1::reply_error()" << std::endl;
    SimpleDBus::Message reply = SimpleDBus::Message::create_error(msg, error_name, error_message);
    _conn->send(reply);
}