int __thiscall sub_5B7210(_DWORD *this, int a2, int a3, int a4)
{
  int *v5; // eax
  int *v6; // edx
  int result; // eax
  int i; // edi
  int v9; // ebx
  int v10; // esi
  float *v11; // edx
  __int16 v12; // fps
  double v13; // st7
  bool v14; // c0
  char v15; // c2
  bool v16; // c3
  int j; // edx
  int v18; // esi
  __int16 v19; // fps
  char v20; // c0
  int v21; // [esp+8h] [ebp-Ch] BYREF
  int v22; // [esp+Ch] [ebp-8h] BYREF
  int v23; // [esp+10h] [ebp-4h] BYREF
  __int16 v24; // [esp+1Ah] [ebp+6h]

  if ( (*(_BYTE *)(a2 + 60) & 0x10) != 0 )
  {
    v5 = (int *)(a4 + 48);
  }
  else
  {
    sub_59E5E0((_DWORD *)a2, &v21, &v22, &v23);
    v5 = &v21;
  }
  v6 = *(int **)(a3 + 284);
  v24 = HIWORD(v5);
  *(_DWORD *)(a3 + 268) = 0;
  result = *v6;
  if ( (*v6 & 0x100) != 0 )
  {
    for ( i = this[79]; i; i = *(_DWORD *)(i + 204) )
    {
      v9 = *(_DWORD *)(a3 + 268);
      if ( v9 >= 8 )
        break;
      if ( *(char *)i < 0 )
      {
        v10 = 0;
        v11 = (float *)(i + 88);
        do
        {
          v13 = *(v11 - 1) * *(float *)(a3 + 232) + v11[1] * *(float *)(a3 + 240) + *(float *)(a3 + 236) * *v11 - v11[2];
          v14 = v13 < *(float *)(a3 + 24);
          v15 = 0;
          v16 = v13 == *(float *)(a3 + 24);
          LOWORD(result) = v12;
          if ( v13 > *(float *)(a3 + 24) )
            break;
          ++v10;
          v11 += 4;
        }
        while ( v10 < 6 );
        if ( v10 == 6 )
        {
          result = *(_DWORD *)(a3 + 272);
          *(_DWORD *)(56 * v9 + result) = i;
          ++*(_DWORD *)(a3 + 268);
        }
      }
    }
    for ( j = this[75]; j; j = *(_DWORD *)(j + 204) )
    {
      v18 = *(_DWORD *)(a3 + 268);
      if ( v18 >= 8 )
        break;
      result = *(_DWORD *)j & 0xA0;
      if ( (_BYTE)result == 0x80 )
      {
        HIWORD(result) = v24;
        LOWORD(result) = v19;
        if ( !v20 )
        {
          *(_DWORD *)(56 * v18 + *(_DWORD *)(a3 + 272)) = j;
          result = 56 * *(_DWORD *)(a3 + 268);
          *(float *)(result + *(_DWORD *)(a3 + 272) + 16) = 1.0 / *(float *)(j + 80);
          ++*(_DWORD *)(a3 + 268);
        }
      }
    }
  }
  return result;
}
