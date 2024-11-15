TEST_CASE("Примерът в условието работи правилно") {
    node* n4 = new node{-1, nullptr};
    node* n3 = new node{2, n4};
    node* n2 = new node{4, n3};
    node* n1 = new node{1, n2};
    n4->next = n1;
    
    node* p = cutCycle(2, n1);

    CHECK_EQ(p->data, -1);
    CHECK_EQ(p->next->data, 1);
    CHECK_EQ(p->next->next->data, 4);
    CHECK_EQ(p->next->next->next, nullptr);

    delete n1;
    delete n2;
    delete n4;
}
