#include <stdio.h>
#include <stdlib.h>

#include <queue.h>

typedef struct {
	char *test;
} test;

void free_test(test *t) {
	if(t->test != NULL)
		free(t->test);
	free(t);
}

int cmp_int_ptr(int *a, int *b) {
	if(*a < *b)
		return -1;
	else if(*a > *b)
		return 1;
	else
		return 0;
}

void unsorted_mode() {
	queue_t *q = queue_create();
	
	char *t1 = malloc(1);
	char *t2 = malloc(2);
	char *t3 = malloc(4);
	char *t4 = malloc(8);
	
	test *s1 = malloc(sizeof(test));
	s1->test = t1; 
	test *s2 = malloc(sizeof(test));
	s2->test = t2; 
	test *s3 = malloc(sizeof(test));
	s3->test = t3; 
	test *s4 = malloc(sizeof(test));
	s4->test = t4; 
	
	queue_put(q, s1);
	queue_put(q, s2);
	queue_put(q, s3);
	queue_put(q, s4);
	
	test *t;
	queue_get(q, (void **)&t);
	free_test(t);
	queue_get(q, (void **)&t);
	free_test(t);
	
	queue_destroy_complete(q, (void *)free_test);
}

void sorted_mode() {
	queue_t *q = queue_create_sorted(1, (void *)cmp_int_ptr);
	
	int *t1 = malloc(sizeof(int));
	int *t2 = malloc(sizeof(int));
	int *t3 = malloc(sizeof(int));
	int *t4 = malloc(sizeof(int));
	
	*t1 = 10;
	*t2 = 12;
	*t3 = 1;
	*t4 = 1;
	
	queue_put(q, t1);
	queue_put(q, t2);
	queue_put(q, t3);
	queue_put(q, t4);
	
	int *t;
	queue_get(q, (void **)&t);
	printf("first int %i\n", *t);
	free(t);
	queue_get(q, (void **)&t);
	printf("second int %i\n", *t);
	free(t);
	queue_get(q, (void **)&t);
	printf("third int %i\n", *t);
	free(t);
	queue_get(q, (void **)&t);
	printf("fourth int %i\n", *t);
	free(t);
	
	queue_destroy_complete(q, NULL);
}

void sorted2_mode() {
	queue_t *q = queue_create_limited_sorted(3, 1, (void *)cmp_int_ptr);
	
	int t1 = 1;
  queue_put(q, &t1);
	int t2 = 15;
  queue_put(q, &t2);
	int t3 = 3;
  queue_put(q, &t3);
	int t4 = 27;
  queue_put(q, &t4);
	int t5 = 9;
  queue_put(q, &t5);
  
  int *i;
  queue_get(q, (void **)&i);
  printf("first element was %d\n", *i);
  queue_get(q, (void **)&i);
  printf("second element was %d\n", *i);
  queue_get(q, (void **)&i);
  printf("third element was %d\n", *i);
  queue_get(q, (void **)&i);
  printf("fourth element was %p\n", i);
  queue_get(q, (void **)&i);
  printf("fifth element was %p\n", i);
  
	queue_destroy_complete(q, NULL);
}

int main(int argc, char *argv[]) {
	unsorted_mode();
	sorted_mode();
	sorted2_mode();
	
	return 0;
}
