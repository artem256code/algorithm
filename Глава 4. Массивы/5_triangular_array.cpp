#include <iostream>
#define ARRAY_DEFAULT_SIDE 3

// Простой класс треугольного массива, умеющий содержать длину этого самого массива :)
template <typename T>
class Array{
private:
    T *array;
    int size;
public:
    /**
     * @brief Конструктор для треугольного массива по умолчанию.
     * 
     */
    Array(){
        size = (ARRAY_DEFAULT_SIDE*ARRAY_DEFAULT_SIDE + ARRAY_DEFAULT_SIDE) / 2;
        array = new T[size];
    }
    /**
     * @brief Конструктор для треугольного массива с параметром.
     * 
     * @param side - размерность двумерного массива 
     */

    Array(int side){
        size = (side*side + side) / 2;
        array = new T[size];
    }

    /**
     * @brief Возвращает нужный элемент из треугольно массива по индексам обычного двум. массива
     * 
     * @param line      - строка на которой расположен элемент в двум. массиве
     * @param column    - столбец на котором расположен элемент в двум. массиве
     * @return T&       - элемент из треугольного 
     */
    T& getElem(int line, int column){
        return array[((line-1)*(line-1) + (line-1))/2 + column];
    }

    /**
     * @brief Устанавливает в треугольном массиве элемент с координатами из обычного двум. массива
     * 
     * @param value     - значение которое треубется записать
     * @param line      - строка на которой расположен элемент в двум. массиве
     * @param column    - столбец на котором расположен элемент в двум. массиве
     */
    void setElem(T value, int line, int column){
        array[((line-1)*(line-1) + (line-1))/2 + column] = value;
    }

    /**
     * @brief Возвращает длину массива
     * 
     * @return int - длина массива
     */
    int length(){
        return size;
    }
};


int main(){
    const int n = 3;        // Размерность двумерного массива
    Array<int> mass(n);     // Создаём треугольный массив из квадратной двум. массива nxn
    
    // Заполняем и выводим треугольный массив
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(j > i)   break;
            mass.setElem(i*n+j, i, j);
            std::cout << mass.getElem(i, j) << " ";
        }
            std::cout << std::endl;
    }



    return 0;
}