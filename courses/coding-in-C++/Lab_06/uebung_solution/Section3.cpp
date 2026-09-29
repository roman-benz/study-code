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
    void turn_on(){
        this->power_status = true;
        std::cout << "Device has been turned on" << std::endl;
    };
    void turn_of(){
        this->power_status = false;
        std::cout << "Device has been turned off" << std::endl;
    };
    void print_info(){
        std::cout << "Name: " << name << std::endl;
        std::cout << "Type: " << type << std::endl;
        std::cout << "Power Status: " << power_status << std::endl;
    };
    std::string get_name(){
        return this->name;
    };
    ~Device(){
        std::cout << "This device has been destroyed" << std::endl;
    }

};

class SharedDevice : public Device {
private:
    std::string ip_address;
    bool network_status;

public:
    void connect_to_network(){
        this->network_status = true;
        std::cout << "Device is connected to network" << std::endl;
    }
    void disconnect_from_network(){
        this->network_status = false;
        std::cout << "Device has been disconnected from network" << std::endl;
    }
    void print_network_info(){
        if (network_status == true)
        {
            std::cout << "Device is connected to network." << std::endl;
        }
        else{
            std::cout << "Device is not connected to network." << std::endl;
        }
        
    }
};

class Room{
private:
    std::string name;
    std::vector<std::unique_ptr<Device>> devices;
    std::vector<std::shared_ptr<Device>> shared_devices;

public:
    void add_device(std::unique_ptr<Device> &device){
        devices.push_back(std::move(device));
    };
    bool remove_device_by_name(std::string &name){
        for(auto it = devices.begin(); it != devices.end(); ++it){
            if ((*it)->get_name() == name)
            {
                std::erase(devices, *it);
                return true;
                break;
            }
            
        }
        return false;
    };
    void print_devices(){
        for (auto &device : devices)
        {
            (*device).print_info();
        }
        
    }
    void add_shared_device(std::shared_ptr<Device> &device){
        shared_devices.push_back(device);
    }
    void print_shared_devices(){
        for (auto &device : shared_devices)
        {
            (*device).print_info();
        }
    }
};



int main(void){

}