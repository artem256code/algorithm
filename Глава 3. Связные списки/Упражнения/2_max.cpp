#include <functional>
#include <iostream>

// Элемент списка 
struct Elem{
    int value;
    Elem *next;
};

// Список 
class List{
private:
    Elem *head;
    Elem *bottom;
public:
    List(): head(nullptr), bottom(nullptr) {}


    /**
     * @brief   Добавляет элемент в конец списка
     * 
     * @param value - значение для добавления
     */
    void addToEnd(int value){
        Elem *new_elem = new Elem{value, nullptr};
        if(head == nullptr){
            head = new_elem;
            bottom = new_elem;
        }
        else{
            bottom->next = new_elem;
            bottom = new_elem;
        }
    }


    /**
     * @brief  Возвращает максимальное значение из списка 
     *         (Список должен содержать хотя бы 1 элемент!!!) 
     * @return int  -  максимальное значение
     */
    int getMax(){
        Elem *tmp = head;
        int max = tmp->value;
        while(tmp->next != nullptr){
            if(tmp->next->value > max) max = tmp->next->value;
            tmp = tmp->next;
        }
        return max;
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
    list.addToEnd(200);
    list.addToEnd(3);
    list.addToEnd(4);
    list.print();

    std::cout << "Max: " << list.getMax() << std::endl;
    return 0;
}