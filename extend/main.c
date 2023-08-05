struct grub_signature {
    unsigned int magic;
    unsigned int flags;
    unsigned int checksum;
};

#define GRUB_MAGIC 0x1BADB002
#define GRUB_FLAGS 0x0
#define GRUB_CHECKSUM (-1 * (GRUB_MAGIC + GRUB_FLAGS))

struct grub_signature gs __attribute__ ((section (".grub_sig"))) =
    { GRUB_MAGIC, GRUB_FLAGS, GRUB_CHECKSUM };


void put_c(unsigned int pos, char c)
{
    char* video = (char*)0xB8000;
    video[2 * pos ] = c;
    video[2 * pos + 1] = 0x3F;
}

void put_s(char *str)
{
    int i = 0;
    while(*str){        
        put_c(i++, *(str++));
    }
}

void main(void)
{
    char txt[] = "MyOS";
    put_s("where is this text"); // does not work, puts(txt) works.
    while (1) {}
}