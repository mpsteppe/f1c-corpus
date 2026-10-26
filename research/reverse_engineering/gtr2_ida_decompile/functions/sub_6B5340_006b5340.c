int __stdcall sub_6B5340(int *a1, unsigned int a2, unsigned int a3)
{
  unsigned int v3; // ebx
  int v5; // eax
  int v6; // eax
  _DWORD *i; // eax
  unsigned int v8; // ebx
  unsigned int v9; // esi
  int v10; // eax
  unsigned int v11; // edx
  int v12; // ecx
  int v14; // [esp+Ch] [ebp-4h]
  _DWORD *v15; // [esp+18h] [ebp+8h]

  v3 = a3;
  v14 = a1[1];
  if ( a3 > 0x3B9AC9F0 )
  {
    v5 = *a1;
    *(_DWORD *)(v5 + 20) = 54;
    *(_DWORD *)(v5 + 24) = 1;
    (*(void (__stdcall **)(int *))v5)(a1);
  }
  if ( (a3 & 7) != 0 )
  {
    v3 = 8 - (a3 & 7) + a3;
    a3 = v3;
  }
  if ( a2 >= 2 )
  {
    v6 = *a1;
    *(_DWORD *)(v6 + 20) = 14;
    *(_DWORD *)(v6 + 24) = a2;
    (*(void (__stdcall **)(int *))v6)(a1);
  }
  i = *(_DWORD **)(v14 + 4 * a2 + 52);
  v15 = 0;
  if ( i )
  {
    while ( i[2] < v3 )
    {
      v15 = i;
      i = (_DWORD *)*i;
      if ( !i )
        goto LABEL_10;
    }
  }
  else
  {
LABEL_10:
    v8 = v3 + 16;
    if ( v15 )
      v9 = dword_744A68[a2];
    else
      v9 = dword_744A60[a2];
    if ( v9 > 1000000000 - v8 )
      v9 = 1000000000 - v8;
    for ( i = (_DWORD *)sub_6D3B00(a1, v9 + v8); !i; i = (_DWORD *)sub_6D3B00(a1, v9 + v8) )
    {
      v9 >>= 1;
      if ( v9 < 0x32 )
      {
        v10 = *a1;
        *(_DWORD *)(v10 + 20) = 54;
        *(_DWORD *)(v10 + 24) = 2;
        (*(void (__stdcall **)(int *))v10)(a1);
      }
    }
    v11 = v9 + v8;
    v3 = a3;
    *(_DWORD *)(v14 + 76) += v11;
    *i = 0;
    i[1] = 0;
    i[2] = a3 + v9;
    if ( v15 )
      *v15 = i;
    else
      *(_DWORD *)(v14 + 4 * a2 + 52) = i;
  }
  v12 = i[1];
  i[1] = v3 + v12;
  i[2] -= v3;
  return (int)i + v12 + 16;
}
