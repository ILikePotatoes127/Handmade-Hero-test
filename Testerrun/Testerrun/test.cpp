

#include <windows.h>

void foo(void)
{
    const char *Foo = "asdg";
    OutputDebugStringA(
        "This is the first thing we have actually printed.\n");
}

struct projectile
{
    //NOTE:These are the members, or "fields", of this structure!

    char unsigned IsThisOnFire; //NOTE: 1 is it's on fire, 0 if it's not
    int Damage; // NOTE: This is how much damage it does on impact
    int ParticlesPerSecond; //NOTE: For special effects
    short HowManyCooks; // NOTE: Too many cooks?
};

int CALLBACK WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR lpCmdLine,
    int nCmdShow)
{

    /*
    char SmallS; //8 bits 256 values [-128, 127]
    char unsigned SmallU; // 8 bits unsigned - 256 different values [0,255]

    short MediumS; // 16 bits - 65536
    short unsigned MediumU;

    int LargeS; // 32 bits - 4 billion
    int unsigned LargeU;
    */

    //little endian - little bit comes first
    //big endian - larger bits comes next

    projectile Test;

    int x = 5;
    int y = 10;
    int z = 12;
    int w;

    //x = 0xA
    //x = x << 4; shift operator

    x = 0;


    //Bitwise operators
    // | (or) & (and) ^ (XOR) ~ (NOT)
    x = x | (1 << 4); 
    //A way to combine sets tgt. 
    //Combines current x set with another set 
    //with 1 shifted left 4 (16 bits/1 space). 00000010
    x = x | (1 << 8);
    //then combines x 00000010
    //with a 1 shifted left 8 (32 bits/2 spaces). 00000100
    //combines to 00000110
    x = x & (1 << 4);
    //only gives back bits where both bits have in common
    x = ~x;
    //gives back inverse of the bits all 0s turn into 1s.
    //All 1s turn into 0s
    
    x = (1 << 4) | (1 << 8);
    y = (1 << 8) | (1 << 16);
    x = x ^ y;
    //exlusive Or (XOR)
    //Gets rid of all values that are the same (turns into 0)
    //keeps all "or" values/ different values (turns into 1)
    //SO, 00000110 XOR 00010100 turns into 00010010


    // "boolean" - is something "true or false", "on or off"
    x = 0; //FALSE
    y = 1; //TRUE
    z = 27384650; //TRUE (anything non-zero)
    w = -673; //TRUE

    //Things are either zero or they are not.

    int less = (x < y);
    int greater = (x > y);
    int  equal = (x == y);
    int notequal = (x != y);


    int a = 3;
    switch (a)
    {
    case 0:
        break;
    case 1:
        break;
    case 2:
        break;
    case 3:
        //falls through to case 4 too
    case 4:
        break;
    case 5:
        break;
    case 6:
        break;
    default:
        break;
    }



}

