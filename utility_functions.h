#pragma once
#include <iostream>
#include "suffix_array.h"
#include "lcp.h"
#include <stdlib.h>
#include <fstream>

using namespace std;

bool SameSequence(char* txt1, char* txt2) {
	//cout << "Length of txt1 : " << strlen(txt1)<<endl;
	//cout << "Length of txt2 : " << strlen(txt2)<<endl;

	int counter = 0;
	for (int i = 0; i < strlen(txt1)-1; i++)
	{
		if (txt1[i+1] == '$') {
			counter = 1;
			for (int j = 0; j < strlen(txt2); j++)
			{
				if (txt2[j] == '$') {
					return true;
				}
			}
		}
		else if (counter == 1) {
			return false;
		}
	}
	for (int i = 0; i < strlen(txt2)-1; i++)
	{
		if (txt2[i] == '$') {
			counter = 1;
		}
	}
	if (counter == 1) {
		return false;
	}
	else return true;

}

void instructions_Menu(char txt1[], char txt2[]) {
	cout << "////////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
	cout << "//                                                                                                    //" << endl;;
	cout << "//                                                                                                    //" << endl;;
	cout << "//                                                                                                    //" << endl;;
	cout << "//                                                                                                    //" << endl;;
	cout << "//                                                                                                    //" << endl;;
	cout << "//                                                                                                    //" << endl;;
	cout << "//                                                                                                    //" << endl;;
	cout << "//                                                                                                    //" << endl;;
	cout << "//                                                                                                    //" << endl;;
	cout << "//                                                                                                    //" << endl;;
	cout << "//                                                                                                    //" << endl;;
	cout << "//  KMACS: the k-mismatch average common substring approach to alignment - free sequence comparison   //" << endl;;
	cout << "//                                                                                                    //" << endl;;
	cout << "//                                                                                                    //" << endl;;
	cout << "//                                                                                                    //" << endl;;
	cout << "//                                     Algorithm & Analysis Project                                   //" << endl;;
	cout << "//                                                                                                    //" << endl;;
	cout << "//                                       Usama Rashid Butt                                            //" << endl;;
	cout << "//                                          I18-0673                                                  //" << endl;;
	cout << "//                                                                                                    //" << endl;;
	cout << "//                                                                                                    //" << endl;;
	cout << "////////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;

	system("pause");

	system("cls");
	cout << "Instrutions: \n\n" << endl;
	cout << "1. Enter two string Not longer than 2500 characters!!!!!\n\n\n\n\n\n\n" << endl;
	cout << "2. String 2 Should be greater than string 1" << endl;

	cout << "Enter String 1 :  ";
	cin >> txt1;
	cout << "Enter String 2 :  ";
	cin >> txt2;



}
