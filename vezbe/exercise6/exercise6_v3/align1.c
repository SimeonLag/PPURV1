#include <stdio.h>
#include <stdint.h>
//#pragma pack(push)  /* push current alignment to stack */
//#pragma pack(1)     /* set alignment to 1 byte boundary */

//#pragma pack(2)

typedef struct _example_struct //poravnanje se gleda u odnosu na najvece polje
{
	uint8_t   char_a;
	uint32_t  uint_b;
	uint16_t  short_c;
	uint16_t  short_d;
//} example_struct;
} __attribute__ ((packed)) example_struct;

//#pragma pack(pop)   /* restore original alignment from stack */

//poravnanje se gleda npr short na svaka 2, int na svaka 4 tj moraju biti deljivi sa tim brojem. Char moze gde oce(neparni)
//takodje se gleda i poravnanje izmedju struktura kad bi imali niz struktura

int main(void)
{	
	int8_t arr1[3];
	int8_t arr2[1];
	example_struct ex_struct;
	
	printf("arr1     size %d  \taddr: %p (4-byte alligned: %s)\n", sizeof(arr1),  &arr1,      ((uintptr_t)(&arr1)%4)      ? "NO" : "YES");
	printf("arr2     size %d  \taddr: %p (4-byte alligned: %s)\n", sizeof(arr2),  &arr2,      ((uintptr_t)(&arr2)%4)      ? "NO" : "YES");
	printf("struct   size %d  \taddr: %p (4-byte alligned: %s)\n", sizeof(example_struct), &ex_struct, ((uintptr_t)(&ex_struct)%4) ? "NO" : "YES");
		
	return 0;
}
