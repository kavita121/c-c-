#include <stdio.h>
 
int check_anagram(char a[], char b[])
{
  int first[26] = {0}, second[26] = {0}, c=0,flag=0;
 
  while (a[c] != '\0')
  {
	if (a[c]>90)
		a[c]=a[c]-32;
    first[a[c]-'A']++;
    c++;
  }
 
  c = 0;
 
  while (b[c] != '\0')
  {
	if (b[c]>90)
		b[c]=b[c]-32;  
    second[b[c]-'A']++;
    c++;
  }
 
  for (c = 0; c < 26; c++)
  {
    if (first[c] != second[c])
      flag=1;
  }
  return flag;
}
 
int main()
{
  char a[100], b[100];
 
  printf("Enter a string\n");
  scanf("%s",&a);
 
  printf("Enter a string\n");
  scanf("%s",&b);
 
  if (check_anagram(a, b) == 1)
    printf("The strings are not anagrams.\n");
  else
    printf("The strings are anagrams.\n");
}
 
