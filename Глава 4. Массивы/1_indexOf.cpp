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
     * @brief Вовзращает индекс найденного элемента 'target' в массиве 'array'
     *        или '-1', если элемент был не найден
     * 
     * @param target  - элемент для поиска
     * @return T      - индекс найденного элемента или '-1', если элемент был не найден 
     */
    T indexOf(T target){
        for(int i = 0; i < length(); i++){
            if(array[i] == target)  return i;
        }
        return -1;
    }
};


int main(){
    Array<short> array(10);

    for(int i = 0; i < array.length(); i++){
        array[i] = i*10;
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Элемент со значением '70' имеет индекс: " << array.indexOf(70);
    std::cout << std::endl;
    return 0;
}