using VideoQueue = std::queue<Video>;
using StringQueue = std::queue<std::string>;

TEST_CASE("Примерът в условието работи правилно") {
    VideoQueue play;
    play.push({"APT", 34});
    play.push({"Лeкция по СДП", 2});
    play.push({"Gangnam style", 531});
    play.push({"Despacito", 856});
    play.push({"Shape of you", 634});
    play.push({"Baby", 320});
    play.push({"Baby shark", 1517});
    
    StringQueue later;
    StringQueue result = watch(2, play, later);
    
    CHECK_EQ(result.front(), "APT");
    result.pop();
    CHECK_EQ(result.front(), "Gangnam style");
    result.pop();
    CHECK_EQ(result.front(), "Despacito");
    result.pop();
    CHECK(result.empty());
    
    CHECK_EQ(later.front(), "Лeкция по СДП");
    later.pop();
    CHECK_EQ(later.front(), "Shape of you");
    later.pop();
    CHECK_EQ(later.front(), "Baby");
    later.pop();
    CHECK(later.empty());
}
