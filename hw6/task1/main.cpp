#include <coroutine>
#include <iostream>

struct Task {
    struct promise_type {
        using Handle = std::coroutine_handle<promise_type>;

        Task get_return_object() {
            return Task{Handle::from_promise(*this)};
        }

        std::suspend_never initial_suspend() { return {}; }
        std::suspend_never final_suspend() noexcept { return {}; }

        void return_void() {}
        void unhandled_exception() {}
    };    

    explicit Task(promise_type::Handle coro) : coro_(coro) {}
    ~Task() { if (!coro_.done()) coro_.destroy(); } // Нужен чтобы корутина не стала зомби (я ведь правильно это понял?). Но в целом тогда нужно юзать shared_ptr чтобы не убить таску случайно. честно в инете буквально 0 документаций про корутины вообще не понятно че методы делают а что не делают

    void destroy() { if (coro_) coro_.destroy(); }
    void resume() { coro_.resume(); }

private:
    promise_type::Handle coro_;
};

Task coroutine() {
    std::cout << "Hello, World!" << std::endl << std::flush;
    co_await std::suspend_always{};

    std::cout << "I am coroutine!" << std::endl << std::flush;
    co_await std::suspend_always{};

    std::cout << "Nice to meet you!" << std::endl << std::flush;
    co_await std::suspend_always{};

    std::cout << "Goodbye!" << std::endl << std::flush;
    co_return;
}

int main() {
    Task cute_guy = coroutine();

    cute_guy.resume();
    cute_guy.resume();
    cute_guy.resume();
}