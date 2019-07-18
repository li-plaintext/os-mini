nasm -f elf32 kernel.asm -o ksm.o
/usr/local/bin/i386-elf-gcc-9.1.0 -m32 -c kernel.c -o kc.o
/usr/local/bin/i386-elf-ld -T link.ld -o kernel.bin ksm.o kc.o
cp kernel.bin ./os-image/boot/
rm *.o
qemu-system-i386 -kernel kernel.bin
