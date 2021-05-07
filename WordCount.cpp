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
    printf("单词数：%d\n",count);
}
}}

void countc(){
		char buf[MAX_NUM];			//字符缓冲区
	FILE *fp;            
	int len,total=0;           //每行字符个数和总字数
	if((fp = fopen("input.txt","r")) == NULL){
		perror("the file fail to read");
		getchar();				//暂停显示
		exit (1) ;
		}
	 while(!feof(fp) && !ferror(fp)){	//文件读取结束或出错则退出
	//while(fgets(buf,MAX_NUM,fp) != NULL)
		fgets(buf,MAX_NUM,fp);//每次读取一行或者MAX_NUM个字符
		len = strlen(buf);
		if(buf[len-1] == '\n'){
			buf[len-1] = '\0';  //去掉换行符在输出
			len--;
		}
		if(len == 0) continue;	//消除空白行
//		printf("%s %d \n",buf,len);
		total+=len;
	 }
	printf("字符数: %d",total);
	fclose(fp);				//关闭文件
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
