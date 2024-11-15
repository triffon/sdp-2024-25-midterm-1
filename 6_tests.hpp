// Попълнете предложените от вас типове в редовете долу
using Stack = СТЕК_ОТ_ЧИСЛА;
using ListOfStacks = СПИСЪК_ОТ_СТЕКОВЕ;

TEST_CASE("Примерът от условието работи") {
    ListOfStacks ls;
    Stack s1, s2, s3, s4;
    s1.push(3); s1.push(2); s1.push(1);
    s2.push(3); s2.push(0);
    s3.push(4); s3.push(2); s3.push(0); s3.push(-1);
    s4.push(7); s4.push(4); s4.push(0);
    ls.insertFirst(s4);
    ls.insertFirst(s3);
    ls.insertFirst(s2);
    ls.insertFirst(s1);
    
    transform(ls);
    
    // Check remaining stacks
    typename ListOfStacks::Iterator it = ls.begin();

    // Check first stack (result)
    CHECK_EQ((*it).pop(), 4);
    CHECK_EQ((*it).pop(), 3);
    CHECK_EQ((*it).pop(), 2);
    CHECK_EQ((*it).pop(), 2);
    CHECK_EQ((*it).pop(), 1);
    CHECK_EQ((*it).pop(), 0);
    CHECK_EQ((*it).pop(), -1);
    CHECK((*it).empty());
    ++it;

    // Check second stack (was s2)
    CHECK_EQ((*it).pop(), 0);
    CHECK_EQ((*it).pop(), 3);
    CHECK((*it).empty());
    ++it;
    
    // Check third stack (was s4)
    CHECK_EQ((*it).pop(), 0);
    CHECK_EQ((*it).pop(), 4);
    CHECK_EQ((*it).pop(), 7);
    CHECK((*it).empty());
    ++it;
    
    CHECK_EQ(it, ls.end());
}
