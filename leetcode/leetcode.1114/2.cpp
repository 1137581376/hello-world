
class Foo {
public:
    std::condition_variable cv;
    std::mutex m;
    int flag;
    Foo() {
        flag = 1;
    }

    void first(function<void()> printFirst) {
        //std::unique_lock<std::mutex> lg(m);
        //cv.wait(lg, [&]{return flag == 1;});
        std::lock_guard<mutex> lk(m);
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        flag = 2;
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        std::unique_lock<std::mutex> lg(m);
        cv.wait(lg, [this]{return flag == 2;});
        // printSecond() outputs "second". Do not change or remove this line.
        flag = 3;
        printSecond();
        cv.notify_one();
    }

    void third(function<void()> printThird) {
        std::unique_lock<std::mutex> lg(m);
        cv.wait(lg, [this]{return flag == 3;});
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};
