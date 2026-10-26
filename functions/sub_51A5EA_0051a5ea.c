int __cdecl sub_51A5EA(int a1, int a2, int a3)
{
  _DWORD *v3; // esi
  int v4; // ebx
  int v5; // eax
  int v6; // ecx
  _BYTE *v7; // edi
  int v8; // edx
  unsigned int v9; // ecx
  int v10; // eax
  int v11; // edi
  int v12; // ecx
  int v13; // edx
  char *v14; // eax
  int v15; // eax
  int v16; // ecx
  int v17; // edx
  _DWORD *v18; // eax
  int v19; // edi
  int result; // eax
  unsigned __int8 *v21; // edi
  bool v22; // cf
  int v23; // edx
  _BYTE *v24; // ebx
  int v25; // eax
  _BYTE *v26; // edi
  int *v27; // eax
  _DWORD v28[258]; // [esp+8h] [ebp-520h]
  _BYTE v29[260]; // [esp+410h] [ebp-118h] BYREF
  unsigned __int8 *v30; // [esp+514h] [ebp-14h]
  int v31; // [esp+518h] [ebp-10h]
  int j; // [esp+51Ch] [ebp-Ch]
  int v33; // [esp+520h] [ebp-8h]
  int v34; // [esp+524h] [ebp-4h]
  int i; // [esp+538h] [ebp+10h]
  int v36; // [esp+538h] [ebp+10h]

  if ( !*(_DWORD *)a3 )
    *(_DWORD *)a3 = (**(int (__cdecl ***)(int, int, int))(a1 + 4))(a1, 1, 1492);
  v3 = *(_DWORD **)a3;
  v4 = a2;
  v5 = 0;
  *(_DWORD *)(*(_DWORD *)a3 + 208) = a2;
  v34 = 0;
  for ( i = 1; i <= 16; ++i )
  {
    v6 = *(unsigned __int8 *)(i + v4);
    v33 = v6;
    if ( v6 >= 1 )
    {
      v7 = &v29[v5];
      LOBYTE(v4) = i;
      BYTE1(v4) = i;
      v8 = v6;
      v9 = (unsigned int)v6 >> 2;
      v10 = v4 << 16;
      LOWORD(v10) = v4;
      v4 = a2;
      memset32(v7, v10, v9);
      memset(&v7[4 * v9], v10, v8 & 3);
      v5 = v8 + v34;
      v34 += v8;
    }
  }
  v29[v5] = 0;
  v11 = v29[0];
  v12 = 0;
  v13 = 0;
  if ( v29[0] )
  {
    v14 = v29;
    do
    {
      v15 = *v14;
      while ( v15 == v11 )
      {
        v15 = (char)v29[v12 + 1];
        v28[++v12] = v13++;
      }
      v13 *= 2;
      v14 = &v29[v12];
      ++v11;
    }
    while ( v29[v12] );
  }
  v16 = 0;
  v17 = 1;
  v18 = v3 + 18;
  do
  {
    if ( *(_BYTE *)(v17 + v4) )
    {
      v19 = v28[v16 + 1];
      v18[18] = v16;
      *(v18 - 17) = v19;
      v16 += *(unsigned __int8 *)(v17 + v4);
      *v18 = v28[v16];
    }
    else
    {
      *v18 = -1;
    }
    ++v17;
    ++v18;
  }
  while ( v17 <= 16 );
  v34 = 0;
  v3[34] = 0xFFFFF;
  memset(v3 + 53, 0, 0x400u);
  v36 = 1;
  for ( j = 7; j >= 0; --j )
  {
    result = v36;
    v21 = (unsigned __int8 *)(v36 + v4);
    v22 = *(_BYTE *)(v36 + v4) == 0;
    v31 = 1;
    v30 = (unsigned __int8 *)(v36 + v4);
    if ( !v22 )
    {
      v23 = 1 << j;
      v24 = (_BYTE *)(v34 + v4 + 17);
      do
      {
        v25 = v28[v34 + 1] << j;
        if ( v23 > 0 )
        {
          v26 = (char *)v3 + v25 + 1236;
          v27 = &v3[v25 + 53];
          v33 = v23;
          do
          {
            *v27++ = v36;
            *v26++ = *v24;
            --v33;
          }
          while ( v33 );
          v21 = v30;
        }
        ++v31;
        result = *v21;
        ++v34;
        ++v24;
      }
      while ( v31 <= result );
      v4 = a2;
    }
    ++v36;
  }
  return result;
}
