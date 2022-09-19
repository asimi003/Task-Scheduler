# Task-Scheduler

Software Construction & Unit Testing & Valgrind 

## Description

Implemented the Structural-Composite design pattern as a part of the Task Scheduler and the Creational-Builder design pattern to handle the varying types of tasks.

Input is taken from the users to generate visual blocks of Tasks with due dates, descriptions, and further details. Output will display a calendar with the tasks in a user-friendly manner. The program will notify users if their task is due today. Output will display a calendar with the tasks in a user-friendly manner. The program will notify users if their task is due today.

Used C++, github, PuTTy, and gtest. C++ for an objected oriented programming workspace, GitHub for version control system and for a backup repository, PuTTY to connect to Hammer, and GTest to create unit tests and make sure the program's classes work as intended.

## Testing

Created test cases and tested each individual task, classification, builder, and planner class in order to validate the cases. Also tested examples using the planner for undoing tasks. Tasks and classifications are IMMUTABLE in testing.

## Class Diagram

![UMLDiagram](https://user-images.githubusercontent.com/97551999/191020852-72dc20c1-3b03-4e55-83ff-58564e3eb2f1.png)

## Installation and Usage

The program installation requires someone to be able to call a .out file.

- The user is prompted with a main menu. They are shown 5 options which are : “Create a task”, “Remove a task”, “View all reminders”, “Edit a task”, “Undo”, and “Exit”
- Creating a task allows the user to create a task or a tasklist.
  - Task creation asks the user to enter title, description, classification, due date, and end date.
- Removing a task allows the user to remove a task from the planner.
  - Asks the user for the title of the task.
- Viewing all reminders displays each task to the console.
  - Displays simply to the console.
- Edit a task changes the task details
  - Task edit asks the user to edit a title, description, classification, due date, OR end date.
- Undo reverts back to the previous task before editing.
  - Simply undos.
- Exit, exits the program

## Screenshots

![1](https://user-images.githubusercontent.com/97551999/191024967-d1d16728-d3ab-4f5c-a74b-bf86256e98c1.png)
![2](https://user-images.githubusercontent.com/97551999/191024969-40d80610-e7a2-4959-961f-778485d6eb33.png)
![3](https://user-images.githubusercontent.com/97551999/191024972-a70cf906-8ea6-4a9f-8fd7-954f80a6f463.png)
![4](https://user-images.githubusercontent.com/97551999/191024974-7aab3a3c-2d13-4068-bd28-8f67a06601ce.png)
