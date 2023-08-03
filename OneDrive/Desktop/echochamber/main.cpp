#include <iostream>
#include <string>
#include <list>
#include <ctime>

class todoItem {
private:
    int id;
    std::string desc;
    bool completed;

public:
    todoItem() : id(0), desc(""), completed(false) {};
    ~todoItem() = default;

    bool create(std::string newDesc) {
        // fail safe
        id = rand() % 100 + 1;
        desc = newDesc;
        return true;
    }

    int getId() {return id;};
    std::string getDesc() {return desc;};
    bool isCompleted() {return completed;};

    void setCompleted(bool val) {completed = val;};
};

int main()
{
    char input_opt;
    int input_id;
    std::string input_desc;

    std::string version = "v0.0.1";
    std::list<todoItem> todoItems;
    std::list<todoItem>::iterator it;

    srand(time(NULL));

    todoItems.clear();

    
    while (1) 
    {
        system("cls");
        std::cout << "todo list maker - " << version << std::endl; 
        std::cout << std::endl << std::endl;

        for (it = todoItems.begin(); it != todoItems.end(); it++) 
        {
            std::string completed = it->isCompleted() ? "done" : "not done";

            std::cout << it->getId() << " | " << it-> getDesc() << " | " << completed << std::endl;
        };

        if (todoItems.empty()) {
            std::cout << "add something" <<std::endl;
        };

        std::cout << std::endl << std::endl;

        std::cout << "[a]dd a new todo" << std::endl;
        std::cout << "[c]omplete a todo" << std::endl;
        std::cout << "[q]uit" << std::endl;

        std::cout << "choice: ";
        std::cin >> input_opt;

        if (input_opt == 'q') 
        {
            std::cout << "gn!" << std::endl;
            break;
        } 

        else if (input_opt == 'a') 
        {
            std::cout << "add a new desc: ";
            std::cin.clear();
            std::cin.ignore();
            std::getline(std::cin, input_desc);

            todoItem newItem;
            newItem.create(input_desc);
            todoItems.push_back(newItem);
        } 

        else if (input_opt == 'c') 
        {
            std::cout << "enter id to mark: ";
            std::cin >> input_id;

            for (it = todoItems.begin(); it != todoItems.end(); it++) 
            {
                if (input_id == it->getId()) {
                    it->setCompleted(true);
                    break;
                } 
            };
        }

    }
    return 0;
}