     #include <stdio.h>
     #include <sys/types.h>        /* defines types used by sys/stat.h */
     #include <sys/stat.h>         /* defines S_IREAD & S_IWRITE       */
     #include <stdlib.h>
     #include <fcntl.h> 
     #include <string.h>
    
     int main()
     {
        int fd,ch;
        char fname[25];
        char buffer[80];
        ssize_t ret_in, ret_out;  /* Number of bytes returned by read() and write() */
        char message[100];
       
    do
       {
	printf("1. Create File");
        printf("2. Write");
        printf("3. read");
        printf("5. exit");
        printf("Enter ur choice");
        scanf("%d",&ch);
       


	if(ch==1)
	{
        printf("Enter file name");
        scanf("%s",fname);
        fd = creat(fname, S_IREAD | S_IWRITE);
        	if (fd == -1)
           	printf("Error in opening File %s\n",fname);
        	else
           	{
           	printf("File %s is opened for read/write access\n",fname);
           	printf("%s is currently empty\n",fname);
           	}
        close (fd);
 	}
        
	if(ch==2)
	{
        printf("Enter file name");
        scanf("%s",fname);
	fd = open(fname, O_WRONLY, 1 ); /* Open the file for write only */
        
        	if (fd != -1)
           	{
           	printf("file %s opened for write access\n",fname);
                printf("Enter Data");
                scanf("%s",message);
                write(fd, message, sizeof(message));
		close (fd);
	   	}
         
	}

        if(ch==3)
	{
        printf("Enter file name");
        scanf("%s",fname);
	fd = open(fname, O_RDONLY, 0); /* Open the file for reading only */
        	if (fd != -1)
           	{
           	printf("%s opened for read access\n",fname);
                
		if (read(fd, buffer, sizeof(buffer)))
                   printf("\"%s\" was written to %s\n", buffer,fname);
                else
                   printf("*** error reading  %s ***\n",fname);
                }
            close (fd);	
        }

	}while(ch!=5);

       close (fd);
        exit (0);
}

