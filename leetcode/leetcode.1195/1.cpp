class FizzBuzz {
private:
    int n;
    std::mutex m;
    std::condition_variable cv;
    int count;
public:
    FizzBuzz(int n) {
        this->n = n;
        count = 1;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        for(int i = 3; i <= n; i += 3)
        {
            if(i % 5 == 0) continue;
            unique_lock<std::mutex> lk(m);
            cv.wait(lk, [this]{return count % 3 == 0 && count % 5 != 0;});
            count++;
            printFizz();
            cv.notify_all();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        for(int i = 5; i <= n; i += 5)
        {
            if(i % 3 == 0) continue;
            unique_lock<std::mutex> lk(m);
            cv.wait(lk, [this]{return count % 3 != 0 && count % 5 == 0;});
            count++;
            printBuzz();
            cv.notify_all();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        for(int i = 15; i <= n; i += 15)
        {
            unique_lock<std::mutex> lk(m);
            cv.wait(lk, [this]{return count % 15 == 0;});
            count++;
            printFizzBuzz();
            cv.notify_all();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        for(int i = 1; i <= n; i++)
        {
            if(i % 5 == 0 || i % 3 == 0) continue;
            unique_lock<std::mutex> lk(m);
            printNumber(count);
            count++;
            cv.notify_all();
        }
    }
};
