# Project-Address-Book-using-C

Project Overview

A console-based Address Book application developed in C that enables users to add, search, edit, delete, and manage contact details, including names, mobile numbers, and email addresses. The application uses file handling to store contact information in a CSV file.

Requirements Details:
1. Add Contact
2. Search Contact
3. Edit Contact
4. Delete Contact
5. List All Contacts
6. Save the address Book
7. Exit the application

Pre-requisities:
1. File I/O
2. String Handling
3. Pointers
4. Structures
5. Arrays
6. csv file handling

Design Overview:

1. Read contact details from a CSV file and store them in an array of structures.
2. Display a menu containing the available operations, 1. Create Contact, 2. Edit Contact, 3. Search Contact, 4. Delete Contact, 5. List Contact, 6. Save and Exit.
3. Accept the user's choice and use a switch statement to invoke the appropriate function.
4. Perform the selected operation, such as creating, editing, searching, deleting, or listing contacts.
5. Save the contact details to the CSV file when the user selects the save-and-exit option.
   
Functional Description

1. Create Contact
  * Read the contact name from the user.
  *  Check whether a contact with the same name already exists.
  *  If the name is not present, proceed to create a new contact.
  *  If a matching name exists, display the existing details and ask the user whether they want to continue creating the contact.
  *  Read the mobile number and validate that it contains exactly 10 digits.
  *  Read the email address, validate it according to the implemented validation rules, and store the contact details.

2. Edit Contact
  * Allow the user to search for a contact using its name, mobile number, or email address.
  * Read the selected search criterion and its value.
  * Display matching contact details and ask the user to select the contact ID to edit.
  * Validate the updated information and modify the selected contact.

3. Search Contact
  * Ask the user to select a search criterion.
  * Accept the corresponding search value.
  * Display the matching contact details if a contact is found.

4. Delete Contact
  * Ask the user to select a search criterion.
  * Accept the name, mobile number, or email address to search for.
  * Display the matching contact details.
  * Ask for confirmation before deleting the selected contact.

5. List All Contacts
  * Display all contact details stored in the array of structures in the console.

6. Save and Exit
  * Save the contact details to the CSV file and terminate the application.

Concepts Practiced
  * Structures and arrays
  * Pointers and string handling
  * File handling in C
  * Input validation
  * Menu-driven programming
  * Functions and conditional logic

Learning Outcomes

This project provides practical experience in organizing structured data, implementing contact-management operations, validating user input, and maintaining contact records using file handling in C.

   
