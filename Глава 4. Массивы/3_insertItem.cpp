#include <iostream>
#define ARRAY_DEFAULT_SIZE 100

// Простой класс массива, умеющий содержать длину этого самого массива :)
template <typename T>
class Array{
private:
    T *array;
    int size;
public:
    /**
     * @brief Конструктор для массива по умолчанию. Создаёт массив длины 'ARRAY_DEFAULT_SIZE'
     * 
     */
    Array(){
        array = new T[ARRAY_DEFAULT_SIZE];
        this->size = ARRAY_DEFAULT_SIZE;
    }
    /**
     * @brief Конструктор для массива с параметром. Создаёт массив длины 'size'
     * 
     * @param size - размер создаваемого массива
     */

    Array(int size){
        array = new T[size];
        this->size = size;
    }

    /**
     * @brief Перегруженные оператор индексации
     * 
     * @param index - нужный индекс
     * @return T&   - ссылка на значение массива по индексу 'index'
     */
    T& operator [] (const int index){
        return array[index];
    }

    /**
     * @brief Возвращает длину массива
     * 
     * @return int - длина массива
     */
    int length(){
        return size;
    }
    
    /**
     * @brief Вставляет значение 'value' в массив на позицию 'position'
     * 
     * @param value     - вставляемое значение
     * @param position  - позиция (индекс) для вставки
     */
    void insertItem(T value, int position){
        for(int i = length()-1; i > position; i--){
            array[i] = array[i-1];
        }
        array[position] = value;
    }

};


int main(){
    Array<short> array(10);

    std::cout << "До вставки:    ";
    for(int i = 0; i < array.length(); i++){
        array[i] = i*10;
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
    
    array.insertItem(100, 7);
    std::cout << "После вставки: ";
    for(int i = 0; i < array.length(); i++){
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}