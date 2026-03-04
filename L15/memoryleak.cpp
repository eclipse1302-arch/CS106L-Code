#include <iostream>
#include <fstream>
#include <memory>
#include <mutex>
#include <thread>
#include <vector>
#include <string>

using namespace std;

// ============================================================================
// 示例 1: 堆内存管理 (Heap Memory)
// ============================================================================

class Person {
public:
    string name;
    Person(string n) : name(n) { cout << "[Person] 构造: " << name << endl; }
    ~Person() { cout << "[Person] 析构: " << name << endl; }
};

void demo_heap_memory() {
    cout << "\n========== 示例 1: 堆内存管理 ==========" << endl;
    
    // 错误方式：手动new/delete（容易泄漏）
    cout << "\n[错误方式] 手动 new/delete:\n";
    {
        Person* p1 = new Person("Alice");
        // 如果这里抛出异常，delete 就不会执行，导致内存泄漏！
        // delete p1;  // 容易忘记or被异常绕过
    }
    
    // 正确方式 1: unique_ptr（推荐）
    cout << "\n[正确方式 1] 使用 unique_ptr:\n";
    {
        unique_ptr<Person> p2 = make_unique<Person>("Bob");
        // 即使抛异常，~unique_ptr 也会自动 delete
    }  // 自动析构
    
    // 正确方式 2: shared_ptr（共享所有权）
    cout << "\n[正确方式 2] 使用 shared_ptr:\n";
    {
        shared_ptr<Person> p3 = make_shared<Person>("Charlie");
        {
            shared_ptr<Person> p3_copy = p3;  // 引用计数 +1
            cout << "引用数: " << p3.use_count() << endl;
        }  // p3_copy 销毁，引用计数 -1
        cout << "引用数: " << p3.use_count() << endl;
    }  // p3 销毁，引用计数为0，自动释放
}

// ============================================================================
// 示例 2: 文件操作 (Files)
// ============================================================================

void demo_file_operations() {
    cout << "\n========== 示例 2: 文件操作 ==========" << endl;
    
    // 错误方式：手动open/close
    cout << "\n[错误方式] 手动 open/close:\n";
    {
        // FILE* f = fopen("test.txt", "w");
        // fprintf(f, "Hello");
        // if (something) return;  // 异常/提前返回，fclose 被跳过！
        // fclose(f);
        cout << "手动管理文件容易在异常/提前返回时忘记 close\n";
    }
    
    // 正确方式：使用 C++ RAII fstream
    cout << "\n[正确方式] 使用 std::ofstream (RAII):\n";
    {
        ofstream outfile("test.txt");
        if (outfile.is_open()) {
            outfile << "Hello, World!\n";
            outfile << "This is a test file.\n";
            cout << "[文件] 已写入\n";
        }
        // 作用域结束 → ~ofstream 自动关闭文件
    }
    
    // 读取文件
    cout << "\n[正确方式] 使用 std::ifstream (RAII):\n";
    {
        ifstream infile("test.txt");
        if (infile.is_open()) {
            string line;
            while (getline(infile, line)) {
                cout << "[文件内容] " << line << endl;
            }
        }
        // 作用域结束 → ~ifstream 自动关闭文件
    }
}

// ============================================================================
// 示例 3: 互斥锁 (Locks)
// ============================================================================

mutex mtx;
int shared_counter = 0;

void unsafe_increment(int id, int times) {
    for (int i = 0; i < times; ++i) {
        // 竞态条件！多个线程同时读-修改-写
        int temp = shared_counter;
        this_thread::sleep_for(chrono::microseconds(1));  // 模拟耗时操作
        shared_counter = temp + 1;
    }
}

void safe_increment(int id, int times) {
    for (int i = 0; i < times; ++i) {
        {
            // 正确方式：lock_guard 自动管理锁
            lock_guard<mutex> lock(mtx);
            shared_counter++;
        }  // lock_guard 析构 → 自动 unlock
    }
}

