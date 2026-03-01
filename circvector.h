#pragma once

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

using namespace std;

template <typename T>
class CircVector {
 private:
  T* data;
  size_t vec_size;
  size_t capacity;
  size_t front_idx;

  // TODO_STUDENT: add private helper functions, such as resize
  // You may also find a "wrapping" function helpful.

 public:
  /**
   * Default constructor. Creates an empty `CircVector` with capacity 10.
   */
  CircVector() {
    capacity = 10;
    front_idx = 0;
    vec_size = 0;
    data = new T[10];
  }

  /**
   * Creates an empty `CircVector` with given capacity. Capacity must exceed 0.
   */
  CircVector(size_t capacity) {
    if (capacity == 0) {
      throw invalid_argument("capacity must be > 0");
    }
    this->capacity = capacity;
    vec_size = 0;
    front_idx = 0;
    data = new T[this->capacity];
  }

  /**
   * Returns whether the `CircVector` is empty (i.e. whether its
   * size is 0).
   */
  bool empty() const {
    return vec_size == 0;
  }

  /**
   * Returns the number of elements in the `CircVector`.
   */
  size_t size() const {
    return vec_size;
  }

  /**
   * Adds the given `T` to the front of the `CircVector`.
   */
  void push_front(T elem) {
  }

  /**
   * Adds the given `T` to the back of the `CircVector`.
   */
  void push_back(T elem) {
    if (vec_size == capacity) {
      size_t new_capacity = capacity * 2;
      T* new_data = new T[new_capacity];

      for (size_t i = 0; i < vec_size; i++) {
        new_data[i] = data[(front_idx + i) % capacity];
      }

      delete[] data;
      data = new_data;
      capacity = new_capacity;
      front_idx = 0;
    }
    size_t physical_index = (front_idx + vec_size) % capacity;
    data[physical_index] = elem;
    vec_size++;
  }

  /**
   * Removes the element at the front of the `CircVector`.
   *
   * If the `CircVector` is empty, throws a `runtime_error`.
   */
  T pop_front() {
    return T{};
  }

  /**
   * Removes the element at the back of the `CircVector`.
   *
   * If the `CircVector` is empty, throws a `runtime_error`.
   */
  T pop_back() {
    return T{};
  }

  /**
   * Removes all elements from the `CircVector`.
   */
  void clear() {
  }

  /**
   * Destructor. Clears all allocated memory.
   */
  ~CircVector() {
    delete[] data;
  }

  /**
   * Returns the element at the given index in the `CircVector`.
   *
   * If the index is invalid, throws `out_of_range`.
   */
  T& at(size_t index) {
    if (index >= vec_size) {
      throw out_of_range("out of range index");
    }
    size_t physical_index = (front_idx + index) % capacity;

    return data[physical_index];
  }

  /**
   * Copy constructor. Creates a deep copy of the given `CircVector`.
   *
   * Must run in O(N) time.
   */
  CircVector(const CircVector& other) {
  }

  /**
   * Assignment operator. Sets the current `CircVector` to a deep copy of the
   * given `CircVector`.
   *
   * Must run in O(N) time.
   */
  CircVector& operator=(const CircVector& other) {
    return *this;
  }

  /**
   * Converts the `CircVector` to a string. Formatted like `[0, 1, 2, 3, 4]`
   * (without the backticks -- hover the function name to see). Runs in O(N)
   * time.
   */
  string to_string() const {
    return "";
  }

  /**
   * Searches the `CircVector` for the first matching element, and returns its
   * index in the `CircVector`. If no match is found, returns "-1".
   */
  size_t find(const T& target) {
    return 0;
  }

  /**
   * Removes the last occurrence of the given `value` from the `CircVector`.
   *
   * For example, if a list was `[0, 1, 2, 1, 0, 1, 8]`, then a call to
   * `remove_last(1)` should change the list to be [0, 1, 2, 1, 0, 8]`.
   *
   * If the given value is not found on the `CircVector`, throws an
   * `invalid_argument` exception.
   */
  void remove_last(const T& value) {
  }

  /**
   * Inserts the given `T` as a new element in the `CircVector` before
   * the element currently stored in the given index. If the index is not
   * a current valid index in the list, throws `out_of_range`.
   */
  void insert_before(size_t index, T elem) {
  }

  /**
   * Remove every other element (alternating) from the
   * `CircVector`, starting at index 1. Must run in O(N). May not reallocate.
   *
   * For example, if a list was `[0, 1, 2, 3, 4]`, removing every other element
   * would change the list to `[0, 2, 4]`.
   */
  void remove_every_other() {
  }

  /**
   * Returns a pointer to the underlying memory managed by the `CircVec`.
   * For autograder testing purposes only.
   */
  T* get_data() const {
    return this->data;
  }

  /**
   * Returns the capacity of the underlying memory managed by the `CircVec`. For
   * autograder testing purposes only.
   */
  size_t get_capacity() const {
    return this->capacity;
  }
};