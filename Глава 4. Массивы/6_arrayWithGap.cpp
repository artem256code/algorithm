
#define DEFAUL_RETURN_VALUE 0

// Одна ячейки массива с разрывом
template <class T>
class Cell{
private:    
    int colNum;         //  Номер ячейки в строке 
    T value;            //  Значение ячейки
public:
    Cell<T> *next;      //  Указатель на следующую ячейку
public:
    Cell<T>(): next(nullptr) {} 
    int getCol()            {return colNum;}
    T   getValue()          {return value;}
};


// Одна строка массива с разрывом
template <class T>
class ArrayRow{
private:
    int rowNum;         //  Номер строки
    Cell<T> *firstCell; //  Первая ячейка в строке
public:
    ArrayRow<T> *next;  //  Указатель на следующую строку

public:
    ArrayRow<T>(): rowNum(0), firstCell(Cell<T>()), next(nullptr) {}
    int     getRow()            {return rowNum;}
    Cell<T> getFirstCell()      {return firstCell;}
};  

template <class T>
class Array{
private:
    ArrayRow<T> *startRow;
public:
    /**
     * @brief Ищет строку в массиве перед строкой с номером 'row'
     * 
     * @param row               - перед какой строкой производить поиск
     * @return ArrayRow<T>      - возвращает строку предшествующую 'row' или 
     *                            последнюю строку (если 'row'-строки в массиве не оказалось)
     */
    ArrayRow<T> findRowBefore(int row){
        ArrayRow<T> *array_row = startRow;
        while(array_row->next != nullptr && array_row->getRow() < row){
            array_row = array_row->next;
        }
        return array_row;
    }
    
    /**
     * @brief   Возвращает ячейку в массиве перед ячейком с номером 'col'
     * 
     * @param col               - перед какой ячейкой производить поиск
     * @return Cell<T>          - возвращает ячейку предшествующую 'row' или
     *                            последнюю ячейку (если 'col'-ячейки в массиве не оказалось)
     */
    Cell<T> findCellBefore(int col){
        Cell<T> *array_cell = startRow->getFirstCell();
        while(array_cell->next != nullptr && array_cell->getCol()){
            array_cell = array_cell->next;
        }
        return array_cell;
    }

    /**
     * @brief Получает значение ячейки из массива, расположенного на строке 'row' и столбце 'col'
     * 
     * @param row   - столбец, где расположена ячейка
     * @param col   - строка, где расположена ячейка
     * @return T    - во
     */
    T getValue(int row, int col){
        ArrayRow<T> array_row = findRowBefore(row);
        array_row = array_row.next;
        if(array_row == nullptr)        return DEFAUL_RETURN_VALUE;
        if(array_row.getRow() > row)    return DEFAUL_RETURN_VALUE;

        Cell<T> cell_row = findCellBefore(col);
        cell_row = cell_row.next;
        if(cell_row== nullptr)          return DEFAUL_RETURN_VALUE;
        if(cell_row.getCol() > col)     return DEFAUL_RETURN_VALUE;

        return cell_row.getValue();
    }
};



int main(){ 


    return 0;
}