void demo_locks() {
    cout << "\n========== 示例 3: 互斥锁 ==========" << endl;
    
    // 演示不安全版本的问题
    cout << "\n[不安全版本] 不使用锁:\n";
    shared_counter = 0;
    {
        vector<thread> threads;
        for (int i = 0; i < 5; ++i) {
            threads.emplace_back(unsafe_increment, i, 100);
        }
        for (auto& t : threads) t.join();
        cout << "最终计数 (应为 500): " << shared_counter << endl;
    }
    
    // 演示安全版本
    cout << "\n[安全版本] 使用 lock_guard:\n";
    shared_counter = 0;
    {
        vector<thread> threads;
        for (int i = 0; i < 5; ++i) {
            threads.emplace_back(safe_increment, i, 100);
        }
        for (auto& t : threads) t.join();
        cout << "最终计数 (应为 500): " << shared_counter << endl;
    }
    
    // 演示 try_lock 方式
    cout << "\n[try_lock 方式] 使用 unique_lock:\n";
    {
        unique_lock<mutex> lk(mtx, try_to_lock);
        if (lk.owns_lock()) {
            cout << "[锁] 成功获得锁\n";
            // 处理受保护的资源
        } else {
            cout << "[锁] 未获得锁（有其他线程持有）\n";
        }
        // unique_lock 析构 → 自动解锁
    }
}

// ============================================================================
// 示例 4: 套接字 (Sockets) - 简化示例
// ============================================================================

class SimpleSocket {
private:
    int socket_fd;
    bool is_open;
    
public:
    SimpleSocket(int fd = -1) : socket_fd(fd), is_open(fd >= 0) {
        if (is_open) {
            cout << "[Socket] 打开 (fd=" << socket_fd << ")" << endl;
        }
    }
    
    ~SimpleSocket() {
        if (is_open && socket_fd >= 0) {
            cout << "[Socket] 关闭 (fd=" << socket_fd << ")" << endl;
            is_open = false;
        }
    }
    
    void send_data(const string& data) {
        if (is_open) {
            cout << "[Socket] 发送: " << data << endl;
        } else {
            cout << "[Socket] 错误：套接字未打开\n";
        }
    }
    
    // 禁用复制，只支持移动（防止双重关闭）
    SimpleSocket(const SimpleSocket&) = delete;
    SimpleSocket& operator=(const SimpleSocket&) = delete;
    
    SimpleSocket(SimpleSocket&& other) noexcept 
        : socket_fd(other.socket_fd), is_open(other.is_open) {
        other.is_open = false;
        cout << "[Socket] 移动构造\n";
    }
};

void demo_sockets() {
    cout << "\n========== 示例 4: 套接字 ==========" << endl;
    
    // 错误方式：手动管理，容易忘记关闭
    cout << "\n[错误方式] 手动 socket/close:\n";
    {
        // int sock = socket(...);
        // if (error) return;  // 忘记 close!
        // close(sock);
        cout << "手动管理套接字容易在异常/提前返回时忘记 close\n";
    }
    
    // 正确方式：包装为 RAII 类
    cout << "\n[正确方式] 使用 RAII 类:\n";
    {
        SimpleSocket sock1(101);  // 模拟打开套接字 fd=101
        sock1.send_data("Hello Server");
        
        {
            SimpleSocket sock2(102);  // 模拟打开套接字 fd=102
            sock2.send_data("Hello from nested scope");
        }  // sock2 自动关闭
        
    }  // sock1 自动关闭
    
    // 或使用 unique_ptr 包装
    cout << "\n[smart pointer 方式] 使用 unique_ptr:\n";
    {
        auto sock = make_unique<SimpleSocket>(103);
        sock->send_data("Smart pointer managed");
    }  // 自动释放
}

// ============================================================================
// 主函数
// ============================================================================

int main() {
    cout << "========================================\n"
         << "   Acquire-Release 资源管理演示\n"
         << "   防止内存泄漏的最佳实践\n"
         << "========================================\n";
    
    demo_heap_memory();
    demo_file_operations();
    demo_locks();
    demo_sockets();
    
    cout << "\n========================================\n"
         << "   演示完成！所有资源已正确释放\n"
         << "========================================\n";
    
    return 0;
}
