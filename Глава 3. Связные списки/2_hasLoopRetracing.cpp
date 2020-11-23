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
    bool hasLoopRetracing(){
        Elem<T> *tmp = head;
        if(tmp == nullptr)  return false;

        while(tmp->next != nullptr){
            Elem<T> *tracer = tmp->next;
            while(tracer->next != nullptr){
                if(tracer->next == tmp->next)   return true;
                tracer = tracer->next;
            }
            tmp = tmp->next;
        }
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

    std::cout << "Список цикличен: " << list.hasLoopRetracing() << std::endl;
    return 0;
}