#include"task.h"
#include<fstream>
#include<string>
#include<conio.h>
#include<vector>




// Add Task

std::string addOne(std:: string s){
    int num = std::stoi(s);
    num = num+1;
    return std::to_string(num);
}

bool checkDate(std::string duedate){

    std::string date = duedate.substr(0,2);
    if(stoi(date) < 1 || stoi(date) > 31) return false;

    std::string month = duedate.substr(3,2);
    if(stoi(month) < 1 || stoi(month) > 12) return false;

    std::string year = duedate.substr(6,2);
    if(stoi(year) < 10 || stoi(year) > 99) return false;

    return true;

}

void task::addTask(){

    system("cls");

    std::cout <<"=============================================\n";
    std::cout <<"|                ADD NEW TASK               |\n";
    std::cout <<"=============================================\n";

    std::ifstream filein;
    filein.open("id.txt", std::ios::in); 

    filein>>id;
    if(id.empty()) id = "1";
    filein.close(); 

 
    while(true){

        std::cout<<"Enter Task Name: ";
        getline(std::cin, name);
        
        if(name.empty()){
            std::cout <<  "\033[31m" << "Enter the name !!!" << "\033[0m";
            getch();
            std::cout<<"\33[2K\r";
            std::cout<<"\033[A";
            std::cout<<"\033[2K\r";
        }
        else break;

    }


    while(true){

        std::cout<<"Enter Due Date (DD-MM-YY): ";
        getline(std::cin, duedate);

        bool check = true;
        for(int i=0;i<duedate.size();i++){
            char ch = duedate[i];
            if(!(ch == '-' || (ch >= '0' && ch <='9'))){
                check = false;
                break;
            }
        }

        if(duedate.size() == 0) check = false;

        if(check) check = checkDate(duedate) && check;

        if(duedate.size() != 8 || !check){
            std::cout <<  "\033[31m" << "Enter correct date !!!" << "\033[0m";
            getch();
            std::cout<<"\33[2K\r";
            std::cout<<"\033[A";
            std::cout<<"\033[2K\r";
        }

        else break;
        
    }

    std::string confirm;
    while(true){

        std::cout<<"Confirm (Y/N): ";
        getline(std::cin, confirm);
        
        if(confirm.length() != 1 || !(confirm == "Y" || confirm == "y" || confirm == "N" || confirm == "n")){
            std::cout <<  "\033[31m" << "Enter Y or N !!!" << "\033[0m";
            getch();
            std::cout<<"\33[2K\r";
            std::cout<<"\033[A";
            std::cout<<"\033[2K\r";
        }
        else break;

    }
    
    if(confirm == "N" || confirm == "n"){
        std::cout <<"---------------------------------------------\n";
        std::cout <<"\033[32m"<<"Task not added !!!" << "\033[0m\n" ;
        std::cout <<"---------------------------------------------\n";
        getch();
        return;
    }

    std::cout <<"---------------------------------------------\n";
    std::cout <<"\033[32m"<<"Task added successfully !!!" << "\033[0m\n";
    std::cout <<"---------------------------------------------\n";

    std::ofstream fileout;
    fileout.open("tasks.txt", std::ios::app);
    fileout << name << "\n" << id << "\n" << duedate << "\n" << "Pending" << "\n";
    fileout.close();

    id = addOne(id);
    fileout.open("id.txt", std::ios::in);
    fileout << id;

    getch();
    filein.close();
    fileout.close();
}











// Remove Task

void task::removeTask(){


    system("cls");

    std::cout <<"=============================================\n";
    std::cout <<"|                REMOVE TASK                |\n";
    std::cout <<"=============================================\n";

    while(true){

        std::cout <<"Enter Task ID to Remove: ";
        getline(std::cin, id);

        bool check = true;
        for(int i=0;i<id.size();i++){
            char ch = id[i];
            if(!(ch >= '0' && ch <='9')){
                check = false;
                break;
            }
        }
        
        if(id.empty() || !check){
            std::cout <<  "\033[31m" << "Enter valid id !!!" << "\033[0m";
            getch();
            std::cout<<"\33[2K\r";
            std::cout<<"\033[A";
            std::cout<<"\033[2K\r";
        }
        else break;

    }

    std::vector<tasks> allTask;

    std::ifstream filein;
    filein.open("tasks.txt", std::ios::in);

    while(filein){
        tasks temp;
        getline(filein, temp.name);
        if(temp.name.size() == 0) break;
        getline(filein, temp.id);
        getline(filein, temp.duedate);
        getline(filein, temp.completed);
        allTask.push_back(temp);
    }

    std::ofstream fileout;
    fileout.open("tasks.txt", std::ios::out);

    bool found = false;
    for(auto it:allTask){
        if(it.id == id){
            found = true;
            continue;
        }
        fileout << it.name << "\n" << it.id << "\n" << it.duedate << "\n" << it.completed << "\n";
    }

    if(!found){
        std::cout <<"---------------------------------------------\n";
        std::cout <<"\033[31m"<<"Task not found !!!" << "\033[0m\n"; 
        std::cout <<"---------------------------------------------\n";
        getch();
        return;
    }

    std::cout <<"---------------------------------------------\n";
    std::cout <<"\033[32m"<<"Task removed successfully !!!" << "\033[0m\n"; 
    std::cout <<"---------------------------------------------\n";

    getch();
    filein.close();
    fileout.close();
}






