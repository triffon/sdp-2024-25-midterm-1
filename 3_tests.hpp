using Queue = std::queue<int>;
using ListOfQueues = std::list<Queue>;

TEST_CASE("Примерът от условието работи правилно") {
    ListOfQueues lq;
    
    // Create and populate the queues
    Queue q1;
    q1.push(-1); q1.push(0); q1.push(3);
    
    Queue q2;
    q2.push(-2); q2.push(-1); q2.push(2); q2.push(5);
    
    Queue q3;
    q3.push(3); q3.push(7);
    
    Queue q4;
    q4.push(1); q4.push(4);
    
    // Add queues to the list
    lq.push_back(q1);
    lq.push_back(q2);
    lq.push_back(q3);
    lq.push_back(q4);
    
    transform(lq);
    
    // Check remaining queues
    typename ListOfQueues::iterator it = lq.begin();
    
    // Check first queue (was q1)
    CHECK_EQ(it->front(), -1);
    it->pop();
    CHECK_EQ(it->front(), 0);
    it->pop();
    CHECK_EQ(it->front(), 3);
    it->pop();
    CHECK(it->empty());
    ++it;
    
    // Check third queue (was q3)
    CHECK_EQ(it->front(), 3);
    it->pop();
    CHECK_EQ(it->front(), 7);
    it->pop();
    CHECK(it->empty());
    ++it;
    
    // Check result queue
    // should be -2 -1 1 2 4 5
    CHECK_EQ(it->front(), -2);
    it->pop();
    CHECK_EQ(it->front(), -1);
    it->pop();
    CHECK_EQ(it->front(), 1);
    it->pop();
    CHECK_EQ(it->front(), 2);
    it->pop();
    CHECK_EQ(it->front(), 4);
    it->pop();
    CHECK_EQ(it->front(), 5);
    it->pop();
    CHECK(it->empty());
    ++it;

    CHECK_EQ(it, lq.end());
}
