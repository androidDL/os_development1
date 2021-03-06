#include <system.h>

void *memcpy(void *dest,const void *src,size_t count){
    const char *sp=(const char *)src;
    char *dp=(char *)dest;
    for(;count!=0;count--)
        *dp++=*sp++;
}

void *memset(void *dest, char val, size_t count){
    char *dp=(char *)dest;
    for(;count!=0;count--){
        *dp++=val;
    }
}
unsigned short *memsetw(unsigned short *dest, unsigned short val, size_t count){
    for(;count!=0;count--){
        *dest++=val;
    }
    return dest;
}
size_t strlen(const char *str){
    int count=0;
    while (str[count++]);
    return count;
}
unsigned char inportb (unsigned short _port){
    unsigned char rv;
    __asm__ __volatile__("inb %1,%0":"=a"(rv):"dN"(_port));
    return rv;
}
void outportb (unsigned short _port, unsigned char _data){
    __asm__ __volatile__("outb %1,%0"::"dN"(_port),"a"(_data));
}

void main(){
    
    gdt_install();
    
    init_video();

    puts("Hello World!");

    for(;;);
}