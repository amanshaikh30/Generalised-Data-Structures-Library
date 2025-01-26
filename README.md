
# Generalized Data Structures Library (GDSL)

A robust C++ library implementing a variety of fundamental data structures with support for multiple data types using templates. This project is designed to provide a modular, reusable, and user-friendly framework for operations on linked lists, stacks, and queues.

## Features

- **Linked Lists**:
  - Singly Linear
  - Doubly Linear
  - Singly Circular
  - Doubly Circular
- **Stack and Queue** with basic operations:
  - Insert (Push/Enqueue)
  - Delete (Pop/Dequeue)
  - Count elements
  - Display elements
- **Generic Programming**: Uses templates for multi-type support (int, float, double, char, etc.).
- **Menu-Driven Interface**: An interactive console interface for seamless user interaction.

## Getting Started

### Prerequisites
- C++ compiler (e.g., GCC)
- Compatible IDE or terminal environment

### Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/amanshaikh30/GDSL.git
   ```
2. Navigate to the project directory:
   ```bash
   cd GDSL
   ```
3. Compile the program:
   ```bash
   g++ GDSL.cpp -o GDSL
   ```
4. Run the executable:
   ```bash
   ./GDSL
   ```

## Usage

Upon running the program, you will be presented with a menu to:
- Choose the data structure type (Linked List, Stack, Queue).
- Select the data type (int, float, double, char).
- Perform operations such as insertion, deletion, display, and count.

## Example

### Sample Interaction:
```
---------------------------------------------------------------------- 
----------- Welcome to Generalized Data Structures Library ----------- 
---------------------------------------------------------------------- 

1. Singly Linear LinkedList
2. Doubly Linear LinkedList
3. Singly Circular LinkedList
4. Doubly Circular LinkedList
5. Stack
6. Queue
7. Exit

Select an operation that you want to perform: 1
...
```

## Project Structure

- **Templates**: Ensure reusability across different data types.
- **Modular Design**: Each data structure is implemented as a separate class.
- **Interactive UI**: Console-based interface for easier operation.

## Contributions

Contributions are welcome! Feel free to fork this repository, submit issues, or create pull requests for improvements.

