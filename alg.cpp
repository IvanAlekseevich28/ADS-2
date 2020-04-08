#include <bits/stdc++.h>
#include "alg.h"


static int count(int arr[], int x, int n);
static int getSV(int limit, int key);

int countPairs1(int *arr, int len, int value) {
	int k = 0;
	for (int i = 0; i < len - 1; i++) {
		for (int j = i + 1; j < len; j++) {
			if (getSV(value, arr[i]) == arr[j]) {
				k++;
			}
		}
	}

	return k;
}

int countPairs2(int *arr, int len, int value) {
	int k = 0;
	for (int i = 0; i < len - 1; i++) {
		for (int j = len - 1; j > i; j--) {
			while (arr[i] + arr[j] == value && j > i) {
				k++;
				j--;
			}
			if (arr[i] + arr[j] < value) {

				break;
			}
		}
	}

	return k;

}

int countPairs3(int *arr, int len, int value) {
	unsigned counter = 0;
	for (int i = 0; i < len - 1; i++) {
		counter += count(arr + i + 1, getSV(value, arr[i]), len - i - 1);
	}

	return counter;
}

static int count(int arr[], int x, int n) {
	/* get the index of first occurrence of x */
	int *low = std::lower_bound(arr, arr + n, x);

	// If element is not present, return 0
	if (low == (arr + n) || *low != x)
		return 0;

	/* Else get the index of last occurrence of x.
	 Note that we  are only looking in the
	 subarray after first occurrence */
	int *high = std::upper_bound(low, arr + n, x);

	/* return count */
	return high - low;
}

static int getSV(int limit, int key) {

	return limit - key;
}
