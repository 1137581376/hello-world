class ZeroEvenOdd {
private:
    int n;
    std::mutex m1, m2, m3;
    bool isOdd;
public:
    ZeroEvenOdd(int n) {
        this->n = n;
        m2.lock();
        m3.lock();
        isOdd = true;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for(int i = 0; i < n; ++i)
        {
            m1.lock();
            printNumber(0);
            if(isOdd)
                m3.unlock();
            else
                m2.unlock();
        }
    }

    void even(function<void(int)> printNumber) {
        for(int i = 2; i <= n; i += 2)
        {
            m2.lock();
            printNumber(i);
            isOdd = !isOdd;
            m1.unlock();
        }
    }

    void odd(function<void(int)> printNumber) {
        for(int i = 1; i <= n; i += 2)
        {
            m3.lock();
            printNumber(i);
            isOdd = !isOdd;
            m1.unlock();
        }
    }
};
