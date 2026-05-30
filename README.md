# 🔐 CodeAlpha_Login-and-Registration-System

> A C++ based login and registration system for Code Alpha Internship Task 2. Features user registration, duplicate username validation, file-based credential storage, and login authentication.

---

## 📋 Table of Contents
- [Project Overview](#project-overview)
- [Features](#features)
- [Technologies Used](#technologies-used)
- [File Structure](#file-structure)
- [How to Run](#how-to-run)
- [Code Explanation](#code-explanation)
- [Sample Output](#sample-output)
- [Test Cases](#test-cases)
- [Requirements Met](#requirements-met)
- [Author](#author)

---

## 📌 Project Overview

This project implements a **secure authentication system** in C++ that allows users to:
- **Register** a new account with username and password
- **Login** to an existing account
- Store credentials **securely** in text files

Each user gets their own `.txt` file, ensuring data persistence across sessions.

---

## ✨ Features

### 📝 Registration
| Feature | Description |
|---------|-------------|
| Username Input | Takes username from user |
| Password Input | Takes password from user |
| Confirm Password | Ensures password matches |
| Username Validation | Minimum 3 characters (alphanumeric + underscore) |
| Password Validation | Minimum 6 characters |
| Duplicate Check | Prevents duplicate usernames |
| File Storage | Saves credentials in `username.txt` |
| Success/Error Messages | Clear feedback for user |

### 🔓 Login
| Feature | Description |
|---------|-------------|
| Username Verification | Checks if user exists |
| Password Verification | Compares with stored password |
| Welcome Message | Displays on successful login |
| Error Handling | Shows clear error messages |

### 🔒 Security Features
- One file per user
- Simple text-based storage
- Input validation to prevent empty fields

---

## 🛠️ Technologies Used

| Technology | Purpose |
|------------|---------|
| **C++** | Core programming language |
| **iostream** | Console input/output operations |
| **fstream** | File handling for credential storage |
| **cctype** | Input validation functions |
| **string** | String manipulation |

---

## 📂 File Structure
