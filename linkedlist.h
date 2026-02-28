#pragma once

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

using namespace std;

template <typename T>
class LinkedList {
 private:
  class Node {
   public:
    T data;
    Node* next;

    Node(T data) {
      this->data = data;
      this->next = nullptr;
    }

    Node(T data, Node* next) {
      this->data = data;
      this->next = next;
    }
  };

  size_t list_size;
  Node* list_front;

 public:
  /**
   * Default constructor. Creates an empty `LinkedList`.
   */
  LinkedList() {
    list_size = 0;
    list_front = nullptr;
  }

  /**
   * Returns whether the `LinkedList` is empty (i.e. whether its
   * size is 0).
   */
  bool empty() const {
    return list_size == 0;
  }

  /**
   * Returns the number of elements in the `LinkedList`.
   */
  size_t size() const {
    return list_size;
  }

  /**
   * Adds the given `T` to the front of the `LinkedList`.
   */
  void push_front(T data) {
    Node* oldFront = list_front;
    Node* node = new Node(data);
    node->next = oldFront;
    list_front = node;
    list_size = list_size + 1;
  }

  /**
   * Adds the given `T` to the back of the `LinkedList`.
   */
  void push_back(T data) {
    Node* node = new Node(false);

    if (list_front == nullptr) {
      list_front = node;
    } else {
      Node* curr = list_front;
      while (curr->next != nullptr) {
        curr = curr->next;
      }

      curr->next = node;
    }

    list_size = list_size + 1;
  }

  /**
   * Removes the element at the front of the `LinkedList`.
   *
   * If the `LinkedList` is empty, throws a `runtime_error`.
   */
  T pop_front() {
    if (list_size == 0) {
      throw runtime_error("empty list");
    }

    Node* oldHead = list_front;
    T result = oldHead->data;

    list_front = oldHead->next;
    delete oldHead;

    list_size = list_size - 1;

    return result;
  }

  /**
   * Removes the element at the back of the `LinkedList`.
   *
   * If the `LinkedList` is empty, throws a `runtime_error`.
   */
  T pop_back() {
    if (list_front == nullptr) {
      throw runtime_error("empty list");
    }

    if (list_front->next == nullptr) {
      T result = list_front->data;
      delete list_front;
      list_front = nullptr;
      list_size--;
      return result;
    }

    Node* curr = list_front;
    while (curr->next->next != nullptr) {
      curr = curr->next;
    }

    T result = curr->next->data;
    delete curr->next;
    curr->next = nullptr;
    list_size--;
    return result;
  }

  /**
   * Empties the `LinkedList`, releasing all allocated memory, and resetting
   * member variables appropriately.
   */
  void clear() {
    while (!empty()) {
      pop_front();
    }
  }

  /**
   * Destructor. Clears all allocated memory.
   */
  ~LinkedList() {
    clear();
  }

  /**
   * Returns the element at the given index in the `LinkedList`.
   *
   * If the index is invalid, throws `out_of_range`.
   */
  T& at(size_t index) {
    if (index >= list_size) {
      throw out_of_range("invaled index");
    }

    Node* curr = list_front;
    for (size_t i = 0; i < index; i++) {
      curr = curr->next;
    }
    return curr->data;
  }

  /**
   * Copy constructor. Creates a deep copy of the given `LinkedList`.
   *
   * Must run in O(N) time.
   */
  LinkedList(const LinkedList& other) {
    list_front = nullptr;
    list_size = 0;

    if (other.list_front == nullptr) {
      return;
    }
    list_front = new Node(other.list_front->data);
    list_size = 1;

    Node* tail = list_front;
    Node* curr = other.list_front->next;

    while (curr != nullptr) {
      push_back(curr->data);
      curr = curr->next;
    }
  }

  /**
   * Assignment operator. Sets the current `LinkedList` to a deep copy of the
   * given `LinkedList`.
   *
   * Must run in O(N) time.
   */
  LinkedList& operator=(const LinkedList& other) {
    if (this == &other) {
      return *this;
    }
    clear();
  }

  /**
   * Converts the `LinkedList` to a string. Formatted like `[0, 1, 2, 3, 4]`
   * (without the backticks -- hover the function name to see). Runs in O(N)
   * time.
   */
  string to_string() const {
    return "";
  }

  /**
   * Searches the `LinkedList` for the first matching element, and returns its
   * index. If no match is found, returns "-1".
   */
  size_t find(const T& data) {
    return 0;
  }

  /**
   * Removes the last occurrence of the given value from the `LinkedList`.
   *
   * For example, if a list was `[0, 1, 2, 1, 0, 1, 8]`, then a call to
   * `remove_last(1)` should change the list to be [0, 1, 2, 1, 0, 8]`.
   *
   * If the given value is not found on the `LinkedList`, throws an
   * `invalid_argument` exception.
   */
  void remove_last(const T& value) {
  }

  /**
   * Inserts the given `T` as a new element in the `LinkedList` before
   * the element currently stored in the given index. If the index is not
   * a current valid index in the list, throws `out_of_range`.
   */
  void insert_before(size_t index, T elem) {
  }

  /**
   * Remove every other element (alternating) from the
   * `LinkedList`, starting at index 1. Must run in O(N).
   *
   * For example, if a list was `[0, 1, 2, 3, 4]`, removing every other element
   * would change the list to `[0, 2, 4]`.
   */
  void remove_every_other() {
  }

  /**
   * Returns a pointer to the node at the front of the `LinkedList`. For
   * autograder testing purposes only.
   */
  void* front() const {
    return this->list_front;
  }
};