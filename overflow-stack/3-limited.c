/*fgets() will read at most one less than sizeof (buf) characters (it will terminate the string with a null); it will read to a NL character or to one less than the size of the buffer (the NL character will be included in the buffer and the string will be terminated with a NULL).
Your loop reads 99 characters, prints them, then reads whatever is left in the system buffer (not your buffer, the I/O buffer maintained by the system) and prints those.
A slightly more "standard" way might be something like this (which is reading from a file rather than the keyboard):
The token, BUFSIZ, is a numeric value (defined as 8192 on many 64-bit systems) -- it doesn't hurt anything (and can be beneficial) to use BUFSIZ for I/O buffering as above; 8K isn't a heck of lot of memory to allocate for this purpose (and you can use the same buffer space again and again throughout a program).
Also, read the manual page for fgets for more information.
ref: http://www.linuxquestions.org/questions/programming-9/fgets-and-buffer-overflow-4175467362 */

#include <stdio.h>
#include <stdlib.h>

void main (void)
{
    char buf [BUFSIZ];
    FILE *helpfile;

    if ((helpfile = fopen ("instructions", "r")) == (FILE *) NULL){
        (void) fprintf (stderr, "can't open instructions\n");
        exit (EXIT_FAILURE);
    }

    while (fgets (buf, BUFSIZ, helpfile) != (char *) NULL)
        (void) fputs (buf, stdout);

    (void) fclose (helpfile);
    exit (EXIT_SUCCESS);
}
