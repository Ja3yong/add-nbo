#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <netinet/in.h>

void add(uint8_t buf1[], uint8_t buf2[]) {
    uint32_t* pointer1 = reinterpret_cast<uint32_t*>(buf1);
    uint32_t n1 = ntohl(*pointer1);

    uint32_t* pointer2 = reinterpret_cast<uint32_t*>(buf2);
    uint32_t n2 = ntohl(*pointer2);

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n",n1, n1, n2, n2, n1+n2, n1+n2);
}

int main(int argc, char *argv[]) {
    if(argc <= 2){
        printf("error!\n");
        return 0;
    }
    uint8_t buf1[32];
    uint8_t buf2[32]; 
    FILE *file1;
    FILE *file2;
    file1 = fopen(argv[1], "rb"); 
    file2 = fopen(argv[2], "rb");
    fread(buf1, 1, 1024, file1); 
    fread(buf2, 1, 1024, file2);

    add(buf1, buf2);
    fclose(file1); 
    fclose(file2);
}