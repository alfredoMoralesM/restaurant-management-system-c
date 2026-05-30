# Restaurant Management System (C)

A console-based restaurant management system developed in C as part of the Data Structures course.

## Overview

This project simulates a restaurant ordering system where users can browse a menu, add products to a shopping cart, calculate totals, estimate delivery times, and complete purchases through a console interface.

The application focuses on the practical implementation of fundamental data structures and dynamic memory management.

## Features

* Menu visualization
* Product selection and shopping cart
* Automatic quantity updates for existing items
* Subtotal and total calculation
* File-based menu loading
* Console-based user interface

## Data Structures Used

### Circular Doubly Linked List

Used to store and navigate restaurant menu items efficiently.

### Singly Linked List

Used to manage shopping cart contents dynamically.

### Dynamic Memory Allocation

Nodes are created at runtime using dynamic memory allocation techniques.

## Technologies

* C Programming Language
* File Handling
* Dynamic Memory Management
* Linked Lists
* Console Interface

## Learning Objectives

This project was developed to reinforce concepts such as:

* Data Structures
* Linked Lists
* Dynamic Memory Allocation
* File Processing
* Modular Programming
* Algorithm Design

## Project Structure

```
restaurant-management-system-c/
├── data.txt
├── decorar.h
├── librerias.h
├── listas.h
├── Makefile.win
├── menu.h
├── portada.txt
├── portadaexcel.xlsx
├── principal.cpp
├── prototipos.h
```

## How to Run

Compile the source code using GCC:

```bash
g++ principal.cpp -o restaurant
```

Run the executable:

```bash
./restaurant
```

For Windows:

```bash
restaurant.exe
```

## Screenshots

* Main menu
<img width="1472" height="746" alt="image" src="https://github.com/user-attachments/assets/73c97903-affa-4713-80fa-335da565f777" />

* Product selection
<img width="1482" height="762" alt="image" src="https://github.com/user-attachments/assets/bbf37197-0a53-427e-8eeb-0bc60b3b5c65" />

* Shopping cart
<img width="1482" height="762" alt="image" src="https://github.com/user-attachments/assets/e38cad9c-abb9-45dd-b222-8300e468d129" />

* Order summary
<img width="1482" height="762" alt="image" src="https://github.com/user-attachments/assets/d8360771-57e6-4f9d-8ec2-eb793a3bb2aa" />

## Author

Christian Alfredo Morales Meza

Information Technology Engineering Student
Universidad Politécnica de San Luis Potosí
