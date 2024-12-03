#include <stdio.h>

int report_1[] = {7,6,4,2,1};
int report_2[] = {1,2,7,8,9};
int report_3[] = {9,7,6,2,1};
int report_4[] = {1,3,2,4,5};
int report_5[] = {8,6,4,4,1};
int report_6[] = {1,3,6,7,9};

int report_len = sizeof(report_1)/sizeof(int);

int isIncOrDec(int report[]){
	return ((report[1] - report[0]) > 0);
}

int difGt123(int a, int b){
	int d = a - b;
	if (d <= 0){
		if(d < -3 || d == 0){
			return 0;
		} else {
			return 1;
		}
	}
	
	if(d > 3){
		return 0;
	}
	
	return 1;
}

int isSafe(int report[]){
	int safe = 0;
	int dec = 1;

	if(isIncOrDec(report)){
		dec = 0;
	}

	for (int i = 0; i < report_len - 1; i++){
		int r = difGt123(report[i + 1],report[i]);
		if(!r){ return safe = 0; }
		if(dec){
			if((report[i + 1] - report[i]) > 0){
				return safe = 0;
			}
		}else{
			if((report[i + 1] - report[i]) < 0){
				return safe = 0;
			}
		}
	}

	return 1;
}

int main(void){
	int result = isSafe(report_1) + 
	isSafe(report_2) + 
	isSafe(report_3) + 
	isSafe(report_4) + 
	isSafe(report_5) + 
	isSafe(report_6);
	
	printf("safe reports: %d\n", result);
	return 0;
}