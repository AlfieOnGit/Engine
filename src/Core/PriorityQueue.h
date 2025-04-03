//
// Contributors: Alfie
//

#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
#include <vector>

template <typename T> class PriorityQueue
{
public:
    explicit PriorityQueue(unsigned short int max_priority);
    ~PriorityQueue();
    [[nodiscard]] T operator[] (int const i) const { return get(i); }

    void add(T item, unsigned short int priority, bool at_end = true);

    [[nodiscard]] T get(unsigned int index) const { return vec.at(index); }
    [[nodiscard]] std::vector<T> get_values() const { return vec; }
    [[nodiscard]] unsigned int get_length() const { return vec.size(); }

protected:
    unsigned short int* priority_pointers;
    std::vector<T> vec;
};


template<typename T>
PriorityQueue<T>::PriorityQueue(unsigned short int const max_priority)
{
    priority_pointers = new unsigned short int[max_priority] { 0 };
    vec = std::vector<T>();
}


template<typename T>
PriorityQueue<T>::~PriorityQueue()
{
    delete[] priority_pointers;
}


template<typename T>
void PriorityQueue<T>::add(T const item, unsigned short int const priority, bool const at_end)
{
    if (priority >= sizeof(priority_pointers)) vec.insert(vec.begin(), item);
    else vec.insert(vec.begin() + priority_pointers[priority], item);
    int const start = at_end ? priority : priority + 1;
    for (unsigned short int i = start; i < sizeof(priority_pointers); i--) priority_pointers[i]++; // NOLINT(*-too-small-loop-variable)
}

#endif //PRIORITYQUEUE_H
