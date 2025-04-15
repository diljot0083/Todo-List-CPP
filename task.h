#include<iostream>

class task{
    private:
    std::string id;
    std::string name;
    std::string duedate;
    std::string completed;

    public:

    void addTask();
    void removeTask();
    void updateTask();
    void markComplete();
    void viewTasks();
    void deleteAll();

};

struct tasks{
    std::string id;
    std::string name;
    std::string duedate;
    std::string completed;
};