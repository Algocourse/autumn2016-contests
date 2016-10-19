#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

/*
 * modern C++11 way of generating random numbers
 *
int get_uniform_rand(int l, int r) {
    static mt19937 generator(42);
    uniform_int_distribution<int> distribution(l, r);
    return distribution(generator);
}
*/

int get_uniform_rand(const int l, const int r) {
    return l + rand() % (r - l + 1);
}

template <typename TIterator>
void inplace_quick_sort_stl_based(const TIterator begin, const TIterator end) {
    if (begin == end) {
        return;
    }

    using TValue = typename TIterator::value_type;

    const int iterator_distance = distance(begin, end);
    const int pivot_iterator_index = get_uniform_rand(0, iterator_distance - 1);

    TIterator pivot_iterator = begin;
    advance(pivot_iterator, pivot_iterator_index);
    const TValue pivot = *pivot_iterator;

    TIterator middle_iterator = partition(begin, end, [&pivot] (const TValue& value) {
        return value < pivot;
    });
    inplace_quick_sort_stl_based(begin, middle_iterator);

    middle_iterator = partition(middle_iterator, end, [&pivot] (const TValue& value) {
        return value <= pivot;
    });
    inplace_quick_sort_stl_based(middle_iterator, end);
}

void inplace_quick_sort(vector<int>& a, const int l, const int r) {
    if (l == r) {
        return;
    }

    const int pivot = a[get_uniform_rand(l, r)];

    int i = l;
    int j = r;
    while (i <= j) {
        while (i <= j && a[i] <= pivot) {
            ++i;
        }
        while (i <= j && a[j] > pivot) {
            --j;
        }
        if (i < j) {
            swap(a[i], a[j]);
        }
    }

    while (j >= l && a[j] == pivot) {
        --j;
    }

    if (l <= j) {
        inplace_quick_sort(a, l, j);
    }

    if (i <= r) {
        inplace_quick_sort(a, i, r);
    }
}

void quick_sort_with_additional_memory(vector<int>& a, const int l, const int r) {
    if (l == r) {
        return;
    }

    const int pivot = a[get_uniform_rand(l, r)];

    vector<int> buffer(r - l + 1);

    int buffer_left = 0;
    int buffer_right = r - l;
    for (int i = l; i <= r; ++i) {
        if (a[i] < pivot) {
            buffer[buffer_left++] = a[i];
        } else if (a[i] > pivot) {
            buffer[buffer_right--] = a[i];
        }
    }

    for (int i = buffer_left; i <= buffer_right; ++i) {
        buffer[i] = pivot;
    }

    copy(buffer.begin(), buffer.end(), a.begin() + l);

    buffer_left += l;
    buffer_right += l;

    if (buffer_left - 1 >= l) {
        quick_sort_with_additional_memory(a, l, buffer_left - 1);
    }

    if (buffer_right + 1 <= r) {
        quick_sort_with_additional_memory(a, buffer_right + 1, r);
    }
}

int main() {
    srand(42);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    inplace_quick_sort_stl_based(a.begin(), a.end());
    // inplace_quick_sort(a, 0, n - 1);
    // quick_sort_with_additional_memory(a, 0, n - 1);
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
