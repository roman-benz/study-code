#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

class Device{
private:
    std::string name;
    std::string type;
    bool power_status = false;
public:
    Device(std::string name, std::string type) : name(name), type(type){};
    std::string get_name(){
        return this->name;
    }
    void turn_on(){
        this->power_status = true;
    }
    void turn_off(){
        this->power_status = false;
    }
    void print_info(){
        std::cout << name << " | " << type << " | " << power_status << std::endl;
    }
    ~Device(){
        std::cout << "Device has been destroyed" << std::endl;
    }
};

class Room{
private:
    std::string name;
    std::vector<std::unique_ptr<Device>> devices;
public:
    Room(std::string name) : name(name){};
    void add_device(std::unique_ptr<Device> &device){
        devices.push_back(std::move(device));
    };
    void remove_device_by_name(std::string name){
        for (auto& device : devices)
        {
            if (device->get_name() == name)
            {
                devices.erase(std::remove(devices.begin(), devices.end(), device), devices.end());
            }
            
        }
        
    }
};

int main(void){
    Room esszimmer("esszimmer");
    Room wohnzimmer("wohnzimmer");

    auto jbl = std::make_unique<Device>("Hi", "speaker");
    esszimmer.add_device(jbl);

}