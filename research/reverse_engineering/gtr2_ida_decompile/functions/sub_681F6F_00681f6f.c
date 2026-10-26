int __stdcall sub_681F6F(unsigned int a1, unsigned int a2, int a3)
{
  int v4; // eax
  int v5; // ecx
  int v6; // eax
  int v7; // edx
  int v8; // ecx
  unsigned int v9; // edi
  int i; // eax
  int j; // eax
  unsigned int v12; // eax
  unsigned int v13; // eax
  int v14; // eax
  int v15; // edx
  int v16; // ebx
  _DWORD *v17; // edx
  bool v18; // zf
  unsigned int v19; // edi
  _DWORD *v20; // ecx
  int v22; // ecx
  int v23; // edx
  int v24; // ecx
  int v25; // eax
  int v26; // edi
  int v27; // edx
  int v28; // ecx
  int k; // eax
  int m; // eax
  unsigned int v31; // ebx
  unsigned int v32; // eax
  int v33; // edx
  unsigned int v34; // ebx
  int v35; // ecx
  int v36; // eax
  int v37; // esi
  int v38; // edx
  int v39; // ecx
  unsigned int v40; // [esp+Ch] [ebp-18h]
  int v41; // [esp+Ch] [ebp-18h]
  int v42; // [esp+10h] [ebp-14h]
  int v43; // [esp+14h] [ebp-10h]
  unsigned int v44; // [esp+18h] [ebp-Ch]
  unsigned int v45; // [esp+18h] [ebp-Ch]
  unsigned int v46; // [esp+1Ch] [ebp-8h]
  unsigned int v47; // [esp+1Ch] [ebp-8h]
  unsigned int v48; // [esp+1Ch] [ebp-8h]
  unsigned int v49; // [esp+20h] [ebp-4h]
  unsigned int v50; // [esp+34h] [ebp+10h]
  unsigned int v51; // [esp+34h] [ebp+10h]
  unsigned int v52; // [esp+34h] [ebp+10h]

  v4 = *(_DWORD *)(a3 + 24);
  v5 = *(_DWORD *)(v4 + 4 * a1);
  v6 = *(_DWORD *)(v4 + 4 * a2);
  v7 = *(_DWORD *)(v6 + 52);
  v43 = v5;
  v8 = *(_DWORD *)(v5 + 52);
  v9 = 0;
  v42 = v6;
  v50 = 0;
  for ( i = v8; i != -1; ++v9 )
    i = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a3 + 20) + 4 * i) + 20);
  for ( j = v7; j != -1; ++v50 )
    j = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a3 + 20) + 4 * j) + 20);
  v46 = v9;
  v40 = v50;
  if ( v9 > v50 )
  {
    v12 = v9 - v50;
    do
    {
      v8 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a3 + 20) + 4 * v8) + 20);
      --v9;
      --v12;
    }
    while ( v12 );
  }
  if ( v50 > v9 )
  {
    v13 = v50 - v9;
    do
    {
      --v50;
      --v13;
      v7 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a3 + 20) + 4 * v7) + 20);
    }
    while ( v13 );
  }
  if ( v8 != v7 )
  {
    v14 = *(_DWORD *)(a3 + 20);
    do
    {
      v8 = *(_DWORD *)(*(_DWORD *)(v14 + 4 * v8) + 20);
      v7 = *(_DWORD *)(*(_DWORD *)(v14 + 4 * v7) + 20);
      --v9;
      --v50;
    }
    while ( v8 != v7 );
  }
  v15 = *(_DWORD *)(v43 + 52);
  v16 = *(_DWORD *)(v42 + 52);
  v49 = a1;
  v44 = a1;
  if ( v9 < v46 )
  {
    v47 = v46 - v9;
    do
    {
      v17 = *(_DWORD **)(*(_DWORD *)(a3 + 20) + 4 * v15);
      if ( v49 > v17[18] )
        v49 = v17[18];
      if ( v44 < v17[22] )
        v44 = v17[22];
      v18 = v47-- == 1;
      v15 = v17[5];
    }
    while ( !v18 );
  }
  v19 = a2;
  v48 = a2;
  if ( v50 < v40 )
  {
    v51 = v40 - v50;
    do
    {
      v20 = *(_DWORD **)(*(_DWORD *)(a3 + 20) + 4 * v16);
      if ( v19 > v20[18] )
        v19 = v20[18];
      if ( v48 < v20[22] )
        v48 = v20[22];
      v18 = v51-- == 1;
      v16 = v20[5];
    }
    while ( !v18 );
  }
  if ( a1 >= v19 && a1 <= v48 || a2 >= v49 && a2 <= v44 )
  {
    if ( v49 < v19 )
      return 1;
    if ( v49 > v19 )
      return -1;
  }
  v22 = *(_DWORD *)(a3 + 20);
  v23 = *(_DWORD *)(v22 + 4 * **(_DWORD **)(v43 + 16));
  v24 = *(_DWORD *)(v22 + 4 * **(_DWORD **)(v42 + 16));
  v25 = *(_DWORD *)(v24 + 24);
  v26 = *(_DWORD *)(v23 + 24);
  v27 = *(_DWORD *)(v23 + 20);
  v45 = 0;
  v52 = 0;
  v28 = *(_DWORD *)(v24 + 20);
  v41 = v25;
  for ( k = v27; k != -1; ++v45 )
    k = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a3 + 20) + 4 * k) + 20);
  for ( m = v28; m != -1; ++v52 )
    m = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a3 + 20) + 4 * m) + 20);
  v31 = v45;
  if ( v45 > v52 )
  {
    v32 = v45 - v52;
    do
    {
      v33 = *(_DWORD *)(*(_DWORD *)(a3 + 20) + 4 * v27);
      v26 = *(_DWORD *)(v33 + 24);
      v27 = *(_DWORD *)(v33 + 20);
      --v31;
      --v32;
    }
    while ( v32 );
  }
  if ( v52 <= v31 )
  {
    v36 = v41;
  }
  else
  {
    v34 = v52 - v31;
    do
    {
      --v34;
      v35 = *(_DWORD *)(*(_DWORD *)(a3 + 20) + 4 * v28);
      v36 = *(_DWORD *)(v35 + 24);
      v28 = *(_DWORD *)(v35 + 20);
    }
    while ( v34 );
  }
  if ( v27 != v28 )
  {
    v37 = *(_DWORD *)(a3 + 20);
    do
    {
      v38 = *(_DWORD *)(v37 + 4 * v27);
      v39 = *(_DWORD *)(v37 + 4 * v28);
      v26 = *(_DWORD *)(v38 + 24);
      v36 = *(_DWORD *)(v39 + 24);
      v27 = *(_DWORD *)(v38 + 20);
      v28 = *(_DWORD *)(v39 + 20);
    }
    while ( v27 != v28 );
  }
  if ( v26 )
  {
    if ( !v36 )
      return -1;
  }
  else if ( v36 )
  {
    return 1;
  }
  if ( a2 > a1 )
    return -1;
  return a2 < a1;
}
