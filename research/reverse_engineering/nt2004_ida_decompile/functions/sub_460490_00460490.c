void __thiscall sub_460490(_DWORD *this, char *Source, char a3)
{
  unsigned int v4; // kr04_4
  size_t v5; // esi
  float v6; // [esp+0h] [ebp-1A8h]
  char v7[64]; // [esp+18h] [ebp-190h] BYREF
  char v8[125]; // [esp+58h] [ebp-150h] BYREF
  __int16 v9; // [esp+D5h] [ebp-D3h]
  char v10; // [esp+D7h] [ebp-D1h]
  _BYTE v11[8]; // [esp+D8h] [ebp-D0h] BYREF
  char Destination[200]; // [esp+E0h] [ebp-C8h] BYREF

  v4 = strlen(Source) + 1;
  v5 = v4 - 1;
  if ( (int)(v4 - 1) >= 0 )
  {
    if ( (int)(v4 - 1) > 127 )
      v5 = 127;
  }
  else
  {
    v5 = 0;
  }
  v6 = dbl_7DA9D0;
  sub_4D0D00(4, 6, v5, 0, LODWORD(v6), 3);
  strncpy(Destination, Source, v5);
  Destination[v5] = 0;
  sub_463A40(v11, 0, -1, -1);
  if ( a3 )
  {
    v8[0] = byte_629120;
    memset(&v8[1], 0, 0x7Cu);
    v9 = 0;
    v10 = 0;
    v7[0] = byte_629120;
    memset(&v7[1], 0, 63);
    sub_4CE010(v7, 64);
    sub_45D040(v7, Destination, v8, 128);
    sub_4BA6B0(v8);
    sub_45D100(&byte_764D68, (int)v8, 0, 16909060, 0);
  }
  this[163] = 0;
}
