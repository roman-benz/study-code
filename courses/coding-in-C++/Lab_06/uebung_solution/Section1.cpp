#include <string>
#include <iostream>
#include <exception>

class ConfigLoader{
    private:

    public:
    void load(std::string filename){
        if (filename == "") 
        {
            throw std::invalid_argument("Filename is missing");
        }
        if (filename.substr(filename.size(), -4) != ".cfg")
        {
            throw std::runtime_error("Invalid file extension");
        }
        if (filename == "missing.cfg")
        {
            throw std::runtime_error("File cannot be opened");
        }
        if (filename == "invalid.cfg")
        {
            throw std::runtime_error("Invalid system-specific configuration!");
        }
         
    }
};

int main(void){
    ConfigLoader myConfig;
    try
    {
        myConfig.load("missing.cfg");
    }
    catch(const std::exception& e){
        std::cout << e.what() << std::endl;
    }
};