// Mark Task as Completed

void task::markComplete(){

    system("cls");

    std::cout <<"=============================================\n";
    std::cout <<"|          MARK TASK AS COMPLETED           |\n";
    std::cout <<"=============================================\n";

    while(true){

        std::cout <<"Enter Task ID: ";
        getline(std::cin, id);

        bool check = true;
        for(int i=0;i<id.size();i++){
            char ch = id[i];
            if(!(ch >= '0' && ch <='9')){
                check = false;
                break;
            }
        }
        
        if(id.empty() || !check){
            std::cout <<  "\033[31m" << "Enter valid id !!!" << "\033[0m";
            getch();
            std::cout<<"\33[2K\r";
            std::cout<<"\033[A";
            std::cout<<"\033[2K\r";
        }
        else break;

    }

    std::vector<tasks> allTask;

    std::ifstream filein;
    filein.open("tasks.txt", std::ios::in);

    while(filein){
        tasks temp;
        getline(filein, temp.name);
        if(temp.name.size() == 0) break;
        getline(filein, temp.id);
        getline(filein, temp.duedate);
        getline(filein, temp.completed);
        allTask.push_back(temp);
    }

    std::ofstream fileout;
    fileout.open("tasks.txt", std::ios::out);

    bool found = false;
    for(auto it:allTask){
        if(it.id == id){
            found = true;
            fileout << it.name << "\n" << it.id << "\n" << it.duedate << "\n" << "Completed" << "\n";
            continue;
        }
        fileout << it.name << "\n" << it.id << "\n" << it.duedate << "\n" << it.completed << "\n";
    }

    if(!found){
        std::cout <<"---------------------------------------------\n";
        std::cout <<"\033[31m"<<"Task not found !!!" << "\033[0m\n"; 
        std::cout <<"---------------------------------------------\n";
        getch();
        return;
    }

    std::cout <<"---------------------------------------------\n";
    std::cout <<"\033[32m"<<"Task Marked as Completed !!!" << "\033[0m\n"; 
    std::cout <<"---------------------------------------------\n";

    filein.close();
    fileout.close();
    getch();

}







// View Tasks

void task::viewTasks(){

    system("cls");

    std::cout <<"=============================================\n";
    std::cout <<"|                 ALL TASKS                 |\n";
    std::cout <<"=============================================\n";


    std::vector<tasks> allTask;

    std::ifstream filein;
    filein.open("tasks.txt", std::ios::in);

    while(filein){
        tasks temp;
        getline(filein, temp.name);
        if(temp.name.size() == 0) break;
        getline(filein, temp.id);
        getline(filein, temp.duedate);
        getline(filein, temp.completed);
        allTask.push_back(temp);
    }

    if(allTask.empty()){
        std::cout <<"\033[32m"<<"Add Some Tasks To See Here !!!" << "\033[0m\n"; 
        std::cout <<"---------------------------------------------\n";
    }

    for(auto it:allTask){
        std::cout << "\033[33m" << "ID: " << "\033[32m" << it.id << "\033[0m" << "\n";
        std::cout << "\033[33m" << "Task: " << "\033[32m" << it.name << "\033[0m" << "\n";
        std::cout << "\033[33m" << "Due: " << "\033[32m" << it.duedate << "\033[0m" << "\n";
        if(it.completed == "Pending")
            std::cout << "\033[33m" << "Status: " << "\033[31m" << it.completed << "\033[0m" << "\n";
        else
            std::cout << "\033[33m" << "Status: " << "\033[32m" << it.completed << "\033[0m" << "\n";
        std::cout <<"---------------------------------------------\n";
    }


    filein.close();
    getch();

}






// Delete All Tasks

void task::deleteAll(){

    system("cls");

    std::cout <<"=============================================\n";
    std::cout <<"|             DELETE ALL TASKS              |\n";
    std::cout <<"=============================================\n";

    std::string confirm;
    while(true){

        std::cout<<"Confirm (Y/N): ";
        getline(std::cin, confirm);
        
        if(confirm.length() != 1 || !(confirm == "Y" || confirm == "y" || confirm == "N" || confirm == "n")){
            std::cout <<  "\033[31m" << "Enter Y or N !!!" << "\033[0m";
            getch();
            std::cout<<"\33[2K\r";
            std::cout<<"\033[A";
            std::cout<<"\033[2K\r";
        }
        else break;

    }

    if(confirm == "N" || confirm == "n"){
        std::cout <<"---------------------------------------------\n";
        std::cout <<"\033[32m"<<"Cancelling !!!" << "\033[0m\n" ;
        std::cout <<"---------------------------------------------\n";
        getch();
        return;
    }  

    std::ofstream file;
    file.open("tasks.txt", std::ios::out);
    file << "";
    file.close();

    file.open("id.txt", std::ios::out);
    file << "";
    file.close();

    
    std::cout <<"---------------------------------------------\n";
    std::cout <<"\033[32m"<<"All Tasks are Deleted !!!" << "\033[0m\n"; 
    std::cout <<"---------------------------------------------\n";

    getch();

}