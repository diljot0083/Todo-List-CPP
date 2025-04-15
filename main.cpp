#include<iostream>
#include"task.h"
#include<string>
#include<conio.h>

void greeting(){

    system("cls");

    std::cout <<"=============================================\n";
    std::cout <<"|                 TO DO LIST                |\n";
    std::cout <<"=============================================\n";

    std::cout <<  "\033[33m" << "1. " << "\033[0m" << "Add Task \n";
    std::cout <<  "\033[33m" << "2. " << "\033[0m" << "Remove Task \n";
    std::cout <<  "\033[33m" << "3. " << "\033[0m" << "Mark Task as Completed \n";
    std::cout <<  "\033[33m" << "4. " << "\033[0m" << "View Tasks \n";
    std::cout <<  "\033[33m" << "5. " << "\033[0m" << "Delete All Tasks \n";
    std::cout <<  "\033[33m" << "6. " << "\033[0m" << "Exit \n";

    std::cout <<"---------------------------------------------\n";
    
    std::string choice;
    while(true){
        std::cout<<"Enter Your Choice: ";
        getline(std::cin, choice);

        if(choice.length() != 1 || !(choice > "0" && choice < "7")){
            std::cout <<  "\033[31m" << "Invalid Choice !!!" << "\033[0m";
            getch();
            std::cout<<"\33[2K\r";
            std::cout<<"\033[A";
            std::cout<<"\033[2K\r";
        }
        else break;
        
    }


    task t;

    if(choice == "1"){
        t.addTask();
    }

    if(choice == "2"){
        t.removeTask();
    }


    if(choice == "3"){
        t.markComplete();
    }

    if(choice == "4"){
        t.viewTasks();
    }

    if(choice == "5"){
        t.deleteAll();
    }

    if(choice == "6"){
        std::cout <<"---------------------------------------------\n";
        std::cout<< "\033[32m" <<"Thank you for using the application.\n" <<"\033[0m";
        getch();
        return;
    }

    greeting();
}

int main(){

    greeting();

}
