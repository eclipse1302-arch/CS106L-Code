// vector_examples.cpp
// 一组小示例，演示常用的 std::vector 操作并在注释中说明作用。

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;
using std::cout;
using std::endl;

// 打印整数向量的辅助函数
void print_vec(const std::vector<int>& v, const std::string& name = "v") {
    cout << name << " (size=" << v.size() << ", capacity=" << v.capacity() << ") : ";
    for (int x : v) cout << x << ' ';
    cout << '\n';
}

int main() {
    // 1) 构造 vector
    std::vector<int> a;                    // 空向量
    std::vector<int> b(5, 42);            // 大小为5，每个元素值为42
    std::vector<int> c = {1, 2, 3};       // 初始化列表
    print_vec(a, "a");
    print_vec(b, "b");
    print_vec(c, "c");

    // 2) push_back / emplace_back
    // push_back 会复制或移动传入对象到容器末尾
    c.push_back(4);
    print_vec(c, "c after push/emplace");
    // emplace_back 在容器末尾原地构造元素（避免额外拷贝/移动）
    c.emplace_back(5);
    print_vec(c, "c after push/emplace");

    // 3) 访问元素： operator[] 与 at()
    // operator[] 不做范围检查；越界会产生未定义行为
    int first = c[0];
    // at() 做范围检查，越界时抛出 std::out_of_range
    try {
        int safe = c.at(10); // 会抛异常
        (void)safe;
    } catch (const std::out_of_range& e) {
        cout << "at() 越界示例: " << e.what() << endl;
    }

    // 4) front / back / pop_back
    cout << "front=" << c.front() << ", back=" << c.back() << endl;
    c.pop_back(); // 移除最后一个元素
    print_vec(c, "c after pop_back");

    // 5) insert / erase
    // 在 begin()+1 位置插入值 99
    c.insert(c.begin() + 1, 99);
    print_vec(c, "c after insert");
    // 删除第2个元素（索引1）
    c.erase(c.begin() + 1);
    print_vec(c, "c after erase");

    // 6) clear 与 empty
    std::vector<int> d = {7,8,9};
    cout << "d empty? " << std::boolalpha << d.empty() << endl;
    d.clear(); // 删除所有元素
    cout << "d empty after clear? " << std::boolalpha << d.empty() << endl;

    // 7) reserve / resize
    std::vector<int> e;
    e.reserve(10); // 预分配足够的容量，避免频繁扩容
    cout << "e capacity after reserve(10): " << e.capacity() << endl;
    e.resize(5, -1); // 改变大小为5，新元素值为-1
    print_vec(e, "e after resize");

    // 8) assign
    std::vector<int> f;
    f.assign(3, 100); // 生成 {100,100,100}
    print_vec(f, "f after assign");

    // 9) swap
    cout << "Before swap f and e:\n";
    print_vec(f, "f");
    print_vec(e, "e");
    f.swap(e); // 交换内容（常数时间）
    cout << "After swap:\n";
    print_vec(f, "f");
    print_vec(e, "e");

    // 10) 遍历方式
    std::vector<int> g = {10, 20, 30};
    // 索引遍历
    for (size_t i = 0; i < g.size(); ++i) cout << "g[" << i << "]=" << g[i] << ' ';
    cout << '\n';
    // 范围 for
    for (int x : g) cout << x << ' ';
    cout << '\n';
    // 迭代器
    for (auto it = g.begin(); it != g.end(); ++it) cout << *it << ' ';
    cout << '\n';
    // 反向迭代
    for (auto it = g.rbegin(); it != g.rend(); ++it) cout << *it << ' ';
    cout << '\n';

    // 11) 与算法配合：排序 / erase-remove 删除满足条件的元素
    std::vector<int> h = {3,1,4,1,5,9,2};
    std::sort(h.begin(), h.end()); // 升序排序
    print_vec(h, "h after sort");
    // 删除所有值为1的元素（erase-remove惯用法）
    h.erase(std::remove(h.begin(), h.end(), 1), h.end());
    print_vec(h, "h after remove 1s");

    // 12) 注意事项（不直接演示）：
    // - 若要避免拷贝大量字符串，可以使用 vector<string_view>（需保证原字符串生命周期）
    // - 在多线程环境下对同一 vector 的并发修改需加锁

    return 0;
}
