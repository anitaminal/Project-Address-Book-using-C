#include "contact.h"

void listContacts(AddressBook *addressBook) 
{
  printf("\n---------------------------------------------------------------------------------\n");
  printf("NAME\t\t\tMOBILE NUMBER\t\t\tEMAIL");
  printf("\n---------------------------------------------------------------------------------\n");
  for(int i=0;i<addressBook->contactCount;i++)
  {
	  printf("\n%s\t%s\t%s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
  }

  printf("\n\n\t\t\t\t***END OF CONTACTS***\n");


} 


int createContact(AddressBook *addressBook) 
{       
	char option[30];
	char mobile[20];
	char id[20];
	int num=0;
	char *e_id;
	char *mob;
	char *ptr;
	char *ptr1;
	char *ret;
	int flag=0;
	int count=0;
	char ch;
//create the name
	printf("Enter the name:");
	scanf(" %29[^\n]", option);
	for(int i=0;i<addressBook->contactCount;i++)
	{
		ret=strstr(addressBook->contacts[i].name, option);
	        if(ret)
		{ 	
			printf("\n%s\t%s\t%s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
		    num=1;
		}       
			
	}
	if(num==0)
	{	
	    strcpy( addressBook->contacts[addressBook->contactCount].name, option);
	}
	else if(num==1)
	{
		printf("\nMatch found\nDo you want to create new contact(y/n)?:");
			scanf(" %c",&ch);
			if(ch=='y')
			{
				strcpy(addressBook->contacts[addressBook->contactCount].name, option);
			
			}else
			{
				return 0;
			}
      
	}
  //create the mobile number
        do
	   {
        	printf("\nEnter the phone:");
 	        scanf(" %s", mobile);
        	count=strlen(mobile);
        	for(int i=0;i<10;i++)
        	{
	        	if(mobile[i]>='0'&&mobile[i]<='9')
		        {
		        	flag=0;
	        	}
	        	else{
		        	flag=1;
		        	break;
		            }
        	}
        	if(count==10 && flag==0)
        	{  num=0;
				for(int i=0;i<addressBook->contactCount;i++)
				{
					mob=strstr(addressBook->contacts[i].phone,mobile);
					if(mob)
					{
			            num=1;
						printf("\n%s\t%s\t%s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
					
					}
				}
				if(num==0)
				{
	        	strcpy(addressBook->contacts[addressBook->contactCount].phone,mobile);
				}else if(num==1){
					printf("\nMOBILE NUMBER MATCH FOUND\n\nEnter unique mobile number");
				}
        	}
	        if(count!=10||flag!=0)
        	{
	        	printf("\nInvalid mobile number\n");
        	}
        }while(count!=10 ||flag!=0 || num==1);
//create the email id
        do
	{
		printf("\nEnter the email id:");
		scanf(" %s", id);
		ptr=strchr(id, '@');
		ptr1=strstr(id, ".com");
		if(ptr==NULL||ptr1==NULL)
		{
			printf("\nInvalid Email");
		}else
		{ num=0;
			for(int i=0; i< addressBook->contactCount;i++)
			{
                e_id=strstr(addressBook->contacts[i].email, id);
				if(e_id)
				{
					num=1;
					printf("\n%s\t%s\t%s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
				}
			}
			if(num==0)
			{
			strcpy(addressBook->contacts[addressBook->contactCount].email, id);
			}else if(num==1)
			{
				printf("\nEMAIL ID MATCH FOUND\n\nEnter a unique email id\n");
			}
		}
	}while((ptr==NULL)||(ptr1==NULL)||(num==1));
//increment contactCount
	addressBook->contactCount++;
	printf("\n\t\t\t\t\t***CONTACT CREATED***\n");
	return 0;

}

void searchContact(AddressBook *addressBook) 
{       
	int choice;
	char name[30];
	int num=0;
	char *ret=NULL;
  do
  {
	printf("\nSearch By:\n1. Name\n2. Mobile Number\n3. Email\n");
	printf("\nEnter your choice:");
	scanf("%d", &choice);

	switch(choice)
	{
		case 1: 
			printf("\n\t\t\t\t\t***SEARCH BY NAME SELECTED***\n");
			printf("\nEnter the name to be searched:");
			scanf(" %29[^\n]",name);
			num=0;
			for(int i=0;i<addressBook->contactCount; i++)
			{
				ret=strstr(addressBook->contacts[i].name, name);
				if(ret)
				{
					     num=1;
			              printf("\n%s\t\t%s\t\t%s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
			         
			    } 
		     }
             if(num==0)
                        {
                                printf("\n\t\t\t\t\tNAME NOT FOUND\n");
	                }
                        break;
               case 2:
                      printf("\n\t\t\t\t\t***SEARCH BY MOBILE NUMBER IS SELECTED***\n");
		      printf("\nEnter the mobile number to be searched:");
		      scanf(" %s", name);
              num=0;
			  for(int i=0;i<addressBook->contactCount;i++)
		      {       
		               ret=strstr(addressBook->contacts[i].phone, name);
			       if(ret)
			       {  
				       printf("\n%s\t\t%s\t\t%s", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
		                num=1;       
		       	       }
		      }
		      if(num==0)
		      {
			      printf("\n\t\t\t\t\tMOBILE NUMBER NOT FOUND\n");
		      }
		      break;
              case 3:
		      printf("\n\t\t\t\t\t***SEARCH BY EMAIL ID SELECTED***\n");
		      printf("\nEnter the email id to be searched: ");
		      scanf(" %s", name);
			  num=0;
		      for(int i=0;i<addressBook->contactCount;i++)
		      {
			      ret=strstr(addressBook->contacts[i].email, name);
			      if(ret)
			      {
					  num=1;
				      printf("\n%s\t\t%s\t\t%s", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
			        
			      }

		      }
		      if(num==0)
		      {
			      printf("\n\t\t\t\t\tEMAIL ID NOT FOUND\n");
		      }
		      break;
		default:
		      printf("\nInvalid choice entered\n Note: Enter number from 1 to 3");
		      break;
	   }			 

	}while(choice>3);		      	

}

int editContact(AddressBook *addressBook) 
{
  int choice;
  int num=0;
  int ret=1;
 
  char *ptr;
  
  char detail[30];
  do
  {
	  printf("\nSearch By:\n1. Name\n2. Mobile Number\n3.Email Id\n");
	  printf("\n Enter the choice:");
	  scanf("%d", &choice);

	 switch(choice)
	 {
		 case 1:
			 printf("\nEnter the name:");
			 scanf(" %29[^\n]", detail);
			 num=0;
			 for(int i=0;i<addressBook->contactCount;i++)
			 {
				 ptr=strstr(addressBook->contacts[i].name, detail);
				 if(ptr)
				 {
					 printf("\nId:%d\t%s\t\t%s\t\t%s", i, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
			                 
					 num=1;							 
		             }
			}
			 if(num==0)
			 {
		         printf("\n\t\t\t\t\tNAME NOT FOUND\n");
			 }
			 if(num==1)
			 {
				int j;
				do
				{
				printf("\nEnter the contact id that is to be edited:");
				scanf("%d", &j);
				if(j<addressBook->contactCount)
				{
					return j;
				}

			    }while(j>addressBook->contactCount);
			}
			 break;

	         case 2:
	     		 printf("\nEnter the mobile number:");
		    	 scanf(" %s", detail);
			      num=0;
			     for(int i=0;i<addressBook->contactCount;i++)
			    {
				 ptr=strstr(addressBook->contacts[i].phone, detail);
				 if(ptr)
				 {
					 printf("\nId: %d\t%s\t\t%s\t\t%s", i, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
					 num=1;    
				 }
			}
			if(num==0)
			{
				printf("\n\t\t\t\t\tMOBILE NUMBER NOT FOUND\n");
			}else if(num==1)
			{
               int j;
				do
				{
				printf("\nEnter the contact id that is to be edited:");
				scanf("%d", &j);
				if(j<addressBook->contactCount)
				{
					return j;
				}

			    }while(j>addressBook->contactCount);
			}
			break;
		 case 3:
			 printf("\nEnter the email id:");
			 scanf(" %s", detail);
			 num=0;
			 for(int i=0;i<addressBook->contactCount;i++)
			 {
				 ptr=strstr(addressBook->contacts[i].email, detail);
				 if(ptr)
				 {
					 printf("\nId:%d\t%s\t\t%s\t\t%s", i, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
			         num=1;        
				 }
			   }
		       	if(num==0)
				{
				printf("\n\t\t\t\t\tMAIL ID NOT FOUND\n");
				}else if(num==1)
				{
					int j;
				do
				{
				printf("\nEnter the contact id that is to be edited:");
				scanf("%d", &j);
				if(j<addressBook->contactCount)
				{
					return j;
				}

			    }while(j>addressBook->contactCount);
				}
			break; 

		default:
			printf("\nInvalid choice entered\nEnter numbers from 1 to 3\n");
			break;
	 }
  }while(choice>3);	 
return 0;
}

void modifycontact(AddressBook *addressBook, int i)
{
   int choice;
   char mem[30];
   int count=0;
   int ret;
   int num=0;
   char *e_id;
   char *mob;
   char *ptr;
   char *ptr1;
	do
	{
		printf("\nYou want to edit:\n1. Name\n2. Mobile Number\n3. Email");
		printf("\nEnter your choice:");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				printf("\nEnter the name: ");
				scanf(" %29[^\n]", mem);
				strcpy(addressBook->contacts[i].name, mem);
				printf("\n\t\t\t\t\t***NAME EDITED***\n");
				break;
			case 2:
				do
				{
					printf("\nEnter the mobile no:");
					scanf(" %s", mem);
					count=strlen(mem);
					for(int i=0;i<10;i++)
					{
						if(mem[i]>='0' &&mem[i]<='9')
						{
							ret=0;
						}else{
							ret=1;
							break;
						}
					}
					if(count==10 && ret==0)
					{
						 num=0;
				         for(int i=0;i<addressBook->contactCount;i++)
				         {
					      mob=strstr(addressBook->contacts[i].phone,mem);
					      if(mob)
					      {
			                     num=1;
						         printf("\n%s\t%s\t%s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
					
					       }
				          }
				        if(num==0)
				        {
	        	                  strcpy(addressBook->contacts[i].phone,mem);
								  printf("\n\t\t\t\t\t***MOBILE NUMBER EDITED***\n");
								  break;
				         }else if(num==1){
					               printf("\nMOBILE NUMBER MATCH FOUND\n\nEnter unique mobile number");
				         }
						
						
					}else{
						printf("\nInvalid mobile number");
					}
				 }while((count!=10)||(ret==1)||(num==1));
			
				 break;
			case 3:
				do{
					printf("\nEnter the email id:");
					scanf(" %s", mem);
					ptr=strchr(mem,'@');
					ptr1=strstr(mem, ".com");
					if(ptr==NULL && ptr1==NULL)
					{
						printf("\nInvalid email");
					}else
					{
						 num=0;
			             for(int i=0; i< addressBook->contactCount;i++)
			             {
                              e_id=strstr(addressBook->contacts[i].email, mem);
				              if(e_id)
				              {
					             num=1;
					             printf("\n%s\t%s\t%s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
				               }
			             }
			            if(num==0)
			            {
			             strcpy(addressBook->contacts[i].email, mem);
						 printf("\n\t\t\t\t\t***EMAIL ID EDITED***\n");
						 break;
			            }else if(num==1)
			            {
				           printf("\nEMAIL ID MATCH FOUND\n\nEnter a unique email id\n");
			            }
						
						
					}
				  }while(ptr==NULL||ptr1==NULL||num==1);
				  break;
			default:
				 printf("\nInvalid choice\nEnter the choice from 1 to 3");
				 break;
		}
	}while(choice>3);
}

int deleteContact(AddressBook *addressBook) 
{
	int choice;
	int num=0;
	char *ptr;
	char ch;
	char detail[30];
	do
	{
		printf("\nSearch By:\n1. Name\n2. Mobile Number\n3. Email\n");
		printf("Enter your choice:");
		scanf("%d", &choice);

		switch(choice)
		{
                   case 1: 
			   printf("\nEnter the name to be searched:");
			   scanf(" %29[^\n]", detail);
			   for(int i=0;i<addressBook->contactCount;i++)
			   {
				   ptr=strstr(addressBook->contacts[i].name, detail);
				   if(ptr)
				   {  
					   printf("\nId:%d\t%s\t\t%s\t\t%s", i, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
					   num=1;
					   
					    
				   }
			 }
		         if(num==0)
				 {
			       printf("\n\t\t\t\t\tNAME NOT FOUND\n");
				 }else if(num==1)
				 {
					int i;
					do{
					printf("\nEnter the contact id that need to be deleted:");
					scanf("%d", &i);
					if(i<addressBook->contactCount)
					{
                     do{
					            printf("\nDo you want to delete this contact(y/n):");
					            scanf(" %c", &ch);
					            if(ch=='n')
					            {
						           return 0;
					            }
					            else if(ch=='y')
					            {
						           for(int j=i; j<addressBook->contactCount;j++)
						           {
						             strcpy(addressBook->contacts[j].name, addressBook->contacts[j+1].name);
						             strcpy(addressBook->contacts[j].phone, addressBook->contacts[j+1].phone);
						             strcpy(addressBook->contacts[j].email, addressBook->contacts[j+1].email);
						            }
						             addressBook->contactCount--;
							     printf("\n\t\t\t\t\t***CONTACT DELETED***\n");
				                      }else
					             {
					                      printf("\nInvalid choice entered\n");
					              }
					     }while(ch!='y'&& ch!='n');	
					}
				 }while(i>addressBook->contactCount);
				}
			    break;
	 case 2:
	        
			 printf("\nEnter the mobile number:");
			 scanf(" %s", detail);
			 num=0;
			 for(int i=0;i<addressBook->contactCount;i++)
			 {
				ptr=strstr(addressBook->contacts[i].phone,detail);
				if(ptr)
				{
					printf("\nId:%d\t%s\t\t%s\t\t%s", i, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
					num=1;
				}
			  }
		          if(num==0)
				  {
			      printf("\n\t\t\t\t\tMOBILE NUMBER NOT FOUND\n");
				  }else if(num==1)
				  {int i;
					do{
					
					printf("\nEnter the contact Id that need to be deleted:");
					scanf("%d", &i);
				    if(i<addressBook->contactCount)
					{
                         do
					     {
						    printf("\nDo you want to delete this contact(y/n)?");
						    scanf(" %c", &ch);
						    if(ch=='n')
						    {
							    return 0;
						    }
						    else if(ch=='y')
						    {
							   for(int j=i;j<addressBook->contactCount;j++)
							   {
								strcpy(addressBook->contacts[j].name, addressBook->contacts[j+1].name);
								strcpy(addressBook->contacts[j].phone, addressBook->contacts[j+1].phone);
								strcpy(addressBook->contacts[j].email, addressBook->contacts[j+1].email);
							   }
							addressBook->contactCount--;
							printf("\n\t\t\t\t\t***CONTACT DELETED***\n");
						    }else
						    {
							printf("\nInvalid choice entered");
						    }
					     }while(ch!='n'&&ch!='y');
				    }
				}while(i>addressBook->contactCount);
			}
		break;		  
  
        case 3: 
                 printf("\nEnter the email id:");
		         scanf(" %s", detail);
				 num=0;
		         for(int i=0; i<addressBook->contactCount; i++)
		        {
			         ptr=strstr(addressBook->contacts[i].email, detail);
					 
			         if(ptr)
					 {
			  	         printf("\nId:%d\t%s\t\t%s\t\t%s", i, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
				         num=1;
						 
			         }
                }		 
	            if(num==0){
	            printf("\n\t\t\t\t\tEMAIL ID NOT FOUND\n");
				}else  if(num==1)
				{   int i;
					do{
				
					printf("\nEnter the contact Id that need to be deleted:");
					scanf("%d", &i);
					if(i<addressBook->contactCount)
					{
                         do
				         {
					         printf("\nDo you want to delete this contact(y/n)?");
					         scanf(" %c", &ch);
					          if(ch=='n')	
					          {
						           return 0;
					           }else if(ch=='y')
					          {
						        for(int j=i;j<addressBook->contactCount;j++)
						        {
							       strcpy(addressBook->contacts[j].name, addressBook->contacts[j+1].name);
							       strcpy(addressBook->contacts[j].phone, addressBook->contacts[j+1].phone);
							       strcpy(addressBook->contacts[j].email, addressBook->contacts[j+1].email);
						        }
						        addressBook->contactCount--;
						        printf("\n\t\t\t\t\t***CONTACT DELETED***\n");
				       	      }else{
						       printf("\nInvalid choice entered\n");
					          }
				         } while(ch!='n'&&ch!='y');
		                  
					}
				}while(i>addressBook->contactCount);

				}
                    break;	 
           default:
                      printf("\nInvalid choice entered\nEnter the numbers from 1-3");
	              break;
	 }
	}while(choice>3);		   
     
      return 0;  

}
