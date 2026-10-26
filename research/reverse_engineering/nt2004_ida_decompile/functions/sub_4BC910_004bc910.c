int __thiscall sub_4BC910(_DWORD *this, int a2, int a3, int ArgList, char *String, int a6)
{
  int v7; // eax
  int v8; // edi
  float *v9; // edi
  int v10; // eax
  int v11; // ecx
  int v13; // [esp+10h] [ebp-114h] BYREF
  char Buffer; // [esp+14h] [ebp-110h] BYREF
  int v15; // [esp+15h] [ebp-10Fh]
  int v16; // [esp+19h] [ebp-10Bh]
  int v17; // [esp+1Dh] [ebp-107h]
  __int16 v18; // [esp+21h] [ebp-103h]
  char v19; // [esp+23h] [ebp-101h]
  _BYTE v20[253]; // [esp+24h] [ebp-100h] BYREF
  __int16 v21; // [esp+121h] [ebp-3h]
  char v22; // [esp+123h] [ebp-1h]

  v20[0] = byte_629120;
  memset(&v20[1], 0, 0xFCu);
  v21 = 0;
  v22 = 0;
  v7 = this[25];
  v13 = 0;
  if ( v7 )
  {
    if ( sub_5ADC80(&v13, ArgList, 1) == -1 )
    {
      sub_591C90(0, v20);
      if ( (unsigned __int8)sub_500F90((int)&unk_7D7920, 1, (int)aDDevNascar2004_12, 237) )
        sub_500FE0((int)&unk_7D7920, aCubeErrorLoadi_0, ArgList);
      return -1;
    }
    v15 = 0;
    v16 = 0;
    Buffer = byte_629120;
    v17 = 0;
    v18 = 0;
    v19 = 0;
    sprintf(&Buffer, "%s%d", (const char *)(v13 + 28), a2);
    strcpy((char *)(v13 + 28), &Buffer);
    v8 = sub_59EFF0(0);
    if ( v8 )
    {
      while ( !sub_5AD950(v13) )
      {
        v8 = *(_DWORD *)(v8 + 16);
        if ( !v8 )
          goto LABEL_8;
      }
      sub_591C90(0, v20);
      if ( (unsigned __int8)sub_500F90((int)&unk_7D7920, 1, (int)aDDevNascar2004_12, 257) )
        sub_500FE0((int)&unk_7D7920, aCubeErrorRegis, ArgList);
      return -1;
    }
LABEL_8:
    v9 = (float *)&this[8 * a2];
    this[26] = sub_59EFF0(0);
    sub_4BC780((_DWORD *)v9 + 27);
    v10 = sub_5ADC10(&Buffer);
    this[8 * a2 + 32] = v10;
    if ( !v10 && (unsigned __int8)sub_500F90((int)&unk_7D7920, 1, (int)aDDevNascar2004_12, 271) )
      sub_500FE0((int)&unk_7D7920, aJustLoadedAnAn, ArgList);
    v11 = v13;
    *((_DWORD *)v9 + 30) = a6;
    v9[31] = *(float *)(v11 + 8);
    if ( String )
      *((_DWORD *)v9 + 33) = sub_4BCB40(String);
    else
      *((_DWORD *)v9 + 33) = 24;
    *((_DWORD *)v9 + 34) = a2;
  }
  return 0;
}
