int __thiscall sub_51F750(char *this, char *Source)
{
  int v4; // eax
  int v5; // ebx
  int v6; // edi
  int v7; // ebx
  int v8; // edi
  int v9; // ebp
  int v10; // [esp+8h] [ebp-3B8h]
  char v11[28]; // [esp+Ch] [ebp-3B4h] BYREF
  char String2[64]; // [esp+28h] [ebp-398h] BYREF
  char Buffer[64]; // [esp+68h] [ebp-358h] BYREF
  char String[384]; // [esp+A8h] [ebp-318h] BYREF
  int v15; // [esp+228h] [ebp-198h]
  char v16; // [esp+22Ch] [ebp-194h]
  int v17; // [esp+234h] [ebp-18Ch]
  int v18; // [esp+238h] [ebp-188h]
  int v19; // [esp+23Ch] [ebp-184h]
  char Str[384]; // [esp+240h] [ebp-180h] BYREF

  sub_57A080(v11);
  memset(Str, 0, sizeof(Str));
  v15 = 0;
  v19 = 0;
  v17 = 0;
  v18 = 0;
  v16 = 1;
  if ( (unsigned __int8)sub_57A2F0(Source, 0) )
  {
    while ( sub_57A490(Str, 384) )
    {
      if ( !sub_577B60(String) && strstr(Str, aPhysical) && sub_57A490(Str, 384) )
      {
        do
        {
          v4 = sub_577B60(String);
          if ( v4 == 1 )
            break;
          if ( !v4 )
          {
            sub_578220(aRadiusadd, (int)this, 0, 0, 0, 0, 0, 0, 0);
            sub_578220(aRadiusmult, (int)(this + 4), 0, 0, 0, 0, 0, 0, 0);
            sub_578220(aRadiusmax, (int)(this + 8), 0, 0, 0, 0, 0, 0, 0);
            sub_578220(aEngine_0, (int)(this + 12), 0, 0, 0, 0, 0, 0, 0);
            sub_578220(aAerodiv, (int)(this + 16), 0, 0, 0, 0, 0, 0, 0);
            sub_578220(aAeromin, (int)(this + 20), 0, 0, 0, 0, 0, 0, 0);
            sub_578220(aVertmult, (int)(this + 24), 0, 0, 0, 0, 0, 0, 0);
            sub_578220(aFrontwingdetac, (int)(this + 28), 0, 0, 0, 0, 0, 0, 0);
            sub_578220(aFrontwingrando, (int)(this + 32), 0, 0, 0, 0, 0, 0, 0);
            sub_578220(aFrontwingpos, (int)(this + 36), (int)(this + 40), (int)(this + 44), 0, 0, 0, 0, 0);
            sub_578220(
              aFrontwingmassi,
              (int)(this + 48),
              (int)(this + 52),
              (int)(this + 56),
              (int)(this + 60),
              0,
              0,
              0,
              0);
            sub_578220(aFrontwingcollp, (int)(this + 64), (int)(this + 68), (int)(this + 72), 0, 0, 0, 0, 0);
            sub_578220(aRearwingdetach, (int)(this + 76), 0, 0, 0, 0, 0, 0, 0);
            sub_578220(aRearwingrandom, (int)(this + 80), 0, 0, 0, 0, 0, 0, 0);
            sub_578220(aRearwingpos, (int)(this + 84), (int)(this + 88), (int)(this + 92), 0, 0, 0, 0, 0);
            sub_578220(
              aRearwingmassin,
              (int)(this + 96),
              (int)(this + 100),
              (int)(this + 104),
              (int)(this + 108),
              0,
              0,
              0,
              0);
            sub_578220(aRearwingcollpa, (int)(this + 112), (int)(this + 116), (int)(this + 120), 0, 0, 0, 0, 0);
            sub_578220(aTirecutdull, (int)(this + 124), (int)(this + 128), 0, 0, 0, 0, 0, 0);
            sub_578220(aTirecutsharp, (int)(this + 132), (int)(this + 136), 0, 0, 0, 0, 0, 0);
            sub_578220(aWheelbend, (int)(this + 140), 0, 0, 0, 0, 0, 0, 0);
            sub_578220(aWheeldetach, (int)(this + 144), 0, 0, 0, 0, 0, 0, 0);
            sub_578220(aWheelrandom, (int)(this + 148), 0, 0, 0, 0, 0, 0, 0);
            v5 = 0;
            v6 = (int)(this + 160);
            do
            {
              sprintf(Buffer, "Wheel%dMassInertia", v5);
              sub_578220(Buffer, v6 - 8, v6 - 4, v6, v6 + 4, 0, 0, 0, 0);
              sprintf(Buffer, "Wheel%dCollParams", v5);
              sub_578220(Buffer, v6 + 8, v6 + 12, v6 + 16, 0, 0, 0, 0, 0);
              ++v5;
              v6 += 28;
            }
            while ( v5 < 4 );
            v7 = 0;
            v8 = (int)(this + 512);
            v9 = (int)(this + 364);
            v10 = (int)(this + 312);
            do
            {
              sprintf(String2, "Part%dDetach", v7);
              sub_578220(String2, v10 - 48, 0, 0, 0, 0, 0, 0, 0);
              sprintf(String2, "Part%dRandom", v7);
              sub_578220(String2, v10, 0, 0, 0, 0, 0, 0, 0);
              sprintf(String2, "Part%dPos", v7);
              sub_578220(String2, v9 - 4, v9, v9 + 4, 0, 0, 0, 0, 0);
              sprintf(String2, "Part%dMassInertia", v7);
              sub_578220(String2, v8 - 8, v8 - 4, v8, v8 + 4, 0, 0, 0, 0);
              sprintf(String2, "Part%dCollParams", v7);
              sub_578220(String2, v8 + 8, v8 + 12, v8 + 16, 0, 0, 0, 0, 0);
              ++v7;
              v9 += 12;
              v8 += 28;
              v10 += 4;
            }
            while ( v7 < 12 );
            sub_577ED0(String, aRadiatorcoveri, this + 840, 0);
            sub_577ED0(String, aDeactivateinst, this + 872, 0);
            sub_577ED0(String, aActivateinstan, this + 904, 0);
            sub_578220(aWallskidthresh, (int)(this + 936), 0, 0, 0, 0, 0, 0, 0);
          }
        }
        while ( sub_57A490(Str, 384) );
      }
    }
    sub_57A360(v11);
    sub_57A0A0(v11);
    return 0;
  }
  else
  {
    sub_57A0A0(v11);
    return -1;
  }
}
