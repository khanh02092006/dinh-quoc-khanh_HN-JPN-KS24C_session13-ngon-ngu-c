#include<stdio.h>
int ucln(int a,int b){
	while (b !=0){
		int tmep=b;
		b=a%b;
		a=tmep;
		}
		return a;
		}
int main(){
    int mun1=48;
	int mun2=12;
	int kq=ucln(mun1,mun2);
	printf("Uoc chung lon nhat cua %d và %d là: %d\n", mun1,mun2,kq);
	return 0;
	}
			
