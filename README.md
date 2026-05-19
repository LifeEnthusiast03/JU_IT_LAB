# JU_IT_LAB - Jadavpur University IT Lab Programs

Comprehensive repository containing lab assignments and projects for various IT subjects at Jadavpur University.

## 📁 Repository Structure

```
JU_IT_LAB/
├── CN_LAB/
│   └── cn/
│       ├── ass1/
│       │   ├── datagram_socket/   (client.c, server.c)
│       │   ├── raw_socket/        (client.c, server.c)
│       │   └── stream_socket/     (client.c, server.c)
│       └── ass2/
│           ├── q1/  (simplex.c)
│           ├── q2/  (stop_n_wait_noiseless.c, stop_n_wait_noisy.c)
│           ├── q3/  (nack.c, non_nack.c, piggybacked.c)
│           ├── q4/  (nack.c, non_nack.c, piggybacked.c)
│           └── q5/  (q5.c)
├── DBMS_LAB/
│   ├── 37_DBMS_ASS1.pdf
│   ├── 37_DBMS_ASS2.pdf
│   ├── 37_DBMS_ASS3.pdf
│   └── 37_DBMS_ASS4.pdf
├── DSA_LAB/
│   └── DSA_ASSIGNMENT.pdf
├── OOP_LAB/
│   ├── OOP_ASSIGNMENT_1.pdf
│   ├── OOP_ASSIGNMENT_2.pdf
│   ├── OOP_ASSIGNMENT_3.pdf
│   ├── OOP_ASSIGNMENT_4.pdf
│   └── OOP_ASSIGNMENT_5.pdf
├── OOS_LAB/
│   ├── 002311001037_SOUGATA_SAHA_ASS2.pdf
│   ├── 002311001037_SOUGATA_SAHA_ASS4.pdf
│   └── 002311001037_SOUGATA_SAHA_ASS5.pdf
├── OS_LAB/
│   ├── A3_10_1A.sh
│   ├── A3_10_1B.c
│   ├── A3_10_2A.c
│   ├── A3_10_2B.c
│   ├── A3_10_3.py
│   ├── A3_10_4.c
│   ├── A3_10_5.c
│   ├── A3_10_6.c
│   ├── A3_10_7.c
│   ├── assignment5   (compiled binary)
│   ├── matmul_pthread (compiled binary)
│   └── mmap_demo     (compiled binary)
├── SE_LAB/
│   ├── 037_ASS1.pdf
│   └── 037_ASS2.pdf
└── WEB_TECH_LAB/
    ├── WEBTECH_ASSIGNMENT.pdf
    ├── Assignment1/   (q1–q5 HTML)
    ├── Assignment2/   (question1–question9 HTML)
    ├── Assignment3/   (q1–q6 HTML, multi-page website)
    └── Assignment4/   (q1–q12 HTML, products.json)
```

---

## Labs Overview

### 📡 CN_LAB — Computer Networks

Socket programming and data-link layer protocol simulations in C.

#### **Assignment 1** — Socket Programming

| Directory | Files | Description |
|---|---|---|
| `datagram_socket/` | `client.c`, `server.c` | UDP client-server communication |
| `raw_socket/` | `client.c`, `server.c` | Raw socket communication with custom packet construction |
| `stream_socket/` | `client.c`, `server.c` | TCP stream-based client-server communication |

#### **Assignment 2** — Data Link Layer Protocols

| Directory | Files | Description |
|---|---|---|
| `q1/` | `simplex.c` | Simplex data transfer protocol |
| `q2/` | `stop_n_wait_noiseless.c`, `stop_n_wait_noisy.c` | Stop-and-Wait ARQ (noiseless & noisy channel variants) |
| `q3/` | `nack.c`, `non_nack.c`, `piggybacked.c` | Go-Back-N ARQ — NACK, Non-NACK, and Piggybacked ACK |
| `q4/` | `nack.c`, `non_nack.c`, `piggybacked.c` | Selective Repeat ARQ — NACK, Non-NACK, and Piggybacked ACK |
| `q5/` | `q5.c` | Additional protocol simulation |

---

### 🗄️ DBMS_LAB — Database Management System

Submitted PDF assignments covering relational database design, SQL, and normalization.

| File | Description |
|---|---|
| `37_DBMS_ASS1.pdf` | Assignment 1 |
| `37_DBMS_ASS2.pdf` | Assignment 2 |
| `37_DBMS_ASS3.pdf` | Assignment 3 |
| `37_DBMS_ASS4.pdf` | Assignment 4 |

---

### 📊 DSA_LAB — Data Structures & Algorithms

| File | Description |
|---|---|
| `DSA_ASSIGNMENT.pdf` | Assignment document covering data structures topics |

---

### 🎯 OOP_LAB — Object-Oriented Programming

Submitted PDF assignments covering OOP concepts.

| File | Description |
|---|---|
| `OOP_ASSIGNMENT_1.pdf` | Assignment 1 |
| `OOP_ASSIGNMENT_2.pdf` | Assignment 2 |
| `OOP_ASSIGNMENT_3.pdf` | Assignment 3 |
| `OOP_ASSIGNMENT_4.pdf` | Assignment 4 |
| `OOP_ASSIGNMENT_5.pdf` | Assignment 5 |

---

### 🖥️ OOS_LAB — Open Source Software / Operating System Concepts

Submitted PDF reports by **Sougata Saha (Roll: 002311001037)**.

