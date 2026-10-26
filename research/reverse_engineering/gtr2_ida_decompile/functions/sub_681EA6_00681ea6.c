int __stdcall sub_681EA6(int a1, int a2, int a3)
{
  int v3; // ecx
  _DWORD *v4; // eax
  _DWORD *v5; // ecx
  unsigned int v6; // edx
  unsigned int v7; // esi
  unsigned int v9; // edx
  unsigned int v10; // esi
  unsigned int v11; // edx
  unsigned int v12; // esi
  unsigned int v13; // edx
  unsigned int v14; // esi
  unsigned int v15; // edx
  unsigned int v16; // esi
  unsigned int v17; // edx
  unsigned int v18; // esi
  unsigned int v19; // edx
  unsigned int v20; // esi
  int v21; // eax
  int v22; // ecx

  v3 = *(_DWORD *)(a3 + 20);
  v4 = *(_DWORD **)(v3 + 4 * a1);
  v5 = *(_DWORD **)(v3 + 4 * a2);
  v6 = v4[14];
  v7 = v5[14];
  if ( v6 < v7 )
    return -1;
  if ( v6 > v7 )
    return 1;
  v9 = v4[15];
  v10 = v5[15];
  if ( v9 < v10 )
    return -1;
  if ( v9 > v10 )
    return 1;
  v11 = v4[1];
  v12 = v5[1];
  if ( v11 < v12 )
    return -1;
  if ( v11 > v12 )
    return 1;
  v13 = v4[3];
  v14 = v5[3];
  if ( v13 < v14 )
    return -1;
  if ( v13 > v14 )
    return 1;
  v15 = v4[2];
  v16 = v5[2];
  if ( v15 < v16 )
    return -1;
  if ( v15 > v16 )
    return 1;
  v17 = v4[4];
  v18 = v5[4];
  if ( v17 < v18 )
    return -1;
  if ( v17 > v18 )
    return 1;
  v19 = v4[5];
  v20 = v5[5];
  if ( v19 < v20 )
    return -1;
  if ( v19 > v20 )
    return 1;
  v21 = v4[6];
  v22 = v5[6];
  if ( v21 < v22 )
    return -1;
  return v21 > v22;
}
