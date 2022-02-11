#ifndef INTARRAY
#define INTARRAY
typedef struct _intarray* intarray;
typedef struct _intarray s_intarray;
struct _intarray {
	int* data;
	int alloc;
	int length;
};

intarray init_intarray(int length, int alloc);
//initialize intarray with length=0
intarray zero_length_intarray(int alloc);
void intarray_destroy(intarray int_array);
void print_intarray(intarray int_array);
void insert_intarray(intarray int_array, 
	int index, int value);
//add a value to the end of the intarray
void add_intarray(intarray int_array,int value);
intarray clone_intarray(intarray int_array);
//double the amount of the allocated memory
void resize_intarray(intarray int_array);
//arrange intarray in ascending order
void asc_sort_intarray(intarray int_array);
//arrange intarray in descending order
void desc_sort_intarray(intarray int_array);
int min_intarray_index(intarray int_array);
int min_intarray(intarray int_array);
int max_intarray_index(intarray int_array);
int max_intarray(intarray int_array);
float median_intarray(intarray int_array);
float average_intarray(intarray int_array);
int sum_intarray(intarray int_array);
//return all the positive values in intarray
intarray positive_intarray(intarray int_array);
//return all the negative values in intarray
intarray negative_intarray(intarray int_array);
//return all the occurrences of a value 
intarray index_of_occu_intarray(intarray int_array, int num);
int num_of_occu_intarray(intarray int_array, int num);


#endif