| File | Description |
|---|---|
| `002311001037_SOUGATA_SAHA_ASS2.pdf` | Assignment 2 submission |
| `002311001037_SOUGATA_SAHA_ASS4.pdf` | Assignment 4 submission |
| `002311001037_SOUGATA_SAHA_ASS5.pdf` | Assignment 5 submission |

---

### ⚙️ OS_LAB — Operating System (Practical)

System programming assignments in C, Python, and Shell Script covering process management, threading, IPC, and memory mapping.

| File | Language | Description |
|---|---|---|
| `A3_10_1A.sh` | Shell | Shell script assignment |
| `A3_10_1B.c` | C | C assignment 1B |
| `A3_10_2A.c` | C | C assignment 2A |
| `A3_10_2B.c` | C | C assignment 2B |
| `A3_10_3.py` | Python | Python assignment |
| `A3_10_4.c` | C | C assignment 4 |
| `A3_10_5.c` | C | C assignment 5 |
| `A3_10_6.c` | C | C assignment 6 |
| `A3_10_7.c` | C | C assignment 7 |
| `assignment5` | Binary | Compiled executable for assignment 5 |
| `matmul_pthread` | Binary | Matrix multiplication using POSIX threads |
| `mmap_demo` | Binary | Memory-mapped file demonstration |

---

### 💼 SE_LAB — Software Engineering

Submitted PDF assignments covering software engineering methodologies.

| File | Description |
|---|---|
| `037_ASS1.pdf` | Assignment 1 |
| `037_ASS2.pdf` | Assignment 2 |

---

### 🌐 WEB_TECH_LAB — Web Technology

Web-based programming with HTML, CSS, and JavaScript. Also includes `WEBTECH_ASSIGNMENT.pdf` (the official assignment sheet).

#### **Assignment 1** — Basic JavaScript & DOM (5 Programs)

| File | Description |
|---|---|
| `q1.html` | Display a message on button click |
| `q2.html` | Change paragraph text using `innerHTML` & `getElementById` |
| `q3.html` | Add two numbers with input boxes and display result via DOM |
| `q4.html` | Change background color using `document.body.style.backgroundColor` |
| `q5.html` | Display current date and time using the `Date()` object |

#### **Assignment 2** — Intermediate JavaScript (9 Programs)

| File | Description |
|---|---|
| `question1.html` | Even/Odd number checker |
| `question2.html` | Calculate square and cube of a number |
| `question3.html` | Dynamic button click counter |
| `question4.html` | Random background color generator |
| `question5.html` | Display current date, time, and day name |
| `question6.html` | Marks calculator (total, average, pass/fail) |
| `question7.html` | Toggle show/hide paragraph functionality |
| `question8.html` | Text input validation with warning messages |
| `question9.html` | Find the largest number among three inputs |

#### **Assignment 3** — Multi-Page Website (6 Pages)

| File | Description |
|---|---|
| `q1.html` | Standalone page / entry point |
| `q2_home.html` | Home page of a multi-page website |
| `q2_login.html` | Login page with form |
| `q2_registration.html` | Registration/sign-up page |
| `q2_catalogue.html` | Product/catalogue listing page |
| `q3.html` | Additional page (q3) |
| `q4.html` | Additional page (q4) |
| `q5.html` | Additional page (q5) |
| `q6.html` | Additional page (q6) |

#### **Assignment 4** — Advanced JavaScript Applications (12 Programs)

| File(s) | Description |
|---|---|
| `q1.html` | Dynamic To-Do Task Manager — add/delete tasks, mark completed, show pending count |
| `q2.html` | PIN Verification Game — random 4-digit PIN, 3 attempts, DOM validation |
| `q3.html` | Expense Tracker — add expenses, calculate total, show last 5 |
| `q4.html` | Product Search Filter — 15 products, live filtering, "no product found" message |
| `q5.html` | Digital Stopwatch — Start/Stop/Reset with `setInterval` |
| `q6.html` | Login Form Validator — username, email & password validation with regex |
| `q7.html` | User Preferences with LocalStorage — save/load/clear favourite color |
| `q8.html` | Automatic Text Carousel — one quote at a time, auto-change every 4s |
| `q9.html` | Voting Poll Application — 3 options, percentage results with progress bars |
| `q10.html` | Product Display from JSON — `fetch()` from `products.json`, card layout, search |
| `q11.html` | Font Size Toggle — increase/decrease size, saves setting via localStorage |
| `q12.html` | Live Word Counter — real-time word count, warning if over 100 words |
| `products.json` | Sample product data file used by `q10.html` |

---

## 🚀 Technologies Used

| Category | Technologies |
|---|---|
| **Web Front-end** | HTML5, CSS3, JavaScript (ES6+) |
| **System Programming** | C, POSIX Threads, Shell Script |
| **Scripting** | Python 3 |
| **Networking** | TCP/IP Sockets, UDP, Raw Sockets |
| **Data** | JSON, LocalStorage |
| **Tools** | VS Code, Git, GCC |

## 📝 Notes

- All `WEB_TECH_LAB` programs are **standalone HTML files** — open directly in any modern browser.
- `CN_LAB` programs require **GCC** and a **Linux/Unix** environment to compile and run.
- `OS_LAB` binaries (`assignment5`, `matmul_pthread`, `mmap_demo`) are pre-compiled Linux ELF executables.
- `OOS_LAB`, `DBMS_LAB`, `DSA_LAB`, `OOP_LAB`, and `SE_LAB` contain submitted **PDF assignments** only.
- Student roll number: **002311001037** (Sougata Saha).

---

**Last Updated:** May 19, 2026