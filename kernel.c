kmain()
{
        char* vidmem=(char*)0xb8000;
        char* text = "hey mate, how are you going?";

        for(int i = 0; i < 29 ; i++) {
          vidmem[i*2] = text[i];
          vidmem[i*2+1] = 0x02;
        }
}
