#include <iostream>

// Элемент двунаправленного связного списка 
template <class T>
struct Elem{
    T value;
    Elem *next;
    Elem *prev;
};

// Список 
template <class T>
class List{
private:
    Elem<T> *head;
    Elem<T> *bottom;

private:
    /**
     * @brief Вставляет элемент в двунаправленный список, после элемента "after_me" 
     * 
     * @param after_me - элемент, после которого будет произведена вставка
     * @param new_elem - новый элемент, который будет добавлен в список
     */
    void insertElem(Elem<T> *after_me, Elem<T> *new_elem){
        new_elem->next = after_me->next;
        after_me->next = new_elem;

        new_elem->next->prev = new_elem;
        new_elem->prev = after_me; 
    }
public:
    List<T>(T min_value, T max_value){
        Elem<T> *up_lim  = new Elem<T>{min_value, nullptr,  nullptr};
        Elem<T> *bot_lim = new Elem<T>{max_value, nullptr, nullptr};
        head   = up_lim;       
        bottom = bot_lim;
        head->next = bottom;
        bottom->prev = head;
    }

    /**
     * @brief Вставляет элемент в сортированный двунаправленный список
     * 
     * @param value - значение которое требуется вставить
     */
    void insert(T value){
        Elem<T> *new_elem = new Elem<T>{value, nullptr, nullptr};
        Elem<T> *tmp = head->next;
        while(tmp != nullptr){
            // Если нашли значение большее, чем текущее, вставляем новый элемент перед текущим
            if(tmp->value > value){
                insertElem(tmp->prev, new_elem);
                break;
            }
            tmp = tmp->next;
        }

    }

    /**
     * @brief Распечатывает список на консоли
     * 
     */
    void print(){
        Elem<T> *tmp = head->next;
        while(tmp->next != nullptr){
            std::cout << tmp->value << " ";
            tmp = tmp->next;
        }
        std::cout << std::endl;
    }
public:

};

int main(){
    List<short> list(-32767, 32767);    
    list.insert(25);
    list.insert(100);
    list.insert(50);
    list.insert(75);
    list.insert(100);
    list.insert(-2100);
    list.insert(-4375);
    list.insert(18934);

    list.print();

    return 0;
}