#include<stdio.h>
void mang_haichieu(int arr[][100],int hang,int cot){
    printf(" nhap cac gia tri trong matran");
    for(int i=0;i<hang;i++){
   	for(int j=0;j<cot;j++){
        printf(" nhap phan thu [%d][%d]",i,j);
        scanf("%d",&arr[i][j]);
   	  }
	}
}  		
void printf_mang(int arr[][100],int hang,int cot){
    printf ("in gia tri trong matran");
	for(int i=0;i<hang;i++){
	for(int j=0;j<cot;j++){
	      printf("%d",arr[i][j]);
      }
    }
 }   		
int main(){
	int hang;
	int cot;
	printf(" nhap so hang");
	scanf("%d",&hang);
	printf(" nhap so cot");
	scanf("%d",&cot);
	int arr[100][100];
	mang_haichieu(arr,hang,cot);
	printf_mang(arr,hang,cot);
	return 0;
	}
