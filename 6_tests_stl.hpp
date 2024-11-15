using Stack = std::stack<int>;
using ListOfStacks = std::list<Stack>;

TEST_CASE("Примерът от условието работи") {
    ListOfStacks ls;
    Stack s1, s2, s3, s4;
    s1.push(3); s1.push(2); s1.push(1);
    s2.push(3); s2.push(0);
    s3.push(4); s3.push(2); s3.push(0); s3.push(-1);
    s4.push(7); s4.push(4); s4.push(0);
    ls.push_front(s4);
    ls.push_front(s3);
    ls.push_front(s2);
    ls.push_front(s1);
    
    transform(ls);
    
    // Check remaining stacks
    typename ListOfStacks::iterator it = ls.begin();

    // Check first stack (result)
    CHECK_EQ(it->top(), 4);
    it->pop();
    CHECK_EQ(it->top(), 3);
    it->pop();
    CHECK_EQ(it->top(), 2);
    it->pop();
    CHECK_EQ(it->top(), 2);
    it->pop();
    CHECK_EQ(it->top(), 1);
    it->pop();
    CHECK_EQ(it->top(), 0);
    it->pop();
    CHECK_EQ(it->top(), -1);
    it->pop();
    CHECK(it->empty());
    ++it;

    // Check second stack (was s2)
    CHECK_EQ(it->top(), 0);
    it->pop();
    CHECK_EQ(it->top(), 3);
    it->pop();
    CHECK(it->empty());
    ++it;
    
    // Check third stack (was s4)
    CHECK_EQ(it->top(), 0);
    it->pop();
    CHECK_EQ(it->top(), 4);
    it->pop();
    CHECK_EQ(it->top(), 7);
    it->pop();
    CHECK(it->empty());
    ++it;
    
    CHECK_EQ(it, ls.end());
}
