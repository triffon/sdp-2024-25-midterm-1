
TEST_CASE("createCycle(4,1 → 0 → 5 → 4 → 8) ⇒ 5 → 4 → 8") {
    node n5 = {8, nullptr};
    node n4 = {4, &n5};
    node n3 = {5, &n4};
    node n2 = {0, &n3};
    node n1 = {1, &n2};
    node* p = createCycle(4, &n1);
    CHECK_EQ(p->data, 5);
    CHECK_EQ(p->next->data, 4);
    CHECK_EQ(p->next->next->data, 8);
    CHECK_EQ(p->next->next->next, nullptr);
    CHECK_EQ(n1.data, 1);
    CHECK_EQ(n1.next->data, 0);
    CHECK_EQ(n1.next->next->data, 4);
    CHECK_EQ(n1.next->next->next, &n1);
    delete n1.next->next;
}
