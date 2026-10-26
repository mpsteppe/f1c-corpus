int __stdcall sub_6D4710(int *a1, int a2, unsigned int a3, int *a4)
{
  int v5; // eax
  int v6; // eax
  int v7; // edi
  int v8; // ebx
  unsigned int v9; // esi
  int v10; // eax
  _BYTE *v11; // edi
  int v12; // eax
  int v13; // edi
  int v14; // esi
  int v15; // ebx
  char *v16; // eax
  int v17; // ecx
  int v18; // eax
  int v19; // ebx
  int result; // eax
  int i; // esi
  int v22; // edi
  int v23; // eax
  char v24; // al
  _DWORD v25[257]; // [esp+Ch] [ebp-510h]
  _BYTE v26[260]; // [esp+410h] [ebp-10Ch] BYREF
  int v27; // [esp+514h] [ebp-8h]
  int v28; // [esp+518h] [ebp-4h]
  int v29; // [esp+528h] [ebp+Ch]
  int v30; // [esp+52Ch] [ebp+10h]
  int v31; // [esp+530h] [ebp+14h]
  int v32; // [esp+530h] [ebp+14h]

  if ( a3 >= 4 )
  {
    v5 = *a1;
    *(_DWORD *)(v5 + 20) = 50;
    *(_DWORD *)(v5 + 24) = a3;
    (*(void (__stdcall **)(int *))v5)(a1);
  }
  if ( a2 )
    v30 = a1[a3 + 22];
  else
    v30 = a1[a3 + 26];
  if ( !v30 )
  {
    v6 = *a1;
    *(_DWORD *)(v6 + 20) = 50;
    *(_DWORD *)(v6 + 24) = a3;
    (*(void (__stdcall **)(int *))v6)(a1);
  }
  if ( !*a4 )
    *a4 = (*(int (__stdcall **)(int *, int, int))a1[1])(a1, 1, 1280);
  v7 = 0;
  v8 = 1;
  v28 = *a4;
  v31 = 0;
  v27 = 1;
  do
  {
    v9 = *(unsigned __int8 *)(v8 + v30);
    if ( (int)(v9 + v7) > 256 )
    {
      v10 = *a1;
      *(_DWORD *)(v10 + 20) = 8;
      (*(void (__stdcall **)(int *))v10)(a1);
    }
    if ( v9 )
    {
      BYTE1(v8) = v8;
      v11 = &v26[v7];
      v12 = v8 << 16;
      LOWORD(v12) = v8;
      v8 = v27;
      memset32(v11, v12, v9 >> 2);
      memset(&v11[4 * (v9 >> 2)], v12, v9 & 3);
      v7 = v9 + v31;
      v31 += v9;
    }
    v27 = ++v8;
  }
  while ( v8 <= 16 );
  v26[v7] = 0;
  v32 = v7;
  v13 = 0;
  v14 = 0;
  v15 = v26[0];
  if ( v26[0] )
  {
    v16 = v26;
    do
    {
      if ( *v16 == v15 )
      {
        do
        {
          v17 = (char)v26[v14 + 1];
          v25[v14++] = v13++;
        }
        while ( v17 == v15 );
      }
      if ( v13 >= 1 << v15 )
      {
        v18 = *a1;
        *(_DWORD *)(v18 + 20) = 8;
        (*(void (__stdcall **)(int *))v18)(a1);
      }
      v16 = &v26[v14];
      v13 *= 2;
      ++v15;
    }
    while ( v26[v14] );
  }
  v19 = v28 + 1024;
  memset((void *)(v28 + 1024), 0, 0x100u);
  v29 = a2 != 0 ? 15 : 255;
  result = v32;
  for ( i = 0; i < v32; ++i )
  {
    v22 = *(unsigned __int8 *)(v30 + i + 17);
    if ( v22 > v29 || *(_BYTE *)(v19 + v22) )
    {
      v23 = *a1;
      *(_DWORD *)(v23 + 20) = 8;
      (*(void (__stdcall **)(int *))v23)(a1);
    }
    v24 = v26[i];
    *(_DWORD *)(v28 + 4 * v22) = v25[i];
    *(_BYTE *)(v19 + v22) = v24;
    result = v32;
  }
  return result;
}
