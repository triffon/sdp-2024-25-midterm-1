TEST_CASE("findMax(7, {1,3,5,3,6,3,1,4,8.4.1}) ⇒ 8") {
    std::vector<int> play = {1,3,5,3,6,3,1,4,8,4,1};
    CHECK_EQ(findMax(7, play), 8);
}

TEST_CASE("findMax(6, {1,3,5,3,6,3,1,4,8,4,1}) ⇒ 0") {
    std::vector<int> play = {1,3,5,3,6,3,1,4,8,4,1};
    CHECK_EQ(findMax(6, play), 0);
}

TEST_CASE("findMax(6, {1,3,5,3,6,5,3,1}) ⇒ 0") {
    std::vector<int> play = {1,3,5,3,6,5,3,1};
    CHECK_EQ(findMax(6, play), 0);
}

TEST_CASE("findMax(6, {1,3,5,3,6,3}) ⇒ 0") {
    std::vector<int> play = {1,3,5,3,6,3};
    CHECK_EQ(findMax(6, play), 0);
}
