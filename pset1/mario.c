#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int cond, userint;
    cond = 0;
    while(cond == 0) {
            userint = get_int("Height: \n");

        if (userint >= 1 && userint <= 8) {
					cond = 1;
				}
			}
            int counter = userint - 1;
			int counter2 = userint - counter;
			int spacecounter = 1;

			while (counter > -1) {
			counter2 = userint - counter;
				for(int j = 0; j< userint-spacecounter; j++) {
					printf(" ");
				}

			for (int i = 0; i <counter2; i++) {
				printf("#");
			}

			printf("  ");

			for (int i = 0; i <counter2; i++) {
				printf("#");
			}
			counter = counter - 1;
			spacecounter = spacecounter + 1;
			printf("\n");
			}
		}