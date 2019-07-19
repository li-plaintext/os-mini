#define VIDEO_MEMORY_START_POINT 0xB8000 

static const int VGA_WIDTH = 80;
static const int VGA_HEIGHT = 25;

volatile char *video = (volatile char*)VIDEO_MEMORY_START_POINT;

void write_string(int colour, const char *string);
int strlen(const char* str);

void kmain()
{
    int colour = 0x04;

    for (int index = 0; index < VGA_HEIGHT - 2; index++) {
      write_string(0x0A, "G'day mate, how are you going?\n");
    }
}


void write_string( int colour, const char *string )
{
    int len_of_input = strlen(string);

    while( *string != 0 )
    {
        if (*string == '\n' && VGA_WIDTH > len_of_input) {
          // new line
          video += (VGA_WIDTH - len_of_input + 1) * 2;
          return;
        }
        *video++ = *string++;
        *video++ = colour;
    }
}

int strlen(const char* str){
		int len = 0;
		while(str[len])
				len++;
		return len;
}