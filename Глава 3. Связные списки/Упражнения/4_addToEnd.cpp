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
     * @brief Добавляет элемент в конец двунаправленного связного списка
     *  
     * @param value - значение для добавления
     */
    void addToEnd(int value){
        Elem *new_elem = new Elem{value, nullptr, nullptr};
        if(head == nullptr){        // Если список пустой
            head = new_elem;
            bottom = new_elem;
        }
        else{
            bottom->next = new_elem;
            new_elem->prev = bottom;
            bottom = new_elem;
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
    list.addToEnd(1);
    list.addToEnd(2);
    list.addToEnd(3);
    list.addToEnd(4);
    list.print();
    return 0;
}