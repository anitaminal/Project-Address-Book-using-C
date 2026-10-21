#include "contact.h"
/*
// Dummy contact data
static Contact dummyContacts[] = {
    {"John Doe", "1234567890", "john@example.com"},
    {"Alice Smith", "0987654321", "alice@example.com"},
    {"Bob Johnson", "1112223333", "bob@company.com"},
    {"Carol White", "4445556666", "carol@company.com"},
    {"David Brown", "7778889999", "david@example.com"},
    {"Eve Davis", "6665554444", "eve@example.com"},
    {"Frank Miller", "3334445555", "frank@example.com"},
    {"Grace Wilson", "2223334444", "grace@example.com"},
    {"Hannah Clark", "5556667777", "hannah@example.com"},
    {"Ian Lewis", "8889990000", "ian@example.com"}
};*/

int populate_contact(AddressBook *addressBook)
{
	//declare the file pointer
	FILE *fptr;
	//open the file contact.csv
	fptr=fopen("contact.csv", "r");
	//check whether file is opened
	if(fptr==NULL)
	{
		printf("Failed to open file\n");
		return 0;
	}
	addressBook->contactCount=0;
	while(!feof(fptr))
	{
	if(fscanf(fptr,"%[^,],%[^,],%[^\n]\n", addressBook->contacts[addressBook->contactCount].name, addressBook->contacts[addressBook->contactCount].phone, addressBook->contacts[addressBook->contactCount].email)==3){
                                
		addressBook->contactCount++;}
	}
	//close the file
	fclose(fptr);
	//print the read nested structure
/*	printf("No of contents:%d\n", addressBook->contactCount);
        //print the contents
	for(int i=0;i<addressBook->contactCount;i++)
	{
		printf("%s %s %s", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
	}*/
		return 0;
}

int savecontact(AddressBook *addressBook)	
{
     FILE  *fptr;
     char ch;     
     fptr=fopen("contact.csv", "w");
     if(fptr==NULL)
     {
        printf("Failed to open file");
        return 0;
     }
     for(int i=0;i<addressBook->contactCount;i++)
     {
     fprintf(fptr, "%s,%s,%s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
     
     }
     printf("\n\t\t\t\t\t***CONTACTS  SAVED***\t\t");
     
      fclose(fptr);

}
