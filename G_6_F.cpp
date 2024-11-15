/***********************************************************************
 * Моля, преименувате файла, като:
 *   - замените G с групата, с която ходите на упражнения
 *   - замените F с вашия факултетен номер
 **********************************************************************/

/***********************************************************************
Задача 6. Разглеждаме списък от стекове от числа, в които елементите са 
подредени в монотонно нарастващ ред от върха към дъното. Да се реализира 
функция, която прехвърля елементите на стековете, които са на нечетни 
позиции в списъка, в нов стек така, че числата в него да са подредени в 
монотонно намаляващ ред от върха към дъното. Новият стек да се запише на 
първа позиция в списъка, а изпразнените стекове да се изтрият от списъка. 
Представянето на списъка от стекове е по ваш избор.
Бонус: използвайте шаблони, така че елементите да могат да са от произволен 
тип.
Пример:

Вход
                4	 
 3              2      7
 2      3       0      4
 1  –>  0  ->  -1  ->  0

Изход
 -1              
  0             
  1             
  2             
  2      	    7
  3      3      4
  4  ->  0  ->  0
************************************************************************/

/***********************************************************************
 РЕШЕНИЕ:
************************************************************************/
#include "linked_stack.hpp"
#include "linked_list.hpp"

template <typename T>
void transform(LinkedList<LinkedStack<T>>& ls) {
    LinkedStack<T> result;
    LinkedStack<T>* mins = nullptr;
    typename LinkedList<LinkedStack<T>>::Iterator it;
    
    do {
        it = ls.begin();
        mins = nullptr;
        
        for (int pos = 1; it != ls.end(); ++it, ++pos) {
            if (pos % 2 != 0 && !(*it).empty()) {
                if (mins == nullptr || (*it).peek() < mins->peek())
                    mins = &*it;
            }
        }
        
        if (mins != nullptr)
            result.push((*mins).pop());
    } while (mins != nullptr);

    LinkedStack<T> tmp;
    ls.deleteFirst(tmp);
    it = ls.begin();
    for (int pos = 3; it != ls.end(); ++pos)
        if (pos % 2 != 0)
            ls.deleteAfter(tmp, it);
        else
            ++it;

    it = ls.begin();
    ls.insertFirst(result);
}
/***********************************************************************
 КРАЙ НА РЕШЕНИЕТО
************************************************************************/

#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"

/***********************************************************************
  РАЗКОМЕНТИРАЙТЕ СЛЕДВАЩИЯ РЕД, ЗА ДА ВКЛЮЧИТЕ ТЕСТОВЕТЕ
************************************************************************/
#include "6_tests.hpp"

int main () {
    // пускане на тестовете
    doctest::Context().run();
    return 0;
}