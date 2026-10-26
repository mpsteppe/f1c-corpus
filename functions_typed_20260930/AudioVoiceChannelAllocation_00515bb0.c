int __usercall sub_515BB0@<eax>(int *a1@<esi>)
{
  int v1; // eax
  _DWORD *v2; // ecx
  unsigned int v3; // ebx
  int result; // eax
  int v5; // edx
  bool v6; // cc
  _DWORD *v7; // ecx
  unsigned int v8; // ebx
  int v9; // edi
  int v10; // edx
  int v11; // edi
  unsigned int v12; // eax
  unsigned int v13; // ebx
  int v14; // edx
  int *v15; // [esp+8h] [ebp-8h]
  int v16; // [esp+Ch] [ebp-4h]

  v1 = a1[72];
  if ( v1 == 1 )
  {
    v2 = (_DWORD *)a1[73];
    a1[77] = v2[7];
    a1[78] = v2[8];
    v3 = v2[3];
    v2[16] = v2[9];
    result = v2[8] / v3;
    v5 = v2[8] % v3;
    v2[13] = 1;
    v2[14] = 1;
    v2[15] = 1;
    v2[17] = 1;
    if ( !v5 )
      v5 = v3;
    v2[18] = v5;
    a1[80] = 0;
    a1[79] = 1;
  }
  else
  {
    if ( v1 <= 0 || v1 > 4 )
    {
      *(_DWORD *)(*a1 + 20) = 24;
      *(_DWORD *)(*a1 + 24) = a1[72];
      *(_DWORD *)(*a1 + 28) = 4;
      (*(void (__cdecl **)(int *))*a1)(a1);
    }
    a1[77] = CeilingDivision(a1[6], 8 * a1[67]);
    result = CeilingDivision(a1[7], 8 * a1[68]);
    v6 = a1[72] <= 0;
    a1[78] = result;
    a1[79] = 0;
    v16 = 0;
    if ( !v6 )
    {
      v15 = a1 + 73;
      do
      {
        v7 = (_DWORD *)*v15;
        v8 = *(_DWORD *)(*v15 + 8);
        v9 = *(_DWORD *)(*v15 + 12);
        v7[16] = v8 * *(_DWORD *)(*v15 + 36);
        v10 = v7[7] % v8;
        v7[14] = v9;
        v11 = v8 * v9;
        v7[13] = v8;
        v7[15] = v11;
        if ( !v10 )
          v10 = v8;
        v12 = v7[8];
        v13 = v7[3];
        v7[17] = v10;
        v14 = v12 % v13;
        if ( !(v12 % v13) )
          v14 = v13;
        v7[18] = v14;
        if ( v11 + a1[79] > 10 )
        {
          *(_DWORD *)(*a1 + 20) = 11;
          (*(void (__cdecl **)(int *))*a1)(a1);
        }
        if ( v11 > 0 )
        {
          do
          {
            a1[a1[79]++ + 80] = v16;
            --v11;
          }
          while ( v11 );
        }
        result = ++v16;
        ++v15;
      }
      while ( v16 < a1[72] );
    }
  }
  return result;
}

