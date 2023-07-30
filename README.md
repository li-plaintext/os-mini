##### http://tuxdiary.com/2013/05/22/simple-kernel-in-c/

#### MAC OS: brew install nasm i386-elf-gcc qemu
#### Ubuntu: apt install nasm i386-elf-gcc qemu

```
nasm -f elf32 kernel.asm -o ksm.o
```

```
gcc -m32 -c kernel.c -o kc.o
```

```
ld -m elf_i386 -T link.ld -o kernel.bin ksm.o kc.o
```

### Execution
```
qemu-system-i386 -kernel kernel.bin
```


### Build os.iso 
```
cp kernel.bin ./os-image/boot/
rm *.o
i386-elf-grub-mkrescue -o os.iso os-image
```