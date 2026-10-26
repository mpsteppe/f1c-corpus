int __stdcall sub_67E31F(int a1, float *a2, int a3)
{
  unsigned int v3; // edi
  char *v4; // ecx
  float *v5; // eax
  _BYTE *v6; // ebx
  double v7; // st7
  double v8; // st7
  int v9; // esi
  double v10; // st7
  double v11; // st7
  float *v12; // eax
  int result; // eax
  _BYTE v14[4]; // [esp+0h] [ebp-14Ch] BYREF
  char v15; // [esp+4h] [ebp-148h] BYREF
  float v16[17]; // [esp+100h] [ebp-4Ch] BYREF
  int v17; // [esp+144h] [ebp-8h]
  float v18; // [esp+148h] [ebp-4h]
  float v19; // [esp+158h] [ebp+Ch]
  int v20; // [esp+158h] [ebp+Ch]

  if ( a3 )
  {
    memset(v16, 0, 0x40u);
    v17 = LODWORD(v18) | 0xC00;
    v16[16] = v18;
    v3 = 0;
    v4 = &v15;
    v5 = a2 + 3;
    v6 = (_BYTE *)(v14 - (_BYTE *)a2);
    do
    {
      v7 = v16[v3];
      *((float *)v4 - 1) = *(v5 - 3);
      v8 = v7 + *v5;
      *(float *)v4 = *(v5 - 2);
      v9 = *((_DWORD *)v5 - 1);
      v18 = v8;
      *((_DWORD *)v4 + 1) = v9;
      v19 = v8 + 0.5;
      v17 = (int)v19;
      v10 = (double)v17;
      v20 = v3 & 3;
      *(float *)((char *)v5 + (_DWORD)v6) = v10;
      v11 = v18 - v10;
      if ( v20 != 3 )
        v16[v3 + 1] = 0.4375 * v11 + v16[v3 + 1];
      if ( v3 < 0xC )
      {
        if ( (v3 & 3) != 0 )
          v16[v3 + 3] = 0.1875 * v11 + v16[v3 + 3];
        v16[v3 + 4] = 0.3125 * v11 + v16[v3 + 4];
        if ( v20 != 3 )
          v16[v3 + 5] = v11 * 0.0625 + v16[v3 + 5];
      }
      ++v3;
      v4 += 16;
      v5 += 4;
    }
    while ( v3 < 0x10 );
    v12 = (float *)v14;
  }
  else
  {
    v12 = a2;
  }
  result = sub_67D6C7(v12, a1, 1, a3);
  if ( result >= 0 )
    return 0;
  return result;
}
