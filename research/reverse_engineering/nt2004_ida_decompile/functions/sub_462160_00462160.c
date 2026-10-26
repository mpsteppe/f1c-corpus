char __thiscall sub_462160(unsigned __int8 *this, int a2, const char *a3, const char *a4)
{
  unsigned __int8 v5; // al
  unsigned __int8 v6; // cl
  char v7; // bl
  int v8; // edx
  bool v9; // zf
  int v10; // eax
  const char *v11; // ecx
  char *v12; // eax
  char *v13; // edi
  char v14; // cl
  int v16; // [esp+Ch] [ebp-B4h] BYREF
  int v17; // [esp+10h] [ebp-B0h] BYREF
  char Destination[80]; // [esp+14h] [ebp-ACh] BYREF
  _BYTE v19[32]; // [esp+64h] [ebp-5Ch] BYREF
  _BYTE v20[60]; // [esp+84h] [ebp-3Ch] BYREF

  v5 = this[30093];
  v6 = this[30092];
  v7 = 0;
  this[30114] = 0;
  this[30115] = 0;
  this[30116] = 0;
  this[30117] = 0;
  if ( (unsigned __int16)sub_461DF0(v6, v5) == *(_WORD *)(a2 + 8) )
    this[30114] = 1;
  if ( a3 && a4 )
  {
    if ( sub_45D7F0((_DWORD *)this + 7523, a3, &v16) && sub_45D7F0((_DWORD *)this + 7523, a4, &v17) )
    {
      v8 = *(_DWORD *)(a2 + 12);
      v7 = 0;
      v16 += v17;
      if ( v16 == v8 )
        this[30115] = 1;
    }
    else
    {
      v7 = 0;
    }
  }
  if ( sub_45D7F0((_DWORD *)this + 7523, aTerrainIni, &v16) )
  {
    v9 = v16 + dword_7D741C + 305986170 == *(_DWORD *)(a2 + 16);
    v16 += dword_7D741C + 305986170;
    if ( v9 )
      this[30116] = 1;
  }
  sub_462C80(v19);
  if ( (unsigned __int8)sub_464BD0(v19) )
  {
    v10 = sub_4E8DA0(v20);
    if ( v10 )
    {
      v11 = (const char *)(v10 + 4 + strlen((const char *)(v10 + 4)));
      if ( (unsigned int)v11 > v10 + 4 )
      {
        while ( *v11 != 92 )
        {
          if ( (unsigned int)--v11 <= v10 + 4 )
            goto LABEL_20;
        }
        ++v11;
      }
LABEL_20:
      strncpy(Destination, v11, 0x4Fu);
      Destination[79] = 0;
      v12 = &Destination[strlen(Destination)];
      if ( v12 > Destination )
      {
        while ( *v12 != 46 )
        {
          if ( --v12 <= Destination )
            goto LABEL_25;
        }
        *v12 = 0;
      }
LABEL_25:
      v13 = &Destination[strlen(Destination) + 1];
      v14 = byte_5FFC78;
      *(_DWORD *)--v13 = dword_5FFC74;
      v13[4] = v14;
      if ( sub_45D7F0((_DWORD *)this + 7523, Destination, &v16) && v16 == *(_DWORD *)(a2 + 20) )
        this[30117] = 1;
    }
  }
  if ( this[30114] && this[30115] && this[30116] && this[30117] )
    v7 = 1;
  nullsub_6(v19);
  return v7;
}
