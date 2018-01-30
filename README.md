nasm -f elf32 kernel.asm -o ksm.o
i386-elf-gcc-7.2.0 -m32 -c kernel.c -o kc.o
i386-elf-ld -T link.ld -o kernel.bin ksm.o kc.o
cp kernel.bin ./os-image/boot/
rm *.o
grub-mkrescue -o os.iso os-image

qemu-system-i386 -kernel kernel.bin