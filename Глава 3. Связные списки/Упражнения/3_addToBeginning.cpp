#include <functional>
#include <iostream>

// Элемент двунаправленного связного списка 
struct Elem{
    int value;
    Elem *next;
    Elem *prev;
};

// Список 
class List{
private:
    Elem *head;
    Elem *bottom;
public:
    List(): head(nullptr), bottom(nullptr) {}

    /**
     * @brief Добавляет элемент в начало двунаправленного связаного списка
     * 
     * @param value - значение которое будует добавлено в начало
     */
    void addToBeginning(int value){
        Elem *new_value = new Elem{value, nullptr, nullptr};
        if(head == nullptr){        //Если список пустой
            head = new_value;
            bottom = new_value;
        }
        else{
            head->prev = new_value;
            new_value->next = head;
            head = new_value;
        }
    }

    /**
     * @brief Распечатывает список на консоли
     * 
     */
    void print(){
        Elem *tmp = head;
        while(tmp != nullptr){
            std::cout << tmp->value << " ";
            tmp = tmp->next;
        }
        std::cout << std::endl;
    }
public:

};

int main(){
    List list;
    list.addToBeginning(1);
    list.addToBeginning(2);
    list.addToBeginning(3);
    list.addToBeginning(4);
    list.print();
    return 0;
}