#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <inttypes.h>


static const int_least32_t treshold1 = 20;
static const int_least32_t treshold2 = 30;
static const int_least32_t treshold3 = 40;

static int_least32_t tresholds[3];

typedef struct _s
{
	int_least32_t value;
	int_least16_t index;
} val_ind_struct_t;

static val_ind_struct_t struct_array[4000];

void (*ptr[2]) (val_ind_struct_t* str_array, int_least16_t n);


static void bubble_sort(val_ind_struct_t* str_array, int_least16_t n)
{
	int_least16_t i;
	int_least16_t j;
	for (i = 0; i < (n - 1); i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (str_array[i].value < str_array[j].value)
			{
				val_ind_struct_t tmp;
				
				tmp = str_array[i];
				str_array[i] = str_array[j];
				str_array[j] = tmp;
			}
		}
	}
}
static int compare(void* val1, void* val2){
	int_least32_t values1 = ((val_ind_struct_t*) val1)->value;
	int_least32_t values2 = ((val_ind_struct_t*) val2)->value;
	if(values1 > values2) {
		return 1;
	}
	else if(values1 == values2) {
		return 0;
	}
	else{
		return -1;
	}
}


static void quick_sort(val_ind_struct_t* str_array, int_least16_t n)
{
	// sort using qsort standard function
	qsort(str_array, (size_t)n, sizeof(val_ind_struct_t), compare);
}


static void print(const val_ind_struct_t* str_array, int_least16_t n, int_fast8_t tr_index)
{
	int_least16_t i = 0;
	int_least32_t treshold;
	printf("Up to the %"PRIdFAST8". treshold: ", tr_index);

	/*switch (tr_index)
	{
	case 1:
		treshold = treshold1;
		break;
	case 2:
		treshold = treshold2;
		break;
	case 3:
		treshold = treshold3;
		break;
	}*/
	for(i=0;i<3;i++){
		if(i==tr_index-1){
			treshold = tresholds[i];
		}
	}
	i = 0;
	while (str_array[i].value > treshold && i < n)
	{
		printf("%"PRIdLEAST32"(%"PRIdLEAST16") ", str_array[i].value, str_array[i].index);
		i++;
	}
	printf("\n");
}


void main()
{
	int_least16_t i;
	int_least16_t n;
	int_fast8_t treshold_index;
	int_fast8_t sort_index;

	printf("Number of elements: ");
	scanf("%"SCNdLEAST16, &n);
	printf("\n");
	for (i = 0; i < n; i++)
	{
		printf("%"PRIdLEAST16". element: ", i);
		scanf("%"SCNdLEAST32, &(struct_array[i].value));
		struct_array[i].index = i;
		printf("\n");
	}
	printf("Trashold you want to use (1, 2, or 3): ");
	scanf("%"SCNdFAST8, &treshold_index);
	printf("\n");
	printf("Sorting algorithm you want to use (1- bubble, 2- quick): ");
	scanf("%"SCNdFAST8, &sort_index);
	printf("\n");

	int_least32_t temp = 20;
	for(i=0;i<3;i++) {
		tresholds[i] +=temp;
		temp+=10;
	}
	ptr[0] = bubble_sort;
	ptr[1] = quick_sort;

	(*ptr[sort_index-1]) (struct_array, n);

	/*switch (sort_index)
	{
	case 1:
		bubble_sort(struct_array, n);
		break;
	case 2:
		quick_sort(struct_array, n);
		break;
	}*/

	print(struct_array, n, treshold_index);
}
