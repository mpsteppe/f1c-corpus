int __usercall sub_6B4F40@<eax>(int *a1@<esi>)
{
  int v1; // ecx
  _DWORD *v2; // ecx
  int v3; // edx
  unsigned int v4; // edi
  unsigned int v5; // eax
  int result; // eax
  int v7; // edx
  int v8; // et2
  int v9; // eax
  int v10; // eax
  int v11; // edx
  bool v12; // cc
  _DWORD *v13; // ecx
  unsigned int v14; // edi
  int v15; // ebx
  int v16; // edx
  int v17; // ebx
  unsigned int v18; // eax
  unsigned int v19; // edi
  int v20; // edx
  int v21; // eax
  _DWORD *v22; // [esp+8h] [ebp-8h]
  int v23; // [esp+Ch] [ebp-4h]

  v1 = a1[83];
  if ( v1 == 1 )
  {
    v2 = (_DWORD *)a1[84];
    v3 = v2[9];
    v4 = v2[3];
    a1[88] = v2[7];
    v5 = v2[8];
    v2[16] = v3;
    a1[89] = v5;
    v8 = v5 % v4;
    result = v5 / v4;
    v7 = v8;
    v2[13] = 1;
    v2[14] = 1;
    v2[15] = 1;
    v2[17] = 1;
    if ( !v8 )
      v7 = v4;
    a1[90] = 1;
    v2[18] = v7;
    a1[91] = 0;
  }
  else
  {
    if ( v1 <= 0 || v1 > 4 )
    {
      v9 = *a1;
      *(_DWORD *)(v9 + 20) = 26;
      *(_DWORD *)(v9 + 24) = v1;
      *(_DWORD *)(v9 + 28) = 4;
      (*(void (__stdcall **)(int *))v9)(a1);
    }
    v10 = sub_6B5FB0(a1[7], 8 * a1[78]);
    v11 = 8 * a1[79];
    a1[88] = v10;
    result = sub_6B5FB0(a1[8], v11);
    a1[89] = result;
    v12 = a1[83] <= 0;
    a1[90] = 0;
    v23 = 0;
    if ( !v12 )
    {
      v22 = a1 + 84;
      do
      {
        v13 = (_DWORD *)*v22;
        v14 = *(_DWORD *)(*v22 + 8);
        v15 = *(_DWORD *)(*v22 + 12);
        v13[16] = v14 * *(_DWORD *)(*v22 + 36);
        v16 = v13[7] % v14;
        v13[14] = v15;
        v17 = v14 * v15;
        v13[13] = v14;
        v13[15] = v17;
        if ( !v16 )
          v16 = v14;
        v18 = v13[8];
        v19 = v13[3];
        v13[17] = v16;
        v20 = v18 % v19;
        if ( !(v18 % v19) )
          v20 = v19;
        v13[18] = v20;
        if ( v17 + a1[90] > 10 )
        {
          v21 = *a1;
          *(_DWORD *)(v21 + 20) = 13;
          (*(void (__stdcall **)(int *))v21)(a1);
        }
        if ( v17 > 0 )
        {
          do
          {
            a1[a1[90] + 91] = v23;
            --v17;
            ++a1[90];
          }
          while ( v17 );
        }
        result = v23 + 1;
        v12 = ++v23 < a1[83];
        ++v22;
      }
      while ( v12 );
    }
  }
  return result;
}
