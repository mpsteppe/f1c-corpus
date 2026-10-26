int __thiscall sub_6829EC(_DWORD *this, _DWORD *a2, int *a3, int a4, int a5)
{
  _DWORD *v6; // ecx
  int v7; // eax
  int v8; // esi
  unsigned int v9; // ecx
  int i; // esi
  int v11; // edi
  unsigned int v12; // esi
  int v13; // eax
  int v14; // esi
  int v15; // edx
  unsigned int v16; // ecx
  int v17; // edx
  int v18; // esi
  int v19; // eax
  int v20; // edx
  _DWORD *v22; // [esp+Ch] [ebp-8h]
  unsigned int v23; // [esp+10h] [ebp-4h]

  v6 = a2;
  v7 = *a2;
  v22 = this;
  if ( *a2 != -1 || *a3 )
  {
    if ( a4 != -1 || a5 )
    {
      v8 = *a2;
      v9 = 0;
      v23 = 0;
      if ( v7 != -1 )
      {
        do
        {
          v8 = *(_DWORD *)(*(_DWORD *)(this[5] + 4 * v8) + 20);
          ++v9;
        }
        while ( v8 != -1 );
      }
      for ( i = a4; i != -1; ++v23 )
        i = *(_DWORD *)(*(_DWORD *)(this[5] + 4 * i) + 20);
      v11 = *a3;
      if ( v9 > v23 )
      {
        v12 = v9 - v23;
        do
        {
          v13 = *(_DWORD *)(this[5] + 4 * v7);
          v11 = *(_DWORD *)(v13 + 24);
          v7 = *(_DWORD *)(v13 + 20);
          --v9;
          --v12;
        }
        while ( v12 );
      }
      v14 = a5;
      v15 = a4;
      if ( v23 > v9 )
      {
        v16 = v23 - v9;
        do
        {
          --v16;
          v17 = *(_DWORD *)(v22[5] + 4 * v15);
          v14 = *(_DWORD *)(v17 + 24);
          v15 = *(_DWORD *)(v17 + 20);
        }
        while ( v16 );
      }
      while ( 1 )
      {
        if ( v11 == v14 && v7 == v15 )
        {
          *a3 = v11;
          v6 = a2;
          goto LABEL_22;
        }
        if ( v7 == -1 || v15 == -1 )
          break;
        v18 = v22[5];
        v19 = *(_DWORD *)(v18 + 4 * v7);
        v20 = *(_DWORD *)(v18 + 4 * v15);
        v11 = *(_DWORD *)(v19 + 24);
        v14 = *(_DWORD *)(v20 + 24);
        v7 = *(_DWORD *)(v19 + 20);
        v15 = *(_DWORD *)(v20 + 20);
      }
      *a3 = 0;
      *a2 = -1;
    }
  }
  else
  {
    *a3 = a5;
    v7 = a4;
LABEL_22:
    *v6 = v7;
  }
  return 0;
}
