#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define SIZE 1024
int main(int argc, char* argv[])
{

        if(argc !=3)
        {
                printf("Usage: %s source_file destination_file\n", argv[0]);
                exit(-1);
        }
        int sfd = open(argv[1],O_RDONLY);
        if (sfd < 0)
        {
                printf("Failed to open source file\n");
                exit(-2);
        }
        int dfd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (dfd < 0) 
	{
        	printf("Failed to open destination file\n");
        	close(sfd);
                exit(-3);
         }
        
       	 char buffer[SIZE];
   	 int bytes_read;
    	while ((bytes_read = read(sfd, buffer,SIZE)) > 0)
       	{
     		 if (write(dfd, buffer, bytes_read) != bytes_read)
		 {
           		 printf("Write error\n");
           		 close(sfd);
           		 close(dfd);
           		 exit(-4);
		 }
    	}

   		 close(sfd);
   		 close(dfd);
       	 return 0;
}

