int __stdcall sub_6447D4(int a1, int a2, int a3, int a4, int a5, int a6, int a7, _DWORD *a8, int a9, int a10)
{
  int v10; // ebx
  int v11; // eax
  _BYTE v13[72]; // [esp+4h] [ebp-C8h] BYREF
  int v14; // [esp+4Ch] [ebp-80h]
  _BYTE v15[20]; // [esp+58h] [ebp-74h] BYREF
  _DWORD v16[4]; // [esp+6Ch] [ebp-60h] BYREF
  _DWORD v17[6]; // [esp+7Ch] [ebp-50h] BYREF
  _BYTE v18[24]; // [esp+94h] [ebp-38h] BYREF
  int v19; // [esp+B4h] [ebp-18h]
  int v20; // [esp+B8h] [ebp-14h]
  int v21; // [esp+BCh] [ebp-10h]
  _BYTE v22[12]; // [esp+C0h] [ebp-Ch] BYREF

  sub_64AADB(v22);
  sub_64E466(v15);
  v10 = 0;
  if ( a1 )
  {
    if ( a4 && a8 )
    {
      if ( a9 == -1 )
        a9 = 524292;
      v11 = sub_64E610(v13, a1, a2, a3, 0, 0);
      if ( v11 < 0 )
        goto LABEL_10;
      v16[1] = a5;
      v16[2] = a6;
      v16[0] = a4;
      v16[3] = 0;
      v17[0] = *a8;
      v17[1] = a8[1];
      v17[2] = a8[2];
      v17[3] = a8[3];
      v17[4] = 0;
      v17[5] = 1;
      qmemcpy(v18, v17, sizeof(v18));
      v19 = v14;
      v20 = a10;
      v21 = a7;
      v11 = sub_64E329(v13, v16, a9);
      if ( v11 < 0 )
LABEL_10:
        v10 = v11;
    }
    else
    {
      v10 = -2005530516;
    }
  }
  else
  {
    v10 = -2005530516;
  }
  sub_64E60B(v15);
  sub_64AAE5(v22);
  return v10;
}
