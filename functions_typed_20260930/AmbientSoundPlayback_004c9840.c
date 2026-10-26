int __thiscall sub_4C9840(_DWORD *this)
{
  int *v1; // esi
  const char *v3; // eax
  int v4; // edx
  int v5; // eax
  void (__thiscall ***v6)(_DWORD, int); // ecx
  double v7; // st7
  float *v8; // edi
  double v9; // st6
  LPVOID v11[2]; // [esp+Ch] [ebp-218h] BYREF
  int v12; // [esp+14h] [ebp-210h]
  int v13; // [esp+18h] [ebp-20Ch]
  char v14; // [esp+1Ch] [ebp-208h]
  float v15; // [esp+20h] [ebp-204h]
  _BYTE v16[512]; // [esp+24h] [ebp-200h] BYREF

  v1 = (int *)dword_8AC4C4;
  if ( dword_8AC4C4 )
  {
    v11[0] = 0;
    v11[1] = (LPVOID)-1;
    StringCopyWithBufferRealloc(byte_5EA438);
    v3 = (const char *)dword_5EC3E0;
    v12 = -1;
    v13 = -1;
    v14 = 0;
    if ( !dword_5EC3E0 )
      v3 = byte_5EA438;
    StringFormatWithBufferOverflowCheck(v16, "%s%s%s", v3, aAmbient, aPithornWav);
    StringCopyWithBufferRealloc(v16);
    v4 = *v1;
    v12 = -1;
    v13 = -1;
    v14 = 0;
    v5 = (*(int (__thiscall **)(int *, LPVOID *, _DWORD, int))(v4 + 92))(v1, v11, 0, 1);
    this[7] = v5;
    if ( v5 )
    {
      if ( (*(int (__thiscall **)(int))(*(_DWORD *)v5 + 20))(v5) )
      {
        v6 = (void (__thiscall ***)(_DWORD, int))this[7];
        if ( v6 )
          (**v6)(v6, 1);
        this[7] = 0;
      }
      else
      {
        v7 = flt_7CF554;
        v8 = (float *)this[7];
        v15 = *(float *)&dword_7CF578;
        if ( flt_7CF530 > 0.0 )
          v9 = 1.0 / flt_7CF530;
        else
          v9 = 1.0;
        v8[7] = v9;
        v8[8] = 1.0 - v9 * v15;
        v8[9] = v7;
      }
    }
    if ( v11[0] )
      FreeWrapper_7bcf(v11[0]);
  }
  return 0;
}

