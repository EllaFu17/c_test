#include<stdio.h>

//求具有N个元素的整型数组b中最长平台的长度。
int GetMaxSubstring (int b[], int n)
{

	int i,len=1,max=0;
	for(i=0;i<n;i++){
		if(b[i+1]==b[i]){
			len++;
			if(len>max){
				max=len;
			}
		}
		else{len=1;}
	}
	return max;

}

int main()
{
	int b[] = {1,2,3,4,5,5,5,5,9,9,9,9,9,0};
	int len = sizeof(b) / sizeof(b[0]);
	
	int maxlen;
	maxlen=GetMaxSubstring(b, len);

	printf("最长平台长度为%d\n",maxlen);
	
}
