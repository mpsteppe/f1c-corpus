int __thiscall sub_5005A0(_DWORD *this, char *ArgList)
{
  char v3; // bl
  const char *v4; // ecx
  char *v5; // eax
  int v6; // esi
  _DWORD *v7; // eax
  _DWORD *v8; // edx
  _DWORD *v9; // eax
  int v10; // ecx
  _DWORD *v11; // eax
  int v12; // edi
  _DWORD *v13; // eax
  _DWORD *v14; // ebx
  _DWORD *v15; // esi
  _DWORD *v16; // eax
  int v17; // ecx
  int v18; // esi
  int v19; // ebx
  int v20; // edi
  void *v21; // ecx
  int v22; // ecx
  int v24; // [esp+Ch] [ebp-378h]
  char v25[28]; // [esp+10h] [ebp-374h] BYREF
  char Destination[64]; // [esp+2Ch] [ebp-358h] BYREF
  _BYTE v27[384]; // [esp+6Ch] [ebp-318h] BYREF
  int v28; // [esp+1ECh] [ebp-198h]
  char v29; // [esp+1F0h] [ebp-194h]
  int v30; // [esp+1F8h] [ebp-18Ch]
  int v31; // [esp+1FCh] [ebp-188h]
  int v32; // [esp+200h] [ebp-184h]
  char Str[384]; // [esp+204h] [ebp-180h] BYREF

  sub_5004E0(this);
  v3 = (char)ArgList;
  sub_578600(ArgList);
  sub_57B490(ArgList, 91, (int)(this + 8));
  v4 = &ArgList[strlen(ArgList)];
  if ( v4 > ArgList )
  {
    while ( *v4 != 92 )
    {
      if ( --v4 <= ArgList )
        goto LABEL_6;
    }
    ++v4;
  }
LABEL_6:
  strncpy(Destination, v4, 0x3Fu);
  Destination[63] = 0;
  v5 = &Destination[strlen(Destination)];
  if ( v5 > Destination )
  {
    while ( *v5 != 46 )
    {
      if ( --v5 <= Destination )
        goto LABEL_11;
    }
    *v5 = 0;
  }
LABEL_11:
  _strupr(Destination);
  sub_578600(Destination);
  sub_57A080(v25);
  if ( (unsigned __int8)sub_57A2F0(ArgList, 1) )
  {
    memset(Str, 0, sizeof(Str));
    v28 = 0;
    v32 = 0;
    v30 = 0;
    v31 = 0;
    v29 = 1;
    while ( sub_57A490(Str, 384) )
    {
      sub_577B60(v27);
      if ( strstr(Str, aSlipcurve) )
      {
        ++this[2];
      }
      else if ( strstr(Str, aCompound) )
      {
        ++this[4];
      }
    }
    v6 = this[2];
    v7 = operator new(40 * v6 + 4);
    if ( v7 )
    {
      v8 = v7 + 1;
      *v7 = v6;
      v9 = v7 + 1;
      if ( v6 - 1 >= 0 )
      {
        v10 = v6;
        do
        {
          *v9 = 0;
          v9[1] = -1;
          v9[9] = 0;
          v9 += 10;
          --v10;
        }
        while ( v10 );
      }
      v11 = v8;
    }
    else
    {
      v11 = 0;
    }
    v12 = this[4];
    this[3] = v11;
    v13 = operator new(2072 * v12 + 4);
    if ( v13 )
    {
      v14 = v13 + 1;
      *v13 = v12;
      v15 = v13 + 1;
      if ( v12 - 1 >= 0 )
      {
        do
        {
          *v15 = 0;
          v15[1] = -1;
          sub_401000((int)(v15 + 6), 512, 4, (int (__thiscall *)(int))sub_4FF780);
          v15 += 518;
          --v12;
        }
        while ( v12 );
      }
      v16 = v14;
      v3 = (char)ArgList;
    }
    else
    {
      v16 = 0;
    }
    v17 = this[4];
    v18 = 0;
    this[5] = v16;
    if ( (!v17 || !v16) && (unsigned __int8)sub_500F90((int)&unk_7D7920, 1, (int)aDDevNascar2004_22, 1003) )
      sub_500FE0((int)&unk_7D7920, aNoCompoundsFou, v3);
    sub_57A530(v25);
    v19 = 0;
    v24 = 0;
    if ( sub_57A490(Str, 384) )
    {
      v20 = 0;
      do
      {
        sub_577B60(v27);
        if ( strstr(Str, aSlipcurve) )
        {
          if ( v19 >= this[2] )
          {
            if ( (unsigned __int8)sub_500F90((int)&unk_7D7920, 1, (int)aDDevNascar2004_22, 1023) )
              sub_500FE0((int)&unk_7D7920, aBadSyntaxInFil, (char)ArgList);
            break;
          }
          v21 = (void *)(v20 + this[3]);
          ++v19;
          v20 += 40;
          sub_4FEDA0(v21, (int)v25);
        }
        if ( strstr(Str, aCompound) )
        {
          if ( v24 >= this[4] )
          {
            if ( (unsigned __int8)sub_500F90((int)&unk_7D7920, 1, (int)aDDevNascar2004_22, 1038) )
              sub_500FE0((int)&unk_7D7920, aBadSyntaxInFil_0, (char)ArgList);
            break;
          }
          v22 = v18 + this[5];
          ++v24;
          v18 += 2072;
          sub_4FFBD0(v22, (int)v25);
        }
      }
      while ( sub_57A490(Str, 384) );
    }
    if ( (v19 != this[2] || v24 != this[4])
      && (unsigned __int8)sub_500F90((int)&unk_7D7920, 1, (int)aDDevNascar2004_22, 1051) )
    {
      sub_500FE0((int)&unk_7D7920, aBadSyntaxInFil_1, (char)ArgList);
    }
    sub_57A360(v25);
  }
  else if ( (unsigned __int8)sub_500F90((int)&unk_7D7920, 1, (int)aDDevNascar2004_22, 980) )
  {
    sub_500FE0((int)&unk_7D7920, aCouldNotOpenS, (char)ArgList);
  }
  return sub_57A0A0(v25);
}
