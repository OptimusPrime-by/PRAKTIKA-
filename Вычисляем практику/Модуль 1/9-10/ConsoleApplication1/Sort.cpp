#include "Sort.h"

template <typename T> void sort_to_max(T* arr, int arr_size) {
	T buf = 0;
	for (int i = 1; i < arr_size; ++i)
	{
		buf = arr[i];
		for (int k = i; k >= 0; --k) {
			if (buf < arr[k]) {
				arr[k + 1] = arr[k];
				arr[k] = buf;
			}
		}
	}
}

template <typename T> void sort_to_min(T* arr, int arr_size) {
	T buf = 0;
	for (int i = 1; i < arr_size; ++i)
	{
		buf = arr[i];
		for (int k = i; k >= 0; --k) {
			if (buf > arr[k]) {
				arr[k + 1] = arr[k];
				arr[k] = buf;
			}
		}
	}
}

template <typename T> void sort(T* arr, int amount)
{
	T buf = 0;
	for (int i = 1; i < amount; ++i)
	{
		buf = arr[i];
		for (int k = i; k >= 0; --k) {
			if (buf.get_amount() < arr[k].get_amount()) {
				arr[k + 1] = arr[k];
				arr[k] = buf;
			}
		}
	}
}