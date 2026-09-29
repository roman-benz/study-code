#include <iostream>
#include <vector>
#include <algorithm>

class Content{
private:
    const int ID;
    std::string type;
    std::vector<std::string> v_material;
public:
    Content(int id, std::string type): ID(id), type(type){};
    void addMaterial(const std::string &material){
        v_material.push_back(material);

    };
    void removeMaterial(const std::string &material){
        v_material.erase(std::remove(v_material.begin(), v_material.end(), material), v_material.end());
    };
};

class Lesson{
private:
    const int ID;
    std::vector<Content*> contents;
public:
    void addContent(Content* content){
        contents.push_back(content);
    }
    void removeContent(const Content* content){
        contents.erase(std::remove(contents.begin(), contents.end(), content), contents.end());
    }
};

class User{
private:
    const int ID;
    std::string name;

public:
    std::string getName() const {
        return this->name;
    }
    void enroll(Course )

};