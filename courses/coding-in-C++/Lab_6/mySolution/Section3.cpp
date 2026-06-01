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
    /**
     * @brief Constructs a Device with the given name and type.
     * @param[in] name Display name of the device.
     * @param[in] type Device category/model (e.g. "Bose").
     */
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
    /**
     * @brief Constructs a SharedDevice (a network-capable Device).
     * @param[in] name Display name of the device.
     * @param[in] type Device category/model.
     */
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
    /**
     * @brief Constructs a Room with the given name.
     * @param[in] name Display name of the room.
     */
    Room(std::string name) : name(name){};

    /**
     * @brief Takes sole ownership of a device and stores it in the room.
     * @param[in] device Unique pointer to the device; moved into the room.
     */
    void add_device(std::unique_ptr<Device> device){
        v_devices.push_back(std::move(device));

    }

    /**
     * @brief Adds a shared device to the room (ownership is shared).
     * @param[in] shared_device Shared pointer to the device.
     */
    void add_shared_device(std::shared_ptr<SharedDevice> shared_device){
        v_shared_devices.push_back(std::move(shared_device));

    }
    void print_shared_devices();
};

/**
 * @brief Powers the device on and reports the new state.
 */
void Device::turn_on(){
    power_status = true;
    std::cout << name << " has been turned on" << std::endl;
}

/**
 * @brief Powers the device off and reports the new state.
 */
void Device::turn_off(){
    power_status = false;
    std::cout << name << " has been turned off" << std::endl;
}

/**
 * @brief Prints the device's name, type and current power state to stdout.
 */
void Device::print_info(){
    std::cout << "Name: " << name << std::endl;
    std::cout << "Type: " << type << std::endl;
    std::cout << "Power: " << (power_status ? "on" : "off") << std::endl;
}

/**
 * @brief Marks the shared device as connected and prints its IP address.
 */
void SharedDevice::connect_to_network(){
    network_status = true;
    std::cout << "Connected to network (" << ip_adress << ")" << std::endl;
}

/**
 * @brief Marks the shared device as disconnected from the network.
 */
void SharedDevice::disconnect_from_network(){
    network_status = false;
    std::cout << "Disconnected from network" << std::endl;
}

/**
 * @brief Prints the shared device's IP address and connection state.
 */
void SharedDevice::print_network_info(){
    std::cout << "IP-Address: " << ip_adress << std::endl;
    std::cout << "Network: " << (network_status ? "connected" : "disconnected") << std::endl;
}

/**
 * @brief Prints info and network info for every shared device in the room.
 */
void Room::print_shared_devices(){
    std::cout << "Shared devices in " << name << ":" << std::endl;
    for (const auto &shared_device : v_shared_devices)
    {
        shared_device->print_info();
        shared_device->print_network_info();
    }
}

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