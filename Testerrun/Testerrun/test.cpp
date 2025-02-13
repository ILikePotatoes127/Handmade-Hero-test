

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

    Test.IsThisOnFire = 1;
    Test.Damage = 2;
    Test.ParticlesPerSecond = 3;
    Test.HowManyCooks = 4;


    projectile* ProjPointer = &Test;
    short* MrPointer = (short*) &Test;

    projectile Projectiles[40];

    projectile* ProjectilePointer = Projectiles;

    int SizeOfProjectiles = sizeof(Projectiles); //16*40 size of actual array
    int SizeOfProjectilePointer = sizeof(ProjectilePointer); //8 size of pointer

    Projectiles[30].Damage = 60;

    (ProjectilePointer + 30 /*C++ automatically does *sizeof(projectile) for you)*/)->Damage = 100;

    //manually doing it
    ((projectile*)((char *)ProjectilePointer + 30 * sizeof(projectile)))->Damage = 100;
    
    //creates byte pointer (8 bits/1 byte)
    char* BytePointer = (char*)ProjectilePointer;
    //Moves the byte pointer by a certain amount
    BytePointer = BytePointer + 30*sizeof(projectile);
    //casts it back to a projectile pointer (16 bytes)
    projectile* Thirty = (projectile*)BytePointer;
    //access the Damage member of the Thirty pointer and set it to 200
    Thirty->Damage = 200;
    //there is a difference between an object and a pointer
    //use Test.Damage for object. Use Test->Damage for pointer


}

