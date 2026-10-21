#include "contact.h"

int main()
{
   //declare the integer variable choice
    int choice;
   //declare the structure variable
    AddressBook s1;
   //initialize addressbook from file
   populate_contact(&s1);
   do
   {
	  printf("\n1. Create Contact\n");
	  printf("2. Edit Contact\n");
	  printf("3. Search Contact\n");
	  printf("4. Delete Contact\n");
	  printf("5. List Contact\n");
	  printf("6. Save and Exit\n");

	  printf("\nEnter your choice(1-6):");
	  scanf("%d", &choice);

	  switch(choice)
	  {
		  case 1:
			  printf("\n\t\t\tCREATE CONTACT IS SELECTED\n");
			  createContact(&s1);
			  break;
		  case 2:
			  printf("\n\t\t\tEDIT CONTACT IS SELECTED\n");
                          int i=editContact(&s1);
		           modifycontact(&s1, i);
			  break;
		  case 3:
			  printf("\n\t\t\tSEARCH CONTACT IS SELECTED\n");
                          searchContact(&s1);
			  break;
		  case 4:
			  printf("\n\t\t\tDELETE CONTACT IS SELECTED\n");
                          deleteContact(&s1);
			  break;
		  case 5:
			  printf("\n\t\t\tLIST CONTACT IS SELECTED\n");
			  listContacts(&s1);
			  break;
		  case 6:
			  printf("\n\t\t\tSAVE CONTACT IS SELECTED\n");
                          savecontact(&s1);
	      		  break;
		  default:
			  printf("\n\t\t\tINVALID OPTION\n\nNote:Enter the option from 1 to 6\n");
			  break;
	  }

      }while(choice!=6);

   return 0;
}

