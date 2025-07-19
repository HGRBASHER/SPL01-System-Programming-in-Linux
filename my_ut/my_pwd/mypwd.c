#include <stdio.h>
#include <unistd.h>

#define  ffilename 1000

int main()
{  
       	char buf[ffilename];
	if(getcwd(buf,ffilename) !=NULL )
	
	{
		printf("Filename : %s\n",buf);
	}
	else
       	{
	 	 printf("getcwd error\n"); 	 
		 return 1;
       	}
    return 0;
}



