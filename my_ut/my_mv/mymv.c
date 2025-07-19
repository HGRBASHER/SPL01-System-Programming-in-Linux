#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{

        if(argc !=3)
        {
                printf("Usage: %s source_file destination_file\n", argv[0]);
                exit(-1);
        }
	if (rename(argv[1],argv[2]) !=0)
        {
                printf("Failed to move file\n");
                exit(-2);
        }
	 return 0;
}
