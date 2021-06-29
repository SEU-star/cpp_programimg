class Foo {
    
    std::mutex m;
    std::condition_variable cv;
    int ok = 0;      
public:
    void first(function<void()> printFirst) {

        {
            std::lock_guard<std::mutex> lock(m); //执行1时对全局锁对象加锁
            ok = 1;
            printFirst();
            cv.notify_all(); //1运行完毕后告知大家
        }

    }

    void second(function<void()> printSecond) {

        {
            std::unique_lock<std::mutex> lock(m);
            cv.wait(lock, [this](){return ok == 1;});//只有ok为1时加锁保证1执行完执行2
            printSecond();
            ok = 2;
            cv.notify_one();
        }
    }

    void third(function<void()> printThird) {

        {
            std::unique_lock<std::mutex> lock(m);
            cv.wait(lock, [this](){return ok == 2;});//只有ok为2时加锁保证2执行完执行3
            printThird();
        }
    }
};