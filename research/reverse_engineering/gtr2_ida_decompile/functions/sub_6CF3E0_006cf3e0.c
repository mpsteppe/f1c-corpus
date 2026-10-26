unsigned int __stdcall sub_6CF3E0(int *a1, unsigned int a2, unsigned int a3, _DWORD *a4)
{
  int v5; // eax
  int v6; // esi
  int v7; // eax
  _DWORD *v8; // edx
  int v9; // edi
  int v10; // ebx
  unsigned int v11; // esi
  int v12; // eax
  _BYTE *v13; // edi
  int v14; // eax
  int v15; // edi
  int v16; // esi
  int v17; // ebx
  char *v18; // eax
  int v19; // ecx
  int v20; // eax
  int v21; // ecx
  int i; // eax
  int v23; // esi
  unsigned __int8 v24; // bl
  int v25; // edx
  int v26; // ecx
  int v27; // ebx
  int v28; // eax
  char *v29; // esi
  int v30; // edi
  int v31; // eax
  char v32; // cl
  _BYTE *v33; // edx
  int *v34; // eax
  int v35; // esi
  bool v36; // zf
  unsigned int result; // eax
  int v38; // edi
  int j; // esi
  int v40; // eax
  _DWORD v41[258]; // [esp+8h] [ebp-520h]
  _BYTE v42[260]; // [esp+410h] [ebp-118h] BYREF
  int v43; // [esp+514h] [ebp-14h]
  int v44; // [esp+518h] [ebp-10h]
  int v45; // [esp+51Ch] [ebp-Ch]
  _DWORD *v46; // [esp+520h] [ebp-8h]
  int v47; // [esp+524h] [ebp-4h]
  int v48; // [esp+538h] [ebp+10h]
  int v49; // [esp+53Ch] [ebp+14h]
  int v50; // [esp+53Ch] [ebp+14h]

  if ( a3 >= 4 )
  {
    v5 = *a1;
    *(_DWORD *)(v5 + 20) = 50;
    *(_DWORD *)(v5 + 24) = a3;
    (*(void (__stdcall **)(int *))v5)(a1);
  }
  if ( a2 )
  {
    v6 = a1[a3 + 46];
    v48 = v6;
  }
  else
  {
    v48 = a1[a3 + 50];
    v6 = a1[a3 + 50];
  }
  if ( !v6 )
  {
    v7 = *a1;
    *(_DWORD *)(v7 + 20) = 50;
    *(_DWORD *)(v7 + 24) = a3;
    (*(void (__stdcall **)(int *))v7)(a1);
  }
  if ( !*a4 )
    *a4 = (*(int (__stdcall **)(int *, int, int))a1[1])(a1, 1, 1424);
  v8 = (_DWORD *)*a4;
  v9 = 0;
  v10 = 1;
  v46 = v8;
  v8[35] = v6;
  v49 = 0;
  v47 = 1;
  while ( 1 )
  {
    v11 = *(unsigned __int8 *)(v10 + v6);
    if ( (int)(v11 + v9) > 256 )
    {
      v12 = *a1;
      *(_DWORD *)(v12 + 20) = 8;
      (*(void (__stdcall **)(int *))v12)(a1);
      v8 = v46;
    }
    if ( v11 )
    {
      BYTE1(v10) = v10;
      v13 = &v42[v9];
      v14 = v10 << 16;
      LOWORD(v14) = v10;
      v10 = v47;
      memset32(v13, v14, v11 >> 2);
      v8 = v46;
      memset(&v13[4 * (v11 >> 2)], v14, v11 & 3);
      v9 = v11 + v49;
      v49 += v11;
    }
    v47 = ++v10;
    if ( v10 > 16 )
      break;
    v6 = v48;
  }
  v42[v9] = 0;
  v43 = v9;
  v15 = 0;
  v16 = 0;
  v17 = v42[0];
  if ( v42[0] )
  {
    v18 = v42;
    do
    {
      if ( *v18 == v17 )
      {
        do
        {
          v19 = (char)v42[v16 + 1];
          v41[++v16] = v15++;
        }
        while ( v19 == v17 );
      }
      if ( v15 >= 1 << v17 )
      {
        v20 = *a1;
        *(_DWORD *)(v20 + 20) = 8;
        (*(void (__stdcall **)(int *))v20)(a1);
        v8 = v46;
      }
      v18 = &v42[v16];
      v15 *= 2;
      ++v17;
    }
    while ( v42[v16] );
  }
  v21 = 0;
  for ( i = 1; i <= 16; ++i )
  {
    v23 = v48;
    v24 = *(_BYTE *)(i + v48);
    if ( v24 )
    {
      v8[i + 18] = v21 - v41[v21 + 1];
      v21 += v24;
      v8[i] = v41[v21];
    }
    else
    {
      v8[i] = -1;
    }
  }
  v8[17] = 0xFFFFF;
  memset(v8 + 36, 0, 0x400u);
  v25 = 0;
  v26 = 7;
  v50 = 0;
  v27 = 1;
  v45 = 7;
  do
  {
    v28 = *(unsigned __int8 *)(v27 + v23);
    if ( *(_BYTE *)(v27 + v23) )
    {
      v29 = (char *)(v25 + v23 + 17);
      v30 = 1 << v26;
      v47 = (int)v29;
      v44 = v28;
      do
      {
        v31 = v41[v25 + 1] << v26;
        if ( v30 > 0 )
        {
          v32 = *v29;
          v33 = (char *)v46 + v31 + 1168;
          v34 = &v46[v31 + 36];
          v35 = v30;
          do
          {
            *v34++ = v27;
            *v33++ = v32;
            --v35;
          }
          while ( v35 );
          v25 = v50;
          v26 = v45;
        }
        ++v25;
        v29 = (char *)(v47 + 1);
        v36 = v44 == 1;
        v50 = v25;
        ++v47;
        --v44;
      }
      while ( !v36 );
      v23 = v48;
    }
    ++v27;
    v45 = --v26;
  }
  while ( v26 >= 0 );
  result = a2;
  if ( a2 )
  {
    v38 = v43;
    for ( j = 0; j < v38; ++j )
    {
      result = *(unsigned __int8 *)(v48 + j + 17);
      if ( result > 0xF )
      {
        v40 = *a1;
        *(_DWORD *)(v40 + 20) = 8;
        result = (*(int (__stdcall **)(int *))v40)(a1);
      }
    }
  }
  return result;
}
