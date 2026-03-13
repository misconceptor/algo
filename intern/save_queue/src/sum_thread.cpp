/*
   CONSIDER READING README.TXT 
*/ 
#include <iostream>
#include <iomanip>
#include <vector>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

const long long maxn = 1e9;

vector<int> a(maxn, 7);

mutex mtx;

void sum (int l, int r, long long &global_sum) {    // [l, r)
    long long local_sum = 0;
    for(int i = l; i < r; ++i) local_sum += a[i];
    std::lock_guard<mutex> lock(mtx);
    global_sum += local_sum;
}

int main(){
    auto start = std::chrono::high_resolution_clock::now();

    long long global_sum = 0;

    vector<thread> workers;

    int num_threads = std::thread::hardware_concurrency(); 

    if(num_threads == 0) num_threads = 4;

    long long step = maxn / num_threads;
    
    for(int i = 0; i < num_threads; ++i){
        workers.emplace_back(sum, step * i, step * (i + 1), std::ref(global_sum));
    }

    for(auto &t : workers) t.join();

    cout << "global sum : " << global_sum << "\n";

    auto end = std::chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;

    cout << fixed << setprecision(3);
    cout << "Time: " << elapsed.count() << "s" << std::endl;

    return 0;
}