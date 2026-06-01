#include <stdlib.h>
#include <iostream>
#include <vector>
#include <memory>

class Device {
private: 
    std::string name;
    std::string type;
    bool power_status = false;
public:
    Device(std::string name, std::string type) : name(name), type(type){};
    void turn_on();
    void turn_off();
    void print_info();

    virtual ~Device(){
        std::cout << "Device has been removed" << std::endl;
    }

};

class SharedDevice : public Device {
private: 
    std::string ip_adress = "127.0.0.1";
    bool network_status = true;
public:
    SharedDevice(std::string name,  std::string type) : Device(name, type){};
    void connect_to_network();
    void disconnect_from_network();
    void print_network_info();

};

class Room {
private: 
    std::string name;
    std::vector<std::unique_ptr<Device>> v_devices;
    std::vector<std::shared_ptr<SharedDevice>> v_shared_devices;
public:
    Room(std::string name) : name(name){};
    void add_device(std::unique_ptr<Device> device){
        v_devices.push_back(std::move(device));
        
    }
    void add_shared_device(std::shared_ptr<SharedDevice> shared_device){
        v_shared_devices.push_back(std::move(shared_device));
        
    }
    void print_shared_devices();    
};

int main(void){


    Room room1("Wohnzimmer");
    Room room2("Schlafzimmer");
    Room room3("Badezimmer");

    auto device1 = std::make_unique<Device>("Lautsprecher", "Bose");
    auto device_hub = std::make_shared<SharedDevice>("Bose Hub", "Multi-Device Hub");
    
    //Unique Device
    room1.add_device(std::move(device1));
    room2.add_device(std::move(device1));
    room3.add_device(std::move(device1));

    //Shared Device
    room1.add_shared_device(device_hub);
    room2.add_shared_device(device_hub);
    room3.add_shared_device(device_hub);
    
    //Check count
    std::cout << "DeviceHub: Use Count: " << device_hub.use_count() << std::endl;

    
}