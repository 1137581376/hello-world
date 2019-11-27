class Foo {
public:
    atomic<int> flag;
    Foo() {
        flag.store(1, std::memory_order_release);
    }

    void first(function<void()> printFirst) {
        while(flag.load(std::memory_order_acquire) != 1);
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        flag.store(2, std::memory_order_release);
    }

    void second(function<void()> printSecond) {
        while(flag.load(std::memory_order_acquire) != 2);
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        flag.store(3, std::memory_order_release);
    }

    void third(function<void()> printThird) {
        while(flag.load(std::memory_order_acquire) != 3);
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        flag.store(1, std::memory_order_release);
    }
};
