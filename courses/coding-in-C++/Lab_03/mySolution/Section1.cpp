#include <iostream>
#include <vector>


class Content
{
private:
    int id;
    std::string type;
    std::string title;
public:
    Content(std::string title, std::string type) : title(title), type(type){};
    void setTitle(std::string title){
        this->title = title;
    }
    void setType(std::string type){
        this->type = type;
    }
    std::string getTitle(){
        return this->title;
    }
    std::string getType(){
        return this->type;
    }
};

class Lesson{
    private:
        std::string title;
        std::vector<Content>contents;
    public:
        // getter, setter
    Lesson(std::string title) : title(title){};
    void createContent(std::string title, std::string type){
        Content new_content = Content(title, type);
        contents.push_back(new_content);
    };
    void deleteContent(Content &content){
        std::erase(contents, content);
    };

};

class Course{
    private:
    std::string title;
    std::string description;
    std::vector<Lesson>lessons;
    public:
    void createLesson(std::string title){
        Lesson new_lesson = Lesson(title);
        lessons.push_back(new_lesson);
           
    }
    void deleteLesson(Lesson &lesson){
        std::erase(lessons, lesson);
    };
};

class Platform;

class User
{
private:
    std::string name;
    std::string address;
    std::vector<Platform*>platforms;
public:
    bool operator==(const User &other){
        return this->name == other.name && this->address == other.address;
    }
    void joinPlatform(Platform *platform); 
    void leavePlatform(Platform *platform);
};

class Platform{
    private:
    std::vector<User*>users;
    std::vector<Course>courses;
    public:
    void registerUser(User *user){
        users.push_back(user);
    }
    void deleteUser(User *user){
        std::erase(users, user);
    }
};

void User::joinPlatform(Platform *platform){
    platforms.push_back(platform);
    platform->registerUser(this);
}

void User::leavePlatform(Platform *platform){
    std::erase(platforms, platform);
    platform->deleteUser(this);
}
