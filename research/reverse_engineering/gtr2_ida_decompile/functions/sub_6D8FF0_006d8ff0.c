int __usercall sub_6D8FF0@<eax>(int *a1@<esi>)
{
  int v1; // ecx
  _DWORD *v2; // ecx
  unsigned int v3; // edi
  unsigned int v4; // eax
  int result; // eax
  int v6; // edx
  int v7; // et2
  int v8; // eax
  int v9; // eax
  int v10; // ecx
  bool v11; // cc
  _DWORD *v12; // ecx
  unsigned int v13; // edi
  unsigned int v14; // eax
  int v15; // ebx
  int v16; // edx
  int v17; // ebx
  unsigned int v18; // eax
  unsigned int v19; // edi
  int v20; // edx
  int v21; // eax
  int v22; // eax
  int v23; // ecx
  _DWORD *v24; // [esp+8h] [ebp-8h]
  int v25; // [esp+Ch] [ebp-4h]

  v1 = a1[63];
  if ( v1 == 1 )
  {
    v2 = (_DWORD *)a1[64];
    v3 = v2[3];
    a1[68] = v2[7];
    v4 = v2[8];
    a1[69] = v4;
    v7 = v4 % v3;
    result = v4 / v3;
    v6 = v7;
    v2[13] = 1;
    v2[14] = 1;
    v2[15] = 1;
    v2[16] = 8;
    v2[17] = 1;
    if ( !v7 )
      v6 = v3;
    v2[18] = v6;
    a1[70] = 1;
    a1[71] = 0;
  }
  else
  {
    if ( v1 <= 0 || v1 > 4 )
    {
      v8 = *a1;
      *(_DWORD *)(v8 + 20) = 26;
      *(_DWORD *)(v8 + 24) = v1;
      *(_DWORD *)(v8 + 28) = 4;
      (*(void (__stdcall **)(int *))v8)(a1);
    }
    v9 = sub_6B5FB0(a1[7], 8 * a1[60]);
    v10 = a1[8];
    a1[68] = v9;
    result = sub_6B5FB0(v10, 8 * a1[61]);
    a1[69] = result;
    v11 = a1[63] <= 0;
    a1[70] = 0;
    v25 = 0;
    if ( !v11 )
    {
      v24 = a1 + 64;
      do
      {
        v12 = (_DWORD *)*v24;
        v13 = *(_DWORD *)(*v24 + 8);
        v14 = *(_DWORD *)(*v24 + 28);
        v15 = *(_DWORD *)(*v24 + 12);
        v12[16] = 8 * v13;
        v16 = v14 % v13;
        v12[14] = v15;
        v17 = v13 * v15;
        v12[13] = v13;
        v12[15] = v17;
        if ( !(v14 % v13) )
          v16 = v13;
        v18 = v12[8];
        v19 = v12[3];
        v12[17] = v16;
        v20 = v18 % v19;
        if ( !(v18 % v19) )
          v20 = v19;
        v21 = v17 + a1[70];
        v12[18] = v20;
        if ( v21 > 10 )
        {
          v22 = *a1;
          *(_DWORD *)(v22 + 20) = 13;
          (*(void (__stdcall **)(int *))v22)(a1);
        }
        if ( v17 > 0 )
        {
          do
          {
            a1[a1[70] + 71] = v25;
            --v17;
            ++a1[70];
          }
          while ( v17 );
        }
        result = v25 + 1;
        v11 = ++v25 < a1[63];
        ++v24;
      }
      while ( v11 );
    }
  }
  v23 = a1[51];
  if ( v23 > 0 )
  {
    result = v23 * a1[68];
    if ( result >= 0xFFFF )
      result = 0xFFFF;
    a1[50] = result;
  }
  return result;
}
