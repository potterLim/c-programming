#ifndef ARRAY_H
#define ARRAY_H

#define TRUE (1)
#define FALSE (0)

int get_index(const int arr[], int count, int num);
int get_last_index(const int arr[], int count, int num);
int get_max_index(const int arr[], int count);
int get_min_index(const int arr[], int count);
int has_zero(const int arr[], int count);
int insert_at(int arr[], int count, int value, int index);
int remove_at(int arr[], int count, int index);

#endif /* ARRAY_H */