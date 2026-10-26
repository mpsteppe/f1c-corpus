int __stdcall sub_6D4FF0(int *a1, int a2, int a3)
{
  int v3; // eax
  int v4; // esi
  int i; // ecx
  int v6; // edx
  int v7; // edx
  int v8; // edi
  int j; // ecx
  int v10; // esi
  int v11; // edi
  int v12; // esi
  int *v13; // ecx
  int v14; // edi
  int v15; // esi
  int v16; // esi
  int v17; // ecx
  int *v18; // eax
  int v19; // eax
  int v20; // ecx
  int k; // edi
  int v22; // esi
  int v23; // eax
  int v24; // esi
  int v25; // ecx
  int v26; // edx
  int v27; // eax
  int v30; // ecx
  int v31; // eax
  int v32; // ecx
  int v33; // ecx
  int m; // edx
  int result; // eax
  _DWORD v36[257]; // [esp+Ch] [ebp-82Ch] BYREF
  _DWORD v37[257]; // [esp+410h] [ebp-428h] BYREF
  int v38; // [esp+814h] [ebp-24h]
  int v39; // [esp+818h] [ebp-20h]
  int v40; // [esp+81Ch] [ebp-1Ch]
  int v41; // [esp+820h] [ebp-18h]
  int v42; // [esp+824h] [ebp-14h]
  int v43; // [esp+828h] [ebp-10h]
  int v44; // [esp+82Ch] [ebp-Ch]
  int v45; // [esp+830h] [ebp-8h]
  char v46; // [esp+834h] [ebp-4h]

  v38 = 0;
  v39 = 0;
  v40 = 0;
  v41 = 0;
  v42 = 0;
  v43 = 0;
  v44 = 0;
  v45 = 0;
  memset(v37, 0, sizeof(v37));
  v46 = 0;
  memset(v36, 0xFFu, sizeof(v36));
  *(_DWORD *)(a3 + 1024) = 1;
  while ( 1 )
  {
    v3 = -1;
    v4 = 1000000000;
    for ( i = 0; i <= 256; ++i )
    {
      v6 = *(_DWORD *)(a3 + 4 * i);
      if ( v6 && v6 <= v4 )
      {
        v4 = *(_DWORD *)(a3 + 4 * i);
        v3 = i;
      }
    }
    v7 = -1;
    v8 = 1000000000;
    for ( j = 0; j <= 256; ++j )
    {
      v10 = *(_DWORD *)(a3 + 4 * j);
      if ( v10 && v10 <= v8 && j != v3 )
      {
        v8 = *(_DWORD *)(a3 + 4 * j);
        v7 = j;
      }
    }
    if ( v7 < 0 )
      break;
    v11 = v37[v3];
    *(_DWORD *)(a3 + 4 * v3) += *(_DWORD *)(a3 + 4 * v7);
    v12 = v36[v3];
    v13 = &v36[v3];
    *(_DWORD *)(a3 + 4 * v7) = 0;
    v37[v3] = v11 + 1;
    if ( v12 >= 0 )
    {
      do
      {
        v3 = *v13;
        v14 = v37[*v13];
        v15 = v36[*v13];
        v13 = &v36[*v13];
        v37[v3] = v14 + 1;
      }
      while ( v15 >= 0 );
    }
    v16 = v37[v7];
    v36[v3] = v7;
    v17 = v36[v7];
    v18 = &v36[v7];
    v37[v7] = v16 + 1;
    if ( v17 >= 0 )
    {
      do
      {
        v19 = *v18;
        v20 = v36[v19];
        ++v37[v19];
        v18 = &v36[v19];
      }
      while ( v20 >= 0 );
    }
  }
  for ( k = 0; k <= 256; ++k )
  {
    v22 = v37[k];
    if ( v22 )
    {
      if ( v22 > 32 )
      {
        v23 = *a1;
        *(_DWORD *)(v23 + 20) = 39;
        (*(void (__stdcall **)(int *))v23)(a1);
      }
      ++*((_BYTE *)&v38 + v22);
    }
  }
  v24 = 16;
  v25 = 30;
  v26 = 16;
  do
  {
    for ( ; *((_BYTE *)&v38 + v25 + 2); --*((_BYTE *)&v38 + v27) )
    {
      v27 = v25;
      if ( !*((_BYTE *)&v38 + v25) )
      {
        while ( !*((_BYTE *)&v37[256] + v27-- + 3) )
          ;
      }
      *((_BYTE *)&v38 + v25 + 2) -= 2;
      ++*((_BYTE *)&v38 + v25 + 1);
      *((_BYTE *)&v38 + v27 + 1) += 2;
    }
    --v25;
    --v24;
  }
  while ( v24 );
  if ( !(_BYTE)v42 )
  {
    while ( !*((_BYTE *)&v37[256] + v26-- + 3) )
      ;
  }
  --*((_BYTE *)&v38 + v26);
  v30 = v39;
  *(_DWORD *)a2 = v38;
  v31 = v40;
  *(_DWORD *)(a2 + 4) = v30;
  v32 = v41;
  *(_DWORD *)(a2 + 8) = v31;
  LOBYTE(v31) = v42;
  *(_DWORD *)(a2 + 12) = v32;
  *(_BYTE *)(a2 + 16) = v31;
  v33 = 0;
  for ( m = 1; m <= 32; ++m )
  {
    for ( result = 0; result <= 255; ++result )
    {
      if ( v37[result] == m )
      {
        *(_BYTE *)(v33 + a2 + 17) = result;
        ++v33;
      }
    }
  }
  *(_DWORD *)(a2 + 276) = 0;
  return result;
}
