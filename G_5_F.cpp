/***********************************************************************
 * Моля, преименувате файла, като:
 *   - замените G с групата, с която ходите на упражнения
 *   - замените F с вашия факултетен номер
 **********************************************************************/

/********************************************************************
Задача 5. Разглеждаме циклична верига от двойни кутии от вида:
struct node { int data; node* next; }; Да се реализира функция
node* cutCycle(int x, node* chain), която по указател към циклична
верига chain прекъсва веригата като изтрива елемента x и връща
началото на новата верига, а ако x не се среща във веригата,
функцията да връща nullptr.
Пример: cutCycle(2,1 → 4 → 2 → -1) ⇒ -1 → 1 → 4
********************************************************************/

struct node {
    int data;
    node* next;
};

/***********************************************************************
 РЕШЕНИЕ:
************************************************************************/

node* cutCycle(int x, node* chain) {
    if (chain == nullptr) {
        return nullptr;
    }

    node* p = chain;

    while (p->next != chain && p->next->data != x)
        p = p->next;

    if (p->next->data != x)
        return nullptr;
    
    node* start = p->next->next;
    delete p->next;
    p->next = nullptr;
    return start;
}

/***********************************************************************
 КРАЙ НА РЕШЕНИЕТО
************************************************************************/

#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"

/***********************************************************************
  РАЗКОМЕНТИРАЙТЕ СЛЕДВАЩИЯ РЕД, ЗА ДА ВКЛЮЧИТЕ ТЕСТОВЕТЕ
************************************************************************/
// #include "5_tests.hpp"

int main () {
    // пускане на тестовете
    doctest::Context().run();
    return 0;
}