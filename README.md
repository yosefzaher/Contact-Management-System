<h3 align="center">
  Contact Management System
</h3>

<p align="center">
  <img src="https://raw.githubusercontent.com/devicons/devicon/master/icons/c/c-original.svg" alt="C Language" width="60" height="60" />
</p>

---

## 📝 Project Overview

This project is a simple console-based contact management system developed in C. It allows the user to add, update, delete, search, and display contacts efficiently. The system stores contact records using a linked list and persists data in a CSV file for future use.

It was designed as a practical academic project to demonstrate:
- Data structures and linked lists
- File handling in C
- Modular programming
- Input validation
- CRUD operations

---

## 🇪🇬 / 🇺🇸 Project Description

### English
The Contact Management System helps users manage personal or business contacts in an organized way. Each contact contains a name, email, and phone number. The program provides a menu-based interface and validates user input before saving data.

### العربية
نظام إدارة جهات الاتصال يساعد المستخدم على إدارة جهات الاتصال بطريقة منظمة وسهلة. كل جهة اتصال تحتوي على الاسم والبريد الإلكتروني ورقم الهاتف. البرنامج يوفر واجهة قائمة تفاعلية، مع فحص للبيانات قبل حفظها في النظام.

---

## ✨ Main Features

- Add new contact
- Delete contact by phone number
- Update phone number
- Update email
- Search contact by phone number
- Search contact by email
- Display all contacts
- Save data to CSV file
- Load data from CSV file
- Input validation for name, email, and phone number

---

## 🧠 Data Structure

The project uses a linked list to store contact records.

Each node contains:
- Name
- Email
- Phone Number
- Pointer to next contact

This makes insertion, deletion, and search operations efficient and easy to implement in a low-level C structure.

---

## 🏗️ System Design

The following images show the system architecture and layer-based design of the project:

### Overall System Design
<img src="System%20Design/Contact%20Management%20System%20-%20The%20Hole%20System.jpg" alt="Overall System Design" width="100%" />

### Application Layer
<img src="System%20Design/Contact%20Management%20System%20-%20Application%20Layer.jpg" alt="Application Layer" width="100%" />

### Data Layer
<img src="System%20Design/Contact%20Management%20System%20-%20Data_Layer.jpg" alt="Data Layer" width="100%" />

### Database Layer
<img src="System%20Design/Contact%20Management%20System%20-%20Data%20Base%20Layer.jpg" alt="Database Layer" width="100%" />

### File System Layer Based Design
<img src="System%20Design/Contact%20Management%20System%20-%20File%20System%20Layer%20Based%20Design.jpg" alt="File System Layer Design" width="100%" />

### Low Level Layer
<img src="System%20Design/Contact%20Management%20System%20-%20Low%20Level%20Layer.jpg" alt="Low Level Layer" width="100%" />

---

## 📁 Project Structure

```text
Contact-Management-System/
├── README.md
├── C Final Project.pdf
├── Contact_Management_System/
│   ├── main.c
│   ├── main.h
│   ├── contacts.csv
│   ├── Contact_Management_System.cbp
│   ├── contact_layer/
│   │   ├── Check_Data_Module/
│   │   │   ├── Check_Data.c
│   │   │   └── Check_Data.h
│   │   └── Contact_Info_Module/
│   │       ├── Contact_Info.c
│   │       └── Contact_Info.h
│   ├── data_base_layer/
│   │   ├── Data_Base.c
│   │   └── Data_Base.h
│   ├── low_level_layer/
│   │   ├── DataType.h
│   │   ├── Linked_List.c
│   │   ├── Linked_List.h
│   │   ├── Std_Libraries.h
│   │   └── ...
│   └── obj/
│       └── Debug/
└── System Design/
    └── Design images
```

---

## ⚙️ Workflow

1. User starts the program.
2. The system loads contacts from the CSV file.
3. A menu is displayed.
4. User selects an action such as add, search, update, or delete.
5. Data is validated before being saved.
6. The linked list is updated.
7. On exit, the updated list is written back to the CSV file.

---

## ✅ Functional Requirements Covered

- Linked list implementation for contact storage
- Menu-based user interaction
- Validation for invalid data
- Duplicate detection for email and phone number
- Contact search by email or phone
- Update and delete functionalities
- CSV file persistence

---

## 🛠️ Tools and Technologies

- C Programming Language
- Code::Blocks / GCC
- Linked List Data Structure
- CSV File Storage
- Windows console APIs

---

## ▶️ How to Run the Project

### Option 1: Using Code::Blocks
1. Open the project file: [Contact_Management_System/Contact_Management_System.cbp](Contact_Management_System/Contact_Management_System.cbp)
2. Build the project
3. Run the program

### Option 2: Using GCC in PowerShell
```powershell
cd "C:\Users\Dell\OneDrive\Desktop\Contact Management System\Contact-Management-System\Contact_Management_System"
gcc -Wall -std=c11 -I. main.c contact_layer/Check_Data_Module/Check_Data.c contact_layer/Contact_Info_Module/Contact_Info.c data_base_layer/Data_Base.c low_level_layer/Linked_List.c -o app.exe
.\app.exe
```

> Note: GCC must be installed and available in PATH before running this command.

---

## 👨‍💻 Contributors

- Eng. Youssef Zaher
- Eng. Zeinab Eltantawy
- Eng. Adam Elsayed
- Eng. Ahmed Eldamhogy
- Eng. Rahma Ahmed

---

## 📌 Notes

This project is a strong example of:
- modular C architecture
- working with dynamic memory
- manipulating linked list nodes
- data validation before insertion
- reading and writing data files

It is a good beginner-to-intermediate C project and can be improved further with:
- better menu styling
- sorting contacts
- search by name
- GUI version in the future
- safer input handling


