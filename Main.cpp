#include <iostream>
#include <cstdlib>
#include <ctime>

template <typename T>
void fill_arr(T arr[], int size, T left, T right) {
    srand(time(0));
    for (int i = 0; i < size; i++) {
        arr[i] = left + rand() % (right - left);
    }
}

template <typename T>
void print_arr(T arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
int search_index(T arr[], int size, T element, int begin = 0) {
    for (int i = begin; i < size; i++) {
        if (arr[i] == element) {
            return i;
        }
    }
    return -1;
}

template <typename T>
int search_last_index(T arr[], int size, T element, int begin = 0) {
    for (int i = size - 1; i >= begin; i--) {
        if (arr[i] == element) {
            return i;
        }
    }
    return -1;
}

template <typename T>
T arr_min(T arr[], int size) {
    T min_val = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min_val) {
            min_val = arr[i];
        }
    }
    return min_val;
}

template <typename T>
T arr_max(T arr[], int size) {
    T max_val = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }
    return max_val;
}

template <typename T>
double mean_value(T arr[], int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum / size;
}

template <typename T>
void range(T arr[], int size, T left, T right) {
    for (int i = 0; i < size; i++) {
        if (arr[i] >= left && arr[i] < right) {
            std::cout << arr[i] << " ";
        }
    }
    std::cout << std::endl;
}

template <typename T>
int count(T arr[], int size, T element) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            count++;
        }
    }
    return count;
}

template <typename T>
void sort_arr(T arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    const int SIZE = 20;
    int arr[SIZE];

    fill_arr(arr, SIZE, -50, 51);
    print_arr(arr, SIZE);

    int index = search_index(arr, SIZE, 0);
    std::cout << "Индекс первого появления 0: " << index << std::endl;

    int last_index = search_last_index(arr, SIZE, 0);
    std::cout << "Индекс последнего появления 0: " << last_index << std::endl;

    int min_val = arr_min(arr, SIZE);
    std::cout << "Минимальное значение: " << min_val << std::endl;

    int max_val = arr_max(arr, SIZE);
    std::cout << "Максимальное значение : " << max_val << std::endl;

    double mean = mean_value(arr, SIZE);
    std::cout << "Среднее значение: " << mean << std::endl;

    range(arr, SIZE, -10, 11);

    int count_zero = count(arr, SIZE, 0);
    std::cout << "Количество нулей: " << count_zero << std::endl;

    sort_arr(arr, SIZE);
    print_arr(arr, SIZE);

    return 0;
}