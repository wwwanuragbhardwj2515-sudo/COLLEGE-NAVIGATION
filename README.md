# 🏫 College Campus Navigation System

A C-based **College Campus Navigation System** that uses a **weighted graph** and **Dijkstra's Algorithm** to find the shortest route between two locations on a college campus.

## 📌 Project Overview

This project represents different locations of a college campus as **vertices (nodes)** and the paths between them as **weighted edges**.

The weight of each edge represents the **distance between two locations in meters**.

The user can enter a starting location and a destination, and the system calculates the shortest possible route using **Dijkstra's Shortest Path Algorithm**.

## 🧠 Concepts Used

* Graph Data Structure
* Weighted Graph
* Adjacency Matrix
* Dijkstra's Shortest Path Algorithm
* Arrays
* Functions
* Enumeration (`enum`)
* Strings in C
* File Handling
* Graph Visualization using Graphviz

## 🗺️ Campus Locations

The project contains the following locations:

* Main Gate
* Admin Block
* Library
* Academic Block
* Canteen
* Computer Lab
* Hostel
* Auditorium

## ⚙️ How It Works

1. The campus locations are represented as vertices.
2. The connections between locations are represented as weighted edges.
3. The distance between connected locations is stored in an adjacency matrix.
4. The user enters the **source** and **destination** locations.
5. Dijkstra's Algorithm calculates the minimum distance.
6. The program displays:

   * Shortest distance
   * Shortest route/path between the two locations

### Example

If the user selects:

**Source:** Main Gate
**Destination:** Hostel

The program finds the shortest route and displays the path along with the total distance.

## 💻 Technologies Used

* **Language:** C
* **Compiler:** GCC / MinGW
* **IDE:** Visual Studio Code
* **Graph Visualization:** Graphviz
* **Version Control:** Git & GitHub

## 📂 Project Structure

```text
college-navigation/
│
├── college_navigation.c
├── campus_graph.dot
├── campus_graph.png
└── README.md
```

## 🚀 How to Run

### 1. Clone the repository

```bash
git clone https://github.com/wwwanuragbhardwj2515-sudo/college-navigation.git
```

### 2. Open the project folder

Open the folder in **Visual Studio Code**.

### 3. Compile the program

```bash
gcc college_navigation.c -o college_navigation
```

### 4. Run the program

On Windows:

```bash
college_navigation
```

## 🎯 Objective

The main objective of this project is to demonstrate the practical application of **Graph Data Structures and Dijkstra's Algorithm** in a real-world campus navigation system.

## 👨‍💻 Author

**Anurag Bhardwaj**

AI & Data Science Engineering
University School of Automation and Robotics (USAR), IPU
