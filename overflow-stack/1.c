void func(char *str)
{
   char buffer[5];
   strcpy(buffer, str);
}

int main()
{
   char string[16];
   printf("input any data\n");
   gets(string); //or even scanf, they are unbounded string size
   func(string);
   printf("Next data goes here\n");
   return 0;
}
