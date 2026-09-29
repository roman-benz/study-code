#include <iostream>

class Note {
    private:
    std::string* text;
    public:
    Note(std::string text_input){
        text = new std::string;
        *text = text_input;
    };
    Note(const Note &otherNote){
        text = new std::string;
        *text = *(otherNote.text);
    }
    void display(){
        std::cout << *text;
    };
    ~Note(){
        delete text;
        std::cout << "Memory released";
    }

};

int main(void){
    Note note1("hallo man");
    Note note2 = note1;
    note1.display();
    note2.display();

}