#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 80
#define EXTRA 5
#define MAXINPUT MAXLEN+EXTRA+2
#define DATAFILE "./user_home/user_code.c"

int main(void)
{
//	FILE *fd = fopen(DATAFILE,"w");
	long len;
	char *lenstr,poststr[200];
	char realstr[200];
	char cmd_str[200] = "gcc -o ./user_home/a.out ";
	int  ret;
	printf("%s%c%c\n","Content-Type:text/html;charset=GB2312",13,10);
	printf("<TITLE>Code Show Page</TITLE>\n");
	lenstr = getenv("CONTENT_LENGTH");
	if(lenstr == NULL)
		printf("<P>Data post error.</p>");
	else{
		len = atoi(lenstr);
		fgets(poststr,len+1,stdin);
		strcpy(realstr,poststr+5);		
		printf("<P>The Code You Submit Is:</p>");
		printf("<P>%s</p>",realstr);
		printf("<hr/>");
//		fprintf(fd,"%s",realstr);
		strcat(cmd_str,DATAFILE);
		printf("<p>cmd = %s</p>",cmd_str);
		ret = system(cmd_str);
		printf("<p>compile = %d</p>",ret);
		ret = system("chmod 777 ./user_home/a.out");
		printf("<p>chmod = %d</p>",ret);
		ret = system("./user_home/a.out");
		printf("<p>run = %d</p>",ret);
	}
//	fclose(fd);
}
