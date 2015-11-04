#include <stdio.h>
#include <stdlib.h>

int main()
{
   char *name;
   char *command;

   name=(char *)malloc(10);
   command=(char *)malloc(128);

   printf("address name: %d\n", name);
   printf("address cmd: %d\n", command);
   printf("difference: %d\n", command-name);

   printf("Enter with your name: %s\n", name);
   gets(name); //buffer overflow

   printf("Hello %s\n", name);
   system(command);

   return 0;
}
