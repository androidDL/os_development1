nasm -f elf32 -o start.o start.asm

gcc -m32 -Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -I./include -c -o main.o main.c

ld -m elf_i386 -T link.ld -o kernel.bin start.o main.o

grub-file --is-x86-multiboot kernel.bin

mkdir -p isodir/boot/grub
cp kernel.bin isodir/boot/kernel.bin
cp grub.cfg isodir/boot/grub/grub.cfg
grub-mkrescue -o kernel.iso isodir

qemu-system-x86_64 -cdrom kernel.iso
