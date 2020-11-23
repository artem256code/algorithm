#include <functional>
#include <iostream>

// Элемент списка с доп. полем "visited" 
template <class T>
struct Elem{
    T value;
    Elem *next;
    bool visited;
};

// Список 
template <class T>
class List{
private:
    Elem<T> *head;
    Elem<T> *bottom;
public:
    List<T>(): head(nullptr), bottom(nullptr) {};
    Elem<T> *getHead(){return head;}
    
    /**
     * @brief Добавляет элемент в начало списка
     * 
     * @param value - элемент для добавления
     */
    void addAtBeginning(T value){
        Elem<T> *new_value = new Elem<T>{value, nullptr}; 
        // Если список пуст
        if(head == nullptr){
            head = new_value;
            bottom = new_value;
        }
        //Если один элемент
        else if(head->next == nullptr){
            head->next = new_value;
            bottom = new_value;
        }
        else{
            new_value->next = head->next;
            head->next = new_value;
        }
    }


    /**
     * @brief Добавляет элемент в конец списка
     * 
     * @param value - элемент для добавления
     */
    void addAtEnd(T value){
        Elem<T> *new_value = new Elem<T>{value, nullptr}; 
        // Если список пуст
        if(head == nullptr){
            head = new_value;
            bottom = new_value;
        }
        else{
            bottom->next = new_value;
            bottom = new_value;
        }
    }


    /**
     * @brief Удаляет ячейку в списке последующию после 'after_me'
     * 
     * @param after_me - ячейка, после которой будет удалена ячейка
     */
    void deleteAfter(Elem<T> *after_me){
        if(after_me != nullptr && after_me->next != nullptr){
            if(after_me->next != bottom){
                Elem<T> *tmp = after_me->next;
                after_me->next = after_me->next->next;
                delete [] tmp;
            }
            else{
                Elem<T> *tmp = bottom;
                bottom = head;
                head->next = nullptr;
                delete [] tmp;
            }
        }
    }   


    /**
     * @brief Распечатывает список на консоли
     * 
     */
    void print(){
        Elem<T> *tmp = head;
        while(tmp != nullptr){
            std::cout << tmp->value << " ";
            tmp = tmp->next;
        }
        std::cout << std::endl;
    }
public:

};

int main(){
    List<int> list;

    list.addAtBeginning(10);
    list.addAtBeginning(20);
    list.addAtBeginning(30);
    list.addAtEnd(40);
    list.addAtEnd(50);
    list.addAtEnd(60);
    list.deleteAfter(list.getHead());

    list.print();

    return 0;
}