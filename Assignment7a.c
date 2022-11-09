#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

void main()
{
	int fd1[2],fd2[2],n;
	FILE *fp,*fp1;
	char ch[30],filen[30]="text.txt";
	char buf1[50],buf2[50];
	pid_t cpid;
	pipe(fd1);
	pipe(fd2);
	
	cpid=fork();
	printf("%d",cpid);
	if(cpid==-1)
	{
		perror("fork");
	}
	if(cpid>0)
	{
		close(fd1[0]);
		printf("\n\tParent process writing data data..\n");
		write(fd1[1],filen,strlen(filen));
		close(fd2[1]);
		n=read(fd2[0],buf1,50);
		buf1[n]='\0';
		printf("\n\tReply from child: %s\n",buf1);

		//sleep(2);
  	}	
	else
	{
		close(fd1[1]);
		printf("\n\tChild process receiving data..\n");
		n=read(fd1[0],buf2,sizeof(buf2));
		buf2[n]='\0';
		printf("\n\tData received from parent through pipe: %s\n",buf2);
		fp=fopen(buf2,"r");
		close(fd2[0]);
		while(fgets(ch,30,fp))
		{
			write(fd2[1],ch,sizeof(ch));			//fprintf(fp1,"%s",ch);
		}
		
		//sleep(3);
		//fclose(fp1);
		fclose(fp);
		
		
		printf("\n\tReply sent.\n");
	}
}
/*************************output******************************/
/*
ssl@ssl-ThinkCentre-M60e:~$ cd Desktop
ssl@ssl-ThinkCentre-M60e:~/Desktop$ gcc pr.c
pr.c: In function ‘main’:
pr.c:25:22: warning: incompatible implicit declaration of built-in function ‘strlen’ [enabled by default]
   write(fd1[1],filen,strlen(filen));
                      ^
ssl@ssl-ThinkCentre-M60e:~/Desktop$ ./a.out
2817
	Parent process writing data data..
0
	Child process receiving data..

	Data received from parent through pipe: text.txt

	Reply from child: Title:Text file for interproc

	Reply sent.
ssl@ssl-ThinkCentre-M60e:~/Desktop$ 






*/








