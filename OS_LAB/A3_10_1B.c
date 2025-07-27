/**************************************************************************************
* Name - Sougata Saha, Soham Chakraborty
* Roll - 002311001037, 002311001042
* Team No - 10
* Date - 26/07/2025
* Group - A3

* Assignment - 1B
* Assignment Description - Program to get and set environment variables using system calls
* Input Description - Takes 2 environment variables and value pair
* Output Description - Displays the following environment variable and value pairs : USER, HOME, ARCH, DISPLAY, PRINTER, PATH, 2 custom environment variables

* Compilation command - gcc A3_10_1B.c
* Execution command - ./a.out COLLEGE "Jadavpur University" CURRLAB "OS Lab"

* Sample Input and Output - 

* USER     = soham
* HOME     = /home/soham
* HOSTNAME = (null)
* ARCH     = (null)
* DISPLAY  = :0
* PRINTER  = (null)
* PATH     = /usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/usr/lib/wsl/lib:/mnt/c/Program Files/WindowsApps/MicrosoftCorporationII.WindowsSubsystemForLinux_2.5.9.0_x64__8wekyb3d8bbwe:/mnt/c/Program Files/Common Files/Oracle/Java/javapath:/mnt/c/WINDOWS/system32:/mnt/c/WINDOWS:/mnt/c/WINDOWS//WindowsApps:/mnt/c/Users/SOHAM/AppData/Local/Programs/Microsoft VS Code/bin:/mnt/c/Users/SOHAM/AppData/Roaming/npm:/snap/bin

* Custom environment variables:
* COLLEGE = Jadavpur University
* CURRLAB = OS Lab
********************************************************************************************/


#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    printf("USER = %s\n", getenv("USER"));
    printf("HOME = %s\n", getenv("HOME"));
    printf("HOSTNAME = %s\n", getenv("HOSTNAME"));
    printf("ARCH = %s\n", getenv("ARCH"));
    printf("DISPLAY = %s\n", getenv("DISPLAY"));
    printf("PRINTER = %s\n", getenv("PRINTER"));
    printf("PATH = %s\n", getenv("PATH"));

    if (argc < 5) {
        printf("\nUsage: %s var1 val1 var2 val2\n", argv[0]);
        return 1;
    }

    setenv(argv[1], argv[2], 1);
    setenv(argv[3], argv[4], 1);

    printf("\nCustom environment variables:\n");
    printf("%s = %s\n", argv[1], getenv(argv[1]));
    printf("%s = %s\n", argv[3], getenv(argv[3]));

    return 0;
}