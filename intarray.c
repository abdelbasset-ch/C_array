#include <stdlib.h>
#include <stdio.h>
#include "intarray.h"
#include "tools.h"

intarray init_intarray(int length, int alloc){
  intarray int_array=sp_alloc(sizeof(intarray));
	int_array->length=length;
	int_array->alloc=alloc;
	int_array->data=sp_alloc(sizeof(int)*int_array->alloc);
	for (int i=0;i<length;i++)
		int_array->data[i]=0;
	return int_array;
}
intarray zero_length_intarray(int alloc){
	return  init_intarray(0,alloc);
}
void print_intarray(intarray int_array){
	printf("[");
	for(int i=0;i<int_array->length;i++){
		printf("%d ",int_array->data[i]);
	}
	printf("]\n");
}
void intarray_destroy(intarray int_array){
  if(int_array!=NULL){
    sp_destroy(int_array->data, sizeof(int)*int_array->alloc);
    sp_destroy(int_array,sizeof(int_array));
  }
}
void insert_intarray(intarray int_array, 
	int index, int value){
	if(int_array->length>index)
	int_array->data[index]=value;
}
void add_intarray(intarray int_array, int value){
	if(int_array->alloc>int_array->length){
		int_array->length++;
		insert_intarray(int_array, int_array->length-1
		,value);
		
	}else if(int_array->alloc<=int_array->length){
		resize_intarray(int_array);
		add_intarray(int_array,value);
	}
}
intarray clone_intarray(intarray int_array){
	intarray new_intarray;
	new_intarray->data=sp_alloc(sizeof(int)*int_array->alloc);
	new_intarray->length=int_array->length;
	new_intarray->alloc=int_array->alloc;
	for(int i=0;i<int_array->length;i++){
		new_intarray->data[i]=int_array->data[i];
	}
	return new_intarray;
}

void resize_intarray(intarray int_array){
	int_array->data=(int *) realloc(int_array->data,
		 (2*int_array->alloc)*sizeof(int));
	int_array->alloc=2*int_array->alloc;
}
void asc_sort_intarray(intarray int_array){
	for(int i=0;i<int_array->length;i++){
		for(int j=i;j<int_array->length;j++){
			if(int_array->data[i]>int_array->data[j])
				int_swap(&int_array->data[i],
					&int_array->data[j]);
		}
	}
}
void desc_sort_intarray(intarray int_array){
	for(int i=0;i<int_array->length;i++){
		for(int j=i;j<int_array->length;j++){
			if(int_array->data[i]<int_array->data[j])
				int_swap(&int_array->data[i],
					&int_array->data[j]);
		}
	}
}
int min_intarray_index(intarray int_array){
	int index=0;
	for (int i=0;i<int_array->length;i++){
		if(int_array->data[index]>int_array->data[i])
			index=i;
	}
	return index;
}
int min_intarray(intarray int_array){
	return int_array->data[min_intarray_index(int_array)];
}
int max_intarray_index(intarray int_array){
	int index=0;
	for (int i=0;i<int_array->length;i++){
		if(int_array->data[index]<int_array->data[i])
			index=i;
	}
	return index;
}
int max_intarray(intarray int_array){
	return int_array->data[max_intarray_index(int_array)];
}
int sum_intarray(intarray int_array){
	int sum=0;
	for(int i=0;i<int_array->length;i++){
		sum+=int_array->data[i];
	}
	return sum;
}
float average_intarray(intarray int_array){
	return sum_intarray(int_array)/(float)int_array->length;
}
float median_intarray(intarray int_array){
	float median;
	int index=(int_array->length-1)/2;
	intarray new_array=clone_intarray(int_array);
	asc_sort_intarray(new_array);
	if(new_array->length%2!=0)
		median=new_array->data[index];
	else if(new_array->length%2==0)
		median=(new_array->data[index]+new_array->data[index+1])/2.0;
	return median;
}
intarray positive_intarray(intarray int_array){
	intarray new_intarray=zero_length_intarray(1);
	for(int i=0; i<int_array->length;i++){
		if(int_array->data[i]>=0){
			add_intarray(new_intarray,int_array->data[i]);
		}
	}
	return new_intarray;
}
intarray negative_intarray(intarray int_array){
	intarray new_intarray=zero_length_intarray(1);
	for(int i=0; i<int_array->length;i++){
		if(int_array->data[i]<0){
			add_intarray(new_intarray,int_array->data[i]);
		}
	}
	return new_intarray;
}
intarray index_of_occu_intarray(intarray int_array, int num){
	intarray new_intarray=zero_length_intarray(1);
	for(int i=0; i<int_array->length;i++){
		if(int_array->data[i]==num){
			add_intarray(new_intarray,i);
		}
	}
	return new_intarray;
}
int num_of_occu_intarray(intarray int_array, int num){
	return index_of_occu_intarray(int_array,num)->length;
}
