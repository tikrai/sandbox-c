#include <stdio.h>
#include <stdint.h>

#define BIN_PATTERN "%c%c%c%c %c%c%c%c %c%c%c%c %c%c%c%c"
#define BINARY(byte)  \
  (byte & 0x8000 ? '1' : '0'), \
  (byte & 0x4000 ? '1' : '0'), \
  (byte & 0x2000 ? '1' : '0'), \
  (byte & 0x1000 ? '1' : '0'), \
  (byte & 0x800 ? '1' : '0'), \
  (byte & 0x400 ? '1' : '0'), \
  (byte & 0x200 ? '1' : '0'), \
  (byte & 0x100 ? '1' : '0'), \
  (byte & 0x80 ? '1' : '0'), \
  (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0')

static void printmap();
static void SpiWrite(uint16_t* txAddress, uint32_t txLen);
uint16_t counter = 0;

int main() {


    printmap();



}

static void printmap()
{
    uint8_t dot_map[] = {
            0x00, 0xf8, 0x00, 0xf8, 0xe0, 0x07, 0xe0, 0x07,
            0x00, 0xf8, 0x00, 0xf8, 0xe0, 0x07, 0xe0, 0x07,
            0x1f, 0x00, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x1f, 0x00, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00,
    };
    printf("\n  ");
    for (int i = 0; i < 32; i+=2) {
        printf("0x%02x%02x, ", dot_map[i], dot_map[i+1]);
        if (!((i+2)%8)) printf("\n  ");
    }
}

static void sizes()
{
    unsigned short a = 10;
    printf("Size of short %x is %d\n", a, sizeof(a));
    unsigned short* a1 = &a;
    printf("Size of short pointer %x is %d pointing at %x\n", a1, sizeof(a1), *a1);
    a1++;
    printf("Size of short pointer %x is %d pointing at %x\n", a1, sizeof(a1), *a1);
    uint16_t* a2 = &a;
    printf("Size of uint16_t pointer %x is %d\n", a2, sizeof(a2));

    uint32_t b = 10;
    printf("Size of uint32_t %x is %d\n", b, sizeof(b));
    uint32_t* b1 = &b;
    printf("Size of uint32_t pointer %x is %d pointing at %x\n", b1, sizeof(b1), *b1);
//    b1++;
//    printf("Size of uint32_t pointer %x is %d pointing at %x\n", b1, sizeof(b1), *b1);
    uint32_t x = (uint32_t)b1;
    uint32_t* x1 = (uint32_t*)x;
    printf("Size of uint32_t x pointer %x is %d pointing at %x\n", x1, sizeof(x1), *x1);

//    for(int i = 1; i < 300; i++) {
//        printf(" %04x  "BIN_PATTERN"\n", counter, BINARY(counter));
//        counter += 2;
//        if (counter & 0x80)
//        {
//            counter += 0x80; // skip turning on circular
//        }
//    }

//    uint16_t data = 0x11;
//    SpiWrite(&data, 1);
//    return 0;

}



static void SpiWrite(uint16_t* txAddress, uint32_t txLen)
{

    char data_command = 'C';
    {

        printf("%d @%x", txLen, txAddress);
        do
        {
            uint16_t txData = *txAddress;
            printf(" %c-", data_command);
            printf("%x", txData);

            txAddress++;


            txLen--;
        }
        while (txLen);
        printf("\n");
    }

}
