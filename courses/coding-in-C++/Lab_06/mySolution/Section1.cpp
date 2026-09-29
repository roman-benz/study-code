#include <iostream>
#include <stdexcept>

class ConfigLoader{
    private:
        std::string filename;
    public:
        void load(std::string filename){
            if (filename.empty())
            {
                throw std::invalid_argument("Filename is empty");
            }

            if (filename.length() < 4 || filename.substr(filename.length() - 4) != ".cfg")
            {
                throw std::invalid_argument("Wrong ending");
            }
            if (filename == "missing.cfg")
            {
                throw std::runtime_error("File not found");
            }
            if (filename == "invalid.cfg")
            {
                throw std::logic_error("Invalid file");
            }
            
            
            
            
            
        }
};

int main(void){
    ConfigLoader myConfig;
    try{
        myConfig.load("hallo.cpg");
    }
    catch(const std::invalid_argument &exception){
        std::cout << "Catch-Block 1" << exception.what() << std::endl;
    }
    catch(const std::exception& error){
        std::cout << "Error: " << error.what() << std::endl;
    }
    
}