char __thiscall sub_46F1B0(_BYTE *this)
{
  CHAR *v2; // eax
  int v3; // eax
  CHAR *v4; // eax
  int v5; // ecx
  int v6; // eax
  void *v7; // edi
  _DWORD *v8; // eax
  _DWORD *v9; // eax
  int v10; // ecx
  double v11; // st6
  double v12; // st5
  double v13; // st3
  long double v14; // st7
  int v16; // [esp+8h] [ebp-3C0h] BYREF
  char *Source; // [esp+Ch] [ebp-3BCh]
  int v18; // [esp+10h] [ebp-3B8h]
  _DWORD v19[7]; // [esp+14h] [ebp-3B4h] BYREF
  char v20[125]; // [esp+30h] [ebp-398h] BYREF
  __int16 v21; // [esp+ADh] [ebp-31Bh]
  char v22; // [esp+AFh] [ebp-319h]
  char String[384]; // [esp+B0h] [ebp-318h] BYREF
  int v24; // [esp+230h] [ebp-198h]
  char v25; // [esp+234h] [ebp-194h]
  int v26; // [esp+23Ch] [ebp-18Ch]
  int v27; // [esp+240h] [ebp-188h]
  int v28; // [esp+244h] [ebp-184h]
  char Buffer[384]; // [esp+248h] [ebp-180h] BYREF

  if ( !this[412] && (*(int (__thiscall **)(_BYTE *))(*(_DWORD *)this + 172))(this) )
  {
    sub_57A080(v19);
    Source = (char *)operator new(0x100u);
    *Source = 0;
    v2 = (CHAR *)dword_62A098;
    v18 = 256;
    if ( !dword_62A098 )
      v2 = &byte_629120;
    sub_578560(v2);
    v3 = (*(int (__thiscall **)(_BYTE *))(*(_DWORD *)this + 172))(this);
    sub_578560(v3);
    v4 = Source;
    if ( !Source )
      v4 = &byte_629120;
    if ( (unsigned __int8)sub_57A2F0(v4, 1) )
    {
      memset(Buffer, 0, sizeof(Buffer));
      v5 = *((_DWORD *)this + 70);
      v24 = 0;
      v28 = 0;
      v26 = 0;
      v27 = 0;
      v25 = 1;
      v16 = 0;
      if ( v5 )
        sub_59E1D0(this + 388, this + 392, this + 396, this + 400, this + 404, this + 408);
      if ( *((_DWORD *)this + 67) )
        sub_593DA0(this + 364, this + 368, this + 372, this + 376, this + 380, this + 384);
      while ( sub_57A490(Buffer, 384) )
      {
        v6 = sub_577B60(String);
        if ( v6 != 1 && (v6 <= 2 || v6 > 4) )
        {
          sub_578220(aInstancePositi, (int)(this + 388), (int)(this + 392), (int)(this + 396), 0, 0, 0, 0, 0);
          if ( sub_578220(aInstanceOrient, (int)(this + 400), (int)(this + 404), (int)(this + 408), 0, 0, 0, 0, 0) )
            *((_DWORD *)this + 81) = *((_DWORD *)this + 101);
          sub_578220(aInstanceVeloci, (int)(this + 320), 0, 0, 0, 0, 0, 0, 0);
          sub_578220(aInstanceDistan, (int)(this + 288), 0, 0, 0, 0, 0, 0, 0);
          sub_578220(aViewPosition, (int)(this + 364), (int)(this + 368), (int)(this + 372), 0, 0, 0, 0, 0);
          sub_578220(aViewOrientatio, (int)(this + 376), (int)(this + 380), (int)(this + 384), 0, 0, 0, 0, 0);
          sub_578110(aAllowInteracti, (int)&v16, 0, 0, 0);
          sub_578220(aHorizontalFov, (int)(this + 424), 0, 0, 0, 0, 0, 0, 0);
          sub_578220(aVerticalFov, (int)(this + 428), 0, 0, 0, 0, 0, 0, 0);
          sub_578220(aFadeInTime, (int)(this + 276), 0, 0, 0, 0, 0, 0, 0);
          v20[0] = byte_629120;
          memset(&v20[1], 0, 0x7Cu);
          v21 = 0;
          v22 = 0;
          if ( sub_577ED0(String, aIsicam, v20, 0) )
          {
            v7 = (void *)*((_DWORD *)this + 85);
            if ( v7 )
            {
              sub_459AC0(*((LPVOID ***)this + 85));
              sub_5BE8AE(v7);
            }
            v8 = operator new(4u);
            if ( v8 )
              v9 = sub_459A60(v8);
            else
              v9 = 0;
            *((_DWORD *)this + 85) = v9;
            sub_459B20((_DWORD **)v9, v19, (int)v20);
            *((float *)this + 89) = sub_459D70((void *)*((_DWORD *)this + 85));
          }
        }
      }
      if ( v16 )
        this[286] = 1;
      sub_57A360(v19);
      *((_DWORD *)this + 79) = *((_DWORD *)this + 80);
      v10 = *((_DWORD *)this + 70);
      v11 = *((float *)this + 92) - *((float *)this + 98);
      v12 = *((float *)this + 93) - *((float *)this + 99);
      v13 = *((float *)this + 91) - *((float *)this + 97);
      v14 = sqrt(v12 * v12 + v11 * v11 + v13 * v13);
      *((float *)this + 72) = v14;
      *((float *)this + 73) = v14;
      if ( v10 )
        sub_59E170(
          *((_DWORD *)this + 97),
          *((_DWORD *)this + 98),
          *((_DWORD *)this + 99),
          *((float *)this + 100),
          *((float *)this + 101),
          *((float *)this + 102));
      if ( *((_DWORD *)this + 67) )
        sub_5934A0(
          *((_DWORD *)this + 91),
          *((_DWORD *)this + 92),
          *((float *)this + 93),
          *((float *)this + 94),
          *((float *)this + 95),
          *((float *)this + 96));
      sub_46EFD0(this);
      this[412] = 1;
    }
    if ( Source )
      sub_5BE8AE(Source);
    sub_57A0A0(v19);
  }
  return this[412];
}
