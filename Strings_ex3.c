#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Strings_ex3.h"

#define TXT 1024
#define WORD 30

int check(char* str1, char* str2, int len)
{
    int i, res=1;
    for(i = 0; i < len; i++)
    {
        if(*(str1+i) != *(str2+i))
        {
            res = 0; 
            break;
        }
    }
    return res;
}
void swap(char *x, char *y)
{
    char tmp = *x;
    *x = *y;
    *y = tmp;
}

void sort(char* sort, int len)
{
   for(int i = 0; i < len - 1; i++) 
   {
       for(int j = i + 1; j < len; j++)
       {
           if (*(sort + i) > *(sort +j))
           {
               swap(sort + i , sort + j);
           }
       }
   }
}
int gema(char* w, int len)
{
    int count = len;
    int i;
    for(i = 0; i < len; i++)
    {
        char c =*(w + i);
        if (c < 'z' && c > 'a')
        {
            count +=(c-'a');
        }
        else if (c < 'Z' && c > 'A')
        {
            count +=(c-'A');
        }
    }
    return count;
}

char* azba(char* w, char* azby1, int wlen)
{
    int i;
    for(i = 0; i < wlen; i++)
    {
        if(*(w+i) >= 'a' && (*(w+i) <= 'z'))
        {
            *(azby1+i)='z'-(*(w+i)-'a');
        }
        else if(*(w+i) >= 'A' && (*(w+i)) <='Z')
        {
            *(azby1+i) ='Z' -(*(w+i)-'A');
        }
        else
        {
            *(azby1+i) =*(w+i);
        }
    }
    return azby1;
}

int translate(char* azby,char* w,int wlen)
{

	char* trans2=malloc(sizeof(char)*wlen);
		if(trans2==NULL)
		{
			printf("Memory not allocated.\n");
		}
	int i;
	for(i=0;i<wlen;i++)
	{
		trans2[i]=*(azby+wlen-1-i);
	}
	for(i=0;i<wlen;i++)
	{
		*(w+i)=trans2[i];
	}
	free(trans2);
	return 0;
}

int Func1(char* text,int size,int stxt)
{
	int firstime=1;
	int i=0, j=0, s=0;
	int mat[stxt][stxt];
	for(i=0;i<stxt;i++)
	{

		if(text[i]>='a'&&text[i]<='z')
		{
		
			mat[0][i]=*(text+i)-'a'+1+s;
			s=mat[0][i];
		}
        else if (text[i]>='A'&&text[i]<='Z')
		{
			mat[0][i]=*(text+i)-'A'+1+s;
			s=mat[0][i];
		
		}
        else
		{
			mat[0][i]=mat[0][i-1];
		}
	}
	for( i=1;i<stxt;i++)
	{
		for( j=i;j<stxt;j++)
		{
			mat[i][j]=mat[i-1][j]-mat[i-1][i-1];		
		}
	}
	for( i=0;i<stxt;i++)
	{
		for( j=i;j<stxt;j++)
		{
			if(mat[i][j]==size&&mat[i][i]!=0)
			{
				if(firstime)
				{
					firstime=0;
					for(int m=i;m<=j;m++)
					{
						if(mat[i][m]>0){
							printf("%c",*(text+m));
						}
					}
					j=stxt;
				}
                else
				{
					printf("~");
					for(int m=i;m<=j;m++)
					{
						if(mat[i][m]>0){
							printf("%c",*(text+m));
						}
					}
					j=stxt;
				}
			}		
		}
	}
	printf("\n");
	return 0;
}
int Func2(char* text,char* azby,char* trans,int textlen,int wlen)
{


	char* azby3=(char*)malloc(wlen);
	char* trans3=(char*)malloc(wlen);
		if(azby3==NULL||trans3==NULL)
		{
			printf("Memory not allocated.\n");
		}
	char* check1=(char*)malloc(textlen);
	char* check2=(char*)malloc(wlen);
	trans3=trans;
	azby3=azby;
	int countword=0;
	int coupoi=0;
	int firstime=1;
	int sizeal;
	for (int i=0;i<=textlen-wlen;i++)
	{
		check1=(char*)malloc(textlen);
		check2=(char*)malloc(wlen);
		if(check1==NULL||check2==NULL)
		{
			printf("Memory not allocated.\n");
		}
		countword=0, 
		coupoi=0;
		sizeal=0;
		for(int j=i;j<=textlen;j++)
		{
			if(countword<wlen)
			{
				if(*(text+i)!=','&&*(text+i)!='\n'&&*(text+j)!='\n')
				{
					*(check1+coupoi++)=*(text+j);
					*(check2+countword++)=*(text+j);
				}
                else
				{
					check1=(char*)realloc(check1,wlen+(++sizeal));
					*(check1+coupoi++)=*(text+j);
				}	
			}
            else
			{
				if(check(check2,azby3,wlen)||check(check2,trans3,wlen))
				{
					if(firstime){
						printf("%s",check1);
						firstime=0;
					}else
					{
						printf("~%s",check1);
					}
				}
				j=textlen;
			}


		}
	}
	free(check1);
	free(check2);	
	free(trans3);
	free(azby3);
	printf("\n");
	return 0;
}
int Func3(char*text,char* w,int wlen,int textlen)
{
	int firstime=1;
	char* check3=(char*)malloc(textlen);
	char* check4=(char*)malloc(wlen);
	char* sortword=(char*)malloc(wlen);
	if(sortword==NULL)
	{
		printf("Memory not allocated.\n");
	}
	for(int i=0;i<wlen;i++)
	{
		*(sortword+i)=*(w+i);
	}
	sort(sortword,wlen);
	int countword=0;
	int coupoi=0;
	for (int i=0;i<=textlen-wlen;i++)
	{
		check3=(char*)malloc(textlen);
		check4=(char*)malloc(wlen);
		if(check3==NULL||check4==NULL)
		{
			printf("Memory not allocated.\n");
		}
		countword=0;
		coupoi=0;
		for(int j=i;j<textlen;j++)
		{
			if(countword<wlen)
			{
				if(*(text+i)!=','&&*(text+i)!='\t'&&*(text+i)!='\n'&&*(text+i)!='.')
				{
					*(check3+coupoi++)=*(text+j);
					*(check4+countword++)=*(text+j);
				}
                else if(coupoi!=0)
				{
					*(check3+coupoi++)=*(text+j);
				}
				
			}
            else
			{
				j=textlen;

			}
			if(countword==wlen)
			{
				j=textlen;
				sort(check4,wlen);	
				if(check(check4,sortword,wlen))
				{
					if(firstime){
						printf("%s",check3);
						firstime=0;
					}
                    else
					{
						printf("~%s",check3);
					}
				}
			}
		}
	}
	free(check3);
	free(check4);
	free(sortword);
	return 0;	
}