#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE 1024
#define MAX_NUM 1024


int countw(){
	    FILE* fp;  
	    char str[MAX_LINE] ; 
	      int len ;  
	     int i;
	       fp = fopen("input.txt","r");
    if(fp == NULL){
        printf("cannot open file!");
        exit(0);
    }
     while(! feof(fp)){
     	    if(fgets(str, MAX_LINE, fp) != NULL){
        int count=0;  
    int i=0;  
    while(str[i]==' '||str[i]==',')
        i++;  
    while(str[i]!='\0')  
    {  
        if(str[i]!=' '&&str[i]!=',')  
        {   
            count++;  
            while(str[i]!=' '&&str[i]!=',') 
            {  
                if(str[i]=='\0')  
                break;  
                i++;      
            }  
        }  
        else  
        {  
            while(str[i]==' '||str[i]==',')  
            i++;      
        }  
    }  
    printf("��������%d\n",count);
}
}}

void countc(){
		char buf[MAX_NUM];			//�ַ�������
	FILE *fp;            
	int len,total=0;           //ÿ���ַ�������������
	if((fp = fopen("input.txt","r")) == NULL){
		perror("the file fail to read");
		getchar();				//��ͣ��ʾ
		exit (1) ;
		}
	 while(!feof(fp) && !ferror(fp)){	//�ļ���ȡ������������˳�
	//while(fgets(buf,MAX_NUM,fp) != NULL)
		fgets(buf,MAX_NUM,fp);//ÿ�ζ�ȡһ�л���MAX_NUM���ַ�
		len = strlen(buf);
		if(buf[len-1] == '\n'){
			buf[len-1] = '\0';  //ȥ�����з������
			len--;
		}
		if(len == 0) continue;	//�����հ���
//		printf("%s %d \n",buf,len);
		total+=len;
	 }
	printf("�ַ���: %d",total);
	fclose(fp);				//�ر��ļ�
	getchar();
}

int main(){
	char parameter[2];
	char filename[10];
	gets(parameter);
	gets(filename);
	if (parameter[1]=='w'){
		countw();
	}
	else{
		countc();
	}
}
