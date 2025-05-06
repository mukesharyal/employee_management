# 🏢 Employee Management System in C

A simple yet functional **Employee Management System** written in C that simulates the structure and task workflow of a company. This project uses **file handling with CSV** to store and manage data, demonstrating how hierarchical roles and task assignments can be implemented using core C concepts.

---

## 📌 Features

- 📁 **File-based data storage** using CSV files (no external databases required)
- 🧑‍💼 **Hierarchical structure** including Managers, Team Leads, and Workers
- 📋 **Task assignment and tracking**
- ✅ **Task completion flagging**
- 🔐 **Role-based permissions** for actions (e.g., only managers can assign tasks)

---

## 💡 How It Works

1. **Roles**: Users are identified by their position (Manager, Team Lead, Worker).
2. **Task Assignment**: Higher-level users can assign tasks to subordinates.
3. **Task Viewing**: Workers can view tasks assigned to them.
4. **Completion Status**: Workers can mark tasks as "completed", and this is reflected in the task records.

All this data is managed using a CSV file that keeps track of employees, their roles, assigned tasks, and their status.

---

## 🛠️ Technologies Used

- **C Programming Language**
- **Standard File I/O (fopen, fscanf, fprintf, etc.)**
- **CSV for data persistence**

---

## 📂 File Structure

```
├── main.c
├── employees.csv
├── tasks.csv
├── submitted_tasks.csv
```

> Note: `employees.csv` and `tasks.csv` are created at runtime (if not already present).

---

## 🚀 Getting Started

### 1. Clone the repository:
```bash
git clone https://github.com/mukesharyal/employee-management.git
cd employee-management
```

### 2. Compile the program:
```bash
gcc main.c -o employee_mgmt
```

### 3. Run the executable:
```bash
./employee_mgmt
```

---

## 🧠 Learning Goals

This project helped me strengthen my understanding of:

- File handling in C
- Structuring real-world data in a program
- Implementing role-based workflows
- Using plain-text (CSV) files for persistent storage

---
