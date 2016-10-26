#include <iostream>
#include <vector>

#include <cassert>
using namespace std;

template <typename T>
class heap_t {
public:
    T top() const {
        assert(size() > 0);
        return values[0];
    }

    bool empty() const {
        return size() == 0;
    }

    size_t size() const {
        return values.size();
    }

    void push(T value) {
        values.push_back(value);
        go_up(values.size() - 1);
    }

    void pop() {
        assert(size() > 0);
        swap(values[0], values.back());
        values.pop_back();
        go_down(0);
    }

private:
    vector<T> values;

    size_t get_left_id(size_t id) const {
        return (id << 1) + 1;
    }

    size_t get_right_id(size_t id) const {
        return (id << 1) + 2;
    }

    size_t get_ancestor_id(size_t id) const {
        return (id - 1) >> 1;
    }

    void go_up(size_t id) {
        while (id > 0) {
            const size_t ancestor_id = get_ancestor_id(id);
            if (values[id] < values[ancestor_id]) {
                swap(values[id], values[ancestor_id]);
                id = ancestor_id;
            } else {
                break;
            }
        }
    }

    void go_down(size_t id) {
        while (true) {
            const size_t left_id = get_left_id(id);
            const size_t right_id = get_right_id(id);

            size_t min_id = id;
            if (left_id < values.size() && values[left_id] < values[min_id]) {
                min_id = left_id;
            }
            if (right_id < values.size() && values[right_id] < values[min_id]) {
                min_id = right_id;
            }

            if (min_id == id) {
                break;
            } else {
                swap(values[id], values[min_id]);
                id = min_id;
            }
        }
    }
};

/* 
 * for some user defined types implementation of swap function is needed
 * 
struct example_t {
    int value;

    bool operator < (const example_t other) const {
        return value < other.value;
    }
};
*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

/*
    heap_t<example_t> h;

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        h.push(example_t{x});
    }

    while (!h.empty()) {
        cout << h.top().value << " ";
        h.pop();
    }
    cout << endl;
*/

    heap_t<int> h;

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        h.push(x);
    }

    while (!h.empty()) {
        cout << h.top() << " ";
        h.pop();
    }
    cout << endl;

    return 0;
}
