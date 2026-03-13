A std::queue is not thread-safe. If two threads call push() at the exact same time, the internal pointers of the queue will corrupt, leading to a crash.

    std::mutex: This is your "talking stick." Only the thread holding the mutex can touch the queue.

    std::lock_guard or std::scoped_lock: These are RAII wrappers. They lock the mutex when created and automatically unlock it when the function ends. This is non-negotiable for professional C++

Condition Variables (std::condition_variable)
This is the most technical part. A condition variable allows a thread to wait for a specific "condition" (like !queue.empty()) without consuming CPU cycles.
    wait(): This command does something unique: it releases the mutex and puts the thread to sleep in one atomic step. When it wakes up, it re-acquires the mutex.
    notify_one(): The Producer calls this after pushing data to wake up a sleeping Consumer
    Since your queue will likely handle objects (like std::string or custom structs), you don't want to copy them in and out of the queue.

    Efficiency: You want to move the data into the queue and move it out to the consumer. This avoids expensive memory allocations.

    Prerequisite: Understand T&& (R-value references) and how std::move interacts with std::queue::push()


The Checklist

Before you start coding, make sure you can answer these:
    What happens if I forget to unlock a mutex? (Hint: Deadlock)
    Why does condition_variable::wait require a std::unique_lock instead of a std::lock_guard?
    How do I stop the queue (e.g., a "shutdown" flag) so the Consumer threads don't wait forever
