#include <iostream>

class Note{
private:
    std::string* text;
public:
    Note(std::string notetext){
        text = new std::string(notetext);       
    }
    Note(const Note &otherNote){
        text = new std::string(*(otherNote.text));
    }
    ~Note(){
        delete text;
        std::cout << "Note has been deleted" << std::endl;
    }
    void display(){
        std::cout << *text << std::endl;
    };

};

int main(void){
    
    Note note1("Hi bro");
    Note note2 = note1;
    note1.display();
    note2.display();
}