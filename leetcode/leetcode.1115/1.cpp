class FooBar {
private:
    int n;
    std::condition_variable cv;
    std::mutex m;
    bool foo_flag;
public:
    FooBar(int n) {
        this->n = n;
        foo_flag = true;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> lg(m);
            cv.wait(lg, [this]{return foo_flag;});
            foo_flag = false;
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            cv.notify_one();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> lg(m);
            cv.wait(lg, [this]{return !foo_flag;});
            foo_flag = true;
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            cv.notify_one();
        }
    }
};
