# 🗂️ Task Management System in C++

## 📋 Overview

This is a simple **console-based Task Management System** built using C++. The program allows a user to:

- Add tasks
- View all tasks
- Edit task details
- Delete tasks

Each task includes:
- Title
- Deadline
- Priority (1–5)
- Status (Pending, Under Process, Completed)

This is a beginner-friendly project demonstrating the use of **classes, arrays, and object-oriented programming in C++**.

---

## 💡 Features

- ✅ Add up to 100 tasks
- ✏️ Edit any task by its index
- ❌ Delete tasks
- 📋 View all current tasks
- 🟢 Track task progress (Pending, Under Process, Completed)
- 👤 Personalized user greeting

---

## 🧱 Class Overview

- `Task` – Represents a single task (title, deadline, priority, status)
- `User` – Manages user name and greeting
- `TaskList` – Manages the array of tasks and all operations (add, edit, delete, view)

---

## 🛠️ How to Compile & Run

### Prerequisites

Make sure you have a C++ compiler like `g++` installed.

### Compile

```bash
g++ -o task_manager task_manager.cpp
