#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/mman.h>
#include <math.h>
#include <dirent.h>

// #include "hello_header.h"

char c;

int main(int argc, char const *argv[])
{
	int a = 39;
	int b = 4;
	off_t of = a & ~(b - 1);
	printf("%d, %lld\n", a % b, of);
	return 0;
	if (argc != 2)
    {
        printf("no files\n");
        exit(1);
    }
    int fd = open(argv[1], O_RDONLY);
	if(fd == -1) {
		printf("Err opening file ‘%s’\n", argv[1]);
		return -1;
	}
    fcntl(fd, F_NOCACHE, 1);
    int offset = 0;
    int pagesize = getpagesize();
    struct stat stats;
    fstat(fd, &stats);
    int filesize = stats.st_size;
    int pageoffset = filesize % getpagesize();
    printf("%d byte pages\n", pagesize);
    printf("file %s @ %d bytes\n", argv[1], filesize);

    int pages = ceil((filesize-offset)/(double)pagesize);
    void * mem = mmap(NULL, filesize, PROT_READ | PROT_EXEC, MAP_SHARED, fd, 0);
    perror("Err\n");
    // void (*function)();
    // function = mem;
    // function();

    munmap(mem, filesize + pageoffset);

    // while(offset < filesize)
    // {
    //     if(offset + size > filesize)
    //     {
    //         int pages = ceil((filesize-offset)/(double)pagesize);
    //         size = pages*pagesize;
    //     }
    //     printf("mapping offset %x with size 0x%lx\n", offset, size);
    //     void * mem = mmap(NULL, filesize, PROT_READ | PROT_EXEC, MAP_SHARED, fd, offset);
    //     if(mem == MAP_FAILED)
    //     	return -1;
    //     offset+=size;
    //     int i=0;
    //     for(; i<size; i+=pagesize)
    //     {
    //         c = *((char *)mem+i);
    //     }
    //     munmap(mem, size);
    // }
    return 0;
}


// int main()
// {
//    void (*fun)();
//    int fd;
//    struct stat s;
//    char *map;
//    fd = open("./mybin", O_RDONLY);
//    if(fd == -1) {
//         printf("Err opening file\n");
//         return -1;
//    }
//    int status = fstat(fd, &s);
//    if (status == -1)
//    {
//    		perror("fstat");
//    		return -1;
//    }
//    int pageoffset = s.st_size % getpagesize();
//    map = (char *)mmap(0, s.st_size + pageoffset, PROT_READ | PROT_EXEC, MAP_SHARED, fd, s.st_size - pageoffset);
//    for (int i = 0; i < s.st_size; i++) {
//         char c;
//         c = map[i];
//         putchar(c);
//     }
//    fun = map;
//    fun();
//    close(fd);
//    return 0;
// }

// int main ()
// {
// 	void *myBinCode;

// 	off_t offset, pa_offset;
// 	offset = sizeof(helloworld_bin);
// 	pa_offset = offset & ~(getpagesize() - 1);

// 	printf("offset: %lld, pa_ffset:%lld , pagesize:%d\n", offset, pa_offset, getpagesize());

// 	 copy helloworld_bin to executable buffer     
// 	myBinCode= mmap (0,offset*2 - pa_offset,PROT_READ|PROT_WRITE|PROT_EXEC,
// 			MAP_PRIVATE|MAP_ANON,-1,pa_offset);
// 	memcpy (myBinCode, helloworld_bin, sizeof(helloworld_bin));

// 	/* run code */
// 	((void (*) (void))myBinCode)();
// }