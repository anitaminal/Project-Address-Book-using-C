#ifndef CONTACT_H
#define CONTACT_H

#define MAX_CONTACTS 100

#include <stdio.h>
#include <string.h>

typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact;

typedef struct {
    Contact contacts[MAX_CONTACTS];
    int contactCount;
} AddressBook;

int createContact(AddressBook *addressBook);
void searchContact(AddressBook *addressBook);
int editContact(AddressBook *addressBook);
int deleteContact(AddressBook *addressBook);
void listContacts(AddressBook *addressBook);
int populate_contact(AddressBook *addressBook);
int savecontact(AddressBook *addressBook);
void modifycontact(AddressBook *addressBook, int i);
#endif
