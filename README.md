# 🧠 Philosophers Project

A concurrency and synchronization project from 42 that simulates the classic Dining Philosophers problem using POSIX threads (pthreads). This project demonstrates how to handle shared resources and avoid issues like deadlocks, starvation, and race conditions.

---

## 📚 Table of Contents
- [Overview](#-overview)
- [Features](#-features)
- [How to Compile](#-how-to-compile)
- [Usage](#-usage)
- [Arguments](#-arguments)
- [Example Output](#-example-output)
- [Project Structure](#-project-structure)
- [Valgrind Tools](#-valgrind-tools)
- [Credits](#-credits)

---

## 🧩 Overview

Each philosopher is a thread that alternates between thinking, eating, and sleeping. The program ensures there are no deadlocks or race conditions while simulating philosophers competing for forks (mutexes).

---

## ✨ Features

- Accurate simulation of the Dining Philosophers problem
- Thread-safe operations using mutexes
- Avoids deadlocks and starvation
- Error handling and clean memory management
- Norm-compliant code

---

## 🛠️ How to Compile

```bash
make
```

To clean up object files and the binary:

```bash
make fclean
```

---

## 🚀 Usage

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

---

## 📥 Arguments

1. `number_of_philosophers`: The number of philosophers and forks.
2. `time_to_die`: Time in milliseconds until a philosopher dies if they don’t start eating.
3. `time_to_eat`: Time in milliseconds it takes a philosopher to eat.
4. `time_to_sleep`: Time in milliseconds a philosopher will sleep.
5. `number_of_times_each_philosopher_must_eat` *(optional)*: Simulation stops once all philosophers have eaten this many times.

---

## 💡 Example Output

```
0 ms  Philosopher 1 is thinking
1 ms  Philosopher 1 is eating
...
```

---

## 📁 Project Structure

- `philo.c`: Entry point
- `philo.h`: Header file with data structures and function prototypes
- `init.c`: Initialization logic for data and threads
- `routine.c`: Thread routine and behavior logic
- `utils.c`: Utility functions for time, printing, and cleanup
- `Makefile`: Build system with custom Valgrind tools

---

## 🔍 Valgrind Tools

You can test thread correctness using:

```bash
make rd
```

This runs **Valgrind DRD**:

```
🔍 Running Valgrind DRD for Rami... 🔍
valgrind --tool=drd ./philo 5 800 200 200 5
```

Or test with **Helgrind**:

```bash
make hell
```

This runs:

```
🔍 Running Valgrind Helgrind for Rami... 🔍
valgrind --tool=helgrind ./philo 5 800 200 200 5
```

---

## 👤 Credits

Developed by **Rami Al Fayad** as part of the 42 Beirut curriculum.