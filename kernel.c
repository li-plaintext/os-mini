
#define VIDEO_MEMORY_START_POINT 0xB8000 

void write_string(int colour, const char *string);

void kmain()
{
    int colour = 0x04;
    write_string(0x04, "G'day mate, how are you going?");
}


void write_string( int colour, const char *string )
{
    volatile char *video = (volatile char*)VIDEO_MEMORY_START_POINT;
    while( *string != 0 )
    {
        *video++ = *string++;
        *video++ = colour;
    }
}