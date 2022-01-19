// Alogrithm_Project_Kmacs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "suffix_array.h"
#include "lcp.h"
#include <stdlib.h>
#include <fstream>
#include "utility_functions.h"

using namespace std;


int* kMACSalgo_444(int n, int* lcp, int* sa, int length_Str, char* txt1, char* txt2, suffix* suffarr/*,int *suffix*/) {

	cout << "////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
	cout << "Coded according to algorithm defined in pdf" << endl;
	cout << "////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;

	//cout << "txt concatenated: "<<txt1 << endl;
	cout << "n: " << n << endl;
	n--;
	//int m = strlen(pat);  // get length of pattern, needed for strncmp()
	int* s = new int[n];
	for (int i = 0; i < n; i++)
	{
		s[i] = NULL;
	}
	int min = 0;
	for (int i = 1; i < n - 2; i++)
	{
		if (SameSequence(suffarr[i].suff, suffarr[i + 1].suff/*, length_Str*/)) { //if SA�iand SA�i + 1 belong to the same sequence then
			if (lcp[i + 1] < min) {
				min = lcp[i + 1];
			}
			s[i + 1] = min;
		}
		else {
			min = lcp[i + 1];
			s[i + 1] = lcp[i + 1];// +1
		}

	}

	//min = 0;
	for (int i = n - 2; i > 1; i--)
	{
		//if SA�iand SA�i + 1 belong to the same sequence then
		//if ((sa[i] == sa[i + 1])) { //if SA�iand SA�i + 1 belong to the same sequence then
		if (SameSequence(suffarr[i].suff, suffarr[i + 1].suff/*, length_Str*/)) {
			if (lcp[i] < min) {
				min = lcp[i];
			}

			s[i - 1] = max(min, s[i - 1]);
		}
		else {
			min = lcp[i];
			s[i - 1] = max(min, s[i - 1]);// lcp[i + 1];// +1
		}
	}
	cout << endl;

	return s;
}

int* kMACSalgo_Final(int n, int* lcp, int* sa, int length_Str, char* txt1, char* txt2, suffix* suffarr/*,int *suffix*/){

	cout << "////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
	cout << "Coded according to algorithm defined in pdf" << endl;
	cout << "////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;

	cout << "n: " << n << endl;
	n--;
	int* s = new int[n];
	for (int i = 0; i < n; i++)
	{
		s[i] = NULL;
	}
	int min = 0;
	for (int i = 1; i < n - 2; i++)
	{
		if (SameSequence(suffarr[i].suff, suffarr[i + 1].suff/*, length_Str*/)) { //if SA�iand SA�i + 1 belong to the same sequence then
			if (lcp[i + 1] < min) {
				min = lcp[i + 1];
			}
			s[i + 1] = min;
		}
		else {
			min = lcp[i + 1];
			s[i + 1] = lcp[i + 1];// +1
		}

	}

	for (int i = n - 2; i > 1; i--)
	{
		if (SameSequence(suffarr[i].suff, suffarr[i + 1].suff/*, length_Str*/)) {
			if (lcp[i] < min) {
				min = lcp[i];
			}

			s[i - 1] = max(min, s[i - 1]);
		}
		else {
			min = lcp[i];
			s[i - 1] = max(min, s[i - 1]);// lcp[i + 1];// +1
		}
	}
	cout << endl;
	return s;
}

int main()
{
	// Driver program to test above functions 
	
	char txt1[2500] = "";
	char txt2[2500] = "";





	instructions_Menu(txt1, txt2);

	int Str1length = strlen(txt1);
	strcat_s(txt1, "$");
	strcat_s(txt1, txt2);

	int n = strlen(txt1);



	int* lcp = new int[n];

	suffix* suffixes = new suffix[n];



	system("cls");
	cout << "txt1  after concationation : " << txt1 << endl;
	int* suffixArr = buildSuffixArray(txt1, suffixes, n, lcp);


	lcp = buildLcpArray(suffixArr, n, txt1);



	cout << "Sorted Suffix Array:  \n" << endl;
	cout << "i  " << "SA[i] " << "LCP[i]    " << "suffix  " << "" << endl;
	for (int i = 0; i < n; i++) {
		cout << i + 1 << "   " << suffixArr[i] << "     " << lcp[i] << "    " << suffixes[i].suff << endl;
	}

	int* s = kMACSalgo_Final(n, lcp, suffixArr, strlen(txt2), txt1, txt2, suffixes);
	int max = n-1;

	for (int j = n-1; j > 0; j--)
	{

		if (s[j] > s[max]) {
			max = j;
		}
	}
	cout << "max : " << max + 1 << endl;
	cout << "s[max]: " << s[max] << endl;
	cout << "suffixArr[max] :" << suffixArr[max] << endl;

	cout << "/////////////////////////////////////////////////////////\n\n\n";
	cout << "String2 matching a substring from S1 is:  \"";
	/// <summary>
	/// c++ indexes start from 0  ....
	/// </summary>
	/// <returns></returns>

	char string_found[5000];
	int k = 0;
		for (int i = (suffixArr[max] - 1); i < (lcp[max]+ (suffixArr[max] - 1)); i++) {
			cout << txt1[i];
			string_found[k] = txt1[i];
		}
		//cout << endl;
		cout << "\" starting from index #\"";
		if ((suffixArr[max - 1])>Str1length ) {
			cout << (suffixArr[max - 1])-Str1length-1;
			cout << "\" in string two " << endl;// &starting at \"";

			//searchindex( string_found, txt1, suffixArr, strlen(string_found));
			//cout << suffixArr[max - 1]-strlen(txt2)-1;
			//cout << "\" in string one";

		}
		else {
			cout << (suffixArr[max - 1]);
			cout<< "\" in string one";
		}
			

		cout << "\n\n\n\n\n\n\n";
	return 0;
}

