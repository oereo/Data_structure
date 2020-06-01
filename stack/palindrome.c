#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define _CRT_SECURE_NO_WARNINGS

char query[50];
int length = 0;
bool isTrue = true;

void input() {
	printf("Enter the query for checking a Palindrome : ");
	//scanf_s("%s", &query); //  판별할 스트링 받기
	gets(query);
	length = strlen(query);
}

void palindrom() {
	for (int i = 0; i < length / 2; i++) {
		if (query[i] != query[length - 1 - i]) {
			isTrue = false;
			break;
		}
	}
}

void output() {
	if (isTrue == true) {
		printf("It is a Palidrome");
	}
	else if (isTrue == false) {
		printf("It is not a Palidrome");
	}
	
}

int main() {
	
	input();
	palindrom();
	output();
}