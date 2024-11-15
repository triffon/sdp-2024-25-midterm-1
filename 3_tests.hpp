// Попълнете предложените от вас типове в редовете долу
using Queue = ОПАШКА_ОТ_ЧИСЛА;
using ListOfQueues = СПИСЪК_ОТ_ОПАШКИ;

TEST_CASE("Примерът от условието работи правилно") {
    ListOfQueues lq;
    
    // Create and populate the queues
    Queue q1;
    q1.enqueue(-1); q1.enqueue(0); q1.enqueue(3);
    
    Queue q2;
    q2.enqueue(-2); q2.enqueue(-1); q2.enqueue(2); q2.enqueue(5);
    
    Queue q3;
    q3.enqueue(3); q3.enqueue(7);
    
    Queue q4;
    q4.enqueue(1); q4.enqueue(4);
    
    // Add queues to the list
    lq.insertLast(q1);
    lq.insertLast(q2);
    lq.insertLast(q3);
    lq.insertLast(q4);
    
    transform(lq);
    
    // Check remaining queues
    typename ListOfQueues::Iterator it = lq.begin();
    
    // Check first queue (was q1)
    CHECK_EQ((*it).dequeue(), -1);
    CHECK_EQ((*it).dequeue(), 0);
    CHECK_EQ((*it).dequeue(), 3);
    CHECK((*it).empty());
    ++it;
    
    // Check third queue (was q3)
    CHECK_EQ((*it).dequeue(), 3);
    CHECK_EQ((*it).dequeue(), 7);
    CHECK((*it).empty());
    ++it;
    
    // Check result queue
    // should be -2 -1 1 2 4 5
    CHECK_EQ((*it).dequeue(), -2);
    CHECK_EQ((*it).dequeue(), -1);
    CHECK_EQ((*it).dequeue(), 1);
    CHECK_EQ((*it).dequeue(), 2);
    CHECK_EQ((*it).dequeue(), 4);
    CHECK_EQ((*it).dequeue(), 5);
    CHECK((*it).empty());
    ++it;

    CHECK_EQ(it, lq.end());
}
