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
public:
    List<T>():                  head(nullptr), size(0) {}
    List<T>(Elem<T> *head):     head(head),    size(0) {}

    /**
     * @brief  Проверяет является ли список цикличным
     * 
     * @return true     - если список имеет цикл
     * @return false    - если список не имеет цикл
     */
    bool hasLoopMarking(){
        Elem<T> *tmp = head;
        bool has_loop = false;
        //Если нет элементов
        if(tmp == nullptr)      return false;

        while(tmp->next != nullptr){
            //Если уже посещали элемент
            if(tmp->visited){
                has_loop = true;
                break;
            }
            tmp->visited = true;
            tmp = tmp->next;
        }

        //Ещё раз проходимся по списку и снимаем флажки
        tmp = head;
        while(tmp->visited != false){
            tmp->visited = false;
            tmp = tmp->next;
        }

        if(has_loop)    return true;
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

    std::cout << "Список цикличен: " << list.hasLoopMarking() << std::endl;
    return 0;
}