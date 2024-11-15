using VideoQueue = LinkedQueue<Video>;
using StringQueue = LinkedQueue<std::string>;

TEST_CASE("Примерът в условието работи правилно") {
    VideoQueue play;
    play.enqueue({"APT", 34});
    play.enqueue({"Лeкция по СДП", 2});
    play.enqueue({"Gangnam style", 531});
    play.enqueue({"Despacito", 856});
    play.enqueue({"Shape of you", 634});
    play.enqueue({"Baby", 320});
    play.enqueue({"Baby shark", 1517});
    
    StringQueue later;
    StringQueue result = watch(2, play, later);
    
    CHECK_EQ(result.dequeue(), "APT");
    CHECK_EQ(result.dequeue(), "Gangnam style");
    CHECK_EQ(result.dequeue(), "Despacito");
    CHECK(result.empty());
    
    CHECK_EQ(later.dequeue(), "Лeкция по СДП");
    CHECK_EQ(later.dequeue(), "Shape of you");
    CHECK_EQ(later.dequeue(), "Baby");
    CHECK(later.empty());
}
