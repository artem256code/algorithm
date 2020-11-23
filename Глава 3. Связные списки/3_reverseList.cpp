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
    int size;
private:
    
public:
    List<T>():                  head(nullptr), size(0) {}
    List<T>(Elem<T> *head):     head(head),    size(0) {}

    /**
     * @brief Реверсирует список и меняет начало списка 'head'
     * 
     */
    void reverseList(){
        Elem<T> *prev_cell = nullptr;
        Elem<T> *curr_cell = head;

        while(curr_cell != nullptr){
            Elem<T> *next_cell = curr_cell->next;
            curr_cell->next = prev_cell;

            prev_cell = curr_cell;
            curr_cell = next_cell;
        }       

        head = prev_cell;
    }

    /**
     * @brief  Проверяет содержит ли список цикл
     * 
     * @return true  - если содержит
     * @return false - если не содержит
     */
    bool hasLoopReversing(){
        if(head == nullptr)     return false;

        Elem<T> *head1 = head;
        reverseList();          //Реверсируем список
        Elem<T> *head2 = head;  //и получаем новое начало списка
        reverseList();          //Ещё раз реверсируем, чтобы вернуть все ссылки на место
        
        if(head1 == head2)      return true;
        return false;
    } 
};

int main(){
    // Создаём элементы
    Elem<int> elem1 = {0, nullptr, false};
    Elem<int> elem2 = {1, nullptr, false};
    Elem<int> elem3 = {2, nullptr, false};

    //Искуственно настраиваем цикл
    elem1.next = &elem2;
    elem2.next = &elem3;
    elem3.next = &elem1;

    List<int> list(&elem1);
    

    std::cout << "Список цикличен: " << list.hasLoopReversing() << std::endl;
    return 0;
}