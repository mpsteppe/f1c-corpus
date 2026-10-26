BOOL __thiscall sub_685795(_DWORD *this, int a2, int a3, int a4, int a5)
{
  int v5; // eax
  _DWORD *v6; // edx
  unsigned int v7; // esi
  int i; // ecx
  int v9; // ecx
  int j; // edi
  bool v11; // cc
  int v12; // edi
  unsigned int v13; // edx
  int v14; // eax
  int v15; // ebx
  unsigned int v16; // esi
  int v17; // ecx
  int v18; // edi
  int v19; // edx
  int v20; // eax
  int v21; // ecx
  int v22; // esi
  unsigned int v25; // [esp+Ch] [ebp-4h]

  v5 = a2;
  v6 = this;
  v7 = 0;
  v25 = 0;
  for ( i = a2; i != -1; ++v25 )
    i = *(_DWORD *)(*(_DWORD *)(v6[5] + 4 * i) + 20);
  v9 = a4;
  for ( j = a4; j != -1; ++v7 )
    j = *(_DWORD *)(*(_DWORD *)(v6[5] + 4 * j) + 20);
  v11 = v7 <= v25;
  if ( v7 < v25 )
  {
    v12 = v6[5];
    v13 = v25 - v7;
    do
    {
      v14 = *(_DWORD *)(v12 + 4 * v5);
      v15 = *(_DWORD *)(v14 + 24);
      --v25;
      --v13;
      v5 = *(_DWORD *)(v14 + 20);
      a3 = v15;
    }
    while ( v13 );
    v6 = this;
    v11 = v7 <= v25;
  }
  if ( v11 )
  {
    v18 = a5;
  }
  else
  {
    v16 = v7 - v25;
    do
    {
      --v16;
      v17 = *(_DWORD *)(v6[5] + 4 * v9);
      v18 = *(_DWORD *)(v17 + 24);
      v9 = *(_DWORD *)(v17 + 20);
    }
    while ( v16 );
  }
  if ( v5 != v9 )
  {
    v19 = v6[5];
    do
    {
      v20 = *(_DWORD *)(v19 + 4 * v5);
      v21 = *(_DWORD *)(v19 + 4 * v9);
      v22 = *(_DWORD *)(v20 + 24);
      v18 = *(_DWORD *)(v21 + 24);
      v5 = *(_DWORD *)(v20 + 20);
      v9 = *(_DWORD *)(v21 + 20);
      a3 = v22;
    }
    while ( v5 != v9 );
  }
  return a3 != v18;
}
