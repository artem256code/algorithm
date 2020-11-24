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
    Elem *getHead()     {return head;}
    Elem *getBottom()   {return bottom;}

    List(){
        // Создаём и настраиваем нижний и верхний ограничители
        Elem *top_lim = new Elem{0, nullptr, nullptr};
        Elem *bot_lim = new Elem{0, nullptr, nullptr};
        top_lim->next = bot_lim;
        bot_lim->prev = top_lim;
        
        head = top_lim;
        bottom = bot_lim;
    }

    /**
     * @brief Вставляет элемент в двунаправленный список, после элемента "after_me" 
     * 
     * @param after_me - элемент, после которого будет произведена вставка
     * @param new_elem - новый элемент, который будет добавлен в список
     */
    void insertElem(Elem *after_me, Elem *new_elem){
        new_elem->next = after_me->next;
        after_me->next = new_elem;

        new_elem->next->prev = new_elem;
        new_elem->prev = after_me; 
    }

    /**
     * @brief Добавляет элемент в конец двунаправленного связного списка
     *  
     * @param value - значение для добавления
     */
    void addToEnd(int value){
        Elem *new_elem = new Elem{value, nullptr, nullptr};
        insertElem(bottom->prev, new_elem);
    }

    /**
     * @brief Добавляет элемент в начало двунаправленного связаного списка
     * 
     * @param value - значение которое будует добавлено в начало
     */
    void addToBeginning(int value){
        Elem *new_elem = new Elem{value, nullptr, nullptr};
        insertElem(head, new_elem);
    }

    /**
     * @brief Удаляет элемент из двунаправленного связного списка после элемента "after_me"
     * 
     * @param after_me - элемент после которого требуется произвести удаление
     */
    void removeElem(Elem *after_me){
        Elem *tmp = after_me->next;
        after_me->next = after_me->next->next;
        after_me->next->prev = after_me;

        delete [] tmp;
    }

    /**
     * @brief Распечатывает список на консоли
     * 
     */
    void print(){
        Elem *tmp = head->next;
        while(tmp->next != nullptr){
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
    list.addToBeginning(2);
    list.addToEnd(3);
    list.addToEnd(4);

    list.print();

    // Удаляем первый элемент после ограничителя
    list.removeElem(list.getHead());
    list.print();


    // Удаляем последний элемент. Для этого смещаемся с ограничетеля 2 раза!
    list.removeElem(list.getBottom()->prev->prev);
    list.print();

    return 0;
}