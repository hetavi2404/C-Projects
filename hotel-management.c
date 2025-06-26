#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

int roomCount=0;
int customerCount=0;
int room_no[MAX],room_price[MAX],availability[MAX],room_type[MAX];
int cust_name[50],cust_phone,cust_staydays;

void addRoom(){

    if(roomCount >= MAX){
        printf("Room limit reached!\n");
        return;
    }

    printf("Enter the number of rooms: ");
    int n;
    scanf("%d",&n);

    for(int i=0;i<n;i++){

        printf("Enter room number: ");
        scanf("%d",&room_no[i]);
        printf("1. Single\n2. Double\n3. Deluxe\nEnter room type: ");
        scanf("%d",&room_type[i]);
        printf("Enter room price: ");
        scanf("%d",&room_price[i]);
        availability[i] = 1;
        roomCount++;
        printf("Room %d has been added successfully.\n",room_no[i]);

    }

}

void updateRoom(){

    int no;
    printf("1. Update Price of Rooms\n2. Update Availability of Rooms\nEnter your chocie: ");
    int ch;
    scanf("%d",&ch);

    switch(ch){
        case 1: printf("Enter the room number: ");
                scanf("%d",&no);
                printf("Enter the new price: ");
                int price;
                scanf("%d",&price);
                for(int i=0;i<roomCount;i++){
                    if(no==room_no[i]){
                        room_price[i]=price;
                        printf("Room price has been updated to %d\n",room_price[i]);
                    }
                }
                break;
        case 2: printf("Enter the room number: ");
                scanf("%d",&no);
                for(int i=0;i<roomCount;i++){
                    if(room_no[i]==no){
                        if(availability[i]==0){
                            availability[i]=1;
                            printf("The room availability has been changed to available.\n");

                        }else if(availability[i]==1){
                            availability[i]=0;
                            printf("The room availability has been changed to booked.\n");
                        }
                    }
                }
                break;
        default: printf("Invalid Choice!!\n");
    }

}

void viewBookedAvailable(){

    printf("Booked Rooms: \n");
    if(roomCount==0){
        printf("No booked rooms available.\n");    
    }else{
        for(int i=0;i<roomCount;i++){
            if(availability[i]==0){
                printf("Room : %d -> Type[single, double, deluxe] : %d -> Price : %d\n",room_no[i],room_type[i],room_price[i]);
            }
        }
    }

    printf("Available Rooms: \n");
    if(roomCount==0){
        printf("No booked rooms available.\n");    
    }else{
        for(int i=0;i<roomCount;i++){
            if(availability[i]==1){
                printf("Room : %d -> Type[single, double, deluxe] : %d -> Price : %d\n",room_no[i],room_type[i],room_price[i]);
            }
        }
    }

}

void bookRoom(){

    printf("Enter your name: ");
    scanf("%s",cust_name);
    printf("Enter your contact informaton [phone]: ");
    scanf("%d",&cust_phone);
    printf("Enter number of stay days: ");
    scanf("%d",&cust_staydays);

    printf("1. Single\n2. Double\n3. Deluxe\nEnter the room type: ");
    int type;
    scanf("%d",&type);
    
    for(int i=0;i<roomCount;i++){
        if(availability[i]==1 && type==room_type[i]){
            availability[i]=0;
            printf("Room %d has been booked successfully!!\n",room_no[i]);
            break;
        }
    }

}

void viewAvailableRooms(){

    printf("Available Rooms: \n");
    if(roomCount==0){
        printf("No booked rooms available.\n");    
    }else{
        for(int i=0;i<roomCount;i++){
            if(availability[i]==1){
                printf("Room : %d -> Type[single, double, deluxe] : %d -> Price : %d\n",room_no[i],room_type[i],room_price[i]);
            }
        }
    }

}

void checkIn(){

    printf("Enter your room number: ");
    int no;
    scanf("%d",&no);
    for(int i=0;i<roomCount;i++){
        if(availability[i]==1 && room_no[i]==no){
            availability[i]=2;
            printf("Room %d has been checked-in successfully.\n",room_no[i]);
            break;
        }else{
            printf("Room %d is not booked or does not exist.\n",room_no[i]);
            break;
        }
    }

}

void checkOut(){

    printf("Enter your room number: ");
    int no;
    scanf("%d",&no);
    for(int i=0;i<roomCount;i++){
        if(availability[i]==2 && room_no[i]==no){
            availability[i]=1;
            printf("Room %d has been checked-out successfully.\n",room_no[i]);
            break;
        }else{
            printf("Room %d is not booked, checked-in or does not exist.\n",room_no[i]);
            break;
        }
    }

}

void cancelBooking(){

    printf("Enter your room number: ");
    int no;
    scanf("%d",&no);
    for(int i=0;i<roomCount;i++){
        if(availability[i]==0 && room_no[i]==no){
            availability[i]=1;
            printf("Room %d has been cancelled successfully.\n",room_no[i]);
        }else{
            printf("Room %d is not booked, does not exist or had already been checked-in.\n",room_no[i]);
        }
    }    

}

int main(){

    int ch,adm,cust;

    while(1){

        printf("\nHotel Booking System\n");
        printf("\nLOGIN\n");
        printf("1. ADMIN\n2. Customer\n3. Exit\nEnter your choice: ");
        scanf("%d",&ch);

        switch(ch){
            case 1: printf("Enter admin password: ");
                    int pwd;
                    scanf("%d",&pwd);
                    if(pwd==2404){
                    
                        while(1){

                            printf("1. Add Room\n2. Update Room Details\n3. View Booked and Available Rooms\n4. Manage Customer Records\n5. Exit\nEnter your choice: ");
                            scanf("%d",&adm);

                            if(adm==1){
                                addRoom();
                            }else if(adm==2){
                                updateRoom();
                            }else if(adm==3){
                                viewBookedAvailable();
                            }else if(adm==4){
                                
                            }else if(adm==5){
                                break;
                            }else{
                                printf("Invalid Choice!!\n");
                            }
                        }

                    }else{
                        printf("Wrong password!!\n");
                    }
                    break;

            case 2: while(1){

                        printf("1. Books a Room\n2. View Available Rooms\n3. Check-In\n4. Check-Out\n5. Cancel Booking\n6. Exit\nEnter your choice: ");
                        scanf("%d",&cust);
                        
                        if(cust==1){
                            bookRoom();
                        }else if(cust==2){
                            viewAvailableRooms();
                        }else if(cust==3){
                            checkIn();
                        }else if(cust==4){
                            checkOut();
                        }else if(cust==5){
                            cancelBooking();
                        }else if(cust==6){
                            break;
                        }else{
                            printf("Invalid Choice!!\n");
                        }
                    }

                    break;

            case 3: printf("Exiting...");
                    return 0;
                    
            default: printf("Invalid Choice!!\n");
        }

    }

}