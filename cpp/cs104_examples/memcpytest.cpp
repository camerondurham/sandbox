/* memcpy example */
#include <stdio.h>
#include <string.h>


int main ()
{
  char myname[] = "Pierre de Fermat";
  char partialname[10];

  // copy from destination
  memcpy ( partialname, myname, strlen(myname) - 6 );
  partialname[9] = '\0';

  /* using memcpy to copy structure: */
  //memcpy ( &person_copy, &person, sizeof(person) );

  printf("myname: %s \npartialname: %s\n", myname, partialname);

  return 0;
}
