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
     * @brief Возвращает минимальный элемент в массиве 'array'
     *  
     * @return T - минимальынй элемент 
     */
    T findMinimum(){
        T min = array[0];
        for(int i = 0; i < length(); i++)   
            if(array[i] < min)  min = array[i];

        return min;
    }

    /**
     * @brief Возвращает максимальный элемент в массиве 'array'
     * 
     * @return T - максимальный элемент
     */
    T findMaximum(){
        T max = array[0];
        for(int i = 0; i < length(); i++)   
            if(array[i] > max)  max = array[i];

        return max;
    }

    /**
     * @brief Возвращает среднее значение элементов массива 'array' того же типа, что и элементы!!!
     * 
     * @return T - среднее значение
     */
    T findAverage(){
        T total = array[0];
        for(int i = 1; i < length(); i++)   total += array[i];
        
        return total/length();
    }
    
};


int main(){
    Array<short> array(10);

    for(int i = 0; i < array.length(); i++){
        array[i] = i*10;
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Минимум: "            << array.findMinimum() << std::endl;
    std::cout << "Максимум: "           << array.findMaximum() << std::endl;
    std::cout << "Среднее значение: "   << array.findAverage() << std::endl;


    return 0;
}