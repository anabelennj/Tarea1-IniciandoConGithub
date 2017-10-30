#include <stdio.h>
#include <ctype.h>
#define MAXLINE 1000


int getline2(char line[], int maxline);
void copy(char to[], char from[]);
void squeeze(char s[], int c);
void cambiar(char s[]);

main()
{
	int len;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];


	max = 0;
	while ((len = getline2(line, MAXLINE)) > 0)
	if (len > max) 
	{
		max = len;
		copy(longest, line);
	}

	if (max > 0)
	{
		printf("%s", longest);
		squeeze(longest,99);
		printf("%s", longest);
		cambiar(longest);
		printf("%s\n", longest);
	}

	return 0;

}

int getline2(char s[],int lim)
{
int c, i;
for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
s[i] = c;
if (c == '\n') {
s[i] = c;
++i;
}
s[i] = '\0';
return i;
}

void copy(char to[], char from[])
{
int i;
i = 0;
while ((to[i] = from[i]) != '\0')
++i;
}

void squeeze(char s[], int c)
{
int i, j;
for (i = j = 0; s[i] != '\0'; i++)
if (s[i] != c)
s[j++] = s[i];
s[j] = '\0';
}

void cambiar(char s[])
{
int i, j;
for (i = j = 0; s[i] != '\0'; i++)
if (isdigit(s[i]))
s[j++] = s[i];
s[j] = '\0';
}
