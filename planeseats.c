#include <stdio.h>

int main(void) {
   //Variables
   char menu[]="\nPlease Type '1' for first class \nPlease Type '2' for economy \nPlease Type '0' to quit: \nEnter:";
   char noMoreFirstSeats[]="\nNo more first class seats available.\n\nWould you like to switch to economy? (y/n)\nEnter:";
   char noMoreEcoSeats[]="\nNo more economy class seats available.\n\nWould you like to switch to first class? (y/n)\nEnter:";
   int userInput;
   int firstclassPointer = 1;
   int economyPointer = 5;
   //Seats Array
   int Seats[12] = {};

   while(1){
      //first class seats <= 4 & economy class seats <= 12
      int firstClassAvailable = firstclassPointer <= 4;
      int economyAvailable = economyPointer <= 12;
      //Print Menu and get user input
      printf("%s", menu);
      scanf("%i", &userInput);
      //If user types 0 quit program
      if(userInput == 0){
         return 0;
      }
      //first class selection
      if(userInput == 1){
         if(firstClassAvailable){
            printf("\nThank you, Your seat number is %i in first class\n", firstclassPointer);
            firstclassPointer++;
         }
         //if no more seats avaible prompt user
         else if(economyAvailable){
            char wantsToSwitch;
            printf("%s", noMoreFirstSeats);
            scanf("%s", &wantsToSwitch);
            if(wantsToSwitch == 'y'){
               printf("\nThank you, Your seat number is %i in economy class\n", economyPointer);
               economyPointer++;
            }
            else if(wantsToSwitch == 'n'){
               printf("\nNext Flight departs tommorow \n");
            }
            else if(wantsToSwitch != 'n' || wantsToSwitch != 'y'){
               printf("%s", noMoreFirstSeats);
               scanf("%s", &wantsToSwitch);
            }
         }
         else{
            printf("\nNo more seats available. Next Flight departs tommorow \n");
         }
      }
      //Economy class selection
      else if(userInput == 2){
         if(economyAvailable){
            printf("\nThank you, Your seat number is %i in economy class\n", economyPointer);
            economyPointer++;
         }
         //if no more seats avaible prompt user
         else if(firstClassAvailable){
            char wantsToSwitch;
            printf("%s", noMoreEcoSeats);
            scanf("%s", &wantsToSwitch);
            if(wantsToSwitch == 'y'){
               printf("\nThank you, Your seat number is %i in first class\n", firstclassPointer);
               firstclassPointer++;
            }
            else if(wantsToSwitch == 'n'){
               printf("\nNext Flight departs tommorow \n");
            }
            else if(wantsToSwitch != 'n' || wantsToSwitch != 'y'){
               printf("%s", noMoreEcoSeats);
               scanf("%s", &wantsToSwitch);
            }
         }
         else{
            printf("\nNo more seats available. Next Flight departs tommorow \n");
         }
      }
      else{
         printf("\nNo more seats available. Next Flight departs tommorow \n");
      }
   }
   printf("\nThank you for using our airline system. Goodbye\n");
   return 0;
}
