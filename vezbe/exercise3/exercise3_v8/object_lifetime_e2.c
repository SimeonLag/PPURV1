/*
 * object_lifetime_e2.c
 *
 *  Created on: Oct 15, 2020
 *      Author: rtrk
 */
int main()
{
 int i;
 int x;
 int y;
 for (i = 0; i < 5; i++)
 {
 int x = 0;
 static int y = 0; //desi se samo jednom
 printf("x=%d, y=%d\n", x++, y++);
 }
 printf("\nx=%d, y=%d\n", x++, y++);
 return 0;
}


