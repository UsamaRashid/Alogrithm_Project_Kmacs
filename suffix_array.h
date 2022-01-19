#pragma once
// Naive algorithm for building suffix array of a given text 
#include <iostream> 
#include <cstring> 
#include <algorithm> 
#include "lcp.h"
#include <vector>
using namespace std;

// Structure to store information of a suffix 
struct suffix
{
	int index;
	char* suff;
};

// A comparison function used by sort() to compare two suffixes 
int cmp(struct suffix a, struct suffix b)
{
	if (strcmp(a.suff, b.suff) < 0) {
		return   1;
	}
	else {
		return 0;
	}
}

int* buildLcpArray(int* suffix_arr, int n, char* txt) {
	int* suffixArr = new int[n];
	for (int i = 0; i < n; i++)
	{
		suffixArr[i] = suffix_arr[i] - 1;
	}

	// To store LCP array 
	int* lcp = new int[n]; (n, 0);
	for (int i = 0; i < n; i++)
	{
		lcp[i] = 0;
	}
	// An auxiliary array to store inverse of suffix array 
	// elements. For example if suffixArr[0] is 5, the 
	// invSuff[5] would store 0.  This is used to get next 
	// suffix string from suffix array. 
	int* invSuff = new int[n];// , 0);
	for (int i = 0; i < n; i++)
	{
		invSuff[i] = 0;
	}
	// Fill values in invSuff[] 
	for (int i = 1; i < n; i++)
	{
		invSuff[suffixArr[i]] = i;
	}
	// Initialize length of previous LCP 
	int k = 0;

	// Process all suffixes one by one starting from 
	// first suffix in txt[] 
	for (int i = 1; i < n; i++)
	{
		/* If the current suffix is at n-1, then we don�t
		   have next substring to consider. So lcp is not
		   defined for this substring, we put zero. */
		if (invSuff[i] == n - 1)
		{
			k = 0;
			continue;
		}

		/* j contains index of the next substring to
		   be considered  to compare with the present
		   substring, i.e., next string in suffix array */
		int j = suffixArr[invSuff[i] + 1];

		// Directly start matching from k'th index as 
		// at-least k-1 characters will match 
		while (i + k < n && j + k < n && txt[i + k] == txt[j + k])
			k++;

		lcp[invSuff[i] + 1] = k; // lcp for the present suffix. 

		// Deleting the starting character from the string. 
		if (k > 0)
			k--;
	}

	// return the constructed lcp array 
	return lcp;



// This is the main function that takes a string 'txt' of size n as an 
// argument, builds and return the suffix array for the given string 
int* buildSuffixArray(char* txt, suffix* suffixes, int n, int* lcp)
{
	//int n = strlen(txt);

	// A structure to store suffixes and their indexes 


	// Store suffixes and their indexes in an array of structures. 
	// The structure is needed to sort the suffixes alphabatically 
	// and maintain their old indexes while sorting 
	for (int i = 0; i < n; i++)
	{
		suffixes[i].index = i + 1;
		suffixes[i].suff = (txt + i);
		//cout << suffixes[i].suff << " ";
	}
	cout << endl;
	// Sort the suffixes using the comparison function 
	// defined above. 
	sort(suffixes, suffixes + n, cmp);

	// Store indexes of all sorted suffixes in the suffix array 
	int* suffixArr = new int[n];
	for (int i = 0; i < n; i++) {
		//cout << suffixes[i].suff << " ";
		suffixArr[i] = suffixes[i].index;
	}
	cout << endl;


	// Return the suffix array 
	return  suffixArr;
}

// A utility function to print an array of given size 
void printArr(int arr[], int n)
{

	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}


// This code only contains search() and main. To make it a complete running 
// above code or see 
// A suffix array based search function to search a given pattern 
// 'pat' in given text 'txt' using suffix array suffArr[] 
void searchindex(char* pat, char* txt, int* suffArr, int n)
{
	int m = strlen(pat);  // get length of pattern, needed for strncmp() 

	// Do simple binary search for the pat in txt using the 
	// built suffix array 
	int l = 0, r = n - 1;  // Initilize left and right indexes 
	while (l <= r)
	{
		// See if 'pat' is prefix of middle suffix in suffix array 
		int mid = l + (r - l) / 2;
		int res = strncmp(pat, txt + suffArr[mid], m);

		// If match found at the middle, print it and return 
		if (res == 0)
		{
			//cout << "Pattern found at index " << ;
				cout<<suffArr[mid];
			return;
		}

		// Move to left half if pattern is alphabtically less than 
		// the mid suffix 
		if (res < 0) r = mid - 1;

		// Otherwise move to right half 
		else l = mid + 1;
	}

	// We reach here if return statement in loop is not executed 
	cout << "Pattern not found";
}

