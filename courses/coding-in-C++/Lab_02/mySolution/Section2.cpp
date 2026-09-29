#include <iostream>
class Note {
    private:
        std::string* text;
    public:
        Note(std::string neueNote){
            text = new std::string(neueNote);
        }
        Note(const Note& n){
            text = new std::string(*n.text);
        }
        ~Note(){
            delete text;
            std::cout << "Memory released" << std::endl;
        }
        void display(){
            std::cout << *text << std::endl;
        }

};

int main(void){
    Note note1("Servus");
    Note note2(note1);
    note1.~Note();
    note2.~Note();
}