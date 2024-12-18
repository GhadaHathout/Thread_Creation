# **POSIX Threads Example**

This project demonstrates the creation and synchronization of threads in the C programming language using the POSIX thread (`pthread`) library. The program employs a **mutex** to ensure thread-safe access to a shared variable.

---

## **Description**

- **Threads**: POSIX threads are created using the `pthread_create()` function.
- **Mutex**: A mutex (mutual exclusion) is used to synchronize access to the shared resource (`sum`) between two threads.
- **Shared Resource**: Both threads increment a shared variable (`sum`) in a loop, ensuring data consistency through the use of `pthread_mutex_lock()` and `pthread_mutex_unlock()`.

---

## **Code Overview**

The program includes:
- **Thread 1**: Increments the shared variable `sum` and prints a message.
- **Thread 2**: Increments the shared variable `sum` and prints a different message.
- **Mutex**: Protects the critical section where `sum` is modified.

At the end of execution, the program prints the final value of `sum`, which is expected to be `200000` (since each thread increments the variable 100,000 times).

---

## **Dependencies**

Ensure you have a C compiler and POSIX thread library installed:
- GCC (GNU Compiler Collection)
- POSIX `pthread` library

---

## **Compilation**

To compile the program, use the following command:

```bash
gcc pthread.c -lpthread -o bin
```

- `-lpthread` links the POSIX thread library.
- `bin` is the output binary file.

---

## **Execution**

Run the compiled program using:

```bash
./bin
```

### **Expected Output**:
You will see interleaved messages from both threads:

```
This is thread 1
	This is thread 2
This is thread 1
	This is thread 2
...
Sum=200000
```

---

## **Key Functions Used**

- `pthread_create()`: Creates a new thread.
- `pthread_join()`: Waits for a thread to terminate.
- `pthread_mutex_init()`: Initializes a mutex.
- `pthread_mutex_lock()`: Locks the mutex to enter the critical section.
- `pthread_mutex_unlock()`: Unlocks the mutex to exit the critical section.

---

## **Concept: Mutex**

A **mutex** (Mutual Exclusion) is used to prevent race conditions when multiple threads access shared resources. Only one thread can lock the mutex at a time, ensuring that no other thread can access the critical section until the mutex is unlocked